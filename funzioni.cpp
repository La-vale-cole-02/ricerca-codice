#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "funzioni.hpp"


const string archivio="squadre.dat";int n=0;
struct squadra
{
    string nome;
    int punti;
    string capocannoniere;
    int goal;
}
s,gruppo[DIM];

//! \relates FUNZIONI
/*! \fn insetrimento()
    \brief inserimento nel file

*/

void inserimento()
{
    string a;
             do{
        fflush(stdin);
        cout << "Inserisci squadra:";
       getline(cin,gruppo[n].nome);
       cout << "Inserisci punti:";
       cin>>gruppo[n].punti;
       fflush(stdin);
       cout << "Inserisci capocannoniere:";
       getline(cin,gruppo[n].capocannoniere);
       cout << "Inserisci numero goal:";
       cin>>gruppo[n].goal;
       n++;
   if(n!=DIM)
        {
        cout<<"Premere a per inserire la prossima squadra, altrimenti q: ";
        cin>>a;
    }
    else
        a="q";
    }while(a=="a");

}


//! \relates FUNZIONI

/*! \fn scrivi()
    \brief scrive quello che abbiamo inserito prima nel file

*/

void scrivi()
{
    ofstream scrivi;

     scrivi.open(archivio.c_str(),ios::app | ios::binary);

    if(!scrivi)

        cout << "errore in apertura del file "<<endl;
    else
        {
        for(int i=0 ; i<n ; i++)

            scrivi.write((char*)&gruppo,sizeof(gruppo));


    }
   scrivi.close();

}


//! \relates FUNZIONI

/*! \fn leggi()
    \brief leggi quello che c'è all'interno del file

*/

void leggi()
{

    int c=0;
    string linea;
    fstream leggi;
    leggi.open(archivio.c_str(),ios::in | ios::binary);

    if(!leggi)

        cout << "errore in apertura del file "<<endl;
       else
       {

        while(leggi.read((char*)&gruppo,sizeof(gruppo)));
       {
            cout<<"nome "<<gruppo[c].nome<<endl;
            cout<<"punti "<<gruppo[c].punti<<endl;
            cout<<"capocannoniere "<<gruppo[c].capocannoniere<<endl;
            cout<<"goal "<<gruppo[c].goal<<endl;


         c++;
        }


    }
    leggi.close();
         fflush(stdin);

}


//! \relates FUNZIONI

/*! \fn classifica_punti()
    \brief restituisce la classifica dei punti della squadra dal maggiore al minore

*/

void classifica_punti()
{

    int temp;
    string temp1;

        for(int b=0; b<=n ; b++)
        {
            for(int c=b+1 ; c<n ; c++)
            {
                if(gruppo[b].punti < gruppo[c].punti)
                {
                    temp1=gruppo[b].nome;
                    gruppo[b].nome = gruppo[c].nome;
                    gruppo[c].nome = temp1;

                     temp=gruppo[b].punti;
                    gruppo[b].punti = gruppo[c].punti;
                    gruppo[c].punti = temp;

                     temp1=gruppo[b].capocannoniere;
                    gruppo[b].capocannoniere = gruppo[c].capocannoniere;
                    gruppo[c].capocannoniere = temp1;

                     temp=gruppo[b].goal;
                    gruppo[b].goal = gruppo[c].goal;
                    gruppo[c].goal = temp;




                }
            }
        }

    cout<< " la classifica dei punti e' : "<<endl<<endl;
    for(int x=0;x<n;x++)
    {
       cout << gruppo[x].punti  << "   " << gruppo[x].nome  <<endl<<endl<<endl;
    }

}


//! \relates FUNZIONI

/*! \fn classifica_marcatori()
    \brief restituisce la classifica dei marcatori da quello che ha fatto più goal a quello che ne ha fatti di meno

*/

void classifica_marcatori()
{
    int temp;
    string temp1;

        for(int b=0; b<=n ; b++)
        {
            for(int c=b+1 ; c<n ; c++)
            {
                if(gruppo[b].goal < gruppo[c].goal)
                {
                    temp1=gruppo[b].nome;
                    gruppo[b].nome = gruppo[c].nome;
                    gruppo[c].nome = temp1;

                     temp=gruppo[b].punti;
                    gruppo[b].punti = gruppo[c].punti;
                    gruppo[c].punti = temp;

                     temp1=gruppo[b].capocannoniere;
                    gruppo[b].capocannoniere = gruppo[c].capocannoniere;
                    gruppo[c].capocannoniere = temp1;

                     temp=gruppo[b].goal;
                    gruppo[b].goal = gruppo[c].goal;
                    gruppo[c].goal = temp;


                }
            }
        }

    cout<< " la classifica dei marcatori è:  "<<endl<<endl;
    for(int x=0;x<n;x++)
    {
       cout << gruppo[x].capocannoniere  << "  ha fatto  "<< gruppo[x].goal  <<" goal "<<endl<<endl<<endl;
    }

}

//! \relates FUNZIONI

/*! \fn ricerca()
    \brief fa la ricerca del codice

*/

void ricerca()
{
    int cod;
    long cont;
    int scelta;

    fstream codice;
    codice.open(archivio.c_str(),ios::in | ios::binary);
    if(!codice)
        cout<<"Errore nell'apertura del file";

    else{
        cout<<"Inserisci il codice da cercare:";
        cin>>cod;
        cont=(cod-1)*(sizeof(gruppo));
        codice.seekg(cont);
        codice.read((char*)&gruppo,sizeof(gruppo));
        cout<<"Nome:"<<gruppo[cont].nome<<endl;
        cout<<"Punti:"<<gruppo[cont].punti<<endl;
        cout<<"Capocannoniere:"<<gruppo[cont].capocannoniere<<endl;
        cout<<"Goal:"<<gruppo[cont].goal<<endl<<endl;
}
}
