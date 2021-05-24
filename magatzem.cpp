#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
{}

Magatzem::Magatzem(list<int>& llista_cambres)    //como darselo para que con un simple cin en 
{
    //Cin distribució cambres magatzem
    bool afegir_fd = false, ple;
    int e, x, i = 0;
    //afegir_arrel
    {
        e = llista_cambres(i);//utilitzar iteradors o punt d'interès
        x = e;
        ++i;
    }
    while(not llista_cambres.empty())
    {
        if(e != 0)
        {
            if(afegir_fd)
            {
                x.fd() = e;   //quan fas x.fd() que es? en plan sembla que estiguis afegint el fill dret pero x es un enter no un arbre, aixo no hauria d'anar al paramatre implicit es a dir l'arbre magatzem declarat al privat? 
                x = e;              //Sugerencia: activa intellisense del visual studio si no el tens aixi vas vien els errors sense haver de compilar i vas veient si el que fas es pot o no 
                afegir_fd = false;
            }
            else
            {
                x.fe() = e;
                x = e;
            }
        }
        else //e == 0
        {
            if(afegir_fd)
            {
                while(x not ple)
                {
                    x = x.arrel();
                }
            }
            else
            {
                afegir_fd = true;
            }
        }
        ++i;
    }


}



//Destructor
Magatzem::~Magatzem()
{}


// Modificadors

int Magatzem::distribuir(string ident_vacuna, int quant_vacuna, Cambra &cambra)  //Cambra es metode de la propia classe i estas dins de la classe pots accedir al privat directament que en aquest cas seria l'arbre magatzem que conte les cambres que vols 
{
    int vacunes_no_distribuides;
    if(not find(ident_vacuna))
    {
        cout << "error" << endl;
        vacunes_no_distribuides = quant_vacuna;
    }
    else
    {
        //recorrer l'arbre binari recursivament
        distribuir_recursivament(ident_vacuna, vacunes_no_distribuides, cambra);
    }
    magatzem.modificar_sistema(ident_vacuna, quant_vacuna - vacunes_no_distribuides, '+');  //estas editant el map dins de la classe pots accedir al map directament no fa falta cridar al metode de la mateixa classe en la que estas 

    return vacunes_no_distribuides;    
}

int Magatzem::distribuir_recursivament(string ident_vacuna, int quant_vacuna, Cambra &cambra) //Bua sembla molt complicat no? i no entenc per que tornes a utilitzar el que fem al metode de crear l'arbre si l'abre ja esta creat cuan fas el metode distribuir 
{
    int quant_vacuna1 = quant_vacuna, quant_vacuna2 = quant_vacuna, vacunes_no_distribuides = quant_vacuna;
    
    bool arbre_recorregut = false;
    
    //Cin distribució cambres magatzem
    bool afegir_fd = false, ple;
    int e, x, i = 0;
    //afegir_arrel
    {
        e = llista_cambres(i);//utilitzar iteradors o punt d'interès
        x = e;
        ++i;
    }
    while(not llista_cambres.empty())
    {
        if(e != 0)
        {
            if(afegir_fd)
            {
                x.fd() = e;
                x = e;
                afegir_fd = false;
            }
            else
            {
                x.fe() = e;
                x = e;
            }
        }
        else //e == 0
        {
            if(afegir_fd)
            {
                while(x not ple)
                {
                    x = x.arrel();
                }
            }
            else
            {
                afegir_fd = true;
            }
        }
        ++i;
    }magatzem.arrel.afegir_unitat(ident_vacuna, quant_vacuna);
    if(vacunes_no_distribuides == 0 or arbre_recorregut)
    {
        //fi_distribuir;
    }
    else if(vacunes_no_distribuides == 1)
    {
        quant_vacuna = fe().afegir_unitats(ident_vacuna, 1);
    }
    else if(vacunes_no_distribuides % 2 != 0)
    {
        quant_vacuna1 = distribuir_recursivament(ident_vacuna, (vacunes_no_distribuides/2) + 1, fe());
        quant_vacuna2 = distribuir_recursivament(ident_vacuna, (vacunes_no_distribuides/2), fd());
        quant_vacuna = quant_vacuna - (quant_vacuna1 + quant_vacuna2);
    }
    else
    {
        quant_vacuna1 = distribuir_recursivament(ident_vacuna, (vacunes_no_distribuides/2), fe());
        quant_vacuna2 = distribuir_recursivament(ident_vacuna, (vacunes_no_distribuides/2), fd());
        quant_vacuna = quant_vacuna - (quant_vacuna1 + quant_vacuna2);
    }
    if()
    return vacunes_no_distribuides;
}


void Magatzem::afegir_vacuna(string ident_vacuna)
{
    if(vacunes_donades_alta.find(ident_vacuna) != vacunes_donades_alta.end())
    {
        cout << " error" << endl;
    }
    else 
    {
        // Afageix la vacuna al diccionari vacunes_donades_alta
        vacunes_donades_alta.insert(make_pair(ident_vacuna,0));
    }
}

void Magatzem::treure_vacuna(string ident_vacuna)   
{
    if(vacunes_donades_alta.find(ident_vacuna) == vacunes_donades_alta.end() or vacunes_donades_alta[ident_vacuna]>0)
    {
        cout << "error" << endl;
    }
    else
    {
        vacunes_donades_alta.erase(ident_vacuna);
    }
}

void Magatzem::modificar_sistema(string ident_vacuna, int quantitat, char operacio)
{
    if(operacio == '+') 
    {
        vacunes_donades_alta[ident_vacuna] = vacunes_donades_alta[ident_vacuna] + quantitat;
    }
    if(operacio == '-') 
    {
        vacunes_donades_alta[ident_vacuna] = vacunes_donades_alta[ident_vacuna] - quantitat;
        if(vacunes_donades_alta[ident_vacuna] < 0) vacunes_donades_alta[ident_vacuna] = 0;
    }
}

// Consultors
int Magatzem::consultar_vacuna(string ident_vacuna) 
{
    if(vacunes_donades_alta.find(ident_vacuna) == vacunes_donades_alta.end())
    {
       return -1;
    }
    else 
    {
        return vacunes_donades_alta[ident_vacuna];
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

Cambra& Magatzem::cambra(int Ident_cambra)  //Actualizar al arbol
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