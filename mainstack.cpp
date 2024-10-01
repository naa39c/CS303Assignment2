#include "stack.h"
int main() {
    Stack stack; // create a stack called stack (super creative name) 

    //check to see if stack is empty
   cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    //adding values to stack
    stack.push(5);
    stack.push(32);
    stack.push(42);
    stack.push(12);
    cout << "Inserted values: 5,32,42,12\n" <<endl;
    // check again now that values are added
    cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") <<  "\n"<<endl;
    //what is top of stack
    cout << "Top of the stack:" << stack.top() << "\n"<<endl;
    //calcing the avg
    cout << "Average value of the stack: " << stack.average() <<  "\n"<<endl;
    //remove element
    stack.pop();
    cout << "Popped the top element from the stack." << "\n"<< endl;
    //checking to ensure it was popped
    cout << "New top of the stack: " << stack.top() <<  "\n"<<endl;
}