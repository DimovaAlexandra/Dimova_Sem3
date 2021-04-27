#pragma once
#include <string>
#include <iostream>

class Truba
{
	unsigned int id; // Идентификатор
	std::string name; // Название
	double dlina; // Длина
	int diametr; // Диаметр
	bool sostoyanie; // Состояние в ремонте или не в ремонте
	unsigned int inputks = 0; // Компрессорная станция, от которой идёт труба
	unsigned int outputks = 0; // Компрессорная станция, к которой идёт труба
	int proizv;

public:

	static unsigned int IDt;
	friend std::istream& operator >> (std::istream& in, Truba& t); // Создание трубы
	friend std::ostream& operator << (std::ostream& out, const Truba& t); // Вывод информации о трубе
	void editTruba(); // Отправить трубу в ремонт
	void savefileTruba(std::ofstream& fout); // Сохранение информации о трубе
	void inputfileTruba(std::ifstream& fin); // Считывание информации о трубе
	std::string getname(); // Возвращение названия
	bool getsostoyanie(); // Возврщение состояния
	unsigned int getid(); // Возвращение id
	void setinputks(unsigned int value); // Присваиваю номер компрессорной станции, от которой идёт труба
	void setoutputks(unsigned int value);// Присваиваю номер компрессорной станции, к которой идёт труба
	unsigned int getinputks(); // Возвращаю номер компрессорной станции, от которой идёт труба
	unsigned int getoutputks(); // Возвращаю номер компрессорной станции, к которой идёт труба
	int getproizv();
	double getdlina();
};


