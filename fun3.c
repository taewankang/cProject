#include "fun3.h"
#include "fun2.h"

int Day_check()
{
	while (getchar() != '\n');
	fflush(stdin);

	printf("날짜를 입력해 주세요( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "rb");

		if (fp_file == NULL)
		{
			printf("파일을 불러올 수 없습니다.\n");
			
			return 0;
		}

	while (1)
	{
		s = fgets(textfile, sizeof(textfile), fp_file);
		if (s == NULL)
			break;
		printf("%s", textfile);
	}

	printf("\n");

	fclose(fp_file);

	return 0;
}

int Time_check()
{
	while (getchar() != '\n');
	fflush(stdin);

	printf("날짜를 입력해 주세요( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "rb");

	if (fp_file == NULL)
	{
		printf("파일을 불러올 수 없습니다.\n");

		return 0;
	}

	while (1) {
		s = fgets(textfile, sizeof(textfile), fp_file);
		if (s == NULL)
			break;
		char*ptr = strstr(textfile, "Total");
		if (ptr == NULL) {
			printf("");
		}
		printf("%s", ptr);
	}

	printf("\n");
	fclose(fp_file);

	return 0;
}

void PlusWrite() {

	while (getchar() != '\n');
	fflush(stdin);

	printf("날짜를 입력해 주세요( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "a+");

	clock_t starts = clock();
	for (int i = 0; i < 50; i++) memset(content[i], '\0', CONTENT_SIZE);
	func2CalculateTime(1); //시작 시간 저장
	int idx = func2WriteMessage();
	func2CalculateTime(0); //끝나는 시간 저장
	fwrite(startTime, 1, strlen(startTime), fp_file);
	for (int i = 0; i < idx; i++) fwrite(content[i], 1, strlen(content[i]), fp_file);
	fwrite(endTime, 1, strlen(endTime), fp_file);
	clock_t end = clock();


	fclose(fp_file);
}

int func3()
{
	int num;

	while (getchar() != '\n');
	fflush(stdin);

	printf("---확인할 기능을 선택해 주세요---.\n");
	printf("1.작업 시간 확인\n");
	printf("2.전체 작업 내용 확인\n");
	printf("3.특정 날짜에 추가 입력\n");
	scanf("%d", &num);

	switch(num)
	{
	case 1:
		Time_check();
			break;

		case 2:
			Day_check();		
			break;

			case 3:
				PlusWrite();
				break;
	}
	return 0;
}

