// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int _stopwatch[4] = { 00,00,00,00 };
	printf("按任意键开始计时。\n%02d:%02d:%02d.%02d\n",
		_stopwatch[0], _stopwatch[1], _stopwatch[2], _stopwatch[3]);
	if (getch())
		system("cls");
	printf("按任意键停止计时。\n");
	while (1)
	{
		printf("%02d:%02d:%02d.%02d\r",
			_stopwatch[0], _stopwatch[1], _stopwatch[2], _stopwatch[3]);
		Sleep(10), _stopwatch[3] += 1;
		if (_stopwatch[3] > 99)
			_stopwatch[2]++, _stopwatch[3] = 0;
		if (_stopwatch[2] > 59)
			_stopwatch[1]++, _stopwatch[2] = 0;
		if (_stopwatch[1] > 59)
			_stopwatch[0]++, _stopwatch[1] = 0;
		if (kbhit())
			break;
	}
	system("cls");
	printf("按任意键清空记录。\n%02d:%02d:%02d.%02d",
		_stopwatch[0], _stopwatch[1], _stopwatch[2], _stopwatch[3]);
	char c;
	while ((c = getchar()) != '\n');
	if (getch())
		system("cls");
	main();
}
