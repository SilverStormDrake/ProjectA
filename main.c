/*
 D&D AutoBattler by André Luiz(andrelu00)


 logs:
    Day 1: Dont start whith While Loops, they can run out of control really fast, try For Loops instead.
    Day 2: Well, i started thinking what i should do here, some simulation. But dont know what kind of simulation
           I did something, does not work properly it seems. I would redo this program in some Object Oriented Langauge, but not right now.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SEED 0

int init_rand()
{
    srand(time(SEED));
    return 0;
}

int roll(int x)
{
    init_rand();
    return rand()%x + 1;
}

int main()
{
    init_rand();

    float heroes_w = 0;
    float enemys_w = 0;
    int sample = 1;

    int numOfHeroes = 1;
    int numOfEnemys = 1;
    int numOfEntities = numOfHeroes + numOfHeroes;

    int heroesInitiative[numOfHeroes];
    int enemysInitiative[numOfEnemys];

    int initBonusHeroes[numOfHeroes];
    int initBonusEnemys[numOfEnemys];

    int hpHeroes[numOfHeroes];
    int hpEnemys[numOfEnemys];

    int heroesBonusAttack[numOfHeroes];
    int enemysBonusAttack[numOfEnemys];

    int heroesBonusDamage[numOfHeroes];
    int enemysBonusDamage[numOfEnemys];

    int heroesAC[numOfHeroes];
    int enemysAC[numOfEnemys];

    int round[numOfEntities];

    hpHeroes[0] = 70;
    initBonusHeroes[0] = 2;
    heroesBonusAttack[0] = 8;
    heroesBonusDamage[0] = 5;
    heroesAC[0] = 15;
    

    hpEnemys[0]= 90;
    initBonusEnemys[0] = 5;
    enemysBonusAttack[0] = 8;
    enemysBonusDamage[0] = 5;
    enemysAC[0] = 15;
    

    for(int i = 0; i<sample; i++)
    {
        sleep(1);
        
        heroesInitiative[0] = roll(20) + initBonusHeroes[0];
        enemysInitiative[0] = roll(20) + initBonusEnemys[0];

        if(heroesInitiative[0] > enemysInitiative[0])
        {
            round[0] = heroesInitiative[0];
            round[1] = enemysInitiative[0];
        }
        else if(heroesInitiative[0] < enemysInitiative[0])
        {
            round[0] = enemysInitiative[0];
            round[1] = heroesInitiative[0];
        }

        while(hpHeroes[0] > 0 && hpEnemys[0] > 0)
        {
            for(int i = 0; i < numOfEnemys+numOfHeroes; i++)
            {
                if(round[i] == heroesInitiative[0])
                {
                    if(roll(20) + heroesBonusAttack[0] >= enemysAC[0])
                    {
                        hpEnemys[0] -= roll(10) + 1 + heroesBonusDamage[0];
                    }
                }
                else if(round[i] == enemysInitiative[0])
                {
                    if(roll(20) + enemysBonusAttack[0] >= heroesAC[0])
                    {
                        hpHeroes[0] -= roll(8) + enemysBonusDamage[0];
                    }
                }
            }
        }

        if(hpHeroes[0] > 0)
        {
            heroes_w++;
        }
        else
        {
            enemys_w++;
        }

        hpEnemys[0]= 90;
        hpHeroes[0] = 70;

    }

    printf("\nWinrate: %.2f\n", ((heroes_w/sample) * 100));

    return 0;
}