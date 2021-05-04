#include "cambra.hpp"
using namespace std;

Cambra::Cambra(int x, int y)
//crea una matriu de x files i y columnes 
{
    cambra.resize(x,vector<string>(y));
}


int Cambra::afegir_unitats(string ident_vacuna,int quantitat)   //hem d'afegir el codi per afegir vacunes al sistema
//Pre:Ident_vacuna ha de començar amb "J07" quantitat>0
//Post:Si la vacuna no existeix, es produeix un error. En cas contrari, es posen tantes unitats 
//	   com capiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut.
{
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; i<cambra[0].size(); ++i)
		{
			if(quantitat!=0 or cambra[i][j]!="NULL") 
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


int Cambra::treure_unitats(string ident_vacuna, int quantitat) //hem d'afegir el codi per treure vacunes al sistema
//Pre: Ident_vacuna ha de començar amb "J07", quantitat>0
//Post: Si la vacuna no existeix dona error, en cas contrari es torna la quantitat que no s'ha 
//		pogut treure perque no hi havia suficients a la cambra 
{
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; i<cambra[0].size(); ++i)
		{
			if(quantitat!=0 or cambra[i][j]!=ident_vacuna) 
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
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; i<cambra.size(); ++i)
		{
			if(cambra[i][j]=="NULL") 
			{
				int contador=0;
				//seguir mirant amb un altre bucle fins trobar un no buit que es posara en el ultim lloc buit trobat
				for(unsigned int v=i; i<cambra.size(); ++i)
				{
					for(unsigned int z=j; i<cambra[0].size(); ++i)
					{
						//i aquell lloc es posara en null i mirem la casilla seguent de la que estaba buida
						if(cambra[v][z]!="NULL") 
						{
							cambra[i][j]=cambra[v][z];
							cambra[v][z]="NULL";
							v=cambra.size();
							z=cambra[0].size();
						}
						else ++contador;
						if(contador==v*z) 
						{
							//si arribem al final de la cambra sense trobar cap ple ja tenim la post i sortim dels bucles
							i=cambra.size();
							j=cambra[0].size();
						}
					}
				}
			}
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
	for(unsigned int i=0; i<cambra.size(); ++i)
	{
		for(unsigned int j=0; i<cambra[0].size(); ++j)
		{
			sort(cambra[i].begin(),cambra[i].end(),mirar_null);
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
	//si la cantidad cabe en la nueva nevera 
	//despres es va omplint la nova amb la antigua
	if(quantitat<=files*columnes)  
	{
		// Crea la nevera aux i es posa la nova amb les noves dimensions
		Matriu cambra_aux(files,vector<string>(columnes,"NULL")); 
		//Es copia la nevera en una aux
		for(unsigned int i=0; i<cambra.size();++i )
		{
			for(unsigned int j=0; j<cambra[0].size(); ++j) 
			{
				if(cambra[i][j]!="NULL") 
				{
					cambra_aux[i][j]=cambra[i][j];
				}
			}	
		}
		//es copia les vacunes de la nevera aux a la nova nevera
		cambra=cambra_aux;
		cambra.resize(files,vector<string>(columnes));
		for(unsigned int i=0; i<cambra.size();++i )
		{
			for(unsigned int j=0; j<cambra[0].size(); ++j) 
			{
				cambra[i][j]=cambra_aux[i][j];
			}	
		}
	}
	else cout<<"ERROR"<<endl;
}


string Cambra::consultar_posicio(int fila, int columna)
//Pre: fila>0 columna>0
//Post:S’indica el contingut de la posicio corresponent de cambra. 
{
	return cambra[fila][columna];
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


void Cambra::escriure()
//Pre: cert
//Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta.
//      Tambe s’escriu quantes unitats hi ha en total i, per ordre d’identificador de vacuna existent en la nevera, 
//      s’escriuen l’identificador de vacuna i la seva quantitat
{
	int quantitat;
	vector<pair<string,int>> vacunes;
	//contigunt de dalt a baix de la nevera
	for(unsigned int i=0; i<cambra.size();++i)
	{
		for(unsigned int j=0; j<cambra[0].size();++j)
		{
			cout<<cambra[i][j];
			if(cambra[i][j]!="NULL") 
			{
				++quantitat;
				if (vacunes.size()==0) vacunes.push_back(make_pair(cambra[i][j],1));
				else
				{
					for(unsigned int z=0; z<vacunes.size(); ++z)
					{
						if(cambra[i][j]==vacunes[i].first)
						{
							++vacunes[i].second;
						}
						else if(cambra[i][j]!="NULL") vacunes.push_back(make_pair(cambra[i][j],1));
					}
				}
			}
		}
		cout<<endl;
	}

	//identificador de vacuna i quantes hi ha d'aquest tipus
	for(unsigned int i=0; i<vacunes.size(); ++i)
	{
		cout<<vacunes[i].first<<vacunes[i].second<<endl;
	}

	//quantitat total de vacunes
	cout<<quantitat<<endl;
}