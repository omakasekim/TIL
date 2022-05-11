//********** useDatabase.cpp *********

#include <iostream>
#include "student.h"
#include "personal.h"
#include "database.h"

int main() {
    Database<Personal> db;
//  Database<Student> db;
    db.run();
}