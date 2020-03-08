#include "main.h"

int main()
{
    A a;
    B b; 
    std::cout << a.gcd( b.fib( 16 ), b.fib( 12 ) ) << '\n';
    return 0;
}
