#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 128

char textfile[40];
char temp[MAX_LENGTH];
FILE *fp_file;
char *s;

void Day_check();
void Time_check();
int func3();