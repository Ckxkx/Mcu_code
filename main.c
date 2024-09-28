#include <STC15F2K60S2.H>

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void LED_Water()
{
	int i;
	P2 = P2 & 0x1f | 0x80 ;
	
	for (i = 0;i < 8 ;i ++)
	{
		//0000 0001   ==  1111 1110
		P0 = ~(0x01 << i);
		Delay500ms();
	}
}

void main()
{
	//Á÷Ë®µÆ
	while (1) 
	{
		LED_Water();
	}
	
	
	
}