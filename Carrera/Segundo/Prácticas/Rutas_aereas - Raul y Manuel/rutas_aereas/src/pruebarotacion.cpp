#include <iostream>
#include <cstdlib>
#include <cmath>

#include "imagen.h"

using namespace std;

/**
 * @brief Obtiene una nueva imagen que es la versión rotada de una imagen de entrada.
 * @param img: imagen de entrada.
 * @param angulo: angulo a rotar la imagen de entrada. Debe estar en radianes.
 * @return Una nueva imagen que es la versión rotada de img.
 * */
Imagen rotar(const Imagen &img, double angulo){
        angulo= (angulo * M_PI)/180;
        double rads=angulo;
        double coseno = cos(angulo);
        double seno = sin(angulo);
        //Para obtener las dimensiones de la imagen
        int rcorners[4],ccorners[4];
        int newimgrows,newimgcols;
        double new_row_min,new_col_min,new_row_max,new_col_max;
        double inter,inter1;
        rcorners[0]=0;
        rcorners[1]=0;
        ccorners[0]=0;
        ccorners[2]=0;
        rcorners[2]=img.GetFilas()-1;
        rcorners[3]=img.GetFilas()-1;
        ccorners[1]=img.GetCols()-1;
        ccorners[3]=img.GetCols()-1;
        new_row_min=0;
        new_col_min=0;
        new_row_max=0;
        new_col_max=0;
        newimgrows=0;
        newimgcols=0;
        for(int count=0;count<4;count++)
        {
            inter=rcorners[count]*coseno+ccorners[count]*seno;

            if(inter<new_row_min)
                new_row_min=inter;
            if(inter>new_row_max)
                new_row_max=inter;
            inter1=-rcorners[count]*seno+ccorners[count]*coseno;

            if(inter1<new_col_min)
                new_col_min=inter1;
            if(inter1>new_col_max)
                new_col_max=inter1;
        }

        newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
        newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);

        Imagen Iout(newimgrows,newimgcols);
        for(int rows=0;rows<newimgrows;rows++)
        {
            for(int cols=0;cols<newimgcols;cols++)
            {
                float oldrowcos=((float)rows+new_row_min)*cos(-rads);
                float oldrowsin=((float)rows+new_row_min)*sin(-rads);
                float oldcolcos=((float)cols+new_col_min)*cos(-rads);
                float oldcolsin=((float)cols+new_col_min)*sin(-rads);
                float old_row=oldrowcos+oldcolsin;
                float old_col=-oldrowsin+oldcolcos;
                old_row=ceil((double)old_row);
                old_col=ceil((double)old_col);
                if((old_row>=0)&&(old_row<img.GetFilas())&&
                   (old_col>=0)&&(old_col<img.GetCols()))
                {
                    Iout(rows,cols)=img(old_row,old_col);

                }
                else
                    Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
                    Iout(rows,cols).transparencia=0;
            }
        }
        return Iout;

    }


int main(int argc, char *argv[])
{
  if (argc != 4 ){
    cerr << "Uso: pruebarotacion <img_original> <angulo_rotacion> <img_rotada>" << endl;
    return 1;
  }else {
    double angulo=stod(argv[2]);

      Imagen img_rotada;
      if(img_rotada.Leer(argv[1])){
          // Rotar imagen
          //angulo = (angulo * M_PI)/180; (Ya lo hace la función Imagen rotar(), pues se lo he preferido implementar al principio en vez de aquí en el main)
          img_rotada=rotar(img_rotada, angulo);

          // Guardar imagen rotada
          // ...
          if(img_rotada.Escribir(argv[3])){
              ;   //Todo ha salido correctamente
          }
          else{
              cerr<<"Ha habido un problema en la escritura de "<< argv[3] << endl;
              exit(1);
          }
      }
      else{
          cerr<<"Ha habido un problema en la lectura de "<< argv[1] <<endl;
          exit(1);
      }
  }
  return 0;
}