#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
{}

Magatzem::Magatzem(int mida_magatzem)
{
    /*
    list<Cambra>::iterator it = magatzem.end(); 
    Cambra aux;
    while(mida_magatzem>0)
    {
        magatzem.insert(it,aux);
        --mida_magatzem;
    }
    */
   
}


//Destructor
Magatzem::~Magatzem()
{}


// Modificadors

int Magatzem::distribuir(string Ident_vacuna, int quant_vacuna, Cambra &cambra)  
{
    int vacunes_no_distribuides;
    if(not find(Ident_vacuna))
    {
        cout << "error" << endl;
    }
    else
    {
        vacunes_no_distribuides = magatzem.arrel.afegir_unitat(Ident_vacuna, quant_vacuna)
        if(vacunes_no_distribuides == 0)
        {
            bucle_no_acabat = false;
        }
        while(bucle_no_acabat)
        {
            if(cnt_cambres >= mida_magatzem)
            {
                bucle_no_acabat = false;
            }
            //recorrer l'arbre binari recursivament
            distribuir_recursivament(vacunes_no_distribuides, cambra);
        }
    }
    return vacunes_no_distribuides;    


void Magatzem::distribuir_recursivament(string Ident_vacuna, int quant_vacuna, Cambra &cambra)
{
    int quant_vacuna1 = quant_vacuna;
    if(quant_vacuna1 == 0)
    {
        fi_distribuir;
    }
    else if(quant_vacuna1 == 1)
    {
        fe().afegir_unitats(Ident_vacuna, 1);
    }
    distribuir_recursivament(Ident_vacuna, vacunes_no_distribuides)/2 + 1, fe());
    distribuir_recursivament(Ident_vacuna, vacunes_no_distribuides)/2, fd());

}


void Magatzem::afegir_vacuna(string Ident_vacuna)
{
    if(vacunes_donades_alta.find(Ident_vacuna) != vacunes_donades_alta.end())
    {
        cout << " error" << endl;
    }
    else 
    {
        // Afageix la vacuna al diccionari vacunes_donades_alta
        vacunes_donades_alta.insert(make_pair(Ident_vacuna,0));
    }
}

void Magatzem::treure_vacuna(string Ident_vacuna)   
{
    if(vacunes_donades_alta.find(Ident_vacuna) == vacunes_donades_alta.end() or vacunes_donades_alta[Ident_vacuna]>0)
    {
        cout << "error" << endl;
    }
    else
    {
        vacunes_donades_alta.erase(Ident_vacuna);
    }
}

void Magatzem::modificar_sistema(string Ident_vacuna, int quantitat, char operacio)
{
    if(operacio=='+') 
    {
        vacunes_donades_alta[Ident_vacuna]=vacunes_donades_alta[Ident_vacuna]+quantitat;
    }
    if(operacio=='-') 
    {
        vacunes_donades_alta[Ident_vacuna]=vacunes_donades_alta[Ident_vacuna]-quantitat;
        if(vacunes_donades_alta[Ident_vacuna]<0) vacunes_donades_alta[Ident_vacuna]=0;
    }
}

// Consultors
int Magatzem::consultar_vacuna(string Ident_vacuna) 
{
    if(vacunes_donades_alta.find(Ident_vacuna) == vacunes_donades_alta.end())
    {
       return -1;
    }
    else 
    {
        return vacunes_donades_alta[Ident_vacuna];
    }
    return 0;
}

bool Magatzem::find(string ident_vacuna) 
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
void Magatzem::inventari() const  
{
    for(map<string, int>::const_iterator it = vacunes_donades_alta.begin(); it != vacunes_donades_alta.end(); ++it)
    {
        cout << " " << it->first << " " << it->second << endl;
    }
}

void Magatzem::fi() const
{
   // Com que tota l'estona està llegint al cridar el mètode fi deixarà de llegir i s'acabarà el programa
   cin.ignore();  
}