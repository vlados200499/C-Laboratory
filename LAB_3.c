#include<stdio.h>
#include<string.h>

//Liczba automorficzna to liczba, która znajduje się na końcu swego kwadratu, np.: 52 = 25, 252 = 625.
//Napisz program znajdowania wszystkich liczb automorficznych w podanym przedziale domkniętym
//<a, b>.
int isAutomorphic(int n)
{
	int square = n * n;
	while (n > 0)
	{
		if (n % 10 != square % 10)
		{
			return 0;
		}
		n /= 10;
		square /= 10;
	}
	return 1;
}//
void N1()
{
	int a, b;
	printf("[a, b]:");
	scanf("%d %d", &a, &b);

	printf("numbers in the range [%d, %d]:\n", a, b);
	for (int i = a; i <= b; i++)
	{
		if (isAutomorphic(i))
		{
			printf("%d\n", i);
		}
	}

}


//Napisz program obliczania sumy cyfr dziesiętnych podanej liczby n (rekurencyjnie).
int sumOfDigits(int n)
{
    
    if (n < 10) {
        return n;
    }

    
    return n % 10 + sumOfDigits(n / 10);
}
void N2()
{
	int n;
    printf("enter a number: ");
    scanf("%d", &n);

    int sum = sumOfDigits(n);
    printf("sum of %d is %d\n", n, sum);
}


//Opracować program, który dla wprowadzonego z klawiatury ciągu znaków (jednej
//linii tekstu ze spacjami), wyprowadza liczbę wystąpień każdej z liter a - z.

struct Text
{
	char input[999];
	int leter_count[27];
	char letter_Name[27];
}ext;
void print()
{
	for (int i = 0; i < 27; ++i)
	{
		printf("Letter %c : count %d .",ext.letter_Name[i],ext.leter_count[i]);
		printf("\n");
	}
}
void N3()
{
    
	strcpy(ext.letter_Name, "qwertyuiopasdfghjklzxcvbnm");
	scanf("%c",ext.input);
	fgets(ext.input, 1000, stdin);
	for (int i = 0; i < 27; ++i)
	{
		for (int j = 0; j < strlen(ext.input); j++)
		{
			
			if (ext.letter_Name[i] == ext.input[j])
			{
				ext.leter_count[i]++;
			}
		}
	}
	print();
}

int main()
{
	N1();
	N2();
    N3();


}
