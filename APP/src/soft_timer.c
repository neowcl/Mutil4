#include "soft_timer.h"

SOFT_TMR s_tTmr[TMR_COUNT];

#define ENABLE_SYSTICK() (SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk)
#define DISABLE_SYSTICK() (SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk)


void InitSoftTimer(void)
{
	uint8_t i;

	for (i = 0; i < TMR_COUNT; i++)
	{
		s_tTmr[i].Count = 0;
		s_tTmr[i].PreLoad = 0;

		s_tTmr[i].Mode = 0;
		s_tTmr[i].CallBack=0;
	}

}

void SoftTimerDec(void)
{
	for (uint8_t i = 0; i < TMR_COUNT; i++)
	{
		
		if (s_tTmr[i].Count > 0)
		{
			s_tTmr[i].Count -= Periodtime;
			if (s_tTmr[i].Count <= 0)
			{
				if(s_tTmr[i].CallBack!=0)
				{
					s_tTmr[i].CallBack();//执行回调函数   
				}
                //连续模式，重新装载计数值
				if(s_tTmr[i].Mode == 1)
				{
					s_tTmr[i].Count = s_tTmr[i].PreLoad;
				}

			}
		}
		
	}//end of for
}


void StartSoftTimer(uint8_t _id, uint8_t mode, uint32_t _period,void *CallBack)
{
	if (_id >= TMR_COUNT)
	{
       
		while(1);
	}
    DISABLE_SYSTICK();                        
    
	s_tTmr[_id].Count = _period;
	s_tTmr[_id].PreLoad = _period;
	s_tTmr[_id].Mode = mode;
	s_tTmr[_id].CallBack=(void (*)(void))CallBack;
    ENABLE_SYSTICK();   
    
    if(_period == 0)
    {
        StopSoftTimer(_id);
    }
}

void IncSoftTimer(uint8_t _id,uint32_t _period)
{
	if (_id >= TMR_COUNT)
	{
       
		while(1);
	}
    DISABLE_SYSTICK();                        
    
	s_tTmr[_id].Count += _period;
	s_tTmr[_id].PreLoad += _period;

    ENABLE_SYSTICK();   
}


void StopSoftTimer(uint8_t _id)
{
	if (_id >= TMR_COUNT)
	{
       
		while(1);
	}
    DISABLE_SYSTICK();                        //关总中断
	s_tTmr[_id].Count = 0;
	s_tTmr[_id].Mode = 0;
	s_tTmr[_id].CallBack=0;
    ENABLE_SYSTICK();                    //开总中断

}


/**
  * @brief  获取软件定时器的工作状态
  * @param  _id: 定时器编号
  * @retval bool: 1--工作，0--不工作
  */
uint8_t getSoftTimerStatus(uint8_t _id)
{
    return (s_tTmr[_id].Count == 0)  ? 0 : 1;
}