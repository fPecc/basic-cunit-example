/**
 * @file main.c
 * @author Federico Peccia
 * @brief Dummy main file
 * @version 0.1
 * @date 2019-08-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include<stdio.h>
#include "../inc/functions.h"

/**
 * @brief Dummy main function
 * 
 * @return int 
 */
int main()
{
    int a = 5;
    int b = 6;

    printf("In data:\n%i\n%i\n",a,b);
    printf("Addition result: %i\n",sum(a,b));
    printf("Substraction : %i\n",sub(a,b));

    return 0;
}

