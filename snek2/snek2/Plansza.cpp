#include "Plansza.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int Plansza::Wybor_planszy()
{
    cout << "Witaj w grze Snake." << endl;
    do {
        try
        {
            cout << "Wybierz plansze. Dostepne rozmiary:\n"
                "1. 20x20\n"
                "2. 30x30\n"
                "3. 40x40\n" << endl;
            cout << "Jaki jest twoj wybor?: ";
            cin >> wybor;
            cout << endl;
            if (wybor > 3 || wybor < 1)
            {
                throw("Wybrana opcja nie istnieje");
            }
        }
        catch (char const* e)
        {
            cin.clear();
            cin.ignore(999, '\n');
            system("cls");
            cout << e << endl << endl;
        }
    } while (wybor > 3 || wybor < 1);
    wybor--;
    return wybor;
}

void Plansza::ZaladujPlansze()
{
    obszar = new std::string* [WymiaryX[wybor]];

    for (int i = 0; i < WymiaryX[wybor]; i++)
    {
        obszar[i] = new std::string[WymiaryY[wybor]];
    }
    glowaX = WymiaryX[wybor] / 2;
    glowaY = WymiaryY[wybor] / 2;
    cialoX.push_back(glowaX+1);
    cialoY.push_back(glowaY);
}

void Plansza::Rysowanie_planszy()
{
    for (int i = 0; i < WymiaryX[wybor]; i++)
    {
        for (int j = 0; j < WymiaryY[wybor]; j++)
        {
            if (i == glowaY && j == glowaX)
            {
                obszar[i][j] = glowa;
            }
            else if (i == owocY && j == owocX)
            {
                obszar[i][j] = charOwoc[ktoryOwoc];
            }
            else obszar[i][j] = (char)255u;

            for (int k = 0; k < cialoX.size(); k++)
            {
                if (i == cialoY[k] && j == cialoX[k])
                {
                    obszar[i][j] = cialo;
                }
            }
        }
    }

    cout << wynik << endl;
    cout << (char)201u; // top left
    for (int i = 0; i < WymiaryX[wybor]; i++)
    {
        cout << (char)205u; // side up
    }
    cout << (char)187u << endl; // top right

    for (int i = 0; i < WymiaryY[wybor]; i++)
    {
        cout << (char)186u; // left side
        for (int j = 0; j < WymiaryX[wybor]; j++)
        {
            cout << obszar[i][j]; // blank
        }
        cout << (char)186u << endl; // right side
    }

    cout << (char)200u; // bottom left
    for (int i = 0; i < WymiaryX[wybor]; i++)
    {
        cout << (char)205u; // side bottom
    }
    cout << (char)188u << endl; // bottom right

    cout << "owoc: " << ktoryOwoc << '\t' << '\t' << "glowaX:Y: " << glowaX << ':' << glowaY << endl;
    cout << "cialoX.size()/cialoY.size() : " << cialoX.size() << '/' << cialoY.size() << endl;
    for (int i = 0; i < cialoX.size(); i++) { cout << cialoX[i] << '\t' << cialoY[i] << endl; }
    cout << "dog" << msg;
}

void Plansza::cleanup()
{
    for (int i = 0; i < WymiaryX[wybor]; i++)
    {
        delete[] obszar[i];
    }
    delete[] obszar;
}