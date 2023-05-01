#pragma once

#include <iostream>
#include <string>
#include "Debug.h"

class Dna
{
public:
	string name;
	string dna;

	string hight;
	string width;
	string color;
	string form;
	string stamina;
	string growthRate;
	string sustainability;
	string fragrance;

	Dna() = default;
    Dna(string name, string dna);
	string GetColorDna();

	static void convertToCharArray(string inputString, char outputCharArray[]) {
		for (int i = 0; i < inputString.length(); i++) {
			outputCharArray[i] = inputString[i];
		}
		outputCharArray[inputString.length()] = '\0';
	}

	bool operator==(const Dna& other) const
	{
		return name == other.name;
	}
};

