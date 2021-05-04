#include <iostream>
#include "magatzem.hpp"
using namespace std;



int main()
{
    int numero_cambres;
    cin>>numero_cambres;
    
    Magatzem magatzem(numero_cambres);

    //Cin de magatzem 
    int files,columnes;
    for(int i=0; i<numero_cambres;++i)
    {
        cin>>files>>columnes;
        magatzem.cambra(i).canviar_nevera(files,columnes);
    }


    string operacion;
    int  ident_cambra;
    string ident_vacuna; 
    int quantitat; 
    int aux;

    //Operacions 
    while(cin>>operacion)
    {
        if (operacion=="afegir_vac")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            magatzem.afegir_vacuna(ident_vacuna);
        }
        if (operacion=="treure_vac")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            magatzem.treure_vacuna(ident_vacuna);
        }
        if(operacion=="afegir_unitats")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(magatzem.find(ident_vacuna)==false) cout<<"error"<<endl;
            else
            {
                aux=magatzem.cambra(ident_cambra).afegir_unitats(ident_vacuna,quantitat);   
                cout<<aux<<endl;
            }
        }
        if(operacion=="treure_unitats")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(magatzem.find(ident_vacuna)==false) cout<<"error"<<endl;
            else
            {
                magatzem.cambra(ident_cambra).treure_unitats(ident_vacuna,quantitat); 
            }
        }
        if(operacion=="distribuir")
        {
            cout<<magatzem.distribuir(ident_vacuna,quantitat)<<endl;
        }
        if(operacion=="comprimir")
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).comprimir();
        }
        if(operacion=="ordenar")
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).ordenar();
        }
        if(operacion=="canviar_nevera")
        {
            cin>>ident_cambra>>files>>columnes;
            magatzem.cambra(ident_cambra).canviar_nevera(files,columnes);
        }
        if(operacion=="inventari")
        {
            magatzem.inventari();
        }
        if(operacion=="escriure")
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).escriure();
        }
        if(operacion=="consultar_pos")
        {
            cin>>ident_cambra>>files>>columnes;
            magatzem.cambra(ident_cambra).consultar_posicio(files,columnes);
        }
        if(operacion=="consultar_vac")
        {
            cin>>ident_vacuna;
            magatzem.consultar_vacuna(ident_vacuna);
        }
        if(operacion=="fi")
        {
          magatzem.fi();
        }
        
        
        
        
        
        
    }



}




