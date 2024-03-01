//
// Created by Manuel & Raul on 3/12/23.
//
#include "pais.h"

Pais::Pais(){}

void Pais::SetPunto(Punto punt){
    p=punt;
}
void Pais::SetPais(string country){
    pais=country;
}
void Pais::SetBandera(string flag){
    bandera=flag;
}

Punto Pais::GetPunto()const {
    return p;
}

string Pais::GetPais()const {
    return pais;
}
string Pais::GetBandera()const {
    return bandera;
}

bool Pais::operator<(const Pais &P)const{
    return pais<P.pais;
}
bool Pais::operator>(const Pais &P) const {
    return pais>P.pais;
}

bool Pais::operator==(const Pais &P)const{
    return pais==P.pais;
}

bool Pais::operator==(const Punto &P)const{
    return p==P;
}

ostream & operator<<(ostream & os, const Pais &P) {
    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
    return os;
}

istream & operator>>(istream & is, Pais & P){
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;

	P.p=Punto(lat,lng,' ');
	return is;
}
