#include "Equipo.h"
#include <ostream>
#include <vector>
#include <cassert>

Equipo::Equipo(string equipo, int cantidad_arbitros)
{
    this->eq = equipo;
    this->puntajes = vector<float>(cantidad_arbitros, 0);
    this->indice_arbitro = 0;
}

string Equipo::obtenerEquipo() const{
    return this->eq;
}

int Equipo::obtener_cantidad_arbitros() const{
    return this->puntajes.size();
}

void Equipo::agregar_puntaje(float puntaje){
    if(this->indice_arbitro < this->puntajes.size()){
        this->puntajes[this->indice_arbitro] = puntaje;
        this->indice_arbitro++;
    }
}

float Equipo::obtenerPuntajes(unsigned int indice) const{
    assert(indice < this->puntajes.size());
    return this->puntajes[indice];
}

ostream & operator << (ostream & salida, const Equipo & eq){
    salida << "Equipo " << eq.obtenerEquipo() <<" Puntajes: ";
    for (int i=0; i < eq.obtener_cantidad_arbitros(); i++){
        salida << eq.obtenerPuntajes(i) << ", ";
    }
    salida << endl;

    return salida;
}

Equipo::~Equipo()
{
}
