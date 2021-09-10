#ifndef Item_h
#define Item_h

#include <iostream>
using namespace std;


class Item{
    public:
        //Constructores
        Item();
        Item(string);
        //Getter
        string getTipo() const;
        //Setter
        void setTipo(string);
        //Método
        void mostrarDesc();

    private:
        //Atributo
        string Tipo;
};

Item::Item (){
    Tipo = "";
}

Item::Item( string _tipo){
    Tipo = _tipo;
}



string Item::getTipo() const{
  return Tipo;
}



void Item::setTipo(string  _tipo){
  Tipo = _tipo;
}


void Item::mostrarDesc(){
    if (Tipo == "Gansito"){
        cout<< "Gansito regenerador: "<< endl;
        cout<< "Este gansito recuperara los puntos de salud perdidos en una pelea"<< endl;
        cout<< "Salud +10"<<endl;
    }
    else if(Tipo == "Llave"){
        cout<< "LLave maestra: "<< endl;
        cout<< "Esta llave te permitira abrir la siguiente puerta "<< endl;
    }
    else{
        cout<< "Tapipesos  "<< endl;
        cout<< "Muy util para gastar en Abarrotes Goku, tristemente hoy esta cerrado :C"<< endl;
    }
}

#endif