/*
 * ADC_int.h
 *
 *  Created on: Sep 7, 2024
 *      Author: DELL
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define ADC_U8_CHANNEL_0             0
#define ADC_U8_CHANNEL_1             1
#define ADC_U8_CHANNEL_2             2
#define ADC_U8_CHANNEL_3             3
#define ADC_U8_CHANNEL_4             4
#define ADC_U8_CHANNEL_5             5
#define ADC_U8_CHANNEL_6             6
#define ADC_U8_CHANNEL_7             7

void ADC_voidInit();
u16 ADC_u16StartConversionSynch(u8 Copy_u8ChannelID);
void ADC_voidStartConversionAsynch(u8 Copy_u8ChannelID,u16* Copy_u8Res,void (*pf)(void));


#endif /* MCAL_ADC_ADC_INT_H_ */
