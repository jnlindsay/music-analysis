#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int LEN_STM = 4;
const int LEN_STP = 4;

struct STM {
  deque<char> content;

  int size() { return content.size(); }

  void print() {
    for (int i = 0; i < content.size(); i++) {
      cout << content[i];
    } cout << endl;
  }

  void push(char c) {
    content.push_front(c);
    if (content.size() > LEN_STM) content.pop_back();
  }

  bool contains(char c) {
    for (int i = 0; i < content.size(); i++) {
      if (content[i] == c) return true;
    }
    return false;
  }

  int latest_delta(char c) {
    for (int i = 0; i < content.size(); i++) {
      if (content[i] == c) return i + 1;
    }
    return 0;
  }
};

struct STP {
  char content[LEN_STP];
  int next;

  void set_delta(char c, int d) {
    content[(next + d) % LEN_STP] = c;
  }

  char get_delta(int d) {
    return content[(next + d) % LEN_STP];
  }

  void print() {
    for (int d = 0; d < LEN_STP; d++) {
      cout << get_delta(d);
    } cout << endl;
  }

  void predict_at(char c, int d) {
    set_delta('_', 0);
    increment();
    if (d > 0) set_delta(c, d - 1);
  }

  void increment() {
    next = (next + 1 % LEN_STP);
  }

  STP() : next(0) {
    fill(content, content + LEN_STP, '_');
  }
};

int main() {
  string rhythm;
  cin >> rhythm;
  int n = rhythm.size();

  // short term memory / prediction
  STM stm;
  STP stp;

  cout << "DEFAULT STP: ";
  stp.print();
  cout << endl;

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