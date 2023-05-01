#pragma once

#include <iostream>
#include <string>
#include <random>
#include "Debug.h"
#include "Dna.h"
//#include "Data.h"
#include "Laboratory.h"

#include <cstdlib>  
#include <ctime>    

//class Data; // forward declaration

using namespace std;

class Competition
{
public:
	bool Play(Dna plant, int countOpponents);
};

