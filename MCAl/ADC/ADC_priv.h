/*
 * ADC_priv.h
 *
 *  Created on: Sep 7, 2024
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define ADC_ADMUX_REG           *((volatile u8*)(0x27))  //VOLTAGE REFRENCE SELSECTION

#define ADC_ADMUX_REFS0         7
#define ADC_ADMUX_REFS1         6
#define ADC_ADMUX_REFS2         5

#define ADC_ADCSRA_REG          *((volatile u8*)(0x26))   //ADC REGISTER ADDRESS

#define ADC_ADCSRA_ADEN         7   //ADC ENABLE
#define ADC_ADCSRA_ADSC         6   //ADC START CONVERSION
#define ADC_ADCSRA_ADATE        5   //AUTO TRIGGER ENABLE
#define ADC_ADCSRA_ADIF         4   //INTERUPT FLAG
#define ADC_ADCSRA_ADIE         3   //INTERUPT ENABLE
#define ADC_ADCSRA_ADPS2        2   //PRESCALER SELECT BIT
#define ADC_ADCSRA_ADPS1        1   //PRESCALER SELECT BIT
#define ADC_ADCSRA_ADPS0        0   //PRESCALER SELECT BIT

#define ADC_ADCH_REG            *((volatile u8*)(0x25))  //ADC HIGH REGISTER
#define ADC_ADCL_REG            *((volatile u8*)(0x24))  //ADC lOW REGISTER

#define ADC_ADC_REG             *((volatile u16*)(0x24)) //10 BIT REGISTER FOR ADC

#define ADC_PRESCALER_MASK      0b11100000

#endif /* MCAL_ADC_ADC_PRIV_H_ */
