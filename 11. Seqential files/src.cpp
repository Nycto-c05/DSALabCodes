/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data
*/

#include <iostream>
#include <fstream>
using namespace std;

class file
{
public:
    int rollno;
    string name;
    char div;
    string addr;

    void accept()
    {
        cout << "\n\tEnter Roll Number : ";
        cin >> rollno;
        cout << "\n\tEnter the Name : ";
        cin >> name;
        cout << "\n\tEnter the Division:";
        cin >> div;
        cout << "\n\tEnter the Address:";
        cin >> addr;
    }

    int getRollNo()
    {
        return rollno;
    }

    void show()
    {

        cout << "\n\t" << rollno << "\t\t" << name << "\t\t" << div << "\t\t" << addr;
    }
};

int main()
{
    file f1;
    string name;
    int choice, ch1;
    int roll;
    fstream f, g;
    do
    {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<";
        cout << "\n1.Insert\n2.Show\n3.Search\n4.Delete a Student Record\n5.Exit\n\tEnter the Choice --> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            f.open("student.txt", ios::out);
        x:
            f1.accept();
            f.write((char *)&f1, sizeof(f1));

            cout << "\nDo you want to enter more records?\n1.Yes\n2.No\n--> ";
            cin >> ch1;
            if (ch1 == 1)
                goto x;
            else
            {
                f.close();
                break;
            }

        case 2:
            f.open("student.txt", ios::in);
            f.read((char *)&f1, sizeof(f1));

            while (f)
            {
                f1.show();
                f.read((char *)&f1, sizeof(f1));
            }
            f.close();
            break;

        case 3:
            cout << "Enter Roll No. --> ";
            cin >> roll;
            f.open("student.txt", ios::in);
            f.read((char *)&f1, sizeof(f1));
            while (f)
            {
                if (roll == f1.rollno)
                {
                    f1.show();
                    break;
                }
                f.read((char *)&f1, sizeof(f1));


            }
            f.close();
            break;

        case 4:
            cout << "Enter Roll No. of student to delete --> ";
            cin >> roll;
            f.open("student.txt", ios::in);
            g.open("temp.txt", ios::out);

            f.read((char *)&f1, sizeof(f1));
            while (f)
            {
                if (f1.rollno != roll)
                {
                    g.write((char *)&f1, sizeof(f1));
                }
                f.read((char *)&f1, sizeof(f1));
            }
            cout << "The record with the roll no. " << roll << " has been deleted " << endl;
            f.close();
            g.close();
            remove("student.txt");
            rename("temp.txt", "student.txt");
            break;
        }

    } while (choice != 5);

    return 0;
}
