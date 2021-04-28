#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::magatzem()
// Crea una llista buida anomenada magatzem
{
}
Magatzem::magatzem(int mida_magatzem)
// Crea un magatzem amb n cambres
{
}

//Destructors
Magatzem::~magatzem()
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
    magatzem1.begin();
    magatzem1.front();
    for(list<cambra>::iterator it = magatzem1.begin(); it != magatzem1.end(); ++it) 
    // recorrer la llista magatzem
    {
        for(unsigned int j = 0; j < c1.size(); ++j)
        // recorrer la matriu cambra
        {
            if(m1.find(Ident_vacuna) == true)
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