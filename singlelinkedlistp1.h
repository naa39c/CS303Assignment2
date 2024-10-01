#include <iostream>

using namespace std;

template <typename Item_Type> class single_Linked_List {
private:
  struct Node {
    Item_Type data;
    Node *next;
    Node(const Item_Type &data, Node *next = nullptr)
        : data(data), next(next) {}
  };
  Node *head;
  Node *tail;
  size_t num_items;

public:
  single_Linked_List();
  ~single_Linked_List();

  // Member functions
  void push_front(const Item_Type &item);
  // INPUT: The list, passed by reference
  // OUTPUT: Adds value to front of linked list
  void push_back(const Item_Type &item);
  // INPUT: The list, passed by reference
  // OUTPUT: Adds value to back of linked list
  void pop_front();
  // INPUT: Nothing
  // OUTPUT: removes front
  void pop_back();
  // INPUT: Nothing
  // OUTPUT: removes back
  bool empty() const;
  // determines if empty/
  void insert(size_t index, const Item_Type &item);
  // INPUT: index and the value
  // OUTPUT: inserts item at index
  bool remove(size_t index);
  // INPUT: index and the list passed by reference
  // OUTPUT: removes item at index
  size_t find(const Item_Type &item) const;
  // INPUT: the list passed by reference
  // OUTPUT: determines where value is located
  size_t size() const;
  // INPUT: nothing
  // OUTPUT: used to find size
  Item_Type &front();
  // used to make functions easier
  Item_Type &back();
};
template <typename Item_Type>
single_Linked_List<Item_Type>::single_Linked_List()
    // setting values to null to begin
    : head(nullptr), tail(nullptr), num_items(0) {}

// destructor
template <typename Item_Type>
single_Linked_List<Item_Type>::~single_Linked_List() {
  while (!empty()) {
    pop_front();
  }
}

// push front function
template <typename Item_Type>
void single_Linked_List<Item_Type>::push_front(const Item_Type &item) {
  Node *new_node = new Node(item, head);
  head = new_node;
  if (tail == nullptr) {
    tail = head; // if list was empty, the header is the tail and vice versa
  }
  ++num_items;
}

// push back
template <typename Item_Type>
void single_Linked_List<Item_Type>::push_back(const Item_Type &item) {
  Node *new_node = new Node(item);
  if (tail) {
    tail->next = new_node;
    tail = new_node;
  } else {
    head = tail = new_node;
  }
  ++num_items;
}

// poppin from the front
template <typename Item_Type> void single_Linked_List<Item_Type>::pop_front() {
  if (empty()) {
    throw runtime_error("List is empty");
  }
  Node *temp = head;
  head = head->next;
  delete temp;
  // decrement when removed
  --num_items;
  if (head == nullptr) {
    tail = nullptr;
  }
}
// pop back function
template <typename Item_Type> void single_Linked_List<Item_Type>::pop_back() {
  if (empty()) {
    throw runtime_error("List is empty");
  }

  if (head == tail) {
    delete head;
    head = tail = nullptr;
  } else {
    Node *current = head;
    while (current->next != tail) {
      current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
  }
  // decrement when removed
  --num_items;
}

// get  front element
template <typename Item_Type>
Item_Type &single_Linked_List<Item_Type>::front() {
  if (empty()) {
    throw runtime_error("List is empty");
  }
  return head->data;
}

// getting back element, throw error if empty
template <typename Item_Type> Item_Type &single_Linked_List<Item_Type>::back() {
  if (empty()) {
    throw runtime_error("List is empty");
  }
  return tail->data;
}

// check if  list is empty
template <typename Item_Type>
bool single_Linked_List<Item_Type>::empty() const {
  return num_items == 0;
}

// insert item at index
template <typename Item_Type>
void single_Linked_List<Item_Type>::insert(size_t index,
                                           const Item_Type &item) {
  if (index > num_items) {
    throw out_of_range("Index out of range");
  }

  if (index == 0) {
    push_front(item);
  } else if (index == num_items) {
    push_back(item);
  } else {
    Node *current = head;
    for (size_t i = 1; i < index; ++i) {
      current = current->next;
    }
    Node *new_node = new Node(item, current->next);
    current->next = new_node;
    ++num_items;
  }
}

// remove item at index
template <typename Item_Type>
bool single_Linked_List<Item_Type>::remove(size_t index) {
  if (index >= num_items) {
    return false;
  }

  if (index == 0) {
    pop_front();
  } else {
    Node *current = head;
    for (size_t i = 1; i < index; ++i) {
      current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    if (temp == tail) {
      tail = current;
    }
    delete temp;
    --num_items;
  }
  return true;
}

// find where value first occurs
template <typename Item_Type>
size_t single_Linked_List<Item_Type>::find(const Item_Type &item) const {
  Node *current = head;
  size_t index = 0;
  while (current) {
    if (current->data == item) {
      return index;
    }
    current = current->next;
    ++index;
  }
  return num_items; // returns size of list if not found (could be interchanged
                    // for 0 depending if uiser wanted)
}

// return the size of the list
template <typename Item_Type>
size_t single_Linked_List<Item_Type>::size() const {
  return num_items;
}