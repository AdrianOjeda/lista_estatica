#include <iostream>
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class ListaEstatica {
private:
    int tamano;
    
public:
    int elementos[MAX_SIZE];
    bool isSorted = false;
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
    void busquedaLineal(int elemento) {
        bool bandera = false;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (elementos[i] == elemento) {
                bandera = true;
                cout << "El elemento se ecnuentra en la posicion: " << i;
            }
        }if (bandera == false) {
            cout << "El elemento no se encuentra en la lista";
        }
        
    }
    int busquedaBinaria( int elemento) {
        int left = 0;
        int right = 10 - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (elementos[mid] == elemento) {
                return mid;
            }
            else if (elementos[mid] < elemento) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1; //elemento no encontrado
    }
    void bubbleSort() {
        for (int step = 0; step < MAX_SIZE; ++step) {

            
            for (int i = 0; i < MAX_SIZE - step; ++i) {

                
                if (elementos[i] > elementos[i + 1]) {

                    
                    int temp = elementos[i];
                    elementos[i] = elementos[i + 1];
                    elementos[i + 1] = temp;
                }
            }
        }
        cout << "Lista ordenada con exito!" << endl;
        isSorted = true;
    }void insertionSort() {
        int aux;
        for (int i = 1; i < MAX_SIZE; i++) {
            aux = elementos[i];
            int j;
            for (j = i - 1; j >= 0 && aux < elementos[j]; j--) {
                elementos[j + 1] = elementos[j];
            }
            elementos[j + 1] = aux;
            cout << endl;
            
        }
        cout << "Lista ordenada con exito!" << endl;
        isSorted = true;
    }void selectionSort() {
        int aux;
        int position;

        cout << endl;
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << elementos[i] << " ";
        }
        for (int i = 0; i < MAX_SIZE; i++) {
            position = i;
            for (int j = i + 1; j < MAX_SIZE; j++) {
                if (elementos[position] > elementos[j]) {
                    position = j;

                }


            }

            aux = elementos[i];
            elementos[i] = elementos[position];
            elementos[position] = aux;
        }
        cout << "Lista ordenada con exito!" << endl;
        isSorted = true;
    }void shellSort() {

        for (int interval = MAX_SIZE / 2; interval > 0; interval /= 2) {
            for (int i = interval; i < MAX_SIZE; i += 1) {
                int temp = elementos[i];
                int j;
                for (j = i; j >= interval && elementos[j - interval] > temp; j -= interval) {
                    elementos[j] = elementos[j - interval];
                }
                elementos[j] = temp;
            }
        }


        cout << "Lista ordenada con exito!" << endl;
        isSorted = true;
    }void merge(int elementos[], int p, int q, int r) {

        
        int n1 = q - p + 1;
        int n2 = r - q;

        int* L = new int[n1];
        int* M = new int[n2];


        for (int i = 0; i < n1; i++)
            L[i] = elementos[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = elementos[q + 1 + j];

        
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                elementos[k] = L[i];
                i++;
            }
            else {
                elementos[k] = M[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            elementos[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            elementos[k] = M[j];
            j++;
            k++;
        }
    }void mergeSort(int elementos[], int l, int r) {
        if (l < r) {
            
            int m = l + (r - l) / 2;

            mergeSort(elementos, l, m);
            mergeSort(elementos, m + 1, r);

           
            merge(elementos, l, m, r);
        }
        
        isSorted = true;
    }
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    int partition(int elementos[], int low, int high) {

        
        int pivot = elementos[high];

       
        int i = (low - 1);

        
        for (int j = low; j < high; j++) {
            if (elementos[j] <= pivot) {

                i++;

                swap(&elementos[i], &elementos[j]);
            }
        }

        
        swap(&elementos[i + 1], &elementos[high]);

        return (i + 1);
    }

    void quickSort(int elementos[], int low, int high) {
        if (low < high) {

            
            int pi = partition(elementos, low, high);

            
            quickSort(elementos, low, pi - 1);

            
            quickSort(elementos, pi + 1, high);
        }


        isSorted = true;
    }
};

int main() {
    ListaEstatica lista;
    int opcion, valor, posicion;
    char opt;
    for (int i = 0; i < 15; i++) {
        lista.insertar(rand(), i);
    }
    do {
        cout << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Verificar si la lista esta vacia" << endl;
        cout << "2. Verificar si la lista esta llena" << endl;
        cout << "3. Insertar un elemento en la lista" << endl;
        cout << "4. Eliminar un elemento de la lista" << endl;
        cout << "5. Obtener el primer elemento de la lista" << endl;
        cout << "6. Obtener el ultimo elemento de la lista" << endl;
        cout << "7. Imprimir la lista" << endl;
        cout << "8. Anular la lista" << endl;
        cout << "9. Buscar" << endl;
        cout << "10. Ordenar" << endl;

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
            else {
                cout << "La lista no esta llena!!" << endl;
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
        }case 9: {
            if (lista.estaVacia() == false) {
            int opBusqueda, elemento;
            cout << "Ingrese el elemento que desea buscar" << endl;
            cin >> elemento;
            cout << "Que metodo de busqueda desea utilizar?" << endl;
            cout << "1. Lineal" << endl;
            cout << "2. Binaria" << endl;
            cin >> opBusqueda;
            if (opBusqueda == 1) {
                lista.busquedaLineal(elemento);

            }
            else if (opBusqueda == 2) {
                if (lista.isSorted == true) {
                    lista.busquedaBinaria(elemento);

                }
                else {
                    cout << "La lista no esta ordenada, debe ordenarla primero" << endl;
                }
                
            }
            else {
                cout << "Ingrese una opcion valida" << endl;

            }


            }
            else {
                cout << "La lista esta vacia" << endl;
            }
            break;
        }case 10: {
            if (lista.estaVacia() == false) {
            int ordenamiento;
            cout << "*** Ordenar ***" << endl;
            cout << "1. Bubble-sort" << endl;
            cout << "2. Insertion-Sort" << endl;
            cout << "3. Selection-Sort" << endl;
            cout << "4. Shell-sort" << endl;
            cout << "5. Merge-Sort" << endl;
            cout << "6. Quick-Sort" << endl;
            cin >> ordenamiento;
            switch (ordenamiento) {
            case 1: {
                lista.bubbleSort();
                break;
            }case 2: {
                lista.insertionSort();
                break;
            }case 3: {
                lista.selectionSort();

                break;
            }case 4: {
                lista.shellSort();

                break;
            }case 5: {
                lista.mergeSort(lista.elementos, 0, MAX_SIZE-1);
                cout << "Lista ordenada con exito!" << endl;
                break;
            }case 6: {
                lista.quickSort(lista.elementos, 0, MAX_SIZE-1);
                cout << "Lista ordenada con exito!" << endl;
                break;
            }default: {

                cout << "Ingrese una opcion valida" << endl;
                break;
            }

            }


            }
            else {
                cout << "La lista esta vacia" << endl;
            }
            break;
        }
        default: {
            cout << "Ingresa una opcion valida!" << endl;
        }
        }


         cout << "Desea continuar? Y/N: ";
         cin >> opt;
        }while (opt == 'Y' or opt == 'y');

    }

