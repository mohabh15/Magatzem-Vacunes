#include <map>
#include <string>

using namespace std;

typedef string Identificador;

class sistema
{
    private:
    
    map<string,int> sistema;    
    // l'string és l'identificador de la vacuna i l'int és la quantitat d'aquella vacuna


    public:

    //Modificadores 
    void afegir_vacuna(string ident_vacuna);
    // Pre:  s’introdueix un identificador de vacuna.
    // Post: si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.

    void treure_vacuna(string ident_vacuna);
    // Pre:  s’introdueix  un  identificador  de  vacuna.
    // Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
    //       En cas contrari, la vacuna s'elimina del map de vacunes

    //Consultores
    bool find(string ident_vacun);
    //Pre: ident_vacun es un identificador de vacuna correcte 
    //Post: Retorna true si existeix la vacuna al sistema i false en cualsevol altre cas

    // Lectura i Escriptura
    pair <string, int> inventari();   // crec que hauria d'anar a magatzem perque diu quantes vacunes hi ha de cada tipus al magatzem no al sistema
    // Pre:  cert
    // Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
    //       total en el magatzem, ordenat per identificador de vacuna.
};