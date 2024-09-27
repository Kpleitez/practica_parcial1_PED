#include <iostream>
#include <string>

struct Mascota {
    std::string nombre;
    int edad;
    std::string vacuna;
};

// Función para capturar datos de una sola mascota
void datos_Mascota(Mascota* mascotas, int cantidad_mascota) {
    std::cin.ignore(); // Limpiamos el buffer al principio
    for (int i = 0; i < cantidad_mascota; i++) {
        std::cout << "Ingrese los datos de la mascota " << i + 1 << ":\n";
        std::cout << "Nombre de la mascota: ";
        std::getline(std::cin, (mascotas + i)->nombre); // Se puede usar mascotas[i].nombre
        std::cout << "Edad de la mascota (en años): ";
        std::cin >> (mascotas + i)->edad;
        std::cin.ignore(); // Ignorar newline antes de la siguiente entrada
        std::cout << "Digite si vacunado o no vacunado:  ";
        std::getline(std::cin, (mascotas + i)->vacuna); // Captura la entrada completa
        std::cout << "-------------------------------\n";
    }
}

// Función para mostrar los datos de una mascota individual
void mostrar_mascota(const Mascota* mascota, int numMascota) {
    std::cout << "Datos de la mascota " << numMascota + 1 << ":\n";
    std::cout << "Nombre: " << mascota->nombre << "\nEdad: " << mascota->edad << " años\nVacuna: " << mascota->vacuna << '\n';
    std::cout << "-------------------------------\n";
}

// Función para mostrar todas las mascotas
void mostrar_mascotas(const Mascota* mascotas, int cantidad_mascotas) {
    std::cout << "La lista de mascotas ingresadas es la siguiente:\n";
    for (int i = 0; i < cantidad_mascotas; i++) {
        mostrar_mascota(&mascotas[i], i);
    }
}

// Función para actualizar el estado de vacunación de las mascotas
void actualizarEstadovac(Mascota* mascotas, int cantidad_mascotas) {
    for (int i = 0; i < cantidad_mascotas; i++) {
        Mascota* mascota = mascotas + i; // Puntero temporal
        if (mascota->vacuna == "no vacunado") {
            std::cout << "Digite el nuevo indicador de vacuna para " << mascota->nombre << ": ";
            std::getline(std::cin, mascota->vacuna);
            std::cout << "-----------------------\n";
        }
    }
    std::cout << "DATOS ACTUALIZADOS\n";
    mostrar_mascotas(mascotas, cantidad_mascotas);
}

// Función para filtrar mascotas no vacunadas
void filtoporVacunacion(Mascota* mascotas, int cantidad_mascotas) {
    std::cout << "Esta es la lista de mascotas que no han sido vacunadas:\n";
    for (int i = 0; i < cantidad_mascotas; i++) {
        Mascota* mascota = mascotas + i; 
        if (mascota->vacuna == "no vacunado") {
            mostrar_mascota(mascota, i);
        }
    }
}

// Función para contar mascotas vacunadas y no vacunadas
void contarMascotas(const Mascota* mascotas, int cantidad_mascotas) {
    int vacunadas = 0, no_vacunadas = 0;
    for (int i = 0; i < cantidad_mascotas; i++) {
        const Mascota* mascota = mascotas + i; // Puntero constante
        if (mascota->vacuna == "vacunado") {
            vacunadas++;
        } else {
            no_vacunadas++;
        }
    }
    std::cout << "La cantidad de mascotas vacunadas es: " << vacunadas << '\n';
    std::cout << "La cantidad de mascotas no vacunadas es: " << no_vacunadas << '\n';
    std::cout << "------------------------------------------------------------\n";
}

// Función para buscar una mascota por nombre
void buscarMascota(Mascota* mascotas, int cantidad_mascotas, const std::string& nombreMascota) {
    bool encontrada = false;
    for (int i = 0; i < cantidad_mascotas; i++) {
        Mascota* mascota = mascotas + i;
        if (mascota->nombre == nombreMascota) {
            mostrar_mascota(mascota, i);
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        std::cout << "Mascota no encontrada.\n";
    }
}

int main() {
    int cantidad_mascotas;

    std::cout << "Digite la cantidad de mascotas a ingresar: ";
    std::cin >> cantidad_mascotas;

    // Uso de punteros dinámicos
    Mascota* mascotas = new Mascota[cantidad_mascotas];
    
    datos_Mascota(mascotas, cantidad_mascotas);
    mostrar_mascotas(mascotas, cantidad_mascotas);
    contarMascotas(mascotas, cantidad_mascotas);
    filtoporVacunacion(mascotas, cantidad_mascotas);
    actualizarEstadovac(mascotas, cantidad_mascotas);

    std::string nombreMascota;
    std::cout << "Ingrese el nombre de la mascota a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombreMascota);

    buscarMascota(mascotas, cantidad_mascotas, nombreMascota);

    // Liberar memoria
    delete[] mascotas;

    return 0;
}
