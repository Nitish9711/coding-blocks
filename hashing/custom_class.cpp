#include <iostream>
#include<cstring>
#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

class Student{
    public:

    string firstname;
    string lastname;
    string rollno;

    Student(string f,string l,string no){
        firstname = f;
        lastname  = l;
        rollno = no;
    }

    bool operator==(const Student &s) const{
       return rollno == s.rollno;
    }
};

class HashFn{
    public:
    // stores the size of some datatype
    size_t operator()(const Student &s) const{
        return s.firstname.length() + s.lastname.length();
    }
};



int main() {

    unordered_map<Student, int, HashFn> student_map;


    Student s1("Prateek","Narang","010");
    Student s2("Rahul","Kumar","023");
    Student s3("Prateek","Gupta","030");
    Student s4("Rahul","Kumar","120");
    // student_map.insert(make_pair(s1.firstname, s1.rollno);
    student_map[s1] = 100;
    student_map[s2] = 150;
    student_map[s3] = 512;
    student_map[s4] = 215;



    for(auto s: student_map){
        cout<<s.first.firstname<<" "<<s.first.rollno<<endl;
    }

    return 0;
}
