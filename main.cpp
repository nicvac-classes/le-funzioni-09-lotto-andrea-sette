#include <iostream>
#include <ctime>

using namespace std;


string toString (double);
int toInt (string);
double toDouble (string);
bool cercaNumero(int v[], int n, int numero);

int controllaVincita(int e[], int g[], int ndg, int nde);

void estrazioneNumeri(int v[], int n);

void gioca(int giocata[], int z);

int visualizzaMenu();

int main() {
    int scelta, n, z;
    bool trovato;
    int e[5];
    int g[5];

    do {
        scelta = visualizzaMenu();
        if (scelta == 1) {
            cout << "Quanti numeri vuoi giocare?" << endl;
            cin >> z;
            int giocata[z];

            gioca(giocata, z);
        }
        if (scelta == 2) {
            n = 5;
            estrazioneNumeri(e, n);
        }
        if (scelta == 3) {
            controlla(e, 5, g, n);
        }
    } while (scelta != 0);
    return 0;
}

bool cercaNumero(int v[], int n, int numero) {
    bool trovato;
    int i;

    trovato = false;
    i = 0;
    while (i < n - 1 && trovato) {
        if (numero == v[i]) {
            trovato = true;
        } else {
            trovato = false;
        }
        i = i + 1;
    }
    
    return trovato;
}

int controllaVincita(int e[], int g[], int ndg, int nde) {
    int i, numero, vittoria, j;

    vittoria = 0;
    i = 0;
    while (i < ndg - 1) {
        numero = g[i];
        if (cercaNumero(e, nde, numero)) {
            vittoria = vittoria + 1;
        }
        i = i + 1;
    }
    string c[5];

    j = 0;
    c[0] = "Estratto!";
    c[1] = "Ambo!!";
    c[2] = "Terna!!!";
    c[3] = "Quaterna!!!!";
    c[4] = "Quintina!!!!!";
    while (j - 1 != vittoria) {
        if (j == vittoria) {
            cout << c[j - 1] << endl;
        }
        j = j + 1;
    }
    
    return vittoria;
}

void estrazioneNumeri(int v[], int n) {
    int i;

    i = 0;
    while (i < n) {
        v[i] = 1 + rand() % 90;
        i = i + 1;
    }
    i = 0;
    cout << "I numeri sono:" << endl;
    while (i < n) {
        cout << v[i] << endl;
        i = i + 1;
    }
}

void gioca(int giocata[], int z) {
    int i;

    i = 0;
    while (i < z) {
        cout << "Che numero scegli?" << endl;
        cin >> giocata[i];
        i = i + 1;
    }
}

int visualizzaMenu() {
    int scelta;

    do {
        cout << "Menu di gioco: 1. Gioca al lotto; 2. Estrazione numeri del lotto; 3. Controlla vincita; 0. Esci" << endl;
        cin >> scelta;
    } while (scelta > 4 || scelta >= 4 && scelta != 0);
    
    return scelta;
}

