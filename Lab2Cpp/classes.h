#pragma once

class Complex
{
	public:
		void set_image(float); // устанавливаем значение image

		void set_real(float);  // устанавливаем значение real

		void get_image();	   // получить значение image

		void get_real();	   // получить значение real

		float get_abs();		// модуль комплексного числа

	private:
		float m_image;
		float m_real;
};

/* class for +, -, *, /
class ComplexOperations
{

}
*/