// expect-success
/*
 * Copyright 2014 Google Inc. All rights reserved.
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

#define IN_FRUIT_CPP_FILE

#include <fruit/impl/util/type_info.h>

#include <vector>
#include <cassert>

using namespace std;
using namespace fruit::impl;


void test_size() {
  assert(getTypeId<char[27]>().type_info->size() == 27);
}

struct alignas(128) TypeAligned128 {
};

void test_alignment() {
  assert(getTypeId<TypeAligned128>().type_info->alignment() == 128);
}

struct MyStruct {
};

void test_name() {
  assert(getTypeId<MyStruct>().type_info->name() == "MyStruct");
  assert(std::string(getTypeId<MyStruct>()) == "MyStruct");
}

void test_isTriviallyDestructible_true() {
  assert(getTypeId<int>().type_info->isTriviallyDestructible());
}

void test_isTriviallyDestructible_false() {
  assert(!getTypeId<std::vector<int>>().type_info->isTriviallyDestructible());
}

int main() {
  
  test_size();
  test_alignment();
  test_name();
  test_isTriviallyDestructible_true();
  test_isTriviallyDestructible_false();
  
  return 0;
}
