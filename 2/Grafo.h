#ifndef GRAFO_H_
#define GRAFO_H_

#include <list>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename C> class Grafo
{
public:
	class Arco
	{
	public:
		Arco();
		Arco(string adyacente, const C & costo);
		string devolver_adyacente() const;
		const C & devolver_costo() const;
	private:
		string vertice;
		C costo;
	}; // class Arco

public:
	// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const;

	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const;

	bool existe_vertice(string vertice) const;

	bool existe_arco(string origen, string destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const C & costo_arco(string origen, string destino) const;

	void devolver_vertices(list<string> & vertices) const;

	void devolver_adyacentes(string origen, list<Arco> & adyacentes) const;

	void agregar_vertice(string vertice);
	//void agregar_vertice(int vertice, int destino, const C & costo);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(string vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(string origen, string destino, const C & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(string origen, string destino, const C & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(string origen, string destino);

	void vaciar();

	//void dfs(list<list<string>> & caminos) const;
	void dfs(list<string> & caminos) const;


private:
    //metodo interno que nos permita hacer la recursión llamado dfs_origen donde le paso un vertice origen
    //y una estructura que nos mantenga los visitados
    void dfs_origen(string origen, string destino, set<string> & visitados,list<string> & caminos) const;

    map <string, list<Arco> > grafo;

}; // class Grafo

/*
 * Arco
 */
//Complejidad constante = O(1)
template <typename C> Grafo<C>::Arco::Arco()
{

}

//Complejidad constante = O(1)
template <typename C> Grafo<C>::Arco::Arco(string adyacente, const C & costo)
{
    this->vertice = adyacente;
    this->costo = costo;
}

//Complejidad constante = O(1)
template <typename C> string Grafo<C>::Arco::devolver_adyacente() const
{
    return this->vertice;
}

//Complejidad constante = O(1)
template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
    return this->costo;
}
/*
 * Grafo
 */
//Complejidad constante = O(1)
template <typename C> Grafo<C>::Grafo(){

}

//Complejidad O(1) constante
template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo){
    grafo = otroGrafo.grafo;
}


//Complejidad O(1) constante
template <typename C> Grafo<C>::~Grafo(){
    vaciar();
}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo){
    grafo= otroGrafo.grafo;
    return *this;
}

//posee asignaciones constantes, un if constante, por ende la complejidad es O(1)
template <typename C> bool Grafo<C>::esta_vacio() const{
    bool es_vacio = false;
    int cantidad = devolver_longitud();
    if (cantidad= 0)
        es_vacio= true;
    return es_vacio;
}

//Complejidad O(n)
template <typename C> int Grafo<C>::devolver_longitud() const{
    grafo.size();
}

//La complejidad es O(log n) ya que la función find logaritmicamente me posiciona en el vértice vertice
//y las demás lineas son constantes O(1) entonces el O(log n)
template <typename C> bool Grafo<C>::existe_vertice(string vertice) const{
    bool existe = false;
    typename map<string, list<Arco> >::const_iterator itV = grafo.find(vertice);
    if (itV != grafo.end())
        existe = true;
    return existe;
}

//La función realiza un find que me posiciona logaritmicamente en el origen es decir es O(log n)
//Luego crea un iterador itA para recorrer toda la lista de adyacencia sería una busqueda lineal es decir O(n)
//finalmente la complejidad de la función existe_arco es O(n log n)
template <typename C> bool Grafo<C>::existe_arco(string origen, string destino) const{
    bool existe = false;
    typename map<string, list<Arco> >::const_iterator itV= grafo.find(origen);
    if (itV != grafo.end()){
        typename list<Arco>::const_iterator itA=itV->second.begin();
        while (!existe && (itA != itV->second.end())){
            Arco arco = *itA;
            if (arco.devolver_adyacente() == destino)
                existe = true;
            itA++;
        }
    }
    return existe;
}

//tengo itV un iterador que realiza un find que se posiciona en origen logaritmicamente complejidad O(log n)
//luego tengo itA un iterador que se posiciona en el comienzo y en el while se realiza una busqueda lineal
//del vértice que en el peor de los casos esta en el final, es decir que tiene complejidad O(n)
template <typename C> const C & Grafo<C>::costo_arco (string origen,string destino) const{
    if (existe_arco(origen, destino)){
        bool encontreVertice= false;
        typename map<string, list<Arco> >:: const_iterator itV = grafo.find(origen); //log n
        if (itV != grafo.end()){
            typename list<Arco>::const_iterator itA=itV->second.begin();             //n
            while (itA != itV->second.end() && (!encontreVertice)){
                Arco arco= *itA;
                if (arco.devolver_adyacente() == destino){
                    return arco.devolver_costo();
                    encontreVertice = true;
                }
            itA++;
            }
        }
    }
}

//El metodo devolver vertices posee un iterador itV que se posiciona en el inicio con el begin, y recorre
//todos los vertices linealmente hasta el final cuando hace el bucle while esto posee una complejidad O(n).
//la función push_back posee complejidad O(1). Por ende la complejidad total del metodo es O(n)
template <typename C> void Grafo<C>::devolver_vertices (list<string> & vertices) const{
    typename map<string, list<Arco> >::const_iterator itV = grafo.begin();
    while (itV != grafo.end()){
        vertices.push_back(itV->first);
        itV++;
    }
}

//La complejidad de encontrar el vértice origen con la función find es logaritmica, y la sentencia if es
//constante por ende la complejidad de devolver_adyacentes es O(log n)
template <typename C> void Grafo<C>::devolver_adyacentes(string origen, list<Arco> & adyacentes) const{
    typename map<string, list<Arco> >::const_iterator itV=grafo.find(origen);
    if(itV != grafo.end())
        adyacentes= itV->second;
}

//Complejidad O(1) ya que solo realiza funciones constantes.
template <typename C> void Grafo<C>::agregar_vertice(string vertice){
    list <Arco> lista1;
    grafo[vertice]= lista1;
}

//tengo un iterador itV que comienza en el inicio y recorre hasta el final el primer elemento del mapa, es decir
//todos los vértices, con complejidad lineal O(n). Luego encuentro el vértice vertice logaritmicamente con la
//funcion find con complejidad O(log n) por ende la complejidad total es O(n log n)
template <typename C> void Grafo<C>::eliminar_vertice(string vertice){
   typename map<string, list<Arco> >::iterator itV= grafo.begin();
    while(itV != grafo.end()){
        eliminar_arco(itV->first, vertice);
        itV++;
    }
    itV= grafo.find(vertice);
    if (itV != grafo.end())
            grafo.erase(itV);
}

//tengo el iterador itV que realiza la función find que encuentra el vértice origen de manera logaritmica es
//decir complejidad O(log n)
//Luego tengo el iterador itA que se posiciona en el inicio de la lista de adyacencia y la recorre linealmente
//con una complejidad O(n)
//la complejidad final de modificar_costo_arco es O(n log n).
template <typename C> void Grafo<C>::modificar_costo_arco(string origen, string destino, const C & costo){
    if(existe_arco(origen, destino)){
        bool encontre = false;
        typename map<string, list<Arco> >::iterator itV= grafo.find(origen);
        if (itV != grafo.end()){
            typename list<Arco>::iterator itA= itV->second.begin();
            while (itA!=itV->second.end()&& (!encontre)){
                Arco arco = *itA;
                if (arco.devolver_adyacente()==destino){
                    encontre=true;
                    eliminar_arco(origen, destino);
                    agregar_arco(origen, destino, costo);
                }
                itA++;
            }
        }
    }
}

//Tegno el iterador itr que de forma logaritmica(find) encuentra el vertice origen O(log n)
//luego tengo tres sentencias if constantes.  Como push_back es constante O(1), el metodo finaliza con
//complejidad O(log n)
template <typename C> void Grafo<C>::agregar_arco(string origen, string destino, const C & costo){
    typename map<string, list<Arco> >::iterator itr= grafo.find(origen);
    if (existe_vertice(origen) && existe_vertice(destino)){
            if ((origen!="Rauch")||(destino!="Las Flores")){            //Condicion para que no sea considerada
                if (!existe_arco(origen, destino)){                     //la ruta de Rauch a Las Flores o de
                    itr->second.push_back(Arco(destino,costo));         //Las Flores a Racuh
                    itr= grafo.find(destino);
                    itr->second.push_back(Arco(origen, costo));
                }
            }
        }
}
//En la linea 268 establezco una sentencia if para cumplir la condición pedida en el tp inciso B, ya que pide
//que la ruta de Rauch a las Flores esta inhabilitada. Sin embargo tomo que no puede pasar por ese arco, pero
//si puede pasar por otro arco que seria otra ruta que va por ejemplo desde las flores a cachari y desde cachari
//a Rauch. Yo interpreto de la consigna que si puede pasar por Rauch y por Las Flores, pero no puede tomar la
//ruta que va desde Las Flores a Rauch y viceversa, es decir la arista que une esos dos vertices.

//El metodo eliminar_arco posee un iterador itV que encuentra logaritmicamente al vértice origen con el find que
//posee complejidad O(log n). Luego creo el iterador itA que recorre linealmente la lista de adyacentes desde el
//inicio hasta el final, la complejidad es O(n). Complejidad total O(n log n)
template <typename C> void Grafo<C>::eliminar_arco(string origen, string destino){
    typename map<string, list<Arco> >::iterator itV= grafo.find(origen);
    typename list<Arco>::iterator itA= itV->second.begin();
    if (existe_arco(origen, destino)){
        if (itV != grafo.end()){
            while ((itA != itV->second.end())&& (itA->devolver_adyacente()!=destino)){
                itA++;
            }
            if(itA!=itV->second.end()){
                itV->second.erase(itA);
            }
        }
        itV=grafo.find(destino);
        itA= itV->second.begin();
        while ((itA != itV->second.end())&& (itA->devolver_adyacente()!=origen)){
                itA++;
            }
        if(itA!=itV->second.end()){
            itV->second.erase(itA);
        }
    }
}

//La complejidad es O(n), ya que el clear es lineal
template <typename C> void Grafo<C>::vaciar(){
    grafo.clear();
}

//La complejidad del dfs es O(log n), ya que el find encuentra el vertice origen logaritmicamente
 template <typename C> void Grafo<C>::dfs(list<string> & caminos) const{
    set <string> visitados;
    string origen = "Buenos Aires";
    string destino = "Tandil";
    typename map<string, list<Arco> >::const_iterator itV = grafo.find(origen);
    dfs_origen(itV->first, destino, visitados, caminos);
}


//Complejidad del dfs_origen es O(n log n)
template <typename C> void Grafo<C>::dfs_origen(string origen, string destino, set<string> & visitados,list<string> & caminos) const{
    visitados.insert(origen);
    caminos.push_back(origen);
    typename map<string, list<Arco> >::const_iterator itV= grafo.find(origen);      //find -->O(log n)
    typename list<Arco>::const_iterator itA= itV->second.begin();
    typename list<string>::iterator itL= caminos.begin();
    typename set<string>::iterator itSet = visitados.find(origen);
    if (origen == destino){                                                         //O(1)
       //imprimir (caminos);
        while (itL!= caminos.end()){                                         //se que la clase grafo no deberia
            cout << *itL << "-";                                             //saber imprimir por pantalla pero
            itL++;                                                          //no supe como hacerlo desde el main
        }
        cout << endl;
    }else{
        while (itA != itV->second.end()){                                           //recorrido lineal O(n)
            if (visitados.find(itA->devolver_adyacente())== visitados.end())
                dfs_origen(itA->devolver_adyacente(),destino, visitados, caminos);
            itA++;
        }
    }
    caminos.pop_back();
    if (itSet != visitados.end())
        visitados.erase(itSet);                        //marca el ultimo vértice que fue visita como no visitado
    }

#endif /* GRAFO_H_ */
