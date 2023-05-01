#include "Laboratory.h"

float SymbolPrice(char symbol) {
	if (symbol == 'A')
	{
		return 0.99;
	}
	else if (symbol == 'T')
	{
		return 0.66;
	}
	else if (symbol == 'C')
	{
		return 0.33;
	}
	else if (symbol == 'G')
	{
		return 0.01;
	}
}

void setTraitsFromDna(const string& dna, float hight[4], float width[4], float color[8], float form[4])
{
	char* chars = new char[dna.length() + 1];
	Dna::convertToCharArray(dna, chars);

	hight[0] = SymbolPrice(chars[0]);
	hight[1] = SymbolPrice(chars[1]);
	hight[2] = SymbolPrice(chars[2]);
	hight[3] = SymbolPrice(chars[3]);

	width[0] = SymbolPrice(chars[4]);
	width[1] = SymbolPrice(chars[5]);
	width[2] = SymbolPrice(chars[6]);
	width[3] = SymbolPrice(chars[7]);

	color[0] = SymbolPrice(chars[8]);
	color[1] = SymbolPrice(chars[9]);
	color[2] = SymbolPrice(chars[10]);
	color[3] = SymbolPrice(chars[11]);
	color[4] = SymbolPrice(chars[12]);
	color[5] = SymbolPrice(chars[13]);
	color[6] = SymbolPrice(chars[14]);
	color[7] = SymbolPrice(chars[15]);

	form[0] = SymbolPrice(chars[16]);
	form[1] = SymbolPrice(chars[17]);
	form[2] = SymbolPrice(chars[18]);
	form[3] = SymbolPrice(chars[19]);
}

int Laboratory::GetPrise(const string& dna) {
    float maxPrise = 1000.0;
    float sum = 0;
    char* chars = new char[dna.length() + 1];
    Dna::convertToCharArray(dna, chars);
    sum += (SymbolPrice(chars[0]) + SymbolPrice(chars[1]) + SymbolPrice(chars[2]) + SymbolPrice(chars[3]));
    sum += (SymbolPrice(chars[4]) + SymbolPrice(chars[5]) + SymbolPrice(chars[6]) + SymbolPrice(chars[7]));
    sum += (SymbolPrice(chars[8]) + SymbolPrice(chars[9]) + SymbolPrice(chars[10]) + SymbolPrice(chars[11]));
    sum += (SymbolPrice(chars[12]) + SymbolPrice(chars[13]) + SymbolPrice(chars[14]) + SymbolPrice(chars[15]));
    sum += (SymbolPrice(chars[16]) + SymbolPrice(chars[17]) + SymbolPrice(chars[18]) + SymbolPrice(chars[19]));
    sum += (SymbolPrice(chars[20]) + SymbolPrice(chars[21]) + SymbolPrice(chars[22]) + SymbolPrice(chars[23]));
    sum += (SymbolPrice(chars[24]) + SymbolPrice(chars[25]) + SymbolPrice(chars[26]) + SymbolPrice(chars[27]));
    sum += (SymbolPrice(chars[28]) + SymbolPrice(chars[29]) + SymbolPrice(chars[30]) + SymbolPrice(chars[31]));
    sum += (SymbolPrice(chars[32]) + SymbolPrice(chars[33]) + SymbolPrice(chars[34]) + SymbolPrice(chars[35]));
    return round((sum / 36) * maxPrise);
}

float Laboratory::GetValuePlant(string dna) {
    char* chars = new char[dna.length() + 1];
    Dna::convertToCharArray(dna, chars);
    float sum = 0;
    sum += (SymbolPrice(chars[20]) + SymbolPrice(chars[21]) + SymbolPrice(chars[22]) + SymbolPrice(chars[23]));
    sum += (SymbolPrice(chars[24]) + SymbolPrice(chars[25]) + SymbolPrice(chars[26]) + SymbolPrice(chars[27]));
    sum += (SymbolPrice(chars[28]) + SymbolPrice(chars[29]) + SymbolPrice(chars[30]) + SymbolPrice(chars[31]));
    sum += (SymbolPrice(chars[32]) + SymbolPrice(chars[33]) + SymbolPrice(chars[34]) + SymbolPrice(chars[35]));
    return (sum / 16);
}

string SetColor(float value, string str, Debug debug) {
    if (value <= 0.5)
    {
        return debug.InsertGreen(str);
    }
    else if(value > 0.5 && 0.6 > value)
    {
        return debug.InsertRed(str);
    }
    else if (value >= 0.6 && 0.7 > value)
    {
        return debug.InsertYellow(str);
    }
    else if (value >= 0.7 && 0.8 > value)
    {
        return debug.InsertBlue(str);
    }
    else if (value >= 0.8 && 0.9 > value)
    {
        return debug.InsertCyan(str);
    }
    else if (value >= 0.9 && 1 > value)
    {
        return debug.InsertMagenta(str);
    }
}

string Laboratory::TraceFlower(string dna)
{
    char trunkCharacterCollection[] = { '|', '/', '+', '1', 'O', '[', ']', 'T', '!', '#', ')', '(', 'S' };
    char leavesCharacterCollection[] = { '@', '$', '&', '%', 'P', 'Q', 'G', 'U', 'E', '~', 'C', 'Y', '9', '6' };

    float hightArray[4];
    float widthArray[4];
    float colorArray[8];
    float formArray[4];

    setTraitsFromDna(dna, hightArray, widthArray, colorArray, formArray);

    int hight = round(((hightArray[0] + hightArray[1] + hightArray[2] + hightArray[3]) * 9) / 4);
    int width = round(((widthArray[0] + widthArray[1] + widthArray[2] + widthArray[3]) * 7) / 4);

    Debug debug;

    /*debug.Log("hight: " + to_string(hight));
    debug.Log("width: " + to_string(width));
    debug.Log("\n\n");*/

    string plantTop;
    string plantDown;

    for (size_t i = 0; i < hight; i++)
    { 
        for (int q = 0; q < width; q++)
        {
            plantTop += leavesCharacterCollection[static_cast<int>(formArray[2] * 13)];
            plantTop += leavesCharacterCollection[static_cast<int>(formArray[3] * 13)];
        }
        plantTop += '\n';
    }
    for (size_t i = 0; i < hight; i++)
    {
        plantDown += " ";
        for (int q = 0; q < width - 2; q++)
        {
            plantDown += trunkCharacterCollection[static_cast<int>(formArray[0] * 12)];
            plantDown += trunkCharacterCollection[static_cast<int>(formArray[1] * 12)];
        }
        plantDown += '\n';
    }    

    return SetColor(((colorArray[0] + colorArray[1] + colorArray[2] + colorArray[3]) / 4), plantTop, debug) + SetColor(((colorArray[4] + colorArray[5] + colorArray[6] + colorArray[7]) / 4), plantDown, debug);
}

string AddRandomMutation(const string& dna)
{
    std::string mutated_dna = dna;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, dna.size() - 1);
    int index = dist(gen);

    std::uniform_int_distribution<int> base_dist(0, 3);
    char bases[] = { 'A', 'T', 'C', 'G' };
    char new_base = bases[base_dist(gen)];

    mutated_dna[index] = new_base;

    return mutated_dna;
}

void Laboratory::Crossbreeding(string name, string parentName, string additionalName, Data data) {
    Debug debug;

    if (data.Buy(100))
    {
        Dna dnaParent = data.FindDnaByName(parentName);
        Dna dnaAdditional = data.FindDnaByName(additionalName);

        char* charsDnaParent = new char[dnaParent.dna.length() + 1];
        Dna::convertToCharArray(dnaParent.dna, charsDnaParent);

        char* charsDnaAdditional = new char[dnaAdditional.dna.length() + 1];
        Dna::convertToCharArray(dnaAdditional.dna, charsDnaAdditional);

        int length = strlen(charsDnaParent);
        char* result = new char[length + 1];
        for (int i = 0; i < length; i++) {
            if (rand() % 2 == 0) {
                result[i] = charsDnaAdditional[i];
            }
            else {
                result[i] = charsDnaParent[i];
            }
        }
        result[length] = '\0';

        string resultStr(result);
        delete[] charsDnaParent;
        delete[] charsDnaAdditional;

        data.AddDna(Dna(name, AddRandomMutation(resultStr)));

        debug.Log("The crossbreeding was a success!");
        debug.Log(data.FindDnaByName(parentName).GetColorDna() + " - parent");
        debug.Log(data.FindDnaByName(additionalName).GetColorDna() + " - additional");
        debug.Log(data.FindDnaByName(name).GetColorDna() + " - " + name + debug.InsertCyan(" NEW!"));

        data.DellDna(data.FindDnaByName(parentName));

        debug.Log(debug.InsertYellow("\nYou paid:") + debug.InsertGreen("100$\n"));
    }
    else
    {
        debug.Log(debug.InsertRed("Not enough money to buy!"));
    }
}

string Laboratory::ColorDNAStrand(string dna, string indexStr) {
    Debug debug;
    int index = stoi(indexStr);
    if (index >= 0 && index < dna.length()) {
        char c = dna.substr(index, 1)[0];
        dna.replace(index, 1, debug.InsertRed(string(1, c)));
    }
    return dna;
}

string AddMutation(const string& dna, string indexStr) {
    string mutated_dna = dna;
    int index = stoi(indexStr);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 3);
    char bases[] = { 'A', 'T', 'C', 'G' };
    char new_base = bases[dist(gen)];

    mutated_dna[index] = new_base;

    return mutated_dna;
}

void Laboratory::GeneticModification(string name, string indexStr, Data data) {
    Debug debug;
    if (data.Buy(10))
    {
        Dna dna = data.FindDnaByName(name);
        debug.Log("old: " + dna.GetColorDna());
        data.DellDna(data.FindDnaByName(name));
        dna = Dna(name, AddMutation(dna.dna, indexStr));
        data.AddDna(dna);
        debug.Log("new: " + dna.GetColorDna());
        debug.Log(debug.InsertYellow("Genetic modification by random mutation of a selected gene was successful!"));
        debug.Log(debug.InsertYellow("You paid:") + debug.InsertGreen("10$\n"));
    }
    else
    {
        debug.Log(debug.InsertRed("Not enough money to buy!"));
    }
}

string PaintPrice(float x) {
    Debug debug;

    if (x > 0 && x <= 0.25)
    {
        return debug.InsertRed(to_string(x));
    }
    else if(x > 0.25 && x <= 0.5)
    {
        return debug.InsertYellow(to_string(x));
    }
    else if (x > 0.5 && x <= 0.75)
    {
        return debug.InsertGreen(to_string(x));
    }
    else if (x > 0.75 && x <= 1)
    {
        return debug.InsertCyan(to_string(x));
    }
}

string Laboratory::GetFullInformation(string dna) {
    string sum = "";
    char* chars = new char[dna.length() + 1];
    Dna::convertToCharArray(dna, chars);

    sum += "Hight:              " + PaintPrice((SymbolPrice(chars[0]) + SymbolPrice(chars[1]) + SymbolPrice(chars[2]) + SymbolPrice(chars[3])) / 4) + "\n";
    sum += "Width:              " + PaintPrice((SymbolPrice(chars[4]) + SymbolPrice(chars[5]) + SymbolPrice(chars[6]) + SymbolPrice(chars[7])) / 4) + "\n";
    sum += "Color:              " + PaintPrice((SymbolPrice(chars[8]) + SymbolPrice(chars[9]) + SymbolPrice(chars[10]) + SymbolPrice(chars[11]) + SymbolPrice(chars[12]) + SymbolPrice(chars[13]) + SymbolPrice(chars[14]) + SymbolPrice(chars[15])) / 8) + "\n";
    sum += "Form:               " + PaintPrice((SymbolPrice(chars[16]) + SymbolPrice(chars[17]) + SymbolPrice(chars[18]) + SymbolPrice(chars[19])) / 4) + "\n";
    sum += "Stamina:            " + PaintPrice((SymbolPrice(chars[20]) + SymbolPrice(chars[21]) + SymbolPrice(chars[22]) + SymbolPrice(chars[23])) / 4) + "\n";
    sum += "Growth rate:        " + PaintPrice((SymbolPrice(chars[24]) + SymbolPrice(chars[25]) + SymbolPrice(chars[26]) + SymbolPrice(chars[27])) / 4) + "\n";
    sum += "Disease resistance: " + PaintPrice((SymbolPrice(chars[28]) + SymbolPrice(chars[29]) + SymbolPrice(chars[30]) + SymbolPrice(chars[31])) / 4) + "\n";
    sum += "Fragrance:          " + PaintPrice((SymbolPrice(chars[32]) + SymbolPrice(chars[33]) + SymbolPrice(chars[34]) + SymbolPrice(chars[35])) / 4) + "\n";
    return sum;
}