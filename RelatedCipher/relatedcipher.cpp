#include "relatedcipher.h"
#include <iostream>
using namespace std;
RelatedCipher::RelatedCipher()
    :key(0),key1(0)
{

}

RelatedCipher::RelatedCipher(int k,int k1)
    :key(k),key1(k1)
{

}

string RelatedCipher::encrypt(string message)
{
    string result;
    for (int i = 0; i < message.length(); ++i) {
        //std::size_t avanzar=(alfabeto.find(message[i])+key)%alfabeto.length();//avanza la posion de la palabra en el alfabeto mas key
        std::size_t avanzar=(key*alfabeto.find(message[i])+key1)%alfabeto.length();
        //cout << "avanzar" << avanzar << "alfabeto" << alfabeto.find(message[i]) << endl;
        result.push_back(alfabeto[avanzar]);//agrega la palabra al string result;
    }
    return result;//retorna el resultado

}

string RelatedCipher::decrypt(string message)
{
    string result1{};
    int inverso=euclides(key,alfabeto.length());
    cout << "inversa" << inverso << endl;
    int retroceder;
    for (int i = 0; i < message.length(); ++i) {
        //retroceder=(alfabeto.find(message[i])-key);//calcula retroceder buscando la posicion le la letra en el alfabeto menos la llave
        retroceder=((alfabeto.find(message[i])-(key1))*inverso);
        //cout << "retroceder is " << retroceder << endl;
        if(retroceder<0)//cuando retroceder es negativo
        {
            retroceder=-1*retroceder;//convierte a positivo
            if(retroceder==alfabeto.length())//en el caso de que retrocedar sea == al tamaño del alfabeto ejemplo 27%27=0
            {   //encambio si retroceder=alfabeto.length()-(retroceder%alfabeto.length()); --> retroceder=27-(27%27)
                retroceder=alfabeto.length()-retroceder;//retroceder =27 y en la posicion 27 en el lalista del alfabeto no existe
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

int RelatedCipher::module(int x, int y)
{
    int q=x/y,r;
    if(q<0)
    {
        q=-1*q;
        q++;
        q=-1*q;
        r=x-(q*y);
    }
    else
    {
        r=x-(q*y);
    }
    return r;
}

int RelatedCipher::euclides(int a, int b )
{
    int q,r,r1=a,r2=b,s,s1,s2,t,t1,t2;
    s1=1,s2=0,t,t1=0,t2=1;
    //cout << "q" << "\t"<<"r1 "<< "\t" << "r2 "<< "\t" << "r "<< "\t" << "s1 "<< "\t" << "s2 "<< "\t" << "s "<< "\t" << "t1" << "\t"<< "t2 " << "\t"<< "t " << endl;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-(q*r2);
        r1=r2;
        r2=r;
        //-----
        s=s1-(q*s2);
        s1=s2;
        s2=s;
        //cout << s << "\t" << s1 << "\t" << s2 << endl;
        //-------
        t=t1-(q*t2);
        t1=t2;
        t2=t;
        //cout << q << "\t" << r1<< "\t" << r2<< "\t" << r<< "\t" << s1<< "\t" << s2<< "\t" << s<< "\t" <<t1<< "\t" <<t2<< "\t" << t << endl;
    }
    return s1;
}
