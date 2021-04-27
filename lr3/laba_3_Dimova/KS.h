#pragma once
#include <string>
#include <vector>

class KS
{
	unsigned int id; // Идентификатор
	std::string name; // Название
	int N; // Количество цехов
	int Ninwork; // Количсевто цехов в работе
	int effect; // Эффективность

public:

	static unsigned int IDks;
	friend std::istream& operator >> (std::istream& in, KS& ks); // Создание компрессорной станции
	friend std::ostream& operator << (std::ostream& out, const KS& ks);  // Вывод информации о компрессорной станции
	void editKS(); // Изменение цехов в работе
	void savefileKS(std::ofstream& fout); // Сохранение информации о компрессорной станции
	void inputfileKS(std::ifstream& fin); // Считывание информации о компрессорной станции
	std::string getname(); // Возвращение названия
	int getN(); // Возвращение количества цехов
	int getNinwork(); // Возвращение количества цехов в работе
	unsigned int getid(); // Возвращение id
};




