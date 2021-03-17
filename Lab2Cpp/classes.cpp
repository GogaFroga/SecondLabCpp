#include<iostream>
#include"classes.h"



void ComplexNumber::set_image(float i_name)
{
	ComplexNumber::m_image = i_name;
}

void ComplexNumber::set_real(float r_name)
{
	ComplexNumber::m_real = r_name;
}

void ComplexNumber::get_image()
{
	std::cout << ComplexNumber::m_image;
}

void ComplexNumber::get_real()
{
	std::cout << ComplexNumber::m_real;
}

void ComplexNumber::set_second_image(float i_name)
{
	ComplexNumber::m_second_image = i_name;
}

void ComplexNumber::set_second_real(float r_name)
{
	ComplexNumber::m_second_real = r_name;
}

void ComplexNumber::get_second_image()
{
	std::cout << ComplexNumber::m_image;
}

void ComplexNumber::get_second_real()
{
	std::cout << ComplexNumber::m_real;
}


// operations
float ComplexNumber::get_abs()
{
	return(ComplexNumber::m_image * ComplexNumber::m_image + ComplexNumber::m_real * ComplexNumber::m_real);
}

float ComplexNumber::get_sum()
{
	return(ComplexNumber::m_real + ComplexNumber::m_second_real, ComplexNumber::m_image + ComplexNumber::m_second_image);
}

float ComplexNumber::get_dif()
{
	return(ComplexNumber::m_real - ComplexNumber::m_second_real, ComplexNumber::m_image - ComplexNumber::m_second_image);
}

float ComplexNumber::get_multi()
{
	return((ComplexNumber::m_real * ComplexNumber::m_second_real) + -1 * (ComplexNumber::m_image * ComplexNumber::m_second_image), 
		(ComplexNumber::m_real * ComplexNumber::m_second_image) + (ComplexNumber::m_second_real * ComplexNumber::m_image));
}

float get_div()
{
	std::cout << "";
}