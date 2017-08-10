#include<NTL/ZZ.h>//include NTL library
#include<NTL/vector.h>
#include<iostream>//include input and output library
#include <vector>
#include <ctime>
#include <map>
#include <string.h>
#include <fstream>
#include <ctime>

#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) )
#define ClearBit(A,k)   ( A[(k/32)] &= ~(1 << (k%32)) )
#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) )
using namespace std;
using namespace NTL;
unsigned t1,t2;
int cont=0;
void guardar(long long m)
{
        ofstream archivo;
        //string line = "\\\\hline";
        archivo.open("criba10.txt",ios::app);
        archivo << m  << endl;
        archivo.close();
        cont++;
}

ZZ mySqrt(ZZ number)
{
    ZZ error = conv<ZZ>(0.00001); //define the precision of your result
    ZZ s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / conv<ZZ>(2);
    }
    return s;
}
void runEratosthenesSieve(long long size) {
      int sizeSquareRoot = (long)sqrt((double)size);
      bool *isComposite = new bool[size + 1];
      memset(isComposite, 0, sizeof(bool) * (size + 1));
      cout << "size" << sizeof(bool)*(size+1) << endl;
      for (int m = 2; m <= sizeSquareRoot; m++) {
            if(!isComposite[m]) {
                  //cout << m << " " << endl;
                  //guardar(m);
                  for (int k = m * m; k <= size; k += m)
                        isComposite[k] = true;
            }
      }
      //cout << "---->>>>";
      for (int m = sizeSquareRoot; m <= size; m++)
            if (isComposite[m]==0)
            {
                  cout << m << " " << endl;
                  //guardar(m);
            }
      delete [] isComposite;
}
void criba2(ZZ num)
{
    int size=100000000;
    ZZ root=mySqrt(num);
    //cout << "the root is " << root << endl;
    bool *vec= new bool[conv<int>(num)+1];
    //cout << "the memset" << sizeof(bool)*(size+1) << endl;
    memset(vec,0,sizeof(bool)*(conv<int>(num)+1));
    for (int m = 2; m <= root; m++) {
        if (!vec[m]) {
            cout << m << " " << endl;
                  //guardar(m);
            for (int k = m * m; k <= num; k += m)
                vec[k]=true;
        }
    }
      //cout << "---->>>>";
    for (int m = conv<int>(root); m <= num; m++){
        if (!vec[m])
        {
            cout << m << " " << endl;
                  //guardar(m);
        }
    }
    delete [] vec;
}
/*
void criba(vector<ZZ> & vec)
{
    ZZ  first;
    for (size_t i = 0;i<vec.size(); i++)
    {   
        if((vec[i]*vec[i])<vec.size())
        {
            if(vec[i]>0)
            {
                first=vec[i];
                for (size_t j = 0; first < vec.size()+2; j++)
                {
                    //cout << "entra -->" << vec[i] <<"-->" <<i << "--->" <<first <<  endl;
                    first+=vec[i];
                    //first+=(i+2);
                    vec[conv<int>(first-2)]=0;

                } 
            }   
        }
        else
            break;
    }
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        if(vec[i]!=0)
        {
            cout << vec[i] << endl;
        }
    }
}
*/
void criba1024(ZZ n)
{
    cout << "hello";
    int size=10000000;
    bool **vec= new bool*[size];
    for (int i = 0; i < size; i++)
    {
        vec[i]=new bool[8];
    }
    memset(vec,0,sizeof(bool)*(size+1));
    //criba de erastotenes
    for (int m = 2; m <= root; m++) {
        if (!vec[m]) {
            cout << m << " " << endl;
                  //guardar(m);
            for (int k = m * m; k <= num; k += m)
                vec[k]=true;
        }
    }
      //cout << "---->>>>";
    for (int m = conv<int>(root); m <= num; m++){
        if (!vec[m])
        {
            cout << m << " " << endl;
                  //guardar(m);
        }
    }
    //liberar memoria
    for (int i = 0; i < size; i++)
    {
        delete []vec[i];
    }
    delete [] vec;
}
int main()
{
    ZZ cribaSize;
    //long long cribaSize;
    //cout << "input size criba" ; 
    cin >> cribaSize;
    
    //runEratosthenesSieve(cribaSize);
    //criba2(cribaSize);
    //criba(lista);
    //2342342342342242342423423423423422972492734923472349274294723942742943723492748234628346234823642873462374263428734623487234624782346234726427492374924723492472492342734293472492429347234927342934827;
    //23423423423422423424234234234234229724927349234723492742947239427429437234927482346283462348236428734623742634287346234872346247823462347264274923749247234924724923427342934724924293472349273429348274389272349234923472424732349274729472934274234723492347234927432394223472432274234724392472934274234243723492862347834628342634823462384263428374623482364823476324238434824623482364237842342342342342348263428346234826348234627834623847623487234627834623487263478234623472634278346234823462873462482364824326342342834234623402348240283402348234028340234823042834023482034283402348230448234028342034823490234234820242342834024382340234823
    //cout <<"the sqrt is " <<  sqrt(cribaSize) << endl;
    //criba2(cribaSize);
    //vector<bool> *v=new vector<bool>(conv<long >(cribaSize));

    //menset(v,0,sizeof(bool)*conv<bool>(cribaSize));
    //t1=clock();
    //runEratosthenesSieve(cribaSize);
    //t2=clock();
    //double time=(double(t2-t1)/CLOCKS_PER_SEC);
    //cout << "the time is " << time << endl;    
    t1=clock();
    criba2(cribaSize);
    t2=clock();
    double time=(double(t2-t1)/CLOCKS_PER_SEC);
    cout << "time" << time << endl;
    //criba1024(cribaSize);
}
