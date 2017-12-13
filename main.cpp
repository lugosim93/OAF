#include <iostream>
#include "creature.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>


using namespace std;

void create(const string &str, vector<Creature*> &creature, vector<char> &days)
{
    ifstream f(str.c_str());
    if(f.fail())
    {
        cout << "Nincs meg a fájl\n";
        exit(1);
    }
    int n;
    f >> n;
    creature.resize(n);
    for(int i=0; i<n; ++i)
    {
        char ch;
        string name;
        int water;
        f >> name >> ch >> water;
        switch(ch)
        {
        case 's' :
            creature[i] = new Sponge(name, water);
            break;
        case 'h' :
            creature[i] = new SandCrawler(name, water);
            break;
        case 'l' :
            creature[i] = new Walker(name, water);
            break;
//       default:
//          throw UNDEFINED_BEHAVIOUR;
        }
    }
    char temp;
    while(!f.fail())
    {
        f >> temp;
        days.push_back(temp);
    }
}


int maxker(vector<Creature*> &creature)
{
    int maxValue = creature[0]->getDistance();
    int maxIndex = 0;

    for (size_t i=1; i<creature.size(); i++)
    {
        if (creature[i]->getDistance() > maxValue)
        {
            maxValue = creature[i]->getDistance();
            maxIndex = i;
        }
    }
    return maxIndex;
}

string race(vector<Creature*> &creature, const vector<char> days)
{
    size_t n = 0;
    while(n < days.size())
    {
        for (size_t i =0; i<creature.size(); i++)
        {
            switch (days[n])
            {
            case 'n':
                {
                    creature[i]->clearDay();
                    break;
                }
            case 'f':
                {
                    creature[i]->cloudyDay();
                    break;
                }
            case 'e':
                {
                    creature[i]->rainyDay();
                    break;
                }
//            default:
//                throw UNDEFINED_BEHAVIOUR;
            }
        }
        n++;
    }
    int winnerIndex = maxker(creature);

    return creature[winnerIndex]->getName();

}

//#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{
    string fajlNev;
    cout << "Kerem az input fajl nevet (fajlnev.txt)" << endl;
    cin >> fajlNev;
    vector<Creature*> creature;
    vector<char> days;
    create(fajlNev, creature, days);


    cout << race(creature, days) << " nyert";

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


// Teszteset 1: Konstruktor jól inicializálja-e a lényeket

TEST_CASE ("1", "konstruktor")
{
    Sponge szivacs ("szivacs", 20);
    Walker lepegeto ("lepegeto", 12);
    SandCrawler homokjaro ("homokjaro", 8);

    CHECK(szivacs.isAlive());
    CHECK(lepegeto.isAlive());
    CHECK(homokjaro.isAlive());

    CHECK(szivacs.getDistance() == 0);
    CHECK(lepegeto.getDistance() == 0);
    CHECK(homokjaro.getDistance() == 0);

    CHECK(szivacs.getCurrentWaterReserve() == 20);
    CHECK(lepegeto.getCurrentWaterReserve() == 12);
    CHECK(homokjaro.getCurrentWaterReserve() == 8);
}

TEST_CASE ("2", "Sponge metodusok")
{
    Sponge test("szivacs", 20);
    CHECK(test.getName() == "szivacs");

    test.clearDay();
    CHECK(test.getCurrentWaterReserve() == 16);
    CHECK(test.isAlive());
    CHECK(test.getDistance() == 0);

    test.cloudyDay();
    CHECK(test.getCurrentWaterReserve() == 15);
    CHECK(test.getDistance() == 1);
    CHECK(test.isAlive());

    test.rainyDay();
    CHECK(test.getCurrentWaterReserve() == 20);
    CHECK(test.getDistance() == 4);
    CHECK(test.isAlive());

    for (int i = 0; i<6; i++)
    {
        test.clearDay();
    }
    CHECK_FALSE(test.isAlive());
}

TEST_CASE ("3", "SandCrawler metodusok")
{
    SandCrawler test("homokjaro", 8);
    CHECK(test.getName() == "homokjaro");

    test.clearDay();
    CHECK(test.getCurrentWaterReserve() == 7);
    CHECK(test.isAlive());
    CHECK(test.getDistance() == 3);

    test.cloudyDay();
    CHECK(test.getCurrentWaterReserve() == 7);
    CHECK(test.getDistance() == 4);
    CHECK(test.isAlive());

    test.rainyDay();
    CHECK(test.getCurrentWaterReserve() == 8);
    CHECK(test.getDistance() == 4);
    CHECK(test.isAlive());

    for (int i = 0; i<8; i++)
    {
        test.clearDay();
    }
    CHECK_FALSE(test.isAlive());
}

TEST_CASE ("4", "Walker metodusok")
{
    Walker test("lepegeto", 12);
    CHECK(test.getName() == "lepegeto");

    test.clearDay();
    CHECK(test.getCurrentWaterReserve() == 10);
    CHECK(test.isAlive());
    CHECK(test.getDistance() == 1);

    test.cloudyDay();
    CHECK(test.getCurrentWaterReserve() == 9);
    CHECK(test.getDistance() == 3);
    CHECK(test.isAlive());

    test.rainyDay();
    CHECK(test.getCurrentWaterReserve() == 12);
    CHECK(test.getDistance() == 4);
    CHECK(test.isAlive());

    for (int i = 0; i<6; i++)
    {
        test.clearDay();
    }
    CHECK_FALSE(test.isAlive());
}

TEST_CASE ("5", "Minta input test")
{
    string fajlNev = "input.txt";
    vector<Creature*> creature;
    vector<char> days;
    create(fajlNev, creature, days);
    CHECK(race(creature, days) == "Seta");

}

#endif
