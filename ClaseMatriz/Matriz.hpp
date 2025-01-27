#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

class Matriz{
    friend std::istream & operator>> (std::istream &entrada, Matriz &v);
    friend std::ostream & operator<< (std::ostream &salida, const Matriz v);
public:
    explicit Matriz(int reng = 1, int col = 1);
    ~Matriz();


private:

    int renglones;
    int columnas;
    double **componente;

};

#endif // MATRIZ_HPP_INCLUDED
