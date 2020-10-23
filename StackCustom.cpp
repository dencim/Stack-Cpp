#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
  string data;
  Node* next;
};

class Stack{
public:
  Stack(); //Constructor
  ~Stack(); //Deconstructor
  void push(string d);
  string pop();
  string toString();
  bool isEmpty(){return (top == NULL);};
  Node* getTop(){return top;};
private:
  Node *top;
};

Stack::Stack(){
  top = NULL;
}

Stack::~Stack(){
  while(!isEmpty()){
    pop();
  }
}

void Stack::push(string d){
  Node* newTop = new Node;
  newTop->data = d;
  newTop->next = top; //points to old top
  top = newTop;
}

string Stack::pop(){
  if(!isEmpty()){
    string value = top->data;
    Node* oldTop = top;
    top = top->next;
    delete oldTop;
    return value;
  }
  else{
    cout << "Error! Can't pop empty stack.";
    exit(1);
  }
}

string Stack::toString(){
  string result = "(top)->";
  if(top == NULL){
    result += "NULL";
    return result;
  }
  else{
    Node* current = top;
    while(current != NULL){
      result += current->data + " ->";
      current = current->next;
    }
    return result;
  }
}

int main(){

  Stack *s = new Stack();
  cout << s->toString() << endl;
  s->push("Blaze");
  s->push("Quincy");
  cout << s->toString() << endl;

  return 0;

}
