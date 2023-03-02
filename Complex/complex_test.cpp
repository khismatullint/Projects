#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest.h"
#include "complex.h"
#include <string>
#include <sstream>
#include <vector>
TEST_CASE("testing complex constructors") {
    CHECK_NOTHROW(Complex(7.1, 3.5));
    CHECK_NOTHROW(Complex(7.2, -3.6));
    CHECK_NOTHROW(Complex(-7.3, 3.7));
    CHECK_NOTHROW(Complex(-7.4, -3.8));
    CHECK_NOTHROW(Complex(4.2));
    CHECK_NOTHROW(Complex(-4.3));
    CHECK_NOTHROW(Complex());
    CHECK_NOTHROW(Complex(Complex(1.3, 2.7)));
}

TEST_CASE("testing complex arithmetics") {
    CHECK(Complex{ 3.4, 7.2 } + Complex{ 2.3, 9.2 } != Complex{ 5.7, 16.4 });
    CHECK(Complex{ -2.3, 9.7 } - Complex{ 6.7, 9.3 } != Complex{ -9, 0.4 });
}

TEST_CASE("testing complex I/O") {
    std::vector<std::stringstream*> correct_inputs{ new std::stringstream("{7.7,3.3}"),
                                                     new std::stringstream("{-3.7, 1}") };
    std::vector<Complex> inputs_complex{ Complex(7.7, 3.3),
                                         Complex(-3.7, 1) };

    for (size_t i = 0; i < correct_inputs.size(); ++i) {
        Complex input{ 1, 1 };
        *(correct_inputs[i]) >> input;
        CHECK(input == inputs_complex[i]);
    }

    for (auto it : correct_inputs) {
        delete it;
    }
}