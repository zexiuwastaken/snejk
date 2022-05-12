#include "Logika.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <windows.h>

void Logika::Odswiezanie()
{
    Plansza::ZaladujPlansze();
    do
    {
        system("cls");
        Owoce();
        Waz(wydluz);
        Sterowanie();
        Plansza::Rysowanie_planszy();
        GameOver();
        Sleep(200);
    } while (!game_over);
    system("cls");
    Plansza::cleanup();
    std::cout << "Dzieki elo" << std::endl;
}

void Logika::Owoce()
{
    if (Plansza::glowaX == owocX && Plansza::glowaY == owocY)
    {
        switch (ktoryOwoc)
        {
        case 0:
            Plansza::wynik += 5;
            break;
        case 1:
            Plansza::wynik += 10;
            break;
        case 2:
            Plansza::wynik += 1;
            break;
        }

        wydluz = true;

        owoc = (rand() % 100);
        owocX = rand() % WymiaryX[wybor];
        owocY = rand() % WymiaryY[wybor];

        if (10 > owoc and owoc >= 0) //banan
        {
            ktoryOwoc = 0;
        }
        else if (21 > owoc and owoc > 10) //ananas
        {
            ktoryOwoc = 1;
        }
        else if (101 > owoc and owoc > 20) //jablko
        {
            ktoryOwoc = 2;
        }
    } 
}

void Logika::Waz(bool& wydluz)
{
    tempX1 = Plansza::cialoX[0];
    tempY1 = Plansza::cialoY[0];
    cialoX[0] = glowaX;
    cialoY[0] = glowaY;

    for (int i = 1; i < Plansza::cialoX.size(); i++) 
    {
        tempX2 = Plansza::cialoX[i];
        tempY2 = Plansza::cialoY[i];
        Plansza::cialoX[i] = tempX1;
        Plansza::cialoY[i] = tempY1;
        tempX1 = tempX2;
        tempY1 = tempY2;
    }

    if (wydluz)
    {
        Plansza::cialoX.push_back(tempX1);
        Plansza::cialoY.push_back(tempY1);
        wydluz = false;
    }
}

void Logika::Sterowanie()
{

    if (_kbhit()) {
        charKierunek = _getch();
    }
    
    if (!(charKierunek == 'w' || charKierunek == 'a' || charKierunek == 's' || charKierunek == 'd')) {
        charKierunek = tempKierunek;
        Plansza::msg = "abc";
    }
    else Plansza::msg = "sda";
    
    switch (charKierunek){ 
    case 'w':
        if (tempKierunek == 's') { charKierunek = 's'; Plansza::glowaY++; }
        else {
            tempKierunek = charKierunek;
            Plansza::glowaY--;
        }
        break;
    case 'a':
        if (tempKierunek == 'd') { charKierunek = 'd'; Plansza::glowaX++; }
        else {
            tempKierunek = charKierunek;
            Plansza::glowaX--;
        }
        break;
    case 's':
        if (tempKierunek == 'w') { charKierunek = 'w'; Plansza::glowaY--; }
        else {
            tempKierunek = charKierunek;
            Plansza::glowaY++;
        }
        break;
    case 'd':
        if (tempKierunek == 'a') { charKierunek = 'a'; Plansza::glowaX--; }
        else {
            tempKierunek = charKierunek;
            Plansza::glowaX++;
        }
        break;
    default:
        break;
    }
}

void Logika::GameOver() {

    if (glowaX == -1 || glowaX == WymiaryX[wybor] || glowaY == -1 || glowaY == WymiaryY[wybor]) {
        game_over = true;
    }
    for (int i = 0; i < Plansza::cialoX.size(); i++)
    {
        if (glowaX == Plansza::cialoX[i] && glowaY == Plansza::cialoY[i])
        {
            game_over = true;
        }
    }
}