#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura Película
struct Pelicula {
    string titulo;
    int duracion;    // Duración en minutos
    float calificacion; // Calificación de 0 a 10
    string genero;   // Género: "Acción", "Comedia", "Drama", etc.
};

// Función para ingresar los datos de varias películas
void ingresarDatos(Pelicula peliculas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingresar datos de la película " << i + 1 << ":" << endl;
        cout << "Título: ";
        cin.ignore();
       getline(cin, peliculas[i].titulo);
        cout << "Duración (en minutos): ";
        cin >> peliculas[i].duracion;
        cout << "Calificación (0 a 10): ";
        cin >> peliculas[i].calificacion;
        cout << "Género: ";
        cin.ignore();
        getline(cin, peliculas[i].genero);
        cout << endl;
    }
}

// Función para calcular el promedio de calificación por género
void calcularPromedioCalificacion(Pelicula peliculas[], int n) {
    float sumaAccion = 0, sumaDrama = 0, sumaComedia = 0;
    int contadorAccion = 0, contadorDrama = 0, contadorComedia = 0;
    
    for (int i = 0; i < n; i++) {
        if (peliculas[i].genero == "Accion") {
            sumaAccion += peliculas[i].calificacion;
            contadorAccion++;
        } else if (peliculas[i].genero == "Drama") {
            sumaDrama += peliculas[i].calificacion;
            contadorDrama++;
        } else if (peliculas[i].genero == "Comedia") {
            sumaComedia += peliculas[i].calificacion;
            contadorComedia++;
        }
    }

    if (contadorAccion > 0)
        cout << "Promedio de calificación para Acción: " << sumaAccion / contadorAccion << endl;
    if (contadorDrama > 0)
        cout << "Promedio de calificación para Drama: " << sumaDrama / contadorDrama << endl;
    if (contadorComedia > 0)
        cout << "Promedio de calificación para Comedia: " << sumaComedia / contadorComedia << endl;
}

// Función para actualizar la calificación de acuerdo al género
void actualizarCalificacion(Pelicula peliculas[], int n) {
    for (int i = 0; i < n; i++) {
        if (peliculas[i].genero == "Accion") {
            peliculas[i].calificacion += 0.5;
            if (peliculas[i].calificacion > 10)
                peliculas[i].calificacion = 10; // No debe superar 10
        } else if (peliculas[i].genero == "Drama") {
            peliculas[i].calificacion -= 0.2;
            if (peliculas[i].calificacion < 0)
                peliculas[i].calificacion = 0; // No debe bajar de 0
        }
    }
    cout << "Calificaciones actualizadas exitosamente." << endl;
}

// Función para mostrar los datos de todas las películas
void mostrarDatos(Pelicula peliculas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Película " << i + 1 << ": " << endl;
        cout << "Título: " << peliculas[i].titulo << endl;
        cout << "Duración: " << peliculas[i].duracion << " minutos" << endl;
        cout << "Calificación: " << peliculas[i].calificacion << endl;
        cout << "Género: " << peliculas[i].genero << endl;
        cout << endl;
    }
}

// Función para buscar una película por su título
void buscarPelicula(Pelicula peliculas[], int n, string tituloBuscada) {
    bool encontrada = false;
    for (int i = 0; i < n; i++) {
        if (peliculas[i].titulo == tituloBuscada) {
            cout << "Película encontrada:" << endl;
            cout << "Título: " << peliculas[i].titulo << endl;
            cout << "Duración: " << peliculas[i].duracion << " minutos" << endl;
            cout << "Calificación: " << peliculas[i].calificacion << endl;
            cout << "Género: " << peliculas[i].genero << endl;
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "Película no encontrada." << endl;
    }
}

// Programa principal
int main() {
    int n;
    cout << "¿Cuántas películas deseas ingresar? ";
    cin >> n;

    Pelicula peliculas[n];  // Arreglo de estructuras

    ingresarDatos(peliculas, n);
    calcularPromedioCalificacion(peliculas, n);
    actualizarCalificacion(peliculas, n);
    mostrarDatos(peliculas, n);

    string tituloBuscado;
    cout << "Ingresa el título de la película que deseas buscar: ";
    cin.ignore();
    getline(cin, tituloBuscado);

    buscarPelicula(peliculas, n, tituloBuscado);

    return 0;
}
