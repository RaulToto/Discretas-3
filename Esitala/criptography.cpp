#include "criptography.h"
using namespace std;
Criptography::Criptography()
    :key(0)
{

}

Criptography::Criptography(int k)
    :key(k)
{

}

std::__cxx11::string Criptography::encrypt(std::string message)
{
    std::string list;
    int i,k=0;//contadores k e i
    int avanzar=(2*this->key)-2;//avanzar
    int avanzar1=avanzar;//avanzar1
    for ( i= 0; i < message.length(); i++)
    {
        list.push_back(message[i]);//siempre agrega  en la posicion i
        if(i==avanzar1/2)//si i== a la mitad de avanzar/2
        {
            k=avanzar1/2;//icializa k con avanzar1/2
            i=message.length();//inicializa i con el tamaño del mensaje para terminar el bucle
        }
        while(avanzar<=message.length() && k<=message.length())
        {
            if(i==0)
                list.push_back(message[avanzar]);

            else if(i>0 and i<avanzar1/2)
            {
                list.push_back(message[avanzar-i]);
                if((avanzar+1)<message.length())
                {
                    list.push_back(message[avanzar+i]);
                }

            }
            else if(i==message.length())
            {
                k=k+avanzar1;
                list.push_back(message[k]);
            }

            avanzar=avanzar+avanzar1;
        }
        avanzar=avanzar1;
    }
    return list;
    //cout << "la lista es:" << list;
}

string Criptography::decrypt(std::string message)
{
    string str=message;//lista para desincriptar
    int avanzar=(2*this->key)-2;//avanzar
    int avanzar1=avanzar;//avanzar1
    int i,k=0,j=2,aumentar=2;
    for ( i = 0; i < message.length(); ++i) {
        str[i]=message[k++];
        //cout<< "the first message"<< message[k++];
        while (avanzar<=message.length())
        {
            if(i==0)
            {
                str[avanzar]=message[k++];
                cout << "cuando i ==0" << endl;
            }
            else if(i>0 and i<avanzar1/2)
            {
                cout << "cuand i-1-2" << endl;
                str[i+j]=message[k++];
                avanzar=avanzar-aumentar;
            }
            else if(i==avanzar1/2)
            {
                if(j==2)
                {
                    k++;
                    //cout << "agregar -->"  << k <<"---"<< message[k] << endl;
                    str[i]=message[k];
                }
                else
                {
                    k++;
                    str[i+avanzar]=message[k];
                }
                i=message.length();
                cout << "cuando i==2" << endl;
            }
            avanzar=avanzar+avanzar1;
            j=j+aumentar;
            //cout << "avanzar" << avanzar << endl;
        }
        avanzar=avanzar1;
        j=2;
        aumentar+=2;
    }
    return str;
}
