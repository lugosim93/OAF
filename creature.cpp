#include <iostream>
#include <fstream>
#include "creature.h"

void Sponge::clearDay()
{
    if (alive)
    {
        currentWaterReserve -= 4;
        if (currentWaterReserve <= 0) {alive = false;}
    }
}

void Sponge::cloudyDay()
{
    if (alive)
    {
        currentWaterReserve -= 1;
        if (currentWaterReserve <= 0) {alive = false;}
    }
    if (alive)
    {
        distance += 1;
    }
}

void Sponge::rainyDay()
{
    if (alive)
    {

        if (currentWaterReserve < maxWaterReserve - 6)
        {
            currentWaterReserve += 6;
        }
        else
        {
            currentWaterReserve = maxWaterReserve;
        }
         distance += 3;
    }
}


void SandCrawler::clearDay()
{
    if (alive)
    {
        currentWaterReserve -= 1;
        if(currentWaterReserve <= 0){alive = false;}
    }
    if (alive)
    {
        distance += 3;
    }
}

void SandCrawler::cloudyDay()
{
    if (alive)
    {
        distance += 1;
    }
}

void SandCrawler::rainyDay()
{
    if (alive)
    {
        if (currentWaterReserve < maxWaterReserve - 3)
        {
            currentWaterReserve += 3;
        }
        else
        {
            currentWaterReserve = maxWaterReserve;
        }
    }
}

void Walker::clearDay()
{
    if (alive)
    {
        currentWaterReserve -= 2;
        if(currentWaterReserve<=0) {alive = false;}
    }

    if (alive)
    {
        distance += 1;
    }
}

void Walker::cloudyDay()
{
    if (alive)
    {
        currentWaterReserve -= 1;
        if(currentWaterReserve <= 0) {alive = false;}
    }
    if (alive)
    {
        distance += 2;
    }
}

void Walker::rainyDay()
{
    if(alive)
    {
        if(currentWaterReserve < maxWaterReserve - 3)
        {
            currentWaterReserve += 3;
        }
        else
        {
            currentWaterReserve = maxWaterReserve;
        }
        distance += 1;
    }
}
