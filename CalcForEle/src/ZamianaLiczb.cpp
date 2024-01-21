#include "pch.h"
#include "ZamianaLiczb.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

char mapNumberToCharacter(int number) {     //funkcja mapuje liczbê na odpowiadaj¹cy jej znak w systemie szesnastkowym
    if (number > 9) {    //sprawdzanie czy liczba jest wieksza niz 9 (czyli A-F w systemie 16-stkowym)
        return 'A' + (number - 10);     //jesli tak, zwroci znak A-F
    }
    return '0' + number;    //jeœli liczba jest mniejsza lub rowna 9, zwroci odpowiadajaca jej cyfre jako znak
}

int mapCharacterToNumber(char character) {  //funkcja mapuje znak na odpowiadaj¹c¹ mu liczbê w systemie szesnastkowym
    if (character >= 'A' && character <= 'F') { //sprawdziani czy znak jest w przedziale od A do F
        return character - 'A' + 10;    //jesli tak, zwroci odpowiadajaca mu liczbe (gdzie A to 10) 
    }
    return character - '0'; //jesli znak jest w zakresie od 0 do 9, zwroci odpowiadajaca mu liczbe
}

std::string ZamianaLiczb::decimalToBinary(std::string decimalNum) {
    int integerNum = std::stoi(decimalNum);     //zamiana string na int
    std::string binaryNum = "";
    if (integerNum == 0) {      //sprawdzenie czy liczba dziesiêtna to 0
        binaryNum = "0";        //zwraca wtedy "0"
        return binaryNum;
    }

    while (integerNum > 0) {
        int remainder = integerNum % 2;     //reszta z dzielenia przez 2
        binaryNum = mapNumberToCharacter(remainder) + binaryNum;    // mapowanie reszty na odpowiedni znak binarny i dodanie go na poczatek stringa  
        integerNum /= 2;
    }

    return binaryNum;
}

std::string ZamianaLiczb::decimalToOctal(std::string decimalNum) {
    int integerNum = std::stoi(decimalNum);     //zamiana string na int
    std::string octalNum = "";
    if (integerNum == 0) {
        octalNum = "0";
        return octalNum;
    }

    while (integerNum > 0) {
        int remainder = integerNum % 8;     //obl reszty z dzielenia przez 8
        octalNum = mapNumberToCharacter(remainder) + octalNum;  //mapowanie reszty na odpowiedni znak ósemkowy i dodanie go na poczatek stringa
        integerNum /= 8;
    }

    return octalNum;
}

std::string ZamianaLiczb::decimalToHexadecimal(std::string decimalNum) {
    int integerNum = std::stoi(decimalNum);     //zamiana string na int
    std::string hexNum = "";
    if (integerNum == 0) {
        hexNum = "0";
        return hexNum;
    }
    while (integerNum > 0) {
        int remainder = integerNum % 16;
        hexNum = mapNumberToCharacter(remainder) + hexNum;  //mapowanie reszty na odpowiedni znak szesnastkowy i dodanie go na poczatek stringa
        integerNum /= 16;
    }

    return hexNum;
}

std::string ZamianaLiczb::hexadecimalToDecimal(const std::string& hexNum) {
    int decimalValue = 0;

    for (size_t i = 0; i < hexNum.length(); ++i) {      //iteracja po ka¿dej cyfrze szesnastkowej w stringu
        int hexDigit = mapCharacterToNumber(hexNum[i]);  //mapowanie znaku szesnastkowego na odpowiadnia wartosc liczbowa

        decimalValue = decimalValue * 16 + hexDigit;    //przesuniecie o 4 bity (czyli mnozenie przez 16) i dodanie wartoœæi 16-stkowej 
    }
    std::string decimalNum = std::to_string(decimalValue);  //konwersja wartoœci dziesiêtnej na string
    return decimalNum;
}

std::string ZamianaLiczb::octalToDecimal(const std::string& octalNum) {
    int decimalValue = 0;

    for (size_t i = 0; i < octalNum.length(); ++i) {    //iteracja po ka¿dej cyfrze ósemkowej w stringu
        int octalDigit = mapCharacterToNumber(octalNum[i]); //mapowanie znaku ósemkowego na odpowiednia warotosc liczbowa

        decimalValue = decimalValue * 8 + octalDigit;   //przesuniecie o 3 bity (czyli mno¿enie przez 8) i dodanie wartosci osemkowwej
    }
    std::string decimalNum = std::to_string(decimalValue);  //konwersja wartosci dziesietnej na string

    return decimalNum;
}

std::string ZamianaLiczb::binaryToDecimal(const std::string& binaryNum) {
    int decimalValue = 0;

    for (size_t i = 0; i < binaryNum.length(); ++i) {   //iteracja po ka¿dej cyfrze binarnej w stringu
        int binaryDigit = mapCharacterToNumber(binaryNum[i]);   //mapowanie znaku binarnego na odpowiednia wartosc liczbowa

        decimalValue = decimalValue * 2 + binaryDigit;  //przesuniecie o 1 bit (czyli mnozenie przez 2) i dodanie wartosci binarnej
    }
    std::string decimalNum = std::to_string(decimalValue);  //konwersja wartosci dziesietnej na string
    return decimalNum;
}

bool ZamianaLiczb::isValidDecimal(const std::string& decimalStr) {
    for (char digit : decimalStr) {     //iteracja po kazdym znaku
        if (digit < '0' || digit > '9')     //sprawdzanie czy znak jest cyfra (od 0 - 9)
            return false;   //jesli nie zwróci false
    }
    return true;    //jesli wszystkie znaki to cyfry (od0 do 9), zwroci true
}

bool ZamianaLiczb::isValidBinary(const std::string& binaryStr) {
    for (char binaryChar : binaryStr) {     //iteracja po kazdym znaku string
        if (binaryChar != '0' && binaryChar != '1') {   //sprawdzanie poprawnosci znaku binarnych (0 lub 1)
            return false;   //jesli nie jest poprawne, zwroci false
        }
    }
    return true;    //jesli poprawne, zwroci true
}

bool ZamianaLiczb::isValidOctal(const std::string& octalStr) {
    for (char octalChar : octalStr) {   //iteracja po kazdym znaku string
        if (octalChar < '0' || octalChar > '7') {   //sprawdzanie czy to cyfra ósemkowa (0-7)
            return false;   //jesli znak jest nie poprawna cyfra osemkowa, zwroci false
        }
    }
    return true;
}

bool ZamianaLiczb::isValidHexadecimal(const std::string& hexStr) {
    for (char hexChar : hexStr) {   //iteracja po kazdym stringu
        if ((hexChar < '0' || (hexChar > '9' && hexChar < 'A') || hexChar > 'F')) {     //sprawdzanie czy znak jest poprawna cyfra szesnastkowa (0-9, A-F)
            return false;   //jesli znak nie jest poprawna cyfra 16-ow¹, zwroci false
        }
    }
    return true;    //jesli wszystkie znaki sa poprawne, zwróci true
}