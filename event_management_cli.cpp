#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
class Customer;
class Employee;
class Employee {
private:
    static int id_count;
    int id;
    string name;
    string designation;
    float salary;
    string contact;
    int events_managed;

public:
    Employee() {
        id = 0; name = ""; designation = " ";
        salary = 0; contact = " "; events_managed = 0;
    };
    Employee(string n, string d, float sa, string c, int e) {
        id_count = id_count + 1;
        id = id_count;
        name = n;
        designation = d;
        salary = sa;
        contact = c;
        events_managed = e;
    }
    void setname() {
        cout << "Enter name for employee id " << id << ":" << endl;
        cin.ignore();
        getline(cin, name);
    }
    string getname() {
        return name;
    }
    int getid() {
        return id;
    }
    void setdes() {
        cout << "Enter designation for employee id " << id << ":" << endl;
        cin.ignore();
        cin >> designation;
    }
    void setsalary() {

        cout << "Enter salary for employee id " << id << ":" << endl;

        cin >> salary;


    }
    void eventm() {
        events_managed++;
    }
    string getdes() { return designation; }

    float getsalary() {
        return salary;
    }
    void setcontact() {
        int i = 0, inval = 0;
        do {
            cout << "Enter contact for employee id " << contact << ":" << endl;
            cin >> contact;
            while (contact[i] != '\0') {
                if (!isdigit(contact[i])) {
                    inval = 1; break;
                }
            }
        } while (inval == 1);
    }
    string getcontact() {
        return contact;
    }
    void setev() {
        events_managed++;
    }
    Employee* checksupervisor(Employee employees[], int x) {
        int i = 0;
        for (i = 0; i < x; i++) {
            if (employees[i].designation == "Supervisor") {
                return &employees[i];
            }

        }
        cout << "No supervisor available";
    }
    Employee* checkworker(Employee employees[], int x) {
        int i = 0;
        for (i = 0; i < x; i++) {
            if (employees[i].designation == "Worker") {
                return &employees[i];
            }

        }
        cout << "No worker available";
    }
};
int Employee::id_count = 0;

class Events {
    string EventID = "";
    string type = "";
    string location = "";
    string date = "";
    int total_price = 0;
    int advance = 0;
    int balance = 0;
public:
    Events() {
    };
    void setEventID(string id) {
        EventID = id;
    }
    int checkDate(string reqdate) {
        try {
            int day, month, year;
            day = stoi(reqdate.substr(0, 2));
            month = stoi(reqdate.substr(2, 2));
            year = stoi(reqdate.substr(4, 4));

            if (month > 12 || year != 2023 || day > 28) {
                throw invalid_argument("Invalid input");

            }
            else if (month <= 5 && year == 2023 && day < 10) {
                throw invalid_argument("Date already passed");
            }
            else if (month < 5 && year == 2023) {
                throw invalid_argument("Date already passed");
            }
            return 1;
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
            return 0;
        }
    }

    void setType() {
        int t;
        cout << "Enter\n 1.For Wedding\n2.For Birthday\n3.For Corporate Event\n Any for Custom Event\n";
        cin >> t;
        switch (t) {
        case 1: {
            type = "Wedding";
            break;
        }
        case 2: {
            type = "Birthday";
            break;
        }
        case 3: {
            type = "Corporate";
            break;
        }
        default: {
            type = "Custom";
            break;
        }
        }

    }
    int MatchDate(string curdate) {
        if (this->getDate() == curdate) {
            return 1;
        }
        else {
            return 0;
        }
    }
    void setLocation() {
        string loc;
        int c;
        cout << "Enter:\n1.For indoor\n Any for outdoor";
        cin >> c;
        //   cout << c;
        if (c == 1) {
            location = "Indoor";
        }
        else {
            location = "Outdoor";
        }

    }

    int setDate(string indate) {
        date = indate;
        return 1;
    }

    void setTotalPrice() {
        if (type == "Wedding") {
            total_price += 200000;
        }
        else if (type == "Birthday") {
            total_price += 125000;
        }
        else if (type == "Corporate") {
            total_price += 100000;
        }
        else if (type == "Custom") {
            total_price += 150000;
        }

        if (location == "Indoor") {
            total_price += 75000;
        }
        else if (location == "Outdoor") {
            total_price += 100000;
        }

        total_price = total_price * 1.1;

    }

    void setAdvance(int adv) {
        advance = adv;

    }
    string getEventID() {
        return EventID;
    }

    string getType() {
        return type;
    }

    string getLocation() {
        return location;
    }

    string getDate() {
        return date;
    }

    int getTotalPrice() {
        return total_price;
    }

    int getAdvance() {
        return advance;
    }
    void setBalance() {
        balance = getTotalPrice() - getAdvance();
    }
    int getBalance() {
        return balance;
    }

};
class Customer {
private:

    static int custcount;
    int custID;
    string name;
    string contact;
    bool advpaid;
    Employee* assigned[3];
public:
    friend void setBalance();
    static vector<Events> event;
    Events* ev;
    Customer() {
        custID = 0; name = " "; contact = " "; advpaid = false;
        ev = new Events();
        for (int i = 0; i < 3; i++) {
            assigned[i] = new Employee();

        }
    };
    Customer(string a, string b) {
        custcount++;
        custID = custcount;
        name = a;
        contact = b;
        ev = new Events();
        for (int i = 0; i < 3; i++) {
            assigned[i] = new Employee();

        }
    }

    /* void setCustID(int id) {
         custID = id;
     }*/

    void setName(string n) {
        name = n;
    }
    void addemployee(Employee* emp) {
        int i;
        for (i = 0; i < 3; i++) {
            if (assigned[i]->getname() == "") {
                this->assigned[i] = emp;
                emp->eventm();
                break;
            }
        }

        cout << "An employee slot assigned." << endl;
    }
    bool getadvp() {
        return advpaid;
    }
    void operator <(Customer& c) {
        cout << "************************************************" << endl;
        cout << "Here are the details of the event: " << endl;
        cout << "Name: " << getName() << endl;
        cout << "Location: " << ev->getLocation() << endl;
        cout << "Event Type: " << ev->getType() << endl;
        cout << "Date: " << ev->getDate() << endl;
        cout << "Total: " << ev->getTotalPrice() << endl;
        cout << "Advance: " << ev->getAdvance() << endl;
        cout << "Balance: " << ev->getBalance() << endl;
        cout << "Employees who will assist you along with their designations and phone numbers: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << assigned[i]->getdes() << " " << assigned[i]->getname() << " " << assigned[i]->getcontact() << endl;
        }
        cout << "************************************************" << endl;

    }
    void setContact(string c) {
        int i = 0, inval = 0;
        do {
            while (contact[i] != '\0') {
                if (!isdigit(contact[i])) {
                    inval = 1; contact = " "; break;
                }
                else {
                    contact = c;
                }
            }
        } while (inval == 1);
        contact = c;
    }


    int getCustID() {
        return custID;
    }

    string getName() {
        return name;
    }
    void check() {

    }

    string getContact() {
        return contact;
    }
    void writetxt() {
        ofstream outfile;
        outfile.open("record.txt",ios::app);
        outfile << "Name: " << getName() << endl;
        outfile << "Location: " << ev->getLocation() << endl;
        outfile << "Event Type: " << ev->getType() << endl;
        outfile << "Date: " << ev->getDate() << endl;
        outfile << "Total: " << ev->getTotalPrice() << endl;
        outfile << "Advance: " << ev->getAdvance() << endl;
        outfile << "Balance: " << ev->getBalance() << endl;
        outfile << "Employees assigned: " << endl;
        for (int i = 0; i < 3; i++) {
            outfile << assigned[i]->getdes() << " " << assigned[i]->getname() << " " << assigned[i]->getcontact() << endl;
        }
        outfile.close();
    }
};
int Customer::custcount = 0;
vector<Events> Customer::event;



int main()
{
    string a, b, reqdate;
    int numev = 0, access;
    Employee emp[9] = {
    Employee("Ali","Supervisor",  40000, "03324314564", 0),
    Employee("Ahmed","Supervisor", 40000, "03333454546", 0),
    Employee("Erum","Supervisor", 40000, "03333454554", 0),
    Employee("Hash","Worker", 60000, "03257865655", 0),
    Employee("Linda","Worker", 60000, "03257225432", 0),
    Employee("Farrukh","Worker",  60000, "03257865666", 0),
    Employee("Hasheem","Worker", 60000, "03257865678", 0),
    Employee("Sarim", "Worker", 15000, "03654590681", 0),
    Employee("Imad", "Worker", 20000, "03344553143", 0)
    };
    /* cout << "Name" << "  " << "Contact" << "  " << "Salary" << endl;
     for (int i = 0; i < 5; i++) {
         cout << emp[i].getname() << " " << emp[i].getcontact() << " " << emp[i].getsalary() << endl;
     }*/
    cout << "\t\t\t\t\tWelcome!\n";
    Events eobj[10];
    Customer obj[10];
    int custc = -1;
    access = 1;
    string password = "hashsoban", pass, n;
    int ch, ch2, idd, j;
    srand(time(0));
    while (access == 1 || access == 2) {
        cout << "Enter 0 to exit, 1 if you are customer and 2 if you are admin: ";
        cin >> access;
        switch (access) {
        case 1: {
            cout << "Please enter your name: ";
            cin.ignore();
            getline(cin, a);
            cout << "Please enter your contact number: ";
            cin >> b;
            custc++;
            obj[custc] = Customer(a, b);

            bool dateisset = false; int x, temp = 0;
            while (!dateisset) {
                cout << "Enter your event date in  DDMMYYYY format: ";
                cin >> reqdate;

                for (x = 0; x < custc; x++) {
                    temp = +obj[custc].ev->MatchDate(reqdate);
                }
                if ((temp < 1) && (obj[custc].ev->checkDate(reqdate) == 1)) {
                    dateisset = true;
                    eobj[custc].setDate(reqdate);
                }
                else {
                    cout << "Sorry, we aren't available on this date due to already booked events";
                    dateisset = false;
                }

            }
            int tempadv;

            (obj[custc].ev)->setLocation();
            (obj[custc].ev)->setType();
            (obj[custc].ev)->setDate(reqdate);
            obj[custc].ev->setTotalPrice();
            cout << "How much advance would you like to pay? ";
            cin >> tempadv;
            (obj[custc].ev)->setAdvance(tempadv);
            (obj[custc].ev)->setBalance();
            numev = 0;
            for (int i = 0; i < custc; i++) {
                
                numev+=obj[custc].ev->MatchDate(reqdate);
            }

            if (numev == 0) {
                obj[custc].addemployee(&emp[0]);
                obj[custc].addemployee(&emp[3]);
                obj[custc].addemployee(&emp[4]);
            }
            else if (numev == 1) {
                obj[custc].addemployee(&emp[1]);
                obj[custc].addemployee(&emp[5]);
                obj[custc].addemployee(&emp[6]);
            }
            else if (numev == 2) {
                obj[custc].addemployee(&emp[2]);
                obj[custc].addemployee(&emp[7]);
                obj[custc].addemployee(&emp[8]);
            }
            

            obj[custc] < (obj[custc]);
            obj[custc].writetxt();
            break;
        }
        case 2: {
            //admin
            cout << "Enter password for admin:";
            cin >> pass;
            while (password != pass) {
                cout << "Incorrect password! Enter again!";
                cin >> pass;
            }
            cout << "Admin Access Granted!\n1.Change Employee name\n2.Change employee designation\n3.Change employee salary\n4.Change employee contact\n5.View employee details\n";
            cin >> ch2;
            if (ch2 == 1) {
                cout << "Enter employee id:";
                cin >> idd;
                if (idd > 9) {
                    cout << "Invalid input!"; break;
                }
                for (j = 0; j < 9; j++) {
                    if (emp[j].getid() == idd) {
                        emp[j].setname();
                    }
                }
            }
            else if (ch2 == 2) {
                cout << "Enter employee id:";
                cin >> idd;
                if (idd > 9) {
                    cout << "Invalid input!"; break;
                }
                for (j = 0; j < 9; j++) {
                    if (emp[j].getid() == idd) {
                        emp[j].setdes();
                    }
                }
            }
            else if (ch2 == 3) {
                cout << "Enter employee id:";
                cin >> idd;
                if (idd > 9) {
                    cout << "Invalid input!"; break;
                }
                for (j = 0; j < 9; j++) {
                    if (emp[j].getid() == idd) {
                        emp[j].setsalary();
                    }
                }
            }
            else if (ch2 == 4) {
                cout << "Enter employee id:";
                cin >> idd;
                if (idd > 9) {
                    cout << "Invalid input!"; break;
                }
                for (j = 0; j < 9; j++) {
                    if (emp[j].getid() == idd) {
                        emp[j].setcontact();
                    }
                }
            }
            else if (ch2 == 5) {
                cout << "Enter employee id:";
                cin >> idd;
                if (idd > 9) {
                    cout << "Invalid input!"; break;
                }
                for (j = 0; j < 9; j++) {
                    if (emp[j].getid() == idd) {
                        cout << "Name" << "  " << "Designation" << "  " << "Contact" << "  " << "Salary" << endl;
                        cout << emp[j].getname() << " " << emp[j].getdes() << " " << emp[j].getcontact() << " " << emp[j].getsalary() << endl;
                    }
                }
            }
        }
        }
    }
}