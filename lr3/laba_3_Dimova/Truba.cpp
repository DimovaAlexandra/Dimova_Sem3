#include "Truba.h"
#include "ut.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


unsigned int Truba::IDt = 0;

istream& operator >> (istream& in, Truba& t) // Создание трубы
{
	t.id = ++Truba::IDt;
	cout << "Введи название трубы\n";
	cin.get();
	getline(cin, t.name);
	t.dlina = getint("Введи длину трубы (Еденица измерения: м)", 1.0, 10000.0);
	t.diametr = getint("Введи диаметр трубы(Еденица измерения : мм)", 1, 10000);
	t.sostoyanie = false;
	return in;
}

ostream& operator << (ostream& out, const Truba& t) // Вывод информации о трубе
{
	out << "Данные о трубе:\n";
	out << "id рубы: " << t.id << endl;
	out << "id входной компрессорной станции: " << t.inputks << endl;
	out << "id выходной компрессорной станции: " << t.outputks << endl;
	out << "Название трубы: " << t.name << endl;
	out << "Длина трубы: " << t.dlina << " (м)" << endl;
	out << "Диаметр турбы: " << t.diametr << " (мм)" << endl;
	out << "Состояние трубы: " << (t.sostoyanie ? "В ремонте\n" : "Не в ремонте\n");
	return out;
}

void Truba::editTruba() // Отправить трубу в ремонт
{
	sostoyanie = !sostoyanie;
}

void Truba::savefileTruba(std::ofstream& fout) // Сохранение информации о трубе
{
	fout << id << endl;
	fout << inputks << endl;
	fout << outputks << endl;
	fout << name << endl;
	fout << dlina << endl;
	fout << diametr << endl;
	fout << sostoyanie << endl;
}
void Truba::inputfileTruba(std::ifstream& fin) // Считывание информации о трубе
{
	fin >> id;
	fin >> inputks;
	fin >> outputks;
	fin >> name;
	fin >> dlina;
	fin >> diametr;
	fin >> sostoyanie;

}

std::string Truba::getname() // Возвращение названия
{
	return name;
}

bool Truba::getsostoyanie() // Возврщение состояния
{
	return sostoyanie;
}

unsigned int Truba::getid() // Возвращение id
{
	return id;
}
void Truba::setinputks(unsigned int value)
{
	inputks = value;
}

void Truba::setoutputks(unsigned int value)
{
	outputks = value;
}

unsigned int Truba::getinputks()
{
	return inputks;
}

unsigned int Truba::getoutputks()
{
	return outputks;
}
