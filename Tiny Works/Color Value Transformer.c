// Copyright (c) Penyo. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

long double C, M, Y, K, R, G, B;

void toCMYK()
{
	system("cls");
	printf("Input a RGB color value:");
	scanf("%lf %lf %lf", &R, &G, &B);
	if (!((R >= 0 && R <= 255) && (G >= 0 && G <= 255) && (B >= 0 && B <= 255)))
	{
		system("cls");
		printf("Invalid value!\n");
		system("pause");
		toCMYK();
	}
	long double R0, G0, B0, maxInRGB;
	R0 = R / 255;
	G0 = G / 255;
	B0 = B / 255;
	if (R0 > G0)
		maxInRGB = R0;
	else
		maxInRGB = G0;
	if (maxInRGB < B0)
		maxInRGB = B0;
	K = 1 - maxInRGB;
	C = (1 - R0 - K) / (1 - K);
	M = (1 - G0 - K) / (1 - K);
	Y = (1 - B0 - K) / (1 - K);
	printf("to CMYK: %.0lf %.0lf %.0lf %.0lf (#%02X%02X%02X)\n", C * 100, M * 100, Y * 100, K * 100, (int)R, (int)G, (int)B);
	system("pause");
	exit(0);
}

void toRGB()
{
	system("cls");
	printf("Input a CMYK color value:");
	scanf("%lf %lf %lf %lf", &C, &M, &Y, &K);
	if (!((C >= 0 && C <= 100) && (M >= 0 && M <= 100) && (Y >= 0 && Y <= 100) && (K >= 0 && K <= 100)))
	{
		system("cls");
		printf("Invalid value!\n");
		system("pause");
		toRGB();
	}
	C = C * 0.01;
	M = M * 0.01;
	Y = Y * 0.01;
	K = K * 0.01;
	R = 255 * (1 - C) * (1 - K);
	G = 255 * (1 - M) * (1 - K);
	B = 255 * (1 - Y) * (1 - K);
	printf("to RGB: %.0lf %.0lf %.0lf (#%02X%02X%02X)\n", R, G, B, (int)R, (int)G, (int)B);
	system("pause");
	exit(0);
}

int main()
{
	system("cls");
	printf("Welcome using Color Value Transformer! Choose the mode you need:\n[ C ] CMYK to RGB   [ R ] RGB to CMYK\n");
	char userChoice[512];
	gets(userChoice);
	if (userChoice[0] == 'C' || userChoice[0] == 'c')
		toRGB();
	else if (userChoice[0] == 'R' || userChoice[0] == 'r')
		toCMYK();
	else if (userChoice[0] == 'i')
	{
		system("cls");
		printf("Copyright (c) Penyo. All rights reserved.\n");
		system("pause");
		main();
	}
	else
	{
		system("cls");
		printf("Invalid choice!\n");
		system("pause");
		main();
	}
}
