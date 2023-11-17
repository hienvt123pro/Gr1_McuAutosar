/**
*   @file    Mcu_PBcfg.c
*   @implements Mcu_PBcfg.c_Artifact
*   @version 1.0.4
*
*   @brief   AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.3 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.4
*   Build Version        : S32K1XX_MCAL_1_0_4_RTM_ASR_REL_4_3_REV_0001_04-Apr-22
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc.
*       Copyright 2017-2022 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mcu.h"

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/**
* @brief          Initialization RAM data.
* @details        Static configuration realized by calling Mcu_InitRamSection() API.
*
*/
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_RamConfigPB0[2] =
{
	/*Start of Ram Section 1*/
	{
		/* Ram Sector configuration ID. */
		(Mcu_RamSectionType)0U,

		/* RAM section base address: Start of Mcu_RamConfig[0]. */
		(uint8 (*)[1U])0x1ffffc00U,

		/* RAM section size: Section base address (must be aligned to 4 bytes). */
		(Mcu_RamSectionType)0x00000064U,

		/* RAM default value. */
		(uint64) ( ((uint64)0x55U << 0U) | ((uint64)0x55U << 8U) ),

		/* RAM section write size (maximum allowed: 8). */
		(Mcu_RamWriteSizeType)1U
	}, /* End of Mcu_Ram_ConfigPB[0]. */

	/*Start of Ram Section 2*/
	{
		/* Ram Sector configuration ID. */
		(Mcu_RamSectionType)1U,

		/* RAM section base address: Start of Mcu_RamConfig[1]. */
		(uint8 (*)[1U])0x1ffffc64U,

		/* RAM section size: Section base address (must be aligned to 4 bytes). */
		(Mcu_RamSectionType)0x0000012cU,

		/* RAM default value. */
		(uint64) ( ((uint64)0xaaU << 0U) | ((uint64)0xaaU << 8U) ),

		/* RAM section write size (maximum allowed: 8). */
		(Mcu_RamWriteSizeType)1U

	} /* End of Mcu_Ram_ConfigPB[1]. */
};



/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST(Mcu_ModeConfigType, MCU_CONST) Mcu_Mode_ConfigPB0[1] =
{
    /* Start of Mcu_ModeConfig[0]*/
    {
        /* The ID for Power Mode configuration. */
        (uint8)0U,

        /* Power Mode */
        (Mcu_PowerModeType)MCU_RUN_MODE
    }
    /* end of Mcu_Mode_ConfigPB0[0]. */
};


/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_ChipSelectionRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_CHIPCTL_ADDR32,

	/* Data configuration for SIM register. */
	(
		SIM_CHIPCTL_TRACECLK_CORE_CLK_U32 |
		SIM_CHIPCTL_CLKOUT_DISABLE_U32 |
		SIM_CHIPCTL_CLKOUTDIV_U32((uint32)0U) |
		SIM_CHIPCTL_CLKOUTSEL_SCG_CLKOUT_U32
	)
};
/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_ChipSelectionConfigType, MCU_CONST) Mcu_SIM_ChipSelectionConfigPB0 =
{
	/* Pointer to SIM_CHIPCTL register configuration. */
	&Mcu_SIM_ChipSelectionRegisterConfigPB0
};


/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_TraceClockRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_CLKDIV4_ADDR32,

	/* Data configuration for SIM register. */
	(
		SIM_DEBUG_TRACE_DIVIDER_ENABLED_U32 |
		SIM_CLKDIV4_TRACEDIV_U32((uint32)1U) |
		SIM_CLKDIV4_TRACEFRAC_0_U32
	)
};

/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_TraceClockConfigType, MCU_CONST) Mcu_SIM_TraceClockConfigPB0 =
{
		/* SIM system clock divider register 4. */
		&Mcu_SIM_TraceClockRegisterConfigPB0
};

/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_ClockGatingRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_PLATCGC_ADDR32,

	/* Data configuration for SIM register. */
	(
		SIM_PLATGC_EIM_CLK_ENABLE_U32 |
		SIM_PLATGC_ERM_CLK_ENABLE_U32 |
		SIM_PLATGC_DMA_CLK_ENABLE_U32 |
		SIM_PLATGC_MPU_CLK_ENABLE_U32 |
		SIM_PLATGC_MSCM_CLK_ENABLE_U32
	)
};
/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_ClockGatingConfigType, MCU_CONST) Mcu_SIM_ClockGatingConfigPB0 =
{
		/* SIM_PLATCGC register configuration. */
		&Mcu_SIM_ClockGatingRegisterConfigPB0
};

/**
* @brief          Initialization data for SIM clock module.
* @details        Static configuration realized at statup by calling Mcu_SIM_ClockInit() API.
*
*/
static CONST(Mcu_SIM_ClockConfigType, MCU_CONST) Mcu_SIM_ClockConfigPB0 =
{
	/* Pointer to SIM chip selection configuration. */
	&Mcu_SIM_ChipSelectionConfigPB0,

	/* Pointer to system clock divider register 4. */
	&Mcu_SIM_TraceClockConfigPB0,

	/* Pointer to platform clock gating control register. */
	&Mcu_SIM_ClockGatingConfigPB0
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST) Mcu_SOSCCSR_RegisterConfigPB0 =
{
	/* SCG_SOSCCSR settings. */
	SCG_SOSCCSR_ADDR32,
	(
		 SCG_SOSCCSR_SOSC_ENABLE_U32 |
		 SCG_SOSCCSR_SOSCCMRE_RESET_U32 |
		 SCG_SOSCCSR_SOSCCM_ENA_U32
	)
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_SOSCDIV_RegisterConfigPB0 =
{
	/* SCG_SOSCDIV settings. */
	SCG_SOSCDIV_ADDR32,
	(
		SCG_SOSCDIV_SOSCDIV2_U32((uint32)1U) |
		SCG_SOSCDIV_SOSCDIV1_U32((uint32)1U)
	)
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_SOSCCFG_RegisterConfigPB0 =
{
	/* SCG_SOSCDIV settings. */
	SCG_SOSCCFG_ADDR32,
    (
        SCG_SOSCCFG_HIGH_FREQ_RANGE_U32 |
        SCG_SOSCCFG_INTERNAL_OSCILLATOR_U32 |
        SCG_SOSCCFG_LOW_POWER_OPERATION_U32
    )
};


/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_SOSC_RegisterConfigType, MCU_CONST)SOSC_ClockConfigPB0 =
{
	/**< @brief The address for SCG register. */
	&Mcu_SOSCCSR_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_SOSCDIV_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_SOSCCFG_RegisterConfigPB0
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_SPLLCSR_RegisterConfigPB0 =
{
	/* SCG_SPLLCSR settings. */
	SCG_SPLLCSR_ADDR32,
	(
		SCG_SPLLCSR_SPLL_ENABLE_U32 |
		SCG_SPLLCSR_SPLLCMRE_RESET_U32 |
		SCG_SPLLCSR_SPLLCM_ENA_U32
	)
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_SPLLDIV_RegisterConfigPB0 =
{
	/* SCG_SPLLDIV settings. */
	SCG_SPLLDIV_ADDR32,
	(
		SCG_SPLLDIV_SPLLDIV2_U32((uint32)2U) |
		SCG_SPLLDIV_SPLLDIV1_U32((uint32)1U)
	)

};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_SPLLCFG_RegisterConfigPB0 =
{
	/* SCG_SPLLCFG settings. */
	SCG_SPLLCFG_ADDR32,
	(
		SCG_SPLLCFG_PREDIV_U32((uint32)0U) |
		SCG_SPLLCFG_MULT_U32((uint32)8U) |
		SCG_SPLLCFG_SOURCE_SOSC_U32
	)
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_SPLL_RegisterConfigType, MCU_CONST) SPLL_ClockConfigPB0 =
{
	/**< @brief The address for SCG register. */
	&Mcu_SPLLCSR_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_SPLLDIV_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_SPLLCFG_RegisterConfigPB0
};


/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_FIRCCSR_RegisterConfigPB0 =
{
	/* SCG_SPLLCSR settings. */
	SCG_FIRCCSR_ADDR32,
	(
		SCG_FIRCCSR_FIRC_ENABLE_U32 |
        SCG_FIRCCSR_REGULATOR_ENABLE_U32
	)
};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_FIRCDIV_RegisterConfigPB0 =
{
	/* SCG_SPLLDIV settings. */
	SCG_FIRCDIV_ADDR32,
	(
		SCG_FIRCDIV_FIRCDIV2_U32((uint32)1U) |
		SCG_FIRCDIV_FIRCDIV1_U32((uint32)1U)
	)

};

/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_RegisterConfigType, MCU_CONST)Mcu_FIRCCFG_RegisterConfigPB0 =
{
	/* SCG_SPLLCFG settings. */
	SCG_SPLLCFG_ADDR32,
	(
	    SCG_FIRCCFG_48MHZ_U32
	)
};



/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_FIRC_RegisterConfigType, MCU_CONST) FIRC_ClockConfigPB0 =
{
	/**< @brief The address for SCG register. */
	&Mcu_FIRCCSR_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_FIRCDIV_RegisterConfigPB0,

	/**< @brief data configuration for SCG register. */
	&Mcu_FIRCCFG_RegisterConfigPB0
};


/**
* @brief          Initialization data for SCG module.
* @details        Static configuration realized at statup by calling Mcu_SCG_Init() API.
*
*/
static CONST(Mcu_SCG_ConfigType, MCU_CONST) Mcu_SCG_ConfigPB0 =
{
	/* Run Clock Config(SCG_RCCR) */
	(
		SCG_SCS_SPLL_U32 |
		SCG_DIVCORE_U32((uint32)3U) |
		SCG_DIVBUS_U32((uint32)3U) |
		SCG_DIVSLOW_U32((uint32)7U)
	),

	/* VLPR Clock Config(SCG_VCCR) */
	(
		SCG_SCS_SIRC_U32 |
		SCG_DIVCORE_U32((uint32)7U) |
		SCG_DIVBUS_U32((uint32)0U) |
		SCG_DIVSLOW_U32((uint32)3U)
	),

	/* High Speed Run Clock Config(SCG_HCCR) */
	(
		SCG_SCS_FIRC_U32 |
		SCG_DIVCORE_U32((uint32)3U) |
		SCG_DIVBUS_U32((uint32)3U) |
		SCG_DIVSLOW_U32((uint32)7U)
	),

	/* SCG ClockOut Config */
	SCG_CLKOUTCNFG_CLKOUTSEL_FIRC_U32,

	/* SOSC Config */
	&SOSC_ClockConfigPB0,

	/* SIRC Config */
	(NULL_PTR),

	/* FIRC Config */
	&FIRC_ClockConfigPB0,

	/* SPLL Config */
	&SPLL_ClockConfigPB0
};


static CONST(Mcu_PCC_RegisterConfigType, MCU_CONST) PCC_aRegistersConfigPB0[MCU_NUMBER_OF_PCC_REGISTERS_U32] =
{
   {
		PCC_FTFC_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_DMAMUX0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_FLEXCAN0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_FLEXCAN1_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_FTM3_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_ADC1_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_FLEXCAN2_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_LPSPI0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_LPSPI1_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_LPSPI2_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_PDB1_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_CRC_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_PDB0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_LPIT_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_FTM0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_FTM1_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_FTM2_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_ADC0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_RTC_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_LPTMR0_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
			 |
			PCC_FRAC_0_U32 |
			PCC_PCD_U32((uint32)0)

		)
	}

	,
	{
		PCC_PORTA_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_PORTB_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_PORTC_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_PORTD_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_PORTE_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_FLEXIO_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_EWM_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

	,
	{
		PCC_LPI2C0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_LPUART0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_LPUART1_ADDR32,
		(
			PCC_CLOCK_ENABLED_U32
			 | PCC_PCS_FIRC_U32

		)
	}

	,
	{
		PCC_LPUART2_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32

		)
	}

	,
	{
		PCC_CMP0_ADDR32,
		(
			PCC_CLOCK_DISABLED_U32
			 | PCC_PCS_UNAVAILABLE_U32

		)
	}

};


/**
* @brief          Initialization data for PCC module.
* @details        Static configuration realized at statup by calling Mcu_PCC_Init() API.
*
*/
static CONST(Mcu_PCC_ConfigType, MCU_CONST) Mcu_PCC_ConfigPB0 =
{
	/* Number of PCC configuration. */
	(uint32)MCU_NUMBER_OF_PCC_REGISTERS_U32,

	/* Pointer to PCC register configuration. */
	&PCC_aRegistersConfigPB0
};


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Initialization clock data.
* @details        Static configuration realized by calling Mcu_InitClock() API.
*
*/
static CONST(Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfigPB0[1] =
{
	/* Start of Mcu_ClockConfig[0]. */
	{
		/* The ID for Clock configuration. */
		(Mcu_ClockType)0U,

		/* Pointer SIM Clock configuration. */
		&Mcu_SIM_ClockConfigPB0,

		/* Pointer SCG configuration. */
		&Mcu_SCG_ConfigPB0,

		/* Pointer PCC configuration. */
		&Mcu_PCC_ConfigPB0,

		/* Clock sources is PLLs under mcu control. */
		(uint8)MCU_SPLL_CLK_SRC
	} /* end of Mcu_ClockConfig[0] */
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */



/**
* @brief          Initialization data for SMC module.
* @details        Static configuration realized at statup by calling Mcu_SMC_Init() API.
*
*/
static CONST(Mcu_SMC_ConfigType, MCU_CONST) Mcu_SMC_ConfigPB0 =
{
	 /*Power Mode Protection register (SMC_PMPROT)*/
	 (SMC_PMPROT_HSRUN_NOT_ALLOWED_U32 | SMC_PMPROT_VLP_NOT_ALLOWED_U32),

	 /*Power Mode Control register (SMC_PMCTRL)*/
	 (uint32)0U,

	 /*Power Mode Control register (SMC_PMCTRL)*/
	 (uint32)0U,

	 /*Power Mode Status register (SMC_PMSTAT)*/
	 (uint32)0U
};


/**
* @brief          Initialization data for PMC module.
* @details        Static configuration realized at statup by calling Mcu_PMC_Init() API.
*
*/
static CONST(Mcu_PMC_ConfigType, MCU_CONST) Mcu_PMC_ConfigPB0 =
{
		/* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1). This register only exist on 1xx series of devices */
		(

			PMC_LVDSC1_LVD_DISABLE_U8 |
			PMC_LVDSC1_LVDRE_DISABLE_U8

		),

		/* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
		(
			PMC_LVDSC2_LVW_DISABLE_U8
		),

		/* Regulator Status and Control Register (PMC_REGSC) */
		(
			PMC_REGSC_LPO_ENABLE_U8 |
			PMC_REGSC_CLKBIAS_ENABLE_U8 |
			PMC_REGSC_BIAS_DISABLE_U8
		),

		/* Low Power Oscillator Trim Register (LPOTRIM) */
		PMC_LPOTRIM_LPOTRIM_U8(0)
};


/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_ChipControlRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_CHIPCTL_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM ChipControlConfiguration */
	(uint32)(SIM_CHIPCTL_DISABLE_ADC_SUPPLY_MON_U32 |
	        SIM_CHIPCTL_ADC_SUPPLY_VDDA_U32 |
	        SIM_CHIPCTL_NO_INTERLEAVE_CHANNEL_U32)
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_ChipControlConfigType, MCU_CONST) Mcu_SIM_ChipControlConfigurationPB0 =
{
	/* Pointer to SIM_CHIPCTL register configuration. */
	&Mcu_SIM_ChipControlRegisterConfigPB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_LPOCLKSRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_LPOCLKS_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM LPO clock configuration */
	(uint32)(
	        SIM_RTCCLKSEL_SOSCDIV1_CLK_U32 |
	        SIM_LPOCLKSEL_LPO_CLK_128K_U32 |
	        SIM_ENABLE_32KHZ_LPO_CLK_U32 |
	        SIM_ENABLE_1KHZ_LPO_CLK_U32)
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_LPOCLKSConfigType, MCU_CONST) Mcu_SIM_LPOClockConfigurationPB0 =
{
	/* Pointer to SIM_LPOCLKS register configuration. */
	&Mcu_SIM_LPOCLKSRegisterConfigPB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_ADCOPTRegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_ADCOPT_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM ADC Configuration */
	(uint32)
    (
        SIM_ADC1_PDB_PRE_TRIGGER_U32 |
        SIM_ADC1_SW_PRE_TRIGGER_DISABLE_U32 |
        SIM_ADC1_PDB_TRIGGER_SOURCE_U32 |
        SIM_ADC0_PDB_PRE_TRIGGER_U32 |
        SIM_ADC0_SW_PRE_TRIGGER_DISABLE_U32 |
        SIM_ADC0_PDB_TRIGGER_SOURCE_U32
    )
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_ADCOPTConfigType, MCU_CONST) Mcu_SIM_AdcOptionsConfigurationPB0 =
{
	/* Pointer to SIM_ADCOPT register configuration. */
	&Mcu_SIM_ADCOPTRegisterConfigPB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_FTMOPT0RegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_FTMOPT0_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM FTMOPT0 Configuration */
	(uint32)
    (
        SIM_FTM3CLKSEL_TCLK0_PIN_U32 |
        SIM_FTM2CLKSEL_TCLK0_PIN_U32 |
        SIM_FTM1CLKSEL_TCLK0_PIN_U32 |
        SIM_FTM0CLKSEL_TCLK0_PIN_U32 |
		SIM_FTM3_FLT0_PIN_FLT0_U32 |
        SIM_FTM3_FLT1_PIN_FLT1_U32 |
        SIM_FTM3_FLT2_PIN_FLT2_U32 |
        SIM_FTM2_FLT0_PIN_FLT0_U32 |
        SIM_FTM2_FLT1_PIN_FLT1_U32 |
        SIM_FTM2_FLT2_PIN_FLT2_U32 |
        SIM_FTM1_FLT0_PIN_FLT0_U32 |
        SIM_FTM1_FLT1_PIN_FLT1_U32 |
        SIM_FTM1_FLT2_PIN_FLT2_U32 |
        SIM_FTM0_FLT0_PIN_FLT0_U32 |
        SIM_FTM0_FLT1_PIN_FLT1_U32 |
        SIM_FTM0_FLT2_PIN_FLT2_U32
    )
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_FTMOPT0ConfigType, MCU_CONST) Mcu_SIM_FTMOPT0ConfigurationPB0 =
{
	/* Pointer to FTMOPT0 register configuration. */
	&Mcu_SIM_FTMOPT0RegisterConfigPB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_FTMOPT1RegisterConfigPB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_FTMOPT1_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM FTMOPT1 Configuration */
	(uint32)
	 (
		SIM_FTMOPT1_FTM3OUTSEL_U32((0x00U)) |
		SIM_FTMOPT1_FTM0OUTSEL_U32((0x00U)) |
		SIM_FTM_GLOBAL_LOAD_DISABLED_U32 |
		SIM_FTM2CH1SEL_FTM2_CH1_U32 |
		SIM_FTM2CH0SEL_FTM2_CH0_INPUT_U32 |
		SIM_FTM1CH0SEL_FTM1_CH0_INPUT_U32
	  ),
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_FTMOPT1ConfigType, MCU_CONST) Mcu_SIM_FTMOPT1ConfigurationPB0 =
{
	/* Pointer to FTMOPT0 register configuration. */
	&Mcu_SIM_FTMOPT1RegisterConfigPB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_MiscellaneousRegisterConfig0PB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_MISCTRL0_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM Miscellaneous Control configuration 0 */
	(uint32)
	(
		SIM_FTM3_OUTPUT_SAFE_STATE_U32 |
		SIM_FTM2_OUTPUT_SAFE_STATE_U32 |
		SIM_FTM1_OUTPUT_SAFE_STATE_U32 |
		SIM_FTM0_OUTPUT_SAFE_STATE_U32 |
		SIM_FTM_GTB_SPLIT_DIS_U32
	)
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_MISCTRL0ConfigType, MCU_CONST) Mcu_SIM_MiscellaneousConfiguration0PB0 =
{
	/* Pointer to MISCTRL0 register configuration. */
	&Mcu_SIM_MiscellaneousRegisterConfig0PB0
};



/**
* @brief          Initialization data for SIM register.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_RegisterConfigType, MCU_CONST) Mcu_SIM_MiscellaneousRegisterConfig1PB0 =
{
	/* The address for SIM register. */
	(uint32)SIM_MISCTRL1_ADDR32,

	/* Data configuration for SIM register. */
	/* SIM Miscellaneous Control configuration 1 */
	(uint32)
    (
        (0x0U)
    )
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_MISCTRL1ConfigType, MCU_CONST) Mcu_SIM_MiscellaneousConfiguration1PB0 =
{
	/* Pointer to MISCTRL1 register configuration. */
	&Mcu_SIM_MiscellaneousRegisterConfig1PB0
};


/**
* @brief          Initialization data for SIM module.
* @details        Static configuration realized at statup by calling Mcu_SIM_Init() API.
*
*/
static CONST(Mcu_SIM_ConfigType, MCU_CONST) Mcu_SIM_ConfigPB0 =
{
	/* Pointer to SIM Chip control configuration. */
	&Mcu_SIM_ChipControlConfigurationPB0,

    /* Pointer to LPO Clock Config. */
	&Mcu_SIM_LPOClockConfigurationPB0,

    /* Pointer to ADC configuration. */
	&Mcu_SIM_AdcOptionsConfigurationPB0,

    /* Pointer to FTMOPT0 Config. */
	&Mcu_SIM_FTMOPT0ConfigurationPB0,

    /* Pointer to FTMOPT1 configuration. */
	&Mcu_SIM_FTMOPT1ConfigurationPB0,

    /* Pointer to SIM Miscellaneous Control configuration. */
	&Mcu_SIM_MiscellaneousConfiguration0PB0,

    /* Pointer to SIM Miscellaneous Control configuration. */
	&Mcu_SIM_MiscellaneousConfiguration1PB0
};



/**
* @brief          Initialization data for Mcu dependent properties.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_DepProsConfigType, MCU_CONST) Mcu_DepProsConfigPB0 =
{
	/* Pointer to SMC configuration */
	&Mcu_SMC_ConfigPB0,

	/* Pointer to PMC configuration */
	&Mcu_PMC_ConfigPB0,

	/* Pointer to SIM configuration */
	&Mcu_SIM_ConfigPB0,
};


/**
* @brief          Initialization data for Mcu RCM Register.
* @details        Static configuration realized at statup by calling Mcu_RCM_Init() API.
*
*/
static CONST(Mcu_RCM_RegisterConfigType, MCU_CONST) Mcu_RCM_ResetPinControlRegisterConfigPB0 =
{
	/* The address for RCM register. */
	(uint32) RCM_RPC_ADDR32,

	/* Data configuration for RCM register. */
	/* Reset Pin Control register (RCM_RPC) */
	(uint32)(RCM_RPC_STOP_ALL_FILTERING_DISABLE_U32 |
	        RCM_RPC_NORMAL_ALL_FILTERING_DISABLE_U32 |
	        RCM_RPC_RSTFLTSEL_U32((uint32)(0U)))
};


/**
* @brief          Initialization data for RCM Reset Pin Control.
* @details        Static configuration realized at statup by calling Mcu_RCM_Init() API.
*
*/
static CONST(Mcu_RCM_ResetPinControlConfigType, MCU_CONST) Mcu_RCM_ResetPinControlConfigPB0 =
{
	/* Pointer to RCM_CHIPCTL register configuration */
	&Mcu_RCM_ResetPinControlRegisterConfigPB0
};



/**
* @brief          Initialization data for Mcu RCM Register.
* @details        Static configuration realized at statup by calling Mcu_RCM_Init() API.
*
*/
static CONST(Mcu_RCM_RegisterConfigType, MCU_CONST) Mcu_RCM_ResetInterruptEnableRegisterConfigPB0 =
{
	/* The address for RCM register. */
	(uint32) RCM_SRIE_ADDR32,

	/* Data configuration for RCM register. */
	/* System Reset Interrupt Enable Register (RCM_SRIE) */
	(uint32)(
	        RCM_SRIE_SACKERR_INT_DIS_U32 |
	        RCM_SRIE_MDM_AP_INT_DIS_U32 |
	        RCM_SRIE_SSW_INT_DIS_U32 |
	        RCM_SRIE_LOCKUP_INT_DIS_U32 |
	        RCM_SRIE_JTAG_INT_DIS_U32 |
	        RCM_SRIE_GIE_INT_DIS_U32 |
	        RCM_SRIE_PIN_INT_DIS_U32 |
	        RCM_SRIE_WDOG_INT_DIS_U32 |
	        RCM_SRIE_CMU_INT_DIS_U32 |
	        RCM_SRIE_LOL_INT_DIS_U32 |
	        RCM_SRIE_LOC_INT_DIS_U32 |
	        RCM_SRIE_DELAY_10_LPO_CYCLES_U32
	    )
};


/**
* @brief          Initialization data for Mcu dependent properties.
* @details        Static configuration realized at statup by calling Mcu_RCM_Init() API.
*
*/
static CONST(Mcu_RCM_ResetInterruptEnableConfigType, MCU_CONST) Mcu_RCM_ResetInterruptEnableConfigPB0 =
{
	/* Pointer RCM_CHIPCTL register configuration. */
	&Mcu_RCM_ResetInterruptEnableRegisterConfigPB0
};



/**
* @brief          Initialization data for RCM module.
* @details        Static configuration realized at statup by calling Mcu_RCM_Init() API.
*
*/
static CONST(Mcu_RCM_ConfigType, MCU_CONST) Mcu_RCM_ConfigPB0 =
{
	/* Pointer to RCM chip selection configuration. */
	&Mcu_RCM_ResetPinControlConfigPB0,

	/* Pointer RCM system clock divider register 4. */
	&Mcu_RCM_ResetInterruptEnableConfigPB0
};


/**
* @brief          Initialization data for Mcu dependent properties.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_ResetConfigType, MCU_CONST) Mcu_ResetConfigPB0 =
{
	/* Pointer to RCM configuration */
	&Mcu_RCM_ConfigPB0,
};


/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
CONST(Mcu_ConfigType, MCU_CONST) Mcu_Config =
{
	/* Number of RAM Sections configurations. */
	(Mcu_RamSectionType)2U,

    /* Number of Power Modes configurations. */
    (Mcu_ModeType)1U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Number of Clock Setting configurations. */
    (Mcu_ClockType)1U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to RAM data configuration. */
	&Mcu_RamConfigPB0,

    /* Pointer to Power Mode configurations. */
    &Mcu_Mode_ConfigPB0,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configurations. */
    &Mcu_ClockConfigPB0,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to Mcu Dependent Properties configuration. */
    &Mcu_DepProsConfigPB0,

	/* Pointer to Mcu Reset configuration. */
	&Mcu_ResetConfigPB0
};



/*==================================================================================================
								   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
									   LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
									   GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
