#include "cesarcode.h"
#include <iostream>
using namespace std;
CesarCode::CesarCode()
    :key(0)//inicializa key con 0
{

}

CesarCode::CesarCode(int k)
    :key(k)//inicilaiza key con k
{

}

std::__cxx11::string CesarCode::encrypt(std::string message)
{

    int avanzar;
    for (int i = 0; i < message.length(); ++i) {

        avanzar=(getPos(message[i])+key)%27;//avanza la posicion de la letra en el alfabeto mas la llave y le saca
                                           //modulo
        this->result.push_back(alfabeto[avanzar]);//agrega la palabra al string result;

    }
    return this->result;//retorna el resultado
}

std::__cxx11::string CesarCode::decrypt(std::string message)
{
    string result1 {};//crea otro string result1 para almacenar las nuevas letras que se decriptaran
    string alfabeto1=alfabeto;//copia del alfabeto a alfabeto1
    reverse(alfabeto1.begin(),alfabeto1.end());//invierte el alfabeto 1
    int retroceder;

    for (int i = 0; i < message.length(); ++i) {

        if(getPos(this->result[i])<key)//si la posicion del la letra en la posicion i es menor que la clave
        {
            retroceder=(((getPos(this->result[i])-key)+1)%27);//resta posicion de la letra en i - la clave y
                                                             //le suma +1 por que comiensa desde 0
            if(retroceder<0)
            {
                retroceder=-1*retroceder;//convierte retroceder en positivo
            }
            result1.push_back(alfabeto1[retroceder]);//agrega la nueva letra a result1
        }
        else if(getPos(this->result[i])>=key)//si la posicion de la letra en i es mayor o igual que la clave
        {
            retroceder=(getPos(this->result[i])-key)%27;
            if(retroceder<0)
            {
                retroceder=-1*retroceder;
            }
            result1.push_back(alfabeto[retroceder]);

        }
    }
    return result1;//retorna la palabra desincriptada
}

int CesarCode::getPos(char l)//esta funcion retorna la posicion de la letra en el alfabeto
{
    int num=0;
    for (int i = 0; i < alfabeto.length(); ++i) {
        if(l==alfabeto[i])//si la la letra l es igual a una letra alfabeto[i] retorna esa posicion i
            num=i;
    }
    return num;
}

