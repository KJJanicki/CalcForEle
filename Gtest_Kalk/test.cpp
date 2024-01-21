#include "pch.h"
#include "ZamianaTest.h"
#include "gtest/gtest.h"

ZamianaTest zam;
TEST(ZamianaTestSuite, DecimalToBinary) {
    EXPECT_EQ(zam.decimalToBinary("0"), "0");
    EXPECT_EQ(zam.decimalToBinary("10"), "1010");
    EXPECT_EQ(zam.decimalToBinary("88"), "1011000");
    EXPECT_EQ(zam.decimalToBinary("155"), "10011011");
}

TEST(ZamianaTestSuite, DecimalToOctal) {
    EXPECT_EQ(zam.decimalToOctal("5"), "5");
    EXPECT_EQ(zam.decimalToOctal("10"), "12");
    EXPECT_EQ(zam.decimalToOctal("46"), "56");
    EXPECT_EQ(zam.decimalToOctal("160"), "240");
}

TEST(ZamianaTestSuite, DecimalToHexadecimal) {
    EXPECT_EQ(zam.decimalToHexadecimal("4"), "4");
    EXPECT_EQ(zam.decimalToHexadecimal("10"), "A");
    EXPECT_EQ(zam.decimalToHexadecimal("68"), "44");
    EXPECT_EQ(zam.decimalToHexadecimal("180"), "B4");
}

TEST(ZamianaTestSuite, HexadecimalToDecimal) {
    EXPECT_EQ(zam.hexadecimalToDecimal("0"), "0");
    EXPECT_EQ(zam.hexadecimalToDecimal("D"), "13");
    EXPECT_EQ(zam.hexadecimalToDecimal("100"), "256");
    EXPECT_EQ(zam.hexadecimalToDecimal("19"), "25");
}

TEST(ZamianaTestSuite, OctalToDecimal) {
    EXPECT_EQ(zam.octalToDecimal("5"), "5");
    EXPECT_EQ(zam.octalToDecimal("12"), "10");
    EXPECT_EQ(zam.octalToDecimal("100"), "64");
    EXPECT_EQ(zam.octalToDecimal("345"), "229");
}

TEST(ZamianaTestSuite, BinaryToDecimal) {
    EXPECT_EQ(zam.binaryToDecimal("101"), "5");
    EXPECT_EQ(zam.binaryToDecimal("11001"), "25");
    EXPECT_EQ(zam.binaryToDecimal("110010"), "50");
    EXPECT_EQ(zam.binaryToDecimal("1010101"), "85");
}