#ifndef _MAGATZEM_HPP_
#define _MAGATZEM_HPP_

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "cambra.hpp"

using namespace std;

class Magatzem
{
    private:

    list<Cambra> magatzem;

    
    map<string,int> vacunes_donades_alta;    
    // L'string és l'identificador de la vacuna i l'int és la quantitat d'aquella vacuna


    public:

    // Constructor
    Magatzem(); 
    // Pre:  Cert.
    // Post: Crea una llista buida anomenada magatzem.
    Magatzem(int mida_magatzem);
    // Pre:  n > 0.
    // Post: Crea un magatzem amb n cambres.

    // Destructors
    ~Magatzem();
    // Pre:  Cert.
    // Post: Esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat.

    // Modificadors
    int distribuir(string Ident_vacuna, int quant_vacuna);
    // Pre:  S’introdueix un identificador de vacuna i una quantitat.
    // Post: Si la vacuna no existeix, es produeix un error. 
    //       En cas contrari, començant per la cambra inicial es distribueixen totes le vacunes que hi caben.
    //       Un cop acabat l'espai de la primera cambra si queda un nº parell de vacunes es distribueixen la meitat
    //       a partir de la cambra següent per l’esquerra i l’altra meitat a partir de la cambra següent per la dreta.
    //       I si queda un nº senar de vacunes la vacuna restant es distribueix per l'esquerra.
    //       Finalemnt torna un enter que indica el nombre d'unitats no s’han pogut distribuir. 
    void afegir_vacuna(string Ident_vacuna);
    // Pre:  S’introdueix un identificador de vacuna.
    // Post: Si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
    void treure_vacuna(string Ident_vacuna);
    // Pre:  S’introdueix  un  identificador  de  vacuna.
    // Post: Si la vacuna no existeix, o existeix i en queden unitats, es produeix un error. 
    //       En cas contrari, la vacuna s'elimina del map de vacunes.
    void modificar_sistema(string Ident_vacuna, int quantitat, char operacio);
    //Pre:  quantitat > 0 i Ident_vacuna comença amb J07.
    //Post: Posa la quantitat de Ident_vacuna al sistema.

    // Consultors
    int consultar_vacuna(string Ident_vacuna);
    // Pre:  S'introdueix un identificador de vacuna
    // Post: Si la vacuna no existeix, es produeix un error.  
    //       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
    bool find(string ident_vacuna);
    //Pre:  ident_vacuna es un identificador de vacuna correcte.
    //Post: Retorna true si existeix la vacuna al sistema i false en cualsevol altre cas.
    Cambra& cambra(int Ident_cambra);
    //Pre:  magatzem.size() > Ident_cambra > 0 
    //Post: Retorna la cambra seleccionada.

    //Lectura i Escriptura
    void inventari() const;
    // Pre:  Cert.
    // Post: Per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
    //       total en el magatzem, ordenat per identificador de vacuna.
    void fi() const;
    // Pre:  Cert.
    // Post: Acaba l'execució de la simulació.

};
#endif