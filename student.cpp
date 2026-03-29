#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <ostream>
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
    student s;
    int id;
    bool fount = false;
    while (true) {
      cout << "Enter ID that user you can cheak : ";
      cin >> id;

      if (id == 0) {
        cout << "ID cannot be 0 . Enter write id ." << endl;
      } else {
        FILE *file = fopen("student.dat", "rb");
        if (!file) {
          cout << "No file found ." << endl;
          return;
        }
        while (fread(&s, sizeof(student), 1, file)) {
          if (s.id == id) {
            cout << "\n--- Student Found ---\n";
            cout << "ID      : " << s.id << "\n";
            cout << "Name    : " << s.name << "\n";
            cout << "Mobile  : " << s.mobile_no << "\n";
            cout << "Address : " << s.address << "\n";
            fount = true;
            return;
          } else {
            // cout << "not found Tuy again ." << endl;
          }
          cout << "Not found Try agein ." << endl;
        }
        fclose(file);
      }
    }
  }
  void delete_id(void) {
    student s;
    int id;
    bool find = false;
    cout << "Enter Your id that you can delete : ";
    cin >> id;
    FILE *file = fopen("student.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    while (fread(&s, sizeof(student), 1, file) == 1) {
      if (s.id == id) {
        find = true; // skip that from file and delete it;
      } else {
        fwrite(&s, sizeof(student), 1, temp);
      }
    }

    fclose(file);
    fclose(temp);

    if (find) {
      remove("student.dat");
      rename("temp.dat", "student.dat");
      cout << "Delete done ;) " << endl;
    } else {
      cout << "id not found .";
    }
  }
};

int main() {
  int option;
  Student s;
  while (true) {

    cout << "Student Page : \n1) Add user \n2) Cheak student\n3) Delete "
            "id\nEnter Your "
            "option : ";
    cin >> option;

    if (option == 1) {
      s.take_inp();
      break;
    } else if (option == 2) {
      s.cheak_id();
      break;
    } else if (option == 3) {
      s.delete_id();
      break;
    } else {
      cout << "You put wrong option . " << endl;
    }
  }
  return 0;
}
