#include  "Graphe.h"
#include <iostream>

using namespace std;
Graphe::Graphe()
{
    cout << "Nombre de noeuds du graphe ?";
    cin >> n;
    g = new int * [n];
    int i,j;
    for (i=0;i<n;i++)
        g[i]=new int [n];
    cout << "Saisie de la matrice des distance"<<endl;
    cout << "Saisie les distance entre les noeuds"<<endl;
    cout << "Saisie 9999 en cas d'absence direct entre 2 noeuds differents"<<endl;
    cout << "Saisie la valeur 0 pour la distance d'un a meme noeud"<<endl;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
        cout  <<"distance arc "<<"("<<i<<","<<j<<")"<<endl;
        cin >>g[i][j];
        }
        distmin = new int[n];
        disttrouve = new bool[n];
        pred = new int[n];
}
void Graphe::initialiser()
{
    int i ;
    cout  <<"Donnez le noeud source" <<endl;
    cin  >> source ;
    cout << endl;
     for (i=0;i<n;i++)
     distmin[i]=9999;
      for (i=0;i<n;i++)
        disttrouve[i]=false;
       disttrouve[i]=false;
       for (i=0;i<n;i++)
        pred[i]=-1;
}


void Graphe::dijkstra()
{
int i,j;
for (j=0;j<n;j++)
{
    distmin[j]= g[source][j];
    pred[j]=source;
    }
disttrouve[source]=true;
distmin[source]=0;
pred[source]=source;
for (int i=0; i < n-1 ; i++)
{
    int mind = 9999;
    int v=source;
    for (j=0; j<n;j++)

        if(!disttrouve[j])
        if(distmin[j] < mind)
    {
        v=j;
        mind = distmin[v];
    }
    disttrouve[v] = true;
    for (int j=0 ; j< n ;j++)
        if (!disttrouve[j])
        if(mind + g[v][j] < distmin[j])
    {
        distmin[j] = mind + g[v][j];
        pred[j]=v;

    }
}


}
void Graphe::afficher()
{
    int i;
    for (i=0;i<n;i++)
    {
        if(i == source)
            cout << source << " "<<source;
        else
            imprimechemin(i);

        if (distmin[i]!=9999)
            cout<<"distance minimale:"<<distmin[i]<<endl;
        else
            cout<<"pas se chemin !!!!!"<<endl;
    }
}
void Graphe::imprimechemin(int noeud)
{
    if (noeud == source)
        cout<<noeud<<" ";
        else
            {
        imprimechemin(pred[noeud]);
        cout<<noeud <<" ";
            }


}










