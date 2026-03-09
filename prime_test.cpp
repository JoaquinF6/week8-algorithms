#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

bool millerTest(long long d, long long n) {

    long long a = 2 + rand() % (n - 4);
    long long x = modPow(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {

        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;

        if (x == n - 1)
            return true;
    }

    return false;
}

bool isPrime(long long n, int k) {

    if (n <= 1 || n == 4)
        return false;

    if (n <= 3)
        return true;

    long long d = n - 1;

    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

int main() {

    srand(time(0));

    long long number;
    cout << "Ingrese un numero: ";
    cin >> number;

    int tests = 5;

    if (isPrime(number, tests))
        cout << number << " probablemente es primo\n";
    else
        cout << number << " es compuesto\n";

    return 0;
}
