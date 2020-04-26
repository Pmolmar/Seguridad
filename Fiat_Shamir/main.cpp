#include <iostream>
#include <random>

int quickExp(int x, int a, int p)
{
    int aux = 1;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            --x;
            aux = (aux * a) % p;
        }
        else
        {
            x /= 2;
            a = (a * a) % p;
        }
    }
    return aux;
}

int main()
{
    srand(1999);
    int p, q, N, s, v, x, a, e, y, i;
    std::cout << "Secreto p: ";
    std::cin >> p;

    std::cout << "Secreto q: ";
    std::cin >> q;

    N = p * q;
    std::cout << "Multiplicacion publica " << N << std::endl;

    std::cout << "Numero primo entre 0 y " << N << ": ";
    std::cin >> s;

    v = quickExp(2, s, N);
    std::cout << "Identificador publico de A " << v << std::endl;

    std::cout << "Numero de iteraciones: ";
    std::cin >> i;

    for (int j = 0; j < i; j++)
    {
        std::cout << "Numero secreto entre 0 y " << N << ": ";
        std::cin >> x;

        a = quickExp(2, x, N);
        std::cout << "Testigo " << a << std::endl;

        //b envia a A un bit elegido al azar
        e = rand() % 1;
        if (e == 0)
        {
            y = x % N;
            if (y ^ 2 == a % N)
                std::cout << "Succes" << std::endl;
        }
        else
        {
            y = (x * s) % N;
            if (y ^ 2 == (a * v) % N)
                std::cout << "Succes" << std::endl;
        }
    }

    return 0;
}
