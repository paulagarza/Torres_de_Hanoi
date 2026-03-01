/* Código básico 
#include <iostream>
using namespace std;

// Función recursiva para resolver Torres de Hanoi 
void hanoi(int n, char origen, char auxiliar, char destino) {
    // Caso base
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }

    // Paso 1. Mover n-1 discos al auxiliar
    hanoi(n-1, origen, destino, auxiliar);
    
    // Paso 2. Mover el disco grande al destino 
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;

    // Paso 3. Mover los n-1 discos al destino 
    hanoi(n-1, auxiliar, origen, destino);
}


int main() {
    int n = 5;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

*/

/* Código más visual */
#include <iostream>
#include <vector>
using namespace std;

// Mostrar estado actual de las torres
void mostrarTorres(vector<int>& A, vector<int>& B, vector<int>& C) {
    cout << "\nEstado actual:\n";

    cout << "A: ";
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "B: ";
    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;

    cout << "C: ";
    for (int i = 0; i < C.size(); i++)
        cout << C[i] << " ";
    cout << endl;
}

// Movimiento real de disco
void moverDisco(vector<int>& origen, vector<int>& destino) {
    int disco = origen.back();
    origen.pop_back();
    destino.push_back(disco);
}

// Función recursiva
void hanoi(int n,
           vector<int>& origen,
           vector<int>& auxiliar,
           vector<int>& destino,
           vector<int>& A,
           vector<int>& B,
           vector<int>& C) {

    if (n == 1) {
        moverDisco(origen, destino);
        mostrarTorres(A, B, C);
        return;
    }

    hanoi(n - 1, origen, destino, auxiliar, A, B, C);

    moverDisco(origen, destino);
    mostrarTorres(A, B, C);

    hanoi(n - 1, auxiliar, origen, destino, A, B, C);
}

int main() {
    int n = 5;
    /*
    cout << "Introduce numero de discos: ";
    cin >> n;
    */

    vector<int> A, B, C;

    // Inicializamos torre A (del mayor al menor)
    for (int i = n; i >= 1; i--)
        A.push_back(i);

    mostrarTorres(A, B, C);

    hanoi(n, A, B, C, A, B, C);

    return 0;
}