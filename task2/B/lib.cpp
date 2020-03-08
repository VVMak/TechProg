#include "lib.h"

long long B::fib( int n )
{
    int f[3] = { 0, 1, 0 };
    for( int i = 2; i <= n; ++i ) {
        f[i % 3] = f[( i - 1 ) % 3] + f[( i - 2 ) % 3];
    }
    return f[n % 3];
}

