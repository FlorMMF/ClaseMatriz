#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main()
{
    cout << "Programa que realiza operaciones de matrices" << endl;


    int Vn, Wn; //renglones
    int Vm, Wm; //columnas

    //Captura de los vectores ****************************************************
    cout << "Ingrese la cantidad de renglones que tiene la primera matriz" << endl;
    cin >> Vn;
    cout << "Ingrese la cantidad de columnas que tiene la primera matriz" << endl;
    cin >> Vm;

    Matriz  v(Vn,Vm);

    cout << "Ingrese los componentes de la primera matriz" << endl;
    cin >> v;

    cout << "Ingrese la cantidad de renglones que tiene la segunda matriz" << endl;
    cin >> Wn;
    cout << "Ingrese la cantidad de columnas que tiene la segunda matriz" << endl;
    cin >> Wm;

    Matriz  w(Wn,Wm);

    cout << "Ingrese los componentes de la segunda matriz" << endl;
    cin >> w;



    //Suma de dos matrices *********************************************************
    Matriz q(Vn,Vm);
    q= v + w;

    cout << v << endl << endl << "+" << endl << endl << w << endl << endl << "=" << endl << endl << q;

    Matriz p(Vn,Vm);
    p= v - w;
    cout <<  endl << endl << v << endl << endl << "-" << endl << endl << w << endl << endl << "=" << endl << endl << p;

    //Resta de dos matrices ********************************************************

    //Producto de dos matrices *****************************************************

    //Producto de una matriz por un escalar ****************************************

    //La transpuesta de una matriz *************************************************

    //La inversa de una matriz cuadrada ********************************************

    //Método de redimensionamiento de una matriz ********************************
    return 0;
}
