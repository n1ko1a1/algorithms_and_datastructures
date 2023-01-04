#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char ABC[50] = { 'a','b','c','d','e','f','g','h','i','j','k','l',
                    'm','n','o','p','q','r','s','t','u','v','w','x','y','z',' ' };
    // Sozdali massiv s dostupnymi dlya shifrovki znacheniyami
    char msg[1000]; // Massiv dlya hraneniya soobshcheniya pol'zovatelya
    int shift; // Hranit chislo, na kotoroe nuzhno sdvinut' soobshchenie
    int index;
    int j = 0;
VVOD:
    cout << "Vvedite soobshchenie, kotoroe hotite zakodirovat': " << endl;
    cout << "Na vvod prinimayutsya strochnye latinskiye bukvy" << endl;
    cout << endl;
    cin.get(msg, 1000); //Vvodim v massiv msg pol'zovatel'skoe soobshchenie
SDVIG:
    cout << "Vvedite sdvig dlya shifrovki: ";   // Pol'zovatel' vvodit sdvig dlya shifra 
    cin >> shift;
    char choise;
SHIFRDESHIFR:
    cout << "Esli hotite zashifrovat' frazu - vvedite 'e', esli deshifrovat' - vvedite 'd': " << endl; // Pol'zovatel' vybiraet zashifrovat' ili deshifrovat' soobshchenie
    cin >> choise;
    if (choise == 'e') {  // Srabotaet, esli pol'zovatel' vybral zashifrovat' soobshchenie

        for (int i = 0; i < strlen(msg); i++) {
            if (msg[i] != ' ') {

                while (msg[i] != ABC[j]) {
                    j++;
                }
                index = j + shift;
                if (index > 35) {
                    index = (index - 35) - 1;
                }
                msg[i] = ABC[index];
                j = 0;
            }
            else {
                msg[i] = ' ';
            }

        }
        cout << msg << endl;
    }
    else if (choise == 'd') {  // Srabotaet, esli pol'zovatel' vybral deshifrovat' soobshchenie
        for (int i = 0; i < strlen(msg); i++) {
            if (msg[i] != ' ') {
                while (msg[i] != ABC[j]) {
                    j++;
                }
                index = j - shift;
                msg[i] = ABC[index];
                j = 0;
            }
            else {
                msg[i] = ' ';
            }
        }
        cout << msg << endl;
    }
    else {
        cout << "Nuzhno vvesti ili 'e' ili 'd'!" << endl;
        goto SHIFRDESHIFR;
    }

}