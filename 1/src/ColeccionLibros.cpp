#include "ColeccionLibros.h"
#include "Lista.h"

ColeccionLibros::ColeccionLibros()
{
    //ctor
}
ColeccionLibros::ColeccionLibros(Libro libro)
{
    //ctor con parametros = NULL;
    this->libros.agregarElemento(libro);
}
ColeccionLibros::~ColeccionLibros()
{
    //dtor
}
void ColeccionLibros::agregarLibro(Libro libro)
{
    this->libros.agregarElemento(libro);
}
bool ColeccionLibros::verificarLibro(string t){
    bool esta = false;
    bool noEsta = false;
    t = this->libros.eliminarCaracteresIndeseados(t,true);
    Libro cursor;
    string aux;
    int i,j;
    i = 0;
    j = 0;
    this->libros.posicionar_cursor();
    while((this->libros.cursorNoVacio() == true) && (esta == false)){
        cursor = this->libros.recuperarElemento();
        aux = cursor.recuperarTitulo();
        aux = this->libros.eliminarCaracteresIndeseados(aux,false);
        while((noEsta == false) && (j<aux.size())){
            if(t[i] == '*'){
                while((aux[j] != ' ') && j<aux.size())
                    j = j + 1;
                i = i + 1;
                if((t[i] == '*') || (t[i] == '?'))
                    return false;
            }
            else if((t[i] != aux[j]) && (t[i] != '?'))
                noEsta = true;
            i = i + 1;
            j = j + 1;
        }
        if((i<t.size()) && (noEsta == false))
            noEsta = true;
        j = 0;
        i = 0;
        this->libros.siguienteCursor();
        if (noEsta == false){
            esta = true;
        }
        noEsta = false;
    }
    return esta;
}
Libro ColeccionLibros::obtenerEconomico(int &precioMin,string idioma){
    this->libros.posicionar_cursor();
    this->libros.siguienteCursor();
    Libro cursor;
    Libro lib_barato;
    int aux;
    int precioBarato = 1000000;
    bool idiomaIgual = false;
    while(this->libros.cursorNoVacio() == true){
        cursor = this->libros.recuperarElemento();
        aux = cursor.recuperarCosto();
        idiomaIgual = estaIdiomaEnLibro(cursor,idioma);
        if((aux > precioMin) && (idiomaIgual == true) && (aux < precioBarato)){
            precioBarato = aux;
            lib_barato = cursor;
        }
        this->libros.siguienteCursor();
        idiomaIgual = false;
    }
    precioMin = precioBarato;
    return lib_barato;

}
void ColeccionLibros::mostrarEconomicos(int limite,string idioma){
    int precioMin = 0;
    int i = 1;
    bool sinLibros = false;
    Libro cursor;
    while((i <= limite) && (sinLibros == false)){
        cursor = obtenerEconomico(precioMin,idioma);
        if(precioMin == 1000000){
            cout << "No se encontraron mas libros." << endl;;
            sinLibros = true;
        }
        else{
            cout << i << ": " << endl;
            cout << "-------------------" << endl;
            cout << cursor;
            cout << "-------------------" << endl;
        }
        i = i + 1;
    }
}

void ColeccionLibros::mostrarPorFecha(int fechaInicial,int fechaFinal){
    Libro cursor;
    this->libros.posicionar_cursor();
    this->libros.siguienteCursor();
    int auxFecha;
    while(this->libros.cursorNoVacio() == true){
        cursor = this->libros.recuperarElemento();
        auxFecha = cursor.recuperarAnio();
        if((auxFecha >= fechaInicial) && (auxFecha <= fechaFinal)){
            cout << "---------------" << endl;
            this->libros.imprimirElemento(cursor);
        }
        this->libros.siguienteCursor();
    }
    cout << "---------------" << endl;
}
void ColeccionLibros::mostrarTodosLosLibros(){
    this->libros.mostrarTodos();
}
bool ColeccionLibros::estaIdiomaEnLibro(Libro libro, string idioma){
    bool esta = false;
    esta = libro.estaIdioma(idioma);
    return esta;
}
