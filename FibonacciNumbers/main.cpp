#include <iostream>
using namespace std;
unsigned long FibonacciRecursion(unsigned long n){
    if ( ( n == 0 ) || ( n == 1 ) )
        return n;
    else
        return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

unsigned long  FibonacciIteration(unsigned long  n){
    static unsigned long  a = 0, b = 1, c;
    if ( ( n == 0 ) || ( n == 1 ) )
        return n;
    else
        while (n > 1) {
            c = a + b;
            a = b;
            b = c;
            n --;
        }
    return c;
}
int main() {
    cout << "Which FibonacciRecursion Numbers do you want?" << endl;
    int n;
    cin >> n;
    clock_t start,end;
    start=clock();
    cout << "Recursion Fibonacci(" << n << ") = " << FibonacciRecursion(n) << endl;
    end=clock();
    cout<<"Recursion Fibonacci() was running for "<<(double)(end-start)/CLOCKS_PER_SEC<< " s" <<endl;
    start=clock();
    cout << "Iteration Fibonacci(" << n << ") = " << FibonacciIteration(n) << endl;
    end=clock();
    cout<<"Iteration Fibonacci() was running for "<<(double)(end-start)/CLOCKS_PER_SEC<< " s" <<endl;
    return 0;
}
