#include "Data.h"

using namespace std;

string pathMoneySave = "Saves/MoneySave.txt";
string pathPlantsSave = "Saves/PlantsSave.txt";
Debug debug;
Laboratory laboratory;

string LoadLine(string path) {

	ifstream fin;
	fin.open(pathMoneySave);

	if (!fin.is_open())
	{
		debug.LogError(pathMoneySave + " file is not open");
		return "";
	}
	else
	{
		string str;
		getline(fin, str);
		fin.close();
		return str;
	}
}

void SaveLine(string data, string path) {
	ofstream fout;
	fout.open(pathMoneySave);

	if (!fout.is_open())
	{
		debug.LogError(pathMoneySave + " file is not open");
	}
	else
	{
		fout << data;
	}
}

list<Dna> LoadDnaList(string path)
{
	ifstream fin(path);

	if (!fin.is_open())
	{
		debug.LogError(path + " file is not open");
		return {};
	}

	list<Dna> dnaList;

	string line;
	string name, dna;

	while (std::getline(fin, line))
	{
		istringstream iss(line);
		if (!(iss >> name >> dna)) { break; }

		dnaList.emplace_back(name, dna);
	}

	fin.close();

	return dnaList;
}

void Data::SaveDnaList(const string& path)
{
	CheckDuplicateNames();

	ofstream fout(path);
	if (!fout.is_open())
	{
		debug.LogError(path + " file is not open");
		return;
	}

	for (const auto& dna : dnaList)
	{
		fout << dna.name << " " << dna.dna << endl;
	}

	fout.close();
}

void Data::LoadData()
{			
	Money = std::stoi(LoadLine(pathMoneySave));
	dnaList = LoadDnaList(pathPlantsSave);
}

int Data::GetMoney()
{
	return Money;
}
void Data::AddMoney(int salary)
{
	Money += salary;
	SaveLine(to_string(Money), pathMoneySave);
}
bool Data::Buy(int cost)
{
	if (Money >= cost)
	{
		Money -= cost;
		SaveLine(to_string(Money), pathMoneySave);
		return true;
	}
	else
	{
		return false;
	}
}

int Data::GetDnaListSize()
{
	return dnaList.size();
}

string Data::GetSynopsisNameByIndex(int index)
{
	if (index < 0 || index >= dnaList.size()) {
		debug.LogError("Invalid index");
		return "";
	}

	auto it = dnaList.begin();
	std::advance(it, index);

	return it->name;
}
string Data::GetSynopsisDnaByIndex(int index)
{
	if (index < 0 || index >= dnaList.size()) {
		debug.LogError("Invalid index");
		return "";
	}

	auto it = dnaList.begin();
	std::advance(it, index);

	return it->dna;
}

Dna Data::FindDnaByIndex(int index)
{
	if (index < 0 || index >= dnaList.size()) {
		debug.LogError("Invalid index");
		return Dna(); 
	}

	auto it = dnaList.begin();
	std::advance(it, index);

	return *it;
}

Dna Data::FindDnaByName(const std::string& name) const {
	for (const auto& dna : dnaList) {
		if (dna.name == name) {
			return dna;
		}
	}
	throw std::invalid_argument("DNA with name " + name + " not found.");
}

void Data::AddDna(const Dna& dna)
{
	dnaList.push_back(dna);
	SaveDnaList(pathPlantsSave);
}

void Data::SellDna(const Dna& dna)
{
	auto it = std::find(dnaList.begin(), dnaList.end(), dna);
	if (it != dnaList.end())
	{
		dnaList.erase(it);
		AddMoney(laboratory.GetPrise(dna.dna));
		debug.Log(debug.InsertMagenta(dna.name) + " - was sold for: " + debug.InsertGreen(to_string(laboratory.GetPrise(dna.dna)) + "$"));
		SaveDnaList(pathPlantsSave);
	}
	else
	{
		std::cout << "DNA not found." << std::endl;
	}
}

void Data::DellDna(const Dna& dna)
{
	auto it = std::find(dnaList.begin(), dnaList.end(), dna);
	if (it != dnaList.end())
	{
		dnaList.erase(it);
		SaveDnaList(pathPlantsSave);
	}
	else
	{
		std::cout << "DNA not found." << std::endl;
	}
}


void Data::CheckDuplicateNames()
{
	list<string> nameList;
	for (auto& dna : dnaList)
	{
		nameList.push_back(dna.name);
	}
	
	srand(time(nullptr));

	for (auto it = nameList.begin(); it != nameList.end(); ++it) {
		int count = 0;
		auto tempIt = it;
		++tempIt;

		while (tempIt != nameList.end()) {
			if (*tempIt == *it) {
				int randomNumber = rand() % 10000;
				*tempIt += to_string(randomNumber);
				++count;
			}
			++tempIt;
		}

		if (count > 0) {
			int randomNumber = rand() % 10000;
			*it += to_string(randomNumber);
		}
	}

	auto nameIt = nameList.begin();
	for (auto& dna : dnaList)
	{
		dna.name = *nameIt++;
	}
}

string Data::GetStringInventoryDna() {
	string sum;
	for (auto& dna : dnaList)
	{
		sum += dna.GetColorDna() + " cost: " + to_string(laboratory.GetPrise(dna.dna)) + "$" + "\n";
	}
	return sum;
}

string Data::GetStringGarden() {
	string sum;
	for (auto& dna : dnaList)
	{
		sum += dna.GetColorDna() + " :\n\n" + laboratory.TraceFlower(dna.dna) + "\n________________________________\n\n";
	}
	return sum;
}
