#pragma once
#include<string>

class ComplexNumber
{
	public:
		void set_image(float);			// set image

		void set_real(float);			// set real

		float get_image();				// get image <im>

		float get_real();				// get real <re>

		float get_abs();				// abs of complex number <abs>

		float get_arg();				// arg of complex number <arg>

		float get_conjugate();			// conjugate of complex number <conj>

		float get_root();				// root of complex number <root>

		ComplexNumber get_sum(class ComplexNumber);			// sum of two complex numbers <+>

		ComplexNumber get_dif(class ComplexNumber);			// diffetence between two complex numbers <->

		ComplexNumber get_multi(class ComplexNumber);		// multiply one complex number on another <*>

		ComplexNumber get_div(class ComplexNumber);			// divide one complex number on another </>

	private:
		float m_image = 0;
		float m_real = 0;
};
