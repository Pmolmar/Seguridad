#include <iostream>
#include <bitset>

#define SALIDA 4

template <size_t bitsetsize>
void lsfr(std::bitset<bitsetsize> &p)
{
    std::bitset<1> at;

    if (p.size() == 25)
        at = p[7] ^ p[11] ^ p[19] ^ p[24];
    if (p.size() == 31)
        at = p[11] ^ p[16] ^ p[23] ^ p[30];
    if (p.size() == 33)
        at = p[3] ^ p[23] ^ p[27] ^ p[32];
    if (p.size() == 39)
        at = p[3] ^ p[27] ^ p[35] ^ p[38];
    p <<= 1;
    p[0] = at[0];
};

std::bitset<1> desplazamiento(std::bitset<25> &p1, std::bitset<31> &p2, std::bitset<33> &p3, std::bitset<39> &p4, std::bitset<2> &R)
{
    //primero pasar inverso a una var R1/aux, normal R2
    std::bitset<2> R2 = R;
    R = R.flip();
   
    int suma = int(p1[0] + p2[0] + p3[0] + p4[0]);
    suma += int(R.to_ulong());

    std::bitset<1>z =p1[0] ^ p2[0] ^ p3[0] ^ p4[0] ^ R[0];
    
    lsfr(p1);
    lsfr(p2);
    lsfr(p3);
    lsfr(p4);

    // std::bitset<2> T1 no lo uso porque es igual a R1
    std::bitset<2> T2;
    T2[0] = R2[0];
    T2[1] = R2[0] ^ R2[1];
    R2 = T2;

    std::bitset<2> aux;
    std::bitset<3> aux1 = suma;
    aux[0] = aux1[1];
    aux[1] = aux1[2];

    aux ^= R2;
    R ^= aux;
    return z;
};

int main(int argc, char const *argv[])
{
    std::bitset<25> reg_first(std::string("0111111111111111111111111"));                //p=8+12+20+25
    std::bitset<31> reg_second(std::string("0111111111111111111111111111111"));         //p=12+16+24+31
    std::bitset<33> reg_third(std::string("011111111111111111111111111111111"));        //p=4+24+28+33
    std::bitset<39> reg_fourth(std::string("010101010101010101010101010101010101010")); //p=4+28+36+39

    std::bitset<2> R1(std::string("01"));

    std::bitset<SALIDA> Z;

    for (size_t i = 0; i < SALIDA; i++)
    {
        Z[i] = desplazamiento(reg_first, reg_second, reg_third, reg_fourth, R1)[0];
    }

    std::cout << Z << std::endl;
    return 0;
}
