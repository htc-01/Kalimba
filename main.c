#include<stm32f10x.h>
#include<stdio.h>
#include<stm32f10x_gpio.h>
#define key1 GPIO_Pin_15
#define key2 GPIO_Pin_12
#define key3 GPIO_Pin_1
#define key4 GPIO_Pin_8
#define key5 GPIO_Pin_7
#define key6 GPIO_Pin_6
#define key7 GPIO_Pin_5
#define key8 GPIO_Pin_4
#define key9 GPIO_Pin_3
#define key10 GPIO_Pin_2
#define beep0 GPIO_Pin_10
#define beep1 GPIO_Pin_11
void rgb_init()
{
GPIO_InitTypeDef 	led_init;
RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	
led_init.GPIO_Pin = key1 | key2 | key3 | key4 | key5 | key6 | key7 | key8 | key9 | key10;
led_init.GPIO_Mode = GPIO_Mode_IPU;
led_init.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA, &led_init);
	
	
led_init.GPIO_Pin= GPIO_Pin_11 | GPIO_Pin_10;
GPIO_SetBits(GPIOB,beep0 | beep1);
led_init.GPIO_Speed=GPIO_Speed_50MHz;
led_init.GPIO_Mode=GPIO_Mode_Out_PP;
GPIO_Init(GPIOB ,&led_init);
}
void delay_init(void)
{
    // 设置外部源时钟 72MHz/8=9MHz
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); // 9MHz
}

// 微秒级延时
void delay_us(int nus) // 最多能计 16,777,216 个数，延时最多延时 1,864,135 us
{
    u32 temp;
    // 重装载寄存器赋值
    SysTick->LOAD = nus*9-1; // LOAD（载入数值）= t（计时时间，单位：秒） x T（频率，单位：Hz）
    // 计数器赋值为 0，防止误差,只有 VAL 为 0 时，重装载寄存器才会赋值给它
    SysTick->VAL=0X00;
    // 使能定时器
    SysTick->CTRL|=(0X01<<0);
    do
    {
        temp=SysTick->CTRL;
    } // 判断定时器是否开启，以及定时器是否计算完毕
    while((temp&(0x01<<0))&&(!(temp&(0x01<<16))));
    // 关闭定时器
    SysTick->CTRL&=~(0X01<<0);
}

void time(unsigned int a)
{
	unsigned int i, j,h;
	for(i=0; i<a; i++)
	{
		for(j=0; j<0x1FFFF; j++);
		//time(40)=1s
	}
}
void time1(unsigned int a)
{
	unsigned int i, j,h;
	for(i=0; i<a; i++)
	{
		for(j=0; j<0x1FF; j++);
		//time(40)=1s
	}
}
/*
int main()
	{
led_init();	
rgb_init();
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
while(1)
	{
		
		
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		time(5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		time(5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_3);
		time(5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
		time(5);
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		time(5);
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		time(5);
		GPIO_SetBits(GPIOA,GPIO_Pin_3);
		time(5);
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		rgb();
		time(5);
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		time(5);
  }
}
*/
int main()
{
	delay_init();
  rgb_init();
		GPIO_SetBits(GPIOB,beep0 | beep1);
	while(1)
	{
		if(!GPIO_ReadInputDataBit(GPIOA,key1))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(3831);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(3831);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key2))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(3412);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(3412);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key3))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(3021);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(3021);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key4))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(2841);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(2841);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key5))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(2545);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(2545);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key6))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(2278);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(2278);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key7))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(2008);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(2008);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key8))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(1898);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(1898);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key9))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(1706);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(1706);
		}
	 if(!GPIO_ReadInputDataBit(GPIOA,key10))
		{
		GPIO_ResetBits(GPIOB,beep0);
		GPIO_SetBits(GPIOB,beep1);
		delay_us(1511);
		GPIO_ResetBits(GPIOB,beep1);
		GPIO_SetBits(GPIOB,beep0);
		delay_us(1511);
		}
		GPIO_SetBits(GPIOB,beep0 | beep1);
	}
}
