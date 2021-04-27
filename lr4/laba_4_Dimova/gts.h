#pragma once
#include"ut.h"
#include"Truba.h"
#include"KS.h"
#include <set>
#include <iostream>
#include <fstream>
#include <vector>

class gts
{
private:
	vector<vector<int>> matrix;
	set<int> idks;
	set<int> idt;
public:
	void editgts(map<int, Truba>& Truboprovod);
	void savefilegts(std::ofstream& fout);
	int inputfilegts(std::ifstream& fin);
	vector<vector<int>> creatematrix(int n);
	void deletematrix(int n);
	void editmatrix(map<int, Truba>& Truboprovod);
	vector<unsigned int> tgtssort(map<int, Truba>& Truboprovod);
	void deleteidks(int value);
	int findindex(vector<unsigned int> v, int value);
	float countpotok(map<int, Truba>& Truboprovod, map<int, KS> Zavod, int istok, int stok);
	float maxpotok(map<int, Truba>& Truboprovod, map<int, KS>& Zavod);
	float countpyt(map<int, Truba>& Truboprovod, map<int, KS>& Zavod, int istok, int stok);
	float minpyt(map<int, Truba>& Truboprovod, map<int, KS>& Zavod);
	void editmatrixformaxpotok(map<int, Truba>& Truboprovod);
	void editmatrixforminpyt(map<int, Truba>& Truboprovod);
	set<int> getidks();
	set<int> getidt();
	void setidks(int value);
	void setidt(int value);

};


