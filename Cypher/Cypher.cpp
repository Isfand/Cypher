#include <iostream>
#include <string>
#include <Windows.h>

std::string word{};
std::string reverse{};
std::string unreverse{};
std::string push{};
std::string decrypt{};

void Encrypt()
{
    std::cout << "Uncrypted Word: ";
    std::getline(std::cin, word);

    for (size_t i = word.length(); i > 0; i--)
    {
        reverse += word[i - 1];
    }

    for (char i : reverse)
    {
        push += i + (365 - (reverse.length() % 100));
    }
    std::cout << "Encrypted Word: ";
    std::cout << push << "\n";
}

void Decrypt()
{
    for (char j : push)
    {
        decrypt += j - (365 - push.length());
    }

    for (size_t i = decrypt.length(); i > 0; i--)
    {
        unreverse += decrypt[i - 1];
    }
    std::cout << "Decrypted Word: ";
    std::cout << unreverse << "\n\n";
}

void Clear()
{
    word.clear();
    push.clear();
    decrypt.clear();
    reverse.clear();
    unreverse.clear();
}

int main()
{

    while (1)
    {
        Encrypt();
        Decrypt();
        Clear();
        Sleep(1);
    }
}
