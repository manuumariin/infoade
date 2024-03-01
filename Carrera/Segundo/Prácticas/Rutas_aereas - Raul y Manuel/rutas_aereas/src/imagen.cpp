/**
 * @file imagen.cpp
 * @brief Fichero con la implementación de los métodos de la clase Imagen
 * @authors Manuel Marín Rodríguez y Raúl Martínez Bustos
 */

#include "imagen.h"

void Imagen::deallocate_array(){
  for (int i=0;i<nf;i++)
    delete[]data[i];
  delete []data;
}

void Imagen::copy_array(const Imagen &other){
    
   nf = other.nf;
  nc = other.nc;
  data = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    data[i]=new Pixel [nc];
    for (int j=0;j<nc;j++){
  data[i][j]=other.data[i][j];
    }
  }  
  
}  
/*********************************/
Imagen::Imagen(){
  data=0;
  nf=nc=0;
}

/*********************************/
Imagen::Imagen(int f,int c){
  nf = f;
  nc = c;
  data = new Pixel*[nf];
  for (int i=0;i<nf;i++){
    data[i]=new Pixel[nc];
    for (int j=0;j<nc;j++){
  data[i][j].r=255;
  data[i][j].g=255;
  data[i][j].b=255;
  data[i][j].transparencia=255;
    }
  }  


}

Imagen & Imagen::operator=(const Imagen & I){
   if (this!=&I){
  deallocate_array();
  copy_array(I);
   }
   return * this;
}


Imagen::~Imagen(){
  deallocate_array();
}

Pixel & Imagen::operator()(int i,int j){
  assert(i>=0 && i<nf && j>=0 && j<nc*3);
  return data[i][j];
}
const Pixel & Imagen::operator()(int i,int j)const{
  assert(i>=0 && i<nf && j>=0 && j<nc);
  return data[i][j];
}

bool Imagen::Escribir(const char * nombre){
      unsigned char * aux = new unsigned char [nf*nc*3];
      unsigned char * m = new unsigned char [nf*nc];
      
      int total = nf*nc*3;
      for (int i=0;i<total;i+=3){
      int posi = i /(nc*3);
     int posj = (i%(nc*3))/3;
      
      aux[i]=data[posi][posj].r;
      aux[i+1]=data[posi][posj].g;
      aux[i+2]=data[posi][posj].b;
      m[i/3]=data[posi][posj].transparencia;
       
   }    
  
      if (!EscribirImagenPPM (nombre, aux,nf,nc)){
    cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
      }	  
      delete[]aux;
      string n_aux = "mascara_";
      n_aux =n_aux+nombre;
      std::size_t found =n_aux.find(".ppm");
      if (found!=std::string::npos){
  n_aux =n_aux.substr(0,found);
      }
      n_aux =n_aux+".pgm";

      
      if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
    cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
      }	    
      delete []m;

    return ( EscribirImagenPGM(n_aux.c_str(), m, nf, nc) ? true : false );
  
}  
/*********************************/
bool Imagen::Leer(const char * nombre,const string &nombremascara){
      bool escrito;
      int f,c;
      unsigned char * aux,*aux_mask ;
      
      LeerTipoImagen(nombre, f, c);
      aux = new unsigned char [f*c*3];
      LeerImagenPPM (nombre, f,c,aux);
      LeerImagenPPM(nombre, f, c, aux) ? escrito=true : escrito=false;
      if (nombremascara!=""){
  int fm,cm;
  LeerTipoImagen(nombremascara.c_str(), fm, cm);
  aux_mask = new unsigned char [fm*cm];
  LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
      }
      else{
  aux_mask=0;
      }	
      
      
      Imagen I(f,c);
      int total = f*c*3;
      for (int i=0;i<total;i+=3){
     int posi = i /(c*3);
     int posj = (i%(c*3))/3;
  //   cout<<posi<<" " <<posj<<endl;
       I.data[posi][posj].r=aux[i];
       I.data[posi][posj].g=aux[i+1];
       I.data[posi][posj].b=aux[i+2];
       if (aux_mask!=0)
        I.data[posi][posj].transparencia=aux_mask[i/3];
       else  
         I.data[posi][posj].transparencia=255;
   }    
    
      *this = I;   
      if (aux_mask!=0) delete[]aux_mask;
      delete []aux;

      return escrito;
}	

void Imagen::LimpiarTransp(){
    for (int i=0;i<nf;i++)
      for (int j=0;j<nc;j++)
  if (data[i][j].transparencia!=0 && data[i][j].transparencia!=255)
    data[i][j].transparencia=0;
}

int Imagen::GetFilas() const{
    return nf;
}

int Imagen::GetCols() const{
    return nc;
}

int Imagen::GetSize() const{
    return nf*nc;
}

int Imagen::GetSizecolors() const{
    return GetSize()*3; //(Red,green and blue)
}

void Imagen::PegarImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
      for (int j=0;j<I.nc;j++)
  if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
  if (I.data[i][j].transparencia!=0){
    if (tippegado==OPACO)
      data[i+posi][j+posj]=I.data[i][j];
    else{
      data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
      data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
      data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
    }  
    
  }  
  }	
      
}
Imagen Imagen::ExtraeImagen(int posi,int posj,int dimi,int dimj){
   Imagen Iaux(dimi,dimj);
   for (int i=posi;i<dimi;i++)
     for (int j=posj;j<dimj;j++)
        Iaux.data[i-posi][j-posj]=data[i][j];
   return Iaux;  
}  
