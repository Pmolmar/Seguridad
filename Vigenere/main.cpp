#include <iostream>

#include <fstream>
#include <vector>
#include <algorithm>

const int ALF_SIZE = 26;
const int CASE = 65; //65 mayusculas, 75 minusculas

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
    std::ofstream file;
    std::string message, key, name;
    std::vector<int> message_int, key_int, coded;

    std::cin.ignore();

    std::cout << "Introduzca el mensaje (MAYUSCULAS):";
    getline(std::cin, message);
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());

    std::cout << "Introduzca la key (MAYUSCULAS):";
    getline(std::cin, key);

    //pedir ficheros de key y codificado, guardar la key
    std::cout << "Introduzca fichero para la key: ";
    getline(std::cin, name);
    file.open(name);
    file << key;
    file.close();

    std::cout << "Introduzca fichero para el mensaje codificado: ";
    getline(std::cin, name);
    file.open(name);

    //convertir a decimal, le resto CASE para que 'A'==0 resot 97 para 'a'==0
    for (size_t i = 0; i < message.size(); i++)
    {
        message_int.push_back(int(message[i]) - CASE);
    }

    for (size_t i = 0; i < key.size(); i++)
    {
        key_int.push_back(int(key[i]) - CASE);
    }

    //realizar suma y el modulo del alfabeto
    unsigned int i = 0;
    while (i < message_int.size() || i < key_int.size())
    {
        coded.push_back((message_int[i % message_int.size()] + key_int[i % key_int.size()]) % ALF_SIZE);
        ++i;
    }

    //convertir coded a caracter de nuevo
    for (size_t i = 0; i < coded.size(); i++)
    {
        std::cout << char(coded[i] + CASE);
        //guardar nuevo mensaje en fichero
        file << char(coded[i] + CASE);
    }
    file.close();
    std::cout << std::endl;
}

void decoder()
{
    std::ifstream file;
    std::string coded, key, message, name;

    std::cin.ignore();

    //pedir fichero de mensaje y llave
    std::cout << "Introduzca fichero para la key: ";
    getline(std::cin, name);
    file.open(name);
    file >> key;
    file.close();

    std::cout << key << std::endl;

    std::cout << "Introduzca fichero para el mensaje: ";
    getline(std::cin, name);
    file.open(name);
    file >> coded;
    file.close();

    std::cout << coded << std::endl;

    //descifrar y mostrar por pantalla
    std::cout << "Mensaje descifrado: ";

    int i = 0;
    while (i < coded.size() || i < key.size())
    {
        int aux = (coded[i % coded.size()] - key[i % key.size()]);
        if (aux < 0)
            aux = aux + ALF_SIZE + CASE;
        else
            aux = aux + CASE;
        
        message.push_back(char(aux));
        ++i;
    }

    std::cout << message << std::endl;
}
