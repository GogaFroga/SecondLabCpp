#pragma once
#define NOMINMAX
#include<windows.h>
#include<locale.h>
#include<string>		// strcompare
#include<iostream>
#include<TCHAR.H>		// implicit or explicit include
#include"classes.h"		// calc lib

using namespace std;
void parse(std::string _string);
unsigned int check(std::string _string, int _array[7]);
void solo_operation(class ComplexNumber number1, std::string _string);
void dual_operation(class ComplexNumber number1, class ComplexNumber number2, std::string _string);
ComplexNumber set_numbers(class ComplexNumber number, std::string _string);


int main()
{
	HWND hwnd;
	TCHAR Title[1024];
	int iWidth = GetSystemMetrics(SM_CXSCREEN);		// разрешение экрана по горизонтали
	int iHeight = GetSystemMetrics(SM_CYSCREEN);	// разрешение экрана по вертикали
	GetConsoleTitle(Title, 1024);					// Узнаем имя окна
	hwnd = FindWindow(NULL, Title);					// Узнаем hwnd окна
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char _string[100];
	
	cout << "\n";
	while (strcmp(_string, "quit") != 0)
	{
		cout << "Enter your string, author or quit!\n>>";
		std::cin >> _string;
		//std::string prove = "(3.5+i*-3)<+>(-4+i*-4.7)";	// <arg>(-4+i*-4)

		if (strcmp(_string, "quit") == 0)
			break;
		else if (strcmp(_string, "author") == 0)
		{
			system("cls");
			cout << "[printed] Author: GogaFroga\n\n";
		}
		else
		{
			//system("cls");
			parse(_string);
			cout << " [printed]\n\n";
		}
	}
}

void parse(std::string _string)
{	
	std::string local_string = _string;
	int flag = 0;
	int i = 0;                  // Example: (a + bi) + (a + bi) <or> (a + bi) * (a + bi)
	if (local_string[0] == '(') // если сначала "(", значит у нас два числа 
	{
		ComplexNumber number1;
		ComplexNumber number2;
		int F_array[8] = { 1, 1, 2, 2, 2, 4, 2, 4 };
		flag = check(local_string, F_array); // запуск проверки правильности
		if (flag == 0)
		{
			number1 = set_numbers(number1, local_string);
			local_string = local_string.substr( local_string.find('<') );
			number2 = set_numbers(number2, local_string);
			dual_operation(number1, number2, local_string); // запуск действия
		}
		else
			cout << "Ошибка в символе номер:" << flag;
	}
	else if (local_string[0] == '<') // если сначала "<", значит у нас одно число
	{
		ComplexNumber number1;
		int S_array[8] = { 1, 1, 1, 1, 1, 2, 1, 2 };
		flag = check(local_string, S_array); // запуск проверки правильности
		if (flag == 0)
		{
			number1 = set_numbers(number1, local_string);
			solo_operation(number1, local_string); // запуск действия
		}
		else
			cout << flag;
	}
	else
		cout << "[ Ошибка ввода: Символ номер 1 ]\n"; //cout << "[ Ошибка ввода: Символ номер << i << ]\n";
}

unsigned int check(std::string _string, int _array[7])
{
	unsigned int error = 0;
	int i = 0;
	int counter[7] = {0, 0, 0, 0, 0, 0, 0};

	while (_string[i] != '\0') //считаем количество// < > ( ) * - + .
	{
		if (_string[i] == '<' && counter[0] <= _array[0])
			counter[0] = counter[0] + 1;
		else if (_string[i] == '>' && counter[1] <= _array[1])
			counter[1] = counter[1] + 1;
		else if (_string[i] == '(' && counter[2] <= _array[2])
			counter[2] = counter[2] + 1;
		else if (_string[i] == ')' && counter[3] <= _array[3])
			counter[3] = counter[3] + 1;
		else if (_string[i] == '*' && counter[4] <= _array[4])
			counter[3] = counter[4] + 1;
		else if ( (_string[i] == '-') && counter[5] <= _array[5] && isdigit(_string[i + 1])) // доп проверка на наличие числа после -
			counter[3] = counter[5] + 1;
		else if ( _string[i] == '+' && (counter[6] <= _array[6]) && (isdigit(_string[i - 1])) ) // доп проверка на наличие числа перед +
			counter[3] = counter[6] + 1;
		else if (_string[i] == '.' && counter[7] <= _array[7] && isdigit(_string[i - 1]) && isdigit(_string[i + 1]))  // доп проверка на наличие числел с обеих сторон
			counter[3] = counter[7] + 1;
		else if (_string[i - 1] == '+' && _string[i] == 'i' && _string[i + 1] == '*') // проверка на i и соседей
		{} 
		else if ( (i < _string.find(">")) && (97 < int(_string[i]) < 122) ) // буквы могут быть в <>
		{} 
		else if ( (i > _string.find(">")) && (48 < int(_string[i])) && (int(_string[i]) < 57) ) // цифры могут быть в ()
		{}
		else
		{
			error = i;
			break;
		}
		i++;
	}
	//проверяем количество// < > ( ) * - + .
	//if (counter[0] != _array[0])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе < ]";
	//}
	//if (counter[1] != _array[1])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе > ]";
	//}
	//if (counter[2] != _array[2])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе ( ]";
	//}
	//if (counter[3] != _array[3])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе ) ]";
	//}
	//if (counter[4] != _array[4])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе * ]";
	//}
	//if (counter[5] != _array[5])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе - ]";
	//}
	//if (counter[6] != _array[6])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе + ]";
	//}
	//if (counter[7] != _array[7])
	//{
	//	error = -1;
	//	cout << "[ Ошибка в символе . ]";
	//}

	return(error);
}

ComplexNumber set_numbers(class ComplexNumber number1, std::string _string)
{
	int num_flag = 1;			// знак числа
	int dot_flag = 0;			// нахождение точки
	int found_flag = 0;			// нашли ли первое число
	float j = 0;					// счетчик для степени
	int i = _string.find("(");	// начало
	float real_number = 0;
	float image_number = 0;

	while ( (_string[i] != ')') || (_string.length() <= i) )
	{
		if (_string[i] == '-')
		{
			num_flag = -1;
		}
		else if (isdigit(_string[i]) && (dot_flag != 1) && (found_flag != 1)) // число, не было точки, не было i
		{
			real_number = real_number + ((int)_string[i] - 48) * pow(10, j);
			j++;
		}
		else if (_string[i] == '.')
		{
			dot_flag = 1;
			j = -1;
		}
		else if ((dot_flag == 1) && isdigit(_string[i]) && (found_flag != 1)) // БЫЛА точка, число, не было i
		{
			real_number = real_number + ((int)_string[i] - 48) * pow(10, j);
			j--;
		}
		else if (_string[i] == 'i')
		{
			real_number = num_flag * real_number;
			found_flag = 1;
			dot_flag = 0;
			num_flag = 1;
			j = 0;
		}
		else if (isdigit(_string[i]) && (found_flag == 1))
		{
			image_number = image_number + ((int)_string[i] - 48) * pow(10, j);
			j++;
		}
		else if ((dot_flag == 1) && isdigit(_string[i]) && (found_flag == 1)) // БЫЛА точка, число, не было i
		{
			real_number = real_number + ((int)_string[i] - 48) * pow(10, j);
			j--;
		}
		i++;
	}
	image_number = num_flag * image_number;
	number1.set_real(real_number);
	number1.set_image(image_number);

	return number1;
}

void solo_operation(class ComplexNumber number1, std::string _string)
{
	if (_string.find("conj") != string::npos)
	{
		number1.get_conjugate();
		cout << "Result: conj = " << number1.get_real() << " + " << number1.get_image() << "i";
	}
	else if (_string.find("abs") != string::npos)
		cout << "Result: abs = " << number1.get_abs();
	else if (_string.find("arg") != string::npos)
		cout << "Result: arg = " << number1.get_arg();
	else if (_string.find("root") != string::npos)
	{
		number1.get_root();
		cout << "Result: root = " << number1.get_real() << " + " << number1.get_image() << "i";
	}
	else if (_string.find("re") != string::npos)
		cout << "Result: re = " << number1.get_real();
	else if (_string.find("im") != string::npos)
		cout << "Result: im = " << number1.get_image();
	else
		cout << "[ Ошибка при вводе операции ]";
}

void dual_operation(class ComplexNumber number1, class ComplexNumber number2, std::string _string)
{
	ComplexNumber result;
	if (_string.find("<+>") != string::npos)
	{
		result = number1.get_sum(number2);
		cout << "Result: " << result.get_real() << " + " << result.get_image() << "i";
	}
	else if (_string.find("<->") != string::npos)
	{
		result = number1.get_dif(number2);
		cout << "Result: " << result.get_real() << " + " << result.get_image() << "i";
	}
	else if (_string.find("<*>") != string::npos)
	{
		result = number1.get_multi(number2);
		cout << "Result: " << result.get_real() << " + " << result.get_image() << "i";
	}
	else if (_string.find("</>") != string::npos)
	{
		result = number1.get_div(number2);
		cout << "Result: " << result.get_real() << " + " << result.get_image() << "i";
	}
	else
		cout << "[ Ошибка при вводе операции ]";
}
