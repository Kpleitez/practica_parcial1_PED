#include <iostream>
using namespace std;

// Declaración de la estructura Alumno
struct Alumno {
    int codigo;
    string nombre;
    int anioNAc;
};

// Función para llenar los datos de un alumno
void llenado_datos(Alumno datos[], int n) {
    for (int i = 0; i < n; i++)
    { 
    cout<< "Digite el codigo del alumno: ";
    cin >> datos[i].codigo;
    cout << "Digite el nombre del alumno: ";
    cin >> datos[i].nombre;
    cout << "Digite el año de nacimiento del alumno: ";
    cin >> datos[i].anioNAc;
    cout << "----------------------" << endl;
    }
    
}

// Función para mostrar los datos de un alumno
void mostrar_datos(Alumno datos[], int n) {
    for (int i = 0; i < n; i++)
    {
    cout << "Los datos del alumno " << i + 1 << " son: " << '\n';
    cout << "Codigo: " << datos[i].codigo << endl;
    cout << "Nombre: " << datos[i].nombre << endl;
    cout << "Año de nacimiento: " << datos[i].anioNAc << endl;
    cout << "----------------------" << endl;
    }
    
    
}

int main() {
    int n;

    // Pedir al usuario la cantidad de alumnos
    cout << "¿Cuántos alumnos deseas ingresar?: ";
    cin >> n;
    
    Alumno datos[n];

    llenado_datos(datos,n);
    mostrar_datos(datos, n);
  

    return 0;
}