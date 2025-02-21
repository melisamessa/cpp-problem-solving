#ifndef COLECCIONLIBROS_H
#define COLECCIONLIBROS_H
#include "Libro.h"
#include "Lista.h"

class ColeccionLibros
{
    public:
        ColeccionLibros();
        ColeccionLibros(Libro);
        virtual ~ColeccionLibros();
        Libro recuperarLibro();
        int longitudLibros();
        void agregarLibro(Libro libro);
        bool verificarLibro(string t);
        Libro obtenerEconomico(int &precioMin,string idioma);
        void imprimirLibro(Libro libro);
        void mostrarPorFecha(int fechaInicial,int fechaFinal);
        void mostrarEconomicos(int limite, string idioma);
        void mostrarTodosLosLibros();
        bool estaIdiomaEnLibro(Libro libro,string idioma);
    protected:
    private:
        Lista <Libro> libros;
};
#endif
