#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Header.h"
#include<locale.h>
#include<time.h>

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n;
	printf("введите номер задания: ");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		note();
		break;
	case 2:
		tovarooborot();
		break;
	default:
		break;
	}

}