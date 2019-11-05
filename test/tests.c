/**
 * @file tests.c
 * @author Federico Peccia
 * @brief Main function to configure and run tests
 * @version 0.1
 * @date 2019-08-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "CUnit/CUnit.h"
#include "../inc/functions_test.h"

#define UNITTEST true

/**
 * @brief Funcion main del test, se crean las suites, se asignan los test, y se corren
 * 
 * @return int 
 */
int main()
{
  // Initialize suites (groups of tests)
  CU_pSuite SumSuite = NULL;
  CU_pSuite SubSuite = NULL;

  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();  

  // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
  // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
  CU_basic_set_mode(CU_BRM_VERBOSE);   // Run the tests and show the run summary

  // Create suites
  SumSuite = CU_add_suite("SumSuite", 0, 0);// Always check if add was successful
  if (NULL == SumSuite) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  
  SubSuite = CU_add_suite("SubSuite", 0, 0);// Always check if add was successful
  if (NULL == SubSuite) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add all tests to the suites
  if (NULL == CU_add_test(SumSuite, "sumTwoPositiveNumbers", sumTwoPositiveNumbers)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(SumSuite, "sumTwoNegativeNumbers", sumTwoNegativeNumbers)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(SubSuite, "subTwoPositiveNumbers", subTwoPositiveNumbers)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(SubSuite, "subTwoNegativeNumbers", subTwoNegativeNumbers)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Run all tests
  CU_basic_run_tests();
  
  return CU_get_error();
}