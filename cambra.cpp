#include "cambra.hpp"
using namespace std;



Cambra::Cambra()
//Pre:
//Post:
{}

Cambra::Cambra(int x, int y)
//crea una matriu de x files i y columnes 
{
    cambra.resize(x,vector<string>(y));
}


int Cambra::afegir_unitats(string ident_vacuna,int quantitat) 
//Post:Es posen tantes unitats com capiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut.
{
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra[0].size(); ++j)
		{
			if(quantitat!=0 and cambra[i][j]=="NULL") 
			{
				cambra[i][j]=ident_vacuna;
				--quantitat;
			}
			if(quantitat==0)
			{
				i=cambra.size();
				j=cambra[0].size();
			}
		}
	}
	return quantitat;
}


int Cambra::treure_unitats(string ident_vacuna, int quantitat)
//Pre: Ident_vacuna ha de començar amb "J07", quantitat>0
//Post: Si la vacuna no existeix dona error, en cas contrari es torna la quantitat que no s'ha 
//		pogut treure perque no hi havia suficients a la cambra 
{
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra[0].size(); ++j)
		{
			if(quantitat!=0 and cambra[i][j]==ident_vacuna) 
			{
				cambra[i][j]="NULL";
				--quantitat;
			}
			if(quantitat==0)
			{
				i=cambra.size();
				j=cambra[0].size();
			}
			
		}
	}
	return quantitat;
}	


void Cambra::comprimir()
//Pre: cert
//Post: Es desplacen les vacunes cap a l’esquerra i cap avall de manera que no resti cap forat
//		entre dues vacunes ni abans de cap vacuna
{
	//mirar de un en un i si esta buit quan trobem un que estigui buit mirem els seguent 
	vector<string> aux;
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra.size(); ++j)
		{
			if(cambra[i][j]!="NULL") 
			{
				aux.push_back(cambra[i][j]);
			}
		}
	}
	int n=0;
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra.size(); ++j)
		{
			if(n<aux.size()) 
			{
				cambra[i][j]=aux[n];
				++n;
			}
			else cambra[i][j]="NULL";
		}
	}
}



bool mirar_null(string a, string b)
{
	return (a<b);
}
void Cambra::ordenar()
//Pre: cert
//Post: S’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats
//		entre elles ni abans de cap vacuna
{
	vector<string> aux;
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra[0].size(); ++j)
		{
			aux.push_back(cambra[i][j]);
		}
	}
	sort(aux.begin(),aux.end(),mirar_null);
	int contador=0;
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; j<cambra[0].size(); ++j)
		{
			cambra[i][j]=aux[contador];
			++contador;
		}
	}
	
}


void Cambra::canviar_nevera(int files, int columnes)
//Pre: files>0 i columnes>0
//Post: Es crea un nova nevera amb les dimension de files i columnes si el contingut de la antigua nevera
//		caben en la nova, si no dona error  
{
	//contar quantes vacunes hay en la cambra
	int quantitat=0;
	for(unsigned int i=0; i<cambra.size();++i )
	{
		for(unsigned int j=0; j<cambra[0].size(); ++j) 
		{
			if(cambra[i][j]!="NULL") ++quantitat;
		}
	}
	//si la cantidad cabe en la nueva nevera es va omplint la nova amb la antigua
	if(quantitat<=files*columnes)  
	{
		//Es copia la nevera en un vector aux
		vector<string> aux; 
		for(unsigned int i=0; i<cambra.size();++i )
		{
			columnes=0;
			for(unsigned int j=0; j<cambra[0].size(); ++j) 
			{
				if(cambra[i][j]!="NULL") 
				{
					aux.push_back(cambra[i][j]);
				}
			}	
		}

		//es copia les vacunes de aux a la nova nevera amb les noves dimensions 
		cambra.resize(files,vector<string>(columnes));
		int contador=0;
		for(unsigned int i=0; i<cambra.size();++i )
		{
			for(unsigned int j=0; j<cambra[0].size(); ++j) 
			{
				if(aux.size()!=0) 
				{
					cambra[i][j]=aux[contador];
					++contador;
				}
				else cambra[i][j]="NULL";
			}	
		}
	}
	else cout<<"error"<<endl;
}

//Consultores
string Cambra::consultar_posicio(int fila, int columna) 
//Pre: fila>0 columna>0
//Post:S’indica el contingut de la posicio corresponent de cambra. 
{
	return cambra[fila-1][columna-1];
}
unsigned int Cambra::files() 
//Pre: cert
//Post: retorna la mida de cambra
{
	return cambra.size();
}
unsigned int Cambra::columnes() 
//Pre: cert
//Post: retorna la mida de cambra
{
	return cambra[0].size();
}

//L/E
void Cambra::escriure() 
//Pre: cert
//Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta.
//      Tambe s’escriu quantes unitats hi ha en total.
//		I per ordre d’identificador de vacuna existent en la nevera, s’escriuen l’identificador de vacuna i la seva quantitat
{
	int quantitat=0;
	bool trobat=true;
	vector<pair<string,int>> vacunes;
	//contigunt de dalt a baix de la nevera
	for(int i=cambra.size()-1; i>=0;--i)
	{
		for(unsigned int j=0; j<cambra[0].size();++j)
		{
			cout<<cambra[i][j]<<" ";
		}
		cout<<endl;
	}
	//Cambres en ordre d'aparicio
	for(unsigned int i=0; i<cambra.size();++i)
	{
		for(unsigned int j=0; j<cambra[0].size();++j)
		{
			if(cambra[i][j]!="NULL") 
			{
				++quantitat;
				if (vacunes.size()==0) vacunes.push_back(make_pair(cambra[i][j],1));
				else
				{
					for(unsigned int z=0; z<vacunes.size(); ++z)
					{
						if(cambra[i][j]==vacunes[z].first)
						{
							++vacunes[z].second;
							trobat=true;
							z=vacunes.size();
						}
						else trobat=false;
					}
					if(not trobat)  vacunes.push_back(make_pair(cambra[i][j],1));
				}
			}
		}
	}

	//identificador de vacuna i quantes hi ha d'aquest tipus
	for(int i=0; i<vacunes.size(); ++i)
	{
		cout<<vacunes[i].first<<" "<<vacunes[i].second<<endl;
	}

	//quantitat total de vacunes
	cout<<quantitat<<endl;
}