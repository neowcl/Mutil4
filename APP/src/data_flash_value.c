#include "data_flash_value.h"

volatile Record t_record = { 0 };
volatile LifeTimes l_lifetimes = { 0 };
const volatile FlashData flashdata __attribute__((used)) __attribute__((section(".ARM.__at_0x0801E000"))) =
	{
		16478, /* Cell1 vol  Gain                    	Calibdata                          	Calib                              	*/
		16562, /* Cell2 vol  Gain                    	*                                  	*                                  	*/
		16458, /* Cell3 vol  Gain                    	*                                  	*                                  	*/
		16355, /* Cell4 vol  Gain                    	*                                  	*                                  	*/
		17092, /* Pack Gain                          	*                                  	*                                  	*/
		16284, /* Bat Gain                           	*                                  	*                                  	*/
		5492,  /* Current Gain                       	*                                  	*                                  	*/
		0,	   /* CC Offset                          	*                                  	*                                  	*/
		5,	   /* Dead Band                          	*                                  	*                                  	*/
		-37,   /* InterTOffset                       	*                                  	*                                  	*/
		19,	   /* TS1Offset                          	*                                  	*                                  	*/
		18,	   /* TS2Offset                          	*                                  	*                                  	*/
		0,	   /* TS3Offset                          	*                                  	*                                  	*/
		0,	   /* TS4Offset                          	*                                  	*                                  	*/
		3200,  /* SOC-OCV Table 0%                   	OCV table                          	OCV-SOC table                      	*/
		3658,  /* SOC-OCV Table 5%                   	*                                  	*                                  	*/
		3679,  /* SOC-OCV Table 10%                  	*                                  	*                                  	*/
		3715,  /* SOC-OCV Table 15%                  	*                                  	*                                  	*/
		3738,  /* SOC-OCV Table 20%                  	*                                  	*                                  	*/
		3761,  /* SOC-OCV Table 25%                  	*                                  	*                                  	*/
		3780,  /* SOC-OCV Table 30%                  	*                                  	*                                  	*/
		3798,  /* SOC-OCV Table 35%                  	*                                  	*                                  	*/
		3818,  /* SOC-OCV Table 40%                  	*                                  	*                                  	*/
		3845,  /* SOC-OCV Table 45%                  	*                                  	*                                  	*/
		3875,  /* SOC-OCV Table 50%                  	*                                  	*                                  	*/
		3919,  /* SOC-OCV Table 55%                  	*                                  	*                                  	*/
		3978,  /* SOC-OCV Table 60%                  	*                                  	*                                  	*/
		4028,  /* SOC-OCV Table 65%                  	*                                  	*                                  	*/
		4082,  /* SOC-OCV Table 70%                  	*                                  	*                                  	*/
		4139,  /* SOC-OCV Table 75%                  	*                                  	*                                  	*/
		4197,  /* SOC-OCV Table 80%                  	*                                  	*                                  	*/
		4269,  /* SOC-OCV Table 85%                  	*                                  	*                                  	*/
		4318,  /* SOC-OCV Table 90%                  	*                                  	*                                  	*/
		4370,  /* SOC-OCV Table 95%                  	*                                  	*                                  	*/
		4454,  /* SOC-OCV Table 100%                 	*                                  	*                                  	*/
		600,
		565,
		530,
		520,
		510,
		505,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		500,
		5000,
		4000,
		3000,
		2500,
		2000,
		1750,
		1500,
		1450,
		1400,
		1375,
		1350,
		1325,
		1300,
		1285,
		1270,
		1255,
		1240,
		1230,
		1220,
		1210,
		1200,
		20,		/* CP_Delay                           	CP Para                            	CP Correction                      	*/
		60,		/* CP_H                               	*                                  	*                                  	*/
		6,		/* CP_L                               	*                                  	*                                  	*/
		7,		/* CPH_Coefficcient                   	*                                  	*                                  	*/
		6,		/* CPL_Coefficcient                   	*                                  	*                                  	*/
		6,		/* FCC_Coefficcient                   	*                                  	*                                  	*/
		20,		/* CP table C-rate 1                  	CP Para table                      	*                                  	*/
		50,		/* CP table C-rate 2                  	*                                  	*                                  	*/
		100,	/* CP table C-rate 3                  	*                                  	*                                  	*/
		150,	/* CP table C-rate 4                  	*                                  	*                                  	*/
		-10,	/* CP table T-rate 1                  	*                                  	*                                  	*/
		5,		/* CP table T-rate 2                  	*                                  	*                                  	*/
		15,		/* CP table T-rate 3                  	*                                  	*                                  	*/
		25,		/* CP table T-rate 4                  	*                                  	*                                  	*/
		45,		/* CP table T-rate 5                  	*                                  	*                                  	*/
		3680,	/* CPH voltage table (C1/T1)          	CPH Table                          	*                                  	*/
		3847,	/* CPH voltage table (C1/T2)          	*                                  	*                                  	*/
		3912,	/* CPH voltage table (C1/T3)          	*                                  	*                                  	*/
		3938,	/* CPH voltage table (C1/T4)          	*                                  	*                                  	*/
		3962,	/* CPH voltage table (C1/T5)          	*                                  	*                                  	*/
		3600,	/* CPH voltage table (C2/T1)          	*                                  	*                                  	*/
		3692,	/* CPH voltage table (C2/T2)          	*                                  	*                                  	*/
		3800,	/* CPH voltage table (C2/T3)          	*                                  	*                                  	*/
		3857,	/* CPH voltage table (C2/T4)          	*                                  	*                                  	*/
		3901,	/* CPH voltage table (C2/T5)          	*                                  	*                                  	*/
		3520,	/* CPH voltage table (C3/T1)          	*                                  	*                                  	*/
		3549,	/* CPH voltage table (C3/T2)          	*                                  	*                                  	*/
		3631,	/* CPH voltage table (C3/T3)          	*                                  	*                                  	*/
		3734,	/* CPH voltage table (C3/T4)          	*                                  	*                                  	*/
		3811,	/* CPH voltage table (C3/T5)          	*                                  	*                                  	*/
		3500,	/* CPH voltage table (C4/T1)          	*                                  	*                                  	*/
		3530,	/* CPH voltage table (C4/T2)          	*                                  	*                                  	*/
		3556,	/* CPH voltage table (C4/T3)          	*                                  	*                                  	*/
		3623,	/* CPH voltage table (C4/T4)          	*                                  	*                                  	*/
		3725,	/* CPH voltage table (C4/T5)          	*                                  	*                                  	*/
		3274,	/* CPL voltage table (C1/T1)          	CPL Table                          	*                                  	*/
		3433,	/* CPL voltage table (C1/T2)          	*                                  	*                                  	*/
		3540,	/* CPL voltage table (C1/T3)          	*                                  	*                                  	*/
		3598,	/* CPL voltage table (C1/T4)          	*                                  	*                                  	*/
		3641,	/* CPL voltage table (C1/T5)          	*                                  	*                                  	*/
		3244,	/* CPL voltage table (C2/T1)          	*                                  	*                                  	*/
		3323,	/* CPL voltage table (C2/T2)          	*                                  	*                                  	*/
		3398,	/* CPL voltage table (C2/T3)          	*                                  	*                                  	*/
		3489,	/* CPL voltage table (C2/T4)          	*                                  	*                                  	*/
		3573,	/* CPL voltage table (C2/T5)          	*                                  	*                                  	*/
		3272,	/* CPL voltage table (C3/T1)          	*                                  	*                                  	*/
		3298,	/* CPL voltage table (C3/T2)          	*                                  	*                                  	*/
		3287,	/* CPL voltage table (C3/T3)          	*                                  	*                                  	*/
		3366,	/* CPL voltage table (C3/T4)          	*                                  	*                                  	*/
		3466,	/* CPL voltage table (C3/T5)          	*                                  	*                                  	*/
		3342,	/* CPL voltage table (C4/T1)          	*                                  	*                                  	*/
		3323,	/* CPL voltage table (C4/T2)          	*                                  	*                                  	*/
		3258,	/* CPL voltage table (C4/T3)          	*                                  	*                                  	*/
		3315,	/* CPL voltage table (C4/T4)          	*                                  	*                                  	*/
		3387,	/* CPL voltage table (C4/T5)          	*                                  	*                                  	*/
		837,	/* QCap Capcity table (C1/T1)         	QCap_Table                         	*                                  	*/
		924,	/* QCap Capcity table (C1/T2)         	*                                  	*                                  	*/
		976,	/* QCap Capcity table (C1/T3)         	*                                  	*                                  	*/
		1027,	/* QCap Capcity table (C1/T4)         	*                                  	*                                  	*/
		1038,	/* QCap Capcity table (C1/T5)         	*                                  	*                                  	*/
		754,	/* QCap Capcity table (C2/T1)         	*                                  	*                                  	*/
		881,	/* QCap Capcity table (C2/T2)         	*                                  	*                                  	*/
		948,	/* QCap Capcity table (C2/T3)         	*                                  	*                                  	*/
		1000,	/* QCap Capcity table (C2/T4)         	*                                  	*                                  	*/
		1036,	/* QCap Capcity table (C2/T5)         	*                                  	*                                  	*/
		687,	/* QCap Capcity table (C3/T1)         	*                                  	*                                  	*/
		836,	/* QCap Capcity table (C3/T2)         	*                                  	*                                  	*/
		926,	/* QCap Capcity table (C3/T3)         	*                                  	*                                  	*/
		987,	/* QCap Capcity table (C3/T4)         	*                                  	*                                  	*/
		1029,	/* QCap Capcity table (C3/T5)         	*                                  	*                                  	*/
		657,	/* QCap Capcity table (C4/T1)         	*                                  	*                                  	*/
		796,	/* QCap Capcity table (C4/T2)         	*                                  	*                                  	*/
		908,	/* QCap Capcity table (C4/T3)         	*                                  	*                                  	*/
		980,	/* QCap Capcity table (C4/T4)         	*                                  	*                                  	*/
		1014,	/* QCap Capcity table (C4/T5)         	*                                  	*                                  	*/
		50,		/* Internal impedance cycle1          	CEDV_Cycle Compensate              	Gas Gauging                        	*/
		100,	/* Internal impedance cycle2          	*                                  	*                                  	*/
		200,	/* Internal impedance cycle3          	*                                  	*                                  	*/
		500,	/* Internal impedance cycle4          	*                                  	*                                  	*/
		800,	/* Internal impedance cycle5          	*                                  	*                                  	*/
		1000,	/* Internal impedance cycle6          	*                                  	*                                  	*/
		0,		/* Internal impedance table1          	*                                  	*                                  	*/
		0,		/* Internal impedance table2          	*                                  	*                                  	*/
		0,		/* Internal impedance table3          	*                                  	*                                  	*/
		0,		/* Internal impedance table4          	*                                  	*                                  	*/
		0,		/* Internal impedance table5          	*                                  	*                                  	*/
		0,		/* Internal impedance table6          	*                                  	*                                  	*/
		1,		/* Internal FCC table1                	*                                  	*                                  	*/
		5,		/* Internal FCC table2                	*                                  	*                                  	*/
		10,		/* Internal FCC table3                	*                                  	*                                  	*/
		15,		/* Internal FCC table4                	*                                  	*                                  	*/
		20,		/* Internal FCC table5                	*                                  	*                                  	*/
		25,		/* Internal FCC table6                	*                                  	*                                  	*/
		72,		/* Relearn stop time                  	FCC                                	*                                  	*/
		5,		/* Min current of cap calc            	*                                  	*                                  	*/
		5,		/* Consum current of discharge        	*                                  	*                                  	*/
		10,		/* Deterioration capacity             	*                                  	*                                  	*/
		256,	/* FCC variance                       	*                                  	*                                  	*/
		-10,	/* relearn temp limit                 	*                                  	*                                  	*/
		40,		/* Qmax update min delta SOC          	Qmax                               	*                                  	*/
		5,		/* Temp Low limit                     	*                                  	*                                  	*/
		45,		/* Temp High limit                    	*                                  	*                                  	*/
		1,		/* C rate low limit                   	*                                  	*                                  	*/
		3,		/* C rate high limit                  	*                                  	*                                  	*/
		30,		/* SOC low limit                      	*                                  	*                                  	*/
		80,		/* SOC high limit                     	*                                  	*                                  	*/
		10,		/* Cycle limit                        	*                                  	*                                  	*/
		3200,	/* 0% voltage                         	Discharge termination              	*                                  	*/
		10,		/* 0% voltage Delay                   	*                                  	*                                  	*/
		30,		/* Cell balancing ON voltage          	Cell Balances                      	*                                  	*/
		10,		/* Cell balancing OFF voltage         	*                                  	*                                  	*/
		4400,	/* Enable voltage upper limit         	*                                  	*                                  	*/
		3800,	/* Enable voltage lower limit         	*                                  	*                                  	*/
		-100,	/* Dsg Current Threshold              	Current Thresholds                 	*                                  	*/
		50,		/* Chg Current Threshold              	*                                  	*                                  	*/
		10,		/* Quit Current                       	*                                  	*                                  	*/
		1,		/* Dsg Relax Time                     	*                                  	*                                  	*/
		20,		/* Chg Relax Time                     	*                                  	*                                  	*/
		6169,	/* Design Capacity mAh                	Design                             	*                                  	*/
		9600,	/* Design Capacity in cWh             	*                                  	*                                  	*/
		15560,	/* Design Voltage                     	*                                  	*                                  	*/
		6300,
		-90,	/* Cycle Count Percentage             	Cycle                              	*                                  	*/
		3200,	/* Set Voltage Threshold              	FD                                 	*                                  	*/
		3400,	/* Clear Voltage Threshold            	*                                  	*                                  	*/
		0,		/* Set RSOC % Threshold               	*                                  	*                                  	*/
		5,		/* Clear RSOC % Threshold             	*                                  	*                                  	*/
		4480,	/* Set Voltage Threshold              	FC                                 	*                                  	*/
		4300,	/* Clear Voltage Threshold            	*                                  	*                                  	*/
		100,	/* Set RSOC % Threshold               	*                                  	*                                  	*/
		95,		/* Clear RSOC % Threshold             	*                                  	*                                  	*/
		3200,	/* Set Voltage Threshold              	TD                                 	*                                  	*/
		3400,	/* Clear Voltage Threshold            	*                                  	*                                  	*/
		10,		/* Set RSOC % Threshold               	*                                  	*                                  	*/
		15,		/* Clear RSOC % Threshold             	*                                  	*                                  	*/
		4480,	/* Set Voltage Threshold              	TC                                 	*                                  	*/
		4330,	/* Clear Voltage Threshold            	*                                  	*                                  	*/
		100,	/* Set RSOC % Threshold               	*                                  	*                                  	*/
		95,		/* Clear RSOC % Threshold             	*                                  	*                                  	*/
		0,		/* Cycle Count                        	State                              	*                                  	*/
		6169,	/* QmaxCell1                          	*                                  	*                                  	*/
		6169,	/* QmaxCell2                          	*                                  	*                                  	*/
		6169,	/* QmaxCell3                          	*                                  	*                                  	*/
		6169,	/* QmaxCell4                          	*                                  	*                                  	*/
		6169,	/* QmaxPack                           	*                                  	*                                  	*/
		0,		/* QmaxCycleCount                     	*                                  	*                                  	*/
		7,		/* Update Status                      	*                                  	*                                  	*/
		0x0000, /* FW Version                         	Version                            	*                                  	*/
		0x0001, /* DF Version                         	*                                  	*                                  	*/
		24000,
		12000,
		12800,
		50,
		600,
		15,
		45,
		15,
		40,
		90,
        40,     /*pi mode*/
        4000 ,
        200, 
        336 ,
        40 ,
        168 ,
		0x03a0, /* Charging Config                    	Configuration                      	Setting                            	*/
		0x3d,	/* FETOptions                         	*                                  	*                                  	*/
		0x17,	/* SBS Gauging Configuration          	*                                  	*                                  	*/
		0x20,	/* SBS Configuration                  	*                                  	*                                  	*/
		0x00,	/* Auth Config                        	*                                  	*                                  	*/
		0x0001, /* Power Config                       	*                                  	*                                  	*/
		0x00,	/* IO Config                          	*                                  	*                                  	*/
		0x0000, /* GPIO Sealed Access Config          	*                                  	*                                  	*/
		0x0000, /* Flag Map Set Up 1                  	*                                  	*                                  	*/
		0x0000, /* Flag Map Set Up 2                  	*                                  	*                                  	*/
		0x0000, /* Flag Map Set Up 3                  	*                                  	*                                  	*/
		0x0000, /* Flag Map Set Up 4                  	*                                  	*                                  	*/
		0x0000, /* LED Configuration                  	*                                  	*                                  	*/
		0x07,	/* Temperature Enable                 	*                                  	*                                  	*/
		0x04,	/* Temperature Mode                   	*                                  	*                                  	*/
		0x001f, /* DA Configuration                   	*                                  	*                                  	*/
		0x0c8c, /* SOC Flag Config A                  	*                                  	*                                  	*/
		0x8c,	/* SOC Flag Config B                  	*                                  	*                                  	*/
		0x67,	/* Balancing Configuration            	*                                  	*                                  	*/
		0xb252, /* IT Gauging Configuration           	*                                  	*                                  	*/
		0x02,	/* IT Gauging Ext                     	*                                  	*                                  	*/
		0x00,	/* Elevate Degrad Configuratio        	*                                  	*                                  	*/
		0x5f,	/* Permanent Fail Fuse A              	Fuse                               	*                                  	*/
		0x18,	/* Permanent Fail Fuse B              	*                                  	*                                  	*/
		0x43,	/* Permanent Fail Fuse C              	*                                  	*                                  	*/
		0x30,	/* Permanent Fail Fuse D              	*                                  	*                                  	*/
		12800,	/* Min Blow Fuse Voltage              	*                                  	*                                  	*/
		30,		/* Fuse Blow Timeout                  	*                                  	*                                  	*/
		0x03,	/* Protection Configuration           	Protection                         	*                                  	*/
		0x7f,	/* Enabled Protections A              	*                                  	*                                  	*/
		0x35,	/* Enabled Protections B              	*                                  	*                                  	*/
		0x11,	/* Enabled Protections C              	*                                  	*                                  	*/
		0x0e,	/* Enabled Protections D              	*                                  	*                                  	*/
		0x5f,	/* Enabled PF A                       	Permanent Failure                  	*                                  	*/
		0x18,	/* Enabled PF B                       	*                                  	*                                  	*/
		0x43,	/* Enabled PF C                       	*                                  	*                                  	*/
		0x30,	/* Enabled PF D                       	*                                  	*                                  	*/
		0x00,	/* AFE Protection Control             	AFE                                	*                                  	*/
		0x0018, /* Manufacturing Status Init          	*                                  	*                                  	*/
		-1000,	/* Accumulate Charg Measuremen        	Accumulate Charg Measuremen        	*                                  	*/
		1000,	/* Accum Charge Threshold             	*                                  	*                                  	*/
		10,		/* TimeRSOCThresholdA                 	Lifetime Setting                   	*                                  	*/
		30,		/* TimeRSOCThresholdB                 	*                                  	*                                  	*/
		50,		/* TimeRSOCThresholdC                 	*                                  	*                                  	*/
		65,		/* TimeRSOCThresholdD                 	*                                  	*                                  	*/
		80,		/* TimeRSOCThresholdE                 	*                                  	*                                  	*/
		90,		/* TimeRSOCThresholdF                 	*                                  	*                                  	*/
		100,	/* TimeRSOCThresholdG                 	*                                  	*                                  	*/
		3000,	/* Precharge Start Voltage            	Voltage Range                      	Charging algorithm                 	*/
		3000,	/* Charging Voltage Low               	*                                  	*                                  	*/
		3890,	/* Charging Voltage Med               	*                                  	*                                  	*/
		4250,	/* Charging Voltage High              	*                                  	*                                  	*/
		50,		/* Charging Voltage Hysteresis        	*                                  	*                                  	*/
		0,		/* T1 Temp                            	Temp ranges                        	*                                  	*/
		15,		/* T2 Temp                            	*                                  	*                                  	*/
		15,		/* T5 Temp                            	*                                  	*                                  	*/
		45,		/* T6 Temp                            	*                                  	*                                  	*/
		45,		/* T3 Temp                            	*                                  	*                                  	*/
		60,		/* T4 Temp                            	*                                  	*                                  	*/
		1,		/* Hysteresis Temp                    	*                                  	*                                  	*/
		4480,	/* LT CV                              	Low temp                           	*                                  	*/
		1234,	/* LT CCL                             	*                                  	*                                  	*/
		1234,	/* LT CCM                             	*                                  	*                                  	*/
		1234,	/* LT CCH                             	*                                  	*                                  	*/
		4480,	/* STL CV                             	Standard Low temp                  	*                                  	*/
		8400,	/* STL CCL                            	*                                  	*                                  	*/
		8400,	/* STL CCM                            	*                                  	*                                  	*/
		6169,	/* STL CCH                            	*                                  	*                                  	*/
		4480,	/* STH CV                             	Standard High temp                 	*                                  	*/
		8400,	/* STH CCL                            	*                                  	*                                  	*/
		8400,	/* STH CCM                            	*                                  	*                                  	*/
		6169,	/* STH CCH                            	*                                  	*                                  	*/
		4200,	/* HT CV                              	High temp                          	*                                  	*/
		3085,	/* HT CCL                             	*                                  	*                                  	*/
		3085,	/* HT CCM                             	*                                  	*                                  	*/
		3085,	/* HT CCH                             	*                                  	*                                  	*/
		4480,	/* RT CV                              	Rec Temp Charging                  	*                                  	*/
		8400,	/* RT CCL                             	*                                  	*                                  	*/
		8400,	/* RT CCM                             	*                                  	*                                  	*/
		6169,	/* RT CCH                             	*                                  	*                                  	*/
		0,		/* Poly T1                            	Poly                               	*                                  	*/
		10,		/* Poly T1A                           	*                                  	*                                  	*/
		15,		/* Poly T2                            	*                                  	*                                  	*/
		55,		/* Poly T2A                           	*                                  	*                                  	*/
		55,		/* Poly T3                            	*                                  	*                                  	*/
		55,		/* Poly T3A                           	*                                  	*                                  	*/
		55,		/* Poly T3B                           	*                                  	*                                  	*/
		55,		/* Poly T3C                           	*                                  	*                                  	*/
		55,		/* Poly T4                            	*                                  	*                                  	*/
		60,		/* Poly T5                            	*                                  	*                                  	*/
		3238,	/* I1                                 	*                                  	*                                  	*/
		10758,	/* I2                                 	*                                  	*                                  	*/
		3238,	/* I3                                 	*                                  	*                                  	*/
		3238,	/* I4                                 	*                                  	*                                  	*/
		3238,	/* I5                                 	*                                  	*                                  	*/
		3238,	/* I6                                 	*                                  	*                                  	*/
		3238,	/* I7                                 	*                                  	*                                  	*/
		3238,	/* I8                                 	*                                  	*                                  	*/
		3238,	/* I9                                 	*                                  	*                                  	*/
		3238,	/* I10                                	*                                  	*                                  	*/
		0,		/* I11                                	*                                  	*                                  	*/
		2000,	/* Poly V1                            	*                                  	*                                  	*/
		3000,	/* Poly V2                            	*                                  	*                                  	*/
		4200,	/* Poly V3                            	*                                  	*                                  	*/
		4250,	/* Poly V4                            	*                                  	*                                  	*/
		4400,	/* Poly V5                            	*                                  	*                                  	*/
		5,		/* Poly hys Jt                        	*                                  	*                                  	*/
		244,	/* Poly Code Tapper Current           	*                                  	*                                  	*/
		100,	/* Poly Step Current Delta            	*                                  	*                                  	*/
		24,		/* Poly Step Current Time             	*                                  	*                                  	*/
		50,		/* Poly Voltage Delta                 	*                                  	*                                  	*/
		53,		/* Poly Reset Temperature             	*                                  	*                                  	*/
		4150,	/* Poly Reset voltage                 	*                                  	*                                  	*/
		4280,	/* Smart Chg CV Step1 Voltage         	Smart charge                       	*                                  	*/
		4480,	/* Smart Chg CV Step2 Voltage         	*                                  	*                                  	*/
		4250,	/* Smart Chg Max Cell Voltage         	*                                  	*                                  	*/
		4250,	/* Smart Chg Volt Reset               	*                                  	*                                  	*/
		2411,	/* Smart Chg Min  CC                  	*                                  	*                                  	*/
		482,	/* Smart Chg Step Current Step        	*                                  	*                                  	*/
		5552,	/* Smar Ch Norma Charg Curren         	*                                  	*                                  	*/
		40,		/* Smart Chg judgement time           	*                                  	*                                  	*/
		50,		/* Charge Term Voltage                	Termination Config                 	*                                  	*/
		308,	/* Charge Term Taper Current          	*                                  	*                                  	*/
		40,		/* Fullcharge judgement time          	*                                  	*                                  	*/
		1,		/* Charge Term Taper Capacity         	*                                  	*                                  	*/
		256,	/* Current                            	PreCharging                        	*                                  	*/
		0,		/* Maintenance ChargingCurrent        	Maintenance Charging               	*                                  	*/
		256,	/* Charge Inhibit Current             	Charge Inhibit                     	*                                  	*/
		0x00,	/* ERETM Status                       	Elevated Degrade                   	*                                  	*/
		29,   
		30,
		31,
		32,
		350,
		320,
		290,
		30,
		30,
		30,
		350,
		3200,																							/* Shutdown Voltage                   	Shutdown                           	Power                              	*/
		13,																								/* Shutdown Time                      	*                                  	*                                  	*/
		1,																								/* IO Shutdown Delay                  	*                                  	*                                  	*/
		8,																								/* IO Shutdown Timeout                	*                                  	*                                  	*/
		3000,																							/* Charger Present Threshold          	*                                  	*                                  	*/
		3,																								/* MAC_FET Off Time                   	*                                  	*                                  	*/
		5,																								/* MAC_Shutdown Delay                 	*                                  	*                                  	*/
		21600,																							/* Auto Ship time                     	*                                  	*                                  	*/
		10,																								/* Sleep Current                      	Sleep                              	*                                  	*/
		30,																								/* Bus TimeOut                        	*                                  	*                                  	*/
		5,																								/* Voltage Time                       	*                                  	*                                  	*/
		20,																								/* Current Time                       	*                                  	*                                  	*/
		0x00,																							/* Wake Comparator                    	*                                  	*                                  	*/
		3,																								/* FET Off Storage Time               	Ship Mode                          	*                                  	*/
		30,																								/* FET Off Min RSOC                   	*                                  	*                                  	*/
		3200,																							/* Threshold                          	CUV—Cell Undervoltage            	Protections                        	*/
		11,																								/* Delay                              	*                                  	*                                  	*/
		3400,																							/* Recovery                           	*                                  	*                                  	*/
		3000,																							/* CUV Charge Presen Threshol         	*                                  	*                                  	*/
		3200,																							/* Threshold                          	CUVC                               	*                                  	*/
		11,																								/* Delay                              	*                                  	*                                  	*/
		3400,																							/* Recovery                           	*                                  	*                                  	*/
		0,																								/* CellResistance                     	*                                  	*                                  	*/
		3200,																							/* CUV Charge Presen Threshol         	*                                  	*                                  	*/
		4530,																							/* Threshold Low Temp                 	COV—Cell Overvoltage             	*                                  	*/
		4530,																							/* Threshold Standard Temp Low        	*                                  	*                                  	*/
		4530,																							/* Threshold Standard Temp High       	*                                  	*                                  	*/
		4530,																							/* Threshold High Temp                	*                                  	*                                  	*/
		4530,																							/* Threshold Rec Temp                 	*                                  	*                                  	*/
		2,																								/* COV Delay                          	*                                  	*                                  	*/
		4280,																							/* Recovery Low Temp                  	*                                  	*                                  	*/
		4280,																							/* Recovery Standard Temp Low         	*                                  	*                                  	*/
		4280,																							/* Recovery Standard Temp High        	*                                  	*                                  	*/
		4280,																							/* Recovery High Temp                 	*                                  	*                                  	*/
		4280,																							/* Recovery Rec Temp                  	*                                  	*                                  	*/
		255,																							/* Cell Overvoltage Latch Limit       	*                                  	*                                  	*/
		3,																								/* Cel Overvolt Coun Decrem Del       	*                                  	*                                  	*/
		15,																								/* Reset                              	*                                  	*                                  	*/
		9300,																							/* Threshold                          	OCC1—Overcurren In Charg 1       	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		10300,																							/* Threshold                          	OCC2—Overcurren In Charg 2       	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		50,																								/* Recovery Threshold                 	OCC—Overcurr In Cha Recov        	*                                  	*/
		30,																								/* Recovery Delay                     	*                                  	*                                  	*/
		-10400,																							/* Threshold                          	OCD1—Overcurr In Discha 1        	*                                  	*/
		11,																								/* Delay                              	*                                  	*                                  	*/
		-12900,																							/* Threshold                          	OCD2—Overcurr In Discha 2        	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		-50,																							/* Recovery Threshold                 	OCD—Overcurren In Discharg       	*                                  	*/
		30,																								/* Recovery Delay                     	*                                  	*                                  	*/
		255,																							/* Latch Limit                        	OCD—Overcurr In Discha Lat       	*                                  	*/
		10,																								/* Counter Dec Delay                  	*                                  	*                                  	*/
		15,																								/* Reset                              	*                                  	*                                  	*/
		0,																								/* Latch Limit                        	AOLD—Overload in Discharge       	*                                  	*/
		0,																								/* Counter Dec Delay                  	*                                  	*                                  	*/
		30,																								/* Recovery                           	*                                  	*                                  	*/
		0,																								/* Reset                              	*                                  	*                                  	*/
		0xf7,																							/* Threshold                          	*                                  	*                                  	*/
		0,																								/* Latch Limit                        	ASCC—Shor Circui In Charg        	*                                  	*/
		0,																								/* Counter Dec Delay                  	*                                  	*                                  	*/
		30,																								/* Recovery                           	*                                  	*                                  	*/
		0,																								/* Reset                              	*                                  	*                                  	*/
		0xd1,																							/* Threshold                          	*                                  	*                                  	*/
		0,																								/* Latch Limit                        	ASCD—Sho Circu in Dischar        	*                                  	*/
		0,																								/* Counter Dec Delay                  	*                                  	*                                  	*/
		30,																								/* Recovery                           	*                                  	*                                  	*/
		0,																								/* Reset                              	*                                  	*                                  	*/
		0xd2,																							/* Threshold1                         	*                                  	*                                  	*/
		0x93,																							/* Threshold2                         	*                                  	*                                  	*/
		60,																								/* Threshold                          	OTC—Overtemperatu in Char        	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		45,																								/* Recovery                           	*                                  	*                                  	*/
		70,																								/* Threshold                          	OTD—Overtemperat in Discha       	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		60,																								/* Recovery                           	*                                  	*                                  	*/
		98,																								/* Threshold                          	OTF—Overtemperature FET          	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		70,																								/* Recovery                           	*                                  	*                                  	*/
		-5,																								/* Threshold                          	UTC—Undertemperatu in Char       	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		0,																								/* Recovery                           	*                                  	*                                  	*/
		-20,																							/* Threshold                          	UTD—Undertempera in Disch        	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		-15,																							/* Recovery                           	*                                  	*                                  	*/
		10,																								/* Delay                              	HWD—Host Watchdog                	*                                  	*/
		2000,																							/* Charge Threshold                   	PTO—PRECHARG Mod Tim Out         	*                                  	*/
		1800,																							/* Suspend Threshold                  	*                                  	*                                  	*/
		1800,																							/* Delay                              	*                                  	*                                  	*/
		2,																								/* Reset                              	*                                  	*                                  	*/
		2500,																							/* Charge Threshold                   	CTO—Fas Charg Mod Tim Out        	*                                  	*/
		2000,																							/* Suspend Threshold                  	*                                  	*                                  	*/
		21600,																							/* Delay                              	*                                  	*                                  	*/
		2,																								/* Reset                              	*                                  	*                                  	*/
		300,																							/* Threshold                          	OC—Overcharge                    	*                                  	*/
		2,																								/* Recovery                           	*                                  	*                                  	*/
		90,																								/* RSOC Recovery                      	*                                  	*                                  	*/
		500,																							/* Threshold                          	CHGV—ChargingVoltage             	*                                  	*/
		30,																								/* Delay                              	*                                  	*                                  	*/
		0,																								/* Recovery                           	*                                  	*                                  	*/
		500,																							/* Threshold                          	CHGC—ChargingCurrent             	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		100,																							/* Recovery Threshold                 	*                                  	*                                  	*/
		2,																								/* Recovery Delay                     	*                                  	*                                  	*/
		450,																							/* Threshold                          	PCHGC—Pre-ChargingCurrent        	*                                  	*/
		20,																								/* Delay                              	*                                  	*                                  	*/
		100,																							/* Recovery Threshold                 	*                                  	*                                  	*/
		2,																								/* Recovery Delay                     	*                                  	*                                  	*/
		1500,																							/* Threshold                          	SUV—Safet Cel Undervoltag        	Permanent Fail                     	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		4580,																							/* Threshold                          	SOV—Safet Cel Overvoltag         	*                                  	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		11330,																							/* Threshold                          	SOCC—Saf Overcurr in Cha         	*                                  	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		-14200,																							/* Threshold                          	SOCD—Sa Overcur in Disch         	*                                  	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		90,																								/* Threshold                          	SOT—Overtemperature Cell         	*                                  	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		120,																							/* Threshold                          	SOTF—Overtemperature FET         	*                                  	*/
		3,																								/* Delay                              	*                                  	*                                  	*/
		3800,																							/* Check Voltage                      	VIMR—Volta Imbalan At Res        	*                                  	*/
		10,																								/* Check Current                      	*                                  	*                                  	*/
		1000,																							/* Delta Threshold                    	*                                  	*                                  	*/
		5,																								/* Delay                              	*                                  	*                                  	*/
		1800,																							/* Duration                           	*                                  	*                                  	*/
		4000,																							/* Check Voltage                      	VIMA—Voltag Imbalanc Activ       	*                                  	*/
		50,																								/* Check Current                      	*                                  	*                                  	*/
		1000,																							/* Delta Threshold                    	*                                  	*                                  	*/
		10,																								/* Delay                              	*                                  	*                                  	*/
		500,																							/* Threshold                          	CFET—CHG FET Failure             	*                                  	*/
		20,																								/* Delay                              	*                                  	*                                  	*/
		20,																								/* VoltageDifference                  	*                                  	*                                  	*/
		5,																								/* Temperature difference             	*                                  	*                                  	*/
		-500,																							/* Threshold                          	DFET—DFET Failure                	*                                  	*/
		20,																								/* Delay                              	*                                  	*                                  	*/
		5,																								/* Threshold                          	FUSE—FUSE Failure                	*                                  	*/
		2,																								/* Delay                              	*                                  	*                                  	*/
		5,																								/* 2LVL                               	2LVL—2nd Level OV                	*                                  	*/
		1000,																							/* Change Voltage                     	TCO                                	*                                  	*/
		2500,																							/* Min_Volrage                        	*                                  	*                                  	*/
		60,																								/* Max_Temp                           	*                                  	*                                  	*/
		1,																								/* Delay                              	*                                  	*                                  	*/
		50,																								/* Cell Impedance                     	*                                  	*                                  	*/
		10,																								/* K                                  	*                                  	*                                  	*/
		23213,																							/* Manufacturer Date                  	Data                               	SBS Configuration                  	*/
		0x1234,																							/* Serial Number                      	*                                  	*                                  	*/
		{7, 'S', 'U', 'N', 'W', 'O', 'D', 'A'},															/* Manufacturer Name                  	*                                  	*                                  	*/
		{4, 'B', 'X', '9', '0'},																		/* Device Name                        	*                                  	*                                  	*/
		{4, 'L', 'i', 'O', 'N'},																		/* Device Chemistry                   	*                                  	*                                  	*/
		616,																							/* Remaining Ah Capacity Alarm        	*                                  	*                                  	*/
		960,																							/* Remaining Wh Capacity Alarm        	*                                  	*                                  	*/
		10,																								/* Remaining Time Alarm               	*                                  	*                                  	*/
		0x0000,																							/* Initial Battery Mode               	*                                  	*                                  	*/
		0x0000,																							/* Configuration Register             	ConfigurationEx                    	Lenovo Data                        	*/
		0x00,																							/* Configuration 2 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 3 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 4 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 5 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 6 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 7 Register           	*                                  	*                                  	*/
		0x00,																							/* Configuration 8 Register           	*                                  	*                                  	*/
		4480,																							/* Charging Voltage                   	Normal Charging                    	*                                  	*/
		3085,																							/* Fast Charging Current              	*                                  	*                                  	*/
		0,																								/* CCCV Charging Voltage              	CCCV Charging                      	*                                  	*/
		0,																								/* CCCV Charging Current              	*                                  	*                                  	*/
		0,																								/* CCCV Curr Taper Threshold          	*                                  	*                                  	*/
		0,																								/* CCCV Curr Taper Voltage            	*                                  	*                                  	*/
		0,																								/* CCCV Curr Taper Window             	*                                  	*                                  	*/
		0,																								/* FCC Deg Current Adjust Cycle       	FCC Degrade Chg Current            	*                                  	*/
		0,																								/* FCC Deg Minimum Current            	*                                  	*                                  	*/
		0,																								/* RT CCV Max Cell                    	CCV Step Down Charging             	*                                  	*/
		0,																								/* LS1 CCV Max Cell                   	*                                  	*                                  	*/
		0,																								/* LS1 CCV Max Cell Drop              	*                                  	*                                  	*/
		0,																								/* LS2 CCV Max Cell                   	*                                  	*                                  	*/
		0,																								/* CCV Min Current                    	*                                  	*                                  	*/
		0,																								/* RT CCV Max Current Step            	*                                  	*                                  	*/
		0,																								/* LS1 CCV Max Current Step           	*                                  	*                                  	*/
		0,																								/* LS2 CCV Max Current Step           	*                                  	*                                  	*/
		0,																								/* CCV Max Time Hysteresis            	*                                  	*                                  	*/
		0,																								/* Smart Chg Voltage Sw Over          	Smart Charge                       	*                                  	*/
		0,																								/* Smart Chg Voltage                  	*                                  	*                                  	*/
		0,																								/* Smart Chg Max Cell                 	*                                  	*                                  	*/
		0,																								/* Smart Chg stp Reset                	*                                  	*                                  	*/
		0,																								/* Smart Chg Max Current Step         	*                                  	*                                  	*/
		0,																								/* Smart Chg Normal Current           	*                                  	*                                  	*/
		0,																								/* Smar Ch Ma Tim Hysteresi           	*                                  	*                                  	*/
		9300,																							/* Cell Over Current                  	Fast OverCurrent Protection        	*                                  	*/
		3,																								/* Cell Delay Time                    	*                                  	*                                  	*/
		64,																								/* Cell Recovery Time                 	*                                  	*                                  	*/
		20,																								/* Cell Alarm Hold Time               	*                                  	*                                  	*/
		1000,																							/* Cell Alarm Delta Current           	*                                  	*                                  	*/
		1500,																							/* Cell Alarm Recovery Current        	*                                  	*                                  	*/
		1,																								/* Cell Alarm Delay Time              	*                                  	*                                  	*/
		4,																								/* Cell Alarm Recovery Time           	*                                  	*                                  	*/
		400,																							/* Cell Knee Temperature              	*                                  	*                                  	*/
		-1700,																							/* Cell Final Current                 	*                                  	*                                  	*/
		-5000,																							/* FET Over Current                   	*                                  	*                                  	*/
		1,																								/* FET Delay Time                     	*                                  	*                                  	*/
		64,																								/* FET Recovery Time                  	*                                  	*                                  	*/
		20,																								/* FET Alarm Hold Time                	*                                  	*                                  	*/
		1000,																							/* FET Alarm Delta Current            	*                                  	*                                  	*/
		1500,																							/* FET Alarm Recovery Current         	*                                  	*                                  	*/
		1,																								/* FET Alarm Delay Time               	*                                  	*                                  	*/
		4,																								/* FET Alarm Recovery Time            	*                                  	*                                  	*/
		800,																							/* FET Knee Temperature               	*                                  	*                                  	*/
		-3000,																							/* FET Final Current                  	*                                  	*                                  	*/
		0,																								/* Total Charged                      	Lifetime Storage Da                 *                                  	*/
		0,																								/* Total Time                         	*                                  	*                                  	*/
		0,																								/* HiVolt Time                        	*                                  	*                                  	*/
		0,																								/* HiTemp Time                        	*                                  	*                                  	*/
		0,																								/* HiTempVolt Time                    	*                                  	*                                  	*/
		450,																							/* Storage High Temp                  	*                                  	*                                  	*/
		4100,																							/* Storage High Volt                  	*                                  	*                                  	*/
		0x00,																							/* Dual mode Status                   	Dual Mode                          	*                                  	*/
		100,																							/* LS1 Start Cycle Count              	*                                  	*                                  	*/
		960,																							/* LS1 Start Time                     	*                                  	*                                  	*/
		240,																							/* LS1 Delta Time                     	*                                  	*                                  	*/
		10,																								/* LS1 First Volt Drop                	*                                  	*                                  	*/
		50,																								/* LS2 Second Volt Drop               	*                                  	*                                  	*/
		5,																								/* LS2 Start Cycle Count              	*                                  	*                                  	*/
		120,																							/* LS2 Star Hi Vol Storag Tim         	*                                  	*                                  	*/
		49561,																							/* Age Per Month                      	*                                  	*                                  	*/
		3980,																							/* LS2 Second Drop FCC Max            	*                                  	*                                  	*/
		50,																								/* LS1 Delta Cycle Count 2            	*                                  	*                                  	*/
		200,																							/* LS1 Delta Cycle Count 3            	*                                  	*                                  	*/
		250,																							/* LS1 Delta Cycle Count 4            	*                                  	*                                  	*/
		300,																							/* LS1 Delta Cycle Count 5            	*                                  	*                                  	*/
		5,																								/* Cycle Count                        	Set FCC Design Capacity            	*                                  	*/
		180,																							/* HiVolt Time Threshold              	FCC Report DesCap Threshold        	*                                  	*/
		10,																								/* TSF Min                            	Dual Mode TempVolt Modifier        	*                                  	*/
		100,																							/* TSF Max                            	*                                  	*                                  	*/
		0,																								/* Time Spent in RT                   	Lifetime Timers                    	*                                  	*/
		0,																								/* Time Spent In LS1_1                	*                                  	*                                  	*/
		0,																								/* Time Spent In LS1_2                	*                                  	*                                  	*/
		0,																								/* Time Spent In LS1_3                	*                                  	*                                  	*/
		0,																								/* Time Spent In LS1_4                	*                                  	*                                  	*/
		0,																								/* Time Spent In LS1_5                	*                                  	*                                  	*/
		0,																								/* Time Spent in LS2                  	*                                  	*                                  	*/
		0,																								/* Adjusted HiVolt Time               	*                                  	*                                  	*/
		0,																								/* VSF High                           	LifeSpan Volt Modifier             	*                                  	*/
		0,																								/* VSF Med                            	*                                  	*                                  	*/
		0,																								/* VSF Low                            	*                                  	*                                  	*/
		0x00,																							/* VSF Default                        	*                                  	*                                  	*/
		.b_System_Data.s_Manufacturer_Data.m_ManufacturerInfo = {7, 'S', 'U', 'N', 'W', 'O', 'D', 'A'}, /* ManufacturerInfo                   	Manufacturer Data                  	System Data               	*/
		18,																								/* Manufacturer Info B Length         	Manufacturer Info B                	*                                  	*/
		0x42,																							/* Manufacturer Info B01              	*                                  	*                                  	*/
		0x4c,																							/* Manufacturer Info B02              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B03              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info B04              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info B05              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B06              	*                                  	*                                  	*/
		0x39,																							/* Manufacturer Info B07              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B08              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B09              	*                                  	*                                  	*/
		0x37,																							/* Manufacturer Info B10              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B11              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info B12              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B13              	*                                  	*                                  	*/
		0x33,																							/* Manufacturer Info B14              	*                                  	*                                  	*/
		0x41,																							/* Manufacturer Info B15              	*                                  	*                                  	*/
		0x52,																							/* Manufacturer Info B16              	*                                  	*                                  	*/
		0x41,																							/* Manufacturer Info B17              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info B18              	*                                  	*                                  	*/
		0x43,																							/* Manufacturer Info B19              	*                                  	*                                  	*/
		0x44,																							/* Manufacturer Info B20              	*                                  	*                                  	*/
		0x75,																							/* Manufacturer Info B21              	*                                  	*                                  	*/
		0x76,																							/* Manufacturer Info B22              	*                                  	*                                  	*/
		0x77,																							/* Manufacturer Info B23              	*                                  	*                                  	*/
		0x7a,																							/* Manufacturer Info B24              	*                                  	*                                  	*/
		0x78,																							/* Manufacturer Info B25              	*                                  	*                                  	*/
		0x79,																							/* Manufacturer Info B26              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info B27              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info B28              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info B29              	*                                  	*                                  	*/
		0x33,																							/* Manufacturer Info B30              	*                                  	*                                  	*/
		0x34,																							/* Manufacturer Info B31              	*                                  	*                                  	*/
		0x35,																							/* Manufacturer Info B32              	*                                  	*                                  	*/
		18,																								/* Manufacturer Info C Length         	Manufacturer Info C                	*                                  	*/
		0x42,																							/* Manufacturer Info C01              	*                                  	*                                  	*/
		0x4c,																							/* Manufacturer Info C02              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C03              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info C04              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info C05              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C06              	*                                  	*                                  	*/
		0x39,																							/* Manufacturer Info C07              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C08              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C09              	*                                  	*                                  	*/
		0x37,																							/* Manufacturer Info C10              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C11              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info C12              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C13              	*                                  	*                                  	*/
		0x33,																							/* Manufacturer Info C14              	*                                  	*                                  	*/
		0x41,																							/* Manufacturer Info C15              	*                                  	*                                  	*/
		0x52,																							/* Manufacturer Info C16              	*                                  	*                                  	*/
		0x41,																							/* Manufacturer Info C17              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info C18              	*                                  	*                                  	*/
		0x43,																							/* Manufacturer Info C19              	*                                  	*                                  	*/
		0x44,																							/* Manufacturer Info C20              	*                                  	*                                  	*/
		0x75,																							/* Manufacturer Info C21              	*                                  	*                                  	*/
		0x76,																							/* Manufacturer Info C22              	*                                  	*                                  	*/
		0x77,																							/* Manufacturer Info C23              	*                                  	*                                  	*/
		0x7a,																							/* Manufacturer Info C24              	*                                  	*                                  	*/
		0x78,																							/* Manufacturer Info C25              	*                                  	*                                  	*/
		0x79,																							/* Manufacturer Info C26              	*                                  	*                                  	*/
		0x30,																							/* Manufacturer Info C27              	*                                  	*                                  	*/
		0x31,																							/* Manufacturer Info C28              	*                                  	*                                  	*/
		0x32,																							/* Manufacturer Info C29              	*                                  	*                                  	*/
		0x33,																							/* Manufacturer Info C30              	*                                  	*                                  	*/
		0x34,																							/* Manufacturer Info C31              	*                                  	*                                  	*/
		0x35,																							/* Manufacturer Info C32              	*                                  	*                                  	*/
		0x0000,																							/* Static DF Signature                	Integrity                          	*                                  	*/
		0x0000,																							/* Static Chem DF Signature           	*                                  	*                                  	*/
		0x0000,																							/* All DF Signature                   	*                                  	*                                  	*/
		0x12,																							/* US_KEY1                            	US                                 	UNSeal                             	*/
		0x34,																							/* US_KEY2                            	*                                  	*                                  	*/
		0x56,																							/* US_KEY3                            	*                                  	*                                  	*/
		0x78,																							/* US_KEY4                            	*                                  	*                                  	*/
		0xff,																							/* FA_KEY1                            	FA                                 	*                                  	*/
		0xff,																							/* FA_KEY2                            	*                                  	*                                  	*/
		0xff,																							/* FA_KEY3                            	*                                  	*                                  	*/
		0xff,																							/* FA_KEY4                            	*                                  	*                                  	*/
		0x6181,																							/* Control flag 1                     	Control flag                       	Control flag                       	*/
		6300,																							/* FCC_max_limit                      	FCC_max_limit                      	FCC_LIMIT                          	*/
		3700,																							/* FCC_min_limit                      	FCC_min_limit                      	*                                  	*/
		100,    // D_5_10_LIMIT 
		200,  // D_5_LIMIT   
		10,   //  TEMPER_LIMIT_T1  temper_cap_limit 
		25,   //  TEMPER_LIMIT_T2 
		300,    // TEMPER_LIMIT_CAP1 
		200,    // TEMPER_LIMIT_CAP2  
		150, /* Chg_current_thresh                 	Chg_current_thresh                 	CHG_SMOOTH                         	*/
		240, /* Chg_current_low                    	Chg_current_low                    	*                                  	*/
		600, /* Chg_current_high                   	Chg_current_high                   	*                                  	*/
		40,	 /* Chg_current_time                   	Chg_current_time                   	*                                  	*/
		3,	 /* Chg_current_range                  	Chg_current_range                  	*                                  	*/
		10,	 /* Chg_smooth_cap                     	Chg_smooth_cap                     	*                                  	*/
		16,	 /* Dsg_smooth_mul                     	Dsg_smooth_mul                     	DSG_SMOOTH                         	*/
		10,	 /* Dsg_smooth_div                     	Dsg_smooth_div                     	*                                  	*/
		0 ,  /* K_UPDATE_FAC 	*/

};
