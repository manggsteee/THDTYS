/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v16.0
processor: K32L3A60xxx
package_id: K32L3A60VPJ1A
mcu_data: ksdk2_0
processor_version: 16.3.0
external_user_signals: {}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm4, enableClock: 'true'}
- pin_list:
  - {pin_num: N2, peripheral: LPUART0, signal: RX, pin_signal: LPCMP0_IN0/PTC7/LLWU_P15/LPSPI0_PCS3/LPUART0_RX/LPI2C1_HREQ/TPM0_CH0/LPTMR1_ALT1}
  - {pin_num: P3, peripheral: LPUART0, signal: TX, pin_signal: LPCMP0_IN1/PTC8/LPSPI0_SCK/LPUART0_TX/LPI2C0_HREQ/TPM0_CH1}
  - {pin_num: D6, peripheral: TPM2, signal: 'CH, 0', pin_signal: PTA24/LPSPI2_PCS0/LPSPI1_SCK/LPI2C2_SCL/FB_OE_b/TPM2_CH0}
  - {pin_num: E6, peripheral: TPM2, signal: 'CH, 1', pin_signal: PTA23/LPSPI2_SIN/LPSPI1_PCS3/LPI2C2_SDA/FB_AD15/TPM2_CH1}
  - {pin_num: G2, peripheral: LPI2C1, signal: SCL, pin_signal: PTB14/LPUART2_RTS/LPI2C1_SCL/LPI2C0_SCLS/FB_AD24/TPM3_CH1/FXIO0_D4}
  - {pin_num: G3, peripheral: LPI2C1, signal: SDA, pin_signal: PTB13/LPUART2_CTS/LPI2C1_SDA/LPI2C0_SDAS/FB_AD25/TPM3_CH0/FXIO0_D3}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M4F */
void BOARD_InitPins(void)
{
    /* Clock Gate Control: Clock enabled. The current clock selection and divider options are locked. */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Clock Gate Control: Clock enabled. The current clock selection and divider options are locked. */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Clock Gate Control: Clock enabled. The current clock selection and divider options are locked. */
    CLOCK_EnableClock(kCLOCK_PortC);

    /* PORTA23 (pin E6) is configured as TPM2_CH1 */
    PORT_SetPinMux(PORTA, 23U, kPORT_MuxAlt6);

    /* PORTA24 (pin D6) is configured as TPM2_CH0 */
    PORT_SetPinMux(PORTA, 24U, kPORT_MuxAlt6);

    /* PORTB13 (pin G3) is configured as LPI2C1_SDA */
    PORT_SetPinMux(PORTB, 13U, kPORT_MuxAlt3);

    /* PORTB14 (pin G2) is configured as LPI2C1_SCL */
    PORT_SetPinMux(PORTB, 14U, kPORT_MuxAlt3);

    /* PORTC7 (pin N2) is configured as LPUART0_RX */
    PORT_SetPinMux(PORTC, 7U, kPORT_MuxAlt3);

    /* PORTC8 (pin P3) is configured as LPUART0_TX */
    PORT_SetPinMux(PORTC, 8U, kPORT_MuxAlt3);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_I2C_ConfigurePins:
- options: {callFromInitBoot: 'false', coreID: cm4, enableClock: 'true'}
- pin_list:
  - {pin_num: G17, peripheral: LPI2C3, signal: SCL, pin_signal: PTE30/LPUART3_TX/LPI2C3_SCL/TPM2_CLKIN/FXIO0_D31, slew_rate: fast, open_drain: enable, pull_select: up,
    pull_enable: enable}
  - {pin_num: G15, peripheral: LPI2C3, signal: SDA, pin_signal: PTE29/LPUART3_RX/LPI2C3_SDA/FXIO0_D30}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_I2C_ConfigurePins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M4F */
void BOARD_I2C_ConfigurePins(void)
{
    /* Clock Gate Control: Clock enabled. The current clock selection and divider options are locked. */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTE29 (pin G15) is configured as LPI2C3_SDA */
    PORT_SetPinMux(PORTE, 29U, kPORT_MuxAlt3);

    const port_pin_config_t porte30_pinG17_config = {/* Internal pull-up resistor is enabled */
                                                     kPORT_PullUp,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain is enabled */
                                                     kPORT_OpenDrainEnable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as LPI2C3_SCL */
                                                     kPORT_MuxAlt3,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORTE30 (pin G17) is configured as LPI2C3_SCL */
    PORT_SetPinConfig(PORTE, 30U, &porte30_pinG17_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
