#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 128

char contents[50][MAX_LENGTH];
char textfile[40];
char temp[MAX_LENGTH];
FILE *fp_file;
char *s;

int Day_check();
int Time_check();
int func3();