#ifndef Personaje_h
#define Personaje_h

#include <iostream>
#include <vector>
using namespace std;
#define BWHT "\e[1;37m"

#include "Cuarto.h"
#include "Item.h"


class Personaje{
    public:
        //Constructores
        Personaje();
        Personaje(string, Cuarto*, string, int);
        //Destructor
        ~Personaje();

        //Setters
        void setNombre(string);
        void setPosicion(Cuarto*);
        void setTipo (string);
        void setHp(int);
        
        
        //Getters
        string getNombre() const;
        Cuarto* getPosicion() const;
        string getTipo() const;
        int getHp() const;
        int getCantItems() const;
        string getItem(int) const;

        //Métodos
        virtual void mostrarInventario();
        virtual void Atacar(Personaje* );
        virtual void dropItem(Personaje*);
        void agregarItem(Item* );
        void mostrarVida();
        void eliminarInventario(string);
        void imprime_carac();

    private:
        //Atributos
        string Nombre;
        Cuarto* cuartoActual;
        string Tipo;
        int HP, cant_item;
        Item* inventario[10]; 
};

Personaje::Personaje(){
    Nombre = "";
    HP = 100;
    Tipo = "";
    cant_item=0;
    cuartoActual = nullptr;
    
}

Personaje::Personaje(string _n, Cuarto* _c, string _t, int _hp){
    Nombre = _n;
    cuartoActual = nullptr;
    Tipo = _t;
    HP = _hp;
    cant_item = 0;
}

Personaje::~Personaje(){}

string Personaje:: getNombre() const{
    return Nombre; 
}

Cuarto* Personaje::getPosicion() const{
    return cuartoActual;
}

string Personaje:: getTipo() const{
    return Tipo;
}

int Personaje::getHp() const{
    return HP;
}
 
void Personaje::setNombre(string nom){
    Nombre = nom;
}

void Personaje::setPosicion(Cuarto* pos){
    cuartoActual = pos;
}

void Personaje:: setTipo(string tipo){
    Tipo = tipo;
}

void Personaje::setHp( int hp){
    HP = hp;
}

   

int Personaje::getCantItems() const{
    return cant_item;
}

string Personaje::getItem(int pos) const{
    if(pos<cant_item && pos<10){
        return inventario[pos]->getTipo();
    }
    else{
        throw "Posicion invalida, reingresela: "; 
    }
}

void Personaje::agregarItem(Item* it){
    if(cant_item<10){
        inventario[cant_item++] = it;
    }
    else{
        throw "Espacio insuficiente";
    }

    cout<<"Se ha agregado "<< it->getTipo()<< " al inventario"<<endl;
}


void Personaje:: mostrarInventario(){
    int cont_llave=0, cont_posc=0, cont_oro=0, invt = 0 ; 
    string item;
    for(int j = 0; j<cant_item;j++){
        item = inventario[j]->getTipo();

        if(item == "Llave"){
            cont_llave+=1;
             invt++;
        }
        else if(item=="Tapipeso"){
            cont_oro+=1;
             invt++;
        }
         else if (item == "Gansito"){
            cont_posc+=1;
             invt++;
        }
    }
    if(cont_llave!=0){
        cout << "Tienes " << cont_llave << " llaves"<< endl;
    }
    if(cont_oro!=0){
        cout << "Tienes " << cont_oro << " tapipesos"<<endl;;
    }
    if(cont_posc!=0){
        cout << "Tienes " << cont_posc << " Gansitos" << endl;
    }
    if ( invt == 0){
        throw "No tienes nada en tu inventario!";
    }

}

void Personaje::eliminarInventario(string tipo){
    for (int i = 0; i< cant_item; i++){
        string tipo1 =inventario[i]->getTipo();
        if (tipo1 == tipo){
             inventario[i]->setTipo("");
        }
    }         
}

void Personaje::Atacar(Personaje* enemigo){
    int salud = enemigo->getHp();
    int dano = 5 + rand()%15+1;;
    enemigo->setHp(salud-dano) ;
    cout<< BWHT<<"\n" <<Nombre<< " ha atacado a " << enemigo->getNombre()<<endl;
    cout<< BWHT<< enemigo->getNombre()<< " ha perdido " << dano << " pts de vida"<<endl;
}

void Personaje:: mostrarVida(){
    cout<< Nombre<< " tiene "<< HP << " de vida"<<endl;
}

void Personaje::imprime_carac(){
    cout << "Mi nombre es " << Nombre << " y tengo " << HP << " de vida" << endl;
    
}


void Personaje::dropItem(Personaje* per){
    int i = 0;
}


#endif //Personaje.h