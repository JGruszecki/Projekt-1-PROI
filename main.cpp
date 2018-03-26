// Jakub Gruszecki

#include <iostream>
#include <cstdlib>
#include "matrix.h"

using namespace std;

int main()
{
    int a, wiersze, kolumny;
    matrix m1, m2;
    cout << "Menu" << endl;
    cout << "Aby wybrac operacje, wybierz odpowiadajacy jej numer i zatwierdz \"enter\"." << endl;
    cout << "1 - Podaj wymiary macierzy m1" << endl;
    cout << "2 - Podaj wymiary macierzy m2" << endl;
    cout << "3 - Wczytaj macierz m1" << endl;
    cout << "4 - Wczytaj macierz m2" << endl;
    cout << "5 - Wypisz macierz m1" << endl;
    cout << "6 - Wypisz macierz m2" << endl;
    cout << "7 - Wypisz wartosc elementu o danych wspolrzednych" << endl;
    cout << "8 - Zmien wartosc elementu o danych wspolrzednych" << endl;
    cout << "9 - m1 + m2" << endl;
    cout << "10 - m1 += m2" << endl;
    cout << "11 - m1 - m2" << endl;
    cout << "12 - m1 -= m2" << endl;
    cout << "13 - m1 * m2" << endl;
    cout << "14 - m1 *= m2" << endl;
    cout << "15 - Czy m1 == m2 ?" << endl;
    cout << "16 - Czy m1 != m2 ?" << endl;
    cout << "0 - zakoncz dzialanie programu" << endl;
    for(int licznik = 0; licznik < 100; licznik++)
    {
        cout << "Wybrane polecenie: ";
        cin >> a;
        switch(a){
        default:
            cout << "Nie ma takieg polecenia!" << endl;
            break;
        case 1:
            cout << "Liczba wierszy:  ";
            cin >> wiersze;
            cout << "Liczba kolumn:  ";
            cin >> kolumny;
            m1 = matrix(wiersze, kolumny);
            break;
        case 2:
            cout << "Liczba wierszy:  ";
            cin >> wiersze;
            cout << "Liczba kolumn:  ";
            cin >> kolumny;
            m2 = matrix(wiersze, kolumny);
            break;
        case 3:
            cin >> m1;
            break;
        case 4:
            cin >> m2;
            break;
        case 5:
            cout << m1 << endl;
            break;
        case 6:
            cout << m2 << endl;
            break;
        case 7:
            cout << "Podaj wspolrzedne elementu: ";
            cin >> wiersze >> kolumny;
            cout << m1.read(wiersze, kolumny) << endl;
            break;
        case 8:
            double x;
            cout << "Podaj wspolrzedne elementu: ";
            cin >> wiersze >> kolumny;
            cout << "Podaj nowa wartosc:  ";
            cin >> x;
            m1.change(x, wiersze, kolumny);
            break;
        case 9:
            cout << m1 + m2;
            break;
        case 10:
            m1 += m2;
            break;
        case 11:
            cout  << m1 - m2;
            break;
        case 12:
            m1 -= m2;
            break;
        case 13:
            cout << m1 * m2;
            break;
            /*
        case 14:
            m1 *= m2;
            break;
            */
        case 15:
            if(m1 == m2)
                cout << "TAK" << endl;
            else
                cout << "NIE" << endl;
            break;
        case 16:
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
