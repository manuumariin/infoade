
/**
 * @file paises.h
 * @brief Fichero cabecera del TDA Paises
 *
 * Se crea un conjunto de objetos de la clase Pais
 * @authors Raúl Martínez y Manuel Marín
 */

#ifndef _PAISES_
#define _PAISES_

#include "pais.h"
#include <set>

using namespace std;

/**
 * @brief T.D.A. Paises
 *
 * Una instancia @e c del tipo de datos abstracto @c Paises es un objeto
 * que representa un conjunto de países, cada uno con sus datos geográficos
 * y demográficos. Internamente se implementa como un conjunto ordenado
 * de objetos de la clase Pais.
 *
 */


class Paises{
  	private:
    	set<Pais> datos; ///< conjunto de países

  	public:

        /**
         * @brief Constructor por defecto de la clase. Crea un objeto vacío.
         */
    	Paises(){}

        /**
         * @brief Inserta un país en el conjunto
         * @param P país a insertar
         */
    	void Insertar(const Pais &P);

        /**
         * @brief Borra un país del conjunto
         * @param P país a borrar
         */
      	void Borrar(const Pais &P);

      	/**
        * @brief Clase para iterar sobre los países
        */
		class iterator{
			private:
			    set<Pais>::iterator p; ///< puntero al conjunto

			public:

                 /**
                 * @brief Constructor por defecto
                 */
			    iterator(){}

                /**
                 * @brief Operador de pre-incremento
                 * @return una referencia al iterador incrementado
                 */
			    iterator & operator ++(){
					++p;
					return * this;
			    }

                /**
                 * @brief Operador de pre-decremento
                 * @return una referencia al iterador decrementado
                 */
			    iterator & operator --(){
					--p;
					return * this;
			    }

                /**
                 * @brief Operador de asignación
                 * @param it iterador a asignar
                 * @return una referencia al iterador asignado
                 */
				iterator & operator=(const iterator & it) {
					p = it.p;
					return *this;
				}

                /**
                 * @brief Operador de igualdad
                 * @param it iterador a comparar
                 * @return true si los iteradores apuntan al mismo país, false en caso contrario
                 */
			    bool operator ==(const iterator  & it){
					return it.p ==p;
			    }

                /**
                * @brief Operador de desigualdad
                * @param it iterador a comparar
                * @return true si los iteradores apuntan a países distintos, false en caso contrario
                */
			    bool operator !=(const iterator  & it){
					return it.p !=p;
			    }

                /**
                 * @brief Operador de indirección
                 * @return una referencia al país al que apunta el iterador
                 */
			    const Pais & operator*()const{
					return *p;
			    }

			    friend class Paises;
			    friend class const_iterator;

		};

        /**
         * @brief Clase para iterar sobre los países (modo constante)
         */
		class const_iterator{
			private:
			    set<Pais>::const_iterator p; ///< puntero al conjunto

			public:
                /**
                 * @brief Constructor por defecto
                 */
			    const_iterator(){}

                /**
                 * @brief Constructor de copia
                 * @param it iterador a copiar
                 */
			    const_iterator(const iterator & it){
			    	p=it.p;
			    }

                /**
                 * @brief Operador de asignación
                 * @param it iterador a asignar
                 * @return una referencia al iterador asignado
                 */
			    const_iterator & operator=(const iterator & it){
					p=it.p;
					return *this;
			    }

                /**
                 * @brief Operador de pre-incremento
                 * @return una referencia al iterador incrementado
                 */
			    const_iterator & operator ++(){
					++p;
					return * this;
			    }

                /**
                 * @brief Operador de pre-decremento
                 * @return una referencia al iterador decrementado
                 */
			    const_iterator & operator --(){
					--p;
					return * this;
			    }

                /**
                 * @brief Operador de igualdad
                 * @param it iterador a comparar
                 * @return true si los iteradores apuntan al mismo país, false en caso contrario
                 */
			    bool operator ==(const const_iterator  & it){
					return it.p ==p;
			    }

                /**
                 * @brief Operador de desigualdad
                 * @param it iterador a comparar
                 * @return true si los iteradores apuntan a países distintos, false en caso contrario
                 */
			    bool operator !=(const const_iterator  & it){
					return it.p !=p;
			    }

                /**
                 * @brief Operador de indirección
                 * @return una referencia al país al que apunta el iterador
                 */
			    const Pais &operator*()const {
					return *p;
			    }

			    friend class Paises;
		};
        /**
         * @brief Inicializa un iterador al primer país
         * @return un iterador al primer país
         */
		iterator begin();

        /**
         * @brief Inicializa un iterador constante al primer país
         * @return un iterador constante al primer país
         */
		const_iterator begin()const;

        /**
         * @brief Inicializa un iterador al final del conjunto
         * @return un iterador al final del conjunto
         */
		iterator end();

        /**
         * @brief Inicializa un iterador constante al final del conjunto
         * @return un iterador constante al final del conjunto
         */
		const_iterator end()const;

        /**
         * @brief Busca un país en el conjunto
         * @param p país a buscar
         * @return un iterador al país encontrado, o end() si no se encuentra
         */
		iterator find(const Pais &p);

        /**
        * @brief Busca un país por su punto geográfico
        * @param p punto geográfico a buscar
        * @return un iterador al país encontrado, o end() si no se encuentra
        */
		iterator find(const Punto &p);

        /**
         * @brief Operador de salida de flujo
         * @param os flujo de salida
         * @param ps conjunto de países a escribir
         * @return una referencia al flujo de salida
         */
		friend istream & operator>>(istream & is, Paises & R);

        /**
         * @brief Operador de entrada de flujo
         * @param is flujo de entrada
         * @param R conjunto de países a leer
         * @return una referencia al flujo de entrada
         */
		friend ostream & operator<<(ostream & os, const Paises &R);
};
#endif
