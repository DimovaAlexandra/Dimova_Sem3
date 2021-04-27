#include "KS.h"
#include <iostream>
#include <fstream>
#include "ut.h"
#include <string>
#include <vector>

unsigned int KS::IDks = 0;

istream& operator >> (istream& in, KS& ks) // Создание компрессорной станции
{
	ks.id = ++KS::IDks;
	cout << "Введи название компрессорной станции\n";
	cin.get();
	getline(cin, ks.name);
	ks.N = getint("Введи количество цехов", 1, 10000);
	ks.Ninwork = getint("Введи количество цехов в работе", 0, ks.N);
	ks.effect = getint("Введи эффективность компрессорной станцции (Эффективность измеряется по 10-ти бальной шкале)", 0, 10000);
	return in;
}

ostream& operator << (ostream& out, const KS& ks) // Вывод информации о компрессорной станции
{
	out << "Данные о компрессорной станции:\n";
	out << "id компрессорной станции: " << ks.id << endl;
	out << "Название компрессорной станции: " << ks.name << endl;
	out << "Количество цехов на компрессорной станции: " << ks.N << endl;
	out << "Количество цехов в работе: " << ks.Ninwork << endl;
	out << "Эффективность компрессорной станции: " << ks.effect << endl;
	return out;
}

void KS::editKS() // Изменение цехов в работе
{
	Ninwork = getint("Введи количество цехов в работе", 0, N);
}

void KS::savefileKS(std::ofstream& fout) // Сохранение информации о компрессорной станции
{
	fout << id << endl;
	fout << name << endl;
	fout << N << endl;
	fout << Ninwork << endl;
	fout << effect << endl;
}

void KS::inputfileKS(std::ifstream& fin) // Считывание информации о компрессорной станции
{
	fin >> id;
	fin >> name;
	fin >> N;
	fin >> Ninwork;
	fin >> effect;
}

std::string KS::getname()
{
	return name;
}

int KS::getN()
{
	return N;
}

int KS::getNinwork()
{
	return Ninwork;
}

unsigned int KS::getid()
{
	return id;
}
