/*
#include<iostream>
#include<math.h>
using namespace std;
class complex {
private:
    float re;
    float im;
public:
    complex(float re, float im) {
        this->re = re;
        this->im = im;
    }
    complex(float r) {
        re = r;
        im = 0.0;
    }

    ~complex() {};

    double Magnitude() {
        return sqrt(re * re + Imag() * Imag());
    }

    float Real() {
        return re;
    }

    float Imag() {
        return im;
    }

    complex operator+(complex c) {
        return complex(re + c.Real(), im + c.Imag());
    }

    complex operator-(complex c) {
        return complex(re - c.Real(), im - c.Imag());
    }

    complex operator*(complex c) {
        return complex(re * c.Real() - im * c.Imag(), re * c.Imag() + im * c.Real());
    }
};

int main() {
    complex a(1.0, 2.0);
    complex* b = new complex(5.0);
    complex c(0, 0);

    cout << "a real =" << a.Real() << endl;
    cout << "a imag =" << a.Imag() << endl;

    cout << "b real =" << b->Real() << endl;
    cout << "b imag =" << b->Imag() << endl;

    c = a + *b;
    cout << "c real =" << c.Real() << endl;
    cout << "c imag =" << c.Imag() << endl;

    c = a - *b;
    cout << "c real =" << c.Real() << endl;
    cout << "c imag =" << c.Imag() << endl;

    c = a * *b;
    cout << "c real =" << c.Real() << endl;
    cout << "c imag =" << c.Imag() << endl;

    complex* c2 = new complex(1.0, 1.0);
    cout << "c2 real =" << c2->Real() << endl;
    cout << "c2 imag =" << c2->Imag() << endl;
    cout << "c2 magnitude =" << c2->Magnitude() << endl;

    delete b;
    return 0;
}

*/
/*#include<iostream>
using namespace std;
template <class T>
class mypair {
    T a, b;
public:
    mypair(T first, T second) {
        a = first;
        b = second;
    }
    T getmax();
    T getmin() {
        T retval;
        retval = a < b ? a : b;
        return retval;
    }
};
template <class T>
T mypair<T>::getmax() {
    T retval;
    retval = a > b ? a : b;
    return retval;
}
int main() {
    mypair<int> myobject(100, 75);
    cout << myobject.getmax();
    cout << myobject.getmin();
    return 0;
}
*/
/*
#include<iostream>
using namespace std;

template <class T, int N>
class mysequence
{
    T memblock[N];
public:
    void setmember(int x, T value);
    T getmember(int x);
    T getmin();
    T getmax();
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value)
{
    memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x)
{
    return memblock[x];
}

template <class T, int N>
T mysequence<T, N>::getmin()
{
    T minValue = memblock[0];
    for (int i = 1; i < N; ++i)
    {
        if (memblock[i] < minValue)
        {
            minValue = memblock[i];
        }
    }
    return minValue;
}

template <class T, int N>
T mysequence<T, N>::getmax()
{
    T maxValue = memblock[0];
    for (int i = 1; i < N; ++i)
    {
        if (memblock[i] > maxValue)
        {
            maxValue = memblock[i];
        }
    }
    return maxValue;
}

int main()
{
    mysequence<int, 5> myints;
    mysequence<double, 5> myfloats;

    myints.setmember(0, 100);
    myints.setmember(1, 200);
    myints.setmember(2, 50);
    myints.setmember(3, 75);
    myints.setmember(4, 10);

    myfloats.setmember(0, 3.14);
    myfloats.setmember(1, 2.71);
    myfloats.setmember(2, 1.61);
    myfloats.setmember(3, 1.41);
    myfloats.setmember(4, 2.23);

    cout << "First integer in myints: " << myints.getmember(0) << '\n';
    cout << "Fourth float in myfloats: " << myfloats.getmember(3) << '\n';
    cout << "Minimum integer in myints: " << myints.getmin() << '\n';
    cout << "Maximum integer in myints: " << myints.getmax() << '\n';
    cout << "Minimum float in myfloats: " << myfloats.getmin() << '\n';
    cout << "Maximum float in myfloats: " << myfloats.getmax() << '\n';

    return 0;
}
*/
/*#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main() {
    ofstream outFile;
    outFile.open("fout.txt");
    ifstream inFile("fin.txt");
    char ch;
    int countChars = 0;
    int countWords = 0;
    int countSentences = 0;
    bool inWord = false;

    if (!inFile) {
        cerr << "File could not be opened!" << endl;
        return 1;
    }

    while (inFile.get(ch)) {
        outFile.put(ch);
        countChars++;
        if (isspace(ch) || ispunct(ch)) {
            if (inWord) {
                countWords++;
                inWord = false;
            }
        }
        else {
            inWord = true;
        }
        if (ch == '.' || ch == '!' || ch == '?') {
            countSentences++;
        }
    }
    if (inWord) {
        countWords++;
    }
    outFile << "\n\n" << countChars << " characters copied.\n";
    outFile << countWords << " words in the file.\n";
    outFile << countSentences << " sentences in the file.\n";

    inFile.close();
    outFile.close();

    return 0;
}


*/
/*#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class House {
private:
    string owner;
    string address;
    int bedrooms;
    float price;

public:

    void readData() {
        cout << "Enter Owner: ";
        getline(cin, owner);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Number of Bedrooms? ";
        cin >> bedrooms;
        cout << "Price: ";
        cin >> price;
        cin.ignore();
    }


    void outputData() const {
        cout << left << setw(15) << owner
            << setw(20) << address
            << setw(12) << bedrooms
            << setw(12) << fixed << setprecision(2) << price << endl;
    }
};

const int MAX_HOUSES = 100;

int main() {
    House available[MAX_HOUSES];
    int count = 0;
    char choice;
    do {
        cout << "Enter details for House " << count + 1 << endl;
        available[count].readData();

        count++;
        if (count >= MAX_HOUSES) {
            cout << "Maximum limit reached!" << endl;
            break;
        }


        cout << "Enter another house? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'Y' || choice == 'y');


    cout << "\nOwner           Address             Bedrooms    Price\n";
    for (int i = 0; i < count; i++) {
        available[i].outputData();
    }

    return 0;
}

*/
/*#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int* grades;
    int numGrades;

public:
    
    Student(string studentName = "", int n = 0) : name(studentName), numGrades(n) {
        grades = new int[numGrades] {}; // Initialize array with zeroes
    }

    
    ~Student() {
        delete[] grades;
    }

    
    void setGrades(int* gradesInput) {
        for (int i = 0; i < numGrades; i++) {
            grades[i] = gradesInput[i];
        }
    }

   
    double getAverage() const {
        if (numGrades == 0) return 0; 
        double sum = 0;
        for (int i = 0; i < numGrades; i++) {
            sum += grades[i];
        }
        return sum / numGrades;
    }

    
    void displayStudentData() const {
        cout << left << setw(20) << name;
        for (int i = 0; i < numGrades; i++) {
            cout << setw(5) << grades[i];
        }
        cout << setw(10) << getAverage() << endl;
    }

   
    string getName() const {
        return name;
    }
};

void displayAllStudents(Student students[], int numStudents) {
    cout << left << setw(20) << "Name" << setw(5) << "Grade 1" << setw(5) << "Grade 2" << setw(5) << "Grade 3" << setw(10) << "Average" << endl;
    for (int i = 0; i < numStudents; i++) {
        students[i].displayStudentData();
    }
}

void displayStudentAverage(Student students[], int numStudents, string studentName) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].getName() == studentName) {
            cout << "Average grade for " << studentName << ": " << students[i].getAverage() << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}



void displayHighestGrade(Student students[], int numStudents) {
    double highest = -1.0;
    string studentWithHighest;
    for (int i = 0; i < numStudents; i++) {
        double avg = students[i].getAverage();
        if (avg > highest) {
            highest = avg;
            studentWithHighest = students[i].getName();
        }
    }
    cout << "Highest average grade is " << highest << " by " << studentWithHighest << endl;
}

void displayLowestGrade(Student students[], int numStudents) {
    double lowest = 101.0;
    string studentWithLowest;
    for (int i = 0; i < numStudents; i++) {
        double avg = students[i].getAverage();
        if (avg < lowest) {
            lowest = avg;
            studentWithLowest = students[i].getName();
        }
    }
    cout << "Lowest average grade is " << lowest << " by " << studentWithLowest << endl;
}

int main() {
    ifstream fin("input.dat");
    if (!fin) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    int numStudents, numGrades;
    fin >> numStudents >> numGrades;
    Student* students = new Student[numStudents];

    string name;
    for (int i = 0; i < numStudents; i++) {
        fin >> name;
        string lastName;
        fin >> lastName;
        name += " " + lastName;
        int* grades = new int[numGrades];
        for (int j = 0; j < numGrades; j++) {
            fin >> grades[j];
        }
        students[i] = Student(name, numGrades);
        students[i].setGrades(grades);
        delete[] grades;
    }
    fin.close();

    int choice;
    do {
        cout << "\nStudent Grades Database\n";
        cout << "1. Display all students\n";
        cout << "2. Display average grade of a student\n";
        cout << "3. Display highest grade\n";
        cout << "4. Display lowest grade\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            displayAllStudents(students, numStudents);
        }
        else if (choice == 2) {
            string studentName;
            cout << "Enter student name: ";
            getline(cin, studentName);
            displayStudentAverage(students, numStudents, studentName);
        }
        else if (choice == 3) {
            displayHighestGrade(students, numStudents);
        }
        else if (choice == 4) {
            displayLowestGrade(students, numStudents);
        }
    } while (choice != 5);

    delete[] students; 
    return 0;
}
*/
