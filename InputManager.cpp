#include "MainHeader.h"
bool getNumberAndIndex(int& length, int& index)
{
	int i = 0;
	char d=0;
	char ntoget[NUM_MAX_SIZE];
	char itoget[NUM_MAX_SIZE];
	d = getchar();

	while (d != '\n')
	{
		if (d < '0' || d> '9')
		{
			cout << "wrong input";
			return false;
		}
		ntoget[i] = d;
		d = getchar();
		i++;
	}
	ntoget[i] = '\0';
	length = atoi(ntoget);

	i = 0;
	d = getchar();

	while (d != '\n')
	{
		if (d < '0' || d> '9')
		{
			cout << "wrong input";
			return false;
		}
		itoget[i] = d;
		d = getchar();
		i++;
	}
	itoget[i] = '\0';
	index = atoi(itoget);
	if (index>length)
	{
		cout << "wrong input";
		return false;
	}
	return true;
}
bool getNumbersToSort(const int n, double arr[])
{
	char numberToCheck[NUM_MAX_SIZE];
	int currentNumberLength, digitsAfterPoint;
	bool isPoint;
	char c;
	for (int i = 0; i < n; i++)
	{
		
		isPoint = false;
		currentNumberLength = 0;
		digitsAfterPoint = 0;
		c = getchar();
		while (c != ' ' && c!='\n')
		{
			if (isPoint)
				digitsAfterPoint++;
			if (c == '.')
			{
				if (currentNumberLength == 0 || isPoint)
				{
					cout << "wrong input";
					return false;
				}
				else
					isPoint = true;
			}
			else if (c == '-')
			{
				if (currentNumberLength != 0)
				{
					cout << "wrong input";
					return false;
				}
			}
			else if (c < '0' || c> '9')
			{
				cout << "wrong input";
				return false;
			}
			numberToCheck[currentNumberLength] = c;
			currentNumberLength++;
			c = getchar();
		}
		if (!isPoint || digitsAfterPoint > 4 || digitsAfterPoint < 1)
		{
			cout << "wrong input";
			return false;
		}
		numberToCheck[currentNumberLength] = '\0';
		double checkedNumber = atof(numberToCheck);
		arr[i] = checkedNumber;
	}

	return true;
}