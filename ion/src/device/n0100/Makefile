ion_device_src += $(addprefix ion/src/device/n0100/drivers/, \
  board.cpp \
  led.cpp \
  power.cpp \
  reset.cpp \
)

ifeq ($(EXTERNAL_FLASH),8M)
SFLAGS += -DEXTERNAL_FLASH_8M=1
LDSCRIPT ?= ion/src/device/n0100/flash_ext_8M.ld
else ifeq ($(EXTERNAL_FLASH),16M)
SFLAGS += -DEXTERNAL_FLASH_16M=1
LDSCRIPT ?= ion/src/device/n0100/flash_ext_16M.ld
else
LDSCRIPT ?= ion/src/device/n0100/flash.ld
endif

