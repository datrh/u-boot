#ifndef MESON_POC_H
#define MESON_POC_H

#define R_BOOT_DEVICE_FLAG  READ_CBUS_REG(ASSIST_POR_CONFIG)
#define POR_NAND_BOOT() (((R_BOOT_DEVICE_FLAG & 7) == 7) || ((R_BOOT_DEVICE_FLAG & 7) == 6))
#define POR_SPI_BOOT()  (((R_BOOT_DEVICE_FLAG & 7) == 5) || ((R_BOOT_DEVICE_FLAG & 7) == 4))
#define POR_EMMC_BOOT() ((IS_MESON_M8M2_CPU)?(((R_BOOT_DEVICE_FLAG & 7) == 3) || ((R_BOOT_DEVICE_FLAG & 7) == 1)):((R_BOOT_DEVICE_FLAG & 7) == 3))
#define POR_CARD_BOOT() ((R_BOOT_DEVICE_FLAG & 7) == 0)

#endif
