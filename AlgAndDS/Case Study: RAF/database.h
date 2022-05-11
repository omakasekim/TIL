//********** database.h *********

#ifndef DATABASE
#define DATABASE

#include <fstream>
#include <iostream>

template<class T> class Database {
    public:
        Database();
        void run();
    private:
        std::fstream database;
        char fName[20];
        std::ofstream& print(std::ofstream&);
        void add(T&);
        bool find(const T&);
        void modify(const T&);
        friend std::ofstream& operator<<(std::ofstream& out, Databse& db) {
            return db.print(out);
        }
};

template<class T> Database<T>::Database() {
    std::cout << "File name: ";
    std::cin >> fName;
}

template<class T> void Database<T>::add(T& d) {
    database.open(fName,ios::in|ios::out|ios::binary);
    database.seekp(0,ios::end);
    d.writeTOFile(database);
    database.close()
}

template<class T> void Database<T>::modify(const T& d) {
    T tmp;
    database.open(fName,ios::in|ios::out|ios::binary);
    while(!database.eof()) {
        tmp.readFromFile(database);
        if(tmp == d) { //overloaded ==
            std::cin >> tmp; //overloaded >>
            database.seekp(-d.size(),ios::cur);
            tmp.writeToFile(database);
            database.close()
            return;
        }
    }
    database.close();
    std::cout << "The record to be modified is not in the database.\n";
}

template<class T> bool Database<T>::find(const T& d) {
    T tmp;
    database.open(fName,ios::in|ios::out|ios::binary);
    while(!database.eof()){
        tmp.readFromFile(database);
        if(tmp == d) { //overloaded ==
            database.close();
            return true;
        }
    }
    database.close();
    return false;
}

template<class T> std::ofstream& Database<T>::print(std::ofstream& out) {
    T.tmp;
    database.open(fName,ios::in|ios::out|ios::binary);
    while(1) {
        tmp.readFromFile(database);
        if(database.eof())
            break;
        out << tmp << endl; // overloaded <<
    }
    database.close();
    return out;
}

template<class T>
void Database<T>::run() {
    char option[5];
    T rec;
    std::cout << "1. Add 2. Find 3. Modify a record 4. Exit\n";
    std::cout << "Enter an option: ";
    std::cin.getline(option,4); //get option along with '\n'
    while(std::cin.getline(option,4)) {
        if(*option == '1') {
            std::cin >> rec; //overloaded >>
            add(rec);
        }
        else if(*option == '2') {
            rec.readKey();
            std::cout << "The record is ";
            if(find(red) == false)
                std::cout << "not ";
            std::cout << "in the database\n";
        }
        else if(*option == '3') {
            rec.readKey();
            modify(rec);
        }
        else if(*option == '4')
            std::cout << "Wrong option\n";
        else return;

        std::cout << *this; //overloaded <<
        std::cout << "Enter an option: ";
    }
}

#endif
