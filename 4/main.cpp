#include "Grafo.h"
#include <set>
#include <string>
#include "iostream"

using namespace std;

void menu();
template<typename C> list<set<string>> llenar_conjunto_aristas(Grafo<C> & g);
void eliminar_arista(list<set<string>> & aristas, string u, string v);
set<string> posicionar_camaras(list<set<string>> & aristas);


template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<string> vertices;
	grafo.devolver_vertices(vertices);
	list<string>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << "\n";
			ady++;
		}
		v++;
	}
	return salida;
}

int main(int argc, char **argv)
{
    unsigned int accion = -1;
    int salida;
    while (accion != 0){
        menu();
        cin >> accion;
        system("cls");
        switch(accion)
        {
        case 1:
            {
            Grafo <int> g;
            list<set<string>> aristas;

            g.agregar_vertice("Av. Rivadavia y Mitre");
            g.agregar_vertice("Alberdi y Mitre");
            g.agregar_vertice("San Lorenzo y Mitre");
            g.agregar_vertice("14 de julio y Mitre");
            g.agregar_vertice("Chacabuco y Mitre");
            g.agregar_vertice("Av. Rivadavia y Sarmiento");
            g.agregar_vertice("Av. Rivadavia y San Martín");
            g.agregar_vertice("Av. Rivadavia y Pinto");
            g.agregar_vertice("Av. Rivadavia y Belgrano");
            g.agregar_vertice("Av. Rivadavia y Maipu");
            g.agregar_vertice("Av. Rivadavia y 25 de mayo");
            g.agregar_vertice("Av. Rivadavia y Constitucion");
            g.agregar_vertice("Av. Rivadavia y Av. Avellaneda");
            g.agregar_vertice("Hipolito Yrigoyen y Mitre");
            g.agregar_vertice("Rodriguez y Mitre");
            g.agregar_vertice("9 de Julio y Mitre");
            g.agregar_vertice("Alem y Mitre");
            g.agregar_vertice("Paz y Mitre");
            g.agregar_vertice("Av. Santamarina y Mitre");
            g.agregar_vertice("Alberdi y Sarmiento");
            g.agregar_vertice("San Lorenzo y Sarmiento");
            g.agregar_vertice("14 de Julio y Sarmiento");
            g.agregar_vertice("Chacabuco y Sarmiento");
            g.agregar_vertice("Hipolito Yrigoyen y Sarmiento");
            g.agregar_vertice("Rodriguez y Sarmiento");
            g.agregar_vertice("9 de Julio y Sarmiento");
            g.agregar_vertice("Alem y Sarmiento");
            g.agregar_vertice("Paz y Sarmiento");
            g.agregar_vertice("Av. Santamarina y Sarmiento");
            g.agregar_vertice("Alberdi y San Martin");
            g.agregar_vertice("San Lorenzo y San Martin");
            g.agregar_vertice("14 de julio y San Martin");
            g.agregar_vertice("Chacabuco y San Martin");
            g.agregar_vertice("Hipolito Yrigoyen y San Martin");
            g.agregar_vertice("Rodriguez y San Martin");
            g.agregar_vertice("9 de julio y San Martin");
            g.agregar_vertice("Alem y San Martin");
            g.agregar_vertice("Paz y San Martin");
            g.agregar_vertice("Av. Santamarina y San Martin");
            g.agregar_vertice("Alberdi y Pinto");
            g.agregar_vertice("San Lorenzo y Pinto");
            g.agregar_vertice("14 de julio y Pinto");
            g.agregar_vertice("Chacabuco y Pinto");
            g.agregar_vertice("Hipolito Yrigoyen y Pinto");
            g.agregar_vertice("Rodriguez y Pinto");
            g.agregar_vertice("9 de julio y Pinto");
            g.agregar_vertice("Alem y Pinto");
            g.agregar_vertice("Paz y Pinto");
            g.agregar_vertice("Av. Santamarina y Pinto");
            g.agregar_vertice("Alberdi y Belgrano");
            g.agregar_vertice("San Lorenzo y Belgrano");
            g.agregar_vertice("14 de julio y Belgrano");
            g.agregar_vertice("Chacabuco y Belgrano");
            g.agregar_vertice("Fuerte Independencia y Belgrano");
            g.agregar_vertice("Rodriguez y Belgrano");
            g.agregar_vertice("9 de julio y Belgrano");
            g.agregar_vertice("Alem y Belgrano");
            g.agregar_vertice("Paz y Belgrano");
            g.agregar_vertice("Av. Santamarina y Belgrano");
            g.agregar_vertice("Av. Rivadavia y Av.España");
            g.agregar_vertice("Av. España y Alberdi");
            g.agregar_vertice("Av. España y San Lorenzo");
            g.agregar_vertice("Av. España y 14 de julio");
            g.agregar_vertice("Av. España y Chacabuco");
            g.agregar_vertice("Av. España e Hipolito Yrigoyen");
            g.agregar_vertice("Av. España y Rodriguez");
            g.agregar_vertice("Av. España y 9 de julio");
            g.agregar_vertice("Av. España y Alem");
            g.agregar_vertice("Av. España y Paz");
            g.agregar_vertice("Av. España y Av. Santamarina");
            g.agregar_vertice("Alberdi y Maipu");
            g.agregar_vertice("San Lorenzo y Maipu");
            g.agregar_vertice("14 de julio y Maipu");
            g.agregar_vertice("Chacabuco y Maipu");
            g.agregar_vertice("Fuerte Independencia y Maipu");
            g.agregar_vertice("Rodriguez y Maipu");
            g.agregar_vertice("9 de julio y Maipu");
            g.agregar_vertice("Alem y Maipu");
            g.agregar_vertice("Paz y Maipu");
            g.agregar_vertice("Av. Santamarina y Maipu");
            g.agregar_vertice("Alberdi y 25 de mayo");
            g.agregar_vertice("San Lorenzo y 25 de mayo");
            g.agregar_vertice("14 de julio y 25 de mayo");
            g.agregar_vertice("Chacabuco y 25 de mayo");
            g.agregar_vertice("Fuerte Independencia y 25 de mayo");
            g.agregar_vertice("Rodriguez y 25 de mayo");
            g.agregar_vertice("9 de julio y 25 de mayo");
            g.agregar_vertice("Alem y 25 de mayo");
            g.agregar_vertice("Paz y 25 de mayo");
            g.agregar_vertice("Av. Santamarina y 25 de mayo");
            g.agregar_vertice("Alberdi y Constitucion");
            g.agregar_vertice("San Lorenzo y Constitucion");
            g.agregar_vertice("14 de julio y Constitucion");
            g.agregar_vertice("Chacabuco y Constitucion");
            g.agregar_vertice("Fuerte Independencia y Constitucion");
            g.agregar_vertice("Rodriguez y Constitucion");
            g.agregar_vertice("9 de julio y Constitucion");
            g.agregar_vertice("Alem y Constitucion");
            g.agregar_vertice("Paz y Constitucion");
            g.agregar_vertice("Av. Santamarina y Constitucion");
            g.agregar_vertice("Alberdi y Av. Avellaneda");
            g.agregar_vertice("San Lorenzo y Av. Avellaneda");
            g.agregar_vertice("14 de julio y Av. Avellaneda");
            g.agregar_vertice("Chacabuco y Av. Avellaneda");
            g.agregar_vertice("Fuerte Independencia y Av. Avellaneda");
            g.agregar_vertice("Rodriguez y Av. Avellaneda");
            g.agregar_vertice("9 de julio y Av. Avellaneda");
            g.agregar_vertice("Alem y Av. Avellaneda");
            g.agregar_vertice("Paz y Av. Avellaneda");
            g.agregar_vertice("Av. Santamarina y Av. Avellaneda");
            g.agregar_vertice("Brandsen y Paraguay");
            g.agregar_vertice("Brandsen y Ohiggins");
            g.agregar_vertice("Brandsen y Almirante Brown");
            g.agregar_vertice("4 de abril y Pinto");
            g.agregar_vertice("4 de abril y Belgrano");
            g.agregar_vertice("4 de abril y Maipu");
            g.agregar_vertice("4 de abril y 25 de mayo");

            g.agregar_arco("Av. Rivadavia y Mitre", "Alberdi y Mitre");
            g.agregar_arco("Alberdi y Mitre", "San Lorenzo y Mitre");
            g.agregar_arco("San Lorenzo y Mitre", "14 de julio y Mitre");
            g.agregar_arco("14 de julio y Mitre", "Chacabuco y Mitre");
            g.agregar_arco("Av. Rivadavia y Mitre", "Av. Rivadavia y Sarmiento");
            g.agregar_arco("Av. Rivadavia y San Martín", "Av. Rivadavia y Pinto");
            g.agregar_arco("Av. Rivadavia y Pinto", "Av. Rivadavia y Belgrano");
            g.agregar_arco("Chacabuco y Mitre", "Hipolito Yrigoyen y Mitre");
            g.agregar_arco("Hipolito Yrigoyen y Mitre", "Rodriguez y Mitre");
            g.agregar_arco("Rodriguez y Mitre", "9 de Julio y Mitre");
            g.agregar_arco("9 de Julio y Mitre", "Alem y Mitre");
            g.agregar_arco("Alem y Mitre", "Paz y Mitre");
            g.agregar_arco("Paz y Mitre", "Av. Santamarina y Mitre");
            g.agregar_arco("Av. Rivadavia y Sarmiento", "Alberdi y Sarmiento");
            g.agregar_arco("Alberdi y Mitre", "Alberdi y Sarmiento");
            g.agregar_arco("Alberdi y Sarmiento", "San Lorenzo y Sarmiento");
            g.agregar_arco("San Lorenzo y Mitre", "San Lorenzo y Sarmiento");
            g.agregar_arco("San Lorenzo y Sarmiento", "14 de Julio y Sarmiento");
            g.agregar_arco("14 de julio y Mitre", "14 de Julio y Sarmiento");
            g.agregar_arco("14 de Julio y Sarmiento", "Chacabuco y Sarmiento");
            g.agregar_arco("Chacabuco y Mitre", "Chacabuco y Sarmiento");
            g.agregar_arco("Chacabuco y Sarmiento", "Hipolito Yrigoyen y Sarmiento");
            g.agregar_arco("Hipolito Yrigoyen y Mitre", "Hipolito Yrigoyen y Sarmiento");
            g.agregar_arco("Hipolito Yrigoyen y Sarmiento", "Rodriguez y Sarmiento");
            g.agregar_arco("Rodriguez y Mitre", "Rodriguez y Sarmiento");
            g.agregar_arco("Rodriguez y Sarmiento", "9 de Julio y Sarmiento");
            g.agregar_arco("9 de Julio y Mitre", "9 de Julio y Sarmiento");
            g.agregar_arco("9 de Julio y Sarmiento", "Alem y Sarmiento");
            g.agregar_arco("Alem y Mitre", "Alem y Sarmiento");
            g.agregar_arco("Alem y Sarmiento","Paz y Sarmiento");
            g.agregar_arco("Paz y Mitre", "Paz y Sarmiento");
            g.agregar_arco("Paz y Sarmiento", "Av. Santamarina y Sarmiento");
            g.agregar_arco("Av. Santamarina y Mitre", "Av. Santamarina y Sarmiento");
            g.agregar_arco("Av. Rivadavia y Sarmiento", "Av. Rivadavia y San Martín");
            g.agregar_arco("Av. Rivadavia y San Martín", "Alberdi y San Martin");
            g.agregar_arco("Alberdi y Sarmiento", "Alberdi y San Martin");
            g.agregar_arco("Alberdi y San Martin", "San Lorenzo y San Martin");
            g.agregar_arco("San Lorenzo y Sarmiento", "San Lorenzo y San Martin");
            g.agregar_arco("San Lorenzo y San Martin", "14 de julio y San Martin");
            g.agregar_arco("14 de Julio y Sarmiento", "14 de julio y San Martin");
            g.agregar_arco("14 de julio y San Martin", "Chacabuco y San Martin");
            g.agregar_arco("Chacabuco y Sarmiento", "Chacabuco y San Martin");
            g.agregar_arco("Chacabuco y San Martin", "Hipolito Yrigoyen y San Martin");
            g.agregar_arco("Hipolito Yrigoyen y Sarmiento", "Hipolito Yrigoyen y San Martin");
            g.agregar_arco("Hipolito Yrigoyen y San Martin", "Rodriguez y San Martin");
            g.agregar_arco("Rodriguez y Sarmiento", "Rodriguez y San Martin");
            g.agregar_arco("Rodriguez y San Martin", "9 de julio y San Martin");
            g.agregar_arco("9 de Julio y Sarmiento", "9 de julio y San Martin");
            g.agregar_arco("9 de julio y San Martin", "Alem y San Martin");
            g.agregar_arco("Alem y Sarmiento", "Alem y San Martin");
            g.agregar_arco("Alem y San Martin", "Paz y San Martin");
            g.agregar_arco("Paz y Sarmiento", "Paz y San Martin");
            g.agregar_arco("Paz y San Martin", "Av. Santamarina y San Martin");
            g.agregar_arco("Av. Santamarina y Sarmiento", "Av. Santamarina y San Martin");
            g.agregar_arco("Av. Rivadavia y Pinto", "Alberdi y Pinto");
            g.agregar_arco("Alberdi y San Martin", "Alberdi y Pinto");
            g.agregar_arco("Alberdi y Pinto", "San Lorenzo y Pinto");
            g.agregar_arco("San Lorenzo y San Martin", "San Lorenzo y Pinto");
            g.agregar_arco("San Lorenzo y Pinto","14 de julio y Pinto");
            g.agregar_arco("14 de julio y San Martin", "14 de julio y Pinto");
            g.agregar_arco("14 de julio y Pinto", "Chacabuco y Pinto");
            g.agregar_arco("Chacabuco y San Martin", "Chacabuco y Pinto");
            g.agregar_arco("Chacabuco y Pinto", "Hipolito Yrigoyen y Pinto");
            g.agregar_arco("Hipolito Yrigoyen y San Martin", "Hipolito Yrigoyen y Pinto");
            g.agregar_arco("Hipolito Yrigoyen y Pinto", "Rodriguez y Pinto");
            g.agregar_arco("Rodriguez y San Martin", "Rodriguez y Pinto");
            g.agregar_arco("Rodriguez y Pinto", "9 de julio y Pinto");
            g.agregar_arco("9 de julio y San Martin", "9 de julio y Pinto");
            g.agregar_arco("9 de julio y Pinto", "Alem y Pinto");
            g.agregar_arco("Alem y San Martin", "Alem y Pinto");
            g.agregar_arco("Alem y Pinto", "Paz y Pinto");
            g.agregar_arco("Paz y San Martin", "Paz y Pinto");
            g.agregar_arco("Paz y Pinto", "Av. Santamarina y Pinto");
            g.agregar_arco("Av. Santamarina y San Martin", "Av. Santamarina y Pinto");
            g.agregar_arco("Av. Rivadavia y Belgrano", "Alberdi y Belgrano");
            g.agregar_arco("Alberdi y Pinto", "Alberdi y Belgrano");
            g.agregar_arco("Alberdi y Belgrano", "San Lorenzo y Belgrano");
            g.agregar_arco("San Lorenzo y Pinto", "San Lorenzo y Belgrano");
            g.agregar_arco("San Lorenzo y Belgrano", "14 de julio y Belgrano");
            g.agregar_arco("14 de julio y Pinto", "14 de julio y Belgrano");
            g.agregar_arco("14 de julio y Belgrano", "Chacabuco y Belgrano");
            g.agregar_arco("Chacabuco y Pinto", "Chacabuco y Belgrano");
            g.agregar_arco("Chacabuco y Belgrano", "Fuerte Independencia y Belgrano");
            g.agregar_arco("Fuerte Independencia y Belgrano", "Rodriguez y Belgrano");
            g.agregar_arco("Rodriguez y Pinto", "Rodriguez y Belgrano");
            g.agregar_arco("Rodriguez y Belgrano", "9 de julio y Belgrano");
            g.agregar_arco("9 de julio y Pinto", "9 de julio y Belgrano");
            g.agregar_arco("9 de julio y Belgrano", "Alem y Belgrano");
            g.agregar_arco("Alem y Pinto", "Alem y Belgrano");
            g.agregar_arco("Alem y Belgrano", "Paz y Belgrano");
            g.agregar_arco("Paz y Pinto", "Paz y Belgrano");
            g.agregar_arco("Paz y Belgrano", "Av. Santamarina y Belgrano");
            g.agregar_arco("Av. Santamarina y Pinto", "Av. Santamarina y Belgrano");
            g.agregar_arco("Av. Rivadavia y Mitre", "Av. Rivadavia y Av.España");
            g.agregar_arco("Av. Rivadavia y Av.España", "Av. España y Alberdi");
            g.agregar_arco("Av. España y Alberdi", "Alberdi y Mitre");
            g.agregar_arco("Av. España y Alberdi", "Av. España y San Lorenzo");
            g.agregar_arco("Av. España y San Lorenzo", "San Lorenzo y Mitre");
            g.agregar_arco("Av. España y San Lorenzo", "Av. España y 14 de julio");
            g.agregar_arco("Av. España y 14 de julio", "14 de julio y Mitre");
            g.agregar_arco("Av. España y 14 de julio", "Av. España y Chacabuco");
            g.agregar_arco("Av. España y Chacabuco", "Chacabuco y Mitre");
            g.agregar_arco("Av. España y Chacabuco", "Av. España e Hipolito Yrigoyen");
            g.agregar_arco("Av. España e Hipolito Yrigoyen", "Hipolito Yrigoyen y Mitre");
            g.agregar_arco("Av. España e Hipolito Yrigoyen", "Av. España y Rodriguez");
            g.agregar_arco("Av. España y Rodriguez", "Rodriguez y Mitre");
            g.agregar_arco("Av. España y Rodriguez", "Av. España y 9 de julio");
            g.agregar_arco("Av. España y 9 de julio", "9 de Julio y Mitre");
            g.agregar_arco("Av. España y 9 de julio", "Av. España y Alem");
            g.agregar_arco("Av. España y Alem", "Alem y Mitre");
            g.agregar_arco("Av. España y Alem", "Av. España y Paz");
            g.agregar_arco("Av. España y Paz", "Paz y Mitre");
            g.agregar_arco("Av. España y Paz", "Av. España y Av. Santamarina");
            g.agregar_arco("Av. España y Av. Santamarina", "Av. Santamarina y Mitre");
            g.agregar_arco("Av. Rivadavia y Maipu", "Alberdi y Maipu");
            g.agregar_arco("Alberdi y Belgrano", "Alberdi y Maipu");
            g.agregar_arco("Alberdi y Maipu", "San Lorenzo y Maipu");
            g.agregar_arco("San Lorenzo y Belgrano", "San Lorenzo y Maipu");
            g.agregar_arco("San Lorenzo y Maipu", "14 de julio y Maipu");
            g.agregar_arco("14 de julio y Belgrano", "14 de julio y Maipu");
            g.agregar_arco("14 de julio y Maipu", "Chacabuco y Maipu");
            g.agregar_arco("Chacabuco y Belgrano", "Chacabuco y Maipu");
            g.agregar_arco("Chacabuco y Maipu", "Fuerte Independencia y Maipu");
            g.agregar_arco("Fuerte Independencia y Belgrano", "Fuerte Independencia y Maipu");
            g.agregar_arco("Fuerte Independencia y Maipu", "Rodriguez y Maipu");
            g.agregar_arco("Rodriguez y Belgrano", "Rodriguez y Maipu");
            g.agregar_arco("Rodriguez y Maipu", "9 de julio y Maipu");
            g.agregar_arco("9 de julio y Belgrano", "9 de julio y Maipu");
            g.agregar_arco("9 de julio y Maipu", "Alem y Maipu");
            g.agregar_arco("Alem y Belgrano", "Alem y Maipu");
            g.agregar_arco("Alem y Maipu", "Paz y Maipu");
            g.agregar_arco("Paz y Belgrano", "Paz y Maipu");
            g.agregar_arco("Paz y Maipu", "Av. Santamarina y Maipu");
            g.agregar_arco("Av. Santamarina y Belgrano", "Av. Santamarina y Maipu");
            g.agregar_arco("Av. Rivadavia y 25 de mayo", "Alberdi y 25 de mayo");
            g.agregar_arco("Alberdi y Maipu", "Alberdi y 25 de mayo");
            g.agregar_arco("Alberdi y 25 de mayo", "San Lorenzo y 25 de mayo");
            g.agregar_arco("San Lorenzo y Maipu", "San Lorenzo y 25 de mayo");
            g.agregar_arco("San Lorenzo y 25 de mayo", "14 de julio y 25 de mayo");
            g.agregar_arco("14 de julio y Maipu", "14 de julio y 25 de mayo");
            g.agregar_arco("14 de julio y 25 de mayo", "Chacabuco y 25 de mayo");
            g.agregar_arco("Chacabuco y Belgrano", "Chacabuco y 25 de mayo");
            g.agregar_arco("Chacabuco y 25 de mayo", "Fuerte Independencia y 25 de mayo");
            g.agregar_arco("Fuerte Independencia y Belgrano", "Fuerte Independencia y 25 de mayo");
            g.agregar_arco("Fuerte Independencia y 25 de mayo", "Rodriguez y 25 de mayo");
            g.agregar_arco("Rodriguez y Belgrano", "Rodriguez y 25 de mayo");
            g.agregar_arco("Rodriguez y 25 de mayo", "9 de julio y 25 de mayo");
            g.agregar_arco("9 de julio y Maipu", "9 de julio y 25 de mayo");
            g.agregar_arco("9 de julio y 25 de mayo", "Alem y 25 de mayo");
            g.agregar_arco("Alem y Maipu", "Alem y 25 de mayo");
            g.agregar_arco("Alem y 25 de mayo", "Paz y 25 de mayo");
            g.agregar_arco("Paz y Maipu", "Paz y 25 de mayo");
            g.agregar_arco("Paz y 25 de mayo", "Av. Santamarina y 25 de mayo");
            g.agregar_arco("Av. Santamarina y Maipu", "Av. Santamarina y 25 de mayo");
            g.agregar_arco("Av. Rivadavia y Constitucion", "Alberdi y Constitucion");
            g.agregar_arco("Alberdi y 25 de mayo", "Alberdi y Constitucion");
            g.agregar_arco("Alberdi y Constitucion", "San Lorenzo y Constitucion");
            g.agregar_arco("San Lorenzo y 25 de mayo", "San Lorenzo y Constitucion");
            g.agregar_arco("San Lorenzo y Constitucion", "14 de julio y Constitucion");
            g.agregar_arco("14 de julio y 25 de mayo", "14 de julio y Constitucion");
            g.agregar_arco("14 de julio y Constitucion", "Chacabuco y Constitucion");
            g.agregar_arco("Chacabuco y 25 de mayo", "Chacabuco y Constitucion");
            g.agregar_arco("Chacabuco y Constitucion", "Fuerte Independencia y Constitucion");
            g.agregar_arco("Fuerte Independencia y 25 de mayo", "Fuerte Independencia y Constitucion");
            g.agregar_arco("Fuerte Independencia y Constitucion", "Rodriguez y Constitucion");
            g.agregar_arco("Rodriguez y 25 de mayo", "Rodriguez y Constitucion");
            g.agregar_arco("Rodriguez y Constitucion", "9 de julio y Constitucion");
            g.agregar_arco("9 de julio y 25 de mayo", "9 de julio y Constitucion");
            g.agregar_arco("9 de julio y Constitucion", "Alem y Constitucion");
            g.agregar_arco("Alem y 25 de mayo", "Alem y Constitucion");
            g.agregar_arco("Alem y Constitucion", "Paz y Constitucion");
            g.agregar_arco("Paz y 25 de mayo", "Paz y Constitucion");
            g.agregar_arco("Paz y Constitucion", "Av. Santamarina y Constitucion");
            g.agregar_arco("Av. Santamarina y 25 de mayo", "Av. Santamarina y Constitucion");
            g.agregar_arco("Av. Rivadavia y Av. Avellaneda", "Alberdi y Av. Avellaneda");
            g.agregar_arco("Alberdi y Constitucion", "Alberdi y Av. Avellaneda");
            g.agregar_arco("Alberdi y Av. Avellaneda", "San Lorenzo y Av. Avellaneda");
            g.agregar_arco("San Lorenzo y Constitucion", "San Lorenzo y Av. Avellaneda");
            g.agregar_arco("San Lorenzo y Av. Avellaneda", "14 de julio y Av. Avellaneda");
            g.agregar_arco("14 de julio y Constitucion", "14 de julio y Av. Avellaneda");
            g.agregar_arco("14 de julio y Av. Avellaneda", "Chacabuco y Av. Avellaneda");
            g.agregar_arco("Chacabuco y Constitucion", "Chacabuco y Av. Avellaneda");
            g.agregar_arco("Chacabuco y Av. Avellaneda", "Fuerte Independencia y Av. Avellaneda");
            g.agregar_arco("Fuerte Independencia y Constitucion", "Fuerte Independencia y Av. Avellaneda");
            g.agregar_arco("Fuerte Independencia y Av. Avellaneda", "Rodriguez y Av. Avellaneda");
            g.agregar_arco("Rodriguez y Constitucion", "Rodriguez y Av. Avellaneda");
            g.agregar_arco("Rodriguez y Av. Avellaneda", "9 de julio y Av. Avellaneda");
            g.agregar_arco("9 de julio y Constitucion", "9 de julio y Av. Avellaneda");
            g.agregar_arco("9 de julio y Av. Avellaneda", "Alem y Av. Avellaneda");
            g.agregar_arco("Alem y Constitucion", "Alem y Av. Avellaneda");
            g.agregar_arco("Alem y Av. Avellaneda", "Paz y Av. Avellaneda");
            g.agregar_arco("Paz y Constitucion", "Paz y Av. Avellaneda");
            g.agregar_arco("Paz y Av. Avellaneda", "Av. Santamarina y Av. Avellaneda");
            g.agregar_arco("Av. Santamarina y Constitucion", "Av. Santamarina y Av. Avellaneda");
            g.agregar_arco("Av. Rivadavia y Sarmiento", "Brandsen y Paraguay");
            g.agregar_arco("Brandsen y Paraguay", "Brandsen y Ohiggins");
            g.agregar_arco("Av. Rivadavia y San Martín", "Brandsen y Ohiggins");
            g.agregar_arco("Brandsen y Ohiggins", "Brandsen y Almirante Brown");
            g.agregar_arco("Av. Rivadavia y Pinto", "Brandsen y Almirante Brown");
            g.agregar_arco("Av. Santamarina y Pinto", "4 de abril y Pinto");
            g.agregar_arco("4 de abril y Pinto", "4 de abril y Belgrano");
            g.agregar_arco("Av. Santamarina y Belgrano", "4 de abril y Belgrano");
            g.agregar_arco("4 de abril y Belgrano", "4 de abril y Maipu");
            g.agregar_arco("Av. Santamarina y Maipu", "4 de abril y Maipu");
            g.agregar_arco("4 de abril y Maipu", "4 de abril y 25 de mayo");
            g.agregar_arco("Av. Santamarina y 25 de mayo", "4 de abril y 25 de mayo");

            //cout << "Estructura del grafo:\n" << g << "\n";

            aristas = llenar_conjunto_aristas(g);
            set<string> solucion = posicionar_camaras(aristas);
            int i= solucion.size();
            cout << "La cantidad de camaras aproximadas es: " << i << endl;
            int cantidad_camaras = (i/2);
            cout << "La cantidad de camaras sin tener en cuenta el valor relativo es a lo sumo " << cantidad_camaras << " camaras."<< endl;
            cantidad_camaras = cantidad_camaras + 1;
            cout << endl;
            cout << "Se necesitaran a lo sumo " << cantidad_camaras << " camaras totales."<< endl;
            cout << endl;
            }
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
        break;

        case 2:
            {
            Grafo <int> g;
            list<set<string>> aristas;

            g.agregar_vertice("a");
            g.agregar_vertice("b");
            g.agregar_vertice("c");
            g.agregar_vertice("d");
            g.agregar_vertice("e");
            g.agregar_vertice("f");
            g.agregar_vertice("g");

            g.agregar_arco("a", "b");
            g.agregar_arco("a", "c");
            g.agregar_arco("c", "d");
            g.agregar_arco("c", "e");
            g.agregar_arco("d", "e");
            g.agregar_arco("d", "f");
            g.agregar_arco("d", "g");
            g.agregar_arco("e", "f");

            cout << "Estructura del grafo:\n" << g << "\n";

            aristas = llenar_conjunto_aristas(g);
            set<string> solucion = posicionar_camaras(aristas);
            int i= solucion.size();
            set<string>::iterator itSet = solucion.begin();
            cout << "Se podrian posicionar camaras en las siguientes esquinas: " << endl;
            cout <<"(";
            while (itSet != solucion.end()){
                cout << *itSet << " - ";
                itSet++;
            }
            cout << ")" << endl;
            cout << "La cantidad de camaras aproximadas es: " << i << endl;
            int cantidad_camaras = i/2;
            cout << "Se necesitaran a lo sumo " << cantidad_camaras << " camaras."<< endl;
            }
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
        break;

        case 3:
            {
            Grafo <int> g;
            list<set<string>> aristas;

            g.agregar_vertice("Av. Rivadavia y Mitre");
            g.agregar_vertice("Alberdi y Mitre");
            g.agregar_vertice("San Lorenzo y Mitre");
            g.agregar_vertice("14 de julio y Mitre");
            g.agregar_vertice("Chacabuco y Mitre");
            g.agregar_vertice("Av. Rivadavia y Sarmiento");
            g.agregar_vertice("Av. Rivadavia y San Martín");
            g.agregar_vertice("Av. Rivadavia y Pinto");
            g.agregar_vertice("Av. Rivadavia y Belgrano");
            g.agregar_vertice("Hipolito Yrigoyen y Mitre");
            g.agregar_vertice("Rodriguez y Mitre");
            g.agregar_vertice("9 de Julio y Mitre");
            g.agregar_vertice("Alem y Mitre");
            g.agregar_vertice("Paz y Mitre");
            g.agregar_vertice("Av. Santamarina y Mitre");
            g.agregar_vertice("Alberdi y Sarmiento");
            g.agregar_vertice("San Lorenzo y Sarmiento");
            g.agregar_vertice("14 de Julio y Sarmiento");
            g.agregar_vertice("Chacabuco y Sarmiento");
            g.agregar_vertice("Hipolito Yrigoyen y Sarmiento");
            g.agregar_vertice("Rodriguez y Sarmiento");
            g.agregar_vertice("9 de Julio y Sarmiento");
            g.agregar_vertice("Alem y Sarmiento");
            g.agregar_vertice("Paz y Sarmiento");
            g.agregar_vertice("Av. Santamarina y Sarmiento");
            g.agregar_vertice("Alberdi y San Martin");
            g.agregar_vertice("San Lorenzo y San Martin");
            g.agregar_vertice("14 de julio y San Martin");
            g.agregar_vertice("Chacabuco y San Martin");
            g.agregar_vertice("Hipolito Yrigoyen y San Martin");
            g.agregar_vertice("Rodriguez y San Martin");
            g.agregar_vertice("9 de julio y San Martin");
            g.agregar_vertice("Alem y San Martin");
            g.agregar_vertice("Paz y San Martin");
            g.agregar_vertice("Av. Santamarina y San Martin");
            g.agregar_vertice("Alberdi y Pinto");
            g.agregar_vertice("San Lorenzo y Pinto");
            g.agregar_vertice("14 de julio y Pinto");
            g.agregar_vertice("Chacabuco y Pinto");
            g.agregar_vertice("Hipolito Yrigoyen y Pinto");
            g.agregar_vertice("Rodriguez y Pinto");
            g.agregar_vertice("9 de julio y Pinto");
            g.agregar_vertice("Alem y Pinto");
            g.agregar_vertice("Paz y Pinto");
            g.agregar_vertice("Av. Santamarina y Pinto");
            g.agregar_vertice("Alberdi y Belgrano");
            g.agregar_vertice("San Lorenzo y Belgrano");
            g.agregar_vertice("14 de julio y Belgrano");
            g.agregar_vertice("Chacabuco y Belgrano");
            g.agregar_vertice("Fuerte Independencia y Belgrano");
            g.agregar_vertice("Rodriguez y Belgrano");
            g.agregar_vertice("9 de julio y Belgrano");
            g.agregar_vertice("Alem y Belgrano");
            g.agregar_vertice("Paz y Belgrano");
            g.agregar_vertice("Av. Santamarina y Belgrano");
            g.agregar_vertice("Av. Rivadavia y Av.España");
            g.agregar_vertice("Av. España y Alberdi");
            g.agregar_vertice("Av. España y San Lorenzo");
            g.agregar_vertice("Av. España y 14 de julio");
            g.agregar_vertice("Av. España y Chacabuco");
            g.agregar_vertice("Av. España e Hipolito Yrigoyen");
            g.agregar_vertice("Av. España y Rodriguez");
            g.agregar_vertice("Av. España y 9 de julio");
            g.agregar_vertice("Av. España y Alem");
            g.agregar_vertice("Av. España y Paz");
            g.agregar_vertice("Av. España y Av. Santamarina");

            g.agregar_arco("Av. Rivadavia y Mitre", "Alberdi y Mitre");
            g.agregar_arco("Alberdi y Mitre", "San Lorenzo y Mitre");
            g.agregar_arco("San Lorenzo y Mitre", "14 de julio y Mitre");
            g.agregar_arco("14 de julio y Mitre", "Chacabuco y Mitre");
            g.agregar_arco("Av. Rivadavia y Mitre", "Av. Rivadavia y Sarmiento");
            g.agregar_arco("Av. Rivadavia y San Martín", "Av. Rivadavia y Pinto");
            g.agregar_arco("Av. Rivadavia y Pinto", "Av. Rivadavia y Belgrano");
            g.agregar_arco("Chacabuco y Mitre", "Hipolito Yrigoyen y Mitre");
            g.agregar_arco("Hipolito Yrigoyen y Mitre", "Rodriguez y Mitre");
            g.agregar_arco("Rodriguez y Mitre", "9 de Julio y Mitre");
            g.agregar_arco("9 de Julio y Mitre", "Alem y Mitre");
            g.agregar_arco("Alem y Mitre", "Paz y Mitre");
            g.agregar_arco("Paz y Mitre", "Av. Santamarina y Mitre");
            g.agregar_arco("Av. Rivadavia y Sarmiento", "Alberdi y Sarmiento");
            g.agregar_arco("Alberdi y Mitre", "Alberdi y Sarmiento");
            g.agregar_arco("Alberdi y Sarmiento", "San Lorenzo y Sarmiento");
            g.agregar_arco("San Lorenzo y Mitre", "San Lorenzo y Sarmiento");
            g.agregar_arco("San Lorenzo y Sarmiento", "14 de Julio y Sarmiento");
            g.agregar_arco("14 de julio y Mitre", "14 de Julio y Sarmiento");
            g.agregar_arco("14 de Julio y Sarmiento", "Chacabuco y Sarmiento");
            g.agregar_arco("Chacabuco y Mitre", "Chacabuco y Sarmiento");
            g.agregar_arco("Chacabuco y Sarmiento", "Hipolito Yrigoyen y Sarmiento");
            g.agregar_arco("Hipolito Yrigoyen y Mitre", "Hipolito Yrigoyen y Sarmiento");
            g.agregar_arco("Hipolito Yrigoyen y Sarmiento", "Rodriguez y Sarmiento");
            g.agregar_arco("Rodriguez y Mitre", "Rodriguez y Sarmiento");
            g.agregar_arco("Rodriguez y Sarmiento", "9 de Julio y Sarmiento");
            g.agregar_arco("9 de Julio y Mitre", "9 de Julio y Sarmiento");
            g.agregar_arco("9 de Julio y Sarmiento", "Alem y Sarmiento");
            g.agregar_arco("Alem y Mitre", "Alem y Sarmiento");
            g.agregar_arco("Alem y Sarmiento","Paz y Sarmiento");
            g.agregar_arco("Paz y Mitre", "Paz y Sarmiento");
            g.agregar_arco("Paz y Sarmiento", "Av. Santamarina y Sarmiento");
            g.agregar_arco("Av. Santamarina y Mitre", "Av. Santamarina y Sarmiento");
            g.agregar_arco("Av. Rivadavia y Sarmiento", "Av. Rivadavia y San Martín");
            g.agregar_arco("Av. Rivadavia y San Martín", "Alberdi y San Martin");
            g.agregar_arco("Alberdi y Sarmiento", "Alberdi y San Martin");
            g.agregar_arco("Alberdi y San Martin", "San Lorenzo y San Martin");
            g.agregar_arco("San Lorenzo y Sarmiento", "San Lorenzo y San Martin");
            g.agregar_arco("San Lorenzo y San Martin", "14 de julio y San Martin");
            g.agregar_arco("14 de Julio y Sarmiento", "14 de julio y San Martin");
            g.agregar_arco("14 de julio y San Martin", "Chacabuco y San Martin");
            g.agregar_arco("Chacabuco y Sarmiento", "Chacabuco y San Martin");
            g.agregar_arco("Chacabuco y San Martin", "Hipolito Yrigoyen y San Martin");
            g.agregar_arco("Hipolito Yrigoyen y Sarmiento", "Hipolito Yrigoyen y San Martin");
            g.agregar_arco("Hipolito Yrigoyen y San Martin", "Rodriguez y San Martin");
            g.agregar_arco("Rodriguez y Sarmiento", "Rodriguez y San Martin");
            g.agregar_arco("Rodriguez y San Martin", "9 de julio y San Martin");
            g.agregar_arco("9 de Julio y Sarmiento", "9 de julio y San Martin");
            g.agregar_arco("9 de julio y San Martin", "Alem y San Martin");
            g.agregar_arco("Alem y Sarmiento", "Alem y San Martin");
            g.agregar_arco("Alem y San Martin", "Paz y San Martin");
            g.agregar_arco("Paz y Sarmiento", "Paz y San Martin");
            g.agregar_arco("Paz y San Martin", "Av. Santamarina y San Martin");
            g.agregar_arco("Av. Santamarina y Sarmiento", "Av. Santamarina y San Martin");
            g.agregar_arco("Av. Rivadavia y Pinto", "Alberdi y Pinto");
            g.agregar_arco("Alberdi y San Martin", "Alberdi y Pinto");
            g.agregar_arco("Alberdi y Pinto", "San Lorenzo y Pinto");
            g.agregar_arco("San Lorenzo y San Martin", "San Lorenzo y Pinto");
            g.agregar_arco("San Lorenzo y Pinto","14 de julio y Pinto");
            g.agregar_arco("14 de julio y San Martin", "14 de julio y Pinto");
            g.agregar_arco("14 de julio y Pinto", "Chacabuco y Pinto");
            g.agregar_arco("Chacabuco y San Martin", "Chacabuco y Pinto");
            g.agregar_arco("Chacabuco y Pinto", "Hipolito Yrigoyen y Pinto");
            g.agregar_arco("Hipolito Yrigoyen y San Martin", "Hipolito Yrigoyen y Pinto");
            g.agregar_arco("Hipolito Yrigoyen y Pinto", "Rodriguez y Pinto");
            g.agregar_arco("Rodriguez y San Martin", "Rodriguez y Pinto");
            g.agregar_arco("Rodriguez y Pinto", "9 de julio y Pinto");
            g.agregar_arco("9 de julio y San Martin", "9 de julio y Pinto");
            g.agregar_arco("9 de julio y Pinto", "Alem y Pinto");
            g.agregar_arco("Alem y San Martin", "Alem y Pinto");
            g.agregar_arco("Alem y Pinto", "Paz y Pinto");
            g.agregar_arco("Paz y San Martin", "Paz y Pinto");
            g.agregar_arco("Paz y Pinto", "Av. Santamarina y Pinto");
            g.agregar_arco("Av. Santamarina y San Martin", "Av. Santamarina y Pinto");
            g.agregar_arco("Av. Rivadavia y Belgrano", "Alberdi y Belgrano");
            g.agregar_arco("Alberdi y Pinto", "Alberdi y Belgrano");
            g.agregar_arco("Alberdi y Belgrano", "San Lorenzo y Belgrano");
            g.agregar_arco("San Lorenzo y Pinto", "San Lorenzo y Belgrano");
            g.agregar_arco("San Lorenzo y Belgrano", "14 de julio y Belgrano");
            g.agregar_arco("14 de julio y Pinto", "14 de julio y Belgrano");
            g.agregar_arco("14 de julio y Belgrano", "Chacabuco y Belgrano");
            g.agregar_arco("Chacabuco y Pinto", "Chacabuco y Belgrano");
            g.agregar_arco("Chacabuco y Belgrano", "Fuerte Independencia y Belgrano");
            g.agregar_arco("Fuerte Independencia y Belgrano", "Rodriguez y Belgrano");
            g.agregar_arco("Rodriguez y Pinto", "Rodriguez y Belgrano");
            g.agregar_arco("Rodriguez y Belgrano", "9 de julio y Belgrano");
            g.agregar_arco("9 de julio y Pinto", "9 de julio y Belgrano");
            g.agregar_arco("9 de julio y Belgrano", "Alem y Belgrano");
            g.agregar_arco("Alem y Pinto", "Alem y Belgrano");
            g.agregar_arco("Alem y Belgrano", "Paz y Belgrano");
            g.agregar_arco("Paz y Pinto", "Paz y Belgrano");
            g.agregar_arco("Paz y Belgrano", "Av. Santamarina y Belgrano");
            g.agregar_arco("Av. Santamarina y Pinto", "Av. Santamarina y Belgrano");
            g.agregar_arco("Av. Rivadavia y Mitre", "Av. Rivadavia y Av.España");
            g.agregar_arco("Av. Rivadavia y Av.España", "Av. España y Alberdi");
            g.agregar_arco("Av. España y Alberdi", "Alberdi y Mitre");
            g.agregar_arco("Av. España y Alberdi", "Av. España y San Lorenzo");
            g.agregar_arco("Av. España y San Lorenzo", "San Lorenzo y Mitre");
            g.agregar_arco("Av. España y San Lorenzo", "Av. España y 14 de julio");
            g.agregar_arco("Av. España y 14 de julio", "14 de julio y Mitre");
            g.agregar_arco("Av. España y 14 de julio", "Av. España y Chacabuco");
            g.agregar_arco("Av. España y Chacabuco", "Chacabuco y Mitre");
            g.agregar_arco("Av. España y Chacabuco", "Av. España e Hipolito Yrigoyen");
            g.agregar_arco("Av. España e Hipolito Yrigoyen", "Hipolito Yrigoyen y Mitre");
            g.agregar_arco("Av. España e Hipolito Yrigoyen", "Av. España y Rodriguez");
            g.agregar_arco("Av. España y Rodriguez", "Rodriguez y Mitre");
            g.agregar_arco("Av. España y Rodriguez", "Av. España y 9 de julio");
            g.agregar_arco("Av. España y 9 de julio", "9 de Julio y Mitre");
            g.agregar_arco("Av. España y 9 de julio", "Av. España y Alem");
            g.agregar_arco("Av. España y Alem", "Alem y Mitre");
            g.agregar_arco("Av. España y Alem", "Av. España y Paz");
            g.agregar_arco("Av. España y Paz", "Paz y Mitre");
            g.agregar_arco("Av. España y Paz", "Av. España y Av. Santamarina");
            g.agregar_arco("Av. España y Av. Santamarina", "Av. Santamarina y Mitre");

            //cout << "Estructura del grafo:\n" << g << "\n";

            aristas = llenar_conjunto_aristas(g);
            set<string> solucion = posicionar_camaras(aristas);
            int i= solucion.size();
            cout << "La cantidad de camaras aproximadas es: " << i << endl;
            int cantidad_camaras = (i/2);
            cout << "La cantidad de camaras sin tener en cuenta el valor relativo es a lo sumo " << cantidad_camaras << " camaras."<< endl;
            cantidad_camaras = cantidad_camaras + 1;
            cout << endl;
            cout << "Se necesitaran a lo sumo " << cantidad_camaras << " camaras totales."<< endl;
            cout << endl;
            }
            cout << "Aprete cualquier numero para continuar: ";
            cin >> salida;
        break;
        }
        system("cls");
    }
    return 0;
}

template <typename C>
list<set<string>> llenar_conjunto_aristas (Grafo <C> & g){
    list<set<string>> aristas;
    list<string> vertices;
    g.devolver_vertices(vertices);
    list <typename Grafo<C>::Arco> adyacentes;
    list<string>:: iterator itV = vertices.begin();
    while (itV != vertices.end()){
            g.devolver_adyacentes(*itV, adyacentes);
            typename list<typename Grafo<C>::Arco>::iterator itAdy = adyacentes.begin();
            while (itAdy != adyacentes.end()){
                string vertice = *itV;
                set<string> v;
                v.insert(vertice);
                v.insert(itAdy->devolver_adyacente());
                aristas.push_back(v);
                g.eliminar_arco(vertice, itAdy->devolver_adyacente());
                itAdy++;
            }
            itV++;
    }
    return aristas;
}

void eliminar_arista(list<set<string>> & aristas, string u, string v){
    list<set<string>>::iterator itAristas = aristas.begin();
    set<string> arista;
    arista.insert(u);
    arista.insert(v);
    itAristas++;
    aristas.remove(arista);
    while (itAristas != aristas.end()){
        set<string> a = *itAristas;
        set<string>::iterator itr = a.begin();
            string aris1 = *itr;
            itr++;
            string aris2 = *itr;
            if ((u == aris1)||(u == aris2)){
                list<set<string>>::iterator itEliminar = itAristas;
                itAristas++;
                aristas.erase(itEliminar);
            }else{
                if ((v == aris1)||(v == aris2)){
                    list<set<string>>::iterator itEliminar = itAristas;
                    itAristas++;
                    aristas.erase(itEliminar);
                }else{
                        itAristas++;
                }
            }
    }
}

set<string>  posicionar_camaras(list<set<string>> & aristas){
    set<string> solucion;
    list<set<string>>::iterator itAristas = aristas.begin();
    while (itAristas != aristas.end()){
            list<set<string>>::iterator itAristas = aristas.begin();
        if (itAristas == aristas.end()){
            return solucion;
        }
        set<string> arista = *itAristas;
        set<string>::iterator itr = arista.begin();
        string u = *itr;
        itr++;
        string v = *itr;
        solucion.insert(u);
        solucion.insert(v);
        eliminar_arista(aristas, u, v);
    }
}

void menu(){
    cout << "------------------------------------------------------" << endl;
    cout << "Menu" << endl;
    cout << "1 Obtener la cantidad de camaras necesarias para 117 esquinas"<< endl;
    cout << "2 Obtener la cantidad de camaras necesarias para 7 esquinas" << endl;
    cout << "3 Obtener la cantidad de camaras necesarias para 66 esquinas" << endl;
    cout << "0 Finalizar el proceso" << endl;
}

