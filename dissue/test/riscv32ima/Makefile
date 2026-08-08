override EXT := riscv32ima
MARCH := rv32ima
MABI := ilp32
NO_DIFF_TESTS := a-ext \
	a-lr-sc-success \
	a-lr-normal-store-clear \
	a-sc-fail-no-reservation \
	a-sc-clear-after-success \
	a-lr-reservation-replace \
	a-amoadd-sequence \
	a-amo-load-order \
	a-amoswap-return \
	a-amo-bitwise \
	a-amo-minmax-signed \
	a-amo-minmax-unsigned \
	a-misaligned-trap \
	device-clint-time \
	device-plic-basic \
	mmio-load-flush-cancel \
	mmio-store-load-order \
	sv32-basic \
	sv32-icache-remap \
	sv32-ad-bit-page-fault \
	sv32-load-page-fault \
	sv32-u-load-supervisor-page-fault \
	sv32-u-store-supervisor-page-fault \
	sv32-s-sum-user-load \
	sv32-s-fetch-user-page-fault \
	sv32-invalid-pte-w-only \
	sv32-nonleaf-reserved-page-fault \
	sv32-mprv-u-page-fault \
	sv32-store-page-fault \
	sv32-instr-page-fault \
	sv32-mxr-xonly-load

include ../mk/extension.mk
