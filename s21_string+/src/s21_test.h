#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// PART 1
Suite *test_memchr();
Suite *test_memcmp();
Suite *test_memcpy();
Suite *test_memset();
Suite *test_strncat();
Suite *test_strchr();
Suite *test_strncmp();
Suite *test_strncpy();
Suite *test_strcspn();
Suite *test_strerror();
Suite *test_strlen();
Suite *test_strpbrk();
Suite *test_strrchr();
Suite *test_strstr();
Suite *test_strtok();
// PART 2 + BONUS PART 4
Suite *test_sprintf();

// BONUS PART 3
Suite *test_sscanf();

// BONUS PART 5
Suite *test_insert();
Suite *test_to_upper();
Suite *test_to_lower();
Suite *test_trim();
#endif
