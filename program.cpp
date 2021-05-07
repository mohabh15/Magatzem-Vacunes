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
    for(int i=1; i<=numero_cambres;++i)
    {
        cin>>files>>columnes;
        magatzem.cambra(i).canviar_nevera(files,columnes);
        //cout<<magatzem.cambra(i).files()<<endl;
    }

    cout<<"Cin de Magatzem fet"<<endl;

    string operacion;
    int  ident_cambra;
    string ident_vacuna; 
    int quantitat; 

    //Operacions 
    while(cin>>operacion)
    {
        if (operacion=="afegir_vac")  //Ja funciona, la he fet jo perque la necesito per comprovar els altres metodes de la classe cambra
        {
            cin>>ident_vacuna;
            magatzem.afegir_vacuna(ident_vacuna);
            cout<<"afegir_vac fet"<<endl;
        }
        if (operacion=="treure_vac")
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            magatzem.treure_vacuna(ident_vacuna);
        }
        if(operacion=="afegir_unitats")    // Ja funciona
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(magatzem.find(ident_vacuna)==false) cout<<"error"<<endl;
            else
            {
                magatzem.modificar_sistema(ident_vacuna,quantitat,'+');
                cout<<magatzem.cambra(ident_cambra).afegir_unitats(ident_vacuna,quantitat)<<endl;   
                cout<<"afegir_unitas fet"<<endl;
            }
        }
        if(operacion=="treure_unitats")  //Ja funciona 
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            if(magatzem.find(ident_vacuna)==false) cout<<"error"<<endl;
            else
            {
                magatzem.modificar_sistema(ident_vacuna,quantitat,'-');
                cout<<magatzem.cambra(ident_cambra).treure_unitats(ident_vacuna,quantitat)<<endl; 
                cout<<"treure_unitats fet"<<endl;
            }
        }
        /*if(operacion=="distribuir")
        {
            cout<<magatzem.distribuir(ident_vacuna,quantitat)<<endl;
        }*/
        if(operacion=="comprimir") //Ja funciona 
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).comprimir();
            cout<<"comprimir fet"<<endl;
        }



        if(operacion=="ordenar") //Ja funciona 
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).ordenar();
            cout<<"ordenat fet"<<endl;
        }



        if(operacion=="canviar_nevera")  //de momento ya funciona 
        {
            cin>>ident_cambra>>files>>columnes;
            magatzem.cambra(ident_cambra).canviar_nevera(files,columnes);
        }
        if(operacion=="inventari")
        {
            magatzem.inventari();
        }
        if(operacion=="escriure")  // funciona pero falta arreglar una cosa 
        {
            cin>>ident_cambra;
            magatzem.cambra(ident_cambra).escriure();
            cout<<"escriure fet"<<endl;
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




