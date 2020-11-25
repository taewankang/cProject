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

int func3()
{
	int num;

	while (getchar() != '\n');
	fflush(stdin);

	printf("---확인할 기능을 선택해 주세요---.\n");
	printf("1.작업 시간 확인\n");
	printf("2.전체 작업 내용 확인\n");
	scanf("%d", &num);

	switch(num)
	{
	case 1:
			Time_check();
			break;

		case 2:
			Day_check();		
			break;
	}
	return 0;
}

