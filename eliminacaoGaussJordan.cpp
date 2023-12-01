#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

void eliminacaoGaussJordan(double matriz[MAX_SIZE][MAX_SIZE + 1], int n) {
    for (int i = 0; i < n; i++) {
        int pivo = i;

        for (int j = i + 1; j < n; j++){
            if (fabs(matriz[j][i]) > fabs(matriz[pivo][i])){
                pivo = j;
            }
        }
            
        for (int k = 0; k <= n; k++) {
            double aux = matriz[i][k];
            matriz[i][k] = matriz[pivo][k];
            matriz[pivo][k] = aux;
        }

        double divisor = matriz[i][i];
        for (int j = 0; j <= n; j++){
            matriz[i][j] /= divisor;
        }

        for (int j = 0; j < n; j++){
            if (j != i) {
                double multiplier = matriz[j][i];
                for (int k = 0; k <= n; k++){
                    matriz[j][k] -= multiplier * matriz[i][k];
                }      
            }
        }
    }
}

int main() {
    int n;
    double matriz[MAX_SIZE][MAX_SIZE + 1];

    cout << "Insira o tamanho da matriz: ";
    cin >> n;

    cout << "Insira os elementos da matriz aumentada, linhas por linhas:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            cin >> matriz[i][j];
        }
    }

    eliminacaoGaussJordan(matriz, n);

    cout << "Solucao:\n";
    for (int i = 0; i < n; i++){
        cout << "x" << i + 1 << " = " << matriz[i][n] << endl;
    }
        
    return 0;
}
