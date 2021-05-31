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
        while (n > 1) {
            c = a + b;
            a = b;
            b = c;
            n --;
        }
    return c;
}
int main() {
    cout << "Hello, World!" << endl;
    cout << "Which FibonacciRecursion Numbers do you want?";
    int n;
    cin >> n;
    clock_t start,end;
    start=clock();
    cout << "Recursion FibonacciRecursion(" << n << ") = " << FibonacciRecursion(n) << endl;
    end=clock();
    cout<<"Recursion FibonacciRecursion was running for "<<(double)(end-start)/CLOCKS_PER_SEC<< " s" <<endl;
    start=clock();
    cout << "Iteration FibonacciRecursion(" << n << ") = " << FibonacciIteration(n) << endl;
    end=clock();
    cout<<"Recursion FibonacciRecursion was running for "<<(double)(end-start)/CLOCKS_PER_SEC<< " s" <<endl;
    return 0;
}
