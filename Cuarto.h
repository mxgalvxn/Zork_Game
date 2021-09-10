#ifndef Cuarto_h
#define Cuarto_h

#include <iostream>
#include "Item.h"
using namespace std;

//Estabamos un poco perdidos con el cuarto, asi que decidimos basarnos en la clase de "Room.h" para poder completarla

class Cuarto{
    public:
        //Constructores
        Cuarto();
        Cuarto(string, bool );
        //Destructor
        ~Cuarto();

        //Getters
        string getDescripcion();
        Cuarto* getPuertas(string);
        bool getAcceso();
        string getItem(int) const;
        int numPuertas(string);

        //Setters
        void setPuertas(Cuarto*, Cuarto*,Cuarto*,Cuarto*);

        //Metodos
        void sacarItem(int);
        void agregarItem(Item* );
        void eliminarInventario(int);

        //Sobrecarga de operadores
        friend ostream& operator<< (ostream &, const Cuarto&);
    private:
    
        //Atributos
        Cuarto* puertas[2];
        Item* inventario_cuarto[10];
        string descripcion;
        bool acceso;
        int cant_item;
};

Cuarto::Cuarto(){
    acceso = false;
    descripcion="Es una habitacion desconocida";
    for (int i=0; i<2; i++){
        puertas[i]=nullptr;
    }
    cant_item = 0;
}

Cuarto::Cuarto(string _desc, bool _acc){
    acceso = _acc;
    descripcion = _desc;
    for (int i=0; i<2; i++){
        puertas[i]=nullptr;
    }
    cant_item = 0;
}

Cuarto::~Cuarto(){}



void Cuarto::setPuertas(Cuarto* n, Cuarto* s, Cuarto* e, Cuarto* o){
    puertas[0]=n;
    puertas[1]=s;
    puertas[2]=e;
    puertas[3]=o;
}


Cuarto* Cuarto::getPuertas(string pos){
    int n = numPuertas(pos);
    if(n>=0){
        return puertas[n];
    }
    return nullptr;
}

string Cuarto::getDescripcion(){
    return descripcion;
}

string Cuarto::getItem(int pos) const{
    if(pos<cant_item && pos<10){
        return inventario_cuarto[pos]->getTipo();
    }
    else{
        return "Vacio"; 
    }
}




int Cuarto::numPuertas(string pos2){
    int pos;
    if (pos2=="norte"){
        pos = 0;
    }
    if (pos2=="sur"){
        pos = 1;
    }
    if (pos2=="este"){
        pos = 2;
    }
    if (pos2=="oeste"){
        pos = 3;
    }
    pos = -1;
    return pos;
}

bool Cuarto::getAcceso(){
    return acceso;
}

//Esta función marca error de vez en cuando, pero de alguna manera se soluciona solo
void Cuarto::agregarItem(Item* it){
    if(cant_item<4){
        inventario_cuarto[cant_item++] = it;
    }
    else{
        cout << "Espacio insuficiente!" << endl;
    }
}


void Cuarto::eliminarInventario(int n){
    inventario_cuarto[n]->setTipo("");
}

//Sobrecarga de operadores
ostream& operator<< (ostream & salida, Cuarto* desc){
    salida<<desc->getDescripcion();

    return salida;
}

#endif //Cuartos_h