#@TYPE: Machine Include
#@SOC: PIC64GX SoC
#@DESCRIPTION: Common Machine Configuration for PIC64GX SoC

require conf/machine/include/riscv/tune-riscv.inc

MACHINE_FEATURES += "screen pci usbgadget ext2 ext3 serial"

KERNEL_CLASSES += "kernel-fit-extra-artifacts"
KERNEL_IMAGETYPE = "Image"
EXTERNAL_KERNEL_DEVICETREE = "${DEPLOY_DIR_IMAGE}/overlays"

RISCV_SBI_PLAT = "generic"

PREFERRED_PROVIDER_virtual/bootloader = "u-boot-mchp"
PREFERRED_PROVIDER_u-boot = "u-boot-mchp"
PREFERRED_VERSION_u-boot-mchp ?= "v2025.07%"

UBOOT_ENTRYPOINT = "0x80200000"
UBOOT_DTB_LOADADDRESS = "0x8a000000"
UBOOT_DTBO_LOADADDRESS = "0x8a080000"
UBOOT_RD_LOADADDRESS = "0x8aa00000"
UBOOT_RD_ENTRYPOINT = "0x8aa00000"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

IMAGE_FSTYPES += "wic wic.gz wic.bmap ext4"

MACHINE_EXTRA_RRECOMMENDS:append = " dt-overlay-mchp"
MACHINE_EXTRA_RRECOMMENDS:append = " linux-yocto-fitimage"
