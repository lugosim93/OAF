#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
//#define NORMAL_MODE

class Creature
{
protected:
    std::string name;
    bool alive;
    int maxWaterReserve;
    int currentWaterReserve;
    int distance;

public:
    virtual void clearDay() = 0;
    virtual void cloudyDay() = 0;
    virtual void rainyDay() = 0;

    Creature (const std::string &str, int n): name(str), currentWaterReserve(n) {distance = 0; alive = true;}
    bool isAlive(){return alive;}
    std::string getName(){return name;}
    int getDistance(){return distance;}
    int getCurrentWaterReserve(){return currentWaterReserve;}
    virtual ~Creature () {}

    #ifdef NORMAL_MODE
    int getMaxWaterReserve(){return maxWaterReserve;}
    #endif
};

class Sponge : public Creature
{
    static const int maxWaterReserve = 20;
public:


    Sponge(const std::string &str, int n): Creature(str, n) {}
    void clearDay();
    void cloudyDay();
    void rainyDay();
    ~Sponge() {}
};

class SandCrawler : public Creature
{
    static const int maxWaterReserve = 8;
public:

    SandCrawler(const std::string &str, int n): Creature(str, n) {}
    void clearDay();
    void cloudyDay();
    void rainyDay();
    ~SandCrawler() {}
};

class Walker : public Creature
{
    static const int maxWaterReserve = 12;
public:

    Walker(const std::string &str, int n): Creature(str, n) {}
    void clearDay();
    void cloudyDay();
    void rainyDay();
    ~Walker() {}
};

#endif
