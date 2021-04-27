#pragma once
#include <string>
#include <iostream>

class Truba
{
	static unsigned int IDt;
	unsigned int id; // Идентификатор
	double dlina; // Длина
	int diametr; // Диаметр


public:
	/* static Truba createTruba(); // Создание трубы
	friend void printTruba(const Truba& t); // Вывод информации о компрессорной станции
	friend void editTruba(Truba& t); // Изменение цехов в работе */

	std::string name; // Название
	bool sostoyanie; // Состояние в ремонте или нет
	friend std::istream& operator >> (std::istream& in, Truba& t); // Создание труба
	friend std::ostream& operator << (std::ostream& out, const Truba& t); // Вывод информации о труба
	void editTruba(); // Отправить трубу в ремонт
	void savefileTruba(std::ofstream& fout); // Сохранение информации о компрессорной станции
	void inputfileTruba(std::ifstream& fin);

	/* static Truba inputfileTruba(std::ifstream& fin); // Считывание информации о компрессорной станции
	friend void selectTruba(vector<Truba>& Truboprovod); // Выбор трубы
	friend void SearchTrubaByName(const Truba& t, std::string parametr); // Поиск по названию
	friend void SearchTrubaBySostoyanie(const Truba& t, double parametr); // Поиск по состоянию
	*/
};


