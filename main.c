#include "fun2.h"
#include "fun3.h"
#include "calendar.h"

int start() {
    int N;
    fflush(stdin);
    printf("���Ͻô� �޴��� �Է��ϼ���.\n");
    printf("#-------------------#\n");
    printf("0. ���α׷� ����\n");
    printf("1. Ķ���� Ȯ��\n");
    printf("2. �۾� ���\n");
    printf("3. �۾� Ȯ�� ���\n");
    printf("��ȣ�� �Է����ּ���: ");
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