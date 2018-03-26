// Jakub Gruszecki

#include <iostream>
#include <cstdlib>
using namespace std;

class matrix{
private:
    int rows, columns;
    double **tmatrix;
public:

    //konstruktory i dekonstruktory
    matrix(int=1, int=1);
    ~matrix();

    double read(int wier, int kol);
    void change(double wartosc, int wier, int kol);
    //operatory
    friend ostream& operator<<(ostream &ostr, const matrix &m);
    friend istream& operator>>(istream &istr, const matrix &m);
    matrix operator+(const matrix &m);
    matrix operator-(const matrix &m);
    matrix operator*(const matrix &m);
    int operator==(const matrix &m);
    int operator!=(const matrix &m);
    void operator+=(const matrix &m);
    void operator-=(const matrix &m);
    void operator*=(const matrix &m);
    matrix& operator=(const matrix &m);
};

