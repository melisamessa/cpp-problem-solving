#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include "cstring"
#include <stdio.h>
#include "Lista.h"

using namespace std;

class Libro
{
    public:
        Libro();
        Libro(string isbm,string titulo,string autor,int anio,string pais,int precio);
        virtual ~Libro();
        string recuperarTitulo();
        string recuperarAutor();
        string recuperarPais();
        string recuperarISBM();
        void agregarIdioma(string idioma);
        int recuperarAnio();
        float recuperarCosto();
        string devolverIdiomas();
        bool estaIdioma(string idioma);
        friend ostream & operator << (ostream & salida, Libro & primer_libro);
    protected:

    private:
        Libro * primer_libro;
        int anio;
        float precio;
        string isbm,titulo,autor,pais;
        Lista <string> idiomas;
};
#endif // LIBRO_H
