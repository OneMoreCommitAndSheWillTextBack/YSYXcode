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
