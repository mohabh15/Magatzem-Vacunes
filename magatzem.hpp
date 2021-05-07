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
    // l'string és l'identificador de la vacuna i l'int és la quantitat d'aquella vacuna


    public:

    //Constructor
    Magatzem(); 
    //Pre: cert
    //Post:Crea una llista buida anomenada magatzem
    Magatzem(int mida_magatzem);
    //Pre:  n>0
    //Post: Magatzem amb n cambres    

    //Destructors
    ~Magatzem();
    //Pre: cert
    // Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 

    //Modificadors
    void distribuir(string Ident_vacuna, int quant_vacuna);
    // Pre:  S’introdueix un identificador de vacuna i una quantitat.
    // Post: Si la vacuna no existeix, es produeix un error. 
    //       En cas contrari, començant per la cambra inicial es distribueix la quantitat de vacunes de 
    //       cap a l’esquerra i cap avall de manera que no quedi cap forat ni abans ni entre dues vacunes. 
    //       L’ordre relatiu de les vacunes no s’ha de canviar.
    //       Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
    //       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.
    void afegir_vacuna(string Ident_vacuna);
    // Pre:  s’introdueix un identificador de vacuna.
    // Post: si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
    void treure_vacuna(string Ident_vacuna);
    // Pre:  s’introdueix  un  identificador  de  vacuna.
    // Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
    //       En cas contrari, la vacuna s'elimina del map de vacunes
    void modificar_sistema(string Ident_vacuna, int quantitat, char operacio);
    //Pre: quantitat>0 i Ident_vacuna comença amb J07
    //Post: Posa la quantitat de Ident_vacuna al sistema 

    //Consultors
    int consultar_vacuna(string Ident_vacuna);
    // Pre:  S'introdueix un identificador de vacuna
    // Post: Si la vacuna no existeix, es produeix un error.  
    //       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
    bool find(string ident_vacuna);
    //Pre: ident_vacun es un identificador de vacuna correcte 
    //Post: Retorna true si existeix la vacuna al sistema i false en cualsevol altre cas
    Cambra& cambra(int Ident_cambra);
    //Pre: magatzem.size() > Ident_cambra > 0 
    //Post: retorna la cambra seleccionada

    //L/E
    void inventari();
    // Pre:  cert
    // Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
    //       total en el magatzem, ordenat per identificador de vacuna.
    void fi();
    // Pre:  cert
    // Post: Acaba l'execució de la simulació

};
#endif