#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct student {
  int id;
  char name[50];
  char mobile_no[15];
  char address[100];
};
class Student {
private:
public:
  void take_inp(void) { // That will for user input from school
    student s;
    while (true) {
      cout << "Enter student roll no : ";
      cin >> s.id;
      string _roll_ = to_string(s.id);
      if (_roll_.length() == 0) {
        cout << "please enter Roll no" << endl;
      } else {
        break;
      }
    }
    while (true) {
      cout << "Enter student name : ";
      cin.getline(s.name, 50);
      if (strlen(s.name) == 0) {
        cout << "Please Enter Your name : " << endl;
      } else {
        break;
      }
    }

    while (true) {
      cout << "Enter Your mobile no (10 digit) : ";
      cin.getline(s.mobile_no, 15);

      if (strlen(s.mobile_no) == 10) {
        break;
      } else {
        cout << "Invalid! mobile no , Enter again . " << endl;
      }
    }
    while (true) {
      cout << "Enter address : ";
      cin.getline(s.address, 100);
      if (strlen(s.address) == 0) {
        cout << "Please enter address . ";
      } else {
        break;
      }
    }
    FILE *file = fopen("student.dat", "ab");
    fwrite(&s, sizeof(student), 1, file);
    fclose(file);
    cout << "Student add completeddd... ;) " << endl;
  }
  void cheak_id(void) {
    int id;
    cout << "Enter id to find student (If you show all student list then put 0 "
            "): ";
    cin >> id;
    if (id == 0) { // That is for cheal all id ;
      cout << "That is all user list :--- " << endl;
      ifstream file("list.txt");
      string line;

      if (!file) {
        cout << "File not open ." << endl;
        return;
      }

      while (getline(file, line)) {
        cout << line << endl;
      }
      file.close();
    }
  }
};

int main() {
  Student saikat;
  saikat.take_inp();

  return 0;
}
