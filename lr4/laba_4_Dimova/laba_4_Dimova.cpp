#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "KS.h"
#include "Truba.h"
#include "ut.h"
#include "gts.h"

using namespace std;

Truba& selectTruba(map<int, Truba>& Truboprovod) // Выбор трубы
{
	unsigned int index = getint("Введи номер трубы", 1u, Truba::IDt);
	return Truboprovod[index];
}

void deleteTruba(map<int, Truba>& Truboprovod) // Удаление трубы
{
	unsigned int index = getint("Введи номер трубы", 1u, Truba::IDt);
	Truboprovod.erase(index);
}

bool SearchTrubaByName(Truba& t, std::string parametr) // Поиск по имени
{
	return t.getname() == parametr;
}

bool SearchTrubaBySostoyanie(Truba& t, bool parametr) // Поиск по состоянию
{
	return t.getsostoyanie() == parametr;
}

KS& selectKS(map<int, KS>& Zavod) // Выбор компрессорной станции
{
	unsigned int index = getint("Введи номер компрессорной станции", 1u, KS::IDks);
	return Zavod[index];
}

void deleteKS(map<int, KS>& Zavod, gts& gts, map<int, Truba>& Truboprovod) // Удаление компрессорной станции
{
	unsigned int index = getint("Введи номер трубы", 1u, KS::IDks);
	gts.deleteidks(index);
	for (auto& n : Truboprovod)
	{
		if (n.second.getinputks() == index)
			n.second.setinputks(0);
		/* }
		for (auto& n : Truboprovod)
		{ */
		if (n.second.getoutputks() == index)
			n.second.setoutputks(0);
	}
	Zavod.erase(index);
}

bool SearchKSByName(KS& ks, std::string parametr) // Поиск по имени
{
	return ks.getname() == parametr;
}

bool SearchKSByNnowork(KS& ks, double parametr) // не работающих
{
	return ((1.0 - ((double)ks.getNinwork() / ks.getN())) >= parametr / 100.0);
}

set<int> selectFilterTruba(map<int, Truba>& Truboprovod)
{
	set<int> idt;
	cout << "Фильтры:\n";
	cout << "1 - По названию\n";
	cout << "2 - По состоянию в ремонте\n";
	int i = getint("Введи номер фильтра", 1, 2);
	switch (i)
	{
	case 1:
	{
		bool f = false;
		cout << "Введи название трубы\n";
		string name;
		cin.get();
		getline(cin, name);
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaByName, name))
		{
			idt.insert(i);
			f = true;
		}
		return idt;
		break;
	}
	case 2:
	{
		bool f = false;
		cout << "Поиск труб, находящихся в ремонте\n";
		for (auto& i : SearchTrubaByFilter(Truboprovod, SearchTrubaBySostoyanie, true))
		{
			idt.insert(i);
			f = true;
		}
		return idt;
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуй ещё раз.\n";
	}
	}
}

set<int> selectFilterKS(map<int, KS>& Zavod)
{
	set<int> idks;
	cout << "Фильтры:\n";
	cout << "1 - По названию\n";
	cout << "2 - По проценту незадействованых цехов\n";
	int i = getint("Введи номер фильтра", 1, 2);
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
			idks.insert(i);
			f = true;
		}
		return idks;
		break;

	}
	case 2:
	{
		bool f = false;
		double procent = getint("Введи процент незадействованных цехов", 1, 100);
		for (auto& i : SearchKSByFilter(Zavod, SearchKSByNnowork, procent))

		{
			idks.insert(i);
			f = true;
		}
		return idks;
		break;
	}
	default:
	{
		cout << "Данные введены не корректно. Попробуй ещё раз.\n";
	}
	}
}


void changeTrubaSostoyanie(map<int, Truba>& Truboprovod)
{
	cout << "Варианты редактирования:\n";
	cout << "1 - Отправить все трубы в ремонт\n";
	cout << "2 - Отправить конкретные трубы в ремонт\n";
	cout << "3 - Починить все трубы\n";
	cout << "4 - Починить конкретные трубы\n";
	int i = getint("Введи вариант редактирования", 1, 4);
	switch (i)
	{
	case 1:
	{
		for (auto& t : Truboprovod)
		{
			if (Truboprovod[t.second.getid()].getsostoyanie() == false)
			{
				Truboprovod[t.second.getid()].editTruba();
			}
		}

		break;
	}
	case 2:
	{
		while (true)
		{
			unsigned int n = getint("Введи номер трубы или, если хочешь выйти, нажми '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == false)
				{
					Truboprovod[n].editTruba();
				}
				else
					cout << "Труба уже в ремонте";
			}
		}
		break;
	}
	case 3:
	{
		for (auto& t : Truboprovod)
		{
			if (Truboprovod[t.second.getid()].getsostoyanie() == true)
			{
				Truboprovod[t.second.getid()].editTruba();
			}
		}
		break;
	}
	case 4:
	{
		while (true)
		{
			unsigned int n = getint("Введи номер трубы или, или, если хочешь выйти, нажми '0'", 0u, Truba::IDt);
			if (n == 0)
				break;
			else
			{
				if (Truboprovod[n].getsostoyanie() == true)
				{
					Truboprovod[n].editTruba();
				}
				else
					cout << "Труба уже не в ремонте";
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
	cout << "1 - Добавить трубу\n";
	cout << "2 - Добавить компрессорную станцию\n";
	cout << "3 - Вывести данные на экран\n";
	cout << "4 - Редактировать состояние трубы\n";
	cout << "5 - Редактировать колличество цехов в работе компрессорной станции\n";
	cout << "6 - Сохранить данные файл\n";
	cout << "7 - Считать данные из файла\n";
	cout << "8 - Найти трубу\n";
	cout << "9 - Найти компрессорную станцию\n";
	cout << "10 - Удалить трубу\n";
	cout << "11 - Удалить компрессорную станцию\n";
	cout << "12 - Соединение в единую газотранспортную сеть\n";
	cout << "13 - Выполнить топологическую сортировку\n";
	cout << "14 - Найти максимальный поток между компрессорными станциями\n";
	cout << "15 - Найти кратчайший путь между компрессорными станциями\n";
	cout << "0 - Выход\n";
}
int main()
{
	setlocale(LC_ALL, "Russian");
	map <int, Truba> Truboprovod;
	map <int, KS> Zavod;
	gts gts;
	vector<unsigned int> sortedmatrix;
	while (true)
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
			Truboprovod[t.getid()] = t;
			break;
		}
		case 2:
		{
			KS ks;
			cin >> ks;
			Zavod[ks.getid()] = ks;
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
						cout << infotruba.second;
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
						cout << infoKS.second;
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
				changeTrubaSostoyanie(Truboprovod);
				break;
			}
			else
			{
				cout << "Труба не создана. Попробуй ещё раз.\n";
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
					fout << Truba::IDt << endl;
					fout << KS::IDks << endl;
					if (Truboprovod.size() > 0)
					{
						for (auto& infotruba : Truboprovod)
						{
							infotruba.second.savefileTruba(fout);
						}
					}
					if (Zavod.size() > 0)
					{
						for (auto& infoKS : Zavod)
						{
							infoKS.second.savefileKS(fout);
						}
					}
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Труба или компрессорная станция не создана. Попробуй ещё раз.\n";
			}
			if (gts.getidks().size() > 0 || gts.getidt().size() > 0)
			{
				ofstream fout;
				fout.open("gts.txt", ios::out);
				if (fout.is_open())
				{
					fout << gts.getidt().size() << endl;
					fout << gts.getidks().size() << endl;
					gts.savefilegts(fout);
					fout.close();
				}
				break;
			}
			else
			{
				cout << "Газотранспортная сеть не создана\n";
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
				fin >> Truba::IDt;
				fin >> KS::IDks;

				if (countt > 0)
				{
					for (int i = 0; i < countt; i++)
					{
						Truba infotruba;
						infotruba.inputfileTruba(fin);
						Truboprovod[i] = infotruba;
					}
				}
				if (countks > 0)
				{
					for (int i = 0; i < countks; i++)
					{
						KS infoKS;
						infoKS.inputfileKS(fin);
						Zavod[i] = infoKS;
					}
				}
				fin.close();
			}
			ifstream fin2;
			fin2.open("gts.txt", ios::in);
			if (fin2.is_open())
			{
				int countidt;
				int countidks;
				fin2 >> countidt;
				fin2 >> countidks;
				if (countidt > 0)
				{
					for (int i = 0; i < countidt; i++)
					{
						int n = gts.inputfilegts(fin2);
						gts.setidt(n);
					}
				}
				if (countidks > 0)
				{
					for (int i = 0; i < countidks; i++)
					{
						int n = gts.inputfilegts(fin2);
						gts.setidks(n);
					}
				}
				fin2.close();
			}
			break;
		}
		case 8:
		{
			set<int>idt = selectFilterTruba(Truboprovod);
			bool f = true;
			for (auto& i : idt)
			{
				f = false;
				cout << Truboprovod[i];
			}
			if (f)
				cout << "Таких труб нет\n";
			break;
		}
		case 9:
		{
			set<int> idks = selectFilterKS(Zavod);
			bool f = true;
			for (auto& i : idks)
			{
				f = false;
				cout << Zavod[i];
			}
			if (f)
				cout << "Таких компрессорных станций нет\n";
			break;
		}
		case 10:
		{
			deleteTruba(Truboprovod);
			break;
		}
		case 11:
		{
			deleteKS(Zavod, gts, Truboprovod);
			break;
		}
		case 12:
		{
			gts.editgts(Truboprovod);
			break;
		}
		case 13:
		{
			sortedmatrix = gts.tgtssort(Truboprovod);
			if (sortedmatrix.size() > 0)
			{
				int k = 1;
				for (auto& i : sortedmatrix)
				{
					cout << "Вершина №" << k << "--> id=" << i << endl;
					k += 1;
				}
			}
			else
				cout << "В графе присутствует цикл => топологическая сортировка невозможна\n";
			break;
		}
		case 14:
		{
			float max = gts.maxpotok(Truboprovod, Zavod);
			cout << "Максимальный поток между компрессорными станциями равен\n";
			cout << max << endl;
			break;
		}
		case 15:
		{
			float max = gts.minpyt(Truboprovod, Zavod);
			cout << "Минимальный путь между компрессорными станциями равен\n";
			cout << max << endl;
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуй ещё раз.\n";
		}
		}
	}
}