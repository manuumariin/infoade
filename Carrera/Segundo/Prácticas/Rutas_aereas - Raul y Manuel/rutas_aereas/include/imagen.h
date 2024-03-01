/**
 * @file imagen.h
 * @author Raúl Martínez Bustos y Manuel Marín Rodríguez.
 */

#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include <cassert>
#include <iostream>
#include <string>

/**
* @brief Tipo de pegado
* Existen dos tipos de pegado, aquí se declaran
*/
enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;


/**
 * @brief Pixel
 * Crea un pixel con sus datos necesarios
 */
struct Pixel {
/**
 * @brief r
 * Color rojo(red)
 */
  unsigned char r;

/**
 * @brief g
 * Color verde(green)
 */
  unsigned char g;

/**
 * @brief b
 * Color azul(blue)
 */
  unsigned char b;

/**
 * @brief transparencia
 * Para las imágenes y máscaras, el grado de transparencia de una imagen irá también de 0 a 255.
 */
  unsigned char transparencia;

};



/**
 * @class Imagen
 * @brief Imagen, ya sea pgm o ppm.
 */
class Imagen{
  private:
    Pixel **data; ///< Matriz de píxeles que representa la imagen.
    int nf;      ///< Número de filas de la imagen.
    int nc;      ///< Número de columnas de la imagen.

    /**
     * @brief Libera la memoria utilizada por la matriz de píxeles.
     */
    void deallocate_array();

    /**
     * @brief Copia el contenido de otra instancia de Imagen.
     *
     * @param other Instancia de Imagen a copiar.
     */
    void copy_array(const Imagen &other);

  public:
    /**
    * @brief Constructor por defecto.
    */
    Imagen();
    /**
     * @brief Constructor con parametros.
     * @param numf Cantidad de filas.
     * @param numc Cantidad de columnas.
     */
    Imagen(int f,int c);

    /**
     * @brief Operador de asignacion.
     * @param I Imagen que se copia.
     * @return I Imagen que se pasa.
     */
    Imagen & operator=(const Imagen & I);

    /**
     * @brief Destructor.
     */
    ~Imagen();

    /**
     * @brief Operador de indexacion
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Pixel (i,j).
     */
    Pixel & operator ()(int i,int j);

    /**
     * @brief Operador de indexacion
     * @param i Fila del pixel.
     * @param j Columna del pixel.
     * @return Pixel (i,j).
     */
    const Pixel & operator ()(int i,int j)const;

    /**
     * @brief Escribe una imagen a PGM o PPM.
     * @param img_path Nombre.
     */
    bool Escribir(const char * nombre);

    /**
     * @brief Lee una imagen de un archivo PGM o PPM.
     * @param img_path Nombre.
     * @param mascara_path Mascara.
     */
    bool Leer(const char * nombre,const string &nombremascara="");

    /**
     * @brief Elimina la imagen con todo lo que haya.
     */
    void LimpiarTransp();

    /**
     * @brief Devuelve el numero de filas.
     * @return nf.
     */
    int GetFilas() const;

    /**
     * @brief Devuelve el numero de columnas.
     * @return nc.
     */
    int GetCols() const;
    /**
    * @brief Devuelve el tamaño de la imagen.
    * @return Numero.
    */
    int GetSize() const;

    /**
    * @brief Devuelve el tamaño de la imagen a color.
    * @return Numero.
    */
    int GetSizecolors() const;

    /**
     * @brief Coloca una imagen en la posicion dada.
     * @param i Fila de la imagen.
     * @param j Columna de la imagen.
     * @param img Imagen.
     * @param tp Tipo de pegado.
     */
    void PegarImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

    /**
    * @brief Devuelve una subimagen.
    * @param i Fila de la imagen.
    * @param j Columna de la imagen.
    * @param dim_i Ancho de la subimagen.
    * @param dim_j Alto de la subimagen.
    * @return Subimagen a devolver.
    */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);

};   
   
#endif
