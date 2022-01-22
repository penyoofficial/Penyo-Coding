# Penyo 数学库使用向导 `Ver. 22.1.23`

==警告：请按照正确的数学常识引用本库中的函数，否则将有可能导致您的程序崩溃。==

---

本库中的函数共有四个类别：
- 判断：返回值为0或1，一般表示有参数构成的命题的布尔值。
- 筛选：返回值为接收到的多个参数中符合要求的一个。
- 求解：返回值由接收到的参数经过一定计算得出。
- 排列：无返回值，但以其他的形式输出结果。

---

以下列出了本库中全部函数的原型及其功能描述：

函数原型|功能描述|备注
-|-|-
int ifeven(int a)|判断：a是偶数
int ifleapyear(int year)|判断：year是闰年
int ifncst(int a)|判断：a是水仙花数
int ifodd(int a)|判断：a是奇数
int ifprime(int a)|判断：a是质数
|||
double whomax(int n, double a, ...)|筛选：输入的n个值中最大的值|本版本更改项
double whomin(int n, double a, ...)|筛选：输入的n个值中最小的值|本版本更改项
|||
double absl(double a)|求解：a的绝对值
double bmi(double w, double h)|求解：体重为w千克、身高为h米的人的身体质量指数
double heron(double a, double b, double c)|求解：三条边分别为a, b, c的三角形的面积
double p2pd(double x1, double y1, double x2, double y2)|求解：平面中a(x1, y1), b(x2, y2)两点间距
double pi()|求解：圆周率
double tocels(double fahr)|求解：fahr华氏度所对应的摄氏度
double tofahr(double cels)|求解：cels摄氏度所对应的华氏度
int ftrs(int n)|求解：阶乘数列前n项和
int gcd2(int a, int b)|求解：a, b两数值的最大公约数|即将更改
int ivs(int a)|求解：a的逆序数
int lcm2(int a, int b)|求解：a, b两数值的最小公倍数|即将更改
|||
void layfbnc(int n)|排列：斐波那契数列前n项
void layftr(int n)|排列：阶乘数列前n项
void layncst(int lb, int ub)|排列：水仙花数数列在(lb, ub)间
void layprime(int lb, int ub)|排列：质数数列在(lb, ub)间

---

Ver. 22.1.23
Copyright (c) Penyo. All rights reserved.
