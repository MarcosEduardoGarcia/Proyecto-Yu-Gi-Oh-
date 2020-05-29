#include <iostream>

#include "Monstruo.h"
#include "Magia.h"
#include "Trampa.h"
#include "Deck.h"

using namespace std;

int main(){

    Deck *principal = new Deck();


    principal->CargarBaseCartas();
    principal->mostrarCartas();
    principal->cuentaTipos();
    cout << endl;
    principal->ArrojaNombres();
    cout << endl;
    principal->ActivarInvocacion();


    delete principal;
    return 0;
}
