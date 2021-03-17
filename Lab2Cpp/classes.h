#pragma once

class ComplexNumber
{
	public:
		void set_image(float);			// set image

		void set_real(float);			// set real

		void get_image();				// get image

		void get_real();				// get real

		void set_second_real(float);	// set 2nd image

		void set_second_image(float);	// set 2nd real

		void get_second_image();		// get 2nd image

		void get_second_real();			// get 2nd real

		float get_abs();				// abs of complex number

		float get_sum();				// sum of two complex numbers

		float get_dif();				// diffetence between two complex numbers

		float get_multi();				// multiply one complex number on another

		float get_div();				// divide one complex number on another

	private:
		float m_image;
		float m_real;
		float m_second_image = 0;
		float m_second_real = 0;
};
