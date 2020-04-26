#include <iostream>

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

int main(int argc, char const *argv[])
{
    int xA, xB;
    int a, p;

    std::cout << "Base: ";
    std::cin >> a;

    std::cout << "Modulo: ";
    std::cin >> p;

    std::cout << "Secreto de A: ";
    std::cin >> xA;

    std::cout << "Secreto de B: ";
    std::cin >> xB;

    int bA = quickExp(xA,a,p); 
    int bB = quickExp(xB,a,p);
    std::cout << "Intermedio A: " << bA << ", "<< "Intermedio B: " << bB << std::endl;
    std::cout << "Clave compartida: " << quickExp(xB,bA,p) << std::endl;

    return 0;
}
