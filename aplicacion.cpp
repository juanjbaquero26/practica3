/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    string str1, str2,str3="";
    ifstream fin,fin2;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura

   cout<<"Ingrese una palabra: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,str1);      //lee una cadena con espacios

    try{
        fout.open("sudo.txt");       //abre el archivo para escritura
        if(!fout.is_open()){
            throw '1';
        }
        fout<<str1;                     //escribe la palabra
        fout.close();                   //cierra el archivo

        fin.open("sudo.txt");        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }



        //getline(fin,str3);           //lee una linea y la almacena en el string str3

       // fin.seekg(0);                 //vuelve al principio del archivo

        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                str2 +=temp;     //Asigna cada caracter leido a la cadena de caracteres
            }
        }
        fin.close();                //Cierra el archivo de lectura.


    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
    char eleccion;
    cout<<"ingrese 1 para admin 2 para usuario"<<endl;
    cin>>eleccion;
    switch (eleccion) {
    case '1':{
      int metodo;
      cout<<"validando contraseña"<<endl;
      cout<<"desea registrar usuarios 1 si 2 no"<<endl;
      cin>>metodo;
      if(metodo==1){
          fin2.open("registro.txt");
          while(fin2.good()){              //lee caracter a caracter hasta el fin del archivo
              char temp=fin2.get();
              if(fin2.good()){
                  str2 +=temp;     //Asigna cada caracter leido a la cadena de caracteres
              }
          }
          fin2.close();

      }
    }

    }


    return 0;
}


*/
