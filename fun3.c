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

int func3()
{
	int num;

	while (getchar() != '\n');
	fflush(stdin);

	printf("---Ȯ���� ����� ������ �ּ���---.\n");
	printf("1.�۾� �ð� Ȯ��\n");
	printf("2.��ü �۾� ���� Ȯ��\n");
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

