/**
  * @file rutas_aereas.cpp
  * @brief Fichero con el programa principal y 2 funciones auxiliares
  *
  * Realiza la rotación de las imágenes y la superposición de aviones en el mapa
  * 
  * @see Imagen
  * @see Paises
  * @see Almacen_Rutas
  *
  */

#include "imagen.h"
#include "almacen_rutas.h"
#include "paises.h"
#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;


/**
 * @brief Función para rotar imágenes
 * 
 * @param Io Imagen a rotar
 * @param angulo Ángulo de rotación que se le quiere dar
 * @return Devuelve la imagen rotada un total de angulo ángulos
 */
Imagen Rota(const Imagen & Io,double angulo){
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
    rcorners[2]=Io.GetFilas()-1;
    rcorners[3]=Io.GetFilas()-1;
    ccorners[1]=Io.GetCols()-1;
    ccorners[3]=Io.GetCols()-1;
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
	       if((old_row>=0)&&(old_row<Io.GetFilas())&&
	          (old_col>=0)&&(old_col<Io.GetCols()))
	       {
	          Iout(rows,cols)=Io(old_row,old_col);

	       }
	       else{
	         Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
	         Iout(rows,cols).transparencia=0;
	       }
	    }
    }
    return Iout;
	  
}

/**
 * @brief Pinta un avión en una imágen
 * 
 * @param f1 Fila en la que empezar a pintar
 * @param f2 Fila en la que se acaba de pintar
 * @param c1 Columna en la que se empieza a pintar
 * @param c2 Columna en la que se acaba de pintar
 * @param I Imagen que se desea pintar
 * @param avion Imagen del avión a pintar
 * @param mindisf Numero de filas minimo que puede tener el avion a pintar
 * @param mindisc Numero de columnas minimo que puede tener el avion a pintar
 * 
 * @pre El parámetro avion tiene que haber pasado por la máscara previamente
 */
void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
      
      int fila,col;
      if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
	
	 if (c1!=c2){
	   double a,b;
	   a= double(f2-f1)/double(c2-c1);
	   b= f1-a*c1;
	   col = (int)(c1+c2)/2;
	   fila = (int)rint(a*col+b);
	 }  
	 else{
	   col = c1;
	   fila = (f1+f2)/2;
	 }  
	  
	  
	  double angulo = atan2((f2-f1),(c2-c1));
	  Imagen Irota=Rota(avion,angulo);
	
	  I.PegarImagen(fila,col,Irota);
	  
	   angulo = atan2((f2-fila),(c2-col));
	  Irota=Rota(avion,angulo);
	
	  I.PegarImagen(f2,c2,Irota);
	  angulo = atan2((fila-f1),(col-c1));
	  Irota=Rota(avion,angulo);
	
	  I.PegarImagen(f1,c1,Irota);
	 
      
      }
     
}  
  

int main(int argc, char * argv[]){
  if (argc!=7){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.-Fichero con la informacion de los paises"<<endl;
      cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
      cout<<"3.-Directorio con las banderas"<<endl;
      cout<<"4.-Fichero con el almacen de rutas"<<endl;
      cout<<"5.- Nombre de la imagen con el avion"<<endl;
      cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;
      
      return 0;
  }    
  Paises Pses;
  ifstream f (argv[1]);
  f>>Pses;
  //cout<<Pses;
  Imagen I;
  I.Leer(argv[2]);
  
  //Leemos los aviones 
  Imagen avion;
  avion.Leer(argv[5],argv[6]);
  
  Almacen_Rutas Ar;
  f.close();
   f.open (argv[4]);
  f>>Ar;

  cout<<"Las rutas: "<<endl<<Ar;
  cout<<"Dime el codigo de una ruta"<<endl;
  string a;
  cin>>a;
  string nombre_imagen=a+".ppm";

  Ruta R=Ar.GetRuta(a);
  
  Ruta::iterator it,it_before;
  Paises::iterator ip_before =Pses.end();
  Paises::iterator ip=Pses.end();
  Imagen i_ban_inicio;
  int posi_ini,posj_ini;
  for (it=R.begin(); it!=R.end();++it){
      Punto pto = (*it);
      
      ip_before = ip;
      ip=Pses.find(pto);
      
      string name = (*ip).GetBandera();
      string n_com = argv[3]+name;
      
      Imagen i_ban;
      i_ban.Leer(n_com.c_str(),"");
      
	cout<<(*ip).GetPais()<<" ";
	int x =  (int) ((I.GetCols()/360.0) * (180 + pto.GetLong()));
	int y =  (int) ((I.GetFilas()/180.0) * (90 - pto.GetLat()));
	if (ip_before!=Pses.end() ){
	  
	  int x_old =(int) ((I.GetCols()/360.0) * (180 + (*it_before).GetLong()));
	  int y_old =  (int) ((I.GetFilas()/180.0) * (90 -(*it_before).GetLat()));
	  
	  Pintar(y_old-avion.GetFilas()/2 ,y-avion.GetFilas()/2, x_old-avion.GetCols()/2,x-avion.GetCols()/2,I,avion,50,50);
	}
	  
	I.PegarImagen(y-i_ban.GetFilas()/2,x-i_ban.GetCols()/2,i_ban,BLENDING);
	if (ip!=Pses.begin()){
	    I.PegarImagen(posi_ini-i_ban_inicio.GetFilas()/2,posj_ini-i_ban_inicio.GetCols()/2,i_ban_inicio,BLENDING);
	} 
	i_ban_inicio=i_ban;
	posi_ini=y;
	posj_ini=x;
	it_before = it;
   }
  cout << endl;
  I.Escribir(nombre_imagen.c_str());
  
}
