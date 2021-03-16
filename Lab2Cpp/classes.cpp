#include<iostream>
#include"classes.h"

void Complex::set_image(float a_name)
{
	Complex::m_image = a_name;
}

void Complex::set_real(float b_name)
{
	Complex::m_real = b_name;
}

void Complex::get_image()
{
	std::cout << Complex::m_image;
}

void Complex::get_real()
{
	std::cout << Complex::m_real;
}

float Complex::get_abs()
{
	return(Complex::m_image * Complex::m_image + Complex::m_real * Complex::m_real);
}

//#include <string>
//
//// Установка имени студента
//void Students::set_name(std::string student_name)
//{
//	Students::name = student_name;
//}
//
//// Получение имени студента
//std::string Students::get_name()
//{
//	return Students::name;
//}
//
//// Установка фамилии студента
//void Students::set_last_name(std::string student_last_name)
//{
//	Students::last_name = student_last_name;
//}
//
//// Получение фамилии студента
//std::string Students::get_last_name()
//{
//	return Students::last_name;
//}
//
//// Установка промежуточных оценок
//void Students::set_scores(int scores[])
//{
//	for (int i = 0; i < 5; ++i) {
//		Students::scores[i] = scores[i];
//	}
//}
//
//// Установка среднего балла
//void Students::set_average_ball(float ball)
//{
//	Students::average_ball = ball;
//}
//
//// Получение среднего балла
//float Students::get_average_ball()
//{
//	return Students::average_ball;
//}