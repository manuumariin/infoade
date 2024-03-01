/**
 * @brief T.D.A. Ruta
 *
 * Se crea un objeto de la clase Ruta que representa una ruta formada por una
 * serie de puntos geográficos con su código identificador
 *
 * @author Raúl Martínez Bustos y Manuel Marín Rodríguez
 * @date Diciembre 2023
 */
#ifndef _RUTA_
#define _RUTA_

#include "punto.h"
#include <list>
#include <string>
#include <cassert>


using namespace std;

class Ruta {

private:

    string code; ///< código identificador de la ruta
    int numpuntos; ///< miembro auxiliar que hemos decidido implementar en el private para simplificar código, pero realmente no es obligatorio ni necesario.
    list<Punto> puntos; ///< lista de puntos geográficos de la ruta


public:
    /**
     * @brief Constructor por defecto de la clase. Crea la ruta ("",[])
     */
    Ruta() {}

    /**
     * @brief Constructor de la clase
     * @param cod código identificador de la ruta
     * @param pts lista de puntos geográficos de la ruta
     * @pre RX != "" && puntos.size() > 0
     */
    Ruta(string cod, list<Punto> pts);

    /**
     * @brief Constructor de copia de la clase
     * @param rut otra ruta
     * @post La ruta actual es una copia exacta de la ruta r
     */
    Ruta(const Ruta &rut);

    /**
     * @brief Obtiene el punto geográfico de la ruta en una posición determinada
     * @param p índice del punto en la lista de puntos
     * @return El punto geográfico correspondiente al índice x
     * @pre 0 <= x < puntos.size()
     */
    Punto GetPunto(int p);

    /**
     * @brief Compara si la ruta actual es igual que otra
     * @param copia otra ruta
     * @return true si la ruta actual tiene el mismo código y los mismos puntos que la otra, false en caso contrario
     */
    bool operator==(const Ruta &copia);

    /**
     * @brief Compara si la ruta actual es igual que otra
     * @param copia otra ruta
     * @return true si la ruta actual tiene el mismo código y los mismos puntos que la otra, false en caso contrario
     */
    bool operator==(const Ruta &copia) const;

    /**
     * @brief Compara si la ruta actual es igual que otra
     * @param  c código de la ruta
     * @return true si la ruta actual tiene el mismo código y los mismos puntos que la otra, false en caso contrario
     */
    bool operator==(const string &c);


    /**
     * @brief Compara si la ruta actual es igual que otra
     * @param  c código de la ruta
     * @return true si la ruta actual tiene el mismo código y los mismos puntos que la otra, false en caso contrario
     */
    bool operator==(const string &c) const;


    /**
     * @brief Compara si la ruta actual contiene un punto
     * @param p punto geográfico
     * @return true si la ruta actual contiene el punto p, false en caso contrario
     */
    bool operator==(const Punto &p);


    /**
     * @brief Compara si la ruta actual contiene un punto
     * @param p punto geográfico
     * @return true si la ruta actual contiene el punto p, false en caso contrario
     */
    bool operator==(const Punto &p) const;


    /**
     * @brief Compara si la ruta actual es menor que otra
     * @param rut otra ruta
     * @return true si la ruta actual tiene un código alfabéticamente menor que el de la otra, false en caso contrario
     */
    bool operator<(const Ruta & rut);


    /**
     * @brief Compara si la ruta actual es menor que otra
     * @param rut otra ruta
     * @return true si la ruta actual tiene un código alfabéticamente menor que el de la otra, false en caso contrario
     */
    bool operator<(const Ruta & rut) const;

    /**
     * @brief Compara si la ruta actual es mayor que otra
     * @param rut otra ruta
     * @return true si la ruta actual tiene un código alfabéticamente mayor que el de la otra, false en caso contrario
     */
    bool operator>(const Ruta & rut);


    /**
     * @brief Compara si la ruta actual es mayor que otra
     * @param rut otra ruta
     * @return true si la ruta actual tiene un código alfabéticamente mayor que el de la otra, false en caso contrario
     */
    bool operator>(const Ruta & rut) const;



    /**
     * @brief Clase para iterar sobre los puntos de la ruta
     */
    class iterator{
    private:
        list<Punto>::iterator p; ///< iterador sobre la lista de puntos

    public:

        /**
         * @brief Constructor por defecto
         */
        iterator(){}

        /**
         * @brief Avanza el iterador una posición
         * @return Una referencia al iterador
         */
        iterator & operator ++(){
            ++p;
            return * this;
        }

        /**
         * @brief Retrocede el iterador una posición
         * @return Una referencia al iterador
         */
        iterator & operator --(){
            --p;
            return * this;
        }

        /**
         * @brief Asigna el valor de otro iterador al iterador actual
         * @param aux otro iterador
         * @return Una referencia al iterador
         */
        iterator & operator = (const iterator & aux) {
            p = aux.p;
            return *this;
        }

        /**
         * @brief Compara si el iterador actual es igual que otro
         * @param aux otro iterador
         * @return true si los iteradores apuntan al mismo punto, false en caso contrario
         */
        bool operator ==(const iterator  & aux){
            return aux.p ==p;
        }

        /**
         * @brief Compara si el iterador actual es distinto que otro
         * @param aux otro iterador
         * @return true si los iteradores apuntan a puntos distintos, false en caso contrario
         */
        bool operator !=(const iterator  & aux){
            return aux.p !=p;
        }

        /**
         * @brief Devuelve el punto al que apunta el iterador
         * @return Una referencia constante al punto
         */
        const Punto & operator*()const{
            return *p;
        }

        friend class Ruta;
        friend class const_iterator;

    };



    /**
     * @brief Clase para iterar sobre los puntos de la ruta de forma constante
     */
    class const_iterator{
    private:

        list<Punto>::const_iterator p; ///< iterador constante sobre la lista de puntos

    public:

        /**
         * @brief Constructor por defecto
         */
        const_iterator(){}

        /**
         * @brief Constructor a partir de un iterador no constante
         * @param aux un iterador no constante
         */
        const_iterator(const iterator & aux){
            p=aux.p;
        }

        /**
         * @brief Asigna el valor de un iterador no constante al iterador constante actual
         * @param aux un iterador no constante
         * @return Una referencia al iterador constante
         */
        const_iterator & operator=(const iterator & aux){
            p=aux.p;
            return *this;
        }

        /**
         * @brief Avanza el iterador una posición
         * @return Una referencia al iterador constante
         */
        const_iterator & operator ++(){
            ++p;
            return * this;
        }

        /**
         * @brief Retrocede el iterador una posición
         * @return Una referencia al iterador constante
         */
        const_iterator & operator --(){
            --p;
            return * this;
        }

        /**
         * @brief Compara si el iterador constante actual es igual que otro
         * @param aux otro iterador constante
         * @return true si los iteradores apuntan al mismo punto, false en caso contrario
         */
        bool operator ==(const const_iterator  & aux){
            return aux.p == p;
        }

        /**
         * @brief Compara si el iterador constante actual es distinto que otro
         * @param aux otro iterador constante
         * @return true si los iteradores apuntan a puntos distintos, false en caso contrario
         */
        bool operator !=(const const_iterator  & aux){
            return aux.p != p;
        }

        /**
         * @brief Devuelve el punto al que apunta el iterador constante
         * @return Una referencia constante al punto
         */
        const Punto &operator*()const {
            return *p;
        }

        friend class Ruta;

    };

    /**
     * @brief Devuelve un iterador al primer punto de la ruta
     * @return Un iterador que apunta al primer punto de la ruta
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador constante al primer punto de la ruta
     * @return Un iterador constante que apunta al primer punto de la ruta
     */
    const_iterator begin()const;

    /**
     * @brief Devuelve un iterador al final de la ruta
     * @return Un iterador que apunta al final de la ruta
     */
    iterator end();

    /**
     * @brief Devuelve un iterador constante al final de la ruta
     * @return Un iterador constante que apunta al final de la ruta
     */
    const_iterator end()const;

    /**
     * @brief Busca un punto en la ruta
     * @param p el punto a buscar
     * @return Un iterador que apunta al punto encontrado, o end() si no se encuentra
     */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de inserción
     * @param os flujo de salida
     * @param rut ruta a escribir
     * @post Se escribe la ruta en el formato "Código Número_de_puntos Punto1 Punto2 ..."
     * @return El flujo de salida
     */
    friend ostream &operator<<(ostream &os, const Ruta &rut);

    /**
     * @brief Sobrecarga del operador de extracción
     * @param is flujo de entrada
     * @param rut ruta a leer
     * @pre El formato de lectura es el mismo que el de escritura
     * @post Se lee la ruta desde el flujo de entrada
     * @return El flujo de entrada
     */
    friend istream & operator>>(istream &is , Ruta & rut);
};

#endif

