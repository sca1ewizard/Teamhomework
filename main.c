/*-----------------------------------------------------*/ 
/*          Объявление библиотек и макросов            */
/*-----------------------------------------------------*/

#include "header.h"
#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#pragma warning(disable: 4996)
#define ERROR - 1

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	int error = 0;	
	int M_Sort;
	char YN;
	int Amount_of_elements;
	clock_t  start_time, end_time;
	FILE* file;

/*-----------------------------------------------------*/
/*               Работа с  массивом                    */
/*-----------------------------------------------------*/

	srand(time(NULL));
	printf("Enter amount of elements: ");
	scanf("%i", &Amount_of_elements);
	getchar();
	int left_index = 0;
	int right_index = Amount_of_elements - 1;
	int* mas = (int*)malloc(Amount_of_elements * sizeof(int));
	int* tmp = (int*)malloc(Amount_of_elements * sizeof(int));
	for (int i = 0; i < Amount_of_elements; i++)
	{
		mas[i] = (0 + rand() % 100);
	}
//------------------------------------------------------------//

	printf("---------------------------------------\n");
	printf("Do you want to see your origin array [Y|N]?\t");
	scanf("%c", &YN); 
	printf("\n");
	if ((YN == 'Y') || (YN == 'y'))
	{
		for (int i = 0; i < Amount_of_elements; i++)
		{
			printf("%i ", mas[i]);
		}
		printf("\n");
	}
	printf("\n");

//------------------------------------------------------------//


/*-----------------------------------------------------*/
/*                 Выбор сортировки                    */
/*-----------------------------------------------------*/

	printf("---------------------------------------\n");
	printf("Choose the sorting algorithm:\n\n");
	printf(" 1.Selection sort (Сортировка выбором)\n");
	printf(" 2.Merger sort (Сортировка слиянием)\n\n");
	printf("Your choose:   ");
	scanf("%i", &M_Sort);
	getchar();
	printf("\n");
	switch (M_Sort)
	{
		case 1:
			{
				start_time = clock();
				printf("Processing...");
				Selection_sort(mas, Amount_of_elements);
				end_time = clock();
				double  search_time = 1.0 * (end_time - start_time) / CLOCKS_PER_SEC;
				printf("\rYour array successfully sorted for %.50f seconds\n", search_time);



				if ((file = fopen("Selection_file.txt", "a")) == NULL) {		
					printf("Cannot open Selection_file.\n");						
					exit(1);											
				}
				else
				{
					fprintf(file, "%d;", Amount_of_elements);
					fprintf(file , "%.50f\n", search_time);
				}
				fclose(file);




				break;
			}

		case 2:
			{
				start_time = clock();
				printf("Processing..."); 
				Merger_sort(mas, tmp, 0, Amount_of_elements - 1);
				end_time = clock();
				double  search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
				printf("\rYour array successfully sorted for %.50f seconds\n", search_time);



				if ((file = fopen("Merger_file.txt", "a")) == NULL) {		
					printf("Cannot open Merger_file.\n");					
					exit(1);											
				}
				else
				{
					fprintf(file, "%d - ", Amount_of_elements);
					fprintf(file, "%.50f;\n", search_time);
				}
				fclose(file);




				break;
			}
		default:
			{	
				error = 1;
				printf("Error type of algirithm\n");
				exit(ERROR);
			}
	}



/*-----------------------------------------------------*/
/*        Вывод отсортированного массива               */
/*-----------------------------------------------------*/
	system("C:\\Users\\Professional\\Desktop\\Projects\\teamhomework\\sound.mp3");

	if (error == 0) 
	{
		printf("Do you want to see your sorted array [Y|N]?\t");
		scanf("%c", &YN);
		printf("\n");
		if ((YN == 'Y') || (YN == 'y'))
		{
			for (int i = 0; i < Amount_of_elements; i++)
			{
				printf("%i ", mas[i]);
			}
			printf("\n");
		}
	}
	printf("\n\n\n\n\n\n");
	free(mas);
	free(tmp);
	return 0;
}