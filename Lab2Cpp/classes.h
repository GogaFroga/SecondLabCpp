#pragma once

class Complex
{
	public:
		void set_image(float); // устанавливаем значение image

		void set_real(float);  // устанавливаем значение b

		void get_image();	   // получить значение image

		void get_real();	   // получить значение real

		float get_abs();		// модуль комплексного числа

	private:
		float m_image;
		float m_real;
};



//class Students
//{
//public:
//	// Установка имени студента
//	void set_name(std::string);
//	// Получение имени студента
//	std::string get_name();
//	// Установка фамилии студента
//	void set_last_name(std::string);
//	// Получение фамилии студента
//	std::string get_last_name();
//	// Установка промежуточных оценок
//	void set_scores(int[]);
//	// Установка среднего балла
//	void set_average_ball(float);
//	// Получение среднего балла
//	float get_average_ball();


//private:
//	// Промежуточные оценки
//	int scores[5];
//	// Средний балл
//	float average_ball;
//	// Имя
//	std::string name;
//	// Фамилия
//	std::string last_name;
//};
