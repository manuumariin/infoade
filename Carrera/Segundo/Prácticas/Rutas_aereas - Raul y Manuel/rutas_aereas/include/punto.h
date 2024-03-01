/**
* @file punto.h
* @brief Fichero cabecera del TDA Punto
*
* Se crea un objeto de la clase Punto que representa un punto geográfico
* con su latitud, longitud y descripción
* @authors Raúl Martínez Bustos y Manuel Marín Rodríguez
*/

#ifndef _PUNTO_

#define _PUNTO_

#include <iostream>

using namespace std;

/**
 * @brief T.D.A. Punto
 *
 * Una instancia @e p del tipo de datos abstracto @c Punto es un objeto
 * que representa un punto geográfico con su latitud, longitud y descripción.
 * Se representa como latitud,longitud,descripcion
 *
 */

class Punto {
    
    private:
        double latitud; ///< latitud del punto
        double longitud; ///< longitud del punto
        char magic_char; ///< descripción del punto  ---> Esto nos dio una increible cantidad de problemas de bad_alloc() cuando estaba como string descripcion,
                       ///< así que decidimos cambiarlo por dato magic_char, ya que era lo que podía hacer que funcionase el programa.

    public:
        /**
         * @brief Constructor por defecto de la clase. Crea el punto (0,0,"")
        */
        Punto();

         /**
         * @brief Constructor de la clase
         * @param lat latitud del punto
         * @param lon longitud del punto
         * @param des descripción del punto
         * @pre lat >= -90 && lat <= 90 && lon >= -180 && lon <= 180
         */
        Punto(double lat, double lon, char magicchar);

        /**
         * @brief Constructor de copia de la clase Punto.
         *
         * Crea una instancia de Punto copiando los valores de otro punto.
         *
         * @param p Punto a copiar.
         */
        Punto(const Punto &p);

         /**
         * @brief Modifica la latitud del punto
         * @param lat nueva latitud del punto
         * @pre lat >= -90 && lat <= 90
         */
        void SetLat(double lat);

        /**
         * @brief Modifica la longitud del punto
         * @param lon nueva longitud del punto
         * @pre lon >= -180 && lon <= 180
         */
        void SetLon(double lon);
        /**
         * @brief Modifica la descripción del punto
         * @param magicchar nueva descripción del punto
         * @pre Debe ser tipo char
         */
        void SetDesc(char magicchar);
         /**
         * @brief Devuelve la latitud del punto
         * @return la latitud del punto
         */
        double GetLat() const;

        /**
         * @brief Devuelve la longitud del punto
         * @return la longitud del punto
         */
        double GetLong() const;

        /**
         * @brief Devuelve la descripción(magic_char) del punto
         * @return la descripción(magic_char) del punto
         */
        char GetDesc() const;

        /**
         * @brief Compara si el punto actual es igual que otro
         * @param p otro punto
         * @return true si el punto actual tiene la misma latitud y longitud que el otro,
         * false en caso contrario
         */
        bool operator==(const Punto & p) const;

        /**
        * @brief Compara si el punto actual es menor que otro
        * @param p otro punto
        * @return true si el punto actual tiene menor latitud que el otro,
        * o si tienen la misma latitud, si tiene menor longitud que el otro,
        * false en caso contrario
        */
        bool operator<(const Punto & p) const;

        /**
         * @brief Compara si el punto actual es mayor que otro
         * @param p otro punto
         * @return true si el punto actual tiene mayor latitud que el otro,
         * o si tienen la misma latitud, si tiene mayor longitud que el otro,
         * false en caso contrario
         */
        bool operator>(const Punto & p) const;

        /**
        * @brief Operador de salida de flujo
        * @param os flujo de salida
        * @param p punto a escribir
        * @return una referencia al flujo de salida
        */
        friend ostream & operator<<(ostream &os, const Punto &p);

        /**
        * @brief Operador de entrada de flujo
        * @param is flujo de entrada
        * @param p punto a leer
        * @return una referencia al flujo de entrada
        */
        friend istream & operator>>(istream &is, Punto &p);
};

#endif //PRACTICAFINAL_PUNTO_H
