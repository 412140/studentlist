#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;
/*
Ghazi Abbas
Fall Semester CPP

student list project. Add/delete/print from an editable list

sources:
https://www.geeksforgeeks.org/vector-in-cpp-stl/
https://www.geeksforgeeks.org/structures-in-cpp/
https://www.geeksforgeeks.org/cpp-vector-of-structs/
https://www.geeksforgeeks.org/iterators-c-stl/
https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp
https://cplusplus.com/reference/iterator/
https://stackoverflow.com/questions/51586495/what-is-an-iterator-in-general
+ Galbraiths online videos (canvas pages)
*/
struct Student { //fronm canvas video
    char firstName[50];
    char lastName[50];
    int studentId;
    float gpa;
};

void addStudent(vector<Student*>& students) //https://www.youtube.com/watch?v=RXzzE2wnnlo
{
  Student* newStudent = new Student(); //from stack heap visualizer videos ( i cant remember which one)
    cout << "Enter first name: " << endl;
    cin >> newStudent->firstName;
    cout << "Enter last name: " << endl;
    cin >> newStudent->lastName;
    cout << "Enter student ID: " << endl;
    cin >> newStudent->studentId;
    cout << "Enter GPA: " << endl;
    cin >> newStudent->gpa;
    students.push_back(newStudent);//from https://www.geeksforgeeks.org/vector-in-cpp-stl/
}

void printStudents(const vector<Student*>& students) //https://www.youtube.com/watch?v=RXzzE2wnnlo
{
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        cout << (*it)->firstName << " " << (*it)->lastName << ", "
             << (*it)->studentId << ", " << fixed << setprecision(2)
             << (*it)->gpa << endl;
    }//i know this may not be the best way but i believe i got it to work. Also i made it look nice.
}

void deleteStudent(vector<Student*>& students, int studentId) // https://www.youtube.com/watch?v=wjfb2kT6dtI
{
    auto it = students.begin();
    while (it != students.end())
    {
        if ((*it)->studentId == studentId)
        {
            delete *it;
            it = students.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    vector<Student*> students;

    char rsp[10];
    int studentId;

    while (true)
      {// mostly from old projects, iterator is again from the video.
        cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
        cin >> rsp;
	//had it in all caps like the canvas page but i couldve just used tolower or toupper i think but this is fine
        if (strcmp(rsp, "ADD") == 0)
        {
            addStudent(students);
        }
        else if (strcmp(rsp, "PRINT") == 0)
        {
            printStudents(students);
        }
        else if (strcmp(rsp, "DELETE") == 0)
        {
            cout << "Enter student ID to delete: ";
            cin >> studentId;
            deleteStudent(students, studentId);
        }
        else if (strcmp(rsp, "QUIT") == 0)
        {
            // Clean up allocated memory before exiting, I cant find what youtube video this is from but it specifically helped me because before it wasnt pre increment.
            for (auto it = students.begin(); it != students.end(); ++it)
            {
                delete *it;
            }
            students.clear();
            break;
        }
        else
        {
	  cout << "Unknown command. Try again." << endl;
        }
    }
}
