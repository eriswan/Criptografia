#include <iostream>
#include <climits>
#include <string>

using namespace std;

string alfabeto_original = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alfabeto_criptogr = "bcdefghijklmnopqrstuvwxyza1234567890BCDEFGHIJKLMNOPQRSTUVWXYZA";

string criptografar(string original) {
    string texto_criptografado;
    for (char letra : original) {
        bool encontrou_letra_no_alfabeto = false;
        for (int i = 0; i < alfabeto_original.size(); i++) {
            if (alfabeto_original[i] == letra) {
                texto_criptografado = texto_criptografado + alfabeto_criptogr[i];
                encontrou_letra_no_alfabeto = true;
            }
        }
        if (!encontrou_letra_no_alfabeto) {
            texto_criptografado = texto_criptografado + letra;
        }
    }
    return texto_criptografado;
}

string descriptografar(string criptografado) {
    string texto_descriptografado;
    for (char letra : criptografado) {
        bool encontrou_letra_no_alfabeto = false;
        for (int i = 0; i < alfabeto_criptogr.size(); i++) {
            if (alfabeto_criptogr[i] == letra) {
                texto_descriptografado = texto_descriptografado + alfabeto_original[i];
                encontrou_letra_no_alfabeto = true;
            }
        }
        if (!encontrou_letra_no_alfabeto){
            texto_descriptografado = texto_descriptografado + letra;
        }
    }
    return texto_descriptografado;
}

int main () {

    int menu_option;
    string texto_original;
    string texto_criptografado;

    while (true) {

        cout << "Digite uma opção" << endl 
            << "1 - Criptografar" << endl 
            << "2 - Descriptografar" << endl
            << "9 - Fechar Programa" << endl;

        cin >> menu_option;

        switch (menu_option) {
            case 1: 
                cout << "Criptografar, digite o texto" << endl; 
                cin >> texto_original;
                cout << "O texto que voce digitou foi: " << texto_original << endl;
                texto_criptografado = criptografar(texto_original);
                cout << "O texto criptografado é: " << texto_criptografado << endl;
                break;
            case 2:
                cout << "Descriptografar, digite o texto criptografado" << endl;
                cin >> texto_criptografado;
                cout << "O texto que voce digitou foi: " << texto_criptografado << endl;
                texto_original = descriptografar(texto_criptografado);
                cout << "O texto descriptografado e: " << texto_original << endl;
                break;
            case 9:
                return 0;
            default:
                cout << "Invalido" << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
        }

        cout << endl;
    }

}
