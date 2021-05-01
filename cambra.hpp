#ifndef _CAMBRA_HPP_
#define _CAMBRA_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

typedef vector<vector<string>> Matriu;

class Cambra
{
    private:

    Matriu cambra;

    public:

    //Constructores
    Cambra(int x, int y);
    //Pre:Cert
    //Post:crea una matriu de x files i y columnes 


    //Modificadores
    int afegir_unitats(string ident_vacuna,int quantitat);
    //Pre: Identificacio de vacuna ha de començar amb "J07"
    //Post:Si la vacuna no existeix,  es produeix un error.  En cas contrari, es posen tantes unitats 
    //com capiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut.
    int treure_unitats(string ident_vacuna, int quantitat);
    //Pre: Identificacio de vacuna ha de començar amb "J07"
    //Post: Si la vacuna no existeix dona error, en cas contrari es torna la quantitat que no s'ha 
    //pogut treure perque no hi havia suficients a la cambra 
    void comprimir();
    //Pre: cert
    //Post:  Es desplacen les vacunes cap a l’esquerra i cap avall de manera que no resti cap forat
    //entre dues vacunes ni abans de cap vacuna
    void ordenar();
    //Pre: cert
    //Post: S’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats
    //entre elles ni abans de cap vacuna
    void canviar_nevera(int files, int columnes);
    //Pre: cert
    //Post: Es crea un nova nevera amb les dimension de files i columnes si el contingut de la antigua nevera
    //caben en la nova, si no dona error  


    //Consultores
    string consultar_posicio(int fila, int columna);
    //Pre:cert
    //Post:S’indicaquina vacuna hi ha en la posici ́o corresponent de la nevera de la cambra. Si no hi hacap vacuna, s’escriu NULL
    unsigned int size();
    //Pre: cert
    //Post: retorna la mida de la matriu cambra
    bool plena();
    //Pre: cert
    //Post: retorna true si la cambra està plena i false en cas contrari

    //L/E
    void escriure();
    //Pre: cert
    //Post: S’escriu el contingut de la neverade la cambra de dalt a baix i d’esquerra a dreta. On hi hagi un forat s’escriu NULL.
    //Tamb ́e s’escriu quantes unitats hi ha en total i,  per ordre d’identificador de vacunaexistent en la nevera, 
    //s’escriuen l’identificador de vacuna i la seva quantitat
};
#endif
