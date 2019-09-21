#ifndef TELEFONOMOVIL_H
#define TELEFONOMOVIL_H

#include <iostream>

#include <string>

using namespace std;

/*
 * Clase TelefonoMovil, esta es la clase principal.
 */
class TelefonoMovil {
    /*
     * Atributos
     */
    private:
        string marca;
        string modelo;
        double precio;
        int inventario;
    public:
        /*
         * Constructor Vacío
         */
        TelefonoMovil(): marca("Generica"), modelo("Basico"), precio(50.00), inventario(0) {}

        /*
         * Constructor para asignar valores a los tres argumentos.
         */
        TelefonoMovil(string ma, string mo, double p, int i) {
                setMarca(ma);
                setModelo(mo);
                setPrecio(p);
                setInventario(i);
            }

        /*
         * Destructor, no es completamente necesario. (buena practica)
         */
        ~TelefonoMovil() {}

        /*
         * Setters / Modifiers / Mutators / Transformers
         */
    
        /*
         * Se le asigna el valor a la marca.
         */
        void setMarca(string ma) {
            marca = ma;
        }
    
        /*
         * Se le asigna el valor al modelo.
         */
        void setModelo(string mo) {
            modelo = mo;
        }
    
        /*
         * Se le asigna el valor al precio.
         */
        void setPrecio(double p) {
            precio = p;
        }
    
        /*
         * Se le asigna el valor al inventario.
         */
        void setInventario(int i) {
            inventario = i;
        }
    
        /*
         * Getters / Observers
         */
    
        /*
         * Devuelve el valor de la marca.
         */
        string getMarca() const {
            return marca;
        }
    
        /*
         * Devuelve el valor del modelo.
         */
        string getModelo() const {
            return modelo;
        }
    
        /*
         * Devuelve el valor del precio.
         */
        double getPrecio() const {
            return precio;
        }
    
        /*
         * Devuelve el valor del inventario.
         */
        int getInventario() const {
            return inventario;
        }
};

#endif // TELEFONOMOVIL_H