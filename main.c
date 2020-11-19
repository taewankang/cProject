// #include "work2.c"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int start() {
  int N;
  printf("원하시는 번호를 입력하세요.\n");
  printf("#-------------------#\n");
  printf("1. 캘린더 확인\n");
  printf("2. 작업 기능\n");
  printf("3. 작업 확인 기능\n");
  printf("번호를 입력해주세요: ");
  scanf("%d", &N);
  return N;
}

int main(void) {
  while(1) {
    int menu = start();
  }

  return 0;
}