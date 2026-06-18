本仓库计划使用 [Chisel](https://www.chisel-lang.org/) 实现一个顺序双发射五级流水。

基于 [Chisel template](https://github.com/ucb-bar/chisel-template)，使用 mill 作为构建工具。
mill is another Scala/Java build tool without obscure DSL like SBT. It is much faster than SBT.

Contents at a glance:

* `.gitignore` - helps Git ignore junk like generated files, build products, and temporary files.
* `build.mill` - instructs mill to build the Chisel project
* `Makefile` - rules to call mill

Frontend
|- Bpu
|- PCGen
|- ICache
|- IFetch
-- InstBuffer
