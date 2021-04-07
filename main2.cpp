#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "funzioni.hpp"

using namespace std;

    /*! \mainpage <CENTER> riceerca del codice </CENTER>
    * \author <B> colella valentina</B>
    * \version <B> V1.0 </B>
    * \date <B> Consegna progetto:  08/04/2021 </B>
    *
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    * - fare l'inserimento
    * - scrivere una struct e stamparla
    * - fare la classifica dei punti ed dei marcatori
    * - ricercare il codice
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */



ifstream inp;
ofstream outp;


int main()
{

    //! \brief main dove si sceglie cosa far fare al programma
    int scelta;

    do
    {
        cout<<"0. inserimento"<<endl;
        cout<<"1. scrivi"<<endl;
        cout<<"2. leggi"<<endl;
        cout<<"3. classifica punti "<<endl;
        cout<<"4. classifica marcatori "<<endl;
        cout<<"5. ricerca"<<endl;
        cout<<"6. esci"<<endl;
        cin >> scelta;


        switch(scelta)
        {
            case 0: inserimento();
                        break;

            case 1: scrivi();
                        break;

            case 2: leggi();
                        break;

            case 3: classifica_punti();
                        break;

            case 4: classifica_marcatori();
                        break;

            case 5: ricerca();
                        break;

            case 6: cout<<"grazie di avere utilizzato questo programma"<<endl;
                        break;
        }
    }
    while(scelta!=7);
    return 0;
}
