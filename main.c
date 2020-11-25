#include "fun2.h"
#include "fun3.h"
#include "calendar.h"

int start() {
    int N;
    fflush(stdin);
    printf("원하시는 메뉴를 입력하세요.\n");
    printf("#-------------------#\n");
    printf("0. 프로그램 종료\n");
    printf("1. 캘린더 확인\n");
    printf("2. 작업 기능\n");
    printf("3. 작업 확인 기능\n");
    printf("번호를 입력해주세요: ");
    scanf("%d", &N);
    return N;
}

int main(void) {
    while (1) {
        int menu = start();
        if (menu == 0) break;
        else if (menu == 1) {
            mainCalendar();

        }
        else if (menu == 2) func2();
        else if (menu == 3) {
			func3();
        }
        printf("\n");
    }
    return 0;
}