#include "iostream"
// Se define una estructura llamada alumno
struct Alumno
{
    int codigo;
    std::string nombre;
    int anioNAc;
} alumno1, alumno2; // se declaran las variables de tipo struct

int main()
{

    struct Alumno alumno3;

    alumno3.codigo = 45454;

    alumno1 = {
        44878,
        "pedro",
        1987};

    std::cout << "Datos del alumno1:" << '\n';
    std::cout << "Codigo: " << alumno1.codigo << '\n';
    std::cout << "Nombre: " << alumno1.nombre << '\n';
    std::cout << "Año de Nacimiento: " << alumno1.anioNAc << '\n';

    return 0;
}