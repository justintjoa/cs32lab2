#include <string>
#include <iostream>
#include <sstream>
#include "studentRoll.h"

using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* p;
  p = new Node;
   p->s = new Student(s);
  if (tail != NULL) {
	tail->next = p;
//	cout << "stick" << endl;
  }
  else {
	head = p;
	tail = p;
	//cout << "boom" << endl;
  }
  //cout << (head->s)->getName() << endl;
  p->next = NULL;
  tail = p;
  //cout << "yup" << endl;
}

Node* StudentRoll::gethead() const {
	return head;
}

std::string StudentRoll::toString() const {
  Node* p1;
  p1 = head;
  std::ostringstream oss; 
  oss << "[";
  if (p1 == NULL) {
	oss << "]";
  }
  else {
  	while (p1 != NULL) {
		//cout << (p1->s)->getName() << endl;
		oss << (p1->s)->toString() << ",";
  		p1 = p1->next;
	}
  	oss.seekp(-1, std::ios_base::end);
  	oss << "]";
  }
  return oss.str();
}
     
StudentRoll::StudentRoll(const StudentRoll &orig) {
        head = tail = NULL;
	Node* p1;
	p1 = orig.gethead();
        while (p1 != NULL) {
                insertAtTail(*(p1->s));
                p1 = p1->next;
        }     
}

StudentRoll::~StudentRoll() {
  Node* p;
  p = head;
  Node* n;
  while (p != NULL) {
	//(*(p->s)).~Student();
	//delete p->s;
	n = p->next;
	delete p;
	p = n;
  }
  head = tail = NULL;
}
StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  else {
	(*this).~StudentRoll();
   	head = tail = NULL;
        Node* p1; 
        p1 = right.gethead();
        while (p1 != NULL) {
                insertAtTail(*(p1->s));
                p1 = p1->next;
        }    	
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





