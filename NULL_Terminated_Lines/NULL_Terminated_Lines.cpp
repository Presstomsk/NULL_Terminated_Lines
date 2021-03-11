/*В проект NULLTerminatedLines добавить следующие функции:
void to_upper(char str[]);	//Переводит строку в верхний регистр
void to_lower(char str[]);	//Переводит строку в нижний регистр
void capitalize(char str[]);	//Первуж букву каждого слова в предложении делает заглавной
void shrink(char str[]);	//Убирает из строки лишние пробелы, например:
				//Хорошо        живет    на   всете       Винни-Пух
				//Хорошо живет на всете Винни-Пух
bool is_palindrome(char str[]);	//Определяет, является ли строка палиндромом

bool is_int_number(char str[]);	//Определяет, является ли строка целым числом, то есть, состоит только из цифр
int  to_int_numer(char str[]);	//Если строка является числом, то функция возвращает значение этого числа
int  bin_to_dec(char str[]);	//Если строка является двоичным числом, то функция возвращает его десятичное значение
int  hex_to_dec(char str[]);	//Если строка является шестнадцатеричным числом, то функция возвращает его десятичное значение*/

#include <iostream>
#include <Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLen(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
int  to_int_numer(char str[]);
int  bin_to_dec(char str[]);
int  hex_to_dec(char str[]);

int main()
{
	setlocale(LC_ALL, "");
	int number_10;
	const int n = 50;
	char str[n] = "";
	cout << "Введите строку: ";
	InputLine(str, n);
	cout << str << endl;
	cout << "Длина строки: " << StrLen(str) <<" символов."<< endl;
	to_upper(str);
	cout << "Строка в верхнем регистре: " << str << endl;
	to_lower(str);
	cout << "Строка в нижнем регистре: " << str << endl;
	capitalize(str);
	cout << "Ставим заглавные буквы в начале каждого слова: " << str << endl;
	shrink(str);
	cout << "Удаляем лишние пробелы: " << str << endl;
	cout << "Длина измененной строки: " << StrLen(str) << " символов." << endl;
	if (is_palindrome(str)==true) cout << "Строка полиндром" << endl;
	else cout << "Строка не полиндром" << endl;
	if (is_int_number(str) == true)
	{
		cout << "Строка-число!" << endl;
		number_10 = to_int_numer(str);
		if (number_10 != -1) cout << "Значение десятичного числа: " << number_10 << endl;
		number_10 = bin_to_dec(str);
		if (number_10 != -1) cout << "Значение двоичного числа в десятичной системе счисления: " << number_10 << endl;
		number_10 = hex_to_dec(str);
		cout << "Значение шестнадцатеричного числа в десятичной системе счисления: " << number_10 << endl;
	}
	else cout << "Строка - не число!" << endl;
	
	
}

void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	
	for (int i=0; str[i]; i++)
	{
	if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'а' && str[i] <= 'я')) str[i] -= 32;
	if (str[i] == 'ё') str[i] = 'Ё';
	}
	
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'А' && str[i] <= 'Я')) str[i] += 32;	
		if (str[i] == 'Ё') str[i] = 'ё';
	}
}

void capitalize(char str[])
{
	for (int i = 0; str[i]; i++)
	{
	if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'а' && str[0] <= 'я')) str[0] -= 32;
	if ((str[i] == ' ')&&((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'а' && str[i+1] <= 'я'))) str[i+1] -= 32;
	}
}

void shrink(char str[])
{
	
	int j, num = StrLen(str);
	for (int i = 0; i<num; i++)
	{   
		if (str[0] == ' ') //удаляю пробел в начале строки
		{
			for (j = i; j < num; j++) str[j] = str[j + 1];
			i--;

		}
		
		if ((str[i] == ' ') && (str[i + 1] == ' ')) //удаляю двойные пробелы
			{
				for (j=i; j < num; j++) str[j] = str[j + 1];
				i--;
				
			}
		if ((str[i] == ' ') && (str[i + 1] ==0)) //удаляю пробел в конце строки
		{
			for (j = i; j < num; j++) str[j] = str[j + 1];
			i--;

		}
		
					
	}

}

bool is_palindrome(char str[])
{   
	int num = StrLen(str);
	char* str_buf=new char[num];//создаю буфферный массив
	for (int i = 0; i < num; i++) str_buf[i] = str[i]; //копирую массив в буффер
	to_lower(str); // перевожу все символы в нижний регистр
	bool flag = true;
	for (int i = 0; i < num; i++) //оптимизация строки под проверку на полиндром
	{
		if (str[i] == ' ') //убираю все пробелы
		{
			for (int j = i; j < num; j++) str[j] = str[j + 1];
			i--;
		}
if ((str[i] == '!') || (str[i] == '.') || (str[i] == '?')|| (str[i] == ',') || (str[i] == ':') || (str[i] == '-')||(str[i] == ';'))
			/*Убираю знаки препинания! проверка на полиндром строк типа : О, лета тело! */
		
			{
				for (int j = i; j < num; j++) str[j] = str[j + 1];
			    i--; 
			}
	    
		

	}
	int num_pol = StrLen(str);
	for (int i = 0; i < num_pol; i++) //проверка на полиндром
	{
		if (str[i] != str[num_pol - 1 - i]) flag = false;
		
	}

	for (int i = 0; i < num; i++) str[i] = str_buf[i];//восстанавливаю первоначальную строку

	delete[] str_buf;

	return flag;
}

bool is_int_number(char str[])
{
	int num = StrLen(str);
		bool flag = true;
	for (int i = 0; i < num; i++) //оптимизирую строку под проверку на число
	{
		if (str[i] == ' ') //убираю пробелы
		{
			for (int j = i; j < num; j++) str[j] = str[j + 1];
			i--;
		}
		
	}
	int num_num = StrLen(str); //проверка на то, что все символы цифры
	for (int i = 0; i < num_num; i++)
	{
		if (((str[i]<48)||(str[i]>58))&&((str[i] < 65)||(str[i] > 70))&& ((str[i] < 97) || (str[i] > 102))) flag = false;

	}

	return flag;
}

int to_int_numer(char str[])
{
	int number = 0;
	int num = StrLen(str);
	int* str_num = new int[num];
	for (int i = 0; i < num; i++) str_num[i] = str[i]-48;
	for (int i = 0; i < num; i++)
	{
		if (str_num[i] > 9)
		{
			cout << "Число не является десятичным! " << endl;
			return (-1); //код ошибки
		}

	}
	for (int i = 0; i < num; i++)
	{
		number += str_num[i] * pow(10,num-1-i);
	}
	delete[] str_num;

	return number;

}

int bin_to_dec(char str[])
{
	int number = 0;
	int num = StrLen(str);
	int* str_num = new int[num];
	for (int i = 0; i < num; i++) str_num[i] = str[i] - 48;
	for (int i = 0; i < num; i++)
	{
		if (str_num[i]>1)
		{
			cout << "Число не является двоичным! " << endl;
			return (-1); //код ошибки
		}
				      
	}
	for (int i = 0; i < num; i++)
	{
		number += str_num[i] * pow(2, num - 1 - i);
	}
	delete[] str_num;

	return number;
}

int hex_to_dec(char str[])
{
	int number = 0;
	int num = StrLen(str);
	int* str_num = new int[num] {};
	for (int i = 0; i < num; i++)
	{
		if((str[i]>=48)&&(str[i]<=57)) str_num[i] = str[i] - 48;
		if ((str[i] >= 65) && (str[i] <= 70)) str_num[i]= str[i] - 55;
		if ((str[i] >= 97) && (str[i] <= 102)) str_num[i] = str[i] - 87;
	}
	for (int i = 0; i < num; i++)
	{
		number += str_num[i] * pow(16, num - 1 - i);
	}
	delete[] str_num;

	return number;
}
