#ifndef SRC_TEST_TEST_CASES_H_
#define SRC_TEST_TEST_CASES_H_

#include "s21_math.h"

double cases_pow_zeros[][2] = {{0, 5},
                               {0, -5},
                               {0, s21_NaN},
                               {0, -s21_NaN},
                               {0, 0},
                               {0, s21_NEG_INFINITY},
                               {-1, s21_INFINITY},
                               {-1, s21_NEG_INFINITY}};

double cases_pow_exp[][2] = {{1, s21_NaN}, {1, s21_INFINITY}, {1, 0},  {1, -5},
                             {1, 5},       {1, 1.5},          {-1, 3}, {-1, 2},
                             {-1, 1.5}};

double cases_pow_base[][2] = {{s21_NaN, 0}, {s21_INFINITY, 0}, {5, 0}};

double cases_pow_base_fractional[][2] = {
    {0.1, s21_INFINITY},      {-0.1, s21_INFINITY},  {0.1, s21_NEG_INFINITY},
    {-0.1, s21_NEG_INFINITY}, {5, s21_INFINITY},     {-5, s21_INFINITY},
    {5, s21_NEG_INFINITY},    {-5, s21_NEG_INFINITY}};

double cases_pow_inf_exp[][2] = {
    {s21_INFINITY, 0},
    {s21_INFINITY, 5},
    {s21_INFINITY, s21_INFINITY},
    {s21_INFINITY, s21_NaN},
    {s21_NEG_INFINITY, 0},
    {s21_NEG_INFINITY, 5},
    {s21_NEG_INFINITY, s21_INFINITY},
    {s21_NEG_INFINITY, s21_NaN},
};

double cases_pow_nan[][2] = {
    {s21_NaN, s21_NaN}, {s21_NaN, -s21_NaN}, {-s21_NaN, -s21_NaN}};
double cases_pow_usual[][2] = {
    {5, s21_NaN}, {5, -s21_NaN}, {5, s21_INFINITY}, {5, s21_NEG_INFINITY}};

double cases_pow_return_nan[][2] = {
    {0.00, s21_NaN},     {s21_INFINITY, s21_NaN}, {s21_NEG_INFINITY, s21_NaN},
    {s21_NaN, s21_NaN},  {s21_NaN, -s21_NaN},     {-s21_NaN, -s21_NaN},
    {0.00, -s21_NaN},    {0.00, -s21_NaN},        {-1.00, 1.50},
    {-s21_NaN, -s21_NaN}};

double cases_pow_return_inf[][2] = {{0.00, -5.00},
                                    {0.00, s21_NEG_INFINITY},
                                    {0.10, s21_NEG_INFINITY},
                                    {-0.10, s21_NEG_INFINITY},
                                    {5.00, s21_INFINITY},
                                    {-5.00, s21_INFINITY},
                                    {s21_INFINITY, 5.00},
                                    {s21_INFINITY, s21_INFINITY},
                                    {s21_NEG_INFINITY, s21_INFINITY}};

double cases_pow_return_one[][2] = {{-1.00, s21_INFINITY},
                                    {-1.00, s21_NEG_INFINITY},
                                    {1.00, s21_NaN},
                                    {1.00, s21_INFINITY},
                                    {1.00, 0.00},
                                    {1.00, -5.00},
                                    {1.00, 5.00},
                                    {1.00, 1.50},
                                    {-1.00, 2.00},
                                    {s21_NaN, 0.00},
                                    {s21_INFINITY, 0.00},
                                    {5.00, 0.00},
                                    {s21_NEG_INFINITY, 0.00}};

// pow(0.00, 5.00)->0.00
// pow(0.00, -5.00)->s21_INFINITY //
// pow(0.00, s21_NaN)->s21_NaN  //
// pow(0.00, -s21_NaN)->-s21_NaN //
// pow(0.00, 0.00)->1.00
// pow(0.00, s21_NEG_INFINITY)->s21_INFINITY //
// pow(-1.00, s21_INFINITY)->1.00 //
// pow(-1.00, s21_NEG_INFINITY)->1.00 //
// END

// pow(1.00, s21_NaN)->1.00 // 55
// pow(1.00, s21_INFINITY)->1.00 // 55
// pow(1.00, 0.00)->1.00 // 55
// pow(1.00, -5.00)->1.00 // 55
// pow(1.00, 5.00)->1.00 // 55
// pow(1.00, 1.50)->1.00 // 55
// pow(-1.00, 3.00)->-1.00
// pow(-1.00, 2.00)->1.00 //
// pow(-1.00, 1.50)->-s21_NaN //
// END

// pow(s21_NaN, 0.00)->1.00 //
// pow(s21_INFINITY, 0.00)->1.00 // 33
// pow(5.00, 0.00)->1.00 //
// END

// pow(0.10, s21_INFINITY)->0.00 22
// pow(-0.10, s21_INFINITY)->0.00 11
// pow(0.10, s21_NEG_INFINITY)->s21_INFINITY // 22
// pow(-0.10, s21_NEG_INFINITY)->s21_INFINITY //11
// pow(5.00, s21_INFINITY)->s21_INFINITY //
// pow(-5.00, s21_INFINITY)->s21_INFINITY //
// pow(5.00, s21_NEG_INFINITY)->0.00
// pow(-5.00, s21_NEG_INFINITY)->0.00
// END

// pow(s21_INFINITY, 5.00)->s21_INFINITY // 33
// pow(s21_INFINITY, s21_INFINITY)->s21_INFINITY // 33
// pow(s21_INFINITY, s21_NaN)->s21_NaN 33
// pow(s21_NEG_INFINITY, 0.00)->1.00 // 44
// pow(s21_NEG_INFINITY, 5.00)->s21_NEG_INFINITY 44
// pow(s21_NEG_INFINITY, s21_INFINITY)->s21_INFINITY // 44
// pow(s21_NEG_INFINITY, s21_NaN)->s21_NaN// 44
// END

// pow(s21_NaN, s21_NaN)->s21_NaN //
// pow(s21_NaN, -s21_NaN)->s21_NaN //
// pow(-s21_NaN, -s21_NaN)->-s21_NaN //
// END

#endif /* SRC_TEST_TEST_CASES_H_ */
