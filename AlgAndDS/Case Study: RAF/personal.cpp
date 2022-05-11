//********** personal.cpp **********

#include "personal.h"
#include <iostream>

Personal::Personal() : nameLen(10), cityLen(10)
{
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
}

Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10)
{
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
    strcpy(SSN, ssn);
    strcpy(name, n);
    year = y;
    salary = s;
}

void Personal::writeToFile(std::ofstream& out) const {
    out.write(SSN, 9);
    out.write(name, nameLen);
    out.write(city, cityLen);
    out.write(reinterpret_cast<const char*>(&year), sizeof(int));
    out.write(reinterpret_cast<const char*>(&salary), sizeof(int));
}

void Personal::readFromFile(std::ifstream& in) {
    in.read(SSN, 9);
    in.read(name, nameLen);
    in.read(city, cityLen);
    in.read(reinterpret_cast<char*>(&year), sizeof(int));
    in.read(reinterpret_cast<char*>(&salary),sizeof(int));
}

void Personal::readKey() {
    char s[80];
    std::cout << "Enter SSN: ";
    std::cin.getline(s,80);
    strncpy(SSN,s,9);
}

std::ofstream& Personal::writelegibly(std::ofstream& out) {
    SSN[9] = name[nameLen] = city[cityLen] = '\0';
    out << "SSN = " << SSN << ", name = " << name << ", city = " << city << ", year = " << year << ", salary = " << salary;
    return out;
}

std::ifstream& Personal::readFromConsole(std::ifstream& in) {
    char s[80];
    std::cout << "SSN: ";
    in.getline(s,80);
    strncpy(SSN,s,9);
    std::cout << "Name: ";
    in.getline(s,80);
    strncpy(name,s,nameLen);
    std::cout << "City: ";
    in.getline(s,80);
    strncpy(city,s,cityLen);
    std::cout << "Year of Birth: ";
    in >> year;
    std::cout << "Salary: ";
    in >> salary;
    in.getline(s,80); //get'\n
    return in;
}

