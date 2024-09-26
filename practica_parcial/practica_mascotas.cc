#include "iostream" 
#include "string"

struct Mascota
{
    std:: string nombre;
    int edad;
    std:: string vacuna;
};

void datos_Mascota(Mascota mascotas[], int cantidad_mascota){
    for (int i = 0; i < cantidad_mascota; i++)
    {
        std::cout << "Ingrese los datos de la mascota " << i + 1 << ":" << '\n';
        std::cout << "Nombre de la mascota: ";
        std::cin.ignore();
        std::getline(std::cin, mascotas[i].nombre);
        std::cout << "Edad de la mascota (en años): ";
        std::cin >> mascotas[i].edad;
        std::cout << "Digite si vacunado o no vacunado segun el caso de cada mascota:  "; 
        std::cin.ignore();
        std::getline(std::cin, mascotas[i].vacuna);
        std::cout<< "-------------------------------";
        std::cout<< '\n';
    }     
}

void mostrar_mascotas(Mascota mascotas[], int cantidad_mascotas){
    
    std::cout << "La lista de mascotas ingresadas es la siguiente: " << '\n';
    for (int i = 0; i < cantidad_mascotas; i++)
    {
        std::cout << "Datos de la mascota " << i + 1 << ":" << '\n';
        std::cout << "Nombre de la mascota: "<< mascotas[i].nombre << '\n';
        std::cout << "Edad de la mascota: "<< mascotas[i].edad << "años" << '\n';
        std::cout << "Indicador de vacuna: " << mascotas[i].vacuna << '\n';
        std::cout<< "-------------------------------";
        std::cout<< '\n';
    }
    
}

void actualizarEstadovac(Mascota mascotas[], int cantidad_mascotas)
{
    for (int i = 0; i < cantidad_mascotas; i++)
    {
        if (mascotas[i].vacuna == "no vacunado")
        {
            std::cout << "Digite el nuevo indicador de vacuna de la mascota: " << i + 1 << '\n';
            std::cin.ignore();
            std::getline(std::cin, mascotas[i].vacuna); 
            std::cout << "-----------------------" << '\n' ;
        }
    }
    std::cout << "DATOS ACTUALIZADOS" << '\n';
    mostrar_mascotas(mascotas,cantidad_mascotas);

};

void filtoporVacunacion(Mascota mascotas[], int cantidad_mascotas)
{
    std::cout << "Esta es la lista de mascotas que no han sido vacunadas: " << '\n';
    for (int i = 0; i < cantidad_mascotas; i++)
    {
        if (mascotas[i].vacuna == "no vacunado")
        {
            std::cout << "Mascota: " << i + 1 << '\n';
            std::cout << mascotas[i].nombre << '\n';
           
        }
    }
    

};

void contarMascotas(Mascota mascotas[], int cantidad_mascotas){
    int contador1 = 0;
    int contador2= 0;
    for (int i = 0; i < cantidad_mascotas; i++)
    {
        if (mascotas[i].vacuna == "vacunado")
        {
            contador1++;
            
        }else {
            contador2++;
        }
        
    }
    
    std:: cout << "La cantidad de mascotas vacunadas es de: " << contador1 << '\n';
    std:: cout << "La cantidad de mascotas no vacunadas es de: " << contador2 << '\n';
}



int main(){
    int cantidad_mascotas;

    std:: cout << "Digite la cantidad de mascotas a ingresar: ";
    std:: cin >> cantidad_mascotas;

    Mascota mascotas[cantidad_mascotas];
    datos_Mascota(mascotas,cantidad_mascotas);
    mostrar_mascotas(mascotas,cantidad_mascotas);
    contarMascotas(mascotas,cantidad_mascotas);
    filtoporVacunacion(mascotas,cantidad_mascotas);
    actualizarEstadovac(mascotas,cantidad_mascotas);




    return 0;
}