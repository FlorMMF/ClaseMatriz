#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main()
{
    try{

        cout << "Programa que realiza operaciones de matrices" << endl;
        cout << "Ingrese la operacion que quiere realizar antes de ingresar las matrices" << endl;
        cout << "1. Suma de matrices" << endl;
        cout << "2. Resta de matrices" << endl;
        cout << "3. Producto entre matrices" << endl;
        cout << "4. Producto por escalar" << endl;
        cout << "5. Transpuesta de una matriz" << endl;
        cout << "6. Inversa de una matriz" << endl;
        cout << "7. Redimensionar matriz" << endl;
        int eleccion ;
        eleccion = Capturarentero("Ingrese el numero que corresponda a la operacion");

        while((eleccion > 7) || (eleccion < 1)){
            eleccion = Capturarentero("Ingrese el numero que corresponda a la operacion");
        }
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

        if(eleccion == 3){
            cout << "Ingrese la cantidad de renglones que tiene la segunda matriz" << endl;
            cin >> Wn;
            cout << "Ingrese la cantidad de columnas que tiene la segunda matriz" << endl;
            cin >> Wm;

        }
        Matriz w(Vn,Vm);

        Matriz q(Vn,Vm);
         Matriz p(Vn,Vm);
        Matriz n(Vn,Vn);
        Matriz m(Wn,Wm);



        switch(eleccion){
            case (1):
                //Suma de dos matrices *********************************************************
                 cout << "Ingrese los componentes de la segunda matriz" << endl;
                cin >> w;
                q= v + w;

                cout << v << endl << endl << "+" << endl << endl << w << endl << endl << "=" << endl << endl << q;
                break;
            case (2):
                //Resta de dos matrices ********************************************************
                cout << "Ingrese los componentes de la segunda matriz" << endl;
                cin >> p;
                p= v - w;
                cout <<  endl << endl << v << endl << endl << "-" << endl << endl << w << endl << endl << "=" << endl << endl << p;
                break;
            case 3:
                 //Producto de dos matrices *****************************************************

                   cout << "Ingrese los componentes de la segunda matriz" << endl;
                   cin >>m;

                n= v * m;
                cout <<  endl << endl << v << endl << endl << "*" << endl << endl << m << endl << endl << "=" << endl << endl << n;
                break;
            case 4:
            case 5:
                break;
            case 6:
                break;
            case 7:
                 //Método de redimensionamiento de una matriz ********************************
                int Rn, Rm;
                cout << endl << "Escribe la cantidad de renglones que tendra tu matriz redimensionada" << endl;
                cin >> Rn;
                cout << endl << "Escribe la cantidad de columnas que tendra tu matriz redimensionada" << endl;
                cin >> Rm;

                Matriz r(Rn, Rm);
                r = v.Redimensionar(Rn,Rm);
                cout << " Esta es la matriz redimensionada" << endl;
                cout << r;
                break;

        }



    }catch(char const*mensaje){
        cerr << mensaje;
    }


    return 0;
}
