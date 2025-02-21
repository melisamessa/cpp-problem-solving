#include <iostream>
#include <fstream>
#include <clocale>
#include "ColeccionLibros.h"
#include "Libro.h"


using namespace std;


/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen,ColeccionLibros &bookstore);//, Contenedor & contenedor);
void imprimirMenu();
string eliminarEspaciosEnBlanco(string cadena);

int main()
{
    setlocale(LC_ALL, "spanish"); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    ColeccionLibros Bookstore;
    procesar_archivo_entrada("libros.csv",Bookstore);
    int opcion = -1;
    int salida,idiomaCant,fechaMin,fechaMax;
    string titulo,idiomaBuscar;
    while(opcion != 0){
        imprimirMenu();
        cout << "Elija una opcion :";
        cin >> opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            cout << "Ha elegido buscar un libro, introduzca el titulo : ";
            cin.ignore();
            getline(cin,titulo);
            if(Bookstore.verificarLibro(titulo) == true)
                cout << "El libro esta en nuestra coleccion!" << endl;
            else
                cout << "No tenemos disponible ese libro!" << endl;

            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
            break;
        case 2:
            cout << "Ha elegido buscar libros en un rango de fechas, introduzca la fecha minima: ";
            cin >> fechaMin;
            cout << endl << "Ha continuacion introduzca la fecha maxima: ";
            cin >> fechaMax;
            Bookstore.mostrarPorFecha(fechaMin,fechaMax);
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
            break;
        case 3:
            idiomaCant = 0;
            cout << "Ha elegido buscar los libros mas economicos de un idioma, ingrese cuantos buscar (maximo 10): ";
            cin >> idiomaCant;
            system("cls");
            if ((idiomaCant < 1) || (idiomaCant > 10)){
                cout << "Error : cantidad no valida" << endl;
            }else{
                cout << endl << "Ingrese el idioma a buscar: ";
                cin.ignore();
                getline(cin,idiomaBuscar);
                Bookstore.mostrarEconomicos(idiomaCant,idiomaBuscar);
            }
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
            break;
        case 4:
            cout << "Todos los libros: " << endl;
            cout << "---------------------------" << endl;
            Bookstore.mostrarTodosLosLibros();
            cout << endl << "Aprete cualquier numero para continuar: ";
            cin >> salida;
            break;
        }
        system("cls");
    }
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen,ColeccionLibros &bookstore)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string isbn = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int fechaPublicacion = stoi(linea.substr(pos_inicial, pos_final - pos_inicial));

             //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string paisOrigen = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            /*cout << "LIBRO Nro "<< nroLibro<< "--------------------------------------" << endl;
            cout << "   ISBN: " << isbn << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   FECHA PUBLIC: " << fechaPublicacion<<endl;
            cout << "   PAIS: " << paisOrigen<< endl;
            cout << "   PRECIO: " << precio<<endl;*/

            //TO DO: Completar la lectura de los Idiomas del libro

            //Desde esta posición hasta el final se encuentra un número variable de idiomas de cada libro.
            //no tomo en cuenta los corchetes
            pos_inicial = pos_final + 2;
            pos_final = linea.size()-1;
            string idiomas = linea.substr(pos_inicial, pos_final - pos_inicial);

            Libro libro = Libro(isbn,titulo,autor,fechaPublicacion,paisOrigen,precio);

            // el siguiente código de prueba separa los diferentes idiomas en un arreglo de 10 posiciones
            string listaIdiomas[10];
            int pos_inicial_idiomas = 0, pos_final_idiomas = 0;
            int nroIdioma = 0;
            string str;
            while (pos_final_idiomas != -1) {
                pos_final_idiomas = idiomas.find(',', pos_inicial_idiomas);
                listaIdiomas[nroIdioma] = idiomas.substr(pos_inicial_idiomas, pos_final_idiomas - pos_inicial_idiomas);
                str = eliminarEspaciosEnBlanco(listaIdiomas[nroIdioma]);
                libro.agregarIdioma(str);
                //cout << str << endl;
                pos_inicial_idiomas = pos_final_idiomas + 1;
                nroIdioma++;
            }
            bookstore.agregarLibro(libro);

            nroLibro++;

        }
    }
}

void imprimirMenu(){
    cout << "Menu de BookStore" << endl;
    cout << "1 = Buscar un libro." << endl;
    cout << "2 = Buscar libros por fecha." << endl;
    cout << "3 = Mostrar los 10 libros mas economicos de cierto idioma." << endl;
    cout << "4 = Imprimir todos los libros disponibles." << endl;
    cout << "0 = Salir del BookStore" << endl;
}

string eliminarEspaciosEnBlanco(string cadena){
    string cadenaModificada;
    if(cadena[0] != ' ')
       cadenaModificada = cadena;
    else{
        for(int i = 1; i<cadena.size();++i)
            cadenaModificada += cadena[i];
    }
    return cadenaModificada;
}

