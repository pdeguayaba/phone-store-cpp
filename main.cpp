//*****************************************************************************
//
//   Programadores : ESTRELLA AYALA, EDWIN J.
//                   GIRAUD BETANCOURT, STEPHANIE
//                   PEREZ SANABRIA, JOSE A.
//                   VALLE RODRIGUEZ, ERICK J.
//   Curso         : COMP3800 (78112) - Programming Languages
//   Proyecto      : Trabajo de Investigacion C++
//   Profesor      : Jose Navarro Figueroa
//   Fecha         : 22 de septiembre de 2019
//*****************************************************************************
/*
 * Incluir el archivo header: telefonomovil.h que contiene la clase.
 */
#include "telefonomovil.h"
#include <array>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <iomanip>

/*
 * Prototipos
 *
 * Prototipo de Funcion menu().
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
     * Variable temporal para la seleccion de opcion del usuario.
     */
    int temp;
    /*
     * Variable para guardar el nombre del archivo .txt
     */
    string fileName;
    /*
     * Variable entera para calcular el total de objetos que se encuentran en el Arreglo.
     */
    int objsEnArr = 0;
    /*
     * Arreglo de Objetos TelefonoMovil que se va a utilizar para guardar la informacion del archivo .txt
     */
    TelefonoMovil arr[100];
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
             * Lo primero que hace este caso es que le pide al usuario el archivo .txt
             */
            cout << "Entre el nombre del archivo que desea leer (Ejemplo: misTelefonos.txt): ";
            cin >> fileName;
            objsEnArr = cargaDatos(arr, fileName);
            break;
            /*
             * Caso 2, esta opcion va a almacenar todos los datos en el archivo que el usuario está modificando.
             */
        case 2:
            opcion2(arr, fileName, objsEnArr);
            break;
            /*
             * Caso 3, esta opcion va a desplegar el valor total del inventario que se tiene.
             */
        case 3:
            cout << "Inventario total: $" << fixed << setprecision(2) << valorDeInventario(arr, objsEnArr) << endl;
            break;
            /*
             * Caso 4, esta opcion va a pedirle al usuario que introduzca una marca y un modelo
             * particular y va a desplegar el valor de inventario que tiene para ese telefono.
             */
        case 4:
            {
                string marca;
                string modelo;
                cout << "Marca: ";
                cin >> marca;
                cout << "Modelo: ";
                cin >> modelo;
                double invMM = valorDeInventarioPorMarcaModelo(arr, marca, modelo, objsEnArr);
                cout << "Valor de Inventario para " << marca << " " << modelo << ": $" << fixed << setprecision(2) << invMM << endl;
            }
            break;
            /*
             * Caso 5, esta opcion va a pedirle al usuario que introduzca una marca y un modelo
             * particular y va a desplegar la cantidad que se tiene de ese telefono.
             */
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
            /*
             * Caso 6, esta opcion va a pedirle al usuario que introduzca una marca y un modelo
             * particular, luego cuando llama la funcion, la misma va a pedirle que introduzca
             * el precio y la cantidad que desea anadir al inventario.
             */
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
            /*
             * Caso 7, esta opcion va a pedirle al usuario que introduzca una marca y un modelo
             * particular, luego va a pedirle la cantidad que vendio de ese telefono.
             */
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
            }
            break;
            /*
             * Caso 8, esta opcion va a desplegar todos los telefonos en orden alfabetico.
             * Ademas muestra la cantidad que hay de los mismos y su precio.
             */
        case 8:
            printOrdenAlfabetico(arr, objsEnArr);
            break;
            /*
             * Si el usuario introduce una opcion invalida, el programa le da un mensaje
             * al usuario de que la opcion que introdujo es una invalida.
             */
        default:
            cout << "Opcion Invalida" << endl;
            break;
        }
    }
    /*
     * Hasta que el usuario no introduzca la opcion 0, el programa sigue corriendo.
     */
    while (temp != 0);
    return 0;
}
/*
 * Menu:        Funcion para desplegarle al usuario el menu con las opciones para escoger.
 * Autor:       ESTRELLA AYALA, EDWIN J.
 * Fecha:       4 de septiembre de 2019
 */
void menu() {
    cout << "\nMenu\n";
    cout << "1) Cargar datos de archivo.\n";
    cout << "2) Almacenar datos en archivo.\n";
    cout << "3) Valor de inventario.\n";
    cout << "4) Valor de inventario para marca-modelo particular.\n";
    cout << "5) Mostrar cantidad disponible para marca-modelo particular.\n";
    cout << "6) Anadir a inventario.\n";
    cout << "7) Vender telefono.\n";
    cout << "8) Mostrar inventario en orden alfabetico de marca-modelo.\n";
    cout << "0) Salir.\n";
    cout << "\nSeleccione una opcion: ";
}
/*
 * Opcion 1:   Esta funcion va a cargar los datos del archivo .txt a un arreglo de objetos y devuelve
 *             un valor entero (objsEnArr) para saber la cantidad de telefonos que cargo al arreglo.
 * Argumentos: Arreglo de objetos (arr[]) para guardar los datos y el nombre del archivo (fileName) .txt
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      17 de septiembre de 2019
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
 * Opcion 2:   Esta funcion va a guardar la informacion recopilada en el archivo .txt
 * Argumentos: Arreglo de objetos (arr[]) que contiene la info a guardarse en el archivo .txt
 *             el nombre del archivo (fileName) .txt en donde se va a guardar la info
 *             y por ultimo el total de telefonos (objsEnArr) que tiene el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      19 de septiembre de 2019
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
 * Opcion 3:   Esta funcion devuelve el valor total ($) del inventario que se tiene.
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos
 *             y el numero de telefonos (objsEnArr) en el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      11 de septiembre de 2019
 */
double valorDeInventario(TelefonoMovil arr[], int objsEnArr) {
    double total = 0;
    for (int i = 0; i < objsEnArr; i++) {
        if (arr[i].getMarca() != "Generica" && arr[i].getModelo() != "Basico" && arr[i].getPrecio() != 50 && arr[i].getInventario() != 0) total += ((double) arr[i].getInventario()) * arr[i].getPrecio();
    }
    return total;
}
/*
 * Opcion 4:   Esta funcion devuelve el valor total ($) de un telefono en particular (marca-modelo).
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos, la marca del telefono (marca),
 *             el modelo del telefono (modelo) y el numero de telefonos (objsEnArr) en el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      11 de septiembre de 2019
 */
double valorDeInventarioPorMarcaModelo(TelefonoMovil arr[], string marca, string modelo, int objsEnArr) {
    double total = 0;
    for (int i = 0; i < objsEnArr; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) total += (double) arr[i].getInventario() * arr[i].getPrecio();
    }
    return total;
}
/*
 * Opcion 5:   Esta funcion devuelve la cantidad total que se tiene de un telefono en particular (marca-modelo).
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos, la marca del telefono (marca),
 *             el modelo del telefono (modelo) y el numero de telefonos (objsEnArr) en el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      11 de septiembre de 2019
 */
int cantidadDisponible(TelefonoMovil arr[], string marca, string modelo, int objsEnArr) {
    int total = 0;
    for (int i = 0; i < objsEnArr; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) total += arr[i].getInventario();
    }
    return total;
}
/*
 * Opcion 6:   Esta funcion anade un telefono (marca-modelo) en el arreglo, toma en consideracion si ya ese telefono
 *             esta en el arreglo, de estarlo simplemente le suma el valor al inventario, de no estar, le pide al
 *             usuario que anada la marca, el modelo, el precio y la cantidad de telefono que desea anadir.
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos, la marca del telefono (marca),
 *             el modelo del telefono (modelo), cantidad que desea anadir (anadir) y el numero de
 *             telefonos (objsEnArr) en el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      11 de septiembre de 2019 (Revisado y Editado: 18 de septiembre de 2019)
 */
void anadirInventario(TelefonoMovil arr[], string marca, string modelo, int anadir, int& objsEnArr) {
    int cantidadPasada = 0;
    double precio;
    int inventario;
    bool dentroDelArr = false;
    for (int i = 0; i < objsEnArr; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) {
            cout << "Cantidad que desea anadir: ";
            cin >> anadir;
            cantidadPasada = arr[i].getInventario();
            arr[i].setInventario(cantidadPasada + anadir);
            dentroDelArr = true;
        }
    }
    if (dentroDelArr == false) {
        cout << "Precio del telefono " << marca << " " << modelo << ": ";
        cin >> precio;
        cout << "Cantidad de " << marca << " " << modelo << " que desea annadir: ";
        cin >> inventario;
        arr[objsEnArr].setMarca(marca);
        arr[objsEnArr].setModelo(modelo);
        arr[objsEnArr].setPrecio(precio);
        arr[objsEnArr].setInventario(inventario);
        objsEnArr++;
    }
}
/*
 * Opcion 7:   Esta funcion toma en consideracion un telefono en particular (marca-modelo), y le va a
 *             restar la cantidad que se vendio de ese telefono al inventario del mismo. Si la cantidad
 *             del inventario del telefono (marca-modelo) particular es de 0, se le notifica al usuario
 *             que "No hay unidades disponibles." Y, si la venta es mayor que el inventario, se le
 *             notifica al usuario y se le deja saber cuantas unidades quedan disponibles.
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos, la marca del telefono (marca),
 *             el modelo del telefono (modelo), cantidad a vender (vender), y la cantidad de telefonos (objsEnArr)
 *             en el arreglo.
 * Autor:      ESTRELLA AYALA, EDWIN J.
 * Fecha:      11 de septiembre de 2019
 */
void venderMovil(TelefonoMovil arr[], string marca, string modelo, int vender, int objsEnArr) {
    int cantidadPasada = 0;
    for (int i = 0; i < objsEnArr; i++) {
        if (!(marca.compare(arr[i].getMarca())) && !(modelo.compare(arr[i].getModelo()))) {
            if (arr[i].getInventario() == 0) cout << "No hay unidades disponibles.\n";
            else if (arr[i].getInventario() < vender) cout << "Solo hay " << arr[i].getInventario() << " unidades disponibles.\n";
            else {
                cantidadPasada = arr[i].getInventario();
                arr[i].setInventario(cantidadPasada - vender);
                if (arr[i].getInventario() < 0) arr[i].setInventario(0);
            }
        }
    }
}
/*
 * Opcion 8:   Esta funcion imprime la informacion (de los telefonos que se tienen en el arreglo) en orden
 *             alfabetico. (Marca | Modelo | Precio | Inventario)
 * Argumentos: Arreglo de objetos (arr[]) con la informacion de los telefonos y el numero de telefonos en
 *             en arreglo (objsEnArr).
 * Autor: ESTRELLA AYALA, EDWIN J.
 * Fecha: 20 de septiembre de 2019 (Revisado y Editado: 21 de septiembre de 2019)
 */
 void printOrdenAlfabetico(TelefonoMovil arr[], int objsEnArr) {
     /*
      * Variables para controlar el output.
      */
     const int name_width = 20 ;
     const int num_flds = 4 ;
     const string sep = " |" ;
     const int total_width = name_width*4 + sep.size() * num_flds ;
     const string line = sep + string(total_width - 1, '-' ) + '|' ;

     TelefonoMovil temp;
     string marcaFirst;
     string marcaNext;
     string modeloFirst;
     string modeloNext;
     for (int i = 0; i < objsEnArr; i++) {
         for (int j = 0; j < objsEnArr - i - 1; j++) {
             marcaFirst = arr[j].getMarca();
             for_each(marcaFirst.begin(), marcaFirst.end(), [](char& c) {
                 c = ::toupper(c);
             });
             marcaNext = arr[j + 1].getMarca();
             for_each(marcaNext.begin(), marcaNext.end(), [](char& c) {
                 c = ::toupper(c);
             });
             modeloFirst = arr[j].getModelo();
             for_each(modeloFirst.begin(), modeloFirst.end(), [](char& c) {
                 c = ::toupper(c);
             });
             modeloNext = arr[j + 1].getModelo();
             for_each(modeloNext.begin(), modeloNext.end(), [](char& c) {
                 c = ::toupper(c);
             });
             if (marcaFirst.compare(marcaNext) > 0) {
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
             } else if (marcaFirst.compare(marcaNext) == 0) {
                 if (modeloFirst.compare(modeloNext) > 0) {
                     temp = arr[j];
                     arr[j] = arr[j + 1];
                     arr[j + 1] = temp;
                 }
             }
         }
     }
     cout << line << '\n' << sep << setw(name_width) << "Marca" << sep << setw(name_width) << "Modelo" << sep
          << setw(name_width) << "Precio" << sep << setw(name_width) << "Inventario" << sep << '\n' << line << '\n' ;
     for (int i = 0; i < objsEnArr; i++) {
         cout << sep << setw(name_width) << arr[i].getMarca() << sep << setw(name_width) << arr[i].getModelo() << sep
              << setw(name_width) << fixed << setprecision(2) << arr[i].getPrecio() << sep << setw(name_width) << arr[i].getInventario() << sep << '\n';
     }
     cout << line << '\n' ;
 }
