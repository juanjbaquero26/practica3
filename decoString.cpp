
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <math.h>

using namespace std;

int main()
{
    string str1, str2,str3="";
    string archivoE,archivoS;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura

    cout<<"Ingrese donde esta el archivo: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,archivoE);
    cout<<"Ingrese donde poner el archivo: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,archivoS);      //l//lee una cadena con espacios

    try{
        //fout.open("archivo3.txt");       //abre el archivo para escritura
        //if(!fout.is_open()){
        //  throw '1';
        //
        //fout<<str1;                     //escribe la palabra
        //fout.close();                   //cierra el archivo

        fin.open(archivoE);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }



        //getline(fin,str3);           //lee una linea y la almacena en el string str3

       // fin.seekg(0);                 //vuelve al principio del archivo

        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                str3 +=temp;     //Asigna cada caracter leido a la cadena de caracteres
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
    cout<<"ingrese el metodo a decodificar"<<endl;
    cin>>eleccion;
    int n;
    cout<<"ingrese las particiones"<<endl;
    cin>>n;
    switch (eleccion) {
        case '2': {
        cout<<str3;
        int tamCantidad=str3.length();

        string codificado,codificadoTotal="",total="",letra="",letras="";
        int j=0;
        if(tamCantidad%n>0){
            while (tamCantidad-n>0) {
                codificado=str3.substr(j,n);
                for(int l=0;l<n;l++){
                    if(l==n-1){
                        codificadoTotal=codificadoTotal+codificado[l-l];
                    }
                    else{
                        codificadoTotal=codificadoTotal+codificado[l+1];
                    }
                }
                tamCantidad-=n;
                j+=n;
                total+=codificadoTotal;
                codificadoTotal="";
            }
            codificado=str3.substr(j,tamCantidad%n);
            for(int l=0;l<tamCantidad%n;l++){
                if(l==n-1){
                    codificadoTotal=codificadoTotal+codificado[tamCantidad%n-tamCantidad%n];
                }
                else{
                    codificadoTotal=codificadoTotal+codificado[l+1];
                }
            }
            total+=codificadoTotal;

        }
        else{

            while(tamCantidad>0){
                codificado=str3.substr(j,n);
                for(int l=0;l<n;l++){
                    if(l==n-1){
                        codificadoTotal=codificadoTotal+codificado[l-l];
                    }
                    else{
                        codificadoTotal=codificadoTotal+codificado[l+1];
                    }
                }
                tamCantidad-=n;
                j+=n;
                total+=codificadoTotal;
                codificadoTotal="";

            }
        }
        cout<<total;

        int pos=0;
        int tama=total.length();

        double totalSuma=0;

        while (tama-8>=0) {
            letra=total.substr(pos,8);
            for(int j=0;j<8;j++){
                if(letra[j]=='1'){
                     totalSuma=totalSuma+pow(2,8-j-1);
                }

            }
            letras+=totalSuma;
            totalSuma=0;
            tama=tama-8;
            pos+=8;

        }
        cout<<letras;
        fout.open(archivoS);
        fout<<letras;                     //escribe la palabra
        fout.close();
        break;

    };

    case '1': {

        cout<<str3;
        int tamCantidad=str3.length();

        string codificado,codificadoTotal="",total="";
        string secuencia;
        string recorre=codificadoTotal,letras,letra;
        int j=0;
        int conta=1,unos=0,ceros=0;
        if(tamCantidad%n>0){
            while(tamCantidad-n>0){
                codificado=str3.substr(j,n);

                if(conta==1){
                    for(int l=0;l<n;l++){
                        if(codificado[l]=='1'){
                            codificadoTotal+='0';
                        }
                        else{
                            codificadoTotal+='1';
                        }
                    }

                }
                else{
                    codificado=str3.substr(j,n);
                    for(int l=0;l<n;l++){
                        if(recorre[l]=='1'){
                            unos++;
                        }
                        else{
                            ceros++;
                        }

                    }
                    secuencia=str3.substr(j+n,n);
                    if(unos==ceros){
                        for(int l=0;l<n;l++){
                            if(secuencia[l]=='1'){
                                codificadoTotal+='0';
                            }
                            else{
                                codificadoTotal+='1';
                            }
                        }

                    }
                    else if(ceros>unos){
                        int dosbits=1;
                        for(int l=0;l<n;l++){
                            if(dosbits==2){
                                if(secuencia[l]=='1'){
                                    codificadoTotal+='0';
                                }
                                else if(secuencia[l]=='0'){
                                    codificadoTotal+='1';
                                }
                                dosbits=1;
                            }
                            else{
                                codificadoTotal+=secuencia[l];
                                dosbits++;
                            }


                        }
                    }
                    else if(unos>ceros){

                        int dosbits=1;
                        for(int l=0;l<n;l++){
                            if(dosbits==3){
                                if(secuencia[l]=='1'){
                                    codificadoTotal+='0';

                                }
                                else{
                                    codificadoTotal+='1';
                                }
                                dosbits=1;
                            }
                            else{
                                dosbits++;
                                codificadoTotal+=secuencia[l];
                            }

                        }
                   }


                    j+=n;

                }
                tamCantidad-=n;
                recorre=codificadoTotal;
                total+=codificadoTotal;
                codificadoTotal="";
                conta++;
                ceros=0;
                unos=0;

            }
            codificado=str3.substr(j,n);
            for(int l=0;l<n;l++){
                if(recorre[l]=='1'){
                    unos++;
                }
                else{
                    ceros++;
                }

            }
            secuencia=str3.substr(j+n,tamCantidad%n);
            if(unos==ceros){
                for(int l=0;l<tamCantidad%n;l++){
                    if(secuencia[l]=='1'){
                        codificadoTotal+='0';
                    }
                    else{
                        codificadoTotal+='1';
                    }
                }

            }
            else if(ceros>unos){
                int dosbits=1;
                for(int l=0;l<tamCantidad%n;l++){
                    if(dosbits==2){
                        if(secuencia[l]=='1'){
                            codificadoTotal+='0';
                        }
                        else{
                            codificadoTotal+='1';
                        }
                        dosbits=1;
                    }
                    else{
                        codificadoTotal+=secuencia[l];
                        dosbits++;
                    }


                }

            }
            else if(unos>ceros){

                int dosbits=1;
                for(int l=0;l<tamCantidad%n;l++){
                    if(dosbits==3){
                        if(secuencia[l]=='1'){
                            codificadoTotal+='0';
                        }
                        else{
                            codificadoTotal+='1';
                        }
                        dosbits=1;
                    }
                    else{
                        dosbits++;
                        codificadoTotal+=secuencia[l];
                    }

                }


            }
            total+=codificadoTotal;
        }
        else{
            while(tamCantidad>0){
                codificado=str3.substr(j,n);

                if(conta==1){
                    for(int l=0;l<n;l++){
                        if(codificado[l]=='1'){
                            codificadoTotal+='0';
                        }
                        else{
                            codificadoTotal+='1';
                        }
                    }


                }
                else{
                    codificado=str3.substr(j,n);
                    for(int l=0;l<n;l++){
                        if(recorre[l]=='1'){
                            unos++;
                        }
                        else{
                            ceros++;
                        }

                    }
                    secuencia=str3.substr(j+n,n);
                    if(unos==ceros){
                        for(int l=0;l<n;l++){
                            if(secuencia[l]=='1'){
                                codificadoTotal+='0';
                            }
                            else{
                                codificadoTotal+='1';
                            }
                        }

                    }
                    else if(ceros>unos){
                        int dosbits=1;
                        for(int l=0;l<n;l++){
                            if(dosbits==2){
                                if(secuencia[l]=='1'){
                                    codificadoTotal+='0';
                                }
                                else if(secuencia[l]=='0'){
                                    codificadoTotal+='1';
                                }
                                dosbits=1;
                            }
                            else{
                                codificadoTotal+=secuencia[l];
                                dosbits++;
                            }


                        }
                    }
                    else if(unos>ceros){

                        int dosbits=1;
                        for(int l=0;l<n;l++){
                            if(dosbits==3){
                                if(secuencia[l]=='1'){
                                    codificadoTotal+='0';

                                }
                                else{
                                    codificadoTotal+='1';
                                }
                                dosbits=1;
                            }
                            else{
                                dosbits++;
                                codificadoTotal+=secuencia[l];
                            }

                        }
                   }


                    j+=n;

                }
                tamCantidad-=n;

                total+=codificadoTotal;
                recorre=codificadoTotal;
                codificadoTotal="";
                conta++;
                ceros=0;
                unos=0;

            }


        }
        int pos=0;
        int tama=total.length();

        double totalSuma=0;

        while (tama-8>=0) {
            letra=total.substr(pos,8);
            for(int j=0;j<8;j++){
                if(letra[j]=='1'){
                     totalSuma=totalSuma+pow(2,8-j-1);
                }

            }
            letras+=totalSuma;
            totalSuma=0;
            tama=tama-8;
            pos+=8;

        }
        cout<<letras;
        fout.open(archivoS);
        fout<<letras;                     //escribe la palabra
        fout.close();
        cout<<"se guardo en el archivo "<<archivoS<<endl;
        break;

    }
    default: cout << "Usted ha ingresado una opción incorrecta";
    } ;


    return 0;
}

