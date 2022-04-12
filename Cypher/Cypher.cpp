#include <iostream>
#include <string>
#include <Windows.h>

std::string word_g{};
std::string reverse_g{};
std::string unreverse_g{};
std::string push_g{};
std::string decrypt_g{};

void reverse()
{
    std::cout << "Uncrypted Word: ";
    std::getline(std::cin, word_g);

    for (size_t i = word_g.length(); i > 0; i--)
    {
        reverse_g += word_g[i - 1];
    }
}
void encrypt()
{
    for (char i : reverse_g)
    {
        push_g += i + (365 - (reverse_g.length() % 100));
    }
    std::cout << "Encrypted Word: ";
    std::cout << push_g << "\n";
}

void decrypt()
{
    for (char j : push_g)
    {
        decrypt_g += j - (365 - push_g.length());
    }

    for (size_t i = decrypt_g.length(); i > 0; i--)
    {
        unreverse_g += decrypt_g[i - 1];
    }
    std::cout << "Decrypted Word: ";
    std::cout << unreverse_g << "\n\n";
}

void Clear()
{
    word_g.clear();
    push_g.clear();
    decrypt_g.clear();
    reverse_g.clear();
    unreverse_g.clear();
}

int main()
{

    while (1)
    {
        reverse();
        encrypt();
        decrypt();
        Clear();
        Sleep(1);
    }
}
