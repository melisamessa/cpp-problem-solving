#include "Grafo.h"

#include "iostream"

using namespace std;


//Complejidad O(v . a) siendo v = cantidad de vertices; siendo a = cantidad de aristas;
template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<string> vertices;
	grafo.devolver_vertices(vertices);
	list<string>::iterator v = vertices.begin();                            //O(1)
	while (v != vertices.end()) {                                           //O(v)
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();   // O(a)
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}

int main(int argc, char **argv)
{
	Grafo <int> g;
	list<string> camino;

	// Cargamos un grafo dirigido
	// Primero los vértices

	g.agregar_vertice("Buenos Aires");
	g.agregar_vertice("Tandil");
	g.agregar_vertice("Ayacucho");
	g.agregar_vertice("Rauch");
	g.agregar_vertice("Las Flores");
	g.agregar_vertice("De la canal");
	g.agregar_vertice("Cachari");
	g.agregar_vertice("San Miguel del Monte");
	g.agregar_vertice("Gral. Belgrano");
	g.agregar_vertice("Coronel Brandsen");
	g.agregar_vertice("Canuelas");

	// Luego los arcos
	g.agregar_arco("Tandil", "De la canal", 33);
	g.agregar_arco("De la canal", "Rauch", 47);
	g.agregar_arco("Rauch", "Cachari", 60);
	g.agregar_arco("Rauch", "Las Flores", 91);
	g.agregar_arco("Cachari", "Las Flores", 59);
	g.agregar_arco("Las Flores", "San Miguel del Monte", 79);
	g.agregar_arco("Tandil", "Ayacucho", 77);
	g.agregar_arco("Ayacucho", "Gral. Belgrano", 167);
	g.agregar_arco("Gral. Belgrano", "Coronel Brandsen", 76);
	g.agregar_arco("San Miguel del Monte", "Canuelas", 46);
	g.agregar_arco("Gral. Belgrano", "San Miguel del Monte", 51); //genera un bucle
	g.agregar_arco("Canuelas", "Buenos Aires",65);
	g.agregar_arco("Coronel Brandsen", "Buenos Aires", 85);

    // Mostramos el grafo
	cout << "Estructura del grafo:\n" << g << "\n";

	//Complejidad total de mostrar los caminos del DFS es O(n)
    cout << endl << "Caminos: "<<endl;
    list<string> caminos;
    g.dfs(caminos);
    list<string>::iterator itr= caminos.begin();                    //Complejidad O(1)
    while (itr != caminos.end()){                                   //Complejidad O(n)
        cout << *itr<< "-";
        itr++;
    }

	return 0;
}
