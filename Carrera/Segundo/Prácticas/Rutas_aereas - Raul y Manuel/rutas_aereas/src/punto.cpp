//
// Created by Manuel & Raul on 3/12/23.
//
#include "punto.h"

void Punto::SetLat(double lat){
    latitud=lat;
}
void Punto::SetLon(double lon){
    longitud=lon;
}

void Punto::SetDesc(char magicchar){
    magic_char=magicchar;
}

double Punto::GetLat() const {
    return latitud;
}

double Punto::GetLong() const {
    return longitud;
}

char Punto::GetDesc() const {
    return magic_char;
}

Punto::Punto() {}

Punto::Punto(double lat, double lng, char magicchar) {
    latitud = lat;
    longitud = lng;
    magic_char = magicchar;
}

bool Punto::operator==(const Punto &p) const {
return (latitud == p.latitud && longitud == p.longitud && magic_char == p.magic_char);
}

bool Punto::operator<(const Punto &p) const {
    return ((*this).longitud<p.GetLong() && (*this).latitud<p.GetLat());
}

bool Punto::operator>(const Punto &p) const {
    return !((*this).longitud>p.GetLong() && (*this).latitud>p.GetLat());
}
Punto::Punto(const Punto &p) {
    latitud = p.latitud;
    longitud = p.longitud;
    magic_char = p.magic_char;
}

ostream & operator<<(ostream &os, const Punto &p){
os << "(" << p.latitud << ", " << p.longitud << ")";
return os;
}

istream & operator>>(istream &is, Punto &p) {
    is.ignore( 1000 , '(' );
    is >> p.latitud;
    is.ignore( 1000 , ',');
    is >> p.longitud;
    is.ignore( 1000 , ')' );
    p.magic_char= ' ';
    return is;
}
