/**
 * @file Pais.h
 * @author Raúl Martínez y Manuel Rodríguez
 */
#ifndef _PAIS_
#define _PAIS_

#include "punto.h"

using namespace std;
/**
 * @class Pais
 * @brief Clase que simboliza un país.
 */

class Pais{
  private:

    Punto p;       ///< Punto geográfico que representa la posición del país.
    string pais;   ///< Nombre del país.
    string bandera;///< Nombre de archivo de la bandera del país.
    
  public:
    /**
     * @brief Constructor por defecto.
     */
    Pais();

    /**
     * @brief Establece la posición geográfica del país.
     *
     * @param punt Punto geográfico que representa la posición del país.
     */
    void SetPunto(Punto punt);

    /**
     * @brief Establece el nombre del país.
     *
     * @param country Nombre del país.
     */
    void SetPais(string country);

    /**
     * @brief Establece el nombre de archivo de la bandera del país.
     *
     * @param flag Nombre de archivo de la bandera.
     */
    void SetBandera(string flag);

    /**
     * @brief Devuelve el punto donde está.
     * @return Punto del mapa del país
     */
    Punto GetPunto()const;

    /**
     * @brief Devuelve el pais.
     * @return Nombre.
     */
    string GetPais()const;

    /**
     * @brief Devuelve la bandera.
     * @return Bandera del pais.
     */
    string GetBandera()const;

    /**
    * @brief Operador relacional "menor".
    * @param P Pais que se compara.
    * @return True si el nombre del pais P es menor que el otro
    * y False si no.
    */
    bool operator<(const Pais &P)const;

    /**
    * @brief Operador relacional "mayor".
    * @param P Pais que se compara.
    * @return True si el nombre del pais P es mayor que el otro
    * y False si no.
    */
    bool operator>(const Pais &P) const;

    /**
    * @brief Operador de igualdad.
    * @param P País que se compara.
    * @return True si los nombres son iguales y False si no.
    **/
    bool operator==(const Pais &P)const;

    /**
    * @brief Operador de igualdad.
    * @param P Punto que se compara.
    * @return True si los nombres son iguales y False si no.
    **/
    bool operator==(const Punto &P)const;

    /**
    * @brief Operador de entrada. Lee un pais.
    * @param is Flujo de entrada.
    * @param P Pais que se lee.
    * @return Flujo de entrada "is".
    */
    friend istream & operator>>(istream & is, Pais & P);

    /**
    * @brief Operador de salida.
    * @param os Flujo de salida.
    * @param P Pais que se saca.
    * @return Flujo de salida "os".
    */
    friend ostream & operator<<(ostream & os, const Pais &P);

};

#endif
