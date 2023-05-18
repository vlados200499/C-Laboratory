#include<cstdio>
#include <cmath>


void N1()
{
	for (int i = 1; i <= 5; ++i)
	{
		for (int k = 0; k < i; ++k)
		{
			printf("O");
		}
		printf("\n");
	}
}


void N2()
{
	int x;
	scanf_s("%d", &x);


	for (int i = 0; i < x; ++i)
	{
		for (int k = x - 1 - i; k > 0; --k)
		{
			printf(" ");
		}

		for (int d = 0; d < (i * 2) + 1; ++d)
		{
			printf("X");
		}


		printf("\n");
	}
}

int N3()
{
	int n, m;

	printf("Enter n and m: ");
	scanf("%d %d", &n, &m);

	double sum = 0.0;

	for (int i = 1; i <= n; i++)
	{
		double prod = 1.0;
		for (int j = 1; j <= m; j++)
		{
			double numerator = i * i + j * j - 1;
			double denominator = 2 * i + 3 * j + 4;
			prod *= numerator / denominator;
		}
		sum += prod;
	}

	printf("Sum: %lf\n", sum);

	return 0;
}

int sum_of_divisors(int num)
{
	int sum = 0;
	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

void N4()
{
	int a;

	printf("Type max number:");
	scanf("%d", &a);
	
	printf("Numbers are : ");

	for (int i = 1; i <= a; i++)
	{
		int sum = sum_of_divisors(i);
		if (sum > i && sum_of_divisors(sum) == i)
		{
			printf("%d i %d\n", i, sum);
		}
	}
}




int main()
{
	N1();
	
	N2();
	
	N3();
	
	N4();
}