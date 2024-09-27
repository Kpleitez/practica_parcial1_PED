#include <iostream>

// Función recursiva para sumar los elementos de un arreglo
int sumaArreglo(int arr[], int n) {
    // Caso base: cuando el tamaño del arreglo es 0, la suma es 0
    if (n == 0)
        return 0;
    // Llamada recursiva: suma el último elemento con la suma del resto
    return arr[n-1] + sumaArreglo(arr, n-1);
}

int main() {
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]); // Tamaño del arreglo
    std::cout << "La suma de los elementos del arreglo es: " << sumaArreglo(arr, n) << std::endl;
    return 0;
}

