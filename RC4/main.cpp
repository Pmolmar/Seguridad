#include <iostream>

#include <random>
#include <bitset>

#define SIZE 256

int main(int argc, char const *argv[])
{
    std::string str;
    std::cout << "Introduzca una semilla: ";
    std::getline(std::cin, str);
    std::seed_seq seed(str.begin(), str.end());

    std::default_random_engine rd(seed);
    const int key = rd() % SIZE;

    std::cout << "Introduzca unmensaje: ";
    std::getline(std::cin, str);

    int S[SIZE], K[SIZE];

    for (size_t i = 0; i < SIZE - 1; i++)
    {
        S[i] = i;
        K[i] = str[i % key];
    }
    int j = 0;

    for (size_t i = 0; i < SIZE - 1; i++)
    {
        j = (j + S[i] + K[i]) % SIZE;
        int x = S[i];
        S[i] = S[j];
        S[j] = x;
    }

    int i = j = 0;
    for (size_t s = 0; s < str.length(); s++)
    {
        i = i + 1 % SIZE;
        j = (j + S[i]) % SIZE;
        int x = S[i];
        S[i] = S[j];
        S[j] = x;
        int t = (S[i] + S[j]) % SIZE;
        std::cout << std::hex << std::bitset<8>(S[t]).to_ulong();
    }

    return 0;
}
