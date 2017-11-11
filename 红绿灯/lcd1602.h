#ifndef LCD1602_H
#define	LCD1602_H

#include<stc12c.h>

#include"main.h"



#define LCD1602_DATA P0

sbit LCD1602_E=P2^7;
sbit LCD1602_RS=P2^6;
sbit LCD1602_RW=P2^5;

void lcd_delay(uint16 c);
void lcd_write(uint8 mode,uint8 dat);
void lcd_init();
void lcd_print(const uint8* mess);

//清屏DDRAM全部填入0x20空字符 光标撤回显示屏左上方	地址计数器(AC)值设为0 需要RS R/W都为0
#define LCDCLR 0x01

/*设置光标移动方向以及写入数据后屏幕是否右移一个字符 指令的第三位必须为1,4-8位为0 
当第二位为 0时光标左移，1时右移 当第一位为0时写入数据后屏幕不移动，为1时屏幕右移1个字符	   需要RS R/W都为0
*/

#define LCDSET 0x06
 

/* 0 0 0 0 1 D C B		  需要RS R/W都为0
  D 0=关闭显示功能  1=开启显示功能
  C 0=无光标 1=有光标
  B 0=光标闪烁 1=光标不闪烁
*/
#define LCDOC 0x0c

/* 0 0 1 DL N F 0 0			  需要RS R/W都为0
  DL 0=数据总线4位  1=数据总线8位
  N 0=显示1行  1=显示2行
  F 0=5*7点阵/每字符 1=5*10点阵/每字符
*/
#define LCDMOD 0x38

/*
  起始字符显示位置	下面的位置+0x80就是位置
  0x00 0x01 0x02 ... 0x0f
  0x40 ...           0x4f
*/
#define	INITPOS 0x80


#define COM 0
#define DAT 1

#endif
