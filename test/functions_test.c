/**
 * @file functions_test.c
 * @author Federico Peccia
 * @brief This file implements the tests which will test the functions declared in functions.c
 * @version 0.1
 * @date 2019-08-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "CUnit/CUnit.h"
#include "../inc/functions.h"

// The following line starts a block of code which will not be taken into account for the coverage report
// LCOV_EXCL_START

/**
 * @brief Checks if the funcion sum works ok for positive numbers
 * 
 */
void sumTwoPositiveNumbers(void)
{
  // Prerequisites for the test
  int result = 0;

  // Running unit under test
  result = sum(2,14);

  // Check result
  CU_ASSERT_EQUAL(result,16);
}

/**
 * @brief Checks if the funcion sum works ok for negative numbers
 * 
 */
void sumTwoNegativeNumbers(void)
{
  // Prerequisites for the test
  int result = 0;

  // Running unit under test
  result = sum(-2,-14);

  // Check result
  CU_ASSERT_EQUAL(result,-16);
}

/**
 * @brief Checks if the funcion sub works ok for positive numbers
 * 
 */
void subTwoPositiveNumbers(void)
{
  // Prerequisites for the test
  int result = 0;

  // Running unit under test
  result = sub(20,5);

  // Check result
  CU_ASSERT_EQUAL(result,15);
}

/**
 * @brief Checks if the funcion sub works ok for negative numbers
 * 
 */
void subTwoNegativeNumbers(void)
{
  // Prerequisites for the test
  int result = 0;

  // Running unit under test
  result = sub(-20,-5);

  // Check result
  CU_ASSERT_EQUAL(result,-15);
}

// The following line ends a block of code which will not be taken into account for the coverage report
// LCOV_EXCL_END