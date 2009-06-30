#ifndef _GLAMO_REGS_H
#define _GLAMO_REGS_H

/* Smedia Glamo 336x/337x driver
 *
 * (C) 2007 by OpenMoko, Inc.
 * Author: Harald Welte <laforge@openmoko.org>
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

enum glamo_regster_offsets {
	GLAMO_REGOFS_GENERIC	= 0x0000,
	GLAMO_REGOFS_HOSTBUS	= 0x0200,
	GLAMO_REGOFS_MEMORY	= 0x0300,
	GLAMO_REGOFS_VIDCAP	= 0x0400,
	GLAMO_REGOFS_ISP	= 0x0500,
	GLAMO_REGOFS_JPEG	= 0x0800,
	GLAMO_REGOFS_MPEG	= 0x0c00,
	GLAMO_REGOFS_LCD	= 0x1100,
	GLAMO_REGOFS_MMC	= 0x1400,
	GLAMO_REGOFS_MPROC0	= 0x1500,
	GLAMO_REGOFS_MPROC1	= 0x1580,
	GLAMO_REGOFS_CMDQUEUE	= 0x1600,
	GLAMO_REGOFS_RISC	= 0x1680,
	GLAMO_REGOFS_2D		= 0x1700,
	GLAMO_REGOFS_3D		= 0x1b00,
	GLAMO_REGOFS_END	= 0x2400,
};


enum glamo_register_generic {
	GLAMO_REG_GCONF1	= 0x0000,
	GLAMO_REG_GCONF2	= 0x0002,
#define	GLAMO_REG_DEVICE_ID	GLAMO_REG_GCONF2
	GLAMO_REG_GCONF3	= 0x0004,
#define	GLAMO_REG_REVISION_ID	GLAMO_REG_GCONF3
	GLAMO_REG_IRQ_GEN1	= 0x0006,
#define GLAMO_REG_IRQ_ENABLE	GLAMO_REG_IRQ_GEN1
	GLAMO_REG_IRQ_GEN2	= 0x0008,
#define GLAMO_REG_IRQ_SET	GLAMO_REG_IRQ_GEN2
	GLAMO_REG_IRQ_GEN3	= 0x000a,
#define GLAMO_REG_IRQ_CLEAR	GLAMO_REG_IRQ_GEN3
	GLAMO_REG_IRQ_GEN4	= 0x000c,
#define GLAMO_REG_IRQ_STATUS	GLAMO_REG_IRQ_GEN4
	GLAMO_REG_CLOCK_HOST	= 0x0010,
	GLAMO_REG_CLOCK_MEMORY	= 0x0012,
	GLAMO_REG_CLOCK_LCD	= 0x0014,
	GLAMO_REG_CLOCK_MMC	= 0x0016,
	GLAMO_REG_CLOCK_ISP	= 0x0018,
	GLAMO_REG_CLOCK_JPEG	= 0x001a,
	GLAMO_REG_CLOCK_3D	= 0x001c,
	GLAMO_REG_CLOCK_2D	= 0x001e,
	GLAMO_REG_CLOCK_RISC1	= 0x0020,	/* 3365 only? */
	GLAMO_REG_CLOCK_RISC2	= 0x0022,	/* 3365 only? */
	GLAMO_REG_CLOCK_MPEG	= 0x0024,
	GLAMO_REG_CLOCK_MPROC	= 0x0026,

	GLAMO_REG_CLOCK_GEN5_1	= 0x0030,
	GLAMO_REG_CLOCK_GEN5_2	= 0x0032,
	GLAMO_REG_CLOCK_GEN6	= 0x0034,
	GLAMO_REG_CLOCK_GEN7	= 0x0036,
	GLAMO_REG_CLOCK_GEN8	= 0x0038,
	GLAMO_REG_CLOCK_GEN9	= 0x003a,
	GLAMO_REG_CLOCK_GEN10	= 0x003c,
	GLAMO_REG_CLOCK_GEN11	= 0x003e,
	GLAMO_REG_PLL_GEN1	= 0x0040,
	GLAMO_REG_PLL_GEN2	= 0x0042,
	GLAMO_REG_PLL_GEN3	= 0x0044,
	GLAMO_REG_PLL_GEN4	= 0x0046,
	GLAMO_REG_PLL_GEN5	= 0x0048,
	GLAMO_REG_GPIO_GEN1	= 0x0050,
	GLAMO_REG_GPIO_GEN2	= 0x0052,
	GLAMO_REG_GPIO_GEN3	= 0x0054,
	GLAMO_REG_GPIO_GEN4	= 0x0056,
	GLAMO_REG_GPIO_GEN5	= 0x0058,
	GLAMO_REG_GPIO_GEN6	= 0x005a,
	GLAMO_REG_GPIO_GEN7	= 0x005c,
	GLAMO_REG_GPIO_GEN8	= 0x005e,
	GLAMO_REG_GPIO_GEN9	= 0x0060,
	GLAMO_REG_GPIO_GEN10	= 0x0062,
	GLAMO_REG_DFT_GEN1	= 0x0070,
	GLAMO_REG_DFT_GEN2	= 0x0072,
	GLAMO_REG_DFT_GEN3	= 0x0074,
	GLAMO_REG_DFT_GEN4	= 0x0076,

        GLAMO_REG_PLL_GEN6      = 0x01e0,
        GLAMO_REG_PLL_GEN7      = 0x01f0,
};

#define GLAMO_REG_HOSTBUS(x)	(GLAMO_REGOFS_HOSTBUS-2+(x*2))

#define REG_MEM(x)		(GLAMO_REGOFS_MEMORY+(x))
#define GLAMO_REG_MEM_TIMING(x)	(GLAMO_REG_MEM_TIMING1-2+(x*2))

enum glamo_register_mem {
	GLAMO_REG_MEM_TYPE	= REG_MEM(0x00),
	GLAMO_REG_MEM_GEN	= REG_MEM(0x02),
	GLAMO_REG_MEM_TIMING1	= REG_MEM(0x04),
	GLAMO_REG_MEM_TIMING2	= REG_MEM(0x06),
	GLAMO_REG_MEM_TIMING3	= REG_MEM(0x08),
	GLAMO_REG_MEM_TIMING4	= REG_MEM(0x0a),
	GLAMO_REG_MEM_TIMING5	= REG_MEM(0x0c),
	GLAMO_REG_MEM_TIMING6	= REG_MEM(0x0e),
	GLAMO_REG_MEM_TIMING7	= REG_MEM(0x10),
	GLAMO_REG_MEM_TIMING8	= REG_MEM(0x12),
	GLAMO_REG_MEM_TIMING9	= REG_MEM(0x14),
	GLAMO_REG_MEM_TIMING10	= REG_MEM(0x16),
	GLAMO_REG_MEM_TIMING11	= REG_MEM(0x18),
	GLAMO_REG_MEM_POWER1	= REG_MEM(0x1a),
	GLAMO_REG_MEM_POWER2	= REG_MEM(0x1c),
	GLAMO_REG_MEM_LCD_BUF1	= REG_MEM(0x1e),
	GLAMO_REG_MEM_LCD_BUF2	= REG_MEM(0x20),
	GLAMO_REG_MEM_LCD_BUF3	= REG_MEM(0x22),
	GLAMO_REG_MEM_LCD_BUF4	= REG_MEM(0x24),
	GLAMO_REG_MEM_BIST1	= REG_MEM(0x26),
	GLAMO_REG_MEM_BIST2	= REG_MEM(0x28),
	GLAMO_REG_MEM_BIST3	= REG_MEM(0x2a),
	GLAMO_REG_MEM_BIST4	= REG_MEM(0x2c),
	GLAMO_REG_MEM_BIST5	= REG_MEM(0x2e),
	GLAMO_REG_MEM_MAH1	= REG_MEM(0x30),
	GLAMO_REG_MEM_MAH2	= REG_MEM(0x32),
	GLAMO_REG_MEM_DRAM1	= REG_MEM(0x34),
	GLAMO_REG_MEM_DRAM2	= REG_MEM(0x36),
	GLAMO_REG_MEM_CRC	= REG_MEM(0x38),
};

#define GLAMO_MEM_TYPE_MASK	0x03

enum glamo_reg_mem_dram1 {
	GLAMO_MEM_DRAM1_EN_SDRAM_CLK	= (1 << 11),
	GLAMO_MEM_DRAM1_SELF_REFRESH	= (1 << 12),
};

enum glamo_reg_mem_dram2 {
	GLAMO_MEM_DRAM2_DEEP_PWRDOWN	= (1 << 12),
};

enum glamo_irq_index {
	GLAMO_IRQIDX_HOSTBUS	= 0,
	GLAMO_IRQIDX_JPEG	= 1,
	GLAMO_IRQIDX_MPEG	= 2,
	GLAMO_IRQIDX_MPROC1	= 3,
	GLAMO_IRQIDX_MPROC0	= 4,
	GLAMO_IRQIDX_CMDQUEUE	= 5,
	GLAMO_IRQIDX_2D		= 6,
	GLAMO_IRQIDX_MMC	= 7,
	GLAMO_IRQIDX_RISC	= 8,
};

enum glamo_irq {
	GLAMO_IRQ_HOSTBUS	= (1 << GLAMO_IRQIDX_HOSTBUS),
	GLAMO_IRQ_JPEG		= (1 << GLAMO_IRQIDX_JPEG),
	GLAMO_IRQ_MPEG		= (1 << GLAMO_IRQIDX_MPEG),
	GLAMO_IRQ_MPROC1	= (1 << GLAMO_IRQIDX_MPROC1),
	GLAMO_IRQ_MPROC0	= (1 << GLAMO_IRQIDX_MPROC0),
	GLAMO_IRQ_CMDQUEUE	= (1 << GLAMO_IRQIDX_CMDQUEUE),
	GLAMO_IRQ_2D		= (1 << GLAMO_IRQIDX_2D),
	GLAMO_IRQ_MMC		= (1 << GLAMO_IRQIDX_MMC),
	GLAMO_IRQ_RISC		= (1 << GLAMO_IRQIDX_RISC),
};

enum glamo_reg_clock_host {
	GLAMO_CLOCK_HOST_DG_BCLK	= 0x0001,
	GLAMO_CLOCK_HOST_DG_M0CLK	= 0x0004,
	GLAMO_CLOCK_HOST_RESET		= 0x1000,
};

enum glamo_reg_clock_mem {
	GLAMO_CLOCK_MEM_DG_M1CLK	= 0x0001,
	GLAMO_CLOCK_MEM_EN_M1CLK	= 0x0002,
	GLAMO_CLOCK_MEM_DG_MOCACLK	= 0x0004,
	GLAMO_CLOCK_MEM_EN_MOCACLK	= 0x0008,
	GLAMO_CLOCK_MEM_RESET		= 0x1000,
	GLAMO_CLOCK_MOCA_RESET		= 0x2000,
};

enum glamo_reg_clock_lcd {
	GLAMO_CLOCK_LCD_DG_DCLK		= 0x0001,
	GLAMO_CLOCK_LCD_EN_DCLK		= 0x0002,
	GLAMO_CLOCK_LCD_DG_DMCLK	= 0x0004,
	GLAMO_CLOCK_LCD_EN_DMCLK	= 0x0008,
	//
	GLAMO_CLOCK_LCD_EN_DHCLK	= 0x0020,
	GLAMO_CLOCK_LCD_DG_M5CLK	= 0x0040,
	GLAMO_CLOCK_LCD_EN_M5CLK	= 0x0080,
	GLAMO_CLOCK_LCD_RESET		= 0x1000,
};

enum glamo_reg_clock_mmc {
	GLAMO_CLOCK_MMC_DG_TCLK		= 0x0001,
	GLAMO_CLOCK_MMC_EN_TCLK		= 0x0002,
	GLAMO_CLOCK_MMC_DG_M9CLK	= 0x0004,
	GLAMO_CLOCK_MMC_EN_M9CLK	= 0x0008,
	GLAMO_CLOCK_MMC_RESET		= 0x1000,
};

enum glamo_reg_basic_mmc {
	/* set to disable CRC error rejection */
	GLAMO_BASIC_MMC_DISABLE_CRC	= 0x0001,
	/* enable completion interrupt */
	GLAMO_BASIC_MMC_EN_COMPL_INT	= 0x0002,
	/* stop MMC clock while enforced idle waiting for data from card */
	GLAMO_BASIC_MMC_NO_CLK_RD_WAIT	= 0x0004,
	/* 0 = 1-bit bus to card, 1 = use 4-bit bus (has to be negotiated) */
	GLAMO_BASIC_MMC_EN_4BIT_DATA	= 0x0008,
	/* enable 75K pullups on D3..D0 */
	GLAMO_BASIC_MMC_EN_DATA_PUPS	= 0x0010,
	/* enable 75K pullup on CMD */
	GLAMO_BASIC_MMC_EN_CMD_PUP	= 0x0020,
	/* IO drive strength 00=weak -> 11=strongest */
	GLAMO_BASIC_MMC_EN_DR_STR0	= 0x0040,
	GLAMO_BASIC_MMC_EN_DR_STR1	= 0x0080,
	/* TCLK delay stage A, 0000 = 500ps --> 1111 = 8ns */
	GLAMO_BASIC_MMC_EN_TCLK_DLYA0	= 0x0100,
	GLAMO_BASIC_MMC_EN_TCLK_DLYA1	= 0x0200,
	GLAMO_BASIC_MMC_EN_TCLK_DLYA2	= 0x0400,
	GLAMO_BASIC_MMC_EN_TCLK_DLYA3	= 0x0800,
	/* TCLK delay stage B (cumulative), 0000 = 500ps --> 1111 = 8ns */
	GLAMO_BASIC_MMC_EN_TCLK_DLYB0	= 0x1000,
	GLAMO_BASIC_MMC_EN_TCLK_DLYB1	= 0x2000,
	GLAMO_BASIC_MMC_EN_TCLK_DLYB2	= 0x4000,
	GLAMO_BASIC_MMC_EN_TCLK_DLYB3	= 0x8000,
};

enum glamo_reg_stat1_mmc {
	/* command "counter" (really: toggle) */
	GLAMO_STAT1_MMC_CMD_CTR	= 0x8000,
	/* engine is idle */
	GLAMO_STAT1_MMC_IDLE	= 0x4000,
	/* readback response is ready */
	GLAMO_STAT1_MMC_RB_RRDY	= 0x0200,
	/* readback data is ready */
	GLAMO_STAT1_MMC_RB_DRDY	= 0x0100,
	/* no response timeout */
	GLAMO_STAT1_MMC_RTOUT	= 0x0020,
	/* no data timeout */
	GLAMO_STAT1_MMC_DTOUT	= 0x0010,
	/* CRC error on block write */
	GLAMO_STAT1_MMC_BWERR	= 0x0004,
	/* CRC error on block read */
	GLAMO_STAT1_MMC_BRERR	= 0x0002
};

enum glamo_reg_fire_mmc {
	/* command "counter" (really: toggle)
	 * the STAT1 register reflects this so you can ensure you don't look
	 * at status for previous command
	 */
	GLAMO_FIRE_MMC_CMD_CTR	= 0x8000,
	/* sets kind of response expected */
	GLAMO_FIRE_MMC_RES_MASK	= 0x0700,
	/* sets command type */
	GLAMO_FIRE_MMC_TYP_MASK	= 0x00C0,
	/* sets command class */
	GLAMO_FIRE_MMC_CLS_MASK	= 0x000F,
};

enum glamo_fire_mmc_response_types {
	GLAMO_FIRE_MMC_RSPT_R1	= 0x0000,
	GLAMO_FIRE_MMC_RSPT_R1b	= 0x0100,
	GLAMO_FIRE_MMC_RSPT_R2	= 0x0200,
	GLAMO_FIRE_MMC_RSPT_R3	= 0x0300,
	GLAMO_FIRE_MMC_RSPT_R4	= 0x0400,
	GLAMO_FIRE_MMC_RSPT_R5	= 0x0500,
};

enum glamo_fire_mmc_command_types {
	/* broadcast, no response */
	GLAMO_FIRE_MMC_CMDT_BNR	= 0x0000,
	/* broadcast, with response */
	GLAMO_FIRE_MMC_CMDT_BR	= 0x0040,
	/* addressed, no data */
	GLAMO_FIRE_MMC_CMDT_AND	= 0x0080,
	/* addressed, with data */
	GLAMO_FIRE_MMC_CMDT_AD	= 0x00C0,
};

enum glamo_fire_mmc_command_class {
	/* "Stream Read" */
	GLAMO_FIRE_MMC_CC_STRR	= 0x0000,
	/* Single Block Read */
	GLAMO_FIRE_MMC_CC_SBR	= 0x0001,
	/* Multiple Block Read With Stop */
	GLAMO_FIRE_MMC_CC_MBRS	= 0x0002,
	/* Multiple Block Read No Stop */
	GLAMO_FIRE_MMC_CC_MBRNS	= 0x0003,
	/* RESERVED for "Stream Write" */
	GLAMO_FIRE_MMC_CC_STRW	= 0x0004,
	/* "Stream Write" */
	GLAMO_FIRE_MMC_CC_SBW	= 0x0005,
	/* RESERVED for Multiple Block Write With Stop */
	GLAMO_FIRE_MMC_CC_MBWS	= 0x0006,
	/* Multiple Block Write No Stop */
	GLAMO_FIRE_MMC_CC_MBWNS	= 0x0007,
	/* STOP command */
	GLAMO_FIRE_MMC_CC_STOP	= 0x0008,
	/* Cancel on Running Command */
	GLAMO_FIRE_MMC_CC_CANCL	= 0x0009,
	/* "Basic Command" */
	GLAMO_FIRE_MMC_CC_BASIC	= 0x000a,
};

/* these are offsets from the start of the MMC register region */
enum glamo_register_mmc {
	/* MMC command, b15..8 = cmd arg b7..0; b7..1 = CRC; b0 = end bit */
	GLAMO_REG_MMC_CMD_REG1	= 0x00,
	/* MMC command, b15..0 = cmd arg b23 .. 8 */
	GLAMO_REG_MMC_CMD_REG2	= 0x02,
	/* MMC command, b15=start, b14=transmission,
	 * b13..8=cmd idx, b7..0=cmd arg b31..24
	 */
	GLAMO_REG_MMC_CMD_REG3	= 0x04,
	GLAMO_REG_MMC_CMD_FIRE	= 0x06,
	GLAMO_REG_MMC_CMD_RSP1	= 0x10,
	GLAMO_REG_MMC_CMD_RSP2	= 0x12,
	GLAMO_REG_MMC_CMD_RSP3	= 0x14,
	GLAMO_REG_MMC_CMD_RSP4	= 0x16,
	GLAMO_REG_MMC_CMD_RSP5	= 0x18,
	GLAMO_REG_MMC_CMD_RSP6	= 0x1a,
	GLAMO_REG_MMC_CMD_RSP7	= 0x1c,
	GLAMO_REG_MMC_CMD_RSP8	= 0x1e,
	GLAMO_REG_MMC_RB_STAT1	= 0x20,
	GLAMO_REG_MMC_RB_BLKCNT	= 0x22,
	GLAMO_REG_MMC_RB_BLKLEN	= 0x24,
	GLAMO_REG_MMC_BASIC	= 0x30,
	GLAMO_REG_MMC_RDATADS1	= 0x34,
	GLAMO_REG_MMC_RDATADS2	= 0x36,
	GLAMO_REG_MMC_WDATADS1	= 0x38,
	GLAMO_REG_MMC_WDATADS2	= 0x3a,
	GLAMO_REG_MMC_DATBLKCNT	= 0x3c,
	GLAMO_REG_MMC_DATBLKLEN	= 0x3e,
	GLAMO_REG_MMC_TIMEOUT	= 0x40,

};

enum glamo_reg_clock_isp {
	GLAMO_CLOCK_ISP_DG_I1CLK	= 0x0001,
	GLAMO_CLOCK_ISP_EN_I1CLK	= 0x0002,
	GLAMO_CLOCK_ISP_DG_CCLK		= 0x0004,
	GLAMO_CLOCK_ISP_EN_CCLK		= 0x0008,
	//
	GLAMO_CLOCK_ISP_EN_SCLK		= 0x0020,
	GLAMO_CLOCK_ISP_DG_M2CLK	= 0x0040,
	GLAMO_CLOCK_ISP_EN_M2CLK	= 0x0080,
	GLAMO_CLOCK_ISP_DG_M15CLK	= 0x0100,
	GLAMO_CLOCK_ISP_EN_M15CLK	= 0x0200,
	GLAMO_CLOCK_ISP1_RESET		= 0x1000,
	GLAMO_CLOCK_ISP2_RESET		= 0x2000,
};

enum glamo_reg_clock_jpeg {
	GLAMO_CLOCK_JPEG_DG_JCLK	= 0x0001,
	GLAMO_CLOCK_JPEG_EN_JCLK	= 0x0002,
	GLAMO_CLOCK_JPEG_DG_M3CLK	= 0x0004,
	GLAMO_CLOCK_JPEG_EN_M3CLK	= 0x0008,
	GLAMO_CLOCK_JPEG_RESET		= 0x1000,
};

enum glamo_reg_clock_2d {
	GLAMO_CLOCK_2D_DG_GCLK		= 0x0001,
	GLAMO_CLOCK_2D_EN_GCLK		= 0x0002,
	GLAMO_CLOCK_2D_DG_M7CLK		= 0x0004,
	GLAMO_CLOCK_2D_EN_M7CLK		= 0x0008,
	GLAMO_CLOCK_2D_DG_M6CLK		= 0x0010,
	GLAMO_CLOCK_2D_EN_M6CLK		= 0x0020,
	GLAMO_CLOCK_2D_RESET		= 0x1000,
	GLAMO_CLOCK_2D_CQ_RESET		= 0x2000,
};

enum glamo_reg_clock_3d {
	GLAMO_CLOCK_3D_DG_ECLK		= 0x0001,
	GLAMO_CLOCK_3D_EN_ECLK		= 0x0002,
	GLAMO_CLOCK_3D_DG_RCLK		= 0x0004,
	GLAMO_CLOCK_3D_EN_RCLK		= 0x0008,
	GLAMO_CLOCK_3D_DG_M8CLK		= 0x0010,
	GLAMO_CLOCK_3D_EN_M8CLK		= 0x0020,
	GLAMO_CLOCK_3D_BACK_RESET	= 0x1000,
	GLAMO_CLOCK_3D_FRONT_RESET	= 0x2000,
};

enum glamo_reg_clock_mpeg {
	GLAMO_CLOCK_MPEG_DG_X0CLK	= 0x0001,
	GLAMO_CLOCK_MPEG_EN_X0CLK	= 0x0002,
	GLAMO_CLOCK_MPEG_DG_X1CLK	= 0x0004,
	GLAMO_CLOCK_MPEG_EN_X1CLK	= 0x0008,
	GLAMO_CLOCK_MPEG_DG_X2CLK	= 0x0010,
	GLAMO_CLOCK_MPEG_EN_X2CLK	= 0x0020,
	GLAMO_CLOCK_MPEG_DG_X3CLK	= 0x0040,
	GLAMO_CLOCK_MPEG_EN_X3CLK	= 0x0080,
	GLAMO_CLOCK_MPEG_DG_X4CLK	= 0x0100,
	GLAMO_CLOCK_MPEG_EN_X4CLK	= 0x0200,
	GLAMO_CLOCK_MPEG_DG_X6CLK	= 0x0400,
	GLAMO_CLOCK_MPEG_EN_X6CLK	= 0x0800,
	GLAMO_CLOCK_MPEG_ENC_RESET	= 0x1000,
	GLAMO_CLOCK_MPEG_DEC_RESET	= 0x2000,
};

enum glamo_reg_clock51 {
	GLAMO_CLOCK_GEN51_EN_DIV_MCLK	= 0x0001,
	GLAMO_CLOCK_GEN51_EN_DIV_SCLK	= 0x0002,
	GLAMO_CLOCK_GEN51_EN_DIV_JCLK	= 0x0004,
	GLAMO_CLOCK_GEN51_EN_DIV_DCLK	= 0x0008,
	GLAMO_CLOCK_GEN51_EN_DIV_DMCLK	= 0x0010,
	GLAMO_CLOCK_GEN51_EN_DIV_DHCLK	= 0x0020,
	GLAMO_CLOCK_GEN51_EN_DIV_GCLK	= 0x0040,
	GLAMO_CLOCK_GEN51_EN_DIV_TCLK	= 0x0080,
	/* FIXME: higher bits */
};

enum glamo_reg_hostbus2 {
	GLAMO_HOSTBUS2_MMIO_EN_ISP	= 0x0001,
	GLAMO_HOSTBUS2_MMIO_EN_JPEG	= 0x0002,
	GLAMO_HOSTBUS2_MMIO_EN_MPEG	= 0x0004,
	GLAMO_HOSTBUS2_MMIO_EN_LCD	= 0x0008,
	GLAMO_HOSTBUS2_MMIO_EN_MMC	= 0x0010,
	GLAMO_HOSTBUS2_MMIO_EN_MICROP0	= 0x0020,
	GLAMO_HOSTBUS2_MMIO_EN_MICROP1	= 0x0040,
	GLAMO_HOSTBUS2_MMIO_EN_CQ	= 0x0080,
	GLAMO_HOSTBUS2_MMIO_EN_RISC	= 0x0100,
	GLAMO_HOSTBUS2_MMIO_EN_2D	= 0x0200,
	GLAMO_HOSTBUS2_MMIO_EN_3D	= 0x0400,
};

/* LCD Controller */

#define REG_LCD(x)	(x)
enum glamo_reg_lcd {
	GLAMO_REG_LCD_MODE1		= REG_LCD(0x00),
	GLAMO_REG_LCD_MODE2		= REG_LCD(0x02),
	GLAMO_REG_LCD_MODE3		= REG_LCD(0x04),
	GLAMO_REG_LCD_WIDTH		= REG_LCD(0x06),
	GLAMO_REG_LCD_HEIGHT		= REG_LCD(0x08),
	GLAMO_REG_LCD_POLARITY		= REG_LCD(0x0a),
	GLAMO_REG_LCD_A_BASE1		= REG_LCD(0x0c),
	GLAMO_REG_LCD_A_BASE2		= REG_LCD(0x0e),
	GLAMO_REG_LCD_B_BASE1		= REG_LCD(0x10),
	GLAMO_REG_LCD_B_BASE2		= REG_LCD(0x12),
	GLAMO_REG_LCD_C_BASE1		= REG_LCD(0x14),
	GLAMO_REG_LCD_C_BASE2		= REG_LCD(0x16),
	GLAMO_REG_LCD_PITCH		= REG_LCD(0x18),
	/* RES */
	GLAMO_REG_LCD_HORIZ_TOTAL	= REG_LCD(0x1c),
	/* RES */
	GLAMO_REG_LCD_HORIZ_RETR_START	= REG_LCD(0x20),
	/* RES */
	GLAMO_REG_LCD_HORIZ_RETR_END	= REG_LCD(0x24),
	/* RES */
	GLAMO_REG_LCD_HORIZ_DISP_START	= REG_LCD(0x28),
	/* RES */
	GLAMO_REG_LCD_HORIZ_DISP_END	= REG_LCD(0x2c),
	/* RES */
	GLAMO_REG_LCD_VERT_TOTAL	= REG_LCD(0x30),
	/* RES */
	GLAMO_REG_LCD_VERT_RETR_START	= REG_LCD(0x34),
	/* RES */
	GLAMO_REG_LCD_VERT_RETR_END	= REG_LCD(0x38),
	/* RES */
	GLAMO_REG_LCD_VERT_DISP_START	= REG_LCD(0x3c),
	/* RES */
	GLAMO_REG_LCD_VERT_DISP_END	= REG_LCD(0x40),
	/* RES */
	GLAMO_REG_LCD_POL		= REG_LCD(0x44),
	GLAMO_REG_LCD_DATA_START	= REG_LCD(0x46),
	GLAMO_REG_LCD_FRATE_CONTRO	= REG_LCD(0x48),
	GLAMO_REG_LCD_DATA_CMD_HDR	= REG_LCD(0x4a),
	GLAMO_REG_LCD_SP_START		= REG_LCD(0x4c),
	GLAMO_REG_LCD_SP_END		= REG_LCD(0x4e),
	GLAMO_REG_LCD_CURSOR_BASE1	= REG_LCD(0x50),
	GLAMO_REG_LCD_CURSOR_BASE2	= REG_LCD(0x52),
	GLAMO_REG_LCD_CURSOR_PITCH	= REG_LCD(0x54),
	GLAMO_REG_LCD_CURSOR_X_SIZE	= REG_LCD(0x56),
	GLAMO_REG_LCD_CURSOR_Y_SIZE	= REG_LCD(0x58),
	GLAMO_REG_LCD_CURSOR_X_POS	= REG_LCD(0x5a),
	GLAMO_REG_LCD_CURSOR_Y_POS	= REG_LCD(0x5c),
	GLAMO_REG_LCD_CURSOR_PRESET	= REG_LCD(0x5e),
	GLAMO_REG_LCD_CURSOR_FG_COLOR	= REG_LCD(0x60),
	/* RES */
	GLAMO_REG_LCD_CURSOR_BG_COLOR	= REG_LCD(0x64),
	/* RES */
	GLAMO_REG_LCD_CURSOR_DST_COLOR	= REG_LCD(0x68),
	/* RES */
	GLAMO_REG_LCD_STATUS1		= REG_LCD(0x80),
	GLAMO_REG_LCD_STATUS2		= REG_LCD(0x82),
	GLAMO_REG_LCD_STATUS3		= REG_LCD(0x84),
	GLAMO_REG_LCD_STATUS4		= REG_LCD(0x86),
	/* RES */
	GLAMO_REG_LCD_COMMAND1		= REG_LCD(0xa0),
	GLAMO_REG_LCD_COMMAND2		= REG_LCD(0xa2),
	/* RES */
	GLAMO_REG_LCD_WFORM_DELAY1	= REG_LCD(0xb0),
	GLAMO_REG_LCD_WFORM_DELAY2	= REG_LCD(0xb2),
	/* RES */
	GLAMO_REG_LCD_GAMMA_CORR	= REG_LCD(0x100),
	/* RES */
	GLAMO_REG_LCD_GAMMA_R_ENTRY01	= REG_LCD(0x110),
	GLAMO_REG_LCD_GAMMA_R_ENTRY23	= REG_LCD(0x112),
	GLAMO_REG_LCD_GAMMA_R_ENTRY45	= REG_LCD(0x114),
	GLAMO_REG_LCD_GAMMA_R_ENTRY67	= REG_LCD(0x116),
	GLAMO_REG_LCD_GAMMA_R_ENTRY8	= REG_LCD(0x118),
	/* RES */
	GLAMO_REG_LCD_GAMMA_G_ENTRY01	= REG_LCD(0x130),
	GLAMO_REG_LCD_GAMMA_G_ENTRY23	= REG_LCD(0x132),
	GLAMO_REG_LCD_GAMMA_G_ENTRY45	= REG_LCD(0x134),
	GLAMO_REG_LCD_GAMMA_G_ENTRY67	= REG_LCD(0x136),
	GLAMO_REG_LCD_GAMMA_G_ENTRY8	= REG_LCD(0x138),
	/* RES */
	GLAMO_REG_LCD_GAMMA_B_ENTRY01	= REG_LCD(0x150),
	GLAMO_REG_LCD_GAMMA_B_ENTRY23	= REG_LCD(0x152),
	GLAMO_REG_LCD_GAMMA_B_ENTRY45	= REG_LCD(0x154),
	GLAMO_REG_LCD_GAMMA_B_ENTRY67	= REG_LCD(0x156),
	GLAMO_REG_LCD_GAMMA_B_ENTRY8	= REG_LCD(0x158),
	/* RES */
	GLAMO_REG_LCD_SRAM_DRIVING1	= REG_LCD(0x160),
	GLAMO_REG_LCD_SRAM_DRIVING2	= REG_LCD(0x162),
	GLAMO_REG_LCD_SRAM_DRIVING3	= REG_LCD(0x164),
};

enum glamo_reg_lcd_mode1 {
	GLAMO_LCD_MODE1_PWRSAVE		= 0x0001,
	GLAMO_LCD_MODE1_PARTIAL_PRT	= 0x0002,
	GLAMO_LCD_MODE1_HWFLIP		= 0x0004,
	GLAMO_LCD_MODE1_LCD2		= 0x0008,
	/* RES */
	GLAMO_LCD_MODE1_PARTIAL_MODE	= 0x0020,
	GLAMO_LCD_MODE1_CURSOR_DSTCOLOR	= 0x0040,
	GLAMO_LCD_MODE1_PARTIAL_ENABLE	= 0x0080,
	GLAMO_LCD_MODE1_TVCLK_IN_ENABLE	= 0x0100,
	GLAMO_LCD_MODE1_HSYNC_HIGH_ACT	= 0x0200,
	GLAMO_LCD_MODE1_VSYNC_HIGH_ACT	= 0x0400,
	GLAMO_LCD_MODE1_HSYNC_FLIP	= 0x0800,
	GLAMO_LCD_MODE1_GAMMA_COR_EN	= 0x1000,
	GLAMO_LCD_MODE1_DITHER_EN	= 0x2000,
	GLAMO_LCD_MODE1_CURSOR_EN	= 0x4000,
	GLAMO_LCD_MODE1_ROTATE_EN	= 0x8000,
};

enum glamo_reg_lcd_mode2 {
	GLAMO_LCD_MODE2_CRC_CHECK_EN	= 0x0001,
	GLAMO_LCD_MODE2_DCMD_PER_LINE	= 0x0002,
	GLAMO_LCD_MODE2_NOUSE_BDEF	= 0x0004,
	GLAMO_LCD_MODE2_OUT_POS_MODE	= 0x0008,
	GLAMO_LCD_MODE2_FRATE_CTRL_EN	= 0x0010,
	GLAMO_LCD_MODE2_SINGLE_BUFFER	= 0x0020,
	GLAMO_LCD_MODE2_SER_LSB_TO_MSB	= 0x0040,
	/* FIXME */
};

enum glamo_reg_lcd_mode3 {
	/* LCD color source data format */
	GLAMO_LCD_SRC_RGB565		= 0x0000,
	GLAMO_LCD_SRC_ARGB1555		= 0x4000,
	GLAMO_LCD_SRC_ARGB4444		= 0x8000,
	/* interface type */
	GLAMO_LCD_MODE3_LCD		= 0x1000,
	GLAMO_LCD_MODE3_RGB		= 0x0800,
	GLAMO_LCD_MODE3_CPU		= 0x0000,
	/* mode */
	GLAMO_LCD_MODE3_RGB332		= 0x0000,
	GLAMO_LCD_MODE3_RGB444		= 0x0100,
	GLAMO_LCD_MODE3_RGB565		= 0x0200,
	GLAMO_LCD_MODE3_RGB666		= 0x0300,
	/* depth */
	GLAMO_LCD_MODE3_6BITS		= 0x0000,
	GLAMO_LCD_MODE3_8BITS		= 0x0010,
	GLAMO_LCD_MODE3_9BITS		= 0x0020,
	GLAMO_LCD_MODE3_16BITS		= 0x0030,
	GLAMO_LCD_MODE3_18BITS		= 0x0040,
};

enum glamo_lcd_rot_mode {
        GLAMO_LCD_ROT_MODE_0            = 0x0000,
        GLAMO_LCD_ROT_MODE_180          = 0x2000,
        GLAMO_LCD_ROT_MODE_MIRROR       = 0x4000,
        GLAMO_LCD_ROT_MODE_FLIP         = 0x6000,
        GLAMO_LCD_ROT_MODE_90           = 0x8000,
        GLAMO_LCD_ROT_MODE_270          = 0xa000,
};
#define GLAMO_LCD_ROT_MODE_MASK         0xe000

enum glamo_lcd_cmd_type {
	GLAMO_LCD_CMD_TYPE_DISP		= 0x0000,
	GLAMO_LCD_CMD_TYPE_PARALLEL	= 0x4000,
	GLAMO_LCD_CMD_TYPE_SERIAL	= 0x8000,
	GLAMO_LCD_CMD_TYPE_SERIAL_DIRECT= 0xc000,
};
#define GLAMO_LCD_CMD_TYPE_MASK		0xc000

enum glamo_lcd_cmds {
	GLAMO_LCD_CMD_DATA_DISP_FIRE	= 0x00,
	GLAMO_LCD_CMD_DATA_DISP_SYNC	= 0x01,		/* RGB only */
	/* switch to command mode, no display */
	GLAMO_LCD_CMD_DATA_FIRE_NO_DISP	= 0x02,
	/* display until VSYNC, switch to command */
	GLAMO_LCD_CMD_DATA_FIRE_VSYNC	= 0x11,
	/* display until HSYNC, switch to command */
	GLAMO_LCD_CMD_DATA_FIRE_HSYNC	= 0x12,
	/* display until VSYNC, 1 black frame, VSYNC, switch to command */
	GLAMO_LCD_CMD_DATA_FIRE_VSYNC_B	= 0x13,
	/* don't care about display and switch to command */
	GLAMO_LCD_CMD_DATA_FIRE_FREE	= 0x14,		/* RGB only */
	/* don't care about display, keep data display but disable data,
	 * and switch to command */
	GLAMO_LCD_CMD_DATA_FIRE_FREE_D	= 0x15,		/* RGB only */
};

enum glamo_core_revisions {
	GLAMO_CORE_REV_A0		= 0x0000,
	GLAMO_CORE_REV_A1		= 0x0001,
	GLAMO_CORE_REV_A2		= 0x0002,
	GLAMO_CORE_REV_A3		= 0x0003,
};

#endif /* _GLAMO_REGS_H */