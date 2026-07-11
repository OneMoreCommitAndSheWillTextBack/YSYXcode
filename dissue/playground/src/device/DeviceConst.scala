package top.device

object DeviceConst {
  // The Linux device tree and OpenSBI platform both describe a 1 MHz timebase.
  // Model a 100 MHz core clock and derive the shared mtime tick from it.
  val coreFrequencyHz:     Int = 100000000
  val timebaseFrequencyHz: Int = 1000000
  val mtimeTickCycles:     Int = coreFrequencyHz / timebaseFrequencyHz
  require(coreFrequencyHz % timebaseFrequencyHz == 0, "mtime timebase must divide the core clock")

  val clintBase: BigInt = BigInt("02000000", 16)
  val clintSize: BigInt = BigInt("00010000", 16)

  val clintMsipBase:     BigInt = BigInt("0000", 16)
  val clintMtimecmpBase: BigInt = BigInt("4000", 16)
  val clintMtimeBase:    BigInt = BigInt("bff8", 16)

  val rtcBase: BigInt = BigInt("a0000048", 16)
  val rtcSize: BigInt = 8

  val plicBase: BigInt = BigInt("0c000000", 16)
  val plicSize: BigInt = BigInt("04000000", 16)

  val plicPriorityBase:  BigInt = BigInt("000000", 16)
  val plicPendingBase:   BigInt = BigInt("001000", 16)
  val plicEnableBase:    BigInt = BigInt("002000", 16)
  val plicContextBase:   BigInt = BigInt("200000", 16)
  val plicEnableStride:  BigInt = BigInt("80", 16)
  val plicContextStride: BigInt = BigInt("1000", 16)
}
