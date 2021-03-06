#include "magatzem.hpp"
using namespace std;

// Constructors
Magatzem::Magatzem()
{}

Magatzem::Magatzem(int mida_magatzem, vector<int>& llista_cambres)    
{
    //Algorisme per modificar el vector amb l'estructura en preordre i passar-lo a postordre
    vector<int> llista_final;
    for(int i = 1; i < llista_cambres.size() - 2; ++i)
    {
        if(llista_cambres[i] != 0 and llista_cambres[i+1] != 0)
        {
            llista_final.push_back(llista_cambres[i]);
            llista_final.push_back(2);
        }
        else if(llista_cambres[i] != 0 and llista_cambres[i+1] == 0)
        {
            llista_final.push_back(llista_cambres[i]);
            llista_final.push_back(0);
            ++i;
        }
    }
    llista_final.push_back(llista_cambres[0]);
    llista_final.push_back(2);

    //Acabem d'ordenar la llista per tenir l'estructura en postordre
    llista_cambres.clear();
    for(int i = 1; i < llista_final.size()-2; ++i)
    {
       if(llista_final[i]!=0)
       {
           for(int j = i; j < i+4; ++j)
           {
               llista_cambres.push_back(llista_final[j+1]);
           }
           llista_cambres.push_back(llista_final[i-1]);
           llista_cambres.push_back(llista_final[i]);
           i+=5;
       }
       else
       {
           llista_cambres.push_back(llista_final[i-1]);
           llista_cambres.push_back(llista_final[i]);
       }
    }
    llista_cambres.push_back(llista_final[llista_final.size()-2]);
    llista_cambres.push_back(llista_final[llista_final.size()-1]);


    //Genera l'arbre amb l'estructura del magatzem que conté els índexos de les cambres
    magatzem = generar_arbre(mida_magatzem,llista_cambres);

    cout << magatzem << endl;
    
    //Genera el vector amb les n cambres
    Cambra aux;
    while(mida_magatzem > 0)
    {
        cambres.push_back(aux);
        --mida_magatzem;
    }
}


//Destructor
Magatzem::~Magatzem()
{}


// Modificadors
arbreBin<int> Magatzem::generar_arbre(int numero_cambres, vector<int>& llista_cambres)
{
    int node,i=0;
    int size, nf;
    arbreBin<int> x;
    stack<arbreBin<int> > p;

    size=numero_cambres;   

    while (size > 0) {
        node = llista_cambres[i];
        nf = llista_cambres[i+1];
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
        i+=2;
    }
    if (not p.empty()) x = p.top();
  return x;
}

int Magatzem::distribuir(string ident_vacuna, int quant_vacuna)
{
    int vacunes_no_distribuides = 0;
    vacunes_no_distribuides = distribuir_recursivament(ident_vacuna, quant_vacuna,magatzem);

    vacunes_donades_alta[ident_vacuna] = quant_vacuna-vacunes_no_distribuides;

    return vacunes_no_distribuides;    
}

int Magatzem::distribuir_recursivament(string ident_vacuna, int quant_vacuna, arbreBin<int> p) 
{
    //Accedim a l'arbre per saber l'índex de la cambra
    //Una vegada sabem l'índex distribuim en aquesta cambra 

    //Cas base
    if(p.es_buit() and quant_vacuna != 0) quant_vacuna = cambres[p.arrel()-1].afegir_unitats(ident_vacuna, quant_vacuna);

    //Cas recursiu
    if(not p.es_buit() and quant_vacuna != 0)
    {
        quant_vacuna = cambres[p.arrel()-1].afegir_unitats(ident_vacuna, quant_vacuna);

        if((quant_vacuna % 2) == 0 and quant_vacuna != 0) 
        {
            int fe=0,fd=0;
            if(not p.fe().es_buit())   
            {
                fe=distribuir_recursivament(ident_vacuna, quant_vacuna/2, p.fe());
            }
            if(not p.fd().es_buit())   
            {
                fd=distribuir_recursivament(ident_vacuna, quant_vacuna/2, p.fd());
            }
            quant_vacuna=fe+fd;
        }
        else if(quant_vacuna != 0)
        {
            if(not p.fd().es_buit())   
            {
                int fe=0,fd=0;
                if(not p.fe().es_buit())   
                {
                    fe=distribuir_recursivament(ident_vacuna, (quant_vacuna/2)+1, p.fe());
                }
                if(not p.fd().es_buit())   
                {
                    fd=distribuir_recursivament(ident_vacuna, quant_vacuna/2, p.fd());
                }
                quant_vacuna=fe+fd;
            }
        }
    }
    return quant_vacuna;
}


void Magatzem::afegir_vacuna(string ident_vacuna)
{
    if(vacunes_donades_alta.find(ident_vacuna) != vacunes_donades_alta.end())
    {
        cout << "  error" << endl;
    }
    else 
    {
        //Afegeix la vacuna al diccionari vacunes_donades_alta
        vacunes_donades_alta.insert(make_pair(ident_vacuna,0));
    }
}

void Magatzem::treure_vacuna(string ident_vacuna)   
{
    if(vacunes_donades_alta.find(ident_vacuna) == vacunes_donades_alta.end() or vacunes_donades_alta[ident_vacuna]>0)
    {
        cout << "  error" << endl;
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

Cambra& Magatzem::cambra(int ident_cambra)  
{   
    vector<Cambra>::iterator it = cambres.begin();
    while(1<ident_cambra)
    {
        ++it;
        --ident_cambra;
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
   //Com que tota l'estona està llegint, al cridar el mètode fi deixarà de llegir i s'acabarà el programa
   cin.ignore();  
}