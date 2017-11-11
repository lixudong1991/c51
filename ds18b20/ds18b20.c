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
		dsio = 0;//�Ƚ���������1us
		i++;
		i++;
		i++;
		dsio = 1;//Ȼ���ͷ�����
		i++;
		i++;
		i++;
		i++;//��ʱ6us�ȴ������ȶ�
		bi = dsio;	 //��ȡ���ݣ������λ��ʼ��ȡ
		/*��byte����һλ��Ȼ����������7λ���bi��ע���ƶ�֮���Ƶ���λ��0��*/
		byte = (byte >> 1) | (bi << 7);						  
		i = 4;		//��ȡ��֮��ȴ�48us�ٽ��Ŷ�ȡ��һ����
		while(i--);
	}				
	return byte;
}

void write18b20(uint8 dat)
{
	uint16 i, j;
	for(j=0; j<8; j++)
	{
		dsio= 0;	     	  //ÿд��һλ����֮ǰ�Ȱ���������1us
		i++;
		i++;
		i++;
		dsio = dat & 0x01;  //Ȼ��д��һ�����ݣ������λ��ʼ
		i=24;
		while(i--); //��ʱ68us������ʱ������60us
		dsio = 1;	//Ȼ���ͷ����ߣ�����1us�����߻ָ�ʱ����ܽ���д��ڶ�����ֵ
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



