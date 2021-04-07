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
	return(m_image);
}

float ComplexNumber::get_real()
{
	return(m_real);
}

// solo operations
float ComplexNumber::get_abs()
{
	return(pow(ComplexNumber::m_image * ComplexNumber::m_image + ComplexNumber::m_real * ComplexNumber::m_real, 0.5));
}

float ComplexNumber::get_conjugate()
{
	ComplexNumber::m_image = ComplexNumber::m_image * -1;
	return(ComplexNumber::m_real, ComplexNumber::m_image);
}

float ComplexNumber::get_root()
{
	ComplexNumber::m_real = pow((get_abs() + ComplexNumber::m_real) / 2, 0.5);
	ComplexNumber::m_image = pow((get_abs() - ComplexNumber::m_real) / 2, 0.5) * ComplexNumber::m_image / abs(ComplexNumber::m_image);
	return(ComplexNumber::m_real, ComplexNumber::m_image);
}

float ComplexNumber::get_arg()
{
	return(pow(ComplexNumber::m_image * ComplexNumber::m_image + ComplexNumber::m_real * ComplexNumber::m_real, 0.5));
}

// two numbers operations
float ComplexNumber::get_sum(class ComplexNumber numberTwo)
{
	ComplexNumber::m_real = ComplexNumber::m_real + numberTwo.m_real;
	ComplexNumber::m_image = ComplexNumber::m_image + numberTwo.m_image;
	return(0);
}

float ComplexNumber::get_dif(class ComplexNumber numberTwo)
{
	ComplexNumber::m_real = ComplexNumber::m_real - numberTwo.m_real;
	ComplexNumber::m_image = ComplexNumber::m_image - numberTwo.m_image;
	return(0);
}

float ComplexNumber::get_multi(class ComplexNumber numberTwo)
{
	ComplexNumber::m_real = (ComplexNumber::m_real * numberTwo.m_real) + -1 * (ComplexNumber::m_image * numberTwo.m_image);
	ComplexNumber::m_real = (ComplexNumber::m_real * numberTwo.m_image) + (numberTwo.m_real * ComplexNumber::m_image);
	return(0);
}

float ComplexNumber::get_div(class ComplexNumber numberTwo)
{
	ComplexNumber::m_real = ComplexNumber::m_real * numberTwo.m_real + ComplexNumber::m_image * numberTwo.m_image
		/ pow(numberTwo.m_real, 2) + pow(numberTwo.m_image, 2);
	ComplexNumber::m_image = ComplexNumber::m_image * numberTwo.m_real + numberTwo.m_image * ComplexNumber::m_real
		/ pow(numberTwo.m_real, 2) + pow(numberTwo.m_image, 2);
	return(0);
}
