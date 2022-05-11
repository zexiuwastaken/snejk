#pragma once
#include <cstdlib>
#include <vector>
#include <string>

class Plansza
{
protected:
    constexpr static int WymiaryX[] = {20, 30, 40};
    constexpr static int WymiaryY[] = {20, 30, 40};
    int wybor = 0;
    int wynik = 0;
    std::string msg = "hhhhhh";
    std::string** obszar;
    int glowaX, glowaY;
    std::vector<int> cialoX;
    std::vector<int> cialoY;
    int owocX = 5, owocY = 5;
    char glowa = 'O', cialo = 'o';
    char charOwoc[3] = { 'b', 'a', 'j' };
    int ktoryOwoc = 0;

    char temp = 0; // czy odswieza czy nie

public:
    //Plansza();
    //~Plansza();
    int Wybor_planszy();
    void ZaladujPlansze();
    void Rysowanie_planszy();
    void cleanup();
};

