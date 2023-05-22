/*
 * Utils.h
 *
 * Created: 10/30/2022 9:44:27 PM
 *  Author: SOUQ COMPUTER
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET(REG,BIT) (REG=REG | (1<<BIT))
#define CLR(REG,BIT) (REG=REG & ~(1<<BIT))
#define FLIP_BIT(REG,BIT) (REG=REG ^ (1<<BIT))
#define WRITE_BIT2(REG,BIT,VALUE) VALUE==0?CLR(REG,BIT):SET(REG,BIT)
#define WRITE_BTI(REG,BIT,VALUE) (REG=(REG & ~(1<<BIT)) | (VALUE<<BIT))  // i will clear the bit first and then or with the value shifted
#define READ_BIT(REG,BIT) (REG>>BIT & 1)
#define TOGGLE_BIT(REG,BIT) (REG=REG^ (1<<BIT))
#define TOGGLE_REG(REG) (REG=REG^0XFF)




#endif /* UTILS_H_ */