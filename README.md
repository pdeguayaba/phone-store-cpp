# PHONE STORE
**Version 1.0.0**

C++ Phone Store project for the Programming Languages course.

The program will present the user with this Menu:
```
1) Cargar datos de archivo.
2) Almacenar datos en archivo.
3) Valor de inventario.
4) Valor de inventario para marca-modelo particular.
5) Mostrar cantidad disponible para marca-modelo particular.
6) Anadir a inventario.
7) Vender telefono.
8) Mostrar inventario en orden alfabetico de marca-modelo.
0) Salir.

Seleccione una opcion:
```

1. The program asks the user  for the name of the file containing the attributes of the objects from the class TelefonoMovil. The content will be saved in an array.

	>You can use the [telefono.txt](https://github.com/pdeguayaba/phone-store-cpp/blob/master/telefono.txt "telefono.txt") included in the repo.
	>**The *.txt* file will have four lines for each object, one for each attribute.**

	**An example of a compatible *.txt* for this program**

			Apple

			iPhone11

			1099.99

			90

2. This option will be available if the first option was selected previously. This option will save the content of the array into the *.txt* from which the contents were uploaded.
3. Prints the inventory value.
4. It asks the user for a brand and a model of a phone and it will display the inventory value of all corresponding units.
5. It asks for a brand, model and it will display the quantity available in inventory.
6. It asks for brand, model and how many would the user like to add to the inventory.
7. It displays the value of the device and will subtract 1 to inventory. If the inventory is at 0, it will indicate that there are no units.
8. It displays the properties of all devices in the inventory in alphabetical order. 

## License & Copyright
[![License](https://img.shields.io/github/license/pdeguayaba/phone-store-cpp)](https://github.com/pdeguayaba/phone-store-cpp/blob/master/LICENSE)
**© Edwin J. Estrella Ayala**
