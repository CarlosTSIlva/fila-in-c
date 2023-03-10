#include <iostream>

using namespace std;

struct NoFila {
    int numero;
    NoFila* proximo;
};

class Fila {
    private:
        NoFila* primeiro;
        NoFila* ultimo; 
    public:
        Fila() { 
            primeiro = NULL;
            ultimo = NULL;
        }

        void inserir(int value) {
            NoFila* newFila = new NoFila;
            newFila->numero = value;
            newFila->proximo = NULL;
            if (primeiro == NULL) {
                primeiro = newFila;
                ultimo = newFila;
            } else {
                ultimo->proximo = newFila;
                ultimo = newFila;
            }
        }

        void remover() {
            if (primeiro == NULL) {
                cout << "A fila está vazia!" << endl;
            } else {
                NoFila* temporario = primeiro;
                primeiro = primeiro->proximo;
                delete temporario;
            }
        }

        void mostrarFila() {
            if (primeiro == NULL) {
                cout << "A fila está vazia!" << endl;
            } else {
                NoFila* temporario = primeiro;
                while (temporario != NULL) {
                    cout << temporario->numero << " ";
                    temporario = temporario->proximo;
                }
                cout << endl;
            }
        }
};

int main() {
    Fila q;
    q.inserir(10);
    q.inserir(20);
    q.inserir(30);
    q.inserir(40);
    q.mostrarFila();
    q.remover();
    q.mostrarFila();
    return 0;
}
