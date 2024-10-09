#include  "Graphe.h"
#include <iostream>
using namespace std;
int main()
{
    Graphe G;
    cout<< endl ;
    int continuer=1;
    do{
        G.initialiser();
        G.dijkstra();
        cout << endl;
        cout <<"****resultats******"<<endl;
        G.afficher();
        cout<<"continuer(1/0)?"<<endl;
        cin>>continuer;
    }
    while(continuer==1);
        return 0;
}
