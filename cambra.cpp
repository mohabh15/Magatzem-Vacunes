#include "cambra.hpp"
using namespace std;


// Constructors
Cambra::Cambra()
{}

Cambra::Cambra(int x, int y)
{
    cambra.resize(x,vector<string>(y));
}


// Modificadors
int Cambra::afegir_unitats(string ident_vacuna,int quantitat) 
{
	//Entrar desde final
	for(int i = cambra.size()-1; i >= 0; --i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			if(quantitat != 0 and cambra[i][j] == "NULL") 
			{
				cambra[i][j] = ident_vacuna;
			}
			if(quantitat == 0)
			{
				i = -1;
				j = cambra[0].size();
			}
		}
	}
	return quantitat;
}

int Cambra::treure_unitats(string ident_vacuna, int quantitat)
{
	//Entrar desde final
	for(int i = cambra.size()-1; i >= 0; --i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			if(quantitat != 0 and cambra[i][j] == ident_vacuna) 
			{
				cambra[i][j] = "NULL";
				--quantitat;
			}
			if(quantitat == 0)
			{
				i = -1;
				j = cambra[0].size();
			}
			
		}
	}
	return quantitat;
}	

void Cambra::comprimir()
{
	// Recorre la cambra posició per posició. Si hi ha alguna posició buida es salta a la següent posició, si no, 
	// es fa un push_back al vector aux.
	vector<string> vector_aux_vacunes;
	for(unsigned int i = 0; i < cambra.size(); ++i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			if(cambra[i][j] != "NULL") 
			{
				vector_aux_vacunes.push_back(cambra[i][j]);
			}
		}
	}
	// Torna a recorrer la cambra posició per posició. Mentre l'enter n sigui més petit que la mida del vector aux
	// s'afagiran les diferents vacunes d'esquerra a dreta i d'avall cap a d'alt per ordre en el que es troben al vector.
	// Un cop ja no quedin més vacunes a afegeir si encara queda espai a la cambra es substituiran els "calaixos" restants
	// per l'string NULL.
	int int_aux = 0;
	for(int i = cambra.size()-1; i >= 0; --i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			if(int_aux < vector_aux_vacunes.size()) 
			{
				cambra[i][j] = vector_aux_vacunes[int_aux];
				++int_aux;
			}
			else cambra[i][j] = "NULL";
		}
	}
}

void Cambra::ordenar()
{
	vector<string> vector_aux_vacunes;
	// Recorre la cambra posició per posició i afageix cada string al vector aux.
	for(unsigned int i = 0; i < cambra.size(); ++i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			vector_aux_vacunes.push_back(cambra[i][j]);
		}
	}
	sort(vector_aux_vacunes.begin(), vector_aux_vacunes.end());
	int comptador = 0;
	for(int i = cambra.size()-1; i >= 0; --i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			cambra[i][j] = vector_aux_vacunes[comptador];
			++comptador;
		}
	}
	
}

void Cambra::canviar_nevera(int files, int columnes)
{
	// Conta quantes vacunes hi ha a la cambra
	int quantitat = 0;
	for(unsigned int i = 0; i < cambra.size(); ++i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j) 
		{
			if(cambra[i][j] != "NULL") ++quantitat;
		}
	}
	// Si la quantitat cap a la nova nevera la nova nevera va omplint-se amb el contingut de l'antiga nevera iteració a iteració
	if(quantitat <= files*columnes)  
	{
		vector<string> vetor_aux_vacunes; 
		for(unsigned int i = 0; i < cambra.size(); ++i)
		{
			for(unsigned int j = 0; j < cambra[0].size(); ++j) 
			{
				if(cambra[i][j] != "NULL") 
				{
					vetor_aux_vacunes.push_back(cambra[i][j]);
				}
			}	
		}

		// Es copien les vacunes del vector aux a la nova nevera amb les noves dimensions 
		cambra = vector<vector<string>>(files, vector<string>(columnes));
		int comptador = 0;
		for(int i = cambra.size()-1; i >= 0; --i)
		{
			for(unsigned int j = 0; j < cambra[0].size(); ++j) 
			{
				if(comptador < vetor_aux_vacunes.size()) 
				{
					cambra[i][j] = vetor_aux_vacunes[comptador];
					++comptador;
				}
				else 
				{
					cambra[i][j] = "NULL";
				}
			}	
		}
	}
	else cout << "  error" << endl;
}


// Consultors
string Cambra::consultar_posicio(int fila, int columna) const
{
	return cambra[fila-1][columna-1];
}

unsigned int Cambra::files() const
{
	return cambra.size();
}

unsigned int Cambra::columnes() const
{
	return cambra[0].size();
}


// Lectura i Escriptura
void Cambra::escriure() const
{
	int quantitat = 0;
	bool trobat = true;
	vector<pair<string,int>> vector_vacunes;
	// Mostra per pantalla el contigunt de la nevera de dalt a baix es a dir de la posicio (1 1) a (n n)
	for(unsigned int i = 0; i < cambra.size(); ++i)
	{
		cout << " ";
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			cout << cambra[i][j] << " ";
		}
		cout << endl;
	}
	// Cambres en ordre d'aparicio
	for(int i = cambra.size()-1; i >= 0; --i)
	{
		for(unsigned int j = 0; j < cambra[0].size(); ++j)
		{
			if(cambra[i][j] != "NULL") 
			{
				++quantitat;
				if (vector_vacunes.size() == 0) 
				{
					vector_vacunes.push_back(make_pair(cambra[i][j],1));
				}
				else
				{
					for(unsigned int k = 0; k < vector_vacunes.size(); ++k)
					{
						if(cambra[i][j] == vector_vacunes[k].first)
						{
							++vector_vacunes[k].second;
							trobat = true;
							k = vector_vacunes.size();
						}
						else trobat = false;
					}
					if(not trobat) 
					{
						vector_vacunes.push_back(make_pair(cambra[i][j],1));
					}
				}
			}
		}
	}
	// Escriu per pantalla el nombre total de vacunes qu hi ha a la cambra. 
	cout << " " << quantitat << endl;
	// Mostra per pantalla l'identificador de vacuna i el nº que hi ha del tipus de vacuna.
	for(int i = 0; i < vector_vacunes.size(); ++i)
	{
		cout << " " << vector_vacunes[i].first << " " << vector_vacunes[i].second << endl;
	}
}