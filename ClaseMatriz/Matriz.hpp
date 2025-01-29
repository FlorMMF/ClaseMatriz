#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

class Matriz {
    friend std::istream &operator>>(std::istream &entrada, Matriz &v);
    friend std::ostream &operator<<(std::ostream &salida, const Matriz &v);
    friend Matriz operator* (double escalar, const Matriz v);
public:


    Matriz(int reng = 1, int col = 1);
    ~Matriz();
    Matriz(const Matriz &otra);
    Matriz &operator=(const Matriz &otra);
    Matriz operator*(double escalar) const;
    Matriz transponida() const;
    Matriz invertida() const;


    Matriz operator+(const Matriz v) const;
    Matriz operator-(const Matriz v) const;
    Matriz Redimensionar(int reng, int col) const;

private:
    int renglones;
    int columnas;
    double **componente;


};

#endif //MATRIZ_HPP_INCLUDED
