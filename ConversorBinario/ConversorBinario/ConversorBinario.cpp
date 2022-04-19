// ConversorBinario.cpp

//there are many ways to do it easily, but I wanted
//to make a code that converted decimal to hexadecimal 
//and binary like humans usually do

#include <iostream>
#include <cmath>
#include <string>

float GetDecimals(float n)
{
    return n - (int)n;
}

std::string convertNumbers(int num)
{
    switch (num)
    {
    case 10:
        return "A";
    case 11:
        return "B";
    case 12:
        return "C";
    case 13:
        return "D";
    case 14:
        return "E";
    case 15:
        return "F";
    default:
        return std::to_string(num);
    }
}

std::string reverseString(std::string string)
{
    std::string final;
    for (int i = string.length(); i >= 0; i--)
    {
        final += string[i];
    }
    return final;
}

std::string ToBinary(int number)
{
    float result = number;
    std::string output;

    while (result > 1)
    {
        result = (int)result;
        result = result / 2;

        if (GetDecimals(result) != 0)
        {
            output += '1';
            continue;
        }

        output += '0';
    }

    if (result > 0)
        output += '1';

    return reverseString(output);
}

std::string ToHex(int number)
{
    float result = number;
    std::string output;

    while (result > 15)
    {
        result = result / 16;
        float decimals = GetDecimals(result) * 16;
        result = (int)result;

        output += " " + convertNumbers((int)decimals);
    }

    output += " " + convertNumbers((int)result);

    return reverseString(output);
}

int main()
{
    while (true)
    {
        std::cout << "Escolha um numero-> ";

       int input;
        std::cin >> input;

        std::cout << "Binario: \n";
        std::cout << ToBinary(input) << std::endl;
        std::cout << "Hex: \n";
        std::cout << ToHex(input) << std::endl;
    }
}
