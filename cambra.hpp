#ifndef _CAMBRA_HPP_
#define _CAMBRA_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

typedef vector<vector<string>> Matriu;

class Cambra
{
    private:

    Matriu cambra;

    public:

    // Constructors
    Cambra();
    // Pre:  Cert.
    // Post: Crea una matriu buida.
    Cambra(int x, int y);
    // Pre:  x i y són la mida de la cambra, sempre més grans que 0.
    // Post: Crea una matriu de x files i y columnes.

    // Modificadors
    int afegir_unitats(string ident_vacuna,int quantitat);
    // Pre:  L'string identificació de vacuna ha de començar amb "J07" i l'enter quantitat ha de ser més gran que 0.
    // Post: Si la vacuna no existeix, es produeix un error. En cas contrari, es posen tantes 
    //       unitats com capiguen a la cambra i es torna un enter que indiqui quantes unitats no han cabut. 
    int treure_unitats(string ident_vacuna, int quantitat);
    // Pre:  L'string identificacio de vacuna ha de començar amb "J07" i l'enter quantitat ha de ser més gran que 0.
    // Post: Si la vacuna no existeix dona error. En cas contrari es torna la quantitat que no s'ha 
    //       pogut treure perque no hi havia prou unitats a la cambra.
    void comprimir();
    // Pre:  Cert.
    // Post: Es desplacen les vacunes cap a l’esquerra i cap avall de manera que no resti cap forat
    //       entre dues vacunes ni abans de cap vacuna.
    bool mirar_null(string a, string b);
    // Pre:  a i b són dos strings no buits.
    // Post: Retorna true si a < b, en cas contrari retorna false. 
    void ordenar();
    // Pre:  Cert.
    // Post: S’ordenen alfabèticament les vacunes que conté la nevera sense deixar forats
    //       entre elles ni abans de cap vacuna.
    void canviar_nevera(int files, int columnes);
    // Pre:  files > 0   columnes > 0.
    // Post: Es crea un nova nevera amb les dimension de files i columnes sempre i quan la nevera antiga càpiga a la 
    //       nova nevera, és a dir, la nova nevera sigui de la mateixa mida o més gran que l'antiga. Si no dona error. 

    // Consultors
    string consultar_posicio(int fila, int columna) const;
    // Pre:  els enters fila i columna són més grans que 0.
    // Post: S’indica quina vacuna hi ha a la posicío [fila][columna] de la cambra. Si no hi ha cap vacuna, s’escriu NULL.
    unsigned int files() const;
    // Pre:  Cert.
    // Post: Retorna la mida de les files de la matriu cambra.
    unsigned int columnes() const;
    // Pre:  Cert.
    // Post: Retorna la mida de les columnes de la matriu cambra.


    // Lectura i Escriptura
    void escriure() const;
    // Pre:  Cert.
    // Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta. On hi hagi un forat s’escriu NULL.
    //       També s’escriu el nombre d'unitats que hi ha en total i, per ordre d’identificador de vacuna existent a la nevera, 
    //       s’escriu l’identificador de vacuna i la seva quantitat.
};
#endif