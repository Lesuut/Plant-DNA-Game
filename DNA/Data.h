#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
//#include <random>

#include <cstdlib>
#include <ctime>

#include "Debug.h"
#include "Dna.h"
#include "Laboratory.h"

class Data
{
private:
	int Money = -999;
	list<Dna> dnaList;
public:
	void LoadData();

	int GetMoney();
	void AddMoney(int salary);
	bool Buy(int cost);

	int GetDnaListSize();
	string GetSynopsisNameByIndex(int index);
	string GetSynopsisDnaByIndex(int index);

	Dna FindDnaByIndex(int index);
	Dna FindDnaByName(const std::string& name) const;

	void AddDna(const Dna& dna);
	void SellDna(const Dna& dna);
	void DellDna(const Dna& dna);

	void SaveDnaList(const string& filePath);

	void CheckDuplicateNames();

	string GetStringInventoryDna();

	string GetStringGarden();
};

