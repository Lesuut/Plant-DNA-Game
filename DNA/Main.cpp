#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <Windows.h>
#include "Debug.h"
#include "Data.h"
#include "Dna.h"
#include "Laboratory.h"
#include "Competition.h"

using namespace std;

string generateRandomDna() {
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

void ConsoleClear() {
    system("cls");

   /* Debug debug;
    for (int i = 0; i < 50; i++)
    {
        debug.Log("\n");
    }*/
}

char SceneMenu(Data& data) {
    Debug debug;
    debug.Log(string(debug.InsertGreen("PLANT\n")) + 
              string(debug.InsertRed("D")) + string(debug.InsertCyan("N")) + string(debug.InsertYellow("A\n")) +
              string(debug.InsertMagenta("GAME\n") + "______________________________________________________________\n"));
    debug.Log("money: " + debug.InsertGreen(to_string(data.GetMoney()) + string("$")));

    debug.Log(debug.InsertYellow(string("\n          enter n to go to: \n") 
        + string("\n            Help: 1") 
        + string("\n          Garden: 2")
        + string("\n          Market: 3")
        + string("\n      Laboratory: 4")
        + string("\n     Competition: 5")));

    debug.Log("\nInventory\n");

    debug.Log(data.GetStringInventoryDna());

    char input;
    cin >> input;
    return input;
}

void SceneHelp() {
    Debug debug;

        debug.Log("\n" + debug.InsertYellow("Garden") + " - In the garden, you can look\nat the visualization of your plants.\nThe visualization depends on the DNA.\n\n" +
        debug.InsertYellow("Market") + " - In the market you\ncan buy and sell plants.\n\n" +
        debug.InsertYellow("Laboratory") + " - the lab allows you to\nperform various monipulations\nwith plants on the DNA level.\n\n" +
        debug.InsertYellow("Competition") + " - it's a place where you can compete \with other selectors and make money.\n\n");

    debug.Log("\nEnter any character to return to the menu");
    char input = 0;
    cin >> input;
}

void SceneGargen(Data& data) {
    Debug debug;

    debug.Log(data.GetStringGarden());

    debug.Log("\Enter any character to return to the menu");
    char input = 0;
    cin >> input;
}

void SceneMarket(Data& data) {
    Debug debug;
    char input = 0;

    while (input != '0')
    {
        data.LoadData();

        debug.Log("money: " + debug.InsertGreen(to_string(data.GetMoney()) + string("$")));

        debug.Log("\nInventory\n");

        debug.Log(data.GetStringInventoryDna());

        debug.Log(debug.InsertYellow(string("Market\n______________________________________________\n")
            + string("\nEnter 0 if you want to return to the menu:")
            + string("\nEnter 1 if you want to sell the plant:")
            +string("\nEnter 2 if you want to buy the plant for 500$:")));

        cin >> input;
        if (input == '0')
        {
            return;
        }

        string name = "";
        switch (input)
        {
            case('1'):            
                debug.Log(debug.InsertYellow("Enter the name of the plant you want to sell: "));
                cin >> name;

                ConsoleClear();

                data.SellDna(data.FindDnaByName(name));
            break;

            case('2'):
                debug.Log(debug.InsertYellow("Enter the name of the new plant: "));
                cin >> name;

                ConsoleClear();

                if (data.Buy(500))
                {
                    data.AddDna(Dna(name, generateRandomDna()));
                    debug.Log(debug.InsertYellow("You have successfully purchased plant.\n Its: ") + data.FindDnaByIndex(data.GetDnaListSize() - 1).GetColorDna());
                }
                else
                {
                    debug.Log(debug.InsertRed("Not enough money to buy!"));
                }
                break;
        default:
            ConsoleClear();
        break;
        }    
    }

    //debug.Log("\Enter any character to return to the menu");
    cin >> input;
}

void SceneLaboratory(Data& data) {
    Debug debug;
    Laboratory laboratory;
    char input = 0;

    while (input != '0')
    {
        data.LoadData();

        debug.Log("money: " + debug.InsertGreen(to_string(data.GetMoney()) + string("$")));

        debug.Log("\nInventory\n");

        debug.Log(data.GetStringInventoryDna());

        debug.Log(debug.InsertCyan(string("Laboratory\n")));
        debug.Log(" ____+_+\n |  || |\n |  || O\n +__+| |\n+____+_+\n| +||+ |\n+______+");
        debug.Log(debug.InsertCyan(
              string("\nEnter 0 if you want to return to the menu:")
            + string("\nEnter 1 if you want help:")
            + string("\nEnter 2 if you want to Crossbreeding:")
            + string("\nEnter 3 if you want to Genetic Modification:")
            + string("\nEnter 4 if you want to get full information about the plant:")));

        cin >> input;
        if (input == '0')
        {
            return;
        }

        string name = "";
        string index = "";
        string parentName;
        string additionalName;
        string tryInput;
        switch (input)
        {
        case('1'):
            debug.Log("          Crossbreeding.\nTo cross two plants - you need to choose \na parent plant and an additional plant. \nAfter crossing, the new plant gets \n~50% of the genome from the second sprout.\nIn the process of crossing, the parent \nplant will be replaced by the new plant.\nAlso one mutation is added.\n");
            debug.Log("1.    " + debug.InsertRed("AAAA"));
            debug.Log("2.    " + debug.InsertGreen("CCCC"));
            debug.Log("new:  " + debug.InsertRed("A") + debug.InsertGreen("C") + debug.InsertRed("C") + debug.InsertGreen("A"));
            debug.Log("\n");
            debug.Log("          Genetic engineering\nAllows you to create a mutation in a given\npiece of dna. You can choose the range\nfrom 0-35 genes.");

            debug.Log(debug.InsertYellow("\nTo continue enter any character:"));
            cin >> name;
            break;
        case('2'):
            debug.Log(debug.InsertYellow("Enter name new plant:"));
            cin >> name;
            debug.Log(debug.InsertYellow("Enter the name of the parent plant:"));
            cin >> parentName;
            debug.Log(debug.InsertYellow("Enter the name of the additional plant:"));
            cin >> additionalName;
            debug.Log(debug.InsertYellow("Do you really want to continue?\nenter 1 - yes:\nenter 0 - no:"));
            cin >> tryInput;
            if (tryInput == "1")
            {
                ConsoleClear();
                laboratory.Crossbreeding(name, parentName, additionalName, data);
            }
            else
            {
                debug.Log(debug.InsertRed("Crossbreeding has been abolished"));
            }
            break;
        case('3'):
            debug.Log(debug.InsertYellow("Enter the name of the plant to be genomodified:"));
            cin >> name;
            debug.Log(debug.InsertYellow("Enter the sequence number of the gene you want to modify (an integer):"));
            cin >> index;
            debug.Log("You chose:" + laboratory.ColorDNAStrand(data.FindDnaByName(name).dna, index));
            debug.Log(debug.InsertYellow("Do you really want to continue?\nenter 1 - yes:\nenter 0 - no:"));

            cin >> tryInput;
            if (tryInput == "1")
            {
                ConsoleClear();
                laboratory.GeneticModification(name, index, data);
            }
            else
            {
                debug.Log(debug.InsertRed("Genetic Modification has been abolished"));
            }
            break;
        case('4'):
            debug.Log(debug.InsertYellow("Enter the name of the plant to get information about it:"));
            cin >> name;
            ConsoleClear();
            debug.Log(debug.InsertYellow("INFO\n"));
            data.FindDnaByName(name).GetColorDna();
            debug.Log(laboratory.GetFullInformation(data.FindDnaByName(name).dna) + "________________\n");
            break;
        default:
            ConsoleClear();
            break;
        }
    }

    //debug.Log("\Enter any character to return to the menu");
    cin >> input;
}

void SceneCompetition(Data& data) 
{
    Debug debug;
    Laboratory laboratory;
    Competition competition;
    char input = 0;

    while (input != '0')
    {
        data.LoadData();

        debug.Log("money: " + debug.InsertGreen(to_string(data.GetMoney()) + string("$")));

        debug.Log("\nInventory\n");

        debug.Log(data.GetStringInventoryDna());

        debug.Log(debug.InsertYellow(string("Competition\n_________________________________________________________\n")));
        debug.Log(("  +_______+\n|+|       |+|\n|  |     |  |\n |__|   |__|\n     | |\n    |   |\n  +-------+\n  +-------+\n"));
       
        debug.Log(("Cost of participation: ") + debug.InsertGreen("300$\n")
            + ("There are five people in the competition\nincluding you. The winner is the one whose\nplant gets the most points. \nPoints are calculated according to stamina,\ngrowth rate, resistance to disease and\nfragrance. The winner receives: ")
            + debug.InsertGreen("1000$\n"));

        debug.Log(debug.InsertYellow(
            string("\nEnter 0 if you want to return to the menu:\n")
            + string("\Enter 1 to play:\n")
            + string("")));

        cin >> input;
        if (input == '0')
        {
            return;
        }

        string name = "";

        switch (input)
        {
        case('1'):
            debug.Log(debug.InsertYellow("Enter the name of the plant that will participate in the competition:"));
            cin >> name;
            ConsoleClear();
            if (data.Buy(300))
            {
                debug.Log("Paid for participation: " + debug.InsertGreen("300$\n"));
                if (competition.Play(data.FindDnaByName(name), 4))
                {
                    debug.Log(debug.InsertGreen("\nYou win!\n+1000$\n"));
                    debug.Log("Your plant was the best among the opponents\n");
                    data.AddMoney(1000);
                }
                else
                {
                    debug.Log(debug.InsertRed("\nYou lose!\n"));
                    debug.Log("Your plant was not the best. Maybe you'll have better luck next time.\n");
                }
            }
            else
            {
                debug.Log(debug.InsertRed("Not enough money to buy!"));
            }
            break;
        default:
            ConsoleClear();
            break;
        }
    }
}

int main() {
    Debug debug;
    Data data;
    Laboratory laboratory;

    while (true)
    {
        data.LoadData();
        ConsoleClear();
        switch (SceneMenu(data))
        {
        case('1'):
            //ConsoleClear();
            SceneHelp();
            break;
        case('2'):
            ConsoleClear();
            SceneGargen(data);
            break;
        case('3'):
            ConsoleClear();
            SceneMarket(data);
            break;
        case('4'):
            ConsoleClear();
            SceneLaboratory(data);
            break;
        case('5'):
            ConsoleClear();
            SceneCompetition(data);
            break;
        default:
            ConsoleClear();
            debug.LogError("Scene not found");
            break;
        }
    }
}