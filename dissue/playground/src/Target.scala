package top

sealed trait Target {
  def resetVector: BigInt
}

object Target {
  case object Npc extends Target {
    override val resetVector: BigInt = BigInt("80000000", 16)
  }

  case object Soc extends Target {
    override val resetVector: BigInt = BigInt("30000000", 16)
  }

  def parse(value: String): Target = value.toLowerCase match {
    case "npc" => Npc
    case "soc" => Soc
    case other => throw new IllegalArgumentException(s"unknown target '$other', expected npc or soc")
  }
}

/** Elaboration view: what the generated RTL will be used for.
  *
  * The sim view carries every observation hook (DPI bridges, difftest, traces); the synth view is pure synthesizable
  * RTL. Both views share the same wiring.
  */
sealed trait View {
  def dirName: String
  def isSim:   Boolean
}

object View {
  case object Sim extends View {
    override val dirName: String  = "sim"
    override val isSim:   Boolean = true
  }

  case object Synth extends View {
    override val dirName: String  = "synth"
    override val isSim:   Boolean = false
  }

  def parse(value: String): View = value.toLowerCase match {
    case "sim"   => Sim
    case "synth" => Synth
    case other   => throw new IllegalArgumentException(s"unknown view '$other', expected sim or synth")
  }
}
