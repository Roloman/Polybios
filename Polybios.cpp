// Polybios.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

string alfa_poly = " abcd....efghi.....jklmn.....ñopqr.....stuvw.....xyz";
string alfas = " abcdefghijklmnñopqrstuvwxyz";
string alfa = "a,b,c,d,e";

string Cifrar_Poly(string mensaje) {

    string cifrado;
    int a = mensaje.size();
    int n = 0;
    for (int i = 0; i < a; i++) {

        n = alfa_poly.find(mensaje[i]);
        if (n > 9) {
            
            cifrado += std::to_string(n);
        }
        else
        {
            cifrado += std::to_string(0);
            cifrado += std::to_string(n);
        }
    }
    return cifrado;
}

string Descifrar_Poly(string mensaje) {

    string descifrado;
    string temp;
    string cero = "0";
    int a = mensaje.size();
    int n = 0;
    for (int i = 0; i < a; i++) {

        temp += mensaje[i];
        if ( i % 2 != 0 ) {
            
            n = atoi(temp.c_str());
            descifrado += alfa_poly[n];
            temp = "";
        }
    }
    return descifrado;
}


string Reil_Fence(string mensaje, int clave) {

    int tam = mensaje.size();
    int a = clave + 1;
    int cont = 0;
    string cifrado;
    int i = 0;
    int j = 1;
    while (a > 0) {
        while (i < tam) {

            cifrado += mensaje[i];
            i = i + a;
        }
        a = a - 2;
        i = j;
        j++;
    }
    if (a == 0) {

        while (i < tam) {

            cifrado += mensaje[i];
            i = i + clave + 1;
        }
    }
    return cifrado;
}

string DesReil_Fence(string mensaje, int clave) {

    int tam = mensaje.size();
    int a = clave + 1;
    int cont = 0;
    string cifrado;
    int i = 0;
    int j = 1;
    while (a > 0) {
        while (i < tam) {

            cifrado += mensaje[i];
            i = i + a;
        }
        a = a - 2;
        i = j;
        j++;
    }
    if (a == 0) {

        while (i < tam) {

            cifrado += mensaje[i];
            i = i + clave + 1;
        }
    }
    return cifrado;
}

int main()
{
    //string a = "railfencecipher";
    string a = "hola manuel hola esteban no gracias soy alergico a los crustaceos";
    string b;
    int clave = 3;
    //a = Reil_Fence(a, clave);
    //cout << a << endl;
    //b = DesReil_Fence(a, clave);
    //cout << b << endl;
    b = Cifrar_Poly(a);
    string c;
    cout << b << endl;
    c = Descifrar_Poly(b);
    cout << c << endl;
    
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
