#include <iostream>

// Función recursiva para contar los dígitos de un número
int contarDigitos(int num) {
    // Caso base: si el número es 0, no tiene más dígitos
    if (num == 0)
        return 0;
    // Llamada recursiva: cuenta 1 dígito y divide entre 10
    return 1 + contarDigitos(num / 10);
}

int main() {
    int num;
    std::cout << "Digite un numero" << '\n';
    std::cin >> num;

    std::cout << "El número " << num << " tiene " << contarDigitos(num) << " dígitos." << std::endl;
    return 0;
}
