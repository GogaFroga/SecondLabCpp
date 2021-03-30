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

float ComplexNumber::get_image()
{
	std::cout << ComplexNumber::m_image;
	return(m_image);
}

float ComplexNumber::get_real()
{
	std::cout << ComplexNumber::m_real;
	return(m_real);
}

// solo operations
float ComplexNumber::get_abs()
{
	return(ComplexNumber::m_image * ComplexNumber::m_image + ComplexNumber::m_real * ComplexNumber::m_real);
}

float ComplexNumber::get_conjugate()
{
	ComplexNumber::m_image = ComplexNumber::m_image * -1;
	return(ComplexNumber::m_real, ComplexNumber::m_image);
}

float ComplexNumber::get_arg()
{
	return(pow(ComplexNumber::m_image * ComplexNumber::m_image + ComplexNumber::m_real * ComplexNumber::m_real, 0.5));
}

// two numbers operations
float ComplexNumber::get_sum(class ComplexNumber numberTwo)
{

	return(ComplexNumber::m_real + numberTwo.m_real, ComplexNumber::m_image + numberTwo.m_image);
}

float ComplexNumber::get_dif(class ComplexNumber numberTwo)
{
	return(ComplexNumber::m_real - numberTwo.m_real, ComplexNumber::m_image - numberTwo.m_image);
}

float ComplexNumber::get_multi(class ComplexNumber numberTwo)
{
	return((ComplexNumber::m_real * numberTwo.m_real) + -1 * (ComplexNumber::m_image * numberTwo.m_image),
		(ComplexNumber::m_real * numberTwo.m_image) + (numberTwo.m_real * ComplexNumber::m_image));
}

double ComplexNumber::get_div(class ComplexNumber numberTwo)
{
	ComplexNumber::m_real = ComplexNumber::m_real * numberTwo.m_real + ComplexNumber::m_image * numberTwo.m_image
		/ pow(numberTwo.m_real, 2) + pow(numberTwo.m_image, 2);

	ComplexNumber::m_image = ComplexNumber::m_image * numberTwo.m_real + numberTwo.m_image * ComplexNumber::m_real
		/ pow(numberTwo.m_real, 2) + pow(numberTwo.m_image, 2);

	return(ComplexNumber::m_real, ComplexNumber::m_image);
}
