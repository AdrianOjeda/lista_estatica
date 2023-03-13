#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class ListaEstatica {
private:
    int elementos[MAX_SIZE];
    int tamano;
public:
    ListaEstatica() {
        tamano = 0;
    }

    bool estaVacia() {
        return tamano == 0;
    }

    bool estaLlena() {
        return tamano == MAX_SIZE;
    }

    void insertar(int valor, int posicion) {
        if (estaLlena()) {
            cout << "La lista esta llena. No se puede insertar más elementos." << endl;
            return;
        }
        if (posicion < 0 || posicion > tamano) {
            cout << "Posicion invalida. No se puede insertar el elemento." << endl;
            return;
        }
        for (int i = tamano; i > posicion; i--) {
            elementos[i] = elementos[i - 1];
        }
        elementos[posicion] = valor;
        tamano++;
        cout << "Elemento insertado correctamente." << endl;
    }

    void eliminar(int posicion) {
        if (estaVacia()) {
            cout << "La lista esta vacia. No se puede eliminar ningún elemento." << endl;
            return;
        }
        if (posicion < 0 || posicion >= tamano) {
            cout << "Posicion invalida. No se puede eliminar el elemento." << endl;
            return;
        }
        for (int i = posicion; i < tamano - 1; i++) {
            elementos[i] = elementos[i + 1];
        }
        tamano--;
        cout << "Elemento eliminado correctamente." << endl;
    }

    int obtenerPrimero() {
        if (estaVacia()) {
            cout << "La lista esta vacia. No se puede obtener el primer elemento." << endl;
            return -1;
        }
        return elementos[0];
    }

    int obtenerUltimo() {
        if (estaVacia()) {
            cout << "La lista esta vacia. No se puede obtener el último elemento." << endl;
            return -1;
        }
        return elementos[tamano - 1];
    }

    void imprimir() {
        if (estaVacia()) {
            cout << "La lista esta vacia. No hay elementos para imprimir." << endl;
            return;
        }
        cout << "Elementos de la lista: ";
        for (int i = 0; i < tamano; i++) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }

    void anular() {
        tamano = 0;
        cout << "La lista ha sido anulada. Todos los elementos han sido eliminados." << endl;
    }
};

int main() {
    ListaEstatica lista;
    int opcion, valor, posicion;
    char opt;

    do {
        cout << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Verificar si la lista esta vacia" << endl;
        cout << "2. Verificar si la lista esta llena" << endl;
        cout << "3. Insertar un elemento en la lista" << endl;
        cout << "4. Eliminar un elemento de la lista" << endl;
        cout << "5. Obtener el primer elemento de la lista" << endl;
        cout << "6. Obtener el último elemento de la lista" << endl;
        cout << "7. Imprimir la lista" << endl;
        cout << "8. Anular la lista" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1: {
            cout << "*** Vacia ***" << endl;
            if (lista.estaVacia()) {
                cout << "La lista esta vacia!!" << endl;
            }
            break;

        }case 2: {
            cout << "*** Llena ***" << endl;
            if (lista.estaLlena()) {

                cout << "La lista esta llena!!" << endl;
            }
            break;
        }case 3: {
            cout << "*** Insertar ***" << endl;
            cout << "Ingresa la posicion: ";
            cin >> posicion;
            cout << "Ingresa el valor: ";
            cin >> valor;
            lista.insertar(valor, posicion);
            break;
        }case 4: {
            cout << "*** Eliminar elemento ***" << endl;
            cout << "Ingrese la posicion: ";
            cin >> posicion;
            lista.eliminar(posicion);
            break;
        }case 5: {
            cout << "*** Primer elemento ***" << endl;
            cout << "El primer elemento es: " << lista.obtenerPrimero() << endl;
            break;
        }case 6: {
            cout << "*** Ultimo elemento ***" << endl;
            cout << "El ultimo elemento es: " << lista.obtenerUltimo() << endl;
            break;
        }case 7: {
            cout << "*** Imprimir ***" << endl;
            lista.imprimir();
            break;
        }case 8: {
            cout << "*** Anular lista ***" << endl;
            lista.anular();
            break;
        }default: {
            cout << "Ingresa una opcion valida!" << endl;
        }
        }


         cout << "Desea continuar? Y/N: ";
         cin >> opt;
        }while (opt == 'Y' or opt == 'y');

    }
