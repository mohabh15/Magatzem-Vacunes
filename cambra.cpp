#include "cambra.hpp"
using namespace std;

cambra::cambra(int x, int y)
//crea una matriu de x files i y columnes 
{
    //cambra1.resize(x,vector<int>(y));
}


int cambra::afegir_unitats(string ident_vacuna,int quantitat, sistema m1)
//Pre: Identificacio de vacuna ha de començar amb "J07"
//Post:Si la vacuna no existeix,  es produeix un error.  En cas contrari, es posen tantes unitats 
//com capiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut.
{
	if(!m1.find(ident_vacuna)) cout<<"ERROR"<<endl;
	else 
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
	}
	return quantitat;
}


int cambra::treure_unitats(string ident_vacuna, int quantitat, sistema m1)
//Pre: Identificacio de vacuna ha de començar amb "J07"
//Post: Si la vacuna no existeix dona error, en cas contrari es torna la quantitat que no s'ha 
//pogut treure perque no hi havia suficients a la cambra 
{
	if(!m1.find(ident_vacuna)) cout<<"ERROR"<<endl;
	else 
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
	}
	return quantitat;
}	


void cambra::comprimir()
//Pre: cert
//Post:  Es desplacen les vacunes cap a l’esquerra i cap avall de manera que no resti cap forat
//entre dues vacunes ni abans de cap vacuna
{
	//mirar de un en un i si esta buit posar les cordenadas en una variable
	//i seguir mirant amb un altre bucle fins trobar un no buit que es posara en les cordenadas abans guardades
	//i aquell lloc es posara en null i mirem la casilla seguent de la que estaba buida
	// si amb el segon bucle arribem al final sense trobar cap ocupat sortim dels 2 bucles

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
	for(int i=0; i<cambra1.size(); ++i)
	{
		for(int j=0; i<cambra1.size(); ++i)
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
	//es copia la nevera en una aux i es cambia la que hi havia 
	//despres es va implint la nova amb la antigua

}


string cambra::consultar_po(int fila, int columna)
//Pre:cert
//Post:S’indicaquina vacuna hi ha en la posici ́o corresponent de la nevera de la cambra. Si no hi hacap vacuna, s’escriu NULL
{
	return cambra1[fila][columna];
}


void cambra::escriure()
//Pre: cert
//Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta. On hi hagi un forat s’escriu NULL.
//Tamb ́e s’escriu quantes unitats hi ha en total i,  per ordre d’identificador de vacunaexistent en la nevera, 
//s’escriuen l’identificador de vacuna i la seva quantitat
{
	int quantitat;

	//contigunt de dalt a baix de la nevera
	//

	//identificador de vacuna i quantes hi ha d'aquest tipus
	cout<<quantitat<<endl;
}