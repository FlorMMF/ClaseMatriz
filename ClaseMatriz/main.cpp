#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main()
{
    cout << "Programa que realiza operaciones de matrices" << endl;


    int n; //renglones
    int m; //columnas

    //Captura de los vectores ****************************************************
    cout << "Ingrese la cantidad de renglones que tiene la primera matriz" << endl;
    cin >> n;
    cout << "Ingrese la cantidad de columnas que tiene la primera matriz" << endl;
    cin >> m;

    Matriz  v(n,m);

    cout << "Ingrese los componentes de la primera matriz" << endl;
    cin >> v;

    cout << "Ingrese la cantidad de renglones que tiene la segunda matriz" << endl;
    cin >> n;
    cout << "Ingrese la cantidad de columnas que tiene la segunda matriz" << endl;
    cin >> m;

    Matriz  w(n,m);

    cout << "Ingrese los componentes de la segunda matriz" << endl;
    cin >> w;


    cout << v;
    cout << endl;
    cout << w;
    //Suma de dos matrices *********************************************************

    //Resta de dos matrices ********************************************************

    //Producto de dos matrices *****************************************************

    //Producto de una matriz por un escalar ****************************************

    //La transpuesta de una matriz *************************************************

    //La inversa de una matriz cuadrada ********************************************

    //Método de redimensionamiento de una matriz ********************************
    return 0;
}
