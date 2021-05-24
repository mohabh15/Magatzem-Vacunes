#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
{}

Magatzem::Magatzem(list<int>& llista_cambres)    
{
    /*124005003600700 */

    vector<int> aux;

    int arrel=llista_cambres.begin();
    llista_cambres.erase(llista_cambres.begin());

    for(list<int>::const_iterator it = l.begin(); it!=llista_cambres.end(); ++it)
    {
        if(*it==0 and *++it==0) 
        {
            --it
            aux.push_back(*it);
            aux.push_back(0);
        }


    }





    /*//Cin distribució cambres magatzem
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
    }*/


}



//Destructor
Magatzem::~Magatzem()
{}


// Modificadors

int Magatzem::distribuir(string ident_vacuna, int quant_vacuna) //NO TOCAR
{
    int vacunes_no_distribuides=0;
    if(not find(ident_vacuna))
    {
        cout << "error" << endl;
        vacunes_no_distribuides = quant_vacuna;
    }
    else
    {
        vacunes_no_distribuides=distribuir_recursivament(ident_vacuna, quant_vacuna,magatzem, vacunes_no_distribuides);
    }

    vacunes_donades_alta[ident_vacuna]=quant_vacuna-vacunes_no_distribuides;

    return vacunes_no_distribuides;    
}

int Magatzem::distribuir_recursivament(string ident_vacuna, int quant_vacuna,arbreBin<int> p,int &vacunes_no_distr) 
{
    //accedir al arbre per saber l'index de la cambra
    //una vegada sabem l'index llavors distribuir en aquesta cambra 
   

    //cas base
    if(p.es_buit() and quant_vacuna!=0)   quant_vacuna=cambres[p.arrel()].afegir_unitats(ident_vacuna,quant_vacuna);

    //cas recursiu
    if(not p.es_buit() and quant_vacuna!=0)
    {
        quant_vacuna=cambres[magatzem.arrel()].afegir_unitats(ident_vacuna,quant_vacuna);
        vacunes_no_distr=quant_vacuna;
        if(quant_vacuna%2==0 and quant_vacuna!=0) 
        {
            if(not p.fe().es_buit())   
            {
                distribuir_recursivament(ident_vacuna,quant_vacuna/2,p.fe(), vacunes_no_distr);
            }
            if(not p.fd().es_buit())   
            {
                distribuir_recursivament(ident_vacuna,quant_vacuna/2,p.fd(), vacunes_no_distr);
            }
        }
        else if(quant_vacuna!=0)
        {
            if(not p.fd().es_buit())   
            {
                distribuir_recursivament(ident_vacuna,quant_vacuna,p.fd(), vacunes_no_distr);
            }
        }
    }
    return vacunes_no_distr;
    



    /*int quant_vacuna1 = quant_vacuna, quant_vacuna2 = quant_vacuna, vacunes_no_distribuides = quant_vacuna;
    
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
    return vacunes_no_distribuides;*/
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
    list<Cambra>::iterator it = cambres.begin(); 
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