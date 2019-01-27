#include "student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

Student::Student(const char * const name, int perm) {
  //cout << "testing1" << endl;
  //this->setName(name);
  this->name = NULL;
  this->setName(name);;
  this->setPerm(perm);
  //cout << "testing1 worked" << endl;
}

int Student::getPerm() const {
  //cout << "testing2" << endl;
   return perm;
}

const char * const Student::getName() const {
  //cout << "testing3" << endl;
	return name;
}

void Student::setPerm(const int permNumber) {
  //cout << "testing4" << endl; 
  perm = permNumber;
  //cout << "testing 4 worked" << endl;
}

void Student::setName(const char * const name) {
  //cout << "testing 5" << endl;
  //if ((this->name)[0] != '\0') { 
  	//cout << "checking" << endl;
	//printf(this->name);
        //cout << "about to delete" << endl;
   if (this->name != NULL) {	
	delete [] this->name;
   }
  //}
  //cout << "okay so far" << endl;
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
  //cout << "testing 5 worked" << endl;
}


Student::Student(const Student &orig) {
  //this->
  //cout << "testing 6" << endl;
  name = NULL;
  setName(orig.getName());
  //this->
  setPerm(orig.getPerm());
  //cout << "testing 6 worked" << endl;
}

Student::~Student() {
	//cout << "testing 7" << endl;
	if (name != NULL) {
		delete [] name; 
	}
	//cout << "testing 7 worked" << endl;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)
  //cout << "testing 8" << endl;
  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
   else {
	 //this->
	this->setName(right.getName());
  	//this->
  	this->setPerm(right.getPerm());
    }
	

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss; 
  oss << "[" 
      << this->getName() << "," 
      << this->getPerm() <<  "]";
  return oss.str();
}

