// Jakub Gruszecki

#include <iostream>
#include <cstdlib>
#include "matrix.h"
using namespace std;


int compare(int x, int y){
    if(x != y)
        return 0;
    else return 1;
}

double matrix::read(int x, int y){
    return tmatrix[x-1][y-1];
}

void matrix::change(double wartosc, int x, int y){
        tmatrix[x-1][y-1] = wartosc;
}
matrix::matrix(int x, int y){             //    Konstruktor - x - wiersze, y - kolumny
    rows = x;
    columns = y;
    tmatrix = new double*[rows];
    for(int i = 0; i < rows; i++)
        tmatrix[i] = new double[columns];
    for(int i = 0; i < rows; i++)
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

ostream& operator<<(ostream &ostr, const matrix &m){
    for(int i = 0; i < m.rows; i++)
    {
        for(int j = 0; j < m.columns; j++)
                ostr << m.tmatrix[i][j] << " ";
        ostr << "\n";
    }
    return ostr;
}

istream& operator>>(istream &istr, const matrix &m){
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
                cout << "Wczytano zly znak, prosze wczytac ponownie:  ";
                istr.clear();
                istr.sync();
                j--;
            }
        }
    }
    return istr;
}

matrix matrix::operator+(const matrix &m){
        matrix m3(rows, columns);
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                m3.tmatrix[i][j] = tmatrix[i][j] + m.tmatrix[i][j];
            cout << endl;
        }
        return m3;
}

void matrix::operator+=(const matrix &m){
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                tmatrix[i][j] = tmatrix[i][j] + m.tmatrix[i][j];
            cout << endl;
        }
}

matrix matrix::operator-(const matrix &m){
        matrix m3(rows, columns);
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                m3.tmatrix[i][j] = tmatrix[i][j] - m.tmatrix[i][j];
            cout << endl;
        }
        return m3;
}

void matrix::operator-=(const matrix &m){
        for(int i = 0; i < m.rows; i++)
        {
            for(int j = 0; j < m.columns; j++)
                tmatrix[i][j] = tmatrix[i][j] - m.tmatrix[i][j];
            cout << endl;
        }
}

matrix matrix::operator*(const matrix &m){
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

void matrix::operator*=(const matrix &m){
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

int matrix::operator==(const matrix &m){
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

int matrix::operator!=(const matrix &m){
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

matrix& matrix::operator=(const matrix &m){
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
