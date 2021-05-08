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
            cout<<"afegir_vac fet"<<ident_vacuna<<endl;
            magatzem.afegir_vacuna(ident_vacuna);
        }
        if (operacion=="treure_vac")  //Ja funciona
        {
            cin>>ident_vacuna;
            cout<<"treure_vac "<<ident_vacuna<<endl;
            magatzem.treure_vacuna(ident_vacuna);
        }
        if(operacion=="afegir_unitats")    // Ja funciona
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            cout<<"afegir_unitats "<<ident_cambra<<" "<<ident_vacuna<<" "<<quantitat<<endl;
            if(magatzem.find(ident_vacuna)==false) cout<<" error"<<endl;
            else
            {
                magatzem.modificar_sistema(ident_vacuna,quantitat,'+');
                cout<<" "<<magatzem.cambra(ident_cambra).afegir_unitats(ident_vacuna,quantitat)<<endl;   
            }
        }
        if(operacion=="treure_unitats")  //Ja funciona 
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            cout<<"treure_unitats "<<ident_cambra<<" "<<ident_vacuna<<" "<<quantitat<<endl;
            if(magatzem.find(ident_vacuna)==false) cout<<" error"<<endl;
            else
            {
                magatzem.modificar_sistema(ident_vacuna,quantitat,'-');
                cout<<" "<<magatzem.cambra(ident_cambra).treure_unitats(ident_vacuna,quantitat)<<endl; 
            }
        }
        /*if(operacion=="distribuir")
        {
            cout<<magatzem.distribuir(ident_vacuna,quantitat)<<endl;
        }*/
        if(operacion=="comprimir") //Ja funciona 
        {
            cin>>ident_cambra;
            cout<<"comprimir "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).comprimir();
        }
        if(operacion=="ordenar") //Ja funciona 
        {
            cin>>ident_cambra;
            cout<<"ordenar "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).ordenar();
        }
        if(operacion=="canviar_nevera")  //Ja funciona 
        {
            cin>>ident_cambra>>files>>columnes;
            cout<<"canviar_nevera "<<ident_cambra<<" "<<files<<" "<<columnes<<endl;
            magatzem.cambra(ident_cambra).canviar_nevera(files,columnes);
        }
        if(operacion=="inventari")  //Ja funciona
        {
            cout<<"inventari"<<endl;
            magatzem.inventari();
        }
        if(operacion=="escriure")  // Ja funciona 
        {
            cin>>ident_cambra;
            cout<<"escriure "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).escriure();
        }
        if(operacion=="consultar_pos") //Ja funciona
        {
            cin>>ident_cambra>>files>>columnes;
            cout<<"consultar_pos "<<files<<" "<<columnes<<endl;
            cout<<" "<<magatzem.cambra(ident_cambra).consultar_posicio(files,columnes)<<endl;
        }
        if(operacion=="consultar_vac")  //Ja funciona
        {
            cin>>ident_vacuna;
            cout<<"consultar_vac "<<ident_vacuna<<endl;
            cout<<" "<<magatzem.consultar_vacuna(ident_vacuna)<<endl;
        }
        if(operacion=="fi")
        {
          magatzem.fi();
        }
    


    }
}




