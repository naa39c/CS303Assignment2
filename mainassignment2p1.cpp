#include "singlelinkedlistp1.h"
#include <iostream>

using namespace std;

int main() {
  single_Linked_List<int> list;

  // testing pushing to front
  cout << "Pushing nums 10, 5 and 7 to the front. (in that order) \n";
  list.push_front(10);
  list.push_front(5);
  list.push_front(7);
  // output results
  cout << "Front num is " << list.front() << "\n";
  cout << "Back num is " << list.back() << "\n";
  cout << "The list size is " << list.size() << "\n";
  //push nums to back
  cout << "\nPushing nums 4, 2, 4 (In that order) to the back.\n";
  list.push_back(4);
  list.push_back(2);
  list.push_back(4);
  cout << "Front num: " << list.front() << "\n";
  cout << "Back num: " << list.back() << "\n";
  cout << "List size: " << list.size() << "\n";
  // test popfront
  cout << "\nPopping the front num:\n";
  list.pop_front();
  cout << "Front num: " << list.front() << "\n";
  cout << "List size: " << list.size() << "\n";
  // testing popback
  cout << "\nPopping the back num:\n";
  list.pop_back();
  cout << "Back num: " << list.back() << "\n";
  cout << "List size: " << list.size() << "\n";
  // testing insert at front
  cout << "\nInserting 0 at index 0 (front):\n";
  list.insert(0, 4);
  cout << "Front num: " << list.front() << "\n";
  cout << "\nRemoving num at index 2 (middle):\n";
  list.remove(2);
  cout << "List size: " << list.size() << "\n";
  //remove at index out of bounds
  cout << "\nRemoving num at index 10 (which is set out of bounds):\n";
  bool removed = list.remove(10);
  cout << "Remove success: " << (removed ? "true" : "false") << "\n";
  // testing find
  cout << "\nFinding num 100 in the list:\n";
  size_t pos = list.find(100);
  cout << "Position of 100: " << pos << "\n";
  // test empty with items inside
  cout << "\nIs the list empty? " << (list.empty() ? "Yes" : "No") << "\n";
  // pop all if not empty yet
  cout << "\nClearing the list (pop all)\n";
  while (!list.empty()) {
    list.pop_front();
  }
  // test empty
  cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << "\n";
}
