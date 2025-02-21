#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "cstring"
#include <stdio.h>



using namespace std;
template <typename T>


class Lista
{
    private:
        struct Nodo {
            T elem;
            Nodo *siguiente;
        };
        Nodo* primero = new Nodo();
        Nodo* cursor;
    public:
        Lista();
        virtual ~Lista();
        void agregarElemento(const T & elem);
        void siguienteCursor();
        const T & recuperarElemento() const;
        void posicionar_cursor();
        bool cursorNoVacio();
        void mostrarTodos();
        string eliminarCaracteresIndeseados(string cadena,bool entradaPorCin);
        void imprimirElemento(const T & elem);
    protected:
};

#endif // LISTA_H
