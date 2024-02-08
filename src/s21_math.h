#pragma once

#include <stdio.h>
#include <stdlib.h>
#define S21_EPS 1E-6L
#define S21_DBL_MIN 2.2250738585072014E-308L
#define S21_INFINITY 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_EXP 2.71828182845904523536028747135266250

// вычисляет абсолютное значение целого числа
int s21_abs(int x);

// вычисляет арккосинус
long double s21_acos(double x);

// вычисляет арксинус
long double s21_asin(double x);

// вычисляет арктангенс
long double s21_atan(double x);

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);

// вычисляет косинус
long double s21_cos(double x);

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);

// вычисляет натуральный логарифм
long double s21_log(double x);

// возводит число в заданную степень
long double s21_pow(double base, double exp);

// вычисляет синус
long double s21_sin(double x);

// вычисляет квадратный корень
long double s21_sqrt(double x);

// вычисляет тангенс
long double s21_tan(double x);

// проверяет на бесконечность
int s21_isinf(double x);

// проверка на NaN
int s21_isnan(double x);