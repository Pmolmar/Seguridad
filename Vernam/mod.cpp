#include <iostream>
#include <fstream>

#include <vector>
#include <bitset>
#include <random>

void coder();
void decoder();
void coder_manual();

int main()
{
    int exit;

    std::cout << "-----Bienvenido a la maquina del CIFRADO DE VERNAM-----" << std::endl;
    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1- Codificar mesaje (aleatorio)." << std::endl;
        std::cout << "2- Decodificar mensaje." << std::endl;
        std::cout << "3- Listar archivos actuales." << std::endl;
        std::cout << "4- Codificar mensaje (teclado)." << std::endl;
        std::cout << "0- Salir." << std::endl;

        std::cout << "Introduzaca opcion:";
        std::cin >> exit;

        if (exit != 0)
        {
            system("clear");
            switch (exit)
            {
            case 1:
                coder();
                break;

            case 2:
                decoder();
                break;

            case 3:
                system("ls");
                break;

            case 4:
                coder_manual();
                break;

            default:
                std::cout << "Opcion no soportada." << std::endl;
                break;
            }
        }
    } while (exit != 0);

    return 0;
}

void coder()
{
    std::ofstream file;
    std::string message;
    std::vector<std::bitset<8>> binary, code;
    std::random_device rd;

    std::cin.ignore();

    //Introduccion del mensaje, traduccion y creacion de key
    std::cout << "Introduce mensaje:";
    std::getline(std::cin, message);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        //paso del mesaje a bits
        binary.push_back(std::bitset<8>(message.c_str()[i]));
        //genero key
        code.push_back(std::bitset<8>(rd()));
    }

    //Guardar la key
    std::cout << "Introduzca fichero para la key: ";
    std::getline(std::cin, message);
    file.open(message);

    for (std::size_t i = 0; i < code.size(); ++i)
    {
        file << code[i];
    }
    file.close();

    //XOR mensaje clave
    for (std::size_t i = 0; i < code.size(); ++i)
    {
        binary[i] = (binary[i] ^= code[i]);
    }

    //Guardar el mensaje
    std::cout << "Introduzca fichero para el mensaje: ";
    getline(std::cin, message);
    file.open(message);

    for (std::size_t i = 0; i < binary.size(); ++i)
    {
        file << binary[i];
    }
    file.close();
};

void decoder()
{
    std::string message;
    std::ifstream file;
    std::vector<std::bitset<8>> binary, code;
    char c;
    int i;
    std::string aux;

    std::cin.ignore();

    //Lectura de mensaje
    std::cout << "Introduzca fichero para el mensaje: ";
    getline(std::cin, message);
    file.open(message);

    i = 0;
    aux.clear();

    while (file.get(c))
    {
        if (i < 8)
        {
            aux.push_back(c);
            ++i;
        }
        else
        {
            binary.push_back(std::bitset<8>(aux));
            aux.clear();
            i = 1;
            aux.push_back(c);
        }
    }
    //mete la ultima linea del mensaje
    binary.push_back(std::bitset<8>(aux));

    file.close();

    //Lectura de llave
    std::cout << "Introduzca fichero para la key: ";
    getline(std::cin, message);
    file.open(message);

    i = 0;
    aux.clear();

    while (file.get(c))
    {
        if (i < 8)
        {
            aux.push_back(c);
            ++i;
        }
        else
        {
            code.push_back(std::bitset<8>(aux));
            aux.clear();
            i = 1;
            aux.push_back(c);
        }
    }
    //mete la ultima linea de la key
    code.push_back(std::bitset<8>(aux));

    file.close();

    //decodificacion
    //XOR clave mensaje
    for (std::size_t i = 0; i < binary.size(); ++i)
    {
        binary[i] = (code[i] ^= binary[i]);
    }

    //pasar de bits a string
    aux.clear();
    for (size_t i = 0; i < binary.size(); i++)
    {
        aux.push_back(static_cast<unsigned char>(binary[i].to_ulong()));
    }
    std::cout << aux << std::endl;
};

void coder_manual()
{
    std::ofstream file;
    std::string message, key;
    std::vector<std::bitset<8>> binary, code;

    std::cin.ignore();

    //Introduccion del mensaje, traduccion y creacion de key
    std::cout << "Introduce mensaje:";
    std::getline(std::cin, message);

    while (true)
    {
        std::cout << "Introduce key:";
        std::getline(std::cin, key);

        if (key.size() != message.size())
        {
            std::cout << "La key no tiene la misma longitud vuelva a introducirla." << std::endl;
        }
        else
        {
            break;
        }
    }

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        //paso del mesaje a bits
        binary.push_back(std::bitset<8>(message.c_str()[i]));
        //genero key
        code.push_back(std::bitset<8>(key.c_str()[i]));
    }

    //Guardar la key
    std::cout << "Introduzca fichero para la key: ";
    std::getline(std::cin, message);
    file.open(message);

    for (std::size_t i = 0; i < code.size(); ++i)
    {
        file << code[i];
    }
    file.close();

    //XOR mensaje clave
    for (std::size_t i = 0; i < code.size(); ++i)
    {
        binary[i] = (binary[i] ^= code[i]);
    }

    //Guardar el mensaje
    std::cout << "Introduzca fichero para el mensaje: ";
    getline(std::cin, message);
    file.open(message);

    for (std::size_t i = 0; i < binary.size(); ++i)
    {
        file << binary[i];
    }
    file.close();
};
