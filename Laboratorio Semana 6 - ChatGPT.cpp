#include <iostream>
#include <stdexcept>
#include <string>

// Estructura del nodo que conforma nuestra pila enlazada.
struct Node {
    char data;   // Caracter almacenado en el nodo.
    Node* next;  // Puntero al siguiente nodo en la pila.
};

// Inserta un nuevo caracter en la parte superior de la pila.
void push(Node*& top, char value) {
    Node* newNode = new Node{value, top};
    top = newNode;
}

// Retira el nodo superior de la pila y devuelve su caracter asociado.
// Precondición: la pila no debe estar vacía al invocar esta función.
char pop(Node*& top) {
    if (top == nullptr) {
        throw std::runtime_error("Intento de extraer un elemento de una pila vacía");
    }

    Node* nodeToRemove = top;
    char value = nodeToRemove->data;
    top = top->next;
    delete nodeToRemove;
    return value;
}

// Determina si la pila no contiene elementos.
bool isEmpty(const Node* top) {
    return top == nullptr;
}

// Invierte la cadena recibida utilizando la pila implementada con nodos enlazados.
std::string invertirCadena(const std::string& textoOriginal) {
    Node* stackTop = nullptr;

    // Carga todos los caracteres en la pila.
    for (char caracter : textoOriginal) {
        push(stackTop, caracter);
    }

    // Extrae los caracteres de la pila para reconstruir la cadena invertida.
    std::string textoInvertido;
    textoInvertido.reserve(textoOriginal.size());

    while (!isEmpty(stackTop)) {
        textoInvertido.push_back(pop(stackTop));
    }

    return textoInvertido;
}

int main() {
    std::string entradaUsuario;

    std::cout << "Ingrese una cadena de texto: ";
    std::getline(std::cin, entradaUsuario);

    try {
        const std::string textoInvertido = invertirCadena(entradaUsuario);
        std::cout << "Cadena invertida: " << textoInvertido << std::endl;
    } catch (const std::exception& error) {
        std::cerr << "Ocurrió un error: " << error.what() << std::endl;
        return 1;  // Finaliza con código de error.
    }

    return 0;  // Ejecución exitosa.
}
