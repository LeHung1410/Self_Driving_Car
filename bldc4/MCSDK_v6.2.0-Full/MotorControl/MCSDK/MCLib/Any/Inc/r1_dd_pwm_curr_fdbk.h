/**
  ******************************************************************************
  * @file    r1_dd_pwm_curr_fdbk.h
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file contains common definitions for Single Shunt, Dual Drives
  *          PWM and Current Feedback components.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  * @ingroup PWMnCurrFdbk_R1_DD
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __R1_DD_PWM_CURR_FDBK_H
#define __R1_DD_PWM_CURR_FDBK_H

#define GPIO_NoRemap_TIM1 ((uint32_t)(0))

#define SAME_FREQ   0u

/** @addtogroup MCSDK
  * @{
  */

/** @addtogroup pwm_curr_fdbk
  * @{
  */


/** @defgroup PWMnCurrFdbk_R1_DD Single Shunt Dual Drive Parameters
  *
  * @brief Common definitions for Single Shunt, Dual Drives PWM and Current Feedback components
  *
  * @{
  */

/**
  * @brief  R1 DD parameters definition
  */
typedef struct
{
  TIM_TypeDef *TIMx;              /*!< Timer used for PWM generation. It should be
                                       TIM1 or TIM8*/
  TIM_TypeDef *TIMx_2;            /*!< Auxiliary timer used for single shunt */
  ADC_TypeDef *ADCx_Inj;          /*!< ADC Peripheral used for phase current sampling */
  ADC_TypeDef *ADCx_Reg;          /*!< ADC Peripheral used for regular conversion */
  GPIO_TypeDef *pwm_en_u_port;
  GPIO_TypeDef *pwm_en_v_port;
  GPIO_TypeDef *pwm_en_w_port;
  uint32_t      pwm_en_u_pin;
  uint32_t      pwm_en_v_pin;
  uint32_t      pwm_en_w_pin;
  uint16_t Tafter;               /*!< It is the sum of dead time plus rise time
                                       express in number of TIM clocks.*/
  uint16_t Tbefore;              /*!< It is the value of sampling time
                                       expressed in numbers of TIM clocks.*/
  uint16_t TMin;                 /*!< It is the sum of dead time plus rise time
                                       plus sampling time express in numbers of
                                       TIM clocks.*/
  uint16_t HTMin;                /*!< It is the half of TMin value.*/
  uint16_t TSample;              /*!< It is the sampling time express in
                                       numbers of TIM clocks.*/
  uint16_t MaxTrTs;              /*!< It is the maximum between twice of rise
                                       time express in number of TIM clocks and
                                       twice of sampling time express in numbers
                                       of TIM clocks.*/
  uint16_t DeadTime;             /*!< Dead time in number of TIM clock
                                       cycles. If CHxN are enabled, it must
                                       contain the dead time to be generated
                                       by the microcontroller, otherwise it
                                       expresses the maximum dead time
                                       generated by driving network*/
  uint8_t  FreqRatio;            /*!< It is used in case of dual MC to
                                         synchronize times. It must be equal
                                         to the ratio between the two PWM
                                         frequencies (higher/lower).
                                         Supported values are 1, 2 or 3 */
  uint8_t  IsHigherFreqTim;      /*!< When bFreqRatio is greather than 1
                                         this param is used to indicate if this
                                         instance is the one with the highest
                                         frequency. Allowed value are: HIGHER_FREQ
                                         or LOWER_FREQ */
  uint8_t InstanceNbr;           /*!< Instance number with reference to PWMC
                                       base class. It is necessary to properly
                                       synchronize TIM8 with TIM1 at peripheral
                                       initializations */
  uint8_t IChannel;              /*!< ADC channel used for conversion of
                                       current. It must be equal to
                                       ADC_CHANNEL_x x= 0, ..., 15*/
  uint8_t  RepetitionCounter;    /*!< It expresses the number of PWM
                                       periods to be elapsed before compare
                                       registers are updated again. In
                                       particular:
                                       RepetitionCounter= (2* PWM periods) -1*/
  bool IsFirstR1DDInstance;      /*!< Specifies whether this object is the first
                                        R1DD instance or not.*/
  LowSideOutputsFunction_t LowSideOutputs; /*!< Low side or enabling signals
                                                generation method are defined
                                                here.*/

} R1_DDParams_t;
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /*__R1_DD_PWM_CURR_FDBK_H*/

/******************* (C) COPYRIGHT 2023 STMicroelectronics *****END OF FILE****/
