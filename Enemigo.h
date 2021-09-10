#ifndef Enemigo_h
#define Enemigo_h

#include <iostream>
using namespace std;
#include <time.h>

#include "Cuarto.h"
#include "Item.h"
#include "Personaje.h"


class Enemigo: public Personaje{
    public:
        //Constructores
        Enemigo();
        Enemigo(string, Cuarto*, string, int, Item*, Personaje*);
        //Destructor
        ~Enemigo();
        //Método
        void dropItem(Personaje*) override;

private:   
    //Atributos
    Item* premio;
};

Enemigo::Enemigo(){}

Enemigo::Enemigo(string _n, Cuarto* _c, string _t, int _hp, Item* _i, Personaje* per):Personaje(_n, _c, _t, _hp){
    premio = _i;
}

Enemigo::~Enemigo(){}

void Enemigo::dropItem(Personaje* per){ 
    cout<<"Haz vencido a: "<< Personaje::getNombre() <<endl;
    cout<<Personaje::getNombre() <<" ha soltado "<< premio->getTipo() <<endl;
    per->agregarItem(premio);
}


#endif