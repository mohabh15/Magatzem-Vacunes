#include <iostream>
#include "magatzem.hpp"
using namespace std;






int main()
{

    Magatzem m1;
    int numero_cambres;
    cin>>numero_cambres;
    

    string operacion;
    int  ident_cambra;
    string ident_vacuna; 
    int quantitat; 

    //Operacions 
    while(cin>>operacion)
    {
        if (operacion=="afegir_vac")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            magatzem.afegir_vacu()
        }
        if (operacion=="treure_vac")
        {
            /* code */
        }
        

        if(operacion=="afegir_unitats")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(m1.find()==false) cout<<"ERROR"<<endl;
            m1[]
            
        }
    }



}
