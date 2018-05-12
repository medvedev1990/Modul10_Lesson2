#pragma once
struct date_Of_Birthday {
	int day;
	int month;
	int year;
};
struct NOTE1 {
	char name[20];
	char surname[20];
	long long tele;
	date_Of_Birthday dob;
};
struct TOVAR {
	char name[100];
	int kollichestvo;
	int sale;
	date_Of_Birthday dob;
};
