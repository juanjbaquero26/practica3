/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <time.h>
using namespace std;
void menu();
int parti=0;
string cadena2;
string tr;
void metodo1();
void metodo2();
ifstream fin;               //stream de entrada, lectura
ofstream fout;
char cadena3[15],cadena4[]={};
int main()

{

    int n=0;
    cout << "ingrese el tamaño de la cadena: "<<endl;
    cin >> n;
    char cadena1[n];
    cout << "Ingrese una cadena de caracteres" << endl ;
    cin >> cadena1;
    //cout << "la cadena ingresada fue:" << cadena1 << endl;

    int tamano = sizeof cadena1;
    //int tam = 8*tamano;
    string cadena2;
    //cout<<"el tamaño de la cadena es: " << tamano<<endl;
    for(int i=0; i<tamano ;i++){
        bitset<8> bin(cadena1[i]);
        string tr = bin.to_string();
        cout << "binario " << cadena1[i]<< ":" << bin<< endl;
        cadena2+=tr;

    }
cout <<"el binario inicial es: "<< cadena2<< endl;



/*for(int i=0;i<tam;i++){
    char tan[32]={""};
tan= tan+ cadena2[i];}*/
/*
 int parti = 0;
cout << "ingrese el numero de particiones"<<endl;
cin >> parti ;
//srand(time(NULL));

menu();
cout << "ingrese que metodo le gustaria usar: "<<endl ;
int opcion;
cin >> opcion ;
switch(opcion){
case 1:
    //metodo1();
    try {
        fout.open("archivo3.txt");
        if(!fout.is_open()){
                    throw '1';
                }
                fout<<cadena2;                     //escribe la palabra
                fout.close();
                fin.open("archivo3.txt");        //abre el archivo para lectura
                        if(!fin.is_open()){
                            throw '2';
                        }

                        int i=0;

                        //fin.getline(cadena4,15);           //lee una linea y la almacena en cadena3

                        fin.seekg(0);                   //vuelve al principio del archivo

                        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                            char temp=fin.get();
                            if(fin.good()){
                                cadena3[i]=temp;     //Asigna cada caracter leido a la cadena de caracteres
                            }
                            i++;
                        }
                        fin.close();
                        cout << "cadena 3: " << cadena3<<endl;
                        char cadenatemporal[]={};
                        for(int i=0;i<parti;i++)  {
                          cadenatemporal[parti ] += cadena3[i];
                          cout << cadenatemporal<<endl;
                        }
                        cout << cadenatemporal<<endl;
    }  catch
        (...){
                cout<<"Error no definido\n";
            }

    break;
case 2:
    metodo2();
    break;
default:
    cout << "ese metodo no existe intente otro" << endl;

}

return 0;
}*//*
void menu(){
    cout << "LAS OPCIONES DE CODIFICACION SON" << endl;
    cout << "____________"<<endl;
    cout << "METODO 1: Invertir numeros" << endl;
    cout << "METODO 2: Desplazamiento" << endl;
}*/
//void metodo1(){
  /*  try {
        fout.open("archivo3.txt");
        if(!fout.is_open()){
                    throw '1';
                }
                fout<<cadena2;                     //escribe la palabra
                fout.close();
                fin.open("archivo3.txt");        //abre el archivo para lectura
                        if(!fin.is_open()){
                            throw '2';
                        }

                        int i=0;

                        fin.getline(cadena4,15);           //lee una linea y la almacena en cadena3

                        fin.seekg(0);                   //vuelve al principio del archivo

                        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                            char temp=fin.get();
                            if(fin.good()){
                                cadena3[i]=temp;     //Asigna cada caracter leido a la cadena de caracteres
                            }
                            i++;
                        }
                        fin.close();
                        cout << cadena3<<endl;
                        cout << cadena4<<endl;
                        cout << cadena2 << endl;

    }  catch
        (...){
                cout<<"Error no definido\n";
            }*/



/*
}
void metodo2(){
  cout<<"met2"<<endl;
}
*/

