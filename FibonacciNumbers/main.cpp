#include <iostream>
using namespace std;
int FibonacciRecursion(int n){
    if ( ( n == 0 ) || ( n == 1 ) )
        return n;
    else
        return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

int FibonacciIteration(int n){
    static int a = 0, b = 1, c;
    if ( ( n == 0 ) || ( n == 1 ) )
        return n;
    else
        for (int i = 1; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
    return c;
}
int main() {
    cout << "Hello, World!" << endl;
    cout << "Which FibonacciRecursion Numbers do you want?";
    int n;
    cin >> n;
    cout << "Recursion FibonacciRecursion(" << n << ") = " << FibonacciRecursion(n) << endl;
    cout << "Iteration FibonacciRecursion(" << n << ") = " << FibonacciIteration(n) << endl;

    return 0;
}
