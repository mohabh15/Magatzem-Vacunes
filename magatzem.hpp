#include <list>
#include "cambra.hpp"
using namespace std;

class magatzem
{
    private:

    list<cambra> magatzem1;      

    public:

    //Creadores
    magatzem(int n);
    //Pre: n>0
    //Post: Magatzem amb n cambres    

    //Modificadores
    int distribuir(string vacuna, int quantitatVacuna, sistema m1);
    // Pre: S’introdueix un identificador de vacuna i una quantitat.
    // Post: Si la vacuna no existeix, es produeix un error. 
    //       En cas contrari, començant per la cambra inicial es distribueix la quantitat de vacunes 
    //       segons la polı́tica explicada anteriorment. 
    //       Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
    //       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.

    //Consultores
    int consultar_vacuna(Identificador vacuna, sistema m1);
    // Pre: S'introdueix un identificador de vacuna
    // Post: Si la vacuna no existeix, es produeix un error.  
    //       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
    
    void fi();
    // Pre: cert
    // Post: Acaba l'execució de la simulació

};