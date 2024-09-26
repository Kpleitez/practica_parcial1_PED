#include "iostream"



int main (){

   int tamano, *arreglo;
   
   /*int valor;
   int *puntero;

   std::cout << "Digite un valor: " <<'\n';
   std::cin >> valor;
   puntero = &valor;



   std::cout << "El valor de la variable es: " << valor << '\n';
   std::cout << "El valor almacenado en la direccion en la que apunta el puntero es: " << *puntero << '\n';*/
   std::cout << "Digite la dimencion del arreglo: "; 
   std::cin >> tamano;

   arreglo = new int [tamano];

   for (int i = 0; i < tamano; i++)
   {
    std::cout << "Ingrese un valor para la posicion " << i + 1 << ": ";
    std:: cin >> arreglo[i];
   }
   
   std:: cout << "Los valores ingresados son: " << '\n';
   for (int i = 0; i < tamano; i++)
   {
    std:: cout << arreglo[i] << " ";
   }
   std:: cout << '\n';


   delete[] arreglo;


    return 0;
}