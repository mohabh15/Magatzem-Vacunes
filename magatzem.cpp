#include "magatzem.hpp"
using namespace std;

// Constructors
magatzem::magatzem()
// Crea una llista buida anomenada magatzem
{
}

magatzem::magatzem(int n)
// Crea un magatzem amb n cambres
{
}

//Destructors
magatzem::~magatzem()
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 
{
}

// Modificadors
int magatzem::distribuir(string vacuna, int quantitatVacuna, sistema m1)
// Pre:  S’introdueix un identificador de vacuna i una quantitat.
// Post: Si la vacuna no existeix, es produeix un error. 
//       En cas contrari, començant per la cambra inicial es distribueix la quantitat de vacunes de 
//       manera correcta i ordenada com ha estat explicat anteriorment.
//       Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
//       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.
{
}

// Consultors
int consultar_vacuna(Identificador vacuna, sistema m1, cambra c1)
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
            if(m1.find(vacuna) == true)
            {
                ++comptador;
            }
        }
        ++it;
    }
    return comptador;
}

void fi()
// Pre: cert
// Post: Acaba l'execució de la simulació.
{
}