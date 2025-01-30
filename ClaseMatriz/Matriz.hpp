#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>
/**

 * \file Matriz.hpp

 * Este archivo declara las clases y sus metodos, incluyendo metodos auxiliares

 * \author Flor Machado y Elias Peregrina

 * \date 30/01/2025

 */


/**

 *Clase Matriz
 Esta clase simula una matriz
 Sus atributos son:
 int renglones,
 int columnas,
 double ** componentes

 Sus metodos hacen ooperaciones que se les pueden realizar a las matrices,
 Como suma, resta, multiplicacion, etc.
 */ class Matriz {

    /** \brief M&eacute;todo que ingresa los componentes de una matriz
     *
     * \param entrada std::istream&
     * \param v Matriz& La direcci&oacute;n de la matriz
     * \return  std::istream&
     *
     */friend std::istream &operator>>(std::istream &entrada, Matriz &v);

    /** \brief M&eacute;todo que imprime los componentes de una matriz
     *
     * \param salida std::ostream&
     * \param v const Matriz& La direcci&oacute;n de la matriz
     * \return std::ostream&
     *
     */
    friend std::ostream &operator<<(std::ostream &salida, const Matriz &v);


    /** \brief M&eacute;todo no miembro de la clase que multiplica una matriz con un n&uacute;mero escalar
     *
     * \param escalar double, el escalar por el que se va a multiplicar
     * \param v Matriz, Matriz por la que se multiplicar&aacute; el escalar
     * \return Matriz, Devuelve una matriz con la operaci&oacute;n ya realizada
     *
     */
    friend Matriz operator* (double escalar, const Matriz v);
public:


    /** \brief Constructor de la clase
     *
     * \param int reng, la cantidad de renglones que tiene la matriz, por default es uno
     * \param int col, la cantidad de columnas que tiene la matriz, por default es uno
     * \throw Excepcion que tira cuando no se ha asignado la memoria correctamente
     */
    Matriz(int reng = 1, int col = 1);


    /** \brief Destructor de la clase Matriz
     *
     *
     */
    ~Matriz();

    Matriz(const Matriz &otra);

    Matriz &operator=(const Matriz &otra);

    Matriz operator*(double escalar) const;

    Matriz transponida() const;

    Matriz invertida() const;


    /** \brief M&eacute;todo que suma dos matrices
     *
     * \param v const Matriz, matriz con la que se va a sumar el objeto de la clase
     * \return Matriz, resultado de sumar las dos matrices
     * \throw Excepci&oacute;n que tira cuando eln tama&ntilde;o de las matrices no es compatible
     */
    Matriz operator+(const Matriz v) const;


    /** \brief M&eacute;todo que resta dos matrices
     *
     * \param v const Matriz, matriz con la que se va a restar el objeto de la clase
     * \return Matriz, resultado de restar las dos matrices
     * \throw Excepci&oacute;n que tira cuando eln tama&ntilde;o de las matrices no es compatible
     */
    Matriz operator-(const Matriz v) const;


    /** \brief M&eacute;todo que redimensiona una matriz,
        Si es una tama&ntilde;o m&aacute;s chico, lo trunca,
     *  Si es m&aacute;s grande, a&ntilde;ade 0
     * \param reng int El n&uacute;mero de renglones al que deseas redimensionar
     * \param col int El n&uacute;mero de columnas al que deseas redimensionar
     * \return Matriz, Devuelve la matriz redimensionada
     *
     */
    Matriz Redimensionar(int reng, int col) const;

    Matriz operator*(const Matriz v) const ;


private:
    int renglones;
    int columnas;
    double **componente;


};

/** \brief M&eacute;todo que verifica que si se haya ingresado un n&uacute;mero entero
 *
 * \param solicitud[] const char, instrucci&oacute;n de que tipo de dato  es el admitido
 * \return int Devuelve el n&uacute;mero despu&eacute;s de la verificaci&oacute;n
 *
 */
int Capturarentero(const char solicitud[]);

#endif //MATRIZ_HPP_INCLUDED
