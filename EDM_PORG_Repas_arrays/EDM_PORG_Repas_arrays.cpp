#include <iostream>
#include <string>

using namespace std;

const int MAX_INVENTARI = 10;

int main() {
    string inventari[MAX_INVENTARI];
    int numElements = 0;
    int opcio;

    while (true) {
        cout << "1. Entrar objecte del joc" << endl;
        cout << "2. Eliminar objecte del joc" << endl;
        cout << "3. Entrar una quantitat determinada d'objectes" << endl;
        cout << "4. Buidar tot l'inventari" << endl;
        cout << "0. Sortir" << endl;

        cout << "Entra la teva opcio (0-4): ";
        cin >> opcio;

        switch (opcio) {
        case 1: {
            if (numElements < MAX_INVENTARI) {
                cout << "Entra el nom de l'objecte: ";
                cin >> inventari[numElements];
                numElements++;
                cout << "Objecte afegit a l'inventari." << endl;
            }
            else {
                cout << "L'inventari està ple. No es pot afegir més objectes." << endl;
            }
            break;
        }
        case 2: {
            if (numElements > 0) {
                cout << "Entra el nom de l'objecte que vols eliminar: ";
                string nomObjecte;
                cin >> nomObjecte;

                for (int i = 0; i < numElements; i++) {
                    if (inventari[i] == nomObjecte) {
                        for (int j = i; j < numElements - 1; j++) {
                            inventari[j] = inventari[j + 1];
                        }
                        numElements--;
                        cout << "Objecte eliminat de l'inventari." << endl;
                        break;
                    }
                }
            }
            else {
                cout << "L'inventari està buit. No es pot eliminar cap objecte." << endl;
            }
            break;
        }
        case 3: {
            int quantitat;
            cout << "Entra la quantitat d'objectes que vols afegir: ";
            cin >> quantitat;

            for (int i = 0; i < quantitat; i++) {
                if (numElements < MAX_INVENTARI) {
                    cout << "Entra el nom de l'objecte: ";
                    cin >> inventari[numElements];
                    numElements++;
                    cout << "Objecte afegit a l'inventari." << endl;
                }
                else {
                    cout << "L'inventari està ple. No es pot afegir més objectes." << endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            numElements = 0;
            cout << "L'inventari s'ha buidat." << endl;
            break;
        }
        case 0: {
            cout << "Adeu! Fi del programa." << endl;
            return 0;
        }
        default: {
            cout << "Opcio no vàlida. Torna a intentar-ho." << endl;
        }
        }
    }

    return 0;
}
