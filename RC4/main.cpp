#include <iostream>

#include <random>
#include <vector>
#include <bitset>

#define SIZE 256

void ksa(std::vector<int> &S, std::string &str)
{
    std::vector<int> K(SIZE);
    int j = 0;

    for (size_t i = 0; i < SIZE; i++)
    {
        S[i] = i;
        K[i] = str[i % str.length()];
    }
    std::cout << K[0];

    for (size_t i = 0; i < SIZE; i++)
    {
        j = (j + S[i] + K[i]) % SIZE;
        std::swap(S[i], S[j]);
    }
};

int prga(std::vector<int> &S, int &i, int &j)
{
    i = i + 1 % SIZE;
    j = (j + S[i]) % SIZE;
    std::swap(S[i], S[j]);

    int t = (S[i] + S[j]) % SIZE;
    return S[j];
};

std::string cifrar(std::vector<int> &S, std::string &str)
{
    int i = 0, j = 0;
    std::string aux = str;

    for (size_t k = 0; k < str.length(); k++)
    {
        char x = prga(S, i, j);
        aux[i] = str[i] ^ x;
    }
    
    return aux;
};

int main(int argc, char const *argv[])
{
    std::string str;
    std::vector<int> S(SIZE);

    std::cout << "Introduzca una semilla: ";
    std::getline(std::cin, str);
    std::seed_seq seed(str.begin(), str.end());

    std::default_random_engine rd(seed);
    const int key = rd();

    std::cout << "Introduzca un mensaje: ";
    std::getline(std::cin, str);

    std::string aux = std::to_string(key);
    ksa(S, aux);
    str = cifrar(S, str);
    std::cout << "Mensaje cirfrado: ";
    for (int i = 0; i < str.length(); i++)
    {
        std::cout << std::hex << std::bitset<8>(str[i]).to_ulong();
    }

    std::cout << std::endl;

    S.clear();
    ksa(S, aux);
    str = cifrar(S, str);
    std::cout << "Mensaje descifrado: " << str << std::endl;

    return 0;
};