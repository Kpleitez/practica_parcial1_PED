#include "iostream"
#include "string"

// Estructura llamada Pelicula

struct Pelicula
{
    std::string titulo;
    float duracion;
    float calificacion;
    std::string genero;
};

void datos_pelicula(Pelicula peliculas[], int cantidad_peliculas)
{
    for (int i = 0; i < cantidad_peliculas; i++)
    {
        std::cout << "Ingresa datos de la pelicula " << i + 1 << ":" << '\n';
        std::cout << "Titulo: ";
        std::cin.ignore();
        std::getline(std::cin, peliculas[i].titulo);
        std::cout << "Digite la duracion de la pelicula: ";
        std::cin >> peliculas[i].duracion;
        std::cout << "Digite la calificacion de la pelicula: ";
        std::cin >> peliculas[i].calificacion;
        std::cout << "Genero de la pelicula: ";
        std::cin.ignore();
        std::getline(std::cin, peliculas[i].genero);
        std::cout << "---------------------";
        std::cout << '\n';
    }
}

void calificacion_Promedio(Pelicula peliculas[], int n)
{
    float sumaAccion = 0, sumaDrama = 0, sumaComedia = 0;
    int contadorAccion = 0, contadorDrama = 0, contadorComedia = 0;

    for (int i = 0; i < n; i++)
    {
        if (peliculas[i].genero == "Accion")
        {
            sumaAccion += peliculas[i].calificacion;
            contadorAccion++;
        }
        else if (peliculas[i].genero == "Drama")
        {
            sumaDrama += peliculas[i].calificacion;
            contadorDrama++;
        }
        else if (peliculas[i].genero == "Comedia")
        {
            sumaComedia += peliculas[i].calificacion;
            contadorComedia++;
        }
    }

    if (contadorAccion > 0)
        std::cout << "Promedio de calificación para Acción: " << sumaAccion / contadorAccion << '\n';
    if (contadorDrama > 0)
        std::cout << "Promedio de calificación para Drama: " << sumaDrama / contadorDrama << '\n';
    if (contadorComedia > 0)
        std::cout << "Promedio de calificación para Comedia: " << sumaComedia / contadorComedia << '\n';
}

void actualizarCalificacion(Pelicula peliculas[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (peliculas[i].genero == "Accion")
        {
            peliculas[i].calificacion += 0.5;
            if (peliculas[i].calificacion > 10)
                peliculas[i].calificacion = 10; // No debe superar 10
        }
        else if (peliculas[i].genero == "Drama")
        {
            peliculas[i].calificacion -= 0.2;
            if (peliculas[i].calificacion < 0)
                peliculas[i].calificacion = 0; // No debe bajar de 0
        }
    }
    std::cout << "Calificaciones actualizadas exitosamente." << '\n';
}
void mostrarDatos(Pelicula peliculas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Película " << i + 1 << ": " << '\n';
        std::cout << "Título: " << peliculas[i].titulo << '\n';
        std::cout << "Duración: " << peliculas[i].duracion << " minutos" << '\n';
        std::cout << "Calificación: " << peliculas[i].calificacion << '\n';
        std::cout << "Género: " << peliculas[i].genero << '\n';
        std::cout << '\n';
    }
}
void buscarPelicula(Pelicula peliculas[], int n, std::string tituloBuscada)
{
    bool encontrada = false;
    for (int i = 0; i < n; i++)
    {
        if (peliculas[i].titulo == tituloBuscada)
        {
            std::cout << "Película encontrada:" << '\n';
            std::cout << "Título: " << peliculas[i].titulo << '\n';
            std::cout << "Duración: " << peliculas[i].duracion << " minutos" << '\n';
            std::cout << "Calificación: " << peliculas[i].calificacion << '\n';
            std::cout << "Género: " << peliculas[i].genero << '\n';
            encontrada = true;
            break;
        }
    }
    if (!encontrada)
    {
        std::cout << "Película no encontrada." << '\n';
    }
}
int main()
{
    int cantidad_peliculas;
    std::cout << "¿Cuántas películas deseas ingresar? ";
    std::cin >> cantidad_peliculas;
    Pelicula peliculas[cantidad_peliculas];
    datos_pelicula(peliculas, cantidad_peliculas);
    actualizarCalificacion(peliculas, cantidad_peliculas);
    mostrarDatos(peliculas, cantidad_peliculas);

    std::string tituloBuscado;
    std::cout << "Ingresa el título de la película que deseas buscar: ";
    std::cin.ignore();
    std::getline(std::cin, tituloBuscado);

    buscarPelicula(peliculas, cantidad_peliculas, tituloBuscado);
    return 0;
}