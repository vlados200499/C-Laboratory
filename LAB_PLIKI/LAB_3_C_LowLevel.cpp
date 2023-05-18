#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Zliczyć ilość wystąpień zdefiniowanego znaku w pliku wejściowym.
void N1()
{
	char c;
	int a = 0;
	scanf("%c", &c);
	FILE* f_file_in = fopen("input1.txt", "rt");
	while (!feof(f_file_in))
	{
		const char c_l = fgetc(f_file_in);
		if (c == c_l)
		{
			a++;
		}
	}
	printf("Rowne = %d\n", a);
}


void NumberToChar(int number, int Stars)
{
	if (Stars == 1)
	{
		printf("%c.",number-1 + 'A');
	}

	if (Stars == 2)
	{
		printf("%d.",number);
	}

	if (Stars == 3)
	{
		printf("%c.",number-1 + 'a');
	}
	if (Stars == 4)
	{
		printf("(%d)",number);
	}
	if (Stars == 5)
	{
		printf("(%c)",number-1 + 'a');
	}
}


void Number()
{
	int parent_i[1024] = {0};
	int line_i = 0;
	int current_on_level[1024] ={0};
	int counter = 1;

	FILE* f = fopen("input2.txt", "r");


	while (!feof(f))
	{
		char buf[1024];
		char* a_c = fgets(buf, 1024, f);
		if (a_c == NULL)
		{
			break;
		}
		for (int i = 0; i < strlen(buf); ++i)
		{
			if (a_c[i] == '*')
			{

				parent_i[line_i] += 1;


			}
			else
			{
				counter++;
			}
			
		}
		


		// Clear if new Tree
		if(parent_i[line_i] == 1)
		{
			for (int i = 2; i < 5; ++i)
			{
				current_on_level[i] = 0;
			}
		}

		current_on_level[parent_i[line_i]]++;
		

		for (int i = 0; i < parent_i[line_i]; ++i)
		{
			printf(" ");
		}


		
		for (int i = 0; i < parent_i[line_i]; ++i)
		{
			printf("%d.", current_on_level[i + 1]);
		}


		fseek(f,-counter,SEEK_CUR);
		a_c = fgets(buf, 1024, f);


		printf("%s", a_c);
		line_i++;
		counter = 1;
		
	}
}

void Char()
{
	int parent_i[1024] = {0}; 
	int line_i = 0;
	int current_on_level[1024] = {0};
	int counter = 1;

	FILE* f = fopen("input2.txt", "r");


	while (!feof(f))
	{
		char buf[1024];
		fseek(f, 0,SEEK_CUR);
		char* a_c = fgets(buf, 1024, f);

		if (a_c == NULL)
		{
			break;
		}

		for (int i = 0; i < strlen(buf); ++i)
		{
			if (a_c[i] == '*')
			{
				parent_i[line_i] += 1;
			}
			else
			{
				counter++;
			}
		}



		// Clear if new Tree
		if(parent_i[line_i] == 1)
		{
			for (int i = 2; i < 5; ++i)
			{
				current_on_level[i] = 0;
			}
		}

		current_on_level[parent_i[line_i]]++;
		

		for (int i = 0; i < parent_i[line_i]; ++i)
		{
			printf(" ");
		}

		
		NumberToChar(current_on_level[parent_i[line_i]],parent_i[line_i]);

		

		fseek(f,-counter,SEEK_CUR);
		a_c = fgets(buf, 1024, f);
		printf("%s", buf);
		line_i++;
		counter =1;
	}
	fseek(f, 0,SEEK_SET);
}

//Napisać programy, które przeprowadzą konwersję plików według poniższych formatów
void N2()
{
	
	Number();
	printf("\n");
	printf("\n");
	printf("\n");
	Char();
	

}

/*8. Napisz program, którego zadaniem będzie wypisanie statystyk związanych z wartościami
numerycznymi znajdującymi się w kolumnach. W skład statystyk dla każdej kolumny ma zostać
wypisana suma wszystkich pól tej kolumny oraz średnia związana z daną kolumną.
Plik wejściowy
1 2 3 5 2
0 10 12 2 3 1
Plik wyjściowy
Suma: 1 12 15 7 5 1
Srednia: 0,5 6 7,5 3,5 2,5 1*/

void N3()
{
	int row1[100][100];
	int row = 0;
	int column = 0;

	int Sum[100];
	float Srednia[100];
	FILE* f = fopen("input3.txt", "r");


	for (int i = 0; i < 100; ++i)
	{
		row1[0][i] = -1;
		row1[1][i] = -1;
	}

	

	while (!feof(f))
	{
		
		if (fgetc(f) == '\n')
		{
			column = 0;
			row++;
		}
		fseek(f,-1,SEEK_CUR);
		fscanf(f,"%d",&row1[row][column]);

		

		column++;

	}


	
	for (int j = 0; j < column; ++j)
	{
		if (row1[0][j] == -1)
		{
			Sum[j] = row1[1][j];
			Srednia[j] = row1[1][j];
		}
		else if (row1[1][j] == -1 )
		{
			Sum[j] = row1[0][j];
			Srednia[j] = row1[0][j];
		}
		else
		{
			Sum[j] = row1[0][j] + row1[1][j];
			Srednia[j] = ((float)(row1[0][j]) + (float)(row1[1][j]))/2.0;
			
		}
		
		
		
	}

	printf("%d",row1[1][0]);


	FILE *out = fopen("result3.txt", "w");
	
	fprintf(out,"%s","Suma:");
	for (int i = 0; i < column; ++i)
	{
		fprintf(out,"%d",Sum[i]);
		fprintf(out,"%c",' ');
	}
	fprintf(out,"%c",'\n');


	fprintf(out,"%s","Srednia:");
	for (int i = 0; i < column; ++i)
	{
		int buf[2] = {0};
		
		if (fmod(Srednia[i],1.0) == 0.0)
		{
			int temp = round(Srednia[i]);
			fprintf(out,"%d",temp);
		}
		else
		{
			
			fprintf(out,"%.1f",Srednia[i]);
		}
		fprintf(out,"%c",' ');
		
	}

	
}


int main()
{
	
	N1();
	N2();
	N3();
}
