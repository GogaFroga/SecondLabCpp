#pragma once
#include<string>

class ComplexNumber
{
	public:
		void set_image(float);			// set image

		void set_real(float);			// set real

		float get_image();				// get image

		float get_real();				// get real

		float get_abs();				// abs of complex number

		float get_arg();				// arg of complex number

		float get_conjugate();			// conjugate of complex number

		//  квадратный корень

		float get_sum(class ComplexNumber);				// sum of two complex numbers

		float get_dif(class ComplexNumber);				// diffetence between two complex numbers

		float get_multi(class ComplexNumber);				// multiply one complex number on another

		double get_div(class ComplexNumber);				// divide one complex number on another

	private:
		float m_image = 0;
		float m_real = 0;
};
