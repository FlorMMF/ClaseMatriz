
#include <iostream>
#include "Matriz.hpp"
#include <cmath>
using  namespace std;

//constructor y destructor ******************************

Matriz::Matriz(int reng, int col){
    renglones = reng;
    columnas = col;
    try{
        componente = new double*[renglones];

        for (int i = 0; i < renglones; ++i) {
            componente[i] = new double[columnas];
        }

        for(int j = 0; j < renglones ; ++ j){
            for(int i = 0; i < columnas ; ++ i){
                componente[i][j] = 0;
            }
        }

    }catch(bad_alloc &){
        throw "Problema de asignacion de memoria";
    }
}

Matriz::~Matriz(){
    delete[] componente;
 }

 //Operaciones ******************************************

 //Operadores *******************************************

 std::istream & operator>> (std::istream &entrada, Matriz &v){
    for(int j = 0; j < v.renglones ; ++ j){
        for(int i = 0; i < v.columnas ; ++ i){
            cout << "Componente [" << i << " , " << j << "]: ";
            entrada >> v.componente[i][j];
        }
    }
    return entrada;
 }

 std::ostream & operator<< (std::ostream &salida, const Matriz v){

     for(int j = 0; j < v.renglones ; ++ j){
        for(int i = 0; i < v.columnas ; ++ i){
            cout << v.componente[i][j] << "  ";
        }
        cout << endl;
    }
    return salida;
 }
