#ifndef DATA_STRUCT_GENERIC_H
#define DATA_STRUCT_GENERIC_H

#include <stdbool.h>

/**
 * Construct a integer in heap
 *
 * @param value Value of integer
 * @return Pointer of the integer
 */
int *NewInt(int value);

/**
 * Set the value of the Integer
 *
 * @param ptr
 * @param value
 */
void SetInt(void *ptr, int value);

/**
 * Get the value of the Integer
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return int Value of the Integer
 */
int GetInt(void *ptr);

/**
 * Incrementing the Integer by 1, return value of the Integer + 1
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer + 1
 */
int IntPrefInc(void *ptr);

/**
 * Incrementing the Integer by 1, return the value of the Integer
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int IntPostInc(void *ptr);

/**
 * Decrementing the Integer by 1, return value of the Integer - 1
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer - 1
 */
int IntPrefDec(void *ptr);

/**
 * Decrementing the Integer by 1, return the value of the Integer
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int IntPostDec(void *ptr);

/**
 * Delete the Integer in heap, and return its value
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int DeleteAndGetInt(void *ptr);

/**
 * @brief Compare two integers
 *
 * @param ptr1 Void pointer but actually point to an Integer
 * @param ptr2 Void pointer but actually point to an Integer
 */
bool IntCmp(void *ptr1, void *ptr2);

/**
 * @brief Compare two integers is equal
 *
 * @param ptr1 Void pointer but actually point to an Integer
 * @param ptr2 Void pointer but actually point to an Integer
 */
bool IntEq(void *ptr1, void *ptr2);
#endif //DATA_STRUCT_GENERIC_H
