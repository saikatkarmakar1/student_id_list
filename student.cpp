#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
public:
  void take_inp(void) { // That will for user input from school
    int roll, mob_no, perse;
    string fast_name, last_name, address, mobile_no;
    while (true) {
      cout << "Enter student roll no : ";
      cin >> roll;
      string _roll_ = to_string(roll);
      if (_roll_.length() == 0) {
        cout << "please enter Roll no" << endl;
      } else {
        break;
      }
    }
    cout << "Enter student name : ";
    cin >> fast_name >> last_name;
    while (true) {
      cout << "Enter Your mobile no (10 digit) : ";
      cin >> mob_no;
      mobile_no = to_string(mob_no);

      if (mobile_no.length() == 10) {
        break;
      } else {
        cout << "Invalid! mobile no , Enter again . " << endl;
      }
    }
    while (true) {
      cout << "Enter address : ";
      cin >> address;
      if (address.length() == 0) {
        cout << "Please enter address . ";
      } else {
        break;
      }
    }
    string roll_str = to_string(roll);
    string total = "\nRoll no : " + roll_str + "\nName : " + fast_name + " " +
                   last_name + "\nMobile No. : " + mobile_no +
                   "\nAdress : " + address + "\n";
    cout << total << endl;
    ofstream file("list.txt", ios::app);
    if (!file) {
      cout << "File no open ," << endl;
      return;
    }
    file << total;
    file.close();
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
