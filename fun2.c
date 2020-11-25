#include "fun2.h"

int func2Input() {
	char c;
	while (getchar() != '\n');
    fflush(stdin);
    printf("�۾��� �����Ͻðڽ��ϱ�?(Y/N): ");
    scanf("%c", &c);
    return (c == 'Y' || c == 'y');
}

void func2FindFileTitle() {
    memset(date, '\0', 100);
    time_t t = time(NULL);
    struct tm* p = localtime(&t);
    char temp[5] = "";

    sprintf(temp, "%d", (p->tm_year + 1900)); //��¥ ������
    strcat(date, temp);
    strcat(date, ".");

    sprintf(temp, "%d", p->tm_mon + 1);
    strcat(date, temp);
    strcat(date, ".");

    sprintf(temp, "%d", p->tm_mday);
    strcat(date, temp);

    strcat(date, ".txt");
}

void func2CalculateTime(int isStart) {
    time_t t = time(NULL);
    struct tm* p = localtime(&t);
    char temp[5] = "", timeArr[100] = "";
    sprintf(temp, "%d", p->tm_hour);
    strcat(timeArr, temp);
    strcat(timeArr, ":");
    sprintf(temp, "%d", p->tm_min);
    strcat(timeArr, temp);
    strcat(timeArr, "\n");
    if (isStart == 1) {
        memset(startTime, '\0', 100);
        strcat(startTime, "begin: ");
        strcat(startTime, timeArr);
    }
    else {
        memset(endTime, '\0', 100);
        strcat(endTime, "end: ");
        strcat(endTime, timeArr);
    }
}

void func2ShowStartMessage() {
    printf("\n########################\n");
    printf("�۾� �� �޸� �� �� �ֽ��ϴ�.\n");
    printf("�۾��� �������� quit�� �Է��ϼ���.\n");
}

void func2ShowEndMessage() {
    printf("����Ǿ����ϴ�.\n");
    printf("########################\n\n");
}

int func2WriteMessage() {
    func2ShowStartMessage();
    fflush(stdin);
    int idx = 0;
    char c;
    while (1) {
        char buf[CONTENT_SIZE] = "";
        int i = 0;
        while (1) {
            scanf("%c", &c);
            buf[i++] = c;
            if (c == '\n') break;
        }
        if (strcmp(buf, "quit\n")) strcat(content[idx++], buf);
        else break;
    }
    func2ShowEndMessage();
    return idx;
}


void func2() {
    if (func2Input()) {
		clock_t start = clock();
        func2FindFileTitle();
        FILE* fp = fopen(date, "a");
        if (fp == NULL) fp = fopen(date, "wt");
        for (int i = 0; i < 50; i++) memset(content[i], '\0', CONTENT_SIZE);
        func2CalculateTime(1); //���� �ð� ����
        int idx = func2WriteMessage();
        func2CalculateTime(0); //������ �ð� ����
        fwrite(startTime, 1, strlen(startTime), fp);
        for (int i = 0; i < idx; i++) fwrite(content[i], 1, strlen(content[i]), fp);
        fwrite(endTime, 1, strlen(endTime), fp);
		clock_t end = clock();

		// ���� �ð� ���
		int min=0, hour=0;
		min = ((end - start) / CLOCKS_PER_SEC)/ 60;
		hour = min / 60;
		char temp[50] = "Total:";

		sprintf(totalTime, "%d", hour);
		strcat(temp, totalTime);
		strcat(temp, "��");

		sprintf(totalTime, "%d", min);
		strcat(temp, totalTime);
		strcat(temp, "��");

		sprintf(totalTime, "%d", ((end - start) / CLOCKS_PER_SEC));
		strcat(temp, totalTime);
		strcat(temp, "��");
		
		fprintf(fp, "%s\n", temp);
		//��� ��

		fclose(fp);
    }
    else printf("�۾� ���\n");
}

