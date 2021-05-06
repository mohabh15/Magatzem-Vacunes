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
    list<Cambra>::iterator it = magatzem.end(); 
    Cambra aux;
    while(mida_magatzem>0)
    {
        magatzem.insert(it,aux);
        --mida_magatzem;
    }
}


//Destructors
Magatzem::~Magatzem()
// Post: esborra automaticament els objectes locals en sortir d'un ambit de visibilitat 
{}


// Modificadors
/*void Magatzem::distribuir(string Ident_vacuna, int quant_vacuna)
// Pre:  S’introdueix un identificador de vacuna i una quantitat.
// Post: Si la vacuna no existeix, es produeix un error. 
//       En cas contrari, començant per la cambra inicial es distribueixen totes le vacunes que hi caben.
//       Un cop acabat l'espai de la primera cambra si queda un nº parell de vacuens es distribueixen la meitat
//       a partir de la cambra seguent per l’esquerra i l’altra meitat a partir de la cambra seguent per la dreta.
//       I si en queda un nº senar de vacunes s'en distribueixen per l'esquerra el restant.
//       Finalemnt torna un enter que indica el nombre d'unitats no s’han pogut distribuir.   

{}*/

void Magatzem::treure_vacuna(string Ident_vacuna)   
// Pre:  s’introdueix  un  identificador  de  vacuna.
// Post: si  la  vacuna  no  existeix,  o existeix i en queden unitats, es produeix un error. 
//       En cas contrari, la vacuna s'elimina del map de vacunes
{
    if(vacunes_donades_alta.find(Ident_vacuna) == vacunes_donades_alta.end() or  vacunes_donades_alta[Ident_vacuna]>0)
    {
        cout << "error" << endl;
    }
    else
    {
        //eliminar_vacuna; 
        vacunes_donades_alta.erase(Ident_vacuna);
    }
}

void Magatzem::afegir_vacuna(string Ident_vacuna)
    // Pre:  s’introdueix un identificador de vacuna.
    // Post: si la vacuna ja existeix, es produeix un error;
    //       sinó, la vacuna s'afegeix al sistema amb 0 unitats.
{
    if(vacunes_donades_alta.find(Ident_vacuna) != vacunes_donades_alta.end())
    {
        cout<<"error"<<endl;
    }
    else 
    {
        // Afageix la vacuna al diccionari vacunes_donades_alta
        vacunes_donades_alta.insert(make_pair(Ident_vacuna,0));
    }
}

void Magatzem::modificar_sistema(string Ident_vacuna, int quantitat)
//Pre: quantitat>0 i Ident_vacuna comença amb J07
//Post: Posa la quantitat de Ident_vacuna al sistema 
{
    vacunes_donades_alta[Ident_vacuna]=quantitat;
}


// Consultors
int Magatzem::consultar_vacuna(string Ident_vacuna)  
// Pre:  S'introdueix un identificador de vacuna
// Post: Si la vacuna no existeix, es produeix un error.  
//       En cas contrari, escriu quantes unitats hi ha en total al magatzem d'aquesta vacuna en concret.
{
    int comptador = 0;
    if(vacunes_donades_alta.find(Ident_vacuna) != vacunes_donades_alta.end())
    {
        cout<<"error"<<endl;
    }
    else 
    {
        // recorrer la llista magatzem
        for(list<Cambra>::iterator it = magatzem.begin(); it != magatzem.end(); ++it) 
        {
            Cambra c1=*it;
            // recorrer la matriu cambra
            for(unsigned int i = 0; i < c1.files(); ++i)
            {
                for(unsigned int j = 0; j < c1.columnes(); ++j)
                {
                    if(c1.consultar_posicio(i,j)==Ident_vacuna) ++comptador;
                }
            }
        }
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

Cambra& Magatzem::cambra(int Ident_cambra)
{
    list<Cambra>::iterator it = magatzem.begin(); 
    for(int i=1; i<Ident_cambra; ++i) 
    {
        ++it;
    }
    return *it;
}


// Lectura i Escriptura
void Magatzem::inventari()   //es el total que hi ha al magatzem no al sistema si no cada vegada que s'hafegixi al magatzem s'ha d'afegir al sistema tambe aixi tenir al sistema la quantitat total que hi ha al magatzem que té sentit  
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
   cin.ignore();  // perque tot l'estona esta llegint llavors una vegada deixi de llegir s'acaba el programa
}