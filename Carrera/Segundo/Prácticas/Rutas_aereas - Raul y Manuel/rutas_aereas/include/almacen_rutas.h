
/**
 * @brief T.D.A. Almacen_Rutas
 *
 * Almacen_Rutas es un objeto que representa un conjunto de rutas, cada
 * una con su código identificador y una serie de puntos geográficos.
 * Además, almacena una serie de puntos prioritarios con su nombre asociado.
 *
 * @author Raúl Martínez Bustos y Manuel Marín Rodríguez
 * @date Diciembre 2023
 */

#ifndef _RUTAS_
#define _RUTAS_

#include "ruta.h"
#include <set>
#include <map>

using namespace std;

class Almacen_Rutas{
private:
    set<Ruta> datos; ///< conjunto de rutas
    int npri; ///< número de puntos prioritarios
    map<Punto, string> puntospri; ///< mapa de puntos prioritarios y sus nombres

public:

    /**
     * @brief Obtiene una ruta dado su código
     * @param a código de la ruta
     * @return La ruta correspondiente al código, o una ruta vacía si no existe
     */
    Ruta GetRuta(const string a);

    /**
     * @brief Constructor por defecto de la clase. Crea el almacén vacío
     */
    Almacen_Rutas(){}

    /**
     * @brief Inserta una ruta en el almacén
     * @param R ruta a insertar
     * @post El almacén contiene la ruta R
     */
    void Insertar(const Ruta &R);

    /**
     * @brief Borra una ruta del almacén
     * @param R ruta a borrar
     * @post El almacén no contiene la ruta R
     */
    void Borrar(const Ruta &R);

    /**
     * @brief Clase para iterar sobre las rutas del almacén
     */
    class iterator{
    private:

        set<Ruta>::iterator r; ///< iterador sobre el conjunto de rutas

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
            ++r;
            return * this;
        }

        /**
         * @brief Retrocede el iterador una posición
         * @return Una referencia al iterador
         */
        iterator & operator --(){
            --r;
            return * this;
        }

        /**
         * @brief Asigna el valor de otro iterador al iterador actual
         * @param it otro iterador
         * @return Una referencia al iterador
         */
        iterator & operator = (const iterator & it) {
            r = it.r;
            return *this;
        }

        /**
         * @brief Compara si el iterador actual es igual que otro
         * @param it otro iterador
         * @return true si los iteradores apuntan a la misma ruta, false en caso contrario
         */
        bool operator ==(const iterator  & it){
            return it.r ==r;
        }

        /**
         * @brief Compara si el iterador actual es distinto que otro
         * @param it otro iterador
         * @return true si los iteradores apuntan a rutas distintas, false en caso contrario
         */
        bool operator !=(const iterator  & it){
            return it.r !=r;
        }

        /**
         * @brief Devuelve la ruta a la que apunta el iterador
         * @return Una referencia constante a la ruta
         */
        const Ruta & operator*()const{
            return *r;
        }

        /**
         * @brief Declara la clase Almacen_Rutas como amiga de la clase iterator
         * @note Esto permite acceder a los atributos privados de la clase iterator desde la clase Almacen_Rutas
         */
        friend class Almacen_Rutas;

        /**
         * @brief Declara la clase const_iterator como amiga de la clase iterator
         * @note Esto permite convertir un iterador no constante en uno constante
         */
        friend class const_iterator;

    };

    /**
     * @brief Clase para iterar sobre las rutas del almacén de forma constante
     */
    class const_iterator{
    private:

        set<Ruta>::const_iterator r; ///< iterador constante sobre el conjunto de rutas

    public:

        /**
         * @brief Constructor por defecto
         */
        const_iterator(){}

        /**
         * @brief Constructor a partir de un iterador no constante
         * @param it un iterador no constante
         */
        const_iterator(const iterator & it){
            r=it.r;
        }

        /**
         * @brief Asigna el valor de un iterador no constante al iterador constante actual
         * @param it un iterador no constante
         * @return Una referencia al iterador constante
         */
        const_iterator & operator=(const iterator & it){
            r=it.r;
            return *this;
        }

        /**
         * @brief Avanza el iterador una posición
         * @return Una referencia al iterador constante
         */
        const_iterator & operator ++(){
            ++r;
            return * this;
        }

        /**
         * @brief Retrocede el iterador una posición
         * @return Una referencia al iterador constante
         */
        const_iterator & operator --(){
            --r;
            return * this;
        }

        /**
         * @brief Compara si el iterador constante actual es igual que otro
         * @param it otro iterador constante
         * @return true si los iteradores apuntan a la misma ruta, false en caso contrario
         */
        bool operator ==(const const_iterator  & it){
            return it.r ==r;
        }

        /**
         * @brief Compara si el iterador constante actual es distinto que otro
         * @param it otro iterador constante
         * @return true si los iteradores apuntan a rutas distintas, false en caso contrario
         */
        bool operator !=(const const_iterator  & it){
            return it.r !=r;
        }

        /**
         * @brief Devuelve la ruta a la que apunta el iterador constante
         * @return Una referencia constante a la ruta
         */
        const Ruta &operator*()const {
            return *r;
        }

        /**
         * @brief Declara la clase Almacen_Rutas como amiga de la clase const_iterator
         * @note Esto permite acceder a los atributos privados de la clase const_iterator desde la clase Almacen_Rutas
         */
        friend class Almacen_Rutas;

    };

    /**
     * @brief Devuelve un iterador al principio del almacén
     * @return Un iterador que apunta a la primera ruta del almacén
     */
    iterator begin();

    /**
     * @brief Devuelve un iterador constante al principio del almacén
     * @return Un iterador constante que apunta a la primera ruta del almacén
     */
    const_iterator begin()const;

    /**
     * @brief Devuelve un iterador al final del almacén
     * @return Un iterador que apunta al final del almacén
     */
    iterator end();

    /**
     * @brief Devuelve un iterador constante al final del almacén
     * @return Un iterador constante que apunta al final del almacén
     */
    const_iterator end()const;

    /**
     * @brief Busca una ruta en el almacén
     * @param r la ruta a buscar
     * @return Un iterador que apunta a la ruta encontrada, o end() si no se encuentra
     */
    iterator find(const Ruta &r);

    /**
     * @brief Sobrecarga del operador de extracción
     * @param is flujo de entrada
     * @param R almacén de rutas a leer
     * @pre El formato de lectura es el mismo que el de escritura
     * @post Se lee el almacén de rutas desde el flujo de entrada
     * @return El flujo de entrada
     */
    friend istream & operator>>(istream & is, Almacen_Rutas & R);

    /**
     * @brief Sobrecarga del operador de inserción
     * @param os flujo de salida
     * @param R almacén de rutas a escribir
     * @post Se escribe el almacén de rutas en el flujo de salida
     * @return El flujo de salida
     */
    friend ostream & operator<<(ostream & os, const Almacen_Rutas &R);
};

#endif
