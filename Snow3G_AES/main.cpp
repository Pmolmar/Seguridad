#include <iostream>
#include <bitset>
#include <string>
#include <vector>

std::string multiplicacion(std::bitset<8> b1, std::bitset<8> b2, std::bitset<8> bA)
{
    std::vector<std::bitset<8>> v_aux;
    std::bitset<8> sol;

    for (int i = 0; i < 8; i++)
    {
        if (b2[i])
        {
            sol = b1;
            for (int j = 0; j < i; j++)
            {
                if (sol[sol.size() - 1])
                {
                    sol <<= 1;
                    sol = sol ^ bA;
                }
                else
                    sol <<= 1;
            }
            v_aux.push_back(sol);
        }
    }

    sol.reset();

    for (int i = 0; i < v_aux.size(); i++)
        sol ^= v_aux[i];

    return sol.to_string();
}

int main(int argc, char const *argv[])
{
    std::bitset<8> b1(87), b2(131), bA(std::string("10101001")); // A9"10101001" 1B"00011011"
    std::string mult;

    std::cout << "Byte 1: " << b1 << std::endl;
    std::cout << "Byte 2: " << b2 << std::endl;
    std::cout << "Byte algoritmo: " << bA << std::endl;

    (b1.count() < b2.count()) ? mult = multiplicacion(b1, b2, bA) : mult = multiplicacion(b2, b1, bA);

    std::cout << "Multiplicacion: " << mult << std::endl;

    return 0;
}