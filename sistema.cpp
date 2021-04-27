#include <map>

#include "sistema.hpp"

using namespace std;

// Constructors
void sistema::afegir_vacuna(Identificador vacuna)
// Pre:  s’introdueix un identificador de vacuna.
// Post: si la vacuna ja existeix, es produeix un error;
//       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
{
    /*
    if(existeix_vacuna)
    {
        error;
    }
    else
    {
        afegir_vacuna;
    }
    */
}

void sistema::treure_vacuna(Identificador vacuna)
// Pre:  s’introdueix  un  identificador  de  vacuna.
// Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
//       En cas contrari, la vacuna s'elimina del map de vacunes
{
    /*
    if(no_existeix_vacuna or no_queden_unitats)
    {
        error;
    }
    else
    {
        eliminar_vacuna;
    }
    */
}

// Destructors
sistema::~sistema()
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 
{
}

// Consultors
bool sistema::find(string ident_vacuna)
//Pre: ident_vacun es un identificador de vacuna correcte 
//Post: Retorna true si existeix la vacuna al sistema i false en qualsevol altre cas
{
    bool trobat=false;
    map<string,int>::iterator it=sistema.find(ident_vacuna);
	if(it==sistema.end()) trobat=false;
    else trobat=true;
    return trobat;
}


// Lectura i Escriptura
pair <string, int> sistema::inventari(sistema m1) 
// Pre:  cert
// Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
//       total en el magatzem, ordenat per identificador de vacuna.
{
    string vacuna;
    int no_de_vacunes = 0;
    for(unsigend int i = 0; i < )
}