#include "Cartas.h"
#include <iostream>

using namespace std;

class Deck {

    private:
        Deck baseCartas[50];
        Deck deckPersonal[30];
        int cont;

    public:
        Deck(){
        }
        void AgregaCmonstruo(Monstruo &m);
        void AgregaCmagica(Magia &mag);
        void AgregaCtrampa(Magia &t);
        void cuentaCartas(deckPersonal);



};
