#include <iostream>

#include <array>

#include <iterator>

#include <string>

#include <fstream>

#include <algorithm>

/*
 * Incluir el archivo header: telefonomovil.h que contiene la clase.
 */
#include "telefonomovil.h"

/*
 * Usar el namespace standard para no complicar el código.
 */
using namespace std;

/*
 * Prototipos
 */

/*
 * Prototipo de Funcion menu() para desplegar las opciones al usuario.
 */
void menu();
/*
 * Prototipo de la opcion 1.
 */
int cargaDatos(TelefonoMovil array[], string file);
/*
 * Prototipo de la opcion 2.
 */
void opcion2(TelefonoMovil arr[], string fileName, int objsEnArr);
/*
 * Prototipo de la opcion 3.
 */
double valorDeInventario(TelefonoMovil arr[], int objsEnArr);
/*
 * Prototipo de la opcion 4.
 */
double valorDeInventarioPorMarcaModelo(TelefonoMovil arr[], string marca, string modelo, int objsEnArr);
/*
 * Prototipo de la opcion 5.
 */
int cantidadDisponible(TelefonoMovil arr[], string marca, string modelo, int objsEnArr);
/*
 * Prototipo de la opcion 6.
 */
void anadirInventario(TelefonoMovil arr[], string marca, string modelo, int anadir, int& objsEnArr);
/*
 * Prototipo de la opcion 7.
 */
void venderMovil(TelefonoMovil arr[], string marca, string modelo, int vender, int objsEnArr);
/*
 * Prototipo de la opcion 8.
 */
void printOrdenAlfabetico(TelefonoMovil arr[], int objsEnArr);

/*
 * Funcion Main del programa.
 */
int main() {
    /*
     * Variable temporal para la opcion del usuario
     */
    int temp;
    /*
     * Variable para guardar el nombre del archivo .txt
     */
    string fileName = "telefono.txt";
    /*
     * Variable entera para calcular el total de objetos que se encuentran en el Arreglo.
     */
    int objsEnArr = 0;
    /*
     * Arreglo de Objetos TelefonoMovil que se va a utilizar para guardar la informacion del archivo .txt
     */
    TelefonoMovil arr[100];
    
    /*
     * Arreglo para probar.
     */
    /*TelefonoMovil arr[10] = {
     TelefonoMovil("Google", "Pixel", 800.00, 20),
     TelefonoMovil("Samsung", "Note10", 1000.00, 18),
     TelefonoMovil("Apple", "iPhoneXR", 750.00, 2),
     TelefonoMovil("Apple", "iPhone11", 1099.99, 80)
     };*/
    
    /*
     * Do-While para desplegar el menu continuamente.
     */
    do {
        /*
         * Llamada a la funcion menu().
         */
        menu();
        /*
         * Asignacion de la variable para la seleccion del usuario.
         */
        cin >> temp;
        /*
         * Caso switch para las diferentes opciones del programa.
         */
        switch (temp) {
            /*
             * Caso 0, cuando el usuario selecciona la opcion 0 el programa termina.
             */
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            /*
             * Caso 1, esta opcion guarda la informacion del archivo .txt en el arreglo de objetos TelefonoMovil.
             */
            case 1:
                /*
                 * objsEnArr va a guardar la cantidad de objetos que leyo del archivo .txt
                 */
                objsEnArr = cargaDatos(arr, fileName);
                break;
            case 2:
                opcion2(arr, fileName, objsEnArr);
                break;
            case 3:
                cout << "Inventario total: $" << valorDeInventario(arr, objsEnArr) << endl;
                break;
            case 4:
            {
                string marca;
                string modelo;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                double invMM = valorDeInventarioPorMarcaModelo(arr, marca, modelo, objsEnArr);
                cout << "Valor de Inventario para " << marca << " " << modelo << ": $" << invMM << endl;
            }
                break;
            case 5:
            {
                string marca;
                string modelo;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                int cantidadMM = cantidadDisponible(arr, marca, modelo, objsEnArr);
                cout << "Cantidad disponible de " << marca << " " << modelo << ": " << cantidadMM << endl;
            }
                break;
            case 6:
            {
                string marca;
                string modelo;
                int anadir;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                anadirInventario(arr, marca, modelo, anadir, objsEnArr);
            }
                break;
            case 7:
            {
                string marca;
                string modelo;
                int vender;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                cout << "Cantidad que se vendio: ";
                cin >> vender;
                venderMovil(arr, marca, modelo, vender, objsEnArr);
                cout << "Cantidad updated: " << cantidadDisponible(arr, marca, modelo, objsEnArr) << endl;
            }
                break;
            case 8:
                printOrdenAlfabetico(arr, objsEnArr);
                break;
            default:
                cout << "Opcion Invalida" << endl;
                break;
        }
    }
    while (temp != 0);
    return 0;
}

/*
 * Funcion para desplegar el menu y hacer que el usuario.
 */
void menu() {
    cout << "\nMenu\n";
    cout << "------------------------------------------------------------------\n";
    cout << "1) Cargar datos de archivo.\n";
    cout << "2) Almacenar datos en archivo.\n";
    cout << "3) Valor de inventario.\n";
    cout << "4) Valor de inventario para marca-modelo particular.\n";
    cout << "5) Mostrar cantidad disponible para marca-modelo particular.\n";
    cout << "6) Añadir a inventario.\n";
    cout << "7) Vender teléfono.\n";
    cout << "8) Mostrar inventario en orden alfabético de marca-modelo.\n";
    cout << "0) Salir.\n";
    cout << "\nSeleccione una opcion: ";
}

/*
 * Opcion 1:
 */

int cargaDatos(TelefonoMovil arr[], string fileName) {
    int objsEnArr = 0;
    string marca;
    string modelo;
    string precio;
    string inventario;
    
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile) {
        cout << "No se pudo abrir el archivo.\n";
        exit(1);
    } else if (inputFile.is_open()) {
        if (inputFile.fail()) {
            throw "No se pudo leer del archivo.\n";
        } else {
            while (!(inputFile.eof())) {
                getline(inputFile, marca);
                getline(inputFile, modelo);
                getline(inputFile, precio);
                getline(inputFile, inventario);
                arr[objsEnArr].setMarca(marca);
                arr[objsEnArr].setModelo(modelo);
                arr[objsEnArr].setPrecio(stod(precio));
                arr[objsEnArr].setInventario(stoi(inventario));
                objsEnArr++;
            }
        }
    }
    inputFile.close();
    return objsEnArr;
}


/*
 * Opcion 2: .
 */
void opcion2(TelefonoMovil arr[], string fileName, int objsEnArr) {
    ofstream outputFile;
    outputFile.open(fileName);
    
    for (int i = 0; i < objsEnArr; i++) {
        outputFile << arr[i].getMarca() << endl;
        outputFile << arr[i].getModelo() << endl;
        outputFile << arr[i].getPrecio() << endl;
        outputFile << arr[i].getInventario() << endl;
    }
    outputFile.close();
}

/*
 * Opcion 3: .
 */
double valorDeInventario(TelefonoMovil arr[], int objsEnArr) {
    double total = 0;
    int size = objsEnArr;
    for (int i = 0; i < size; i++) {
        if (arr[i].getMarca() != "Generica" && arr[i].getModelo() != "Basico" && arr[i].getPrecio() != 50 && arr[i].getInventario() != 0)
            total += ((double) arr[i].getInventario()) * arr[i].getPrecio();
    }
    return total;
}

/*
 * Opcion 4:
 */
double valorDeInventarioPorMarcaModelo(TelefonoMovil arr[], string marca, string modelo, int objsEnArr) {
    double total = 0;
    int size = objsEnArr;
    for (int i = 0; i < size; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo())))
            total += (double) arr[i].getInventario() * arr[i].getPrecio();
    }
    return total;
}

/*
 * Opcion 5:
 */
int cantidadDisponible(TelefonoMovil arr[], string marca, string modelo, int objsEnArr) {
    int total = 0;
    int size = objsEnArr;
    for (int i = 0; i < size; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo())))
            total += arr[i].getInventario();
    }
    return total;
}

/*
 * Opcion 6:
 */
void anadirInventario(TelefonoMovil arr[], string marca, string modelo, int anadir, int& objsEnArr) {
    int cantidadPasada = 0;
    double precio;
    int inventario;
    int size = objsEnArr;
    bool dentroDelArr = false;
    for (int i = 0; i < size; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) {
            cout << "Cantidad que desea anadir: ";
            cin >> anadir;
            cantidadPasada = arr[i].getInventario();
            arr[i].setInventario(cantidadPasada + anadir);
            dentroDelArr = true;
        }
    }
    if(dentroDelArr == false) {
        cout << "Precio del telefono " << marca << " " << modelo << ": ";
        cin >> precio;
        cout << "Cantidad de " << marca << " " << modelo << " que desea anñadir: ";
        cin >> inventario;
        arr[objsEnArr].setMarca(marca);
        arr[objsEnArr].setModelo(modelo);
        arr[objsEnArr].setPrecio(precio);
        arr[objsEnArr].setInventario(inventario);
        objsEnArr++;
    }
}

/*
 * Opcion 7:
 */
void venderMovil(TelefonoMovil arr[], string marca, string modelo, int vender, int objsEnArr) {
    int cantidadPasada = 0;
    int size = objsEnArr;
    for (int i = 0; i < size; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) {
            if (arr[i].getInventario() == 0)
                cout << "No hay unidades disponibles.\n";
            else if (arr[i].getInventario() < vender)
                cout << "Solo hay " << arr[i].getInventario() << " unidades disponibles.\n";
            else {
                cantidadPasada = arr[i].getInventario();
                arr[i].setInventario(cantidadPasada - vender);
                if (arr[i].getInventario() < 0)
                    arr[i].setInventario(0);
            }
        }
    }
}

/*
 * Opcion 8:
 */
void printOrdenAlfabetico(TelefonoMovil arr[], int objsEnArr) {
    TelefonoMovil temp;
    TelefonoMovil tempm;
    int size = objsEnArr;
    /*
     * Selection Sort
     */
    
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            //cout << "--------" << transform(arr[0].begin(), arr[0].end(), arr[9].begin(), ::tolower);
            if (arr[j].getMarca() == (arr[min].getMarca())) {
                if (arr[j].getModelo().compare(arr[min].getModelo()) < 0) {
                    min = j;
                }
            } else if (arr[j].getMarca().compare(arr[min].getMarca()) < 0) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    
    for (int i = 0; i < size; i++) {
        cout << arr[i].getMarca() << " " << arr[i].getModelo() << ": " << arr[i].getInventario() << " \t|\t Precio: $" << arr[i].getPrecio() << endl;
    }
}
