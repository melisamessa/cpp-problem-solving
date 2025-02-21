#ifndef EQUIPO_H
#define EQUIPO_H
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class Equipo
{
    public:
        Equipo(string equipo, int cantidad_arbitros);
        virtual ~Equipo();
        void agregar_puntaje(float puntaje);
        string obtenerEquipo() const;
        int obtener_cantidad_arbitros() const;
        int obtener_preferencia() const; //obtener_arbitro_preferido
        float obtenerPuntajes(unsigned int indice) const;

    private:
        string eq;
        vector<float> puntajes;

        int indice_arbitro;
};
ostream & operator << (ostream & salida, const Equipo & eq);

#endif // EQUIPO_H
