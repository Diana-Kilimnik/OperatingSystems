#include "../struct.h"

void debtor(struct student arr[])
{
	int i;
	for (i = 0; i < MAXST; i++)
	{
		if ((arr[i].web < 50) || (arr[i].ukr < 50) || (arr[i].infSys < 50))
		{
			printf("%s\n", arr[i].surname);
		}
	}
	return;
}

int lowGroup(struct student arr[])
{
	float arrScores[4];
	float mid, min;
	int i, k, counter = 0;
	int j = 1;

	while (j < 5)
	{
		for (i = j - 1; i < MAXST; i++)
		{
			if (arr[i].group == j)
			{
				mid += (arr[i].web + arr[i].ukr + arr[i].infSys) / 3;
				counter++;
			}
		}
		arrScores[j - 1] = mid / counter;
		counter = 0;
		mid = 0;
		j++;
	}
	min = arrScores[0];
	counter = 1;
	for (i = 0; i < 4; i++)
	{
		if (arrScores[i] <= min)
		{
			min = arrScores[i];
			counter = i + 1;
		}
	}
	return (counter);
}

void percent(struct student arr[])
{
	int count = 0;

	int i;
	for (i = 0; i < MAXST; i++)
	{
		if (arr[i].web >= 70 && arr[i].infSys >= 70 && arr[i].ukr >= 70)
		{
			count++;
		}
	}

	float result = ((float)count * 100 / (float)MAXST);
	printf("Percent of good students: %f\n", result);
	return;
}

char *subject(struct student arr[])
{
	int ukrSum = 0;
	int webSum = 0;
	int infSysSum = 0;
	int i, max;

	for (i = 0; i < MAXST; i++)
	{
		webSum += arr[i].web;
		ukrSum += arr[i].ukr;
		infSysSum += arr[i].infSys;
	}

	if (webSum > ukrSum)
	{
		if (webSum > infSysSum)
			return "Web-technology";
		return "Information systems";
	}
	else
	{
		if (ukrSum > infSysSum)
			return "Ukrainian";
		return "Information systems";
	}
}