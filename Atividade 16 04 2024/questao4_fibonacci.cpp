#include <iostream>

using namespace std;

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


int main(){
        
    int n;
    cout << "Digite o valor de N: ";
    cin >> n;
    cout << "O valor de X na posição N da sequência de fibonacci_iterativo é: " << fibonacci_iterativo(n) << endl;
    cout << "O valor de X na posição N da sequência de fibonacci_recurssivo é: " << fibonacci_recursivo(n) << endl;
    


    return 0;
}