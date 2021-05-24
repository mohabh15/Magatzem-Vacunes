#include <iostream>
#include "magatzem.hpp"
using namespace std;

int main()
{
    int numero_cambres;
    cin>>numero_cambres;

    //Lectura de l'Estructura del magatzem
    vector<int> llista_cambres;
    for(unsigned int i; i < numero_cambres; ++i)
    {
        int cambra;
        cin >> cambra;
        llista_cambres.push_back(cambra);
    }

    Magatzem magatzem(numero_cambres,llista_cambres);

    //Cin mida cambres
    int files,columnes;
    for(int i = 1; i<=numero_cambres;++i)
    {
        cin>>files>>columnes;
        magatzem.cambra(i).canviar_nevera(files,columnes);
    }

    //Declaracio de Variables que es necessitaran 
    string operacion;
    int  ident_cambra;
    string ident_vacuna; 
    int quantitat; 

    //Operacions 
    while(cin>>operacion)
    {
        if (operacion=="afegir_vac")  
        {
            cin>>ident_vacuna;
            cout<<"afegir_vac "<<ident_vacuna<<endl;
            magatzem.afegir_vacuna(ident_vacuna);
        }
        if (operacion=="treure_vac")  
        {
            cin>>ident_vacuna;
            cout<<"treure_vac "<<ident_vacuna<<endl;
            magatzem.treure_vacuna(ident_vacuna);
        }
        if(operacion=="afegir_unitats")    
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            cout<<"afegir_unitats "<<ident_cambra<<" "<<ident_vacuna<<" "<<quantitat<<endl;
            if(magatzem.find(ident_vacuna)==false) cout<<" error"<<endl;
            else
            { 
                int n=magatzem.cambra(ident_cambra).afegir_unitats(ident_vacuna,quantitat);
                cout<<"  "<<n<<endl;
                magatzem.modificar_sistema(ident_vacuna,quantitat-n,'+');
            }
        }
        if(operacion=="treure_unitats")   
        {
            cin>>ident_cambra>>ident_vacuna>>quantitat;
            cout<<"treure_unitats "<<ident_cambra<<" "<<ident_vacuna<<" "<<quantitat<<endl;
            if(magatzem.find(ident_vacuna)==false) cout<<" error"<<endl;
            else
            {
                int n=magatzem.cambra(ident_cambra).treure_unitats(ident_vacuna,quantitat);
                cout<<"  "<<n<<endl; 
                magatzem.modificar_sistema(ident_vacuna,quantitat-n,'-');
            }
        }
        /*if(operacion=="distribuir")
        {
            cout<<magatzem.distribuir(ident_vacuna,quantitat)<<endl;
        }*/
        if(operacion=="comprimir") 
        {
            cin>>ident_cambra;
            cout<<"comprimir "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).comprimir();
        }
        if(operacion=="ordenar") 
        {
            cin>>ident_cambra;
            cout<<"ordenar "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).ordenar();
        }
        if(operacion=="canviar_nevera")  
        {
            cin>>ident_cambra>>files>>columnes;
            cout<<"canviar_nevera "<<ident_cambra<<" "<<files<<" "<<columnes<<endl;
            magatzem.cambra(ident_cambra).canviar_nevera(files,columnes);
        }
        if(operacion=="inventari")  
        {
            cout<<"inventari"<<endl;
            magatzem.inventari();
        }
        if(operacion=="escriure")
        {
            cin>>ident_cambra;
            cout<<"escriure "<<ident_cambra<<endl;
            magatzem.cambra(ident_cambra).escriure();
        }
        if(operacion=="consultar_pos") 
        {
            cin>>ident_cambra>>files>>columnes;
            cout<<"consultar_pos "<<ident_cambra<<" "<<files<<" "<<columnes<<endl;
            cout<<"  "<<magatzem.cambra(ident_cambra).consultar_posicio(files,columnes)<<endl;
        }
        if(operacion=="consultar_vac") 
        {
            cin>>ident_vacuna;
            cout<<"consultar_vac "<<ident_vacuna<<endl;
            if(magatzem.consultar_vacuna(ident_vacuna)==-1)  cout<<"  error"<<endl;
            else cout<<"  "<<magatzem.consultar_vacuna(ident_vacuna)<<endl;
        }
        if(operacion=="fi")
        {
            cout<<"fi"<<endl;
            magatzem.fi();
        }
    }
}