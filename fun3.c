#include "fun3.h"
#include "fun2.h"

int Day_check()
{
	while (getchar() != '\n');
	fflush(stdin);

	printf("��¥�� �Է��� �ּ���( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "rb");

		if (fp_file == NULL)
		{
			printf("������ �ҷ��� �� �����ϴ�.\n");
			
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

	printf("��¥�� �Է��� �ּ���( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "rb");

	if (fp_file == NULL)
	{
		printf("������ �ҷ��� �� �����ϴ�.\n");

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

	printf("��¥�� �Է��� �ּ���( ex - 2020.11.25.txt ) ");
	printf(">>");
	gets_s(textfile, 40);
	printf("\n");

	fp_file = fopen(textfile, "a+");

	clock_t starts = clock();
	for (int i = 0; i < 50; i++) memset(content[i], '\0', CONTENT_SIZE);
	func2CalculateTime(1); //���� �ð� ����
	int idx = func2WriteMessage();
	func2CalculateTime(0); //������ �ð� ����
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

	printf("---Ȯ���� ����� ������ �ּ���---.\n");
	printf("1.�۾� �ð� Ȯ��\n");
	printf("2.��ü �۾� ���� Ȯ��\n");
	printf("3.Ư�� ��¥�� �߰� �Է�\n");
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

