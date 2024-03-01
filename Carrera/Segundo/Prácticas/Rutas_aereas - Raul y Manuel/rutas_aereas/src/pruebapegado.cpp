#include <iostream>
#include <cstdlib>
#include <cmath>

#include "imagen.h"

using namespace std;

int main(int argc, char *argv[]){
  if (argc != 8) {
      cerr << "Uso: pruebapegado <img_fondo> <img_pegar> <mascara> <img_salida> <fila> <columna> <opacidad>" << endl;
      exit(1);
  }
  else {
      Imagen I, Ip;
      I.Leer(argv[1]);
      Ip.Leer(argv[2], argv[3]);
      int i, j;
      i = atoi(argv[5]);
      j = atoi(argv[6]);

      Tipo_Pegado tp = OPACO; // Variable de tipo Tipo_Pegado que es un enumerado con los valores OPACO y	BLENDING
      int au = atoi(argv[7]);
      if (au != 0)
          tp = BLENDING;

      I.PegarImagen(i, j, Ip, tp);
      I.Escribir(argv[4]);
  }
  return 0;
}