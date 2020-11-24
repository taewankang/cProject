#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_YEAR	1900
#define CYCLE		7


static int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int sum_of_range(int low, int high, int (*term) (int), int (*next) (int));
int leap_year(int year);
int inc(int x);
int year_term(int year);
int days_of_year(int low, int high);
int month_term(int month);
int days_of_month(int low, int high, int year);
void pre_fixed(int times);
void calendar(int days, int year, int month);
int is_number(char* target);
int mainCalendar();