#include <iostream>
#include <ostream>
#include <fstream>
#include <list>
#include "Equipo.h"

using namespace std;

struct Partido{
    int partido;
    string equipo1;
    string equipo2;
    vector<float> puntaje_promedio;
};

struct SolucionOptima{
    vector<unsigned int> asignacion_arbitro;
    float puntaje;
};

void procesar_dataset(string origen, list<Equipo> & equipos);
void imprimir_partidos_puntajes (const list<Partido> & partidos, int cantidad_arbitros);
void crear_partidos (list<Equipo> & equipos, list<Partido> & partidos, int indice, int cantidad_arbitros);
void imprimir_solucion(SolucionOptima & solucion, int cantidad_partidos);
int poda (SolucionOptima & actual,int nroPartido);
SolucionOptima resolver_backtracking(int cantidad_partidos, list<Partido> & partidos, int indice);
void Menu();

int main(){

    list<Equipo> equipos;
    list<Partido> partidos;
    procesar_dataset("prueba_equipos.csv", equipos);
    int cantidad_partidos = 3;
    int cantidad_equipos = 6;
    int cantidad_arbitros= 7;
    int indice = 1;
    while (indice <= cantidad_partidos){
        crear_partidos(equipos, partidos, indice, cantidad_arbitros);
        indice++;
    }

    unsigned int accion = -1;
    int salida;
    while (accion != 0){
        Menu();
        cin >> accion;
        system("cls");
        switch(accion)
        {
        case 1:
            imprimir_partidos_puntajes(partidos, cantidad_arbitros);
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;

        break;

        case 2:
            {
            SolucionOptima solucion = resolver_backtracking(cantidad_partidos, partidos, accion);
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
            }
        break;

        case 3:
            {
            list<Partido>::const_iterator itList = partidos.begin();
            SolucionOptima solucion = resolver_backtracking(cantidad_partidos, partidos, accion);
            cout << "La asignacion optima es: " << endl;
            for (int i=1; i <= cantidad_partidos; i++){
                cout << "P"<<itList->partido<<"["<< itList->equipo1<< "-" <<itList->equipo2<< "] A" << solucion.asignacion_arbitro[i] << endl;
                itList++;
            }
            cout << "Puntaje maximo: " << solucion.puntaje << endl;
            }
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
        break;
        }
        system("cls");
    }
    return 0;
}

void Menu (){
    cout << "------------------------------------------------------" << endl;
    cout << "Organizacion de jornada" << endl;
    cout << "1 Visualizar todos los partidos con sus respectivos puntajes promediados hacia cada arbitro"<< endl;
    cout << "2 Visualizar todas las combinaciones Arbitro/Partido  con su respectivo puntaje" << endl;
    cout << "3 Visualizar la combinacion Arbitro/Partido  optima" << endl;
    cout << "0 Finalizar el proceso" << endl;
}

void procesar_dataset(string origen, list<Equipo> & equipos){
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else{
        string linea;
        getline(archivo, linea);
        int cantidad_equipos = atoi(linea.c_str());
        int cantidad_partidos = cantidad_equipos/2;

        cout <<"Se jugaran " << cantidad_partidos<<" partidos." << endl;
        cout << "Habra "<< cantidad_equipos<<" equipos."<<endl;

        //CUENTO CUANTAS COLUMNAS "arbitro" HAY PARA DETERMINAR LA CANTIDAD DE ARBITROS
        getline(archivo,linea);
        int cantidad_arbitros= 0;
        string nombre= "arbitro_";
        size_t pos = linea.find(nombre);
        while (pos != string::npos){
            cantidad_arbitros++;
            pos = linea.find("arbitro_", pos+nombre.size());
        }

       cout <<"Habra " << cantidad_arbitros <<" arbitros." << endl;
       cout << "---------------------------------------------------"<< endl;

        //LEO UNA LINEA POR VEZ
        while (getline(archivo, linea)){
            //lectura del partido
            int pos_inicial = 0;
            int pos_final = linea.find(',');
            string e = linea.substr(pos_inicial, pos_final);

            pos_inicial = pos_final+1;
            pos_final = linea.find(',', pos_inicial);
            Equipo eq(e, cantidad_arbitros);
            //lectura de los puntaje de los arbitros
            for (int arbitro=0; arbitro < cantidad_arbitros; arbitro++){
                float puntaje = atof(linea.substr(pos_inicial, pos_final).c_str());
                eq.agregar_puntaje(puntaje);
                pos_inicial= pos_final+1;
                pos_final = linea.find(',', pos_inicial);
            }
            equipos.push_back(eq);
        }
    }
}

Partido guardar_partido (int partido, string equipo1, string equipo2, list<Equipo> & equipos, int cantidad_arbitros){
    Partido p;
    p.partido = partido;
    p.equipo1 = equipo1;
    p.equipo2 = equipo2;
    p.puntaje_promedio= vector<float>(cantidad_arbitros, 0);
    list<Equipo>::const_iterator itEquipo1 = equipos.begin();
    list<Equipo>::const_iterator itEquipo2 = equipos.begin();
    while (itEquipo1->obtenerEquipo() != equipo1){
        itEquipo1++;
    }
    while (itEquipo2->obtenerEquipo() != equipo2){
        itEquipo2++;
    }
    for (int arbitro=0; arbitro < cantidad_arbitros; arbitro++){
        float puntaje1= itEquipo1->obtenerPuntajes(arbitro);
        float puntaje2= itEquipo2->obtenerPuntajes(arbitro);
        float puntaje = (puntaje1 + puntaje2)/2;
        p.puntaje_promedio[arbitro]= puntaje;
    }
    return p;
}

void imprimir_solucion(SolucionOptima & solucion, int cantidad_partidos){
    cout << "-------------------------------------------------------"<< endl;
    for (int i=1; i <= cantidad_partidos; i++){
        cout <<"P"<< i <<"A" << solucion.asignacion_arbitro[i] << endl;
    }
    cout << "Puntaje obtenido: " << solucion.puntaje << endl;
    }

int poda (SolucionOptima & actual,int nroPartido){
    unsigned int indice = 1;
    while (indice < nroPartido){
        if (actual.asignacion_arbitro[indice] == actual.asignacion_arbitro[nroPartido]){
            return 1;
        }
        indice++;
    }
    return 0;
}

void Backtracking(list<Partido> & partidos, list<Partido>::const_iterator itList,int nroPartido, SolucionOptima & actual, SolucionOptima & mejor,int cantidad_partidos, int indice){
    if (nroPartido > cantidad_partidos){
        if (indice == 2)
            imprimir_solucion(actual, cantidad_partidos);
        if (actual.puntaje > mejor.puntaje){
            mejor = actual;
        }
    }else{
        int nroArbitro= 0;
        if (nroPartido <= cantidad_partidos){
            while (nroArbitro < 7){
                nroPartido= itList->partido;
                actual.asignacion_arbitro[nroPartido]= nroArbitro;
                actual.puntaje += itList->puntaje_promedio[nroArbitro];
                itList++;
                if (poda(actual, nroPartido) != 1)
                        Backtracking(partidos, itList,nroPartido+1, actual, mejor, cantidad_partidos, indice);
                itList--;
                actual.puntaje -= itList->puntaje_promedio[nroArbitro];
                nroArbitro++;
            }
        }
    }
}

SolucionOptima resolver_backtracking(int cantidad_partidos, list<Partido> & partidos, int indice){
    SolucionOptima solucion_actual;
    SolucionOptima mejor_solucion;

    solucion_actual.puntaje = 0;
    solucion_actual.asignacion_arbitro= vector<unsigned int>(cantidad_partidos+1,0);

    mejor_solucion.puntaje = -1;
    mejor_solucion.asignacion_arbitro= vector<unsigned int>(cantidad_partidos+1,0);

    list<Partido>::const_iterator itList= partidos.begin();

    Backtracking(partidos, itList, 1, solucion_actual, mejor_solucion, cantidad_partidos, indice);


    return mejor_solucion;
}

void crear_partidos (list<Equipo> & equipos, list<Partido> & partidos, int indice, int cantidad_arbitros){
    list<Equipo>::iterator itEquipo = equipos.begin();
    cout <<"JORNADA"<< endl;
    cout << "Equipos disponibles: ";
    while (itEquipo != equipos.end()){
        cout << itEquipo->obtenerEquipo() << "-";
        itEquipo++;
    }
    string equipo1, equipo2;
    cout << endl;
    cout << "Partido "<<indice << " ingrese el primer equipo del partido"<< endl;
    getline(cin, equipo1);
    cout << "ingrese el segundo equipo del partido" << endl;
    getline(cin, equipo2);
    Partido p = guardar_partido(indice, equipo1, equipo2, equipos, cantidad_arbitros);
    partidos.push_back(p);
    string eliminar;
    itEquipo = equipos.begin();
    bool encontre = false;
    int indice1, indice2;
    while ((encontre==false)&&(itEquipo != equipos.end())){
        eliminar= itEquipo->obtenerEquipo();
        if (eliminar == equipo1){
            indice1= 1;
            list<Equipo>::const_iterator itEliminar = itEquipo;
            itEquipo++;
            equipos.erase(itEliminar);
        }else{
            if(eliminar == equipo2){
                indice2= 1;
                list<Equipo>::const_iterator itEliminar = itEquipo;
                itEquipo++;
                equipos.erase(itEliminar);
            }else{
                itEquipo++;
            }
        }
        if ((indice1==0) && (indice2==0))
            encontre = true;
        }
}

void imprimir_partidos_puntajes (const list<Partido> & partidos, int cantidad_arbitros){
    list<Partido>::const_iterator itP = partidos.begin();
    while (itP != partidos.end()){
        cout << itP->partido << endl;
        cout << itP->equipo1 << endl;
        cout << itP->equipo2 << endl;
        for (int i=0; i < cantidad_arbitros; i++){
            cout <<"Arbitro "<< i << " puntaje: " << itP->puntaje_promedio[i] << endl;
        }
        itP++;
    }
}
