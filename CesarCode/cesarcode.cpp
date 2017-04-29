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

std::__cxx11::string CesarCode::encrypt(std::string message) //funcion para encriptar un mensaje
{
    string result;
    for (int i = 0; i < message.length(); ++i) {
        std::size_t avanzar=(alfabeto.find(message[i])+key)%alfabeto.length();//avanza la posion de la palabra en el alfabeto mas key
        result.push_back(alfabeto[avanzar]);//agrega la palabra al string result;
    }
    return result;//retorna el resultado
}

std::__cxx11::string CesarCode::decrypt(std::string message)//funcion para desincriptar un mensaje
{
    string result1{};
    int retroceder;
    for (int i = 0; i < message.length(); ++i) {
        retroceder=(alfabeto.find(message[i])-key);//calcula retroceder buscando la posicion le la letra en el alfabeto menos la llave
        if(retroceder<0)//cuando retroceder es negativo
        {
            retroceder=-1*retroceder;//convierte a positivo
            if(retroceder==alfabeto.length())//en el caso de que retrocedar sea == al tamaño del alfabeto ejemplo 27%27=0
            {   //encambio si retroceder=alfabeto.length()-(retroceder%alfabeto.length()); --> retroceder=27-(27%27)
                retroceder=alfabeto.length()-retroceder;//retroceder =27 y en la posicion 27 en el lalista del alfabeto no existe
                cout << "entra" << endl;
            }
            else if (retroceder%alfabeto.length()==0){// en el caso de que retroceder%tamaño del alfabeto  sea igual a 0
                retroceder=retroceder%alfabeto.length();//en este caso solo saca modulo
            }
            else//si no pasa ninguno de las anteriores
                retroceder=alfabeto.length()-(retroceder%alfabeto.length());
            result1.push_back(this->alfabeto[retroceder]);
        }

        else if(retroceder>=0)//cuando retroceder es positivo
        {
            retroceder=retroceder%alfabeto.length();
            result1.push_back(this->alfabeto[retroceder]);
        }
    }
    return result1;//retorna el resultado
}
