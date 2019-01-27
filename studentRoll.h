#ifndef STUDENTROLL_H
#define STUDENTROLL_H 

#include <string>
#include "student.h"

 struct Node {
    Student *s = NULL; 
    Node *next = NULL;
  };

class StudentRoll {

 public:
  StudentRoll();
  void insertAtTail(const Student &s);
  std::string toString() const;
  Node* gethead() const;
  StudentRoll(const StudentRoll &orig);
  ~StudentRoll();
  StudentRoll & operator=(const StudentRoll &right);

 private:
  //struct Node {
    //Student *s;
    //Node *next;
  //};
  Node *head;
  Node *tail;
};


#endif
