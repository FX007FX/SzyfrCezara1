#include <iostream>
#include <fstream>

using namespace std;

string zaszyfruj(int k, string slowo);

int main() {

    int k;
    cout << "Podaj k:  ";
    cin >> k;

    ifstream odczyt("dane_cezara_1.txt");
    ofstream zapis("wyniki_cezara_1.txt");

    if (!odczyt || !zapis) {
        cerr << "Blad systemu plikow" << endl;
        return 1;
    }

    while (!odczyt.eof()) {
        string slowo;
        odczyt >> slowo;
        slowo = zaszyfruj(k, slowo);
        zapis << slowo << endl;
    }

    odczyt.close();
    zapis.close();

    return 0;
}

string zaszyfruj(int k, string slowo) {
    int kmod = k % 26;
    char* tmp = (char*)slowo.c_str();

    for (int i = 0; i < slowo.length(); i++) {
        char a = tmp[i];
        a += kmod;

        if (a > 90) {
            a -= 26;
        }

        tmp[i] = a;
    }

    return string(tmp);
}