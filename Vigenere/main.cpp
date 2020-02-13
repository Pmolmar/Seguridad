#include <iostream>

#include <vector>

const int ALF_SIZE = 26;

void coder();
void decoder();

int main(int argc, char const *argv[])
{

    int exit;

    std::cout << "-----Bienvenido a la maquina del CIFRADO DE VIGENERE-----" << std::endl;
    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1- Codificar mesaje." << std::endl;
        std::cout << "2- Decodificar mensaje." << std::endl;
        std::cout << "3- Listar archivos actuales." << std::endl;
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
    std::string message;
    std::string key;
    std::vector<int> message_int, key_int, coded;

    std::cin.ignore();

    std::cout << "Introduzca el mensaje:";
    getline(std::cin, message);

    std::cout << "Introduzca la key:";
    getline(std::cin, key);

    //convertir a decimal, le resto 96 para que 'a'==1
    for (size_t i = 0; i < message.size(); i++)
    {
        message_int.push_back(int(message[i]) - 97);
    }

    for (size_t i = 0; i < key.size(); i++)
    {
        key_int.push_back(int(key[i]) - 97);
    }

    //realizar suma y el modulo del alfabeto
    unsigned int i = 0;
    while ((i <= message_int.size() && i != key_int.size()) || 
    (i <= key_int.size() && i != message_int.size()))
    {
        coded.push_back((message_int[i % message_int.size()] + key_int[i % key_int.size()]) % ALF_SIZE);
        ++i;
    }

    //convertir coded a caracter de nuevo
    for (size_t i = 0; i < coded.size(); i++)
    {
        std::cout << char(coded[i] +97);
    }
    std::cout<<std::endl;

    //guardar nuevo mensaje en fichero
}

void decoder()
{
    //pedir fichero de mensaje y llave

    //descifrar y mostrar por pantalla
}
