#include "Lista.h"
#include <cstddef>
#include "Libro.h"


template <typename T> Lista<T>::Lista()
{

}

template <typename T> Lista<T>::~Lista()
{
    //dtor
}
template <typename T> void Lista <T>::agregarElemento(const T & elem){
    int contador = 0;
    Nodo* nuevo = new Nodo();
    Nodo* puntero = new Nodo();
    puntero = this->primero;
    nuevo->elem = elem;
    while(puntero->siguiente != NULL){
            puntero = puntero->siguiente;
            contador = contador + 1;
    }
    puntero->siguiente = nuevo;
}
template <typename T> void Lista <T>::siguienteCursor(){
    this->cursor = this->cursor->siguiente;
}
template <typename T> const T & Lista<T>::recuperarElemento() const{
    return this->cursor->elem;
}
template <typename T> void Lista<T>::posicionar_cursor(){
    this->cursor = this->primero;
}
template <typename T> bool Lista<T>::cursorNoVacio(){
    if(cursor != NULL)
        return true;
    else
        return false;
}
template <typename T> void Lista<T>::imprimirElemento(const T & elem){
     Nodo* puntero = new Nodo();
     puntero->elem = elem;
     cout << puntero->elem;
}
template <typename T> void Lista<T>::mostrarTodos(){
    this->cursor = primero->siguiente;
    while(this->cursor != NULL){
        imprimirElemento(this->cursor->elem);
        cout << "-----------------------" << endl;
        this->cursor = cursor->siguiente;
    }
}
template <typename T> string Lista<T>::eliminarCaracteresIndeseados(string cadena, bool entradaPorCin){
    int caracteresIndeseados[] = {160,130,161,162,163,164};
    int mayusculasConAcento[] = {181,144,246,224,233,165};
    int ascii_value;
    int j;
    bool corregido = false;
    string reemplazo = "aeioun";
    string cadenaSinCaracteresIndeseados;
    if(entradaPorCin == true){
        for(int i = 0; i<cadena.size(); i++){
            cadena[i] = tolower(cadena[i]);
            ascii_value = cadena[i] & 0x00FF;
            while((j<6) && (corregido == false)){
                if((ascii_value == caracteresIndeseados[j]) || (ascii_value == mayusculasConAcento[j])){
                    cadena[i] = reemplazo[j];
                    corregido = true;
                }
            j = j + 1;
            }
        corregido = false;
        j = 0;
        if((cadena[i] == ' ') && (i == cadena.size() - 1))
            continue;
        else
            cadenaSinCaracteresIndeseados += cadena[i];
        }
        return cadenaSinCaracteresIndeseados;
    }else{
        for(int i = 0; i<cadena.size() ; i++){
            cadena[i] = tolower(cadena[i]);
            if (cadena[i] == 'á') cadena[i]='a';
            if (cadena[i] == 'é') cadena[i]='e';
            if (cadena[i] == 'í') cadena[i]='i';
            if (cadena[i] == 'ó') cadena[i]='o';
            if (cadena[i] == 'ú') cadena[i]='u';
            if (cadena[i] == 'ñ') cadena[i]='n';
            if((cadena[i] == ' ') && (i == cadena.size() - 1))
                continue;
            else
                cadenaSinCaracteresIndeseados += cadena[i];
        }
        return cadenaSinCaracteresIndeseados;
        }
        return cadenaSinCaracteresIndeseados;
}


template class Lista<Libro>;
template class Lista<string>;

