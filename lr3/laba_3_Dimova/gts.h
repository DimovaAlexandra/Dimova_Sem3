#pragma once
#include"ut.h"
#include"Truba.h"
#include"KS.h"
#include <set>
#include <iostream>
#include <fstream>

class gts
{
private:
	int** matrix;
	set<int> idks;
	set<int> idt;
public:
	void editgts(map<int, Truba>& Truboprovod);
	void savefilegts(std::ofstream& fout);
	int inputfilegts(std::ifstream& fin);
	int** creatematrix(int n);
	void deletematrix(int n);
	void editmatrix(map<int, Truba>& Truboprovod);
	vector<unsigned int> tgtssort(map<int, Truba>& Truboprovod);
	void deleteidks(int value);
	set<int> getidks();
	set<int> getidt();
	void setidks(int value);
	void setidt(int value);

};


