#include "ds18b20.h"
sbit dsio=DS18IO;


uint8 ds18b20init()
{
	uint16 i=0; 
	unsigned char a,b;	
	dsio=0;
	delay500us();
	dsio=1;    
    for(b=18;b>0;b--)
        for(a=100;a>0;a--)
	{
		if(!dsio)
		{
			return 1;
		}
	}
	return 0;	
}
uint8 read18b20()
{	
	uint8 byte, bi;
	uint16 i, j;	
	for(j=8; j>0; j--)
	{
		dsio = 0;//先将总线拉低1us
		i++;
		i++;
		i++;
		dsio = 1;//然后释放总线
		i++;
		i++;
		i++;
		i++;//延时6us等待数据稳定
		bi = dsio;	 //读取数据，从最低位开始读取
		/*将byte左移一位，然后与上右移7位后的bi，注意移动之后移掉那位补0。*/
		byte = (byte >> 1) | (bi << 7);						  
		i = 4;		//读取完之后等待48us再接着读取下一个数
		while(i--);
	}				
	return byte;
}

void write18b20(uint8 dat)
{
	uint16 i, j;
	for(j=0; j<8; j++)
	{
		dsio= 0;	     	  //每写入一位数据之前先把总线拉低1us
		i++;
		i++;
		i++;
		dsio = dat & 0x01;  //然后写入一个数据，从最低位开始
		i=24;
		while(i--); //延时68us，持续时间最少60us
		dsio = 1;	//然后释放总线，至少1us给总线恢复时间才能接着写入第二个数值
		dat >>= 1;
	}
}

uint16 convertTemp(uint16 temperature)
{
	uint16 tem=0x07f0;
	double x=0.0625;
	tem&=temperature;
	tem>>=4;
	x*=tem;
	return x*100;
}
uint16 readTemperature()
{
	uint16 templ=0,ret=0;
	ds18b20init();
	delay500us();
	write18b20(0xcc);
	write18b20(0x44);
	delay500us();
	write18b20(0xbe);	
	ret=read18b20();
	//templ=read18b20();
	//ret<<=8;
	//ret|=templ;
	//ret=convertTemp(ret);
	return ret;	
}



