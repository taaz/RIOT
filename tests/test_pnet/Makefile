export APPLICATION = test_pnet
include ../Makefile.tests_common

BOARD_INSUFFICIENT_RAM := chronos msb-430h redbee-econotag telosb wsn430-v1_3b wsn430-v1_4 z1
BOARD_BLACKLIST := arduino-due mbed_lpc1768 msb-430 udoo qemu-i386
# mbed_lpc1768:     see https://github.com/RIOT-OS/RIOT/issues/675
# msb-430:          see https://github.com/RIOT-OS/RIOT/issues/658
# qemu-i386: no tranceiver, yet

USEMODULE += posix
USEMODULE += pnet
USEMODULE += vtimer
USEMODULE += defaulttransceiver

include $(RIOTBASE)/Makefile.include
