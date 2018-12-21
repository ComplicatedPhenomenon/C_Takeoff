/**
 * Every object in c++ has access to its own address through an import pointer called this pointer. 
 **/

#include<iostream>
using namespace std;

// This is the interface class

class Person{
    // No implementation for the virtual function
    virtual int Calculate()=0;
};

class Student:Person{
    //Defining a student class with 5 properties
    private:
        string Name;
        int ID;
        int marks1;
        int marks2;
        int marks3;
    public:
        void setName(string pName){
            this->Name = pName;
        }
        void setID(int pID){
            this->ID=pID;
        }

        void setmarks1(int pmarks1){
            this->marks1 = pmarks1;
        }

        void setmarks2(int pmarks2){
            this->marks2 = pmarks2;
        }

        void setmarks3(int pmarks3){
            this->marks3 = pmarks3;
        }

        string getName(){
            return this->Name;
        }

        int getID(){
            return this->ID;
        }

        int getmarks1(){
            return this->marks1;
        }

        int getmarks2(){
            return this->marks2;
        }

        int getmarks3(){
            return this->marks3;
        }

        int Calculate(){
            return this->marks1 + this->marks2 + this->marks3;
        }
};

int main(){
    Student stud1;
    stud1.setID(1);
    stud1.setName("Joe");
    stud1.setmarks1(5);
    stud1.setmarks2(10);
    stud1.setmarks3(15);

    cout << "The Id of the student is " << stud1.getID() << endl;
    cout << "The name of the student is " << stud1.getName() << endl;
    cout << "The marks of subject 1 of the student is " << stud1.getmarks1() << endl;
    cout << "The marks of subject 2 of the student is " << stud1.getmarks2() << endl;
    cout << "The marks of subject 3 of the student is " << stud1.getmarks3() << endl;
    cout << "The total marks of the student is " << stud1.Calculate() << endl;

    return 0;
}
