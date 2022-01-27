# Penyo 数学库使用向导 `Ver. 22.1.27`

**警告：请按照正确的数学常识引用本库中的函数，否则将有可能导致您的程序无法按预期运行。**

本库中的函数共有四个类别：
- 判断：返回值为0或1，一般表示有参数构成的命题的[布尔值](https://baike.baidu.com/item/%E5%B8%83%E5%B0%94%E5%80%BC)。
- 筛选：返回值为接收到的多个参数中符合要求的一个。
- 求解：返回值由接收到的参数经过一定计算得出。
- 排列：无返回值，但以其他的形式输出结果。

---

## 索引

函数原型|功能描述|开发日志
-|-|-
int ifeven(int a)|判断：a是偶数
int ifleapyear(int year)|判断：year是[闰年](https://baike.baidu.com/item/%E9%97%B0%E5%B9%B4)
int ifncst(int a)|判断：a是[水仙花数](https://baike.baidu.com/item/%E6%B0%B4%E4%BB%99%E8%8A%B1%E6%95%B0)
int ifodd(int a)|判断：a是奇数
int ifprime(int a)|判断：a是[质数](https://baike.baidu.com/item/%E8%B4%A8%E6%95%B0)
|||
double whomax(int n, ...)|筛选：n个**双精度浮点型**值中的最大值|近期已更改
double whomin(int n, ...)|筛选：n个**双精度浮点型**值中的最小值|近期已更改
|||
double absl(double a)|求解：a的绝对值
double bmi(double w, double h)|求解：体重为w千克、身高为h米的人的[身体质量指数](https://baike.baidu.com/item/%E8%BA%AB%E4%BD%93%E8%B4%A8%E9%87%8F%E6%8C%87%E6%95%B0)
double heron(double a, double b, double c)|求解：三条边分别为a, b, c的三角形的面积
double p2pd(double x1, double y1, double x2, double y2)|求解：平面中a(x1, y1), b(x2, y2)两点间距
double pi()|求解：圆周率
double tocels(double fahr)|求解：fahr[华氏度](https://baike.baidu.com/item/%E5%8D%8E%E6%B0%8F%E5%BA%A6)所对应的摄氏度
double tofahr(double cels)|求解：cels摄氏度所对应的华氏度
int ftrs(int n)|求解：阶乘数列前n项和
int gcd(int n, ...)|求解：n个**整型**值的[最大公约数](https://baike.baidu.com/item/%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0)|近期已更改
int ivs(int a)|求解：a的[逆序数](https://baike.baidu.com/item/%E9%80%86%E5%BA%8F%E6%95%B0)
int lcm(int n, ...)|求解：n个**整型**值的[最小公倍数](https://baike.baidu.com/item/%E6%9C%80%E5%B0%8F%E5%85%AC%E5%80%8D%E6%95%B0)|近期已更改
|||
void layfbnc(int n)|排列：[斐波那契数列](https://baike.baidu.com/item/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97)前n项
void layftr(int n)|排列：阶乘数列前n项
void layncst(int lb, int ub)|排列：水仙花数数列在(lb, ub)间
void layprime(int lb, int ub)|排列：质数数列在(lb, ub)间

---

## 注意

1. 在使用`whomax`、`whomin`、`gcd`和`lcm`函数时，第一个参数应为整数，且之后的参数**必须**为浮点数或整数（取决于具体要求）。
以下展示`whomax`函数的应用示例：
```C
//问题：筛选出114514，1919.810和-2333三个数中的最大值。
double max = whomax(3, (float)114514, 1919.810, (float)-2333);
printf("%lf", max);
```
2. 所有的**排列**函数都以输出字符串的方式输出结果，每两个值之间以空格分离。

---

Copyright (c) Penyo. All rights reserved.
