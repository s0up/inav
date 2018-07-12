/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include "platform.h"
#include "drivers/io.h"

#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

const timerHardware_t timerHardware[] = {
    { TIM5, IO_TAG(PA3), TIM_Channel_4, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM5, TIM_USE_PPM }, //PPM

/*
#if defined(OMNIBUSF4SD) || defined(EXUAVF4PRO)
    DEF_TIM(TIM10, CH1, PB8,  TIM_USE_PWM | TIM_USE_PPM,   0, 0), // PPM
    DEF_TIM(TIM4,  CH4, PB9,  TIM_USE_PWM,                 0, 0), // S2_IN
#else
    DEF_TIM(TIM12, CH1, PB14, TIM_USE_PWM | TIM_USE_PPM,   0, 0), // PPM
    DEF_TIM(TIM12, CH2, PB15, TIM_USE_PWM,                 0, 0), // S2_IN
#endif

    DEF_TIM(TIM8,  CH1, PC6,  TIM_USE_PWM,                 0, 0), // S3_IN, UART6_TX
    DEF_TIM(TIM8,  CH2, PC7,  TIM_USE_PWM,                 0, 0), // S4_IN, UART6_RX
    DEF_TIM(TIM8,  CH3, PC8,  TIM_USE_PWM,                 0, 0), // S5_IN
    DEF_TIM(TIM8,  CH4, PC9,  TIM_USE_PWM,                 0, 0), // S6_IN

    DEF_TIM(TIM3,  CH3, PB0,  TIM_USE_MOTOR,               0, 0), // S1_OUT D1_ST7
    DEF_TIM(TIM3,  CH4, PB1,  TIM_USE_MOTOR,               0, 0), // S2_OUT D1_ST2
    DEF_TIM(TIM2,  CH4, PA3,  TIM_USE_MOTOR,               0, 1), // S3_OUT D1_ST6
    DEF_TIM(TIM2,  CH3, PA2,  TIM_USE_MOTOR,               0, 0), // S4_OUT D1_ST1

#if defined(OMNIBUSF4SD) || defined(EXUAVF4PRO)
    DEF_TIM(TIM5,  CH2, PA1,  TIM_USE_MOTOR,               0, 0), // S5_OUT
    DEF_TIM(TIM4,  CH1, PB6,  TIM_USE_LED,                 0, 0), // LED strip for F4 V2 / F4-Pro-0X and later (RCD_CS for F4)
#else
    DEF_TIM(TIM5,  CH2, PA1,  TIM_USE_MOTOR | TIM_USE_LED, 0, 0), // S5_OUT
#endif
    DEF_TIM(TIM1,  CH1, PA8,  TIM_USE_MOTOR,               0, 0), // S6_OUT
    DEF_TIM(TIM1,  CH2, PA9,  TIM_USE_NONE,                0, 0), // UART1_TX
    DEF_TIM(TIM1,  CH3, PA10, TIM_USE_NONE,                0, 0), // UART1_RX
*/


/*

    { TIM10, IO_TAG(PB8),  TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM10, TIM_USE_PPM }, // PPM
    { TIM4,  IO_TAG(PB9),  TIM_Channel_4, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM4,  TIM_USE_ANY }, // S2_IN
#else
    { TIM12, IO_TAG(PB14), TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM12, TIM_USE_PPM }, // PPM / S.BUS input, above MOTOR1
    { TIM12, IO_TAG(PB15), TIM_Channel_2, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM12, TIM_USE_ANY }, // Connected: small CH2 pad, not used as PWM, definition inherited from REVO target - GPIO_PartialRemap_TIM3
#endif
    { TIM8,  IO_TAG(PC6),  TIM_Channel_1, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: UART6 TX, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC7),  TIM_Channel_2, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: UART6 RX, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC8),  TIM_Channel_3, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: small CH5 pad, not used as PWM, definition inherited from REVO target
    { TIM8,  IO_TAG(PC9),  TIM_Channel_4, 0, IOCFG_AF_PP_PD, GPIO_AF_TIM8, TIM_USE_ANY }, // Connected: small CH6 pad, not used as PWM, definition inherited from REVO target
    { TIM3,  IO_TAG(PB0),  TIM_Channel_3, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM3, TIM_USE_MC_MOTOR                    | TIM_USE_FW_MOTOR }, // MOTOR_1
    { TIM3,  IO_TAG(PB1),  TIM_Channel_4, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM3, TIM_USE_MC_MOTOR                    | TIM_USE_FW_MOTOR }, // MOTOR_2
    { TIM9,  IO_TAG(PA3),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM9, TIM_USE_MC_MOTOR                    | TIM_USE_FW_SERVO }, // MOTOR_3
    { TIM2,  IO_TAG(PA2),  TIM_Channel_3, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM2, TIM_USE_MC_MOTOR                    | TIM_USE_FW_SERVO }, // MOTOR_4
#if (defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)) && !defined(OMNIBUSF4PRO_LEDSTRIPM5)
    { TIM5,  IO_TAG(PA1),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM5, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_5
    { TIM4,  IO_TAG(PB6),  TIM_Channel_1, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM4, TIM_USE_LED                                            }, // LED strip for F4 V2 / F4-Pro-0X and later
#else
    { TIM5,  IO_TAG(PA1),  TIM_Channel_2, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM5, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_5
#endif
    { TIM1,  IO_TAG(PA8),  TIM_Channel_1, 1, IOCFG_AF_PP_PD, GPIO_AF_TIM1, TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO }, // MOTOR_6
*/
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);