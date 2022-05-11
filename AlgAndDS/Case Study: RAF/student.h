//********** student.h **********

#include "personal.h"

class Student : public Personal {
    public:
        Student();
        Student(char*,char*,char*,int,long,char*);
        void writeToFile(std::ofstream&) const;
        void readFromFile(std::ifstream&);
        int size() const {
            return Personal::size() + majorLen;
        }
    protected:
        char *major;
        const int majorLen;
        std::ofstream& writeLegibly(std::ofstream&);
        friend std::ofstream& operator<<(std::ofstream& out, Student& sr) {
            return sr.writeLegibly(out);
        }
        std::ifstream& readFromConsole(std::ifstream&);
        friend std::ifstream& operator>>(std::ifstream& in, Student& sr) {
            return sr.readFromConsole(in);
        }
};