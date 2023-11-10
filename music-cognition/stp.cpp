//
//  stp.cpp
//  music-cognition
//
//  Created by Jeremy Lindsay on 10/11/2023.
//

#include "stp.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

void STP::set_delta(char c, int d) {
  content[(next + d) % LEN_STP] = c;
}

char STP::get_delta(int d) {
  return content[(next + d) % LEN_STP];
}

void STP::print() {
  for (int d = 0; d < LEN_STP; d++) {
    cout << get_delta(d);
  } cout << endl;
}

void STP::predict_at(char c, int d) {
  set_delta('_', 0);
  increment();
  if (d > 0) set_delta(c, d - 1);
}

void STP::increment() {
  next = (next + 1 % LEN_STP);
}

STP::STP() : next(0) {
  fill(content, content + LEN_STP, '_');
}
