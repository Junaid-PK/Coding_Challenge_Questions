#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  void setHead(Node *node) {
    // Write your code here.
    if (head == nullptr){
        head = node;
        tail = node;
        return;
    }
    insertBefore(head,node);
  }

  void setTail(Node *node) {
    // Write your code here.
    if(tail == nullptr){
        setHead(node);
        return;
    }
    insertAfter(tail,node);
  }

  void insertBefore(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if(nodeToInsert == head and nodeToInsert == tail)
        return;
    remove(nodeToInsert);
    nodeToInsert->prev = node->prev;
    nodeToInsert->next = node;
    if(node->prev == nullptr){
        head = nodeToInsert;
    }else{
        node->prev->next = nodeToInsert;
    }
    node->prev = nodeToInsert;
  }

  void insertAfter(Node *node, Node *nodeToInsert) {
    // Write your code here.
    if(nodeToInsert == head and nodeToInsert == tail)
        return;
    remove(nodeToInsert);
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;
    if (node->next == nullptr){
        tail = nodeToInsert;
    }else{
        node->next->prev = nodeToInsert
    }
    node->next = nodeToInsert;
  }

  void insertAtPosition(int position, Node *nodeToInsert) {
    // Write your code here.
    if (position == 1){
      setHead(nodeToInsert);
        return;
    }
    Node *node = head;
    int currentPosition = 1;
    while (node != nullptr && currentPosition != position){
      node = node->next;
      currentPosition++;
    }
    if (node !=nullptr){
      insertBefore(node, nodeToInsert);
    }else{
      setTail(nodeToInsert);
    }
  }

  void removeNodesWithValue(int value) {
    // Write your code here.
    Node* tmp;
    tmp =  head;
    while(tmp !=nullptr){
        Node* nodeToRemove;
        nodeToRemove = tmp;
        tmp = tmp->next;
        if(nodeToRemove->value == value){
            remove(nodeToRemove);
        }
    }
  }

  void remove(Node *node) {
    // Write your code here.
    if(node == head){
        head = head->next;
    }
    if ( node == tail){
        tail = tail.prev;
    }
    if(node->prev !=nullptr){
        node->prev->next = node->next;
    }
    if (node->next !=nullptr){
        node->next->prev = node->prev;
    }
    node->next = nullptr;
    node->prev = nullptr;
  }


  bool containsNodeWithValue(int value) {
    // Write your code here.
    Node *tmp;
    tmp = head;
    while (tmp!=nullptr){
            if(tmp.value == value){
                return true;
            }
        tmp = tmp->next;
    }
    return false;
  }
};
