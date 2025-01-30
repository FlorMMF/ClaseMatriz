#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main()
{
    int eleccion ;
    try{
        do{
            cout << "Programa que realiza operaciones de matrices" << endl;
            cout << "Ingrese la operaci\242n que quiere realizar antes de ingresar las matrices" << endl;
            cout << "1. Suma de matrices" << endl;
            cout << "2. Resta de matrices" << endl;
            cout << "3. Producto entre matrices" << endl;
            cout << "4. Producto por escalar" << endl;
            cout << "5. Transpuesta de una matriz" << endl;
            cout << "6. Inversa de una matriz" << endl;
            cout << "7. Redimensionar matriz" << endl;

            eleccion = Capturarentero("Ingrese el n\243mero que corresponda a la operaci\242n");

            while((eleccion > 7) || (eleccion < 1)){
                eleccion = Capturarentero("Ingrese el n\243mero que corresponda a la operaci\242n");
            }
            int Vn, Wn; //renglones
            int Vm, Wm; //columnas

            //Captura de los vectores ****************************************************

            Vn = Capturarentero("Ingrese la cantidad de renglones que tiene la primera matriz");

            Vm = Capturarentero("Ingrese la cantidad de columnas que tiene la primera matriz");
            Matriz  v(Vn,Vm);

            cout << "Ingrese los componentes de la primera matriz" << endl;
            cin >> v;

            if(eleccion == 3){
                Wn = Capturarentero("Ingrese la cantidad de renglones que tiene la segunda matriz");

                Wm = Capturarentero("Ingrese la cantidad de columnas que tiene la segunda matriz");

            }
            Matriz w(Vn,Vm);//Segunda matriz para suma y resta
            Matriz q(Vn,Vm);//Matriz resultante de la suma
             Matriz p(Vn,Vm);//Matriz resultante de la resta
            Matriz n(Vn,Vn);//Matriz resultante de la multiplicaci&oacute;n de matrices
            Matriz m(Wn,Wm);// Segunda matriz para multiplicaci&oacute;n entre matrices (se ingresa el tama&ntilde;o por separado)
            Matriz s(Vn,Vm); //Matriz resultante de multiplicaci&oacute;n por escalar

            double escalar;

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
                    //Multiplicaci&oacute;n por un escalar (m&eacute;todo no miembro de la clase)
                    escalar = Capturarentero("Ingrese el escalar por el que desea multiplicar la matriz");
                    s = escalar * v;
                    cout <<  endl << endl << v << endl << endl << "*" << endl << endl << escalar << endl << endl << "=" << endl << endl << s;
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                     //M&eacute;todo de redimensionamiento de una matriz ********************************
                    int Rn, Rm;

                    Rn = Capturarentero("Escribe la cantidad de renglones que tendr\240 tu matriz redimensionada");
                    Rm = Capturarentero("Escribe la cantidad de columnas que tendr\240 tu matriz redimensionada");
                    Matriz r(Rn, Rm);
                    r = v.Redimensionar(Rn,Rm);
                    cout << " Esta es la matriz redimensionada" << endl;
                    cout << r;
                    break;

            }

        eleccion = Capturarentero("Si desea salir presione 0, si quiere continuar realizando operaciones, presione otro n\243mero");
        }while(eleccion != 0);

    }catch(char const*mensaje){
        cerr << mensaje;
    }


    return 0;
}
