#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacci_recursivo(int n){
    if (n <= 1) {
        return n; // Casos base: Fibonacci(0) = 0, Fibonacci(1) = 1
    } else {
        return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2); // Recursão
    }
}

int fibonacci_iterativo(int n){
    
        int a = 0, b = 1, c;
    
        if(n == 0){
            return a;
        }
    
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
    
        return b;
    
}


int main() {
    // Testar os algoritmos Fibonacci para diferentes valores de n
    for (int n = 0; n <= 30; n++) {
        auto start_iterativo = high_resolution_clock::now();
        int fib_iterativo = fibonacci_iterativo(n);
        auto stop_iterativo = high_resolution_clock::now();
        auto duration_iterativo = duration_cast<microseconds>(stop_iterativo - start_iterativo);

        auto start_recursivo = high_resolution_clock::now();
        int fib_recursivo = fibonacci_recursivo(n);
        auto stop_recursivo = high_resolution_clock::now();
        auto duration_recursivo = duration_cast<microseconds>(stop_recursivo - start_recursivo);

        cout << "n = " << n << endl;
        cout << "Fibonacci Iterativo: " << fib_iterativo << " Tempo: " << duration_iterativo.count() << " microssegundos" << endl;
        cout << "Fibonacci Recursivo: " << fib_recursivo << " Tempo: " << duration_recursivo.count() << " microssegundos" << endl;
        cout << endl;
    }

    return 0;
}
