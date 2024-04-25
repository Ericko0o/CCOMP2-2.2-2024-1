#include <iostream>
#include <string>

// Función para determinar si un carácter es una letra del alfabeto (mayúscula o minúscula)
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Función para convertir un carácter a minúsculas
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Función recursiva para verificar si una cadena es un palíndromo
bool testPalindrome(const std::string& str, int start, int end) {
    // Caso base: cuando hemos revisado todos los caracteres
    if (start >= end) {
        return true;
    }

    // Ignoramos los caracteres de puntuación y los espacios
    while (start < end && !isLetter(str[start])) {
        start++;
    }
    while (start < end && !isLetter(str[end])) {
        end--;
    }

    // Convertimos ambos caracteres a minúsculas para hacer la comparación sin distinción de mayúsculas y minúsculas
    char char1 = toLower(str[start]);
    char char2 = toLower(str[end]);

    // Si los caracteres son diferentes, no es un palíndromo
    if (char1 != char2) {
        return false;
    }

    // Llamada recursiva con los índices actualizados
    return testPalindrome(str, start + 1, end - 1);
}

int main() {
    std::string sentence = "las rosas rojas no corren ningún riesgo, señor, para las enfermeras";
    
    // Llamada a la función para verificar si la cadena es un palíndromo
    bool isPalindrome = testPalindrome(sentence, 0, sentence.length() - 1);
    
    if (isPalindrome) {
        std::cout << "La oración es un palíndromo." << std::endl;
    } else {
        std::cout << "La oración no es un palíndromo." << std::endl;
    }

    return 0;
}
