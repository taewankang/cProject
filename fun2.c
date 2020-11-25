#include "fun2.h"

int func2Input() {
	char c;
	while (getchar() != '\n');
    fflush(stdin);
    printf("작업을 시작하시겠습니까?(Y/N): ");
    scanf("%c", &c);
    return (c == 'Y' || c == 'y');
}

void func2FindFileTitle() {
    memset(date, '\0', 100);
    time_t t = time(NULL);
    struct tm* p = localtime(&t);
    char temp[5] = "";

    sprintf(temp, "%d", (p->tm_year + 1900)); //날짜 덧붙임
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
    printf("작업 중 메모를 할 수 있습니다.\n");
    printf("작업을 끝내려면 quit을 입력하세요.\n");
}

void func2ShowEndMessage() {
    printf("저장되었습니다.\n");
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
        func2CalculateTime(1); //시작 시간 저장
        int idx = func2WriteMessage();
        func2CalculateTime(0); //끝나는 시간 저장
        fwrite(startTime, 1, strlen(startTime), fp);
        for (int i = 0; i < idx; i++) fwrite(content[i], 1, strlen(content[i]), fp);
        fwrite(endTime, 1, strlen(endTime), fp);
		clock_t end = clock();

		// 총합 시간 계산
		int min=0, hour=0;
		min = ((end - start) / CLOCKS_PER_SEC)/ 60;
		hour = min / 60;
		char temp[50] = "Total:";

		sprintf(totalTime, "%d", hour);
		strcat(temp, totalTime);
		strcat(temp, "시");

		sprintf(totalTime, "%d", min);
		strcat(temp, totalTime);
		strcat(temp, "분");

		sprintf(totalTime, "%d", ((end - start) / CLOCKS_PER_SEC));
		strcat(temp, totalTime);
		strcat(temp, "초");
		
		fprintf(fp, "%s\n", temp);
		//계산 끝

		fclose(fp);
    }
    else printf("작업 취소\n");
}

