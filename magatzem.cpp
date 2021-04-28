#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
//Pre:
// Post:Crea una llista buida anomenada magatzem
{}
Magatzem::Magatzem(int mida_magatzem)
// Crea un magatzem amb n cambres
{
}

//Destructors
Magatzem::~Magatzem()
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 
{
}



// Modificadors
int Magatzem::distribuir(string Ident_vacuna, int quant_vacuna)
// Pre:  S’introdueix un identificador de vacuna i una quantitat.
// Post: Si la vacuna no existeix, es produeix un error. 
//       En cas contrari, començant per la cambra inicial es distribueix la quantitat de vacunes de 
//       manera correcta i ordenada com ha estat explicat anteriorment.
//       Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
//       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.
{
}
void Magatzem::treure_vacuna(string Ident_vacuna)
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
void Magatzem::afegir_vacuna(string Ident_vacuna)
    // Pre:  s’introdueix un identificador de vacuna.
    // Post: si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
{

}



// Consultors
int Magatzem::consultar_vacuna(string Ident_vacuna)
// Pre:  S'introdueix un identificador de vacuna
// Post: Si la vacuna no existeix, es produeix un error.  
//       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
{
    int comptador = 0;
    for(list<cambra>::iterator it = magatzem.begin(); it != magatzem.end(); ++it) 
    // recorrer la llista magatzem
    {
        for(unsigned int j = 0; j < *it.size(); ++j)
        // recorrer la matriu cambra
        {
            if(sistema.find(Ident_vacuna)!=sistema.end())
            {
                ++comptador;
            }
        }
        ++it;
    }
    return comptador;
}
bool Magatzem::find(string ident_vacuna)
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
pair <string, int> Magatzem::inventari()
// Pre:  cert
// Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
//       total en el magatzem, ordenat per identificador de vacuna.
{
    
}


void Magatzem::fi()
// Pre: cert
// Post: Acaba l'execució de la simulació.
{
   cin.ignore();
}