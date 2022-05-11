#pragma once
#include "Plansza.h"

class Logika: public Plansza
{
protected:
    bool game_over = false;
    bool wydluz = false;
    int owoc = 0;
    char charKierunek = 'w';
    char tempKierunek = 'w';
    int tempX1 = 0, tempY1 = 0, tempX2 = 0, tempY2 = 0;

public:
    void Odswiezanie();
    void Waz(bool& wydluz);
    void Sterowanie();
    void Owoce();
    void GameOver();
};
