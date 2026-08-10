import top.Target
import top.config.FrontendConfig

object Elaborate extends App {
  private val targetOption       = "--ysyx-target"
  private val disableTraceOption = "--disable-trace"
  private val icacheSizeOption   = "--icache-size-bytes"
  private val icacheLineOption   = "--icache-line-bytes"
  private val icacheWaysOption   = "--icache-ways"
  private val defaultTargetDir   = "build"

  private final case class ICacheOptions(sizeBytes: Int = 512, lineBytes: Int = 8, ways: Int = 1)

  private def positiveInt(option: String, value: String): Int = {
    val parsed = value.toIntOption.getOrElse(throw new IllegalArgumentException(s"$option requires an integer"))
    require(parsed > 0, s"$option must be positive")
    parsed
  }

  private val (target, enableTrace, icacheOptions, chiselArgs) = {
    def parseArgs(
      rest:          List[String],
      kept:          List[String],
      currentTarget: Target,
      traceEnabled:  Boolean,
      cache:         ICacheOptions
    ): (Target, Boolean, ICacheOptions, Array[String]) =
      rest match {
        case Nil                                                                                         => (currentTarget, traceEnabled, cache, kept.reverse.toArray)
        case (`targetOption`) :: Nil                                                                     =>
          throw new IllegalArgumentException(s"$targetOption requires npc or soc")
        case (`targetOption`) :: value :: tail                                                           =>
          parseArgs(tail, kept, Target.parse(value), traceEnabled, cache)
        case arg :: tail if arg.startsWith(s"$targetOption=")                                            =>
          parseArgs(tail, kept, Target.parse(arg.drop(targetOption.length + 1)), traceEnabled, cache)
        case (`disableTraceOption`) :: tail                                                              =>
          parseArgs(tail, kept, currentTarget, traceEnabled = false, cache)
        case (`icacheSizeOption`) :: value :: tail                                                       =>
          parseArgs(
            tail,
            kept,
            currentTarget,
            traceEnabled,
            cache.copy(sizeBytes = positiveInt(icacheSizeOption, value))
          )
        case arg :: tail if arg.startsWith(s"$icacheSizeOption=")                                        =>
          parseArgs(
            tail,
            kept,
            currentTarget,
            traceEnabled,
            cache.copy(sizeBytes = positiveInt(icacheSizeOption, arg.drop(icacheSizeOption.length + 1)))
          )
        case (`icacheLineOption`) :: value :: tail                                                       =>
          parseArgs(
            tail,
            kept,
            currentTarget,
            traceEnabled,
            cache.copy(lineBytes = positiveInt(icacheLineOption, value))
          )
        case arg :: tail if arg.startsWith(s"$icacheLineOption=")                                        =>
          parseArgs(
            tail,
            kept,
            currentTarget,
            traceEnabled,
            cache.copy(lineBytes = positiveInt(icacheLineOption, arg.drop(icacheLineOption.length + 1)))
          )
        case (`icacheWaysOption`) :: value :: tail                                                       =>
          parseArgs(tail, kept, currentTarget, traceEnabled, cache.copy(ways = positiveInt(icacheWaysOption, value)))
        case arg :: tail if arg.startsWith(s"$icacheWaysOption=")                                        =>
          parseArgs(
            tail,
            kept,
            currentTarget,
            traceEnabled,
            cache.copy(ways = positiveInt(icacheWaysOption, arg.drop(icacheWaysOption.length + 1)))
          )
        case option :: Nil if Set(icacheSizeOption, icacheLineOption, icacheWaysOption).contains(option) =>
          throw new IllegalArgumentException(s"$option requires a value")
        case arg :: tail                                                                                 =>
          parseArgs(tail, arg :: kept, currentTarget, traceEnabled, cache)
      }

    parseArgs(args.toList, Nil, Target.Npc, traceEnabled = true, ICacheOptions())
  }

  private val bytesPerSet = icacheOptions.lineBytes * icacheOptions.ways
  require(icacheOptions.sizeBytes % bytesPerSet == 0, "ICache capacity must be divisible by lineBytes * ways")
  private val icacheSets  = icacheOptions.sizeBytes / bytesPerSet
  require(icacheSets > 0 && (icacheSets & (icacheSets - 1)) == 0, "derived ICache set count must be a power of two")
  private val frontendCfg = FrontendConfig(
    icacheLineBytes = icacheOptions.lineBytes,
    icacheSets = icacheSets,
    icacheWays = icacheOptions.ways
  )

  private val targetDirSpecified = chiselArgs.exists(arg =>
    arg == "--target-dir" || arg == "-td" || arg.startsWith("--target-dir=") || arg.startsWith("-td=")
  )

  private val stageArgs = if (targetDirSpecified) chiselArgs else chiselArgs ++ Array("--target-dir", defaultTargetDir)

  val firtoolOptions = Array(
    "--lowering-options=" + List(
      // make yosys happy
      // see https://github.com/llvm/circt/blob/main/docs/VerilogGeneration.md
      "disallowLocalVariables",
      "disallowPackedArrays",
      "locationInfoStyle=wrapInAtSquareBracket"
    ).reduce(_ + "," + _)
  )
  circt.stage.ChiselStage.emitSystemVerilogFile(
    new top.Top(target, enableTrace, frontendCfg),
    stageArgs,
    firtoolOptions
  )
}
