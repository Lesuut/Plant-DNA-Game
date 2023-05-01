#include "Competition.h"

string generateRandomDnaCompetition() {
    const string bases = "ATCG";
    string dna;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, bases.size() - 1);

    for (int i = 0; i < 36; i++) {
        dna += bases[dis(gen)];
    }

    return dna;
}

string getRandomName()
{
    string names[] = { "Alice", "Bob", "Charlie", "David", "Eva", "Frank",
                   "Grace", "Harry", "Ivan", "Jack", "Kate", "Leo",
                   "Maggie", "Nancy", "Oscar", "Peter", "Quincy", "Rose",
                   "Sam", "Tom", "Ursula", "Violet", "Wendy", "Xavier",
                   "Yolanda", "Zack", "Amber", "Ben", "Catherine", "Danny",
                   "Emily", "Fiona", "George", "Holly", "Isaac", "Jasmine",
                   "Kevin", "Lila", "Molly", "Nate", "Oliver", "Pamela",
                   "Queenie", "Ryan", "Sophia", "Tina", "Victor", "Winnie",
                   "Xander", "Yara", "Zoe", "Anna", "Michael", "Samantha" };

    static const int num_names = sizeof(names) / sizeof(names[0]);
    static bool initialized = false;
    static vector<int> indices;

    if (!initialized)
    {
        for (int i = 0; i < num_names; ++i)
            indices.push_back(i);
        initialized = true;
    }

    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % indices.size();
    int nameIndex = indices[randomIndex];
    indices.erase(indices.begin() + randomIndex);

    return names[nameIndex];
}


bool Competition::Play(Dna plant, const int countOpponents)
{
    Debug debug;
    Laboratory laboratory;

    vector<Dna> dnaList(countOpponents);

    for (int i = 0; i < countOpponents; i++)
    {
        dnaList[i] = Dna(getRandomName(), generateRandomDnaCompetition());
    }

    dnaList.push_back(plant);

    auto compareDna = [&laboratory](const Dna& dna1, const Dna& dna2) {
        return laboratory.GetValuePlant(dna1.dna) > laboratory.GetValuePlant(dna2.dna);
    };

    std::sort(dnaList.begin(), dnaList.end(), compareDna);

    for (int i = 0; i < dnaList.size(); i++)
    {
        debug.Log(dnaList[i].name + ":");
        debug.Log(dnaList[i].GetColorDna());
        debug.Log(laboratory.TraceFlower(dnaList[i].dna));
        debug.Log("____________________________________________________________________________________________________________________\n");
    }

    for (int i = 0; i < dnaList.size(); i++)
    {
        if (dnaList[i].name == plant.name)
        {
            debug.Log(debug.InsertYellow(to_string(i + 1) + ". " + dnaList[i].name + " - value: " + to_string(laboratory.GetValuePlant(dnaList[i].dna))));
        }
        else
        {
            debug.Log(to_string(i + 1) + ". " + dnaList[i].name + " - value: " + to_string(laboratory.GetValuePlant(dnaList[i].dna)));
        }
    }

    if (dnaList[0].name == plant.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}