#include <iostream>
using namespace std;
int Fibonacci(int n){
    if ( ( n == 0 ) || ( n == 1 ) )
        return n;
    else
        return Fibonacci( n - 1 ) + Fibonacci( n - 2 );
}
int main() {
    cout << "Hello, World!" << endl;
    cout << "Which Fibonacci Numbers do you want?";
    int n;
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << Fibonacci(n);
    return 0;
}
