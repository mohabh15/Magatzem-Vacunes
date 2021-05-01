#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
//Pre:
// Post:Crea una llista buida anomenada magatzem
{}
Magatzem::Magatzem(int mida_magatzem)
// Crea un magatzem amb n cambres
{}

//Destructors
Magatzem::~Magatzem()
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 
{}



// Modificadors
int Magatzem::distribuir(string Ident_vacuna, int quant_vacuna)
// Pre:  S’introdueix un identificador de vacuna i una quantitat.
// Post: Si la vacuna no existeix, es produeix un error. 
//       En cas contrari, començant per la cambra inicial es distribueixen totes le vacunes que hi caben. 
//       Un cop acabat l'espai de la primera cambra si queda un nº parell de vacuens es distribueixen
//       la meitat a la cambra de l'esquerra (en aquest cas just la següent de la cambra inicial) i
//       l'altre meitat es distribueix a la cambra de la dreta (la que es troba 2 posicions més enllà
//       de la 1a cambra) i si en queda un nº senar de vacunes s'en distribueixen la meitat més una a la
//       cambra de la dreta. Si no hi ha suficient espai a les cambres per poder guardar totes les vacunes, 
//       torna un enter que indica el nombre d'unitats no s’han pogut distribuir.
{
    int vacunes_distribuides = 0;
    for(list<Cambra>::iterator it = magatzem.begin(); it != magatzem.end(); ++it) 
    // recorrer la llista magatzem
    {
        while(vacunes_distribuides < quant_vacuna)
        {

        }
    }
}

bool Magatzem::treure_vacuna(string Ident_vacuna)
// Pre:  s’introdueix  un  identificador  de  vacuna.
// Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
//       En cas contrari, la vacuna s'elimina del map de vacunes
{
    bool vacuna_treta;
    if(vacunes_donades_alta.find(Ident_vacuna) == vacunes_donades_alta.end() or  vacunes_donades_alta[Ident_vacuna]>0)
    {
        cout<<"error"<<endl;
        vacuna_treta = false;
    }
    else
    {
        //eliminar_vacuna; 
        vacunes_donades_alta.erase(Ident_vacuna);
        vacuna_treta = true;
    }
    return vacuna_treta;
    
}
string Magatzem::afegir_vacuna(string Ident_vacuna)
    // Pre:  s’introdueix un identificador de vacuna.
    // Post: si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
{
    string vacuna_afegida;
    if(vacunes_donades_alta.find(Ident_vacuna) != vacunes_donades_alta.end())
    {
        cout<<"ERROR"<<endl;
        vacuna_afegida = "ERROR";
    }
    else 
    {
        // Afageix la vacuna al diccionari vacunes_donades_alta
        vacunes_donades_alta.insert(make_pair(Ident_vacuna,0));
        vacuna_afegida = Ident_vacuna;
    }
    return vacuna_afegida;
}



// Consultors
int Magatzem::consultar_vacuna(string Ident_vacuna)
// Pre:  S'introdueix un identificador de vacuna
// Post: Si la vacuna no existeix, es produeix un error.  
//       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
{
    int comptador = 0;
    for(list<Cambra>::iterator it = magatzem.begin(); it != magatzem.end(); ++it) 
    // recorrer la llista magatzem
    {
        Cambra c1=*it;
        for(unsigned int j = 0; j < c1.size(); ++j)
        // recorrer la matriu cambra
        {
            if(vacunes_donades_alta.find(Ident_vacuna) != vacunes_donades_alta.end())
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
    bool trobat = false;
    map<string,int>::iterator it = vacunes_donades_alta.find(ident_vacuna);
	if(it == vacunes_donades_alta.end()) 
    {
        trobat = false;
    }
    else 
    {
        trobat = true;
    }
    return trobat;
}

// Lectura i Escriptura
pair <string, int> Magatzem::inventari()
// Pre:  cert
// Post: per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu identificador i la quantitat
//       total en el magatzem, ordenat per identificador de vacuna.
{
    for(map<string, int>::const_iterator it = vacunes_donades_alta.begin(); it != vacunes_donades_alta.end(); ++it)
    {
        cout << "Del tipus de vacuna " << it -> first << " hi ha " << it -> second << "vacunes" << endl;
    }
}


void Magatzem::fi()
// Pre: cert
// Post: Acaba l'execució de la simulació.
{
   cin.ignore();  // perque tot el rato esta llegint llavors una vegada deixi de llegir s'acaba el programa
}