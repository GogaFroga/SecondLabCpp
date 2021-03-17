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


/*
float ComplexOperations::get_sum()
{
	return
}
*/