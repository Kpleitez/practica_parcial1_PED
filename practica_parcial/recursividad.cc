#include "iostream"

int Decimal_Binario(int n) {

    if (n == 0) {
        return; // Caso base o condición de paro
    } 
    
        return Decimal_Binario(n/2); // Llamada recursiva
    
}



int main (){

    int numero; 
    std::cout << "Digite un numero entero: " ;
    std::cin>> numero;


    Decimal_Binario(numero);
    return 0;
}