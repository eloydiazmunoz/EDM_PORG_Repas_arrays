#include <iostream>
#include <string>

using namespace std;

const int MAX_INVENTARI = 10;

int main() {
    // Declaració d'una matriu de cadenes anomenada 'inventari' amb una mida màxima de 10 elements.
    string inventari[MAX_INVENTARI];

    // Declaració de variables per al nombre d'elements a l'inventari i l'opció triada per l'usuari.
    int numElements = 0;
    int opcio;

    // Bucle principal que manté el programa en execució fins que l'usuari triï sortir (opció 0).
    while (true) {
        // Menú d'opcions per a l'usuari.
        cout << "1. Entrar objecte del joc" << endl;
        cout << "2. Eliminar objecte del joc" << endl;
        cout << "3. Entrar una quantitat determinada d'objectes" << endl;
        cout << "4. Buidar tot l'inventari" << endl;
        cout << "0. Sortir" << endl;

        // Sol·licitar a l'usuari que ingressi l'opció desitjada.
        cout << "Entra la teva opcio (0-4): ";
        cin >> opcio;

        // Utilització d'una estructura de control switch per gestionar les diferents opcions.
        switch (opcio) {
        case 1: {
            // Afegir un objecte a l'inventari si no està ple.
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
            // Eliminar un objecte de l'inventari si hi ha elements presents.
            if (numElements > 0) {
                cout << "Entra el nom de l'objecte que vols eliminar: ";
                string nomObjecte;
                cin >> nomObjecte;

                // Buscar l'objecte a l'inventari i eliminar-lo.
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
            // Afegir una quantitat específica d'objectes a l'inventari.
            int quantitat;
            cout << "Entra la quantitat d'objectes que vols afegir: ";
            cin >> quantitat;

            // Bucle per ingressar la quantitat especificada d'objectes.
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
            // Buidar completament l'inventari establint 'numElements' a 0.
            numElements = 0;
            cout << "L'inventari s'ha buidat." << endl;
            break;
        }
        case 0: {
            // Finalitzar el programa si l'usuari tria sortir.
            cout << "Adeu! Fi del programa." << endl;
            return 0;
        }
        default: {
            // Missatge en cas que l'usuari ingressi una opció no vàlida.
            cout << "Opcio no vàlida. Torna a intentar-ho." << endl;
        }
        }
    }

    return 0;
}
