//********** student.cpp **********


#include "student.h"
#include <iostream>

Student::Student() : majorLen(10) {
    Personal();
    major = new char[majorLen + 1];
}

Student::Student(char *ssn, char *n, char *c, int y, long s, char *m) : majorLen(11) {
    Personal(ssn,n,c,y,s);
    major = new char[majorLen + 1];
    strcpy(major, m);
}

void Student::writeToFile(std::ofstream& out) const {
    Personal::writeToFile(out);
    out.write(major,majorLen);
}

void Student::readFromFile(std::ifstream& in) {
    Personal::readFromFile(in);
    in.read(major, majorLen);
}

std::ofstream& Student::writeLegibly(std::ofstream& out) {
    Personal::writelegibly(out);
    major[majorLen] = '\0';
    out << ", major = " << major;
    return out;
}

std::ifstream& Student::readFromConsole(std::ifstream& in) {
    Personal::readFromConsole(in);
    char s[80];
    std::cout << "Major: ";
    in.getline(s,80);
    strncpy(major,s,9);
    return in;
}
