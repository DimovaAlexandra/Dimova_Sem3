#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "KS.h"
#include "Truba.h"


using namespace std;
template <typename T>
T getint(string text, T border1, T border2)
{
	T value;
	while (1)
	{
		cout << text << endl;
		cin >> value;
		if (cin.fail() || cin.peek() != '\n' || value < border1 || value >border2)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введённые данные не корректны. Попробуй ещё раз.\n";;
		}
		else
		{
			return value;
		}
	}
}

template <typename T>
using Filtert = bool(*)(Truba& t, T parametr);
template <typename T>
vector<int> SearchTrubaByFilter(map<int, Truba>& Truboprovod, Filtert<T> f, T parametr)
{
	vector <int> result;
	for (auto& t : Truboprovod)
	{
		if (f(t.second, parametr))
		{
			result.push_back(t.second.getid());
		}
	}
	return result;

}

template <typename T>
using Filterks = bool(*)(KS& t, T parametr);
template <typename T>
vector <int> SearchKSByFilter(map<int, KS>& Zavod, Filterks<T> f, T parametr)
{
	vector <int> result;
	int i = 0;
	for (auto& ks : Zavod)
	{
		if (f(ks.second, parametr))
		{
			result.push_back(ks.second.getid());
		}
	}
	return result;

}

class ut
{
};

