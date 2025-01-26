#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

class Matriz{
public:
    explicit Vector(int renglones = 1, int columnas = 1);
    ~Vector();
private:

    int renglones;
    int columnas;
    double **arreglo;

};

#endif // MATRIZ_HPP_INCLUDED
