#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "arbreBin.hpp"
#include "Cambra.hpp"
using namespace std;


typedef vector<vector<string> > Matriu;



arbreBin<int> generar_arbre(arbreBin<int>& x)
{
    int node;
    int size, nf;
    stack<arbreBin<int> > p;

    cin >> size;  

    while (size > 0) {
        cin >> node >> nf;
        if (nf == 0) 
        {  //fills buits
            p.push(arbreBin<int>(node, arbreBin<int>(), arbreBin<int>()));
        } 
        else if (nf == -1) 
        {  //nf=-1 --> nomes un fill, l'esquerre
            arbreBin<int> fe = p.top();
            p.pop();
            p.push(arbreBin<int>(node, fe, arbreBin<int>()));
        }
        else if (nf == 1) 
        {  //nf=1 --> nomes un fill, el dret
            arbreBin<int> fd = p.top();
            p.pop();
            p.push(arbreBin<int>(node, arbreBin<int>(), fd));
        } 
        else {  //nf=2 --> dos fills no buits
            arbreBin<int> fd = p.top();
            p.pop();
            arbreBin<int> fe = p.top();
            p.pop();
            p.push(arbreBin<int>(node, fe, fd));
        }
        --size;
    }
    if (not p.empty()) x = p.top();
  return x;
}


//prueba
int main()
{
    /*Matriu cambra1(3,vector<string>(3,"NULL"));

    for(unsigned int i=0; i<cambra1.size();++i )
	{
		for(unsigned int j=0; j<cambra1[0].size(); ++j) 
		{
            cout<<cambra1[i][j]<<endl;
        }
    }*/

    /*stack<arbreBin<int>> fills;
    int arrel,fe,fd;


    while(cin>>arrel)
    {
        if(arrel!=0)
        {
            arbreBin<int> aux(arrel,aux.fe(),aux.fd());
            fills.push(aux);
        }
    }
    
    while(not fills.empty())
    {
        arbreBin<int> fe=fills.top();
        fills.pop();
        arbreBin<int> fd=fills.top();

        arbreBin<int> aux1(fills.top().arrel(),fe,fd);

    }*/



    arbreBin<int> aux;

    generar_arbre(aux);
    cout<<aux;
}



//<>



