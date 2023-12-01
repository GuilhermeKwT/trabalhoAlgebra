#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int la, lb, ca, cb;
    cout << "Digite o numero de linhas da matriz A: ";
    cin >> la;
    cout << "Digite o numero de colunas da matriz A: ";
    cin >> ca;
    cout << "Digite o numero de linhas da matriz B: ";
    cin >> lb;
    while (lb != ca){
        cout << "O numero de linhas da segunda matriz deve ser igual ao numero de colunas da primeira" << endl;
        cin >> lb;
    }
    cout << "Digite o numero de colunas da matriz B: ";
    cin >> cb;
    double matrizA[la][ca], matrizB[lb][cb];

    cout << "Digite os elementos da primeira matriz: " << endl;
    for(int i=0; i<la; i++){
        for(int j=0; j<ca; j++){
            cin >> matrizA[i][j];
        }
    }

    cout << "Digite os elementos da segunda matriz:" << endl;
    for(int i=0; i<lb; i++){
        for(int j=0; j<cb; j++){
            cin >> matrizB[i][j];
        }
    }

    float matrizFinal[la][cb];
    for(int i=0; i<la; i++){
        for(int j=0; j<cb; j++){
            double somaMult=0;
            for(int k=0; k<ca; k++){
                somaMult = somaMult + (matrizA[i][k] * matrizB[k][j]);
            }
            matrizFinal[i][j] = somaMult;
        }
    }

    for(int i=0; i<la; i++){
        for(int j=0; j<cb; j++){
            cout << setw(5) << matrizFinal[i][j] << " ";
        }
        cout << endl;
    }

}