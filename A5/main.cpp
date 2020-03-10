#include <iostream>

#include <bitset>
#include <vector>

//---------------------------------------
template <size_t bitsetsize>
void lsfr(std::bitset<bitsetsize> &p)
{
    std::bitset<1> at;

    if (p.size() == 19)
        at = p[18] ^ p[17] ^ p[16] ^ p[13];
    if (p.size() == 22)
        at = p[21] ^ p[20];
    if (p.size() == 23)
        at = p[22] ^ p[21] ^ p[20] ^ p[7];

    p <<= 1;
    p[0] = at[0];
};
//---------------------------------------
void desplazamiento(std::bitset<19> &p1, std::bitset<22> &p2, std::bitset<23> &p3)
{
    std::bitset<1> mayoria = p1[8] * p2[10] ^ p1[8] * p3[10] ^ p2[10] * p3[10];

    if (p1[8] == mayoria[0])
        lsfr(p1);
    if (p2[10] == mayoria[0])
        lsfr(p2);
    if (p3[10] == mayoria[0])
        lsfr(p3);
};
//---------------------------------------
int main(int argc, char const *argv[])
{
    std::bitset<19> p1(std::string("1001000100011010001"));
    std::bitset<22> p2(std::string("0101100111100010011010"));
    std::bitset<23> p3(std::string("10111100110111100001111"));

    std::cout << "Original:" << std::endl
              << p1 << std::endl
              << p2 << std::endl
              << p3 << std::endl
              << std::endl;

    std::bitset<6> x;

    for (int i = 0; i < 6; i++)
    {
        x[6 - 1 - i] = p1[18] ^ p2[21] ^ p3[22];
        if (i != 5)
            desplazamiento(p1, p2, p3);
    }
    std::cout << "Z:" << x << std::endl
              << std::endl;

    std::cout << "Desplazados:" << std::endl;
    std::cout << p1 << std::endl
              << p2 << std::endl
              << p3 << std::endl;

    return 0;
};