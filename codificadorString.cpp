
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    string str1, str2,str4,str3="";
    string archivoE,archivoS;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura

    cout<<"Ingrese una palabra: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,str1);
    cout<<"Ingrese el archivo donde esta el coso: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,archivoE);
    cout<<"Ingrese donde quiere que quede el archivo: ";
    //cin>>str1;                          //lee una cadena sin espacios

    getline(cin,archivoS);
    //lee una cadena con espacios

    try{
        fout.open("archivo3.txt");       //abre el archivo para escritura
        if(!fout.is_open()){
            throw '1';
        }
        fout<<str1;                     //escribe la palabra
        fout.close();                   //cierra el archivo

        fin.open(archivoE);        //abre el archivo para lectura
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
    cout<<"ingrese el metodo a utilizar"<<endl;
    cin>>eleccion;
    int n;
    cout<<"ingrese las particiones"<<endl;
    cin>>n;
    switch (eleccion) {
        case '2': {
        int tamano=str2.length();
        string temporal="";
        for(int i=0;i<tamano;i++){
            bitset<8> bs3(str2[i]);
            temporal=bs3.to_string();
            cout << "binary:  " << bs3 <<" letra  " <<str2[i]<<endl;
            str3+=temporal;
            temporal="";




        }
        cout<<str3;
        int tamCantidad=str3.length();

        string codificado,codificadoTotal="",total="";
        int j=0;
        if(tamCantidad%n>0){
            while (tamCantidad-n>0) {
                codificado=str3.substr(j,n);
                for(int l=0;l<n;l++){
                    if(l==0){
                        codificadoTotal=codificadoTotal+codificado[n-1];
                    }
                    else{
                        codificadoTotal=codificadoTotal+codificado[l-1];
                    }
                }
                tamCantidad-=n;
                j+=n;
                total+=codificadoTotal;
                codificadoTotal="";
            }
            codificado=str3.substr(j,tamCantidad%n);
            for(int l=0;l<tamCantidad%n;l++){
                if(l==0){
                    codificadoTotal=codificadoTotal+codificado[tamCantidad%n-1];
                }
                else{
                    codificadoTotal=codificadoTotal+codificado[l-1];
                }
            }
            total+=codificadoTotal;

        }
        else{

            while(tamCantidad>0){
                codificado=str3.substr(j,n);
                for(int l=0;l<n;l++){
                    if(l==0){
                        codificadoTotal=codificadoTotal+codificado[n-1];
                    }
                    else{
                        codificadoTotal=codificadoTotal+codificado[l-1];
                    }
                }
                tamCantidad-=n;
                j+=n;
                total+=codificadoTotal;
                codificadoTotal="";

            }
        }
        cout<<total;

        fout.open(archivoS);
        fout<<total;                     //escribe la palabra
        fout.close();
        cout<<"el archivo generado esta en "<<archivoS<<endl;
        break;

    };

    case '1': {
        int tamano=str2.length();
        string temporal="";
        for(int i=0;i<tamano;i++){
            bitset<8> bs3(str2[i]);
            temporal=bs3.to_string();
            cout << "binary:  " << bs3 <<" letra  " <<str2[i]<<endl;
            str3+=temporal;
            temporal="";


    }
        cout<<str3;
        int tamCantidad=str3.length();

        string codificado,codificadoTotal="",total="";
        string secuencia;
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
                        if(codificado[l]=='1'){
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
                codificadoTotal="";
                conta++;
                ceros=0;
                unos=0;

            }
            codificado=str3.substr(j,n);
            for(int l=0;l<n;l++){
                if(codificado[l]=='1'){
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
                        if(codificado[l]=='1'){
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
                                codificadoTotal+=secuencia[l];
                                dosbits++;

                            }

                        }
                    }
                    j+=n;

                }
                tamCantidad-=n;

                total+=codificadoTotal;
                codificadoTotal="";
                conta++;
                ceros=0;
                unos=0;

            }

        }
        fout.open(archivoS);
        fout<<total;                     //escribe la palabra
        fout.close();
         cout<<"el archivo generado esta en "<<str4<<endl;
        break;
   };
        default: cout << "Usted ha ingresado una opción incorrecta";
    } ;


    return 0;
}


