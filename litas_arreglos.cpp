#include <iostream>
using namespace std;

const int CAPACIDAD_MAXIMA = 10;

class ListaArreglo {
private:
    int datos[CAPACIDAD_MAXIMA];
    int tamano; // cantidad de elementos actualmente almacenados

public:
    ListaArreglo() {
        tamano = 0;
    }

    bool estaVacia() {
        return tamano == 0;
    }

    bool estaLlena() {
        return tamano == CAPACIDAD_MAXIMA;
    }

    int obtenerTamano() {
        return tamano;
    }

// Inserta 'valor' en la posición 'posicion' (0-indexada)
// caso límite 1: lista llena -> no se debe insertar
// caso límite 2: posición inválida (posicion < 0 o posicion > tamaño)
    bool insertar (int valor, int posicion) {
        if (estaLlena()) {
            cout << "Error: la lista esta llena, no se puede insertar." << endl;
            return false;
        }
        if (posicion < 0 || posicion > tamano){
            cout << "Error: posicion invalida (" << posicion << ")." <<endl;
            return false;
        }
        
        // Desplazar elementos hacia la derecha para abrir espacio
        for (int i = tamano; i > posicion; i--) {
            datos[i] = datos[i - 1];
        }
            datos[posicion] = valor;
            tamano++;
            return true;
        }
    // Elimina el elemento en 'posicion'
    // Caso límte 1: lista vacía -> no se puede eliminar
    // Caso límite 2: posición inv'alida (posicion < 0 o posicion >= tamano)
    bool eliminar(int posicion) {
        if(estaVacia()) {
            cout << "Error: la lista esta vacia, no se puede eliminar." << endl;
            return false;
        }
        if (posicion < 0 || posicion >= tamano) {
            cout << "Error: posicion invalida (" << posicion << ")." << endl;
            return false;
        }

        //Desplazar elementos hacia la izquierda para cerrar el espacio
        for (int i = posicion; i < tamano - 1; i++) {
            datos[i] = datos[i + 1];
        }

        tamano--;
        return true;
    }

    //Busca 'valor' y retorna su posicion, o -1 si no existe
    int buscar(int valor) {
        for (int i = 0; i < tamano; i++) {
            if (datos[i] == valor){
                return i;
            }
        }
        return -1;
    }

    // Recorre e imprime todos los elementos de la lista
    void recorrer() {
        if (estaVacia()) {
            cout << "[ lista vacia ]" << endl;
            return;
        }
        cout << "[ ";
        for (int i = 0; i < tamano; i++) {
            cout << datos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }
};

int main() {
    ListaArreglo lista;

    cout << "--- Insertando elementos ---" << endl;
    lista.insertar(10, 0);
    lista.insertar(20, 1);
    lista.insertar(15, 1); // queda: 10, 15, 20
    lista.recorrer();

    cout << "\n--- Buscando el valor 15 ---" << endl;
    int pos = lista.buscar(15);
    cout << (pos != -1 ? "Encontrado en la posicion" + to_string(pos):"No encontrado") << endl;
    
    cout << "\n--- Eliminando la posicion 0 ---" << endl;
    lista.eliminar(0);
    lista.recorrer();

    cout << "\n=== Caso limite (Taller practico con IA ===" << endl;

    cout << "\n--- Caso 1: lista vacia (eliminar) ---" << endl;
    ListaArreglo listaVacia;
    listaVacia.eliminar(0); 

    cout << "\n--- Caso 2: lista llena (insertar) ---" << endl;
    ListaArreglo listaLlena;
    for (int i = 0; i < CAPACIDAD_MAXIMA; i++) {
        listaLlena.insertar(i, i);
    }
    listaLlena.recorrer();
    listaLlena.insertar(99, 0); 

    cout << "\n--- Caso 3: posicion invalida (insertar y eliminar) ---";
    ListaArreglo listaPruebas;
    listaPruebas.insertar(1, 0);
    listaPruebas.insertar(2, 1);
    listaPruebas.insertar(50, -1); 
    listaPruebas.insertar(50, 10); 
    listaPruebas.eliminar(-1);    
    listaPruebas.eliminar(10);    
    listaPruebas.recorrer();      

    return 0;
}