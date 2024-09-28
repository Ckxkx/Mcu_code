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

void LED_Marquee()
{
	static unsigned char step = 0; 
	static unsigned char direction = 0; 

	P2 = (P2 & 0x1f) | 0x80; 

	if (direction == 0) { 
		P0 = 0xFF; 
		for (unsigned char i = 0; i < step; ++i) {
			P0 &= ~(1 << i); 
		}
		if (step < 8) {
			step++; 
		} else {
			direction = 1; 
		}
	} else { 
		P0 = 0x00; 
		for (unsigned char i = 0; i < 8 - step; ++i) {
			P0 |= (1 << i); 
		}
		if (step > 0) {
			step--; 
		} else {
			direction = 0; 
		}
	}

	Delay500ms();
}

void main()
{
	
	P0M0 = 0x00; 
	P0M1 = 0x00;


	while (1) 
	{
		LED_Marquee();
	}
}