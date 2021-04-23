#include "sistema.hpp"
using namespace std;


void afegir_vacuna(Identificador vacuna)
// Pre:  s’introdueix un identificador de vacuna.
// Post: si la vacuna ja existeix, es produeix un error;
//       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
{

}


void treure_vacuna(Identificador vacuna)
// Pre:  s’introdueix  un  identificador  de  vacuna.
// Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
//       En cas contrari, la vacuna s'elimina del map de vacunes
{

}

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


//L/E
pair <string, int> inventari()
// Pre:  cert
// Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
//       total en el magatzem, ordenat per identificador de vacuna.
{
    
}
