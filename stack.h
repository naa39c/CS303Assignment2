#include <numeric> // needed for some functions
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;
class Stack {
private:
  vector<int> stack; 

public:
  void push(int value);
  // INPUT: int value
  // OUTPUT: adds it to top of the stack
  void pop();
  // INPUT: nothing
  // OUTPUT: removes top
  bool empty() const;
  // INPUT: nothing
  // OUTPUT: checks if empty

  int top() const;
  // INPUT: nothing
  // OUTPUT: finds top value

  double average() const;
  // INPUT: nothing
  // OUTPUT: gets average in decimals
};
