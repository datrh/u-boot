#ifndef __CONFIG_M6_MBX_G19_H__
#define __CONFIG_M6_MBX_G19_H__

#define CONFIG_SUPPORT_CUSOTMER_BOARD 1
#define CONFIG_AML_MESON_6 1
#define CONFIG_MACH_MESON6_MBX
#define CONFIG_MESON_ARM_GIC_FIQ

//#define TEST_UBOOT_BOOT_SPEND_TIME
#define CONFIG_IR_RECOVERY_DETECT

/*
 *  write to efuse/nand when usb_burning 
 *  WRITE_TO_EFUSE_ENABLE and WRITE_TO_NAND_ENABLE should not be both existed
 */
#define CONFIG_AML_MESON6
#define WRITE_TO_EFUSE_ENABLE
//#define WRITE_TO_NAND_ENABLE

#if defined(WRITE_TO_NAND_ENABLE)
#define CONFIG_SECURITYKEY 1
#define CONFIG_AML_NAND_KEY 1
#define CONFIG_HDCP_PREFETCH 1
#endif

#if defined(WRITE_TO_EFUSE_ENABLE) && defined(WRITE_TO_NAND_ENABLE)
#error You should only select one of WRITE_TO_EFUSE_ENABLE and WRITE_TO_NAND_ENABLE
#endif


#define CONFIG_AML_TINY_USBTOOL

#define CONFIG_CMDLINE_TAG     1       /* enable passing of ATAGs      */
#define CONFIG_CMDLINE_EDITING 1       /* Command-line editing */

//UART Sectoion
#define CONFIG_CONS_INDEX   2

//support "boot,bootd"
//#define CONFIG_CMD_BOOTD 1
//#define CONFIG_AML_I2C      1

#define HAS_AO_MODULE
//#define CONFIG_AML_I2C	//add by Elvis Yu
//#define CONFIG_AW_AXP20

//Enable storage devices
//#ifndef CONFIG_JERRY_NAND_TEST
//#define CONFIG_CMD_NAND  1
//#endif
//#define CONFIG_CMD_SF    1

#if defined(CONFIG_CMD_SF)
#define SPI_WRITE_PROTECT  1
#define CONFIG_CMD_MEMORY  1
#endif /*CONFIG_CMD_SF*/

//Amlogic SARADC support
//#define CONFIG_SARADC 1
//#define CONFIG_CMD_SARADC
#define CONFIG_EFUSE 1
//#define CONFIG_MACHID_CHECK 1

#define CONFIG_L2_OFF			1
//#define CONFIG_ICACHE_OFF	1
//#define CONFIG_DCACHE_OFF	1


//#define CONFIG_CMD_NET   1

#if defined(CONFIG_CMD_NET)
#define CONFIG_AML_ETHERNET 1
#define CONFIG_NET_MULTI 1
#define CONFIG_CMD_PING 1
#define CONFIG_CMD_DHCP 1
#define CONFIG_CMD_RARP 1

//#define CONFIG_NET_RGMII
#define CONFIG_NET_RMII_CLK_EXTERNAL //use external 50MHz clock source

#define CONFIG_AML_ETHERNET    1                   /*to link /driver/net/aml_ethernet.c*/
#define CONFIG_HOSTNAME        arm_m6
#define CONFIG_ETHADDR         00:15:18:01:81:31   /* Ethernet address */
#define CONFIG_IPADDR          10.18.9.97          /* Our ip address */
#define CONFIG_GATEWAYIP       10.18.9.1           /* Our getway ip address */
#define CONFIG_SERVERIP        10.18.9.113         /* Tftp server ip address */
#define CONFIG_NETMASK         255.255.255.0
#endif /* (CONFIG_CMD_NET) */


//#define CONFIG_SDIO_B1   1
//#define CONFIG_SDIO_A    1
#define CONFIG_SDIO_B    1
#define CONFIG_SDIO_C    1
#define CONFIG_ENABLE_EXT_DEVICE_RETRY 1


#define CONFIG_MMU                    1
#define CONFIG_PAGE_OFFSET 	0xc0000000
#define CONFIG_SYS_LONGHELP	1

/* USB
 * Enable CONFIG_MUSB_HCD for Host functionalities MSC, keyboard
 * Enable CONFIG_MUSB_UDD for Device functionalities.
 */
/* #define CONFIG_MUSB_UDC		1 */
#define CONFIG_M6_USBPORT_BASE	0xC9040000
#define CONFIG_M6_USBPORT_BASE_A	0xC9040000
#define CONFIG_USB_STORAGE      1
#define CONFIG_USB_DWC_OTG_HCD  1
#define CONFIG_USB_DWC_OTG_294	1
#define CONFIG_CMD_USB 1

//#define CONFIG_USB_ETHER
#ifdef CONFIG_USB_ETHER
#define IO_USB_A_BASE			0xc9040000
#define CONFIG_USBPORT_BASE IO_USB_A_BASE
#define CONFIG_SYS_CACHELINE_SIZE       64 
#define CONFIG_USB_ETH_RNDIS
#define CONFIG_USB_GADGET_S3C_UDC_OTG
#define CONFIG_USB_GADGET_DUALSPEED
#endif



#define CONFIG_UCL 1
#define CONFIG_SELF_COMPRESS

#define CONFIG_IMPROVE_UCL_DEC   1

#ifdef CONFIG_IMPROVE_UCL_DEC
#define UCL_DEC_EN_IDCACHE        1
#define UCL_DEC_EN_IDCACHE_FINE_TUNE  1
#endif


#define CONFIG_CMD_AUTOSCRIPT
//#define CONFIG_CMD_AML 1
#define CONFIG_CMD_IMGPACK 1
#define CONFIG_CMD_REBOOT 1
#define CONFIG_CMD_MATH 1
#define CONFIG_CMD_SUSPEND 1

/*
 * add for mx revd
 */
#define CONFIG_CMD_CHIPREV 1

/* Environment information */
#define CONFIG_BOOTDELAY	1
#define CONFIG_BOOTFILE		boot.img

#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x82000000\0" \
	"testaddr=0x82400000\0" \
	"loadaddr_misc=0x83000000\0" \
	"usbtty=cdc_acm\0" \
	"console=ttyS0,115200n8\0" \
	"boardname=m6_mbx\0" \
	"chipname=8726m6\0" \
	"machid=4e28\0" \
	"video_dev=tvout\0" \
	"display_width=720\0" \
	"display_height=480\0" \
	"display_bpp=24\0" \
	"display_color_format_index=24\0" \
	"display_layer=osd1\0" \
	"display_color_fg=0xffff\0" \
	"display_color_bg=0\0" \
	"fb_addr=0x84900000\0" \
	"sleep_threshold=20\0" \
	"upgrade_step=0\0" \
	"batlow_threshold=10\0" \
	"batfull_threshold=98\0" \
	"outputmode=720p\0" \
	"outputtemp=720p\0" \
	"cvbsenable=true\0" \
	"preboot=get_rebootmode; clear_rebootmode; echo reboot_mode=${reboot_mode}; if test ${reboot_mode} = usb_burning; then tiny_usbtool 20000; fi; run upgrade_check; run irtest; run switch_bootmode\0" \
	"upgrade_check=if itest ${upgrade_step} == 1; then defenv_without reboot_mode;setenv upgrade_step 2; save; mmc read 1 82000000 0 1; mw.w 820001fe 0; mmc write 1 82000000 0 1; fi\0" \
	"update=if mmcinfo; then if fatload mmc 0 ${loadaddr} aml_autoscript; then autoscr ${loadaddr}; fi;fi;run recovery\0" \
	"irtest=if irdetect; then run recovery; fi\0" \
	"cvbscheck=setenv outputtemp ${outputmode};if test ${outputmode} = 480i; then if test ${cvbsenable} = true; then setenv outputtemp 480cvbs;fi;fi; if test ${outputmode} = 576i; then if test ${cvbsenable} = true; then setenv outputtemp 576cvbs;fi;fi\0" \
	"nandargs=run cvbscheck;mmc read 1 0x83000000 4000 2000;unpackimg 0x83000000; cp ${bootup_offset} 0x84100000 ${bootup_size}; setenv bootargs init=/init console=${console} logo=osd1,0x84100000,${outputtemp},full androidboot.resolution=${outputtemp} hlt vmalloc=256m mem=1024m a9_clk_max=1512000000\0"\
	"switch_bootmode=if test ${reboot_mode} = factory_reset; then run recovery;else if test ${reboot_mode} = update; then run recovery;fi;fi\0" \
	"nandboot=echo Booting from eMMC ...;run nandargs;mmc read 1 ${loadaddr} a000 3000;bootm;run recovery\0" \
	"recovery=echo enter recovery;run nandargs;if mmcinfo; then if fatload mmc 0 ${loadaddr} recovery.img; then bootm;fi;fi; mmc read 1 ${loadaddr} 6000 3000; bootm\0" \
	"bootargs=init=/init console=ttyS0,115200n8 hlt vmalloc=256m mem=1024m logo=osd1,0x84100000,720p\0" \
	"update_chiprev=chiprev; setenv bootargs ${bootargs} chiprev=${chiprev}\0" \
	"usbnet_devaddr=00:15:18:01:81:31" \
	"usbnet_hostddr=00:15:18:01:a1:3b" \
	"cdc_connect_timeout=9999999999" \

#define CONFIG_BOOTCOMMAND \
 "run nandboot"

/*
#define CONFIG_BOOTCOMMAND \
 "mmcinfo 0;fatload mmc 0 82000000 aml_logo480.bmp;video dev open 480P;bmp display 82000000;video open"
*/

//\\temp above

#define CONFIG_AUTO_COMPLETE	1

//#define CONFIG_SPI_BOOT 1
#define CONFIG_MMC_BOOT 1
#ifndef CONFIG_JERRY_NAND_TEST
//#define CONFIG_NAND_BOOT 1
#endif

#ifdef CONFIG_NAND_BOOT
#define CONFIG_AMLROM_NANDBOOT 1
#endif

#define CONFIG_ENV_SIZE         0x8000

#ifdef CONFIG_SPI_BOOT
	#define CONFIG_ENV_OVERWRITE
	#define CONFIG_ENV_IS_IN_SPI_FLASH
	#define CONFIG_CMD_SAVEENV
	//for CONFIG_SPI_FLASH_SPANSION 64KB sector size
	#define CONFIG_ENV_SECT_SIZE        0x10000
	#define CONFIG_ENV_OFFSET           0x70000
#elif defined CONFIG_NAND_BOOT
	#define CONFIG_ENV_IS_IN_AML_NAND
	#define CONFIG_CMD_SAVEENV
	#define CONFIG_ENV_OVERWRITE
	#define CONFIG_ENV_OFFSET       0x400000
	#define CONFIG_ENV_BLOCK_NUM    2
#elif defined CONFIG_MMC_BOOT
	#define CONFIG_ENV_IS_IN_MMC
	#define CONFIG_CMD_SAVEENV
	#define CONFIG_SYS_MMC_ENV_DEV        1
	#define CONFIG_ENV_DEVICE_ID 1    
	#define CONFIG_ENV_OFFSET       0x400000
#elif defined CONFIG_EMMC_BOOT
	#define CONFIG_ENV_IS_IN_EMMC
	#define CONFIG_CMD_SAVEENV
	#define CONFIG_ENV_DEVICE_ID 1    
	#define CONFIG_ENV_OFFSET       0x400000
#else
#define CONFIG_ENV_IS_NOWHERE    1
#endif


/*
 * Size of malloc() pool
 */
						/* Sector */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (1 << 26))
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* bytes reserved for */
						/* initial data */


#define BOARD_LATE_INIT
#define CONFIG_PREBOOT
#if 0
#define CONFIG_VIDEO_AML
/* config TV output */
#define CONFIG_VIDEO_AMLTVOUT
/* config LCD output */
//#define CONFIG_VIDEO_AMLLCD
//#define CONFIG_VIDEO_AMLLCD_M3
#define CONFIG_CMD_BMP
#define LCD_BPP LCD_COLOR24
#define TV_BPP LCD_BPP
#define LCD_TEST_PATTERN
#endif

#ifndef CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#endif
/*end config LCD output*/

/*POST support*/
/*
#define CONFIG_POST (CONFIG_SYS_POST_CACHE	| CONFIG_SYS_POST_BSPEC1 |	\
										CONFIG_SYS_POST_RTC | CONFIG_SYS_POST_ADC | \
										CONFIG_SYS_POST_PLL)
*/
//CONFIG_SYS_POST_MEMORY

#undef CONFIG_POST
#ifdef CONFIG_POST
#define CONFIG_POST_AML
#define CONFIG_POST_ALT_LIST
#define CONFIG_SYS_CONSOLE_IS_IN_ENV  /* Otherwise it catches logbuffer as output */
#define CONFIG_LOGBUFFER
#define CONFIG_CMD_DIAG

#define SYSTEST_INFO_L1 1
#define SYSTEST_INFO_L2 2
#define SYSTEST_INFO_L3 3

#define CONFIG_POST_BSPEC1 {    \
	"L2CACHE test", \
	"l2cache", \
	"This test verifies the L2 cache operation.", \
	POST_RAM | POST_MANUAL,   \
	&l2cache_post_test,		\
	NULL,		\
	NULL,		\
	CONFIG_SYS_POST_BSPEC1 	\
	}

#define CONFIG_POST_BSPEC2 {  \
	"BIST test", \
	"bist", \
	"This test checks bist test", \
	POST_RAM | POST_MANUAL, \
	&bist_post_test, \
	NULL, \
	NULL, \
	CONFIG_SYS_POST_BSPEC1  \
	}
#endif   /*end ifdef CONFIG_POST*/

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
//Please just define M6 DDR clock here only
//current DDR clock range (300~600)MHz
#define M6_DDR_CLK (516)

#define CONFIG_DDR_LOW_POWER


//#define DDR3_9_9_9
#define DDR3_7_7_7
//above setting must be set for ddr_set __ddr_setting in file
//board/amlogic/m6_ref_v1/firmware/timming.c

//note: please DO NOT remove following check code
#if !defined(DDR3_9_9_9) && !defined(DDR3_7_7_7)
	#error "Please set DDR3 property first in file m6_duokan_mbx_g19ref.h\n"
#endif

#define M6_DDR3_1GB
//#define M6_DDR3_512M
//above setting will affect following:
//board/amlogic/m6_ref_v1/firmware/timming.c
//arch/arm/cpu/aml_meson/m6/mmutable.s

//note: please DO NOT remove following check code
#if !defined(M6_DDR3_1GB) && !defined(M6_DDR3_512M)
	#error "Please set DDR3 capacity first in file m6_duokan_mbx_g19ref.h\n"
#endif


#define CONFIG_NR_DRAM_BANKS    1   /* CS1 may or may not be populated */

#define PHYS_MEMORY_START    0x80000000 // from 500000
#if defined(M6_DDR3_1GB)
	#define PHYS_MEMORY_SIZE     0x40000000 // 1GB
#elif defined(M6_DDR3_512M)
	#define PHYS_MEMORY_SIZE     0x20000000 // 512M
#else
	#error "Please define DDR3 memory capacity in file m6_ref_v1.h\n"
#endif

#define CONFIG_SYS_MEMTEST_START    0x80000000  /* memtest works on */
#define CONFIG_SYS_MEMTEST_END      0x07000000  /* 0 ... 120 MB in DRAM */
//#define CONFIG_ENABLE_MEM_DEVICE_TEST 1
#define CONFIG_NR_DRAM_BANKS	1	/* CS1 may or may not be populated */

//M6 security boot
//#define CONFIG_M6_SECU_BOOT          1

#if defined(CONFIG_M6_SECU_BOOT)
       /*NOTE: must define the block num for crypto, illegal value is 2 - 10*/
       #define CONFIG_M6_CRYPTO_BLK    2               
#endif //CONFIG_M6_SECU_BOOT   

//////////////////////////////////////////////////////////////////////////
//check code, please keep.
#if defined(CONFIG_M6_SECU_BOOT)
       #if !defined(CONFIG_M6_CRYPTO_BLK)
               #error "Please define CONFIG_M6_CRYPTO_BLK (2-10) !"
       #elif (CONFIG_M6_CRYPTO_BLK < 2 || CONFIG_M6_CRYPTO_BLK > 10)
               #error "Illegal valuel of CONFIG_M6_CRYPTO_BLK (2-10)!"
       #endif  //CONFIG_M6_CRYPTO_BLK
#endif //CONFIG_M6_SECU_BOOT
//////////////////////////////////////////////////////////////////////////

/*-----------------------------------------------------------------------
 * power down
 */
//#define CONFIG_CMD_RUNARC 1 /* runarc */
#define CONFIG_AML_SUSPEND 1
#define CONFIG_CEC_WAKE_UP 1
#define CONFIG_CMD_IMI 1
#define CONFIG_ANDROID_IMG 1
//#define CONFIG_TURN_OFF_ODT
#define CONFIG_PWM_CORE_VOLTAGE
#define CONFIG_CMD_DDR_TEST       1       //ddrtest & d2pll

#endif //__CONFIG_M6_MBX_G19_H__