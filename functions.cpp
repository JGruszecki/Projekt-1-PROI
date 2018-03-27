// Jakub Gruszecki

#include <iostream>
#include <cstdlib>
#include "matrix.h"
using namespace std;


int compare(int x, int y){    // Funkcja do porownywania wartosci
    if(x != y)
        return 0;
    else return 1;
}

double matrix::read(int x, int y){   // metoda klasy zwracajaca wartosc elementu maceirzy o podanych wspolrzednych
    return tmatrix[x-1][y-1];
}

void matrix::change(double wartosc, int x, int y){ // Meroda klasy zmieniajaca wartosc elementu macierzy o podanych wspolrzednych
        tmatrix[x-1][y-1] = wartosc;
}
matrix::matrix(int x, int y){             //    Konstruktor - x - wiersze, y - kolumny
    rows = x;
    columns = y;
    tmatrix = new double*[rows];
    for(int i = 0; i < rows; i++)
        tmatrix[i] = new double[columns];
    for(int i = 0; i < rows; i++)            // Wypelnianie maceirzy zerammi
    {
        for(int j = 0; j < columns; j++)
            tmatrix[i][j] = 0;
    }
}

matrix::~matrix(){                       //    Destruktor
    for(int i = 0; i < rows; i++)
        delete [] tmatrix[i];
    delete [] tmatrix;
}

ostream& operator<<(ostream &ostr, const matrix &m){    // operator wypisania macierzy na ekran
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.columns; j++)
                ostr << m.tmatrix[i][j] << " ";
        ostr << endl;
    }
    return ostr;
}

istream& operator>>(istream &istr, const matrix &m){    // Operator wczytania macierzy
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.columns; j++)
        {
            double x;
            istr >> x;
            if(istr.good())
            {
                m.tmatrix[i][j] = x;
            }
            else
            {
                cout << "Wczytano zly znak, prosze wczytac ponownie:  ";               // Zabezpieczenie przed wpisaniem zlych danych
                istr.clear();
                istr.ignore(9999, '\n');
                j--;
            }
        }
    }
    return istr;
}

matrix matrix::operator+(const matrix &m){       // Operator sluzocy do dowawania macierzy. Zwraca obiekt bedacy wynikiem dodawania
        matrix m3(rows, columns);
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                m3.tmatrix[i][j] = tmatrix[i][j] + m.tmatrix[i][j];
            cout << endl;
        }
        return m3;
}

void matrix::operator+=(const matrix &m){       // Operator dodania macierzy do drogiej macierzy. Nic nie zwraca, zmienia wartosc obiektu podstawowego
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                tmatrix[i][j] = tmatrix[i][j] + m.tmatrix[i][j];
            cout << endl;
        }
}

matrix matrix::operator-(const matrix &m){  // Operator sluzacy do odejmowania macierzy. Zwraca obiekt
        matrix m3(rows, columns);
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                m3.tmatrix[i][j] = tmatrix[i][j] - m.tmatrix[i][j];
            cout << endl;
        }
        return m3;
}

void matrix::operator-=(const matrix &m){ // Analogicznie do operatora +=
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                tmatrix[i][j] = tmatrix[i][j] - m.tmatrix[i][j];
            cout << endl;
        }
}

matrix matrix::operator*(const matrix &m){     // Operator mnozenia macierzy. Zwraca obiekt
        matrix m3(rows, m.columns);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
            {
                int sum = 0;
                for(int n = 0; n < columns; n++)
                    sum += tmatrix[i][n] * m.tmatrix[n][j];
                m3.tmatrix[i][j] = sum;
            }
        }
        return m3;

}

void matrix::operator*=(const matrix &m){    // Analogicznie do += i -=
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
            {
                int sum = 0;
                for(int n = 0; n < columns; n++)
                    sum += tmatrix[i][n] * m.tmatrix[n][j];
                tmatrix[i][j] = sum;
            }
        }
}

int matrix::operator==(const matrix &m){     // Operator sprawdzajacy, czy obiekty sa rowne
    if(columns != m.columns || rows != m.rows)
        return 0;
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < columns; j++)
        {
            if(tmatrix[i][j] != m.tmatrix[i][j])
                return 0;
        }
    }
    return 1;
}

int matrix::operator!=(const matrix &m){          // Operator sprawdzajacy czy obiekty sa rozne
    if(rows != m.rows || columns != m.columns)
        return 1;
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < columns; j++)
        {
            if(tmatrix[i][j] != m.tmatrix[i][j])
                return 1;
        }
    }
    return 0;
}

matrix& matrix::operator=(const matrix &m){  // Operator przypisania
    rows = m.rows;
    columns = m.columns;
    tmatrix = new double* [rows];
    for(int i = 0; i < rows; i++)
        tmatrix[i] = new double [columns];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            tmatrix[i][j] = m.tmatrix[i][j];
    }
    return *this;
}
