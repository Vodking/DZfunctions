#include<iostream>
#include<cstdlib>

using namespace std;

int DataMinuser(int year1, int year2, int month1, int month2, int day1, int day2);//Задача 1
int Visokosnik(int year1, int year2);//Задача 1
int ArrAvarage(int arr[], int size);//Задача 2
int PosOrNegOrZer(int arr[], int size, int choose);//Задача 3


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	//Задание 1
	int year1, year2, month1, month2, day1, day2;
	cout << "Введите год первой даты: \n";
	cin >> year1;
	cout << "Введите месяц первой даты: \n";
	cin >> month1;
	cout << "Введите день первой даты: \n";
	cin >> day1;

	cout << "Введите год второй даты: \n";
	cin >> year2;
	cout << "Введите месяц второй даты: \n";
	cin >> month2;
	cout << "Введите день второй даты: \n";
	cin >> day2;
	cout << "Количество дней между этими датами - " << DataMinuser(year1, year2, month1, month2, day1, day2) << " Дней\n\n\n";

	//Задача 2
	const int size = 5;
	int arr[5];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите число: \n";
		cin >> arr[i];
	}
	cout << "Среднее арифметическое этого массива - " << ArrAvarage(arr, size) << "\n\n\n";
	//Задача 3
	int choose;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите число: \n";
		cin >> arr[i];
	}
	cout << "Введите выбор. 1 - больше ноля, 0 - нули, -1 - меньше ноля: \n";
	cin >> choose;
	cout << PosOrNegOrZer(arr, size, choose);
}

int DataMinuser(int year1, int year2, int month1, int month2, int day1, int day2) //Задача 1
{
	int totaldays1, totaldays2;
	if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12)
	{
		totaldays1 = year1 * 365 + 31 - day1 + Visokosnik(0, year1);
	}
	else if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
	{
		totaldays1 = year1 * 365 + 30 - day1 + Visokosnik(0, year1);
	}
	else if (year1 % 4 == 0)
	{
		totaldays1 = year1 * 365 + 29 - day1 + Visokosnik(0, year1);
	}
	else if (year1 % 4 != 0)
	{
		totaldays1 = year1 * 365 + 28 - day1 + Visokosnik(0, year1);
	}

	if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12)
	{
		totaldays2 = year2 * 365 + 31 - day2 + Visokosnik(0, year2);
	}
	else if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11)
	{
		totaldays2 = year2 * 365 + 30 - day2 + Visokosnik(0, year2);
	}
	else if (year2 % 4 == 0)
	{
		totaldays2 = year2 * 365 + 29 - day2 + Visokosnik(0, year2);
	}
	else if (year2 % 4 != 0)
	{
		totaldays2 = year2 * 365 + 28 - day2 + Visokosnik(0, year2);
	}
	if (totaldays2 - totaldays1 < 0)
	{
		return totaldays1 - totaldays2;
	}
	else
	{
		return totaldays2 - totaldays1;
	}
}

int Visokosnik(int year1, int year2)//Задача 1
{
	int totalDays = 0;
	for (int i = year1; i < year2; i++)
	{
		if (i % 4 == 0)
		{
			totalDays++;
		}
	}
	return totalDays;
}

int ArrAvarage(int arr[], int size)//Задача 2
{
	int sum = 0;
	
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

int PosOrNegOrZer(int arr[], int size, int choose)//Задача 3
{
	int positive = 0, negative = 0, zeros = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)
		{
			positive++;
		}
		else if (arr[i] < 0)
		{
			negative++;
		}
		else
		{
			zeros++;
		}
	}
	if (choose == 1)
	{
		return positive;
	}
	else if (choose == 0)
	{
		return zeros;
	}
	else if (choose == -1)
	{
		return negative;
	}
	else
	{
		cout << "Нет такого выбора";
		return -1;
	}
}
