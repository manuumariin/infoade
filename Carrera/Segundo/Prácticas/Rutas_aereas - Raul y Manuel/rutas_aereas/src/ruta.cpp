//
// Created by Manuel & Raul on 3/12/23.
//
#include "ruta.h"

Ruta::Ruta(string cod, list<Punto> pts) {
    code = cod;
    puntos = pts;
    numpuntos = pts.size();
}

Ruta::Ruta(const Ruta &rut) {
    code = rut.code;
    numpuntos = rut.numpuntos;
    puntos = rut.puntos;
}

Punto Ruta::GetPunto(int p) {
    assert(p <= puntos.size());
    list<Punto>::iterator it = puntos.begin();
    for (int i = 0; i < p; i++)
        ++it;
    return *it;
}

bool Ruta::operator==(const Ruta &copia) {
    return (code == copia.code);
}

bool Ruta::operator==(const Ruta &copia)const{
    return (code == copia.code);
}

bool Ruta::operator==(const std::string &c){
    return (code == c);
}

bool Ruta::operator==(const string &c) const {
    return (code == c);
}

bool Ruta::operator==(const Punto &p){
    list<Punto>::const_iterator i;

    for (i = puntos.cbegin(); i != puntos.cend(); ++i) {
        if ((*i) == p) return true;
    }

    return false;
}

bool Ruta::operator==(const Punto &p) const{
    list<Punto>::const_iterator i;

    for (i = puntos.cbegin(); i != puntos.cend(); ++i) {
        if ((*i) == p) return true;
    }

    return false;
}


bool Ruta::operator<(const Ruta & rut) {
    return code < rut.code;
}


bool Ruta::operator<(const Ruta & rut) const {
    return code > rut.code;
}


bool Ruta::operator>(const Ruta & rut) {
    return code > rut.code;
}


bool Ruta::operator>(const Ruta & rut) const {
    return code > rut.code;
}
ostream &operator<<(ostream &os, const Ruta &rut) {
    os << rut.code << "\t" << rut.numpuntos << "\t";

    list<Punto>::const_iterator it;

    for (it = rut.puntos.cbegin(); it != rut.puntos.cend(); ++it) os << *it;

    return os;
}

istream & operator>>(istream &is , Ruta & rut) {
    is >> rut.code >> rut.numpuntos;

    if (!rut.puntos.empty()) rut.puntos.clear();

    for (int i = 0; i < rut.numpuntos; i++) {
        Punto p;
        is >> p;
        rut.puntos.push_back(p);
    }

    return is;
}

Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}


Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end()const{
    const_iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    iterator it;
    list<Punto>::iterator i;
    for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i); it.p=i;

    return it;
}