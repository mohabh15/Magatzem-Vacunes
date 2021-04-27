#include <list>

#include "cambra.hpp"
//#include "sistema.hpp"

using namespace std;

class Magatzem
{
    private:

    list<cambra> magatzem; 

    public:

    //Constructor
    Magatzem(int n);
    //Pre: n>0
    //Post: Magatzem amb n cambres    

    //Modificadors
    int distribuir(string ident_vacuna, int quant_vacuna, sistema m1);
    // Pre: S’introdueix un identificador de vacuna i una quantitat.
    // Post: Si la vacuna no existeix, es produeix un error. 
    //       En cas contrari, començant per la cambra inicial es distribueix la quantitat de vacunes de 
    //       manera correcta i ordenada com ha estat explicat anteriorment.
    //       Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
    //       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.

    //Consultors
    int consultar_vacuna(int ident_vacuna, sistema m1);
    // Pre: S'introdueix un identificador de vacuna
    // Post: Si la vacuna no existeix, es produeix un error.  
    //       En cas contrari, escriu quantes unitats d'aquesta vacuna en concret 
    //       hi ha al magatzem en total
    
    void fi();
    // Pre: cert
    // Post: Acaba l'execució de la simulació

};