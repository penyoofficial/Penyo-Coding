// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char userInput[64];
void Event1Interaction(), Event2Interaction(), Event3Interaction(), Event4Interaction(), Event5Interaction();

void Menu(int state)
{
	if (state)
		system("cls");
	printf("请输入需要发生事件的序号，然后按回车键。\n1. 抛硬币\n2. 掷色子\n3. 抽扑克牌\n4. 生成双色球号码\n5. 生成身份证号码\n");
	gets(userInput);
	switch (userInput[0])
	{
	case '1':Event1Interaction();
	case '2':Event2Interaction();
	case '3':Event3Interaction();
	case '4':Event4Interaction();
	case '5':Event5Interaction();
	case 'i':system("cls"); printf("Copyright (c) Penyo. All rights reserved.\n"); system("pause"); Menu(1);
	default: system("cls"); printf("非法参数！\n"); system("pause"); Menu(1);
	}
}

int main()
{
	system("cls");
	printf("欢迎使用独立随机事件生成器！\n");
	Menu(0);
}

void Seed()
{
	static long long fakeStd = -65536, fakeI = 1;
	switch (fakeStd % 3)
	{
	case 0:srand(fakeStd++ + 133 * fakeI++); break;
	case 1:case -1:srand(fakeStd++ + 266 * fakeI++); break;
	case 2:case -2:srand(fakeStd++ + 400 * fakeI++);
	}
}

void Event1()
{
	Seed();
	switch (rand() % 2)
	{
	case 0:printf("反面"); break;
	case 1:printf("正面");
	}
	printf("\t");
}

void Event1Interaction()
{
	system("cls");
	printf("请输入你要抛的枚数，然后再按回车。\n");
	gets(userInput);
	if (atoi(userInput) > 0 && atoi(userInput) < 65536)
		printf("结果：\n");
	else
	{
		system("cls");
		printf("非法参数！\n");
		system("pause");
		Event1Interaction();
	}
	for (int i = 0; i < atoi(userInput); i++)
		Event1();
	printf("\n\n是否要再次进行该项？请输入Y并按回车键。\n若需要返回主界面，直接按回车键即可。\n");
	gets(userInput);
	switch (userInput[0])
	{
	case 'Y':case 'y':Event1Interaction();
	default:Menu(1);
	}
}

void Event2()
{
	Seed();
	switch (rand() % 6 + 1)
	{
	case 1:printf("一点"); break;
	case 2:printf("二点"); break;
	case 3:printf("三点"); break;
	case 4:printf("四点"); break;
	case 5:printf("五点"); break;
	case 6:printf("六点");
	}
	printf("\t");
}

void Event2Interaction()
{
	system("cls");
	printf("请输入你要掷的粒数，然后再按回车。\n");
	gets(userInput);
	if (atoi(userInput) > 0 && atoi(userInput) < 65536)
		printf("结果：\n");
	else
	{
		system("cls");
		printf("非法参数！\n");
		system("pause");
		Event2Interaction();
	}
	for (int i = 0; i < atoi(userInput); i++)
		Event2();
	printf("\n\n是否要再次进行该项？请输入Y并按回车键。\n若需要返回主界面，直接按回车键即可。\n");
	gets(userInput);
	switch (userInput[0])
	{
	case 'Y':case 'y':Event2Interaction();
	default:Menu(1);
	}
}

void Event3()
{
	Seed();
	int cardSuitCode = rand() % 4 + 1, cardPowerCode = rand() % 15 + 1;
	char cardSuit[5], cardPower[5];
	switch (cardSuitCode)
	{
	case 1:strcpy(cardSuit, "黑桃"); break;
	case 2:strcpy(cardSuit, "方块"); break;
	case 3:strcpy(cardSuit, "梅花"); break;
	case 4:strcpy(cardSuit, "红心");
	}
	switch (cardPowerCode)
	{
	case 1:strcpy(cardPower, "A"); break;
	case 2:strcpy(cardPower, "2"); break;
	case 3:strcpy(cardPower, "3"); break;
	case 4:strcpy(cardPower, "4"); break;
	case 5:strcpy(cardPower, "5"); break;
	case 6:strcpy(cardPower, "6"); break;
	case 7:strcpy(cardPower, "7"); break;
	case 8:strcpy(cardPower, "8"); break;
	case 9:strcpy(cardPower, "9"); break;
	case 10:strcpy(cardPower, "10"); break;
	case 11:strcpy(cardPower, "J"); break;
	case 12:strcpy(cardPower, "Q"); break;
	case 13:strcpy(cardPower, "K"); break;
	case 14:strcpy(cardPower, "小王"); break;
	case 15:strcpy(cardPower, "大王");
	}
	if (cardPowerCode < 14)
		printf("%s%s\t", cardSuit, cardPower);
	else
		printf("%s\t", cardPower);
}

void Event3Interaction()
{
	system("cls");
	printf("请输入你要抽的张数，然后再按回车。\n");
	gets(userInput);
	if (atoi(userInput) > 0 && atoi(userInput) < 65536)
		printf("结果：\n");
	else
	{
		system("cls");
		printf("非法参数！\n");
		system("pause");
		Event3Interaction();
	}
	for (int i = 0; i < atoi(userInput); i++)
		Event3();
	printf("\n\n是否要再次进行该项？请输入Y并按回车键。\n若需要返回主界面，直接按回车键即可。\n");
	gets(userInput);
	switch (userInput[0])
	{
	case 'Y':case 'y':Event3Interaction();
	default:Menu(1);
	}
}

void Event4()
{
	Seed();
	printf("%02d - %02d - %02d - %02d - %02d - %02d | %02d\n",
		rand() % 33 + 1, rand() % 33 + 1, rand() % 33 + 1, rand() % 33 + 1, rand() % 33 + 1, rand() % 33 + 1,
		rand() % 16 + 1);
}

void Event4Interaction()
{
	system("cls");
	printf("请输入你要生成的个数，然后再按回车。\n");
	gets(userInput);
	if (atoi(userInput) > 0 && atoi(userInput) < 65536)
		printf("结果：\n");
	else
	{
		system("cls");
		printf("非法参数！\n");
		system("pause");
		Event4Interaction();
	}
	for (int i = 0; i < atoi(userInput); i++)
		Event4();
	printf("\n是否要再次进行该项？请输入Y并按回车键。\n若需要返回主界面，直接按回车键即可。\n");
	gets(userInput);
	switch (userInput[0])
	{
	case 'Y':case 'y':Event4Interaction();
	default:Menu(1);
	}
}

int ifleapyear(int year)
{
	if (!(year % 400))
		return 1;
	else
	{
		if (!(year % 100))
			return 0;
		else
		{
			if (!(year % 4))
				return 1;
			else
				return 0;
		}
	}
}

void Event5() //存在局限性！
{
	Seed();
	int bit1 = rand() % 6 + 1; //第一位：地区
	int bit2; //第二位：省
	switch (bit1)
	{
	case 1:bit2 = rand() % 5 + 1; break;
	case 2:bit2 = rand() % 3 + 1; break;
	case 3:bit2 = rand() % 7 + 1; break;
	case 4:bit2 = rand() % 6 + 1; break;
	case 5:bit2 = rand() % 5 + 0; break;
	case 6:bit2 = rand() % 5 + 1; break;
		//case 7:bit2 = rand() % 1 + 1; break;
		//case 8:bit2 = rand() % 2 + 1;
	}
	int bit7_10 = rand() % 120 + 1900; //第七位到第十位：出生年
	int bit7 = bit7_10 / 1000;
	int bit8 = (bit7_10 - bit7_10 / 1000 * 1000) / 100;
	int bit9 = (bit7_10 - bit7 * 1000 - bit8 * 100) / 10;
	int bit10 = bit7_10 - bit7 * 1000 - bit8 * 100 - bit9 * 10;
	int bit11_12 = rand() % 12 + 1; //第十一位到第十二位：出生月
	int bit11 = bit11_12 / 10;
	int bit12 = bit11_12 - bit11 * 10;
	int bit13_14; //第十三位到第十四位：出生日
	if (ifleapyear(bit7_10))
		bit13_14 = rand() % 29 + 1;
	else
		bit13_14 = rand() % 28 + 1;
	switch (bit11_12)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		bit13_14 = rand() % 31 + 1; break;
	case 4:case 6:case 9:case 11:
		bit13_14 = rand() % 30 + 1;
	}
	int bit13 = bit13_14 / 10;
	int bit14 = bit13_14 - bit13 * 10;
	int bit17 = rand() % 9 + 1; //第十七位：顺序码（奇男偶女）
	int bitArr[17] = { bit1,bit2,0,1,0,1,bit7,bit8,bit9,bit10,bit11,bit12,bit13,bit14,0,0,bit17 }; //第十八位：校验码
	int checkArr[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 }, sum = 0; //checkArr是位权值数组，sum是总和
	for (int i = 0; i < 17; i++) //前17位的位权值相加
		sum += checkArr[i] * bitArr[i];
	char bit18;
	switch (sum % 11)
	{
	case 0:bit18 = '1'; break;
	case 1:bit18 = '0'; break;
	case 2:bit18 = 'X'; break;
	case 3:bit18 = '9'; break;
	case 4:bit18 = '8'; break;
	case 5:bit18 = '7'; break;
	case 6:bit18 = '6'; break;
	case 7:bit18 = '5'; break;
	case 8:bit18 = '4'; break;
	case 9:bit18 = '3'; break;
	case 10:bit18 = '2';
	}
	printf("%d%d0101%04d%02d%02d00%d%c\n", bit1, bit2, bit7_10, bit11_12, bit13_14, bit17, bit18);
}

void Event5Interaction()
{
	system("cls");
	printf("警告：软件著作者不为用户使用软件造成的任何后果负责。使用则视为您知晓并同意该协议。\n请输入你要生成的个数，然后按回车。\n");
	gets(userInput);
	if (atoi(userInput) > 0 && atoi(userInput) < 65536)
		printf("结果：\n");
	else
	{
		system("cls");
		printf("非法参数！\n");
		system("pause");
		Event5Interaction();
	}
	for (int i = 0; i < atoi(userInput); i++)
		Event5();
	printf("\n是否要再次进行该项？请输入Y并按回车键。\n若需要返回主界面，直接按回车键即可。\n");
	gets(userInput);
	switch (userInput[0])
	{
	case 'Y':case 'y':Event5Interaction();
	default:Menu(1);
	}
}
