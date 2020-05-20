#include <iostream>
#include <random>
#include <math.h>
#include <vector>
#include <algorithm>

#define BASE 26

long int quickExp(long int a, long int x, long int p)
{
    long int aux = 1;
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

bool lemanPeralta(int primo)
{
    int s[5] = {2, 3, 5, 7, 11}, r[100];
    bool pos = false, neg = false;

    for (int i = 0; i < 5; i++)
        if (primo % s[i] == 0)
            return false;

    for (int i = 0; i < 100; i++)
    {
        r[i] = rand() % primo;

        if (quickExp(r[i], (primo - 1) / 2, primo) == 1)
            pos = true;

        if (quickExp(r[i], (primo - 1) / 2, primo) == -1)
            neg = true;
    }

    if (pos && neg)
        return false;

    return true;
}

long int euclides(int a, int b)
{
    if (a > b)
    {
        int aux_a = a, r = 1, r_old = 0;

        while (b != 0)
        {
            int aux_r = r;
            r = (-(a / b) * r + r_old);
            r_old = aux_r;

            int aux_b = b;
            b = a % b;
            a = aux_b;
        }

        if (a == 1)
            return (r_old + aux_a) % aux_a;
        else
            return -1;
    }
    else
        return -1;
}

int findJ(int n)
{
    for (int j = 0; j < n; j++)
        if ((pow(BASE, j - 1) < n) && (n < pow(BASE, j)))
            return j;
}

std::vector<std::vector<long int>> separador(int j, std::string msj)
{
    std::vector<std::vector<long int>> bloques;
    for (int i = 0; i < msj.size(); i += (j - 1))
    {
        std::vector<long int> aux;
        for (int k = 0; k < j - 1; k++)
            (k + i < msj.size()) ? aux.push_back(int(msj[k + i] - 65)) : aux.push_back(int('X' - 65));

        bloques.push_back(aux);
    }
    return bloques;
}

std::vector<long int> cifrar(std::vector<std::vector<long int>> bloques, long int e, int n)
{
    std::vector<long int> aux;
    for (int i = 0; i < bloques.size(); i++)
    {
        long int sum = 0;
        for (int j = 0; j < bloques[i].size(); j++)
        {
            sum += bloques[i][j] * pow(BASE, bloques[i].size() - (j + 1));
        }
        aux.push_back(quickExp(sum, e, n));
    }
    return aux;
}

int main(int argc, char const *argv[])
{
    int p, q, o, d, n;
    std::string msj;

    //pedir datos
    std::cout << "Introduzca p: ";
    std::cin >> p;

    std::cout << "Introduzca q: ";
    std::cin >> q;

    std::cout << "Introduzca d: ";
    std::cin >> d;

    std::cout << "Introduzca mensaje: ";
    std::cin.ignore();
    std::getline(std::cin, msj);
    //borrar espacios
    msj.erase(std::remove_if(msj.begin(), msj.end(), ::isspace), msj.end());

    //procesar
    o = (p - 1) * (q - 1);
    n = p * q;
    int j = findJ(n);
    long int e = euclides(o, d);

    std::cout << std::endl;
    (lemanPeralta(p) && lemanPeralta(q)) ? std::cout << "P y Q son primos" << std::endl : std::cout << "P y Q NO son primos" << std::endl;
    std::cout << "Tamano bloques: " << j - 1 << ", Euclides: " << e << ", N: " << n << ", Omega: " << o << std::endl;
    std::cout << std::endl;

    std::vector<std::vector<long int>> bloques = separador(j, msj);

    std::vector<long int> codificado = cifrar(bloques, e, n);

    std::cout << "Cifrado: ";
    for (int i = 0; i < codificado.size() - 1; i++)
        std::cout << codificado[i] << ", ";

    std::cout << codificado[codificado.size() - 1] << std::endl;

    std::cout << "Descifrado: ";
    for (int i = 0; i < codificado.size() - 1; i++)
        std::cout << quickExp(codificado[i], d, n) << ", ";

    std::cout << quickExp(codificado[codificado.size() - 1], d, n) << std::endl;

    return 0;
}
