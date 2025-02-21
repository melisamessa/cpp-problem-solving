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
		Arco(string adyacente);
		string devolver_adyacente() const;
	private:
		string vertice;

	}; // class Arco

public:
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	bool esta_vacio() const;

	int devolver_longitud() const;

	bool existe_vertice(string vertice) const;

	bool existe_arco(string origen, string destino) const;

	void devolver_vertices(list<string> & vertices) const;

	void devolver_adyacentes(string origen, list<Arco> & adyacentes) const;

	void agregar_vertice(string vertice);

	void eliminar_vertice(string vertice);

	void agregar_arco(string origen, string destino);

	void eliminar_arco(string origen, string destino);

	void vaciar();

private:

    map <string, list<Arco> > grafo;

}; // class Grafo

/*
 * Arco
 */

template <typename C> Grafo<C>::Arco::Arco()
{

}

template <typename C> Grafo<C>::Arco::Arco(string adyacente)
{
    this->vertice = adyacente;
}

template <typename C> string Grafo<C>::Arco::devolver_adyacente() const
{
    return this->vertice;
}

/*
 * Grafo
 */

template <typename C> Grafo<C>::Grafo(){

}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo){
    grafo = otroGrafo.grafo;
}

template <typename C> Grafo<C>::~Grafo(){
    vaciar();
}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo){
    grafo= otroGrafo.grafo;
    return *this;
}

template <typename C> bool Grafo<C>::esta_vacio() const{
    bool es_vacio = false;
    int cantidad = devolver_longitud();
    if (cantidad= 0)
        es_vacio= true;
    return es_vacio;
}

template <typename C> int Grafo<C>::devolver_longitud() const{
    grafo.size();
}

template <typename C> bool Grafo<C>::existe_vertice(string vertice) const{
    bool existe = false;
    typename map<string, list<Arco> >::const_iterator itV = grafo.find(vertice);
    if (itV != grafo.end())
        existe = true;
    return existe;
}

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

template <typename C> void Grafo<C>::devolver_vertices (list<string> & vertices) const{
    typename map<string, list<Arco> >::const_iterator itV = grafo.begin();
    while (itV != grafo.end()){
        vertices.push_back(itV->first);
        itV++;
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(string origen, list<Arco> & adyacentes) const{
    typename map<string, list<Arco> >::const_iterator itV=grafo.find(origen);
    if(itV != grafo.end())
        adyacentes= itV->second;
}

template <typename C> void Grafo<C>::agregar_vertice(string vertice){
    list <Arco> lista1;
    grafo[vertice]= lista1;
}

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

template <typename C> void Grafo<C>::agregar_arco(string origen, string destino){
    typename map<string, list<Arco> >::iterator itr= grafo.find(origen);
    if (existe_vertice(origen) && existe_vertice(destino)){
                if (!existe_arco(origen, destino)){
                    itr->second.push_back(Arco(destino));
                    itr= grafo.find(destino);
                    itr->second.push_back(Arco(origen));
                }
    }
}

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

template <typename C> void Grafo<C>::vaciar(){
    grafo.clear();
}

#endif /* GRAFO_H_ */
