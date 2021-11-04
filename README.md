# NULL_Terminated_Lines

В проект NULLTerminatedLines добавить следующие функции:

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

int  hex_to_dec(char str[]);	//Если строка является шестнадцатеричным числом, то функция возвращает его десятичное значение