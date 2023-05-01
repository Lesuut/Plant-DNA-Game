#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Debug.h"
#include "Dna.h"
#include "Data.h"

class Data; // forward declaration

class Laboratory
{
public:
    string TraceFlower(string dna);
    int GetPrise(const string& dna);
    float GetValuePlant(string dna);
    void Crossbreeding(string name, string parentName, string additionalName, Data data);
    string ColorDNAStrand(string dna, string indexStr);
    void GeneticModification(string name, string indexStr, Data data);
    string GetFullInformation(string dna);
};