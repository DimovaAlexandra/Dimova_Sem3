#include "gts.h"
#include<set>
#include<map>
#include<vector>


void gts::editgts(map<int, Truba>& Truboprovod)
{
	while (true)
	{
		cout << "1 - Соединить компрессорные станции\n";
		cout << "0 - Выход\n";
		int i = getint("Введи номер действия", 0, 1);
		switch (i)
		{
		case 1:
		{
			unsigned int ks = getint("Введи номер первой копрессорной станции", 0u, KS::IDks);
			idks.insert(ks);
			unsigned int t;
			while (true)
			{
				t = getint("Введи номер трубы, которая будет соединять компрессорные станции", 0u, Truba::IDt);
				if (Truboprovod[t].getinputks() == 0 && Truboprovod[t].getoutputks() == 0)
					break;
				else
					cout << "Данная труба уже задействована\n";
			}
			idt.insert(t);
			Truboprovod[t].setinputks(ks);
			unsigned int ks1;
			while (true)
			{
				ks1 = getint("Введи номер второй копрессорной станции", 0u, KS::IDks);
				if (ks1 != ks)
					break;
				else
					cout << "Одна копмпрессорная станция не может быть и входом, и выходом";
			}
			idks.insert(ks1);
			Truboprovod[t].setoutputks(ks1);
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Данные введены не корректно. Попробуй ещё раз.\n";
		}
		}
	}
}

void gts::savefilegts(std::ofstream& fout)
{
	if (idks.size() > 0)
	{
		for (auto& n : idks)
		{
			fout << n << endl;
		}
	}
	if (idks.size() > 0)
	{
		for (auto& n : idt)
		{
			fout << n << endl;
		}
	}
}

int gts::inputfilegts(std::ifstream& fin)
{
	int n;
	fin >> n;
	return n;
}

vector<vector<int>> gts::creatematrix(int n)
{
	matrix.resize(n);
	for (int i = 0; i < n; i++)
	{
		matrix[i].resize(n);
	}
	return matrix;
}

void gts::deletematrix(int n)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i].clear();
	}
	matrix.clear();
}

void gts::editmatrix(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if (first > -1 && second > -1)
			matrix[first][second] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

}

void gts::editmatrixformaxpotok(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if (first > -1 && second > -1 && infotruba.second.getsostoyanie() == false)
			matrix[first][second] = infotruba.second.getproizv();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


void gts::editmatrixforminpyt(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sortedidks;
	for (auto& v : idks)
	{
		sortedidks.push_back(v);
	}
	int n = idks.size();
	for (auto& infotruba : Truboprovod)
	{
		int first = -1;
		int second = -1;
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getinputks() == sortedidks[i])
				first = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (infotruba.second.getoutputks() == sortedidks[i])
				second = i;
		}
		if (first > -1 && second > -1 && infotruba.second.getsostoyanie() == false)
			matrix[first][second] = infotruba.second.getdlina();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


vector<unsigned int> gts::tgtssort(map<int, Truba>& Truboprovod)
{
	vector<unsigned int> sorted;
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	int n = idks.size();
	matrix = creatematrix(n);
	editmatrix(Truboprovod);
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += matrix[i][j];
			}
			if (sum == 0)
			{
				sorted.push_back(vks[i]);
				for (int j = 0; j < n; j++)
				{
					matrix[j][i] = 0;
				}
				matrix[i][i] = 1;
			}
		}
		/* }
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j];
			}
			cout << endl;*/
	}

	deletematrix(n);
	reverse(sorted.begin(), sorted.end());
	return sorted;
}

void gts::deleteidks(int value)
{
	idks.erase(idks.find(value));
}

int gts::findindex(vector<unsigned int> v, int value)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value)
			return i;
	}
}

float gts::countpotok(map<int, Truba>& Truboprovod, map<int, KS> Zavod, int istok, int stok)
{
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	float F = 0;
	while (true)
	{
		vector<int> queue;
		queue.push_back(istok);
		int count = 0;
		int iterator = findindex(vks, istok);
		Zavod[istok].pometka = INFINITY;
		while (Zavod[stok].pometka == 0)
		{
			for (int i = 0; i < matrix.size(); i++)
			{
				if (matrix[iterator][i] != 0)
				{
					if (Zavod[queue[0]].pometka >= matrix[iterator][i])
					{
						Zavod[vks[i]].pometka = matrix[iterator][i];
						Zavod[vks[i]].pred = vks[iterator];
						queue.push_back(vks[i]);
					}
					else
					{
						Zavod[vks[i]].pometka = Zavod[queue[0]].pometka;
						Zavod[vks[i]].pred = vks[iterator];
						queue.push_back(vks[i]);
					}
				}
			}
			queue.erase(queue.begin());
			if (queue.size() == 0)
				return F;
			iterator = findindex(vks, queue[0]);
			count++;
		}
		int s = Zavod[stok].pometka;
		int iter = stok;
		int index1 = findindex(vks, Zavod[stok].pred);
		int index2 = findindex(vks, stok);
		for (int i = 0; i < count; i++)
		{
			matrix[index1][index2] -= s;
			if (matrix[index1][index2] == s)
				matrix[index1][index2] = 0;
			int pr = index1;
			index2 = index1;
			index1 = findindex(vks, Zavod[vks[pr]].pred);
			iter = Zavod[iter].pred;
		}
		for (auto& i : idks)
		{
			Zavod[i].pometka = 0;
		}
		F += s;
	}
}

float gts::maxpotok(map<int, Truba>& Truboprovod, map<int, KS>& Zavod)
{
	int istok;
	int stok;
	while (true)
	{
		istok = getint("Введи id первой компрессорной станции", 1u, KS::IDks);
		stok = getint("Введи id второй компрессорной станции", 1u, KS::IDks);
		bool f1 = false;
		bool f2 = false;
		for (auto& i : idks)
		{
			if (i == istok)
			{
				Zavod[i].pometka = INFINITY;
				f1 = true;
			}
			if (i == stok)
			{
				Zavod[i].pometka = 0;
				f2 = true;
			}
		}
		if (istok == stok || f1 == false || f2 == false)
		{
			cout << "Данные введены некорректно. Попробуй ещё раз\n";
		}
		else
			break;
	}
	size_t n = idks.size();
	matrix = creatematrix(n);
	editmatrixformaxpotok(Truboprovod);
	float F = countpotok(Truboprovod, Zavod, istok, stok);
	deletematrix(n);
	return F;
}

float gts::countpyt(map<int, Truba>& Truboprovod, map<int, KS>& Zavod, int istok, int stok)
{
	vector<unsigned int> vks;
	for (auto& v : idks)
	{
		vks.push_back(v);
	}
	float F = 0;
	vector< unsigned int> queue;
	queue.push_back(istok);
	int iterator = findindex(vks, istok);
	while (true)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[iterator][i] != 0)
			{
				if (Zavod[vks[i]].pometka >= (matrix[iterator][i] + Zavod[queue[0]].pometka))
				{
					Zavod[vks[i]].pometka = matrix[iterator][i] + Zavod[queue[0]].pometka;
					bool f = false;
					for (auto& k : queue)
					{
						if (k == vks[i])
							f = true;
					}
					if (f == false)
						queue.push_back(vks[i]);
				}
			}
		}
		queue.erase(queue.begin());
		if (queue.size() == 0)
			return Zavod[stok].pometka;
		float min = INFINITY;
		int id = 0;
		for (auto& i : queue)
		{
			if (min > Zavod[i].pometka)
			{
				min = Zavod[i].pometka;
				id = findindex(queue, i);
			}
		}
		swap(queue[0], queue[id]);
		iterator = findindex(vks, queue[0]);
	}
}

float gts::minpyt(map<int, Truba>& Truboprovod, map<int, KS>& Zavod)
{
	int istok;
	int stok;
	while (true)
	{
		istok = getint("Введи id первой компрессорной станции", 1u, KS::IDks);
		stok = getint("Введи id второй компрессорной станции", 1u, KS::IDks);
		bool f1 = false;
		bool f2 = false;
		for (auto& i : idks)
		{
			Zavod[i].pometka = INFINITY;
			if (i == istok)
			{
				Zavod[i].pometka = 0;
				f1 = true;
			}
			if (i == stok)
			{
				Zavod[i].pometka = INFINITY;
				f2 = true;
			}
		}
		if (istok == stok || f1 == false || f2 == false)
		{
			cout << "Данные введены некорректно. Попробуй ещё раз\n";
		}
		else
			break;
	}
	size_t n = idks.size();
	matrix = creatematrix(n);
	editmatrixforminpyt(Truboprovod);
	float S = countpyt(Truboprovod, Zavod, istok, stok);
	deletematrix(n);
	return S;
}


set<int> gts::getidks()
{
	return idks;
}

set<int> gts::getidt()
{
	return idt;
}

void gts::setidks(int value)
{
	idks.insert(value);
}

void gts::setidt(int value)
{
	idt.insert(value);
}

