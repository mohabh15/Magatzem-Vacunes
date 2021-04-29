#include <iostream>
#include "magatzem.hpp"
using namespace std;






int main()
{
    int numero_cambres;
    cin>>numero_cambres;
    
    Magatzem m1(numeros_cambres);

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
            magatzem.afegir_vac(ident_vacuna);
        }
        if (operacion=="treure_vac")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            magatzem.treure_vac(ident_vacuna);
        }
        if(operacion=="afegir_unitats")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(m1.find()==false) cout<<"error"<<endl;
            else
            {
                magatzem. //metode que retorni la cambra desitjada
            }
        }
        if(operacion=="treure_unitats")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(m1.find()==false) cout<<"error"<<endl;
            else
            {
                magatzem. //metode que retorni la cambra desitjada
            }
        }
        if(operacion=="distribuir")
        {
          
        }
        if(operacion=="comprimir")
        {
          
        }
        if(operacion=="ordenar")
        {
          
        }
        if(operacion=="canviar_nevera")
        {
          
        }
        if(operacion=="inventari")
        {
          
        }
        if(operacion=="escriure")
        {
          
        }
        if(operacion=="consultar_pos")
        {
          
        }
        if(operacion=="consultar_vac")
        {
          
        }
        if(operacion=="fi")
        {
          magatzem.fi();
        }
        
        
        
        
        
        
    }



}




