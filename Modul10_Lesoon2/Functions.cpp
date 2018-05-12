#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"
#include"Structers.h"

char *name()
{
	char *second_Name[] = { "Sergio", "Alex", "Elise", "Kate", "Egunio" };
	return (*(second_Name + 0 + rand() % 5));
}
char *SurName()
{
	char *familiya[] = { "Katkov","Orlov","Sokolov","Dvornichenko","Kardapolceva" };
	return (*(familiya + 0 + rand() % 5));
}
char *name_tovar()
{
	char *tovar[] = { "Milk","Oil","Bread","Corn","tomatos","Salt" };
	return (*(tovar + 0 + rand() % 6));
}
void note()
{
	NOTE1 *BLOCK;
	BLOCK = (NOTE1*)calloc(9, sizeof(NOTE1));
	for (int i = 0;i < 9;i++)
	{
		strcpy((BLOCK + i)->name, name());
		strcpy((BLOCK + i)->surname, SurName());
		(BLOCK + i)->tele = 87070000000 + rand() % 9999999;
		(BLOCK + i)->dob.day = 1 + rand() % 30;
		(BLOCK + i)->dob.month = 1 + rand() % 12;
		(BLOCK + i)->dob.year = 1960 + rand() % 50;
	}
	for (int i = 0;i < 9;i++)
	{
		for (int j = 8;j > i;j--)
		{
			char temp[20];
			if ((BLOCK + j)->name[0] < (BLOCK + (j - 1))->name[0])
			{
				strcpy(temp,(BLOCK + j)->name);
				strcpy((BLOCK + j)->name,(BLOCK + (j - 1))->name);
				strcpy((BLOCK + (j - 1))->name, temp);

			}
		}
	}
	for (int i = 0;i < 9;i++)
	{
		printf("%2d - %c.%s\n%d:%d:%d\n%ll", i, (BLOCK + i)->name[0], (BLOCK + i)->surname, (BLOCK + i)->dob.day, (BLOCK + i)->dob.month, (BLOCK + i)->dob.year, (BLOCK + i)->tele);
	}
	printf("-----------------------------------------------------\n");
	int month_dob;
	int chek = 0;
	printf("введите месяц рождения: ");
	scanf("%d", &month_dob);
	for (int i = 0;i < 9;i++)
	{
		if ((BLOCK + i)->dob.month == month_dob)
		{
			printf("%2d - %c.%s\n%d:%d:%d\n%ll", i, (BLOCK + i)->name[0], 
				(BLOCK + i)->surname,
				(BLOCK + i)->dob.day,
				(BLOCK + i)->dob.month,
				(BLOCK + i)->dob.year,
				(BLOCK + i)->tele);
			chek++;
		}
	}
	if (chek==0)
		printf("NO People");
}
void tovarooborot()
{
	TOVAR *Spisok;
	int month = 5;
	Spisok = (TOVAR*)calloc(10, sizeof(TOVAR));
	int sred_summ = 0;
	int temp;
	for (int i = 0;i < 10;i++)
	{
		strcpy((Spisok + i)->name, name_tovar());
		(Spisok + i)->kollichestvo = 1 + rand() % 1000;
		(Spisok + i)->sale = 100 + rand() % 10000;
		(Spisok + i)->dob.day = 1 + rand() % 30;
		(Spisok + i)->dob.month = 1 + rand() % 12;
		(Spisok + i)->dob.year = 2018;
		sred_summ += (Spisok + i)->sale;
	}
	sred_summ = sred_summ / 10;
	printf("средняя сумма товаров = %d\n", sred_summ);
	for (int i = 0;i < 10;i++)
	{
		for (int j = 9;j > i;j--)
		{
			if ((Spisok + j)->sale < (Spisok + (j - 1))->sale)
			{
				temp = (Spisok + j)->sale;
				(Spisok + j)->sale = (Spisok + (j - 1))->sale;
				(Spisok + (j - 1))->sale = temp;
			}
		}
	}
	for (int i = 0;i < 10;i++)
	{
		if (((Spisok + i)->dob.month) - 10 <= -5)
			printf("%2d - %10s\nData %d:%d:%d\nSale %d\nKol-vo %d\n",i, (Spisok + i)->name,
			(Spisok + i)->dob.day,
			(Spisok + i)->dob.month,
			(Spisok + i)->dob.year,
			(Spisok + i)->sale,
			(Spisok + i)->kollichestvo);
	}
}