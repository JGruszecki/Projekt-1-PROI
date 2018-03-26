// Jakub Gruszecki

#include <iostream>
#include <cstdlib>
#include "matrix.h"

using namespace std;

int compare(int x, int y);
double getvalue();

int main()
{
    int a, wiersze, kolumny, wiersze2, kolumny2;
    cout << "Podaj wymiary pierwszej macierzy:  " << endl;
    while(1){
        cin >> wiersze >> kolumny;
        if(cin.good()){
            if(wiersze <= 0 || kolumny <= 0)
            {
                cout << "Wymiary macierzy musza byc wieksze niz 0! Prosze wczytac ponownie:  " << endl;
                continue;
            }
            else
                break;
        }
        else
        {
            cout << "Nie podano liczny, sproboj ponownie" << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }
    }
    cout << "Podaj wymiary drugiej macierzy:  " << endl;
    while(1){
        cin >> wiersze2 >> kolumny2;
        if(cin.good()){
            if(wiersze2 <= 0 || kolumny2 <= 0)
            {
                cout << "Wymiary macierzy musza byc wieksze niz 0! Prosze wczytac ponownie:  " << endl;
                continue;
            }
            else
                break;
        }
        else
        {
            cout << "Nie podano liczby, sproboj ponownie:  " << endl;
            cin.clear();
            cin.ignore(9999, '\n');
        }
    }
    matrix m1(wiersze, kolumny);
    matrix m2(wiersze2, kolumny2);
    cout << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Aby wybrac operacje, wybierz odpowiadajacy jej numer i zatwierdz \"enter\"." << endl;
    cout << "1 - Wczytaj macierz m1" << endl;
    cout << "2 - Wczytaj macierz m2" << endl;
    cout << "3 - Wypisz macierz m1" << endl;
    cout << "4 - Wypisz macierz m2" << endl;
    cout << "5 - Wypisz wartosc elementu macierzy m1 o danych wspolrzednych" << endl;
    cout << "6 - Zmien wartosc elementu macierzy m1 o danych wspolrzednych" << endl;
    cout << "7 - m1 + m2" << endl;
    cout << "8 - m1 += m2" << endl;
    cout << "9 - m1 - m2" << endl;
    cout << "10 - m1 -= m2" << endl;
    cout << "11 - m1 * m2" << endl;
    cout << "12 - m1 *= m2" << endl;
    cout << "13 - Czy m1 == m2 ?" << endl;
    cout << "14 - Czy m1 != m2 ?" << endl;
    cout << "0 - zakoncz dzialanie programu" << endl;
    for(int licznik = 0; licznik < 100; licznik++)
    {
        cout << endl << "Wybrane polecenie: ";
        cin >> a;
        cout << endl;
        switch(a){
        default:
            cout << "Nie ma takieg polecenia!" << endl;
            break;
        case 1:
            cin >> m1;
            break;
        case 2:
            cin >> m2;
            break;
        case 3:
            cout << m1 << endl;
            break;
        case 4:
            cout << m2 << endl;
            break;
        case 5:
            cout << "Podaj wspolrzedne elementu: ";
            while(1)
            {
                cin >> wiersze >> kolumny;
                if(cin.good()){
                if(wiersze <= 0 || kolumny <= 0)
                {
                    cout << "Wymiary macierzy musza byc wieksze niz 0! Prosze wczytac ponownie:  " << endl;
                    continue;
                }
                else
                    break;
                }
                else
                {
                    cout << "Nie podano liczny, sproboj ponownie" << endl;
                    cin.clear();
                    cin.ignore(9999, '\n');
                }
            }
            if(x >= rows || y >= columns)
            {
                cout << "Nie ma elementu o podanych wartosciach!" << endl;
                break;
            }
            cout << endl << "Wartosc elementu o wspolrzednych x = " << wiersze << ", y = " << kolumny << ": " << m1.read(wiersze, kolumny) << endl;
            break;
        case 6:
            double x;
            cout << "Podaj wspolrzedne elementu: ";
            while(1)
            {
                cin >> wiersze >> kolumny;
                if(cin.good()){
                if(wiersze <= 0 || kolumny <= 0)
                {
                    cout << "Wymiary macierzy musza byc wieksze niz 0! Prosze wczytac ponownie:  " << endl;
                    continue;
                }
                else
                    break;
                }
                else
                {
                    cout << "Nie podano liczny, sproboj ponownie" << endl;
                    cin.clear();
                    cin.ignore(9999, '\n');
                }
            }
            if(x >= rows || y >= columns)
            {
                cout << "Nie ma elementu o podanych wartosciach!" << endl;
                break;
            }
            cout << "Podaj nowa wartosc:  ";
            while(1)
            {
                cin >> x;
                if(cin.good())
                    break;
                else
                {
                    cout << "Nie podano liczny, sproboj ponownie" << endl;
                    cin.clear();
                    cin.ignore(9999, '\n');
                }
            }
            m1.change(x, wiersze, kolumny);
            break;
        case 7:
            if(compare(wiersze, wiersze2) && compare(kolumny, kolumny2))
            {
                matrix m3(wiersze, kolumny);
                m3 = m1 + m2;
                cout << m3;
            }
            else
                cout << "Blad, macierze maja rozne wymiary!" << endl;
            break;
        case 8:
            if(compare(wiersze, wiersze2) && compare(kolumny, kolumny2))
            {
                m1 += m2;
                cout << m1;
            }
            else
                cout << "Blad, macierze maja rozne wymiary!" << endl;
            break;
        case 9:
            if(compare(wiersze, wiersze2) && compare(kolumny, kolumny2))
            {
                matrix m3(wiersze, kolumny);
                m3 = m1 - m2;
                cout  << m3;
            }
            else
                cout << "Blad, macierze maja rozne wymiary!" << endl;
            break;
        case 10:
            if(compare(wiersze, wiersze2) && compare(kolumny, kolumny2))
            {
                m1 -= m2;
                cout << m1 << endl;
            }
            else
                cout << "Blad, macierze maja rozne wymiary!" << endl;
            break;
        case 11:
            if(compare(kolumny, wiersze2))
            {
                matrix m3(wiersze, kolumny2);
                m3 = m1 * m2;
                cout << m3 << endl;
            }
            else
                cout << "Blad, nie mozna wykonac operacji mnozenia na tych macierzach!" << endl;
            break;
        case 12:
            if(compare(wiersze, wiersze2) && compare(kolumny, kolumny2))
            {
                m1 *= m2;
                cout << m1 << endl;
            }
            else
                cout << "Blad, nie mozna wykonac operacji mnozenia na tych macierzach!" << endl;
            break;
        case 13:
            if(m1 == m2)
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
            break;
        case 14:
            if(m1 != m2)
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
            break;
        case 0:
            cout << "Zamykanie programu..." << endl;
            return 0;
        }
    }
    return 0;
}
