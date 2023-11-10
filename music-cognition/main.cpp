//
//  main.cpp
//  music-cognition
//
//  Created by Jeremy Lindsay on 10/11/2023.
//

#include <iostream>
#include <algorithm>
#include "stm.hpp"
#include "stp.hpp"
using namespace std;

int main() {
  string rhythm;
  cin >> rhythm;
  int n = (int)rhythm.size();

  // short term memory / prediction
  STM stm;
  STP stp;

  // listen loop
  vector<bool> heard_before(n, false);
  vector<int> last_heard_delta(n, 0);
  vector<bool> correctly_predicted(n, false);
  for (int i = 0; i < n; i++) {
    heard_before[i] = (stm.contains(rhythm[i]));
    last_heard_delta[i] = stm.latest_delta(rhythm[i]);
    correctly_predicted[i] = (rhythm[i] == stp.get_delta(0));
    stp.predict_at(rhythm[i], last_heard_delta[i]);

    cout << rhythm[i] << " : ";
    stp.print();

    stm.push(rhythm[i]);
  }

  // post mortem
  cout << endl << rhythm << endl;

  for (int i = 0; i < n; i++) {
    cout << heard_before[i];
  } cout << endl;

  for (int i = 0; i < n; i++) {
    cout << last_heard_delta[i];
  } cout << endl;

  for (int i = 0; i < n; i++) {
    cout << correctly_predicted[i];
  } cout << endl;

  return 0;
}
