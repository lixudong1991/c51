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

//����DDRAMȫ������0x20���ַ� ��곷����ʾ�����Ϸ�	��ַ������(AC)ֵ��Ϊ0 ��ҪRS R/W��Ϊ0
#define LCDCLR 0x01

/*���ù���ƶ������Լ�д�����ݺ���Ļ�Ƿ�����һ���ַ� ָ��ĵ���λ����Ϊ1,4-8λΪ0 
���ڶ�λΪ 0ʱ������ƣ�1ʱ���� ����һλΪ0ʱд�����ݺ���Ļ���ƶ���Ϊ1ʱ��Ļ����1���ַ�	   ��ҪRS R/W��Ϊ0
*/

#define LCDSET 0x06
 

/* 0 0 0 0 1 D C B		  ��ҪRS R/W��Ϊ0
  D 0=�ر���ʾ����  1=������ʾ����
  C 0=�޹�� 1=�й��
  B 0=�����˸ 1=��겻��˸
*/
#define LCDOC 0x0c

/* 0 0 1 DL N F 0 0			  ��ҪRS R/W��Ϊ0
  DL 0=��������4λ  1=��������8λ
  N 0=��ʾ1��  1=��ʾ2��
  F 0=5*7����/ÿ�ַ� 1=5*10����/ÿ�ַ�
*/
#define LCDMOD 0x38

/*
  ��ʼ�ַ���ʾλ��	�����λ��+0x80����λ��
  0x00 0x01 0x02 ... 0x0f
  0x40 ...           0x4f
*/
#define	INITPOS 0x80


#define COM 0
#define DAT 1

#endif
