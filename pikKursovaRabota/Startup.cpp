#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void insertValues(int arr[],int lenght);
void printValues(int arr[], int lenght);
void checkElement(int arr[], int lenght);
void printRealRoots(int arr[], int lenght);
void readFromFile(FILE *fileArray ,int arr[]);
int SaveArrayIntoAFile(int lenght, int arr[]);
	
int main()
{
	FILE *fileArray, *file;
	fileArray = fopen("numbers.txt", "r");
	char fileName[100];
    int arr[100];
	int lenght,cases;
	bool activity = 0 ;
	do
	{
		printf("Enter number between 1-100 for legnth,please!\n");
		lenght = inputNumber();
	} while (lenght < 1 || lenght > 100);
	for (; ; )
	{
		printf("_____________________________MENU_____________________________\n--------------------------------------------------------------|\nHello ! What would you like to do now ?                       |\n--------------------------------------------------------------|\nPlease select one of the options listed below.                |\n--------------------------------------------------------------|\n1.I would like to enter numbers in the array                  |\n--------------------------------------------------------------|\n2.I would like to search for specific element in the array.   |\n--------------------------------------------------------------|\n3.I would like to see the array with it's elements            |\n--------------------------------------------------------------|\n4.I would like to see the biggest sum of array digits         |\n--------------------------------------------------------------|\n5.I would like to load existing numbers                       |\n--------------------------------------------------------------|\n6.I would like to save my array into a text file              |\n--------------------------------------------------------------|\n7.Exit                                                        |\n--------------------------------------------------------------|\n");
		printf("\nEnter your choice!");
		cases = inputNumber();
		switch (cases)
		{
		case 1: insertValues(arr, lenght); activity = 1; break;
		case 2:
			if (activity == 0)
			{
				printf("Please use option 1 or option 5 first!!!\n");
				getchar();
				break;
				
			} checkElement(arr, lenght); break;
			case 3: if (activity == 0)
			{
				printf("Please use option 1 or option 5 first!!!\n");
				getchar();
				break;
				
			} printValues(arr, lenght); break; 
			case 4: if (activity == 0)
			{
				printf("Please use option 1 or option 5 first!!!\n");
				getchar();
				break;
				
			} printRealRoots(arr, lenght); break;
			case 5: readFromFile(fileArray, arr); break;
			case 6: if (activity == 0)
			{
				printf("Please use option 1 or option 5 first!!!\n");
					getchar();
				break;
				
			} SaveArrayIntoAFile(lenght, arr); break;
			case 7: goto exit;
			default: printf("Wrong choice");
			
		}
	}
	
	exit:
	printf("\nThank you for using our app!\n\n");
	

}

void insertValues(int arr[], int lenght)
{

	for (int i = 0; i<lenght; ++i)
	{
		printf("Enter number%d: ", i + 1);
		arr[i] = inputNumber();
	}
	printf("Succesfully imported values!");
	printf("\nPress any key to continue!");
	getchar();
	
}
void printValues(int arr[],int lenght)
{
	for (int i = 0; i < lenght; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Press any key to continue!");
	getchar();

}
void checkElement(int arr[],int lenght)
{
	int element;
	printf("Enter the element you search for!:");
	element = inputNumber();
	int num = 0;
	
		for (int i = 0; i < lenght; i++)
		{
			if (arr[i] == element)
			{
				num = 1;
			}
			
		
		}

		if (num != 0)
		{
			printf("We have your number !\n");

		}
		else if (num == 0)
		{
			printf("We dont have your number !\n");

		}
		printf("Press any key to continue!");
		getchar();
}
void printRealRoots(int arr[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{ 
			int num = arr[i];
			for (int k = 1; k <= num; k++)
			{
				if (k*k==num)
				{
					printf("The number %d has integer sqroot!", num);
					return;
				}	
			}
	
	}
	printf("Press any key to continue!");
	getchar();
}
void readFromFile(FILE *fileArray,int arr[])
{
	if (fileArray == NULL) { printf("Error loading file"); return 0; }

	for (int i = 0; i < 99 ; i++)
	{
		fscanf(fileArray, "%d,", &arr[i]);

	}

	for (int i = 0; i < 99; i++)
	{
		if (arr[i] != -858993460)
		{
			printf("Number %d is: %d\n\n", i + 1, arr[i]);
		}

	}
	fclose(fileArray);
	printf("Press any key to continue!");
	getchar();
	return;
	
	
}
int SaveArrayIntoAFile(int lenght, int arr[]) {
	char fileName[100];
    
	printf("Please enter name for your file: ");
	scanf("%s", fileName);
	strcat(fileName, ".txt");
	FILE *file = fopen(fileName, "w");

	for (int i = 0; i < lenght; i++)
	{
		fprintf(file, "%d ", arr[i]);
	}
	fclose(file);
	printf("We successfully saved your numbers in %s \n", fileName);
	getchar();
	printf("Press any key to continue!");
	return 0;
	
}
int inputNumber(void)
{
	char *p, string[30];
	int n;
	fflush(stdin);
	while (fgets(string, sizeof(string), stdin)) {
		n = strtol(string, &p, 10);
		if (p == string || *p != '\n') {
			printf("\nPlease enter number with correct value, without letters: ");
			
		}
		
		else
			break;
	}
	return n;
}
