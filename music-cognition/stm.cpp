//
//  stm.cpp
//  music-cognition
//
//  Created by Jeremy Lindsay on 10/11/2023.
//

#include "stm.hpp"
#include <iostream>
#include <deque>
using namespace std;

int STM::size() { return (int)content.size(); }

void STM::print() {
  for (int i = 0; i < content.size(); i++) {
    cout << content[i];
  } cout << endl;
}

void STM::push(char c) {
  content.push_front(c);
  if (content.size() > LEN_STM) content.pop_back();
}

bool STM::contains(char c) {
  for (int i = 0; i < content.size(); i++) {
    if (content[i] == c) return true;
  }
  return false;
}

int STM::latest_delta(char c) {
  for (int i = 0; i < content.size(); i++) {
    if (content[i] == c) return i + 1;
  }
  return 0;
}
