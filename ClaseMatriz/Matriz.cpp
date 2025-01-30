#include <iostream>
#include "Matriz.hpp"
#include <cmath>
#include <limits>
using  namespace std;

/**

 * \file Matriz.cpp

 * Este archivo desarrolla las funciones declaradas en Matiz.hpp

 * \author Flor Machado y Elias Peregrina

 * \date 30/01/2025

 */

//Constructor y destructor ******************************

Matriz::Matriz(int reng, int col){
    renglones = reng;
    columnas = col;
    try{
        componente = new double*[renglones];
        for (int i = 0; i < renglones; ++i){
            componente[i] = new double[columnas];
        }
        for (int j = 0; j < renglones; ++j){
            for (int i = 0; i < columnas; ++i){
                componente[j][i] = 0;
            }
        }
    }catch (bad_alloc &) {
        throw "Problema de asignacion de memoria";
    }
}

Matriz::~Matriz(){
    for (int i = 0; i < renglones; ++i) {
        delete[] componente[i];
    }
    delete[] componente;
}

//Copia du la copia du la copia
Matriz::Matriz(const Matriz &otra) {
    renglones = otra.renglones;
    columnas = otra.columnas;
    componente = new double*[renglones];
    for (int i = 0; i < renglones; ++i) {
        componente[i] = new double[columnas];
        for (int j = 0; j < columnas; ++j) {
            componente[i][j] = otra.componente[i][j];
        }
    }
}

//Operador igual =) (parece una cara feliz)
Matriz &Matriz::operator=(const Matriz &otra) {
    if (this != &otra) {
        for (int i = 0; i < renglones; ++i) {
            delete[] componente[i];
        }
        delete[] componente;

        renglones = otra.renglones;
        columnas = otra.columnas;
        componente = new double*[renglones];
        for (int i = 0; i < renglones; ++i) {
            componente[i] = new double[columnas];
            for (int j = 0; j < columnas; ++j) {
                componente[i][j] = otra.componente[i][j];
            }
        }
    }
    return *this;
}


Matriz Matriz::operator+(const Matriz v) const{

    if(renglones != v.renglones || columnas != v.columnas)throw "Matrices incompatibles para la suma";
    Matriz s(renglones,columnas);
    for(int j = 0; j < s.renglones; ++j){
        for(int i = 0; i < s.columnas ; ++ i){
            s.componente[j][i] = componente[j][i] + v.componente[j][i];
        }
    }

    return s;

}

Matriz Matriz::operator*(const Matriz v) const{

    if(columnas != v.renglones && renglones != v.columnas)throw "Matrices incompatibles para la multiplicacion";
    Matriz s(renglones,v.columnas);
    for(int i = 0; i < renglones; ++i){
        for(int j = 0; j < v.columnas; ++j){
            for(int k = 0; k < columnas ; ++ k){
                s.componente[i][j] += componente[i][k]*v.componente[k][j];
            }
        }
    }

    return s;

}

Matriz Matriz::operator-(const Matriz v) const{

    if(renglones != v.renglones || columnas != v.columnas)throw "Matrices incompatibles para la resta";
    Matriz s(renglones,columnas);
    for(int j = 0; j < s.renglones; ++j){
        for(int i = 0; i < s.columnas ; ++ i){
            s.componente[j][i] = componente[j][i] - v.componente[j][i];
        }
    }

    return s;

}





//Matriz para escalar
Matriz Matriz::operator*(double escalar) const {
    Matriz resultado(renglones, columnas);
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.componente[i][j] = componente[i][j] * escalar;
        }
    }
    return resultado;
}

//Transponida de una matriz
Matriz Matriz::transponida() const {
    Matriz resultado(columnas, renglones);
    for (int i = 0; i < renglones; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.componente[j][i] = componente[i][j];
        }
    }
    return resultado;
}

//Invertida de matriz cuadrada
Matriz Matriz::invertida() const {
    if (renglones != columnas) {
        throw "Solo se puede calcular la inversa de matrices cuadradas";
    }
    int n = renglones;
    Matriz inversa(n, n);
    Matriz temp(*this);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inversa.componente[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (temp.componente[i][i] == 0) {
            throw "La matriz no es invertible";
        }
        double pivote = temp.componente[i][i];
        for (int j = 0; j < n; ++j) {
            temp.componente[i][j] /= pivote;
            inversa.componente[i][j] /= pivote;
        }
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = temp.componente[k][i];
                for (int j = 0; j < n; ++j) {
                    temp.componente[k][j] -= factor * temp.componente[i][j];
                    inversa.componente[k][j] -= factor * inversa.componente[i][j];
                }
            }
        }
    }
    return inversa;
}

Matriz Matriz::Redimensionar(int reng, int col) const{
    Matriz s(reng, col);
    for(int j = 0; j < s.renglones; ++j){
        for(int i = 0; i < s.columnas ; ++ i){
            if((j>=renglones) || (i >=columnas)){
                s.componente[j][i] = 0;
            }else{
                s.componente[j][i] = componente [j][i];
            }
        }
    }
    return s;
}

// Operadores *******************************************

std::istream &operator>>(std::istream &entrada, Matriz &v) {
    for (int i = 0; i < v.renglones; ++i) {
        for (int j = 0; j < v.columnas; ++j) {
            cout << "Componente [" << i << " , " << j << "]: ";
            entrada >> v.componente[i][j];
        }
    }
    return entrada;
}

std::ostream &operator<<(std::ostream &salida, const Matriz &v) {
    for (int i = 0; i < v.renglones; ++i) {
        for (int j = 0; j < v.columnas; ++j) {
            salida << v.componente[i][j] << "  ";
        }
        salida << endl;
    }
    return salida;
}

//Metodo auxiliar
int Capturarentero(const char solicitud[]){
    int num;
    cout<<solicitud;
    cin>>num;
    while (cin.fail()){
        cout<<"Erorr: no es un numero"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(),'\n');
        cout<<solicitud;
        cin>> num;
    }
    return num;
}
