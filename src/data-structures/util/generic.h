/*
 * Copyright 2024 Thespica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATA_STRUCT_GENERIC_H
#define DATA_STRUCT_GENERIC_H

#include <stdbool.h>

/**
 * The generic interface for integer
 */
typedef void* Int;

/**
 * Construct a integer in heap
 *
 * @param value Value of integer
 * @return Pointer of the integer
 */
int* NewInt(int value);

/**
 * Set the value of the Integer
 *
 * @param ptr
 * @param value
 */
void SetInt(Int ptr, int value);

/**
 * Get the value of the Integer
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return int Value of the Integer
 */
int GetInt(Int ptr);

/**
 * Incrementing the Integer by 1, return value of the Integer + 1
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer + 1
 */
int IntPrefInc(Int ptr);

/**
 * Incrementing the Integer by 1, return the value of the Integer
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int IntPostInc(Int ptr);

/**
 * Decrementing the Integer by 1, return value of the Integer - 1
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer - 1
 */
int IntPrefDec(Int ptr);

/**
 * Decrementing the Integer by 1, return the value of the Integer
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int IntPostDec(Int ptr);

/**
 * Delete the Integer in heap, and return its value
 *
 * @param ptr Void pointer but actually point to an Integer
 * @return Value of the Integer
 */
int DeleteAndGetInt(Int ptr);

/**
 * @brief Compare two integers
 *
 * @param ptr1 Void pointer but actually point to an Integer
 * @param ptr2 Void pointer but actually point to an Integer
 */
bool IntCmp(Int ptr1, Int ptr2);

/**
 * @brief Compare two integers is equal
 *
 * @param ptr1 Void pointer but actually point to an Integer
 * @param ptr2 Void pointer but actually point to an Integer
 */
bool IntEq(Int ptr1, Int ptr2);
#endif  // DATA_STRUCT_GENERIC_H
