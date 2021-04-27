#pragma once
#include <string>
#include <iostream>
#include <vector>
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
		if (cin.fail() || value < border1 || value > border2)
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
using Filtert = bool(*)(const Truba& t, T parametr);
template <typename T>
vector <int> SearchTrubaByFilter(const vector<Truba>& Truboprovod, Filtert<T> f, T parametr)
{
	vector <int> result;
	int i = 0;
	for (auto& t : Truboprovod)
	{
		if (f(t, parametr))
		{
			result.push_back(i);
		}
		i++;
	}
	return result;

}

template <typename T>
using Filterks = bool(*)(const KS& t, T parametr);
template <typename T>
vector <int> SearchKSByFilter(const vector<KS>& Zavod, Filterks<T> f, T parametr)
{
	vector <int> result;
	int i = 0;
	for (auto& ks : Zavod)
	{
		if (f(ks, parametr))
		{
			result.push_back(i);
		}
		i++;
	}
	return result;

}

class ut
{
};