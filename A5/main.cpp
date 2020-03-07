#include <iostream>

#include <bitset>
#include <vector>

//---------------------------------------
std::bitset<1> lsfr_1(std::bitset<19> &p)
{
    std::bitset<1> at = p[18] + p[17] + p[16] + p[13];
      p<<=1;
    p[0] = at[0];
    return at;
};
std::bitset<1> lsfr_2(std::bitset<22> &p)
{
    std::bitset<1> at = p[21] + p[20];
      p<<=1;
    p[0] = at[0];
    return at;
};
std::bitset<1> lsfr_3(std::bitset<23> &p)
{
    std::bitset<1> at = p[22] + p[21] + p[20] + p[7];
    p<<=1;
    p[0] = at[0];
    return at;
};

//---------------------------------------
std::bitset<1> desplazamiento(std::bitset<19> &p1, std::bitset<22> &p2, std::bitset<23> &p3)
{
    std::bitset<1> a,b,c;

    if (p1[8] == p2[10] == p3[10])
    {
        a = lsfr_1(p1);
        b = lsfr_2(p2);
        c = lsfr_3(p3);
    }
    else if (p1[8] == p2[10])
    {
        a = lsfr_1(p1);
        b = lsfr_2(p2);
    }
    else if (p1[8] == p3[10])
    {
        a = lsfr_1(p1);
        c = lsfr_3(p3);
    }
    else
    {
        b = lsfr_2(p2);
        c = lsfr_3(p3);
    }

    return(a^b^c);
};

//---------------------------------------
int main(int argc, char const *argv[])
{
    std::bitset<19> p1(std::string("1001000100011010001"));
    std::bitset<22> p2(std::string("0101100111100010011010"));
    std::bitset<23> p3(std::string("10111100110111100001111"));

    std::cout << p1 << std::endl;

    //bucle 6 movimientos como en el pdf
    for (int i = 0; i < 6; i++)
    {
      std::cout << desplazamiento(p1, p2, p3);
    }

    std::cout << std::endl;
    std::cout << p1 << std::endl;

    return 0;
};