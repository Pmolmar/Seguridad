#include <iostream>

int main(int argc, char const *argv[])
{
    int op = 1;

    while (op != 0)
    {
        std::cout << "----Menu----" << std::endl
                  << "1.- A5" << std::endl
                  << "2.- Bluethooth_E0" << std::endl
                  << "3.- DiffieHellman" << std::endl
                  << "4.- Fiat_Shamir" << std::endl
                  << "5.- RC4" << std::endl
                  << "6.- Rijndael" << std::endl
                  << "7.- RSA" << std::endl
                  << "8.- Snow3G_AES" << std::endl
                  << "9.- Vernam" << std::endl
                  << "10.- Vigenere" << std::endl
                  << "0.- Para salir" << std::endl
                  << "------------------------" << std::endl
                  << "Introduzca opcion: " << std::endl;
        std::cin >> op;
        system("clear");

        switch (op)
        {
        case 0:
            std::cout << "Finalizando . . ." << std::endl;
            break;

        case 1:
            std::cout << "---A5---" << std::endl;
            system("./A5/a.out");
            break;

        case 2:
            std::cout << "---Bluethooth_E0---" << std::endl;
            system("./Bluethooth_E0/a.out");
            break;

        case 3:
            std::cout << "---DiffieHellman---" << std::endl;
            system("./DiffieHellman/a.out");
            break;

        case 4:
            std::cout << "---Fiat_Shamir---" << std::endl;
            system("./Fiat_Shamir/a.out");
            break;

        case 5:
            std::cout << "---RC4---" << std::endl;
            system("./RC4/a.out");
            break;

        case 6:
            std::cout << "---Rijndael---" << std::endl;
            system("./Rijndael/a.out");
            break;

        case 7:
            std::cout << "---RSA---" << std::endl;
            system("./RSA/a.out");
            break;

        case 8:
            std::cout << "---Snow3G_AES---" << std::endl;
            system("./Snow3G_AES/a.out");
            break;

        case 9:
            std::cout << "---Vernam---" << std::endl;
            system("./Vernam/a.out");
            break;

        case 10:
            std::cout << "---Vigenere---" << std::endl;
            system("./Vigenere/a.out");
            break;

        default:
            std::cout << "Opcion no valida intente de nuevo." << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}
