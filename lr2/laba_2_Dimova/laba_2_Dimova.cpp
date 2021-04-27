#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "KS.h"
#include "Truba.h"
#include "ut.h"

using namespace std;

Truba& selectTruba(vector<Truba>& Truboprovod) // Выбор трубы
{
	unsigned int index = getint("Введи номер трубы", (size_t)1u, Truboprovod.size());
	return Truboprovod[index - 1];
}

void deleteTruba(vector<Truba>& Truboprovod) // Удаление трубы
{
	unsigned int index = getint("Введи номер трубы", (size_t)1u, Truboprovod.size());
	Truboprovod.erase(Truboprovod.begin() + index - 1);
}

bool SearchTrubaByName(const Truba& t, std::string parametr) // Поиск по имени
{
	return t.name == parametr;
}

bool SearchTrubaBySostoyanie(const Truba& t, bool parametr) // Поиск по состоянию
{
	return t.sostoyanie == parametr;
}

KS& selectKS(vector<KS>& Zavod) // Выбор компрессорной станции
{
	unsigned int index = getint("Введи номер компрессорной станции", (size_t)1u, Zavod.size());
	return Zavod[index - 1];
}

void deleteKS(vector<KS>& Zavod) // Удаление компрессорной станции
{
	unsigned int index = getint("Введи номер трубы", (size_t)1u, Zavod.size());
	Zavod.erase(Zavod.begin() + index - 1);
}

bool SearchKSByName(const KS& ks, std::string parametr) // Поиск по имени
{
	return ks.name == parametr;
}

bool SearchKSByNnowork(const KS& ks, double parametr) // не работающих
{
	return ((1.0 - ((double)ks.Ninwork / ks.N)) >= parametr / 100.0);
}

void selectFilterTruba(const vector<Truba>& Truboprovod, int i)
{
	switch (i)
	{
	case 1:
	{
		cout << "Введи название трубы\n";
		string name;
		cin.get();
		getline(cin, name);
		auto res = SearchTrubaByFilter(Truboprovod, SearchTrubaByName, name);
		if (res.size() == 0)
		{
			cout << "Нет труб с таким названием\n";
		}
		for (auto& i : res)
		{
			cout << Truboprovod[i];
		}
		break;

	}
	case 2:
	{
		bool f = false;
		cout << "Поиск труб находящихся в ремонте\n";
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaBySostoyanie, false))
		{
			cout << Truboprovod[i];
			f = true;
		}
		if (!f)
		{
			cout << "Нет труб в ремонте\n";
		}
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуй ещё раз.\n";
	}
	}
}

void selectFilterKS(const vector<KS>& Zavod, int i)
{
	switch (i)
	{
	case 1:
	{
		bool f = false;
		cout << "Введи название компрессорной станции\n";
		string name;
		cin.get();
		getline(cin, name);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByName, name))
		{
			cout << Zavod[i];
			f = true;
		}
		if (!f)
		{
			cout << "Нет компрессорных станций с таким названием\n";
		}
		break;

	}
	case 2:
	{
		bool f = false;
		double procent = getint("Введит процент незадействованных цехов", 1, 100);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByNnowork, procent))

		{
			cout << Zavod[i];
			f = true;
		}
		if (!f)
		{
			cout << "Нет компрессорных станций с таким процентом\n";
		}
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуй ещё раз.\n";
	}
	}
}


void changeTrubaSostoyanie(vector<Truba>& Truboprovod, int i)
{
	switch (i)
	{
	case 1:
	{
		for (auto& infotruba : Truboprovod)
		{
			if (infotruba.sostoyanie == true)
			{
				infotruba.editTruba();
			}
		}

		break;
	}
	case 2:
	{
		int coutt = getint("Введи количество труб", (size_t)1, Truboprovod.size());
		while (coutt--)
		{
			int n = getint("Введи номер трубы", (size_t)1, Truboprovod.size());
			if (Truboprovod[n].sostoyanie == true)
			{
				Truboprovod[n].editTruba();
			}
		}
		break;
	}
	case 3:
	{
		for (auto& infotruba : Truboprovod)
		{
			if (infotruba.sostoyanie == false)
			{
				infotruba.editTruba();
			}
		}
		break;
	}
	case 4:
	{
		int countt = getint("Введи количество труб", (size_t)1, Truboprovod.size());
		while (countt--)
		{
			int n = getint("Введи номер трубы", (size_t)1, Truboprovod.size());
			if (Truboprovod[n].sostoyanie == false)
			{
				Truboprovod[n].editTruba();
			}
		}
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуй ещё раз.\n";
	}
	}
}


void printmenu()
{
	cout << "1-Добавить трубу\n";
	cout << "2-Добавить компрессорную станцию\n";
	cout << "3-Вывести данные на экран\n";
	cout << "4-Редактировать состояние трубы\n";
	cout << "5-Редактировать колличество цехов в работе компрессорной станции\n";
	cout << "6-Сохранить данные файл\n";
	cout << "7-Считать данные из файла\n";
	cout << "8-Найти трубу\n";
	cout << "9-Найти компрессорную станцию\n";
	cout << "10-Удалить трубу\n";
	cout << "11-Удалить компрессорную станцию\n";
	cout << "0-Выход\n";
}


int main()
{
	setlocale(LC_ALL, "Russian");
	vector <Truba> Truboprovod;
	vector <KS> Zavod;
	while (1)
	{
		printmenu();
		int i;
		i = getint("Введи номер действия", 0, 10000);
		switch (i)
		{
		case 1:
		{
			Truba t;
			cin >> t;
			Truboprovod.push_back(t);
			break;
		}
		case 2:
		{
			KS ks;
			cin >> ks;
			Zavod.push_back(ks);
			break;
		}
		case 3:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				if (Truboprovod.size() > 0)
				{
					for (auto& infotruba : Truboprovod)
					{
						cout << infotruba;
					}
				}
				else
				{
					cout << "Труба не создана.\n";
				}
				if (Zavod.size() > 0)
				{
					for (auto& infoKS : Zavod)
					{
						cout << infoKS;
					}
				}
				else
				{
					cout << "Компрессорная станция не создана.\n";
				}
				break;

			}
			else
			{
				cout << "Труба или компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 4:
		{
			if (Truboprovod.size() > 0)
			{
				cout << "Варианты редактирования:\n";
				cout << "1-Отправить все трубы в ремонт\n";
				cout << "2-Отправить конкретные трубы в ремонт\n";
				cout << "3-Починить все трубы\n";
				cout << "4-Починить конкретные трубы\n";
				int i = getint("Введи вариант редактирования", 1, 4);
				changeTrubaSostoyanie(Truboprovod, i);
				break;
			}
			else
			{
				cout << "Труба не создана. Попробуйте ещё раз.\n";
				break;
			}
		}
		case 5:
		{
			if (Zavod.size() > 0)
			{
				selectKS(Zavod).editKS();
				break;
			}
			else
			{
				cout << "Компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 6:
		{
			if (Truboprovod.size() > 0 || Zavod.size() > 0)
			{
				ofstream fout;
				fout.open("info.txt", ios::out);
				if (fout.is_open())
				{
					fout << Truboprovod.size() << endl;
					fout << Zavod.size() << endl;
					if (Truboprovod.size() > 0)
					{
						for (auto& infotruba : Truboprovod)
						{
							infotruba.savefileTruba(fout);
						}
					}
					if (Zavod.size() > 0)
					{
						for (auto& infoKS : Zavod)
						{
							infoKS.savefileKS(fout);
						}
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Труба или компрессорная станция не создана. Попробуй ещё раз.\n";
				break;
			}
		}
		case 7:
		{
			ifstream fin;
			fin.open("info.txt", ios::in);
			if (fin.is_open())
			{
				int countt;
				int countks;
				fin >> countt;
				fin >> countks;
				Truba infotruba;
				KS infoKS;
				if (countt > 0)
				{
					while (countt--)
					{
						infotruba.inputfileTruba(fin);
						Truboprovod.push_back(infotruba);
					}
				}
				if (countks > 0)
				{
					while (countks--)
					{
						infoKS.inputfileKS(fin);
						Zavod.push_back(infoKS);
					}
				}
				fin.close();
			}
			break;
		}
		case 8:
		{
			cout << "Фильтры:\n";
			cout << "1-По имени\n";
			cout << "2-По состоянию в ремонте\n";
			i = getint("Введи номер фильтра", 1, 2);
			selectFilterTruba(Truboprovod, i);
			break;
		}
		case 9:
		{
			cout << "Фильтры:\n";
			cout << "1-По имени\n";
			cout << "2-По проценту незадействованых цехов\n";
			i = getint("Введи номер фильтра", 1, 2);
			selectFilterKS(Zavod, i);
			break;
		}
		case 10:
		{
			deleteTruba(Truboprovod);
			break;
		}
		case 11:
		{
			deleteKS(Zavod);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуй ещё раз.";
		}
		}
	}
}