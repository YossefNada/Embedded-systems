/*
 * Converter.h
 *
 * Created: 11/27/2022 8:41:50 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef CONVERTER_H_
#define CONVERTER_H_

void Converter_From(void);
void Converter_To(void);
void Converter_Init(void);
u8 Converter_After_First_Entry(void);
void Converter_DEC_To_DEC_Layout(void);
void Converter_BIN_To_BIN_Layout(void);
void Converter_HEX_To_HEX_Layout(void);
void Converter_DEC_To_BIN_Layout(void);
void Converter_DEC_To_HEX_Layout(void);
void Converter_BIN_To_DEC_Layout(void);
void Converter_HEX_To_DEC_Layout(void);
void Converter_BIN_To_HEX_Layout(void);
void Converter_HEX_To_BIN_Layout(void);



s32 Converter_GetDecimal(u8*check,u8*checkn);
s16 Converter_GetBinary(u8*check,u8*checkn);
u8 Converter_GetHex(u8*check);
u32 power(u8 base,u8 p);










#endif /* CONVERTER_H_ */