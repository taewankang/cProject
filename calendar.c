#include "calendar.h"

int sum_of_range(int low, int high, int (*term) (int), int (*next) (int))
{
	int i, result = 0;

	for (i = low; i <= high; i = (*next) (i))
	{
		result += (*term) (i);
	}

	return result;
}

int leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int inc(int x)
{
	return x + 1;
}

int year_term(int year)
{
	return leap_year(year) ? 366 : 365;
}

int days_of_year(int low, int high)
{
	return sum_of_range(low, high, year_term, inc);
}

int month_term(int month)
{
	return months[month];
}

int days_of_month(int low, int high, int year)
{
	int days = sum_of_range(low, high, month_term, inc);

	return low <= 2 && high >= 2 && leap_year(year) ? days + 1 : days;
}

void pre_fixed(int times)
{
	while (times--) printf("\t");
}

void calendar(int days, int year, int month)
{
	int i, month_day;
	printf("******************************************************\n");
	printf("\n");

	printf("\n\t\t%d\t\t%d\n\n", year, month);
	printf("Mon\tTues\tWen\tThur\tFri\tSta\tSun\n");

	if (month == 2)
		months[month] = leap_year(year) ? 29 : 28;

	pre_fixed((days) % CYCLE);
	for (i = 1; i <= months[month]; i++)
	{
		printf("%d%c", i, (days + i) % CYCLE ? '\t' : '\n');
	}

	printf("\n\n");
	printf("******************************************************\n");
}


int is_number(char* target)
{
	while (*target != '\0' && *target >= '0' && *target <= '9')
		target++;

	return *target == '\0';
}

int mainCalendar()
{
	int year = 0, month = 0;
	int i, days = 0;

	struct tm* time_ptr;
	time_t timeval;

	int number;
	printf("************* �޷��� ��¹���� �����ϼ��� ****************\n");
	printf("\n");
	printf("1 -> ���� ���� �ش��ϴ� �޷��� ���\n");
	printf("2 -> Ư�� �⵵�� �Է��ϸ�, Ư�� ���� ��� ���� ���\n");
	printf("3 -> Ư�� �⵵�� ���� �Է��ϸ� �ش��ϴ� �޷��� ���\n");
	printf("\n");
	printf("�ϳ��� ���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &number);

	switch (number)
	{
	case 1:
		(void)time(&timeval);
		time_ptr = localtime(&timeval);

		year = time_ptr->tm_year + 1900;
		month = time_ptr->tm_mon + 1;
		days += days_of_year(START_YEAR, year - 1);
		days += days_of_month(1, month - 1, year);

		calendar(days, year, month);
		break;

	case 2:
		printf("����Ͻ� �޷��� �⵵�� �Է��ϼ��� : ");
		scanf("%d", &year);
		if (year < 1900) {
			printf("1900�̻��� �⵵�� Ȯ���� �� �ֽ��ϴ� !\n");
			break;
		}

		days += days_of_year(START_YEAR, year - 1);
		for (i = 1; i <= 12; i++)
		{
			calendar(days, year, i);
			days += months[i];
		}
		break;

	case 3:
		printf("����Ͻ� �޷��� �⵵�� �Է��ϼ��� : ");
		scanf("%d", &year);
		if (year < 1900) {
			printf("1900�̻��� �⵵�� Ȯ���� �� �ֽ��ϴ� !\n");
			break;
		}
		printf("����Ͻ� �޷��� ���� �Է��ϼ��� : ");
		scanf("%d", &month);
		if (1 > month || month > 12) {
			printf("�߸��� �� �Է�!!\n");
			break;
		}
		days += days_of_year(START_YEAR, year - 1);
		days += days_of_month(1, month - 1, year);

		calendar(days, year, month);
		break;

	default:
		fprintf(stderr, "�߸��� �Է�! \n");
	}

	return 0;
}