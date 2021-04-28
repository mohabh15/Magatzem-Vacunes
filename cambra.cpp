#include "cambra.hpp"
using namespace std;

cambra::cambra(int x, int y)
//crea una matriu de x files i y columnes 
{
    cambra1.resize(x,vector<string>(y));
}


int cambra::afegir_unitats(string ident_vacuna,int quantitat)
//Pre: Identificacio de vacuna ha de començar amb "J07"
//Post:Si la vacuna no existeix,  es produeix un error.  En cas contrari, es posen tantes unitats 
//com capiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut.
{
	for(int i=0; i<cambra1.size(); ++i)
	{
		for(int j=0; i<cambra1[0].size(); ++i)
		{
			if(quantitat!=0 or cambra1[i][j]!="NULL") 
			{
				cambra1[i][j]=ident_vacuna;
				--quantitat;
			}
			if(quantitat==0)
			{
				i=cambra1.size();
				j=cambra1[0].size();
			}
			
		}
	}
	return quantitat;
}


int cambra::treure_unitats(string ident_vacuna, int quantitat)
//Pre: Identificacio de vacuna ha de començar amb "J07"
//Post: Si la vacuna no existeix dona error, en cas contrari es torna la quantitat que no s'ha 
//pogut treure perque no hi havia suficients a la cambra 
{
	for(int i=0; i<cambra1.size(); ++i)
	{
		for(int j=0; i<cambra1[0].size(); ++i)
		{
			if(quantitat!=0 or cambra1[i][j]!=ident_vacuna) 
			{
				cambra1[i][j]="NULL";
				--quantitat;
			}
			if(quantitat==0)
			{
				i=cambra1.size();
				j=cambra1[0].size();
			}
			
		}
	}
	return quantitat;
}	


void cambra::comprimir()
//Pre: cert
//Post:  Es desplacen les vacunes cap a l’esquerra i cap avall de manera que no resti cap forat
//entre dues vacunes ni abans de cap vacuna
{
	//mirar de un en un i si esta buit quan trobem un que estigui buit mirem els seguent 
	for(unsigned int i=0; i<cambra1.size(); ++i)
	{
		for(unsigned int j=0; i<cambra1.size(); ++i)
		{
			if(cambra1[i][j]=="NULL") 
			{
				int contador=0;
				//seguir mirant amb un altre bucle fins trobar un no buit que es posara en el ultim lloc buit trobat
				for(unsigned int v=i; i<cambra1.size(); ++i)
				{
					for(unsigned int z=j; i<cambra1[0].size(); ++i)
					{
						//i aquell lloc es posara en null i mirem la casilla seguent de la que estaba buida
						if(cambra1[v][z]!="NULL") 
						{
							cambra1[i][j]=cambra1[v][z];
							cambra1[v][z]="NULL";
							v=cambra1.size();
							z=cambra1[0].size();
						}
						else ++contador;
						if(contador==v*z) 
						{
							//si arribem al final de la cambra sense trobar cap ple ja tenim la post i sortim dels bucles
							i=cambra1.size();
							j=cambra1[0].size();
						}
					}
				}
			}
		}
	}
}

bool mirar_null(string a, string b)
{
	if(a=="NULL") return false;
	return true;
}
void cambra::ordenar()
//Pre: cert
//Post: S’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats
//entre elles ni abans de cap vacuna
{
	for(unsigned int i=0; i<cambra1.size(); ++i)
	{
		for(unsigned int j=0; i<cambra1.size(); ++i)
		{
			sort(cambra1.begin(),cambra1.end(),mirar_null);
		}
	}
}


void cambra::canviar_nevera(int files, int columnes)
//Pre: cert
//Post: Es crea un nova nevera amb les dimension de files i columnes si el contingut de la antigua nevera
//caben en la nova, si no dona error  
{
	//contar quantes vacunes hay en la cambra
	int quantitat=0;
	for(int i=0; i<cambra1.size();++i )
	{
		for(int j=0; j<cambra1[0].size(); ++j) 
		{
			if(cambra1[i][j]!="NULL") ++quantitat;
		}
	}
	//si la cantidad cabe en la nueva nevera 
	//despres es va omplint la nova amb la antigua
	if(quantitat<=files*columnes)  
	{
		// Crea la nevera aux i es posa la nova amb les noves dimensions
		Matriu cambra_aux(files,vector<string>(columnes,"NULL")); 
		//Es copia la nevera en una aux
		for(int i=0; i<cambra1.size();++i )
		{
			for(int j=0; j<cambra1[0].size(); ++j) 
			{
				if(cambra1[i][j]!="NULL") 
				{
					cambra_aux[i][j]=cambra1[i][j];
				}
			}	
		}
		//es copia les vacunes de la nevera aux a la nova nevera
		cambra1=cambra_aux;
		cambra1.resize(files,vector<string>(columnes));
		for(int i=0; i<cambra1.size();++i )
		{
			for(int j=0; j<cambra1[0].size(); ++j) 
			{
				cambra1[i][j]=cambra_aux[i][j];
			}	
		}
	}
	else cout<<"ERROR"<<endl;
}


string cambra::consultar_po(int fila, int columna)
//Pre:cert
//Post:S’indicaquina vacuna hi ha en la posici ́o corresponent de la nevera de la cambra. Si no hi hacap vacuna, s’escriu NULL
{
	return cambra1[fila][columna];
}


/*unsigned int cambra::size(int fila, int columna)
//Pre: 
//Post: retorna la mida de la matriu cambra
{
	unsigned int mida_matriu;
	mida_matriu = fila * columna;
	return mida_matriu;
}*/


void cambra::escriure()
//Pre: cert
//Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta. On hi hagi un forat s’escriu NULL.
//Tamb ́e s’escriu quantes unitats hi ha en total i,  per ordre d’identificador de vacuna existent en la nevera, 
//s’escriuen l’identificador de vacuna i la seva quantitat
{
	int quantitat;
	vector<pair<string,int>> vacunes;
	//contigunt de dalt a baix de la nevera
	for(unsigned int i=0; i<cambra1.size();++i)
	{
		for(unsigned int j=0; j<cambra1[0].size();++j)
		{
			cout<<cambra1[i][j];
			if(cambra1[i][j]!="NULL") 
			{
				++quantitat;
				if (vacunes.size()==0) vacunes.push_back(make_pair(cambra1[i][j],1));
				else
				{
					for(unsigned int z=0; z<vacunes.size(); ++z)
					{
						if(cambra1[i][j]==vacunes[i].first)
						{
							++vacunes[i].second;
						}
						else if(cambra1[i][j]!="NULL") vacunes.push_back(make_pair(cambra1[i][j],1));
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