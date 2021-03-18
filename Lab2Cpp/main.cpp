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
	std::cout << number.get_abs();

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
			
			cout << "[printed] nothing \n\n";
		}
	}
}

