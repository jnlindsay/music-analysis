//
//  stp.hpp
//  music-cognition
//
//  Created by Jeremy Lindsay on 10/11/2023.
//

#ifndef stp_hpp
#define stp_hpp

#include <stdio.h>

const int LEN_STP = 4;

struct STP {
  char content[LEN_STP];
  int next;

  void set_delta(char c, int d);
  char get_delta(int d);
  void print();
  void predict_at(char c, int d);
  void increment();

  STP();
};

#endif /* stp_hpp */
