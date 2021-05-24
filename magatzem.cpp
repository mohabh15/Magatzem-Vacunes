#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
{}

Magatzem::Magatzem(list<int>& llista_cambres)    
{
    
    


}



//Destructor
Magatzem::~Magatzem()
{}


// Modificadors

arbreBin<int> Magatzem::generar_arbre(arbreBin<int>& x)
{
    int node;
    int size, nf;
    stack<arbreBin<int> > p;

    cin >> size;  

    while (size > 0) {
        cin >> node >> nf;
        if (nf == 0) 
        {  //fills buits
            p.push(arbreBin<int>(node, arbreBin<int>(), arbreBin<int>()));
        } 
        else if (nf == -1) 
        {  //nf=-1 --> nomes un fill, l'esquerre
            arbreBin<int> fe = p.top();
            p.pop();
            p.push(arbreBin<int>(node, fe, arbreBin<int>()));
        }
        else if (nf == 1) 
        {  //nf=1 --> nomes un fill, el dret
            arbreBin<int> fd = p.top();
            p.pop();
            p.push(arbreBin<int>(node, arbreBin<int>(), fd));
        } 
        else {  //nf=2 --> dos fills no buits
            arbreBin<int> fd = p.top();
            p.pop();
            arbreBin<int> fe = p.top();
            p.pop();
            p.push(arbreBin<int>(node, fe, fd));
        }
        --size;
    }
    if (not p.empty()) x = p.top();
  return x;
}

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