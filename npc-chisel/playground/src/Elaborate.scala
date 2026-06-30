import top.Target

object Elaborate extends App {
  private val targetOption     = "--ysyx-target"
  private val defaultTargetDir = "build"

  private val (target, chiselArgs) = {
    def parseArgs(rest: List[String], kept: List[String], currentTarget: Target): (Target, Array[String]) =
      rest match {
        case Nil                                              => (currentTarget, kept.reverse.toArray)
        case (`targetOption`) :: Nil                          =>
          throw new IllegalArgumentException(s"$targetOption requires npc or soc")
        case (`targetOption`) :: value :: tail                =>
          parseArgs(tail, kept, Target.parse(value))
        case arg :: tail if arg.startsWith(s"$targetOption=") =>
          parseArgs(tail, kept, Target.parse(arg.drop(targetOption.length + 1)))
        case arg :: tail                                      =>
          parseArgs(tail, arg :: kept, currentTarget)
      }

    parseArgs(args.toList, Nil, Target.Npc)
  }

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
  circt.stage.ChiselStage.emitSystemVerilogFile(new top.Top(target), stageArgs, firtoolOptions)
}
