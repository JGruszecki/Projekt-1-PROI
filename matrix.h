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
    matrix(int x, int y);
    ~matrix();

    double read(int x, int y);
    void change(double wartosc, int x, int y);
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

