#pragma once
#include <string>
#include <vector>

class KS
{
	static unsigned int IDks;
	unsigned int id; // Идентификатор
	int effect; // Эффективность

public:

	std::string name; // Название
	int N; // Количество цехов
	int Ninwork; // Количсевто цехов в работе

	/*static KS createKS(); // Создание компрессорной станции
	friend void printKS(const KS& ks); // Вывод информации о компрессорной станции
	friend void editKS(KS& ks); // Изменение цехов в работе*/

	friend std::istream& operator >> (std::istream& in, KS& ks); // Создание компрессорной станции
	friend std::ostream& operator << (std::ostream& out, const KS& ks); // Вывод информации о компрессорной станции
	void editKS(); // Изменение цехов в работe
	void savefileKS(std::ofstream& fout); // Сохранение информации о компрессорной станции
	void inputfileKS(std::ifstream& fin); // Считывание инфы о компрессорной станции

	/* static KS inputfileKS(std::ifstream& fin); // Считывание информации о компрессорной станции
	friend KS& selectKS(vector<KS>& Zavod); // Выбор компрессорной станции
	friend void deleteKS(vector<KS>& Zavod); // Удаление компрессорной станции
	friend bool SearchKSByName(const KS& ks, std::string parametr); // Поиск по названию
	friend bool SearchKSByNinwork(const KS& ks, double parametr); // поиск не работающих цехов по % */

};


