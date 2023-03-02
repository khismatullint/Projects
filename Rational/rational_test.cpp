#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "rational.h"
#include <iostream>
#include "../doctest/doctest.h"

bool testParse(const std::string &s, const Rational &correct) {
    std::istringstream istrm(s);
    Rational n(0);
    istrm >> n;
    return n == correct;
}

bool testWrite(const Rational &n, const std::string &correct) {
    std::ostringstream ostrm;
    ostrm << n;
    return ostrm.str() == correct;
}

TEST_CASE("Rational Testing") {
    SUBCASE("Reading from a stream") {
        CHECK(testParse("3/5", Rational(3, 5)));
        CHECK(testParse("-3/7", Rational(-3, 7)));
        CHECK(testParse("-9/3", Rational(-3, 1)));
        CHECK_FALSE(testParse("3  /5", Rational(3, 5)));
        CHECK_FALSE(testParse("6 / 5", Rational(6, 5)));
        CHECK_FALSE(testParse("3/ 7", Rational(3, 7)));
        CHECK_FALSE(testParse("{3/7}", Rational(3, 7)));
        CHECK_FALSE(testParse("(4.2/7)", Rational(4, 7)));
        CHECK_FALSE(testParse("[4.2/7]", Rational(4, 7)));
        CHECK_FALSE(testParse("(4.2/7}", Rational(4, 7)));
    }

    SUBCASE("Writing to a stream") {
        CHECK(testWrite(Rational(3, 5), "3/5"));
        CHECK(testWrite(Rational(-3, 7), "-3/7"));
        CHECK(testWrite(Rational(3, -5), "-3/5"));
        CHECK(testWrite(Rational(3, 6), "1/2"));
        CHECK(testWrite(Rational(15, 25), "3/5"));
    }

    SUBCASE("Initialization") {
        CHECK(testWrite(Rational(), "0/1"));
        CHECK(testWrite(Rational(7), "7/1"));
        CHECK(testWrite(Rational(7, 2), "7/2"));
        CHECK(testWrite(Rational(-7, 2), "-7/2"));
        CHECK(testWrite(Rational(7, -2), "-7/2"));
        CHECK(testWrite(Rational(-7, -2), "7/2"));
        CHECK(testWrite(Rational(0, -2), "0/1"));
        CHECK(testWrite(Rational(14, 21), "2/3"));
        CHECK(testWrite(Rational(77, 21), "11/3"));
        CHECK_THROWS_WITH(Rational(7, 0), "error: division by zero");
    }

    SUBCASE("Addition (+)") {
        CHECK(Rational(3, 5) + Rational(10, 4) == Rational(62, 20));
        CHECK(Rational(-3, 5) + Rational(10, 4) == Rational(38, 20));
        CHECK(Rational(1, 4) + Rational(1, 4) == Rational(1, 2));
        CHECK(Rational(3, 5) + 5 == Rational(28, 5));
        Rational n(3, 5);
        n += Rational(10, 4);
        CHECK(n == Rational(62, 20));
        n += 5;
        CHECK(n == Rational(162, 20));
    }

    SUBCASE("Subtraction (-)") {
        CHECK(Rational(3, 5) - Rational(10, 4) == Rational(-38, 20));
        CHECK(Rational(3, 5) - Rational(-10, 4) == Rational(62, 20));
        CHECK(Rational(1, 4) - Rational(1, 4) == Rational(0));
        CHECK(Rational(3, 5) - 5 == Rational(-22, 5));
        Rational n(3, 5);
        n -= Rational(10, 4);
        CHECK(n == Rational(-38, 20));
        n -= 5;
        CHECK(n == Rational(-138, 20));
        CHECK(-n == Rational(138, 20));
    }

    SUBCASE("Multiplication (*)") {
        CHECK(Rational(3, 5) * Rational(10, 4) == Rational(30, 20));
        CHECK(Rational(3, 5) * Rational(-10, 4) == Rational(-30, 20));
        CHECK(Rational(3, 5) * 5 == Rational(15, 5));
        Rational n(3, 5);
        n *= Rational(10, 4);
        CHECK(n == Rational(30, 20));
        n *= (-5);
        CHECK(n == Rational(-150, 20));
    }

    SUBCASE("Division (/)") {
        CHECK(Rational(3, 5) / Rational(10, 4) == Rational(12, 50));
        CHECK(Rational(3, 5) / Rational(-10, 4) == Rational(-12, 50));
        CHECK(Rational(3, 5) / 5 == Rational(3, 25));
        Rational n(3, 5);
        n /= Rational(10, 4);
        CHECK(n == Rational(6, 25));
        CHECK_THROWS_WITH(n /= 0, "error: division by zero");
        CHECK_THROWS_WITH(Rational(6, 3) /= Rational(0, 1), "error: division by zero");
        CHECK(n == Rational(6, 25));
    }

    SUBCASE("Comparison (==, !=)") {
        CHECK(Rational(3, 5) == Rational(3, 5));
        CHECK(Rational(25, 100) == Rational(1, 4));
        CHECK(Rational(-39, 52) == Rational(-3, 4));
        CHECK(Rational(-39, 52) != Rational(3, 4));
        CHECK(Rational(1, 4) != Rational(1, 8));
    }
}
