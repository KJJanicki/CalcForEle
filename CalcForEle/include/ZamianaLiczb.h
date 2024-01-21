#pragma once
#include "pch.h"
#include <string>
class ZamianaLiczb
{
public:
    static std::string decimalToBinary(std::string num);
    static std::string decimalToOctal(std::string num);
    static std::string decimalToHexadecimal(std::string num);

    static std::string hexadecimalToDecimal(const std::string& hex);
    static std::string octalToDecimal(const std::string& octal);
    static std::string binaryToDecimal(const std::string& binary);

    bool isValidDecimal(const std::string& str);
    bool isValidBinary(const std::string& str);
    bool isValidOctal(const std::string& str);
    bool isValidHexadecimal(const std::string& str);
};

