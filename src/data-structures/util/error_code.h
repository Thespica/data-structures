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

#ifndef DATA_STRUCT_ERROR_CODE_H
#define DATA_STRUCT_ERROR_CODE_H

#include <stdio.h>
#include <stdlib.h>

#define OOM_FAIL 1
#define ASSERT_IMPOSSIBLE (OOM_FAIL + 1)
#define OUT_OF_RANGE_FAIL (ASSERT_IMPOSSIBLE + 1)
#define DE_EMPTY_QUEUE_FAIL (OUT_OF_RANGE_FAIL + 1)
#define POP_EMPTY_STACK_FAIL (DE_EMPTY_QUEUE_FAIL + 1)
#define PUSH_FULL_STACK_FAIL (POP_EMPTY_STACK_FAIL + 1)

#endif  // DATA_STRUCT_ERROR_CODE_H
