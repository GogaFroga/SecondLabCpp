#pragma once
#define NOMINMAX
#include<windows.h>
#include<locale.h>
#include<string>		// strcompare
#include<iostream>
#include"classes.h"		// calc lib
/* 
#include<cstdlib>
#include<cstdio>     
#include<memory>
#include<stdexcept> 
*/

using namespace std;

int main()
{
	HWND hwnd;
	char Title[1024];
	int iWidth = GetSystemMetrics(SM_CXSCREEN);		// разрешение экрана по горизонтали
	int iHeight = GetSystemMetrics(SM_CYSCREEN);	// разрешение экрана по вертикали
	GetConsoleTitle(Title, 1024);					// Узнаем имя окна
	hwnd = FindWindow(NULL, Title);					// Узнаем hwnd окна
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char _string[100];
	ComplexNumber number;
	number.set_image(10.0);
	number.set_real(10.0);
	number.get_image();
	number.get_real();
	std::cout << number.get_abs() << "\n";
	std::cout << number.get_conjugate() << "\n";
	std::cout << number.get_arg() << "\n";
	
	cout << "\n";
	while (strcmp(_string, "quit") != 0)
	{
		cout << "Enter your string, author or quit!\n>>";
		std::cin >> _string;						// Example: (a + bi) + (a + bi) or (a + bi) * (a + bi)

		if (strcmp(_string, "quit") == 0)
			break;
		else if (strcmp(_string, "author") == 0)
		{
			system("cls");
			cout << "[printed] Author: \n\n";
		}
		else
		{
			system("cls");
			parse(_string);
			cout << "[printed]\n\n";
		}
	}
}


void parse(std::string _string)
{	
	std::string local_string = _string;
	std::string a_string;
	int i = 1;                  // Example: (a + bi) + (a + bi) <or> (a + bi) * (a + bi)
	if (local_string[i] == "(") // если сначала "(", значит у нас два числа 
	{
		ComplexNumber number1;
		ComplexNumber number2;
		/*number1.set_image();
		number1.set_real();*/
		while (i > 0)
		{

			i++;
		}
		if (_string.find("<+>") != string::npos)
			cout << "Result: " << number1.get_sum(number2);
		if (_string.find("<->") != string::npos)
			cout << "Result: " << number1.get_dif(number2);
		if (_string.find("<*>") != string::npos)
			cout << "Result: " << number1.get_multi(number2);
		if (_string.find("</>") != string::npos)
			cout << "Result: " << number1.get_div(number2);
	}
	else if (local_string[0] == "<") // если сначала "<", значит у нас одно число
	{
		ComplexNumber number1;
		i = _string.find("(");
		while (i > 0)
		{
			i++;
			a_string = local_string[i]
		}
		if (_string.find("conj") != string::npos)
		{
			number1.get_conjugate();
			cout << "Result: conj = " << number1.get_real() << " + " << number1.get_image() << "i";
		}
		if (_string.find("abs") != string::npos)
			cout << "Result: abs = " << number1.get_abs();
		if (_string.find("arg") != string::npos)
			cout << "Result: arg = " << number1.get_arg();
		if (_string.find("re") != string::npos)
			cout << "Result: re = " << number1.get_real();
		if (_string.find("im") != string::npos)
			cout << "Result: im = " << number1.get_image();
	}
	else
		cout << "[ Ошибка ввода: Символ номер 1 ]\n";
}
