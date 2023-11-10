//
//  stm.hpp
//  music-cognition
//
//  Created by Jeremy Lindsay on 10/11/2023.
//

#ifndef stm_hpp
#define stm_hpp

#include <stdio.h>
#include <deque>

const int LEN_STM = 4;

struct STM {
  std::deque<char> content;

  int size();
  void print();
  void push(char c);
  bool contains(char c);
  int latest_delta(char c);
};

#endif /* stm_hpp */
