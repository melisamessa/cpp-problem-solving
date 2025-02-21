#include "Libro.h"
using namespace std;

Libro::Libro()
{
    //ctor
}

Libro::Libro(string isbm,string titulo,string autor,int anio,string pais,int precio)
{
    //ctor con parametros
    this->isbm = isbm;
    this->titulo = titulo;
    this->autor = autor;
    this->anio = anio;
    this->pais = pais;
    this->precio = precio;
}

Libro::~Libro()
{
    //dtor
}

string Libro::recuperarISBM(){
    return isbm;
}
string Libro::recuperarTitulo(){
    return titulo;
}
string Libro::recuperarAutor(){
    return autor;
}
int Libro::recuperarAnio(){
    return anio;
}
string Libro::recuperarPais(){
    return pais;
}
float Libro::recuperarCosto(){
    return precio;
}
void Libro::agregarIdioma(string idioma){
    this->idiomas.agregarElemento(idioma);
}
string Libro::devolverIdiomas(){
    this->idiomas.posicionar_cursor();
    string total;
    this->idiomas.siguienteCursor();
    while(this->idiomas.cursorNoVacio() == true){
        total.append(this->idiomas.recuperarElemento());
        total.append(",");
        this->idiomas.siguienteCursor();
    }
    total.pop_back();
    return total;
}
bool Libro::estaIdioma(string idioma){
    bool esta = false;
    string aux;
    this->idiomas.posicionar_cursor();
    this->idiomas.siguienteCursor();
    idioma = this->idiomas.eliminarCaracteresIndeseados(idioma,true);
    while((this->idiomas.cursorNoVacio() == true) && (esta == false)){
        aux = this->idiomas.recuperarElemento();
        aux = this->idiomas.eliminarCaracteresIndeseados(aux,false);
        if(aux == idioma){
            esta = true;
        }
        this->idiomas.siguienteCursor();
    }
    return esta;
}
ostream & operator << (ostream & salida,Libro & primer_libro){
    salida << "ISBM: " << primer_libro.recuperarISBM() << endl;
    salida << "Titulo: " << primer_libro.recuperarTitulo() << endl;
    salida << "Autor: " << primer_libro.recuperarAutor() << endl;
    salida << "Anio: " << primer_libro.recuperarAnio() << endl;
    salida << "Pais de Origen: " << primer_libro.recuperarPais() << endl;
    salida << "Precio: $" << primer_libro.recuperarCosto() << endl;
    salida << "Idiomas:[" << primer_libro.devolverIdiomas() << "]" << endl;
    return salida;
}
