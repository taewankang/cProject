#ifndef FUN2
#define FUN2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define CONTENT_SIZE 1000

char date[100];
char startTime[100], endTime[100] , totalTime[100];
char content[50][CONTENT_SIZE];
clock_t end;
clock_t start;

extern int func2Input();
extern void func2FindFileTitle();
extern void func2CalculateTime(int isStart);
extern void func2ShowStartMessage();
extern void func2ShowEndMessage();
extern int func2WriteMessage();
extern void func2();
#endif