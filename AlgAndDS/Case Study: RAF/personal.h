//********** personal.h **********

#ifndef PERSONAL
#define PERSONAL

#include <fstream>
#include <string.h>

class Personal {
    public:
        Personal();
        Personal(char*,char*,char*, int,long);
        void writeToFile(std::ofstream&) const;
        void readFromFile(std::ifstream&);
        void readKey();
        int size() const {
            return 9 + nameLen + cityLen + sizeof(year) + sizeof(salary);
        }
        bool operator==(const Personal& pr) const {
            return strcmp(pr.SSN, SSN) == 0;
        }
    protected:
        const int nameLen, cityLen;
        char SSN[10], *name, *city;
        int year;
        long salary;
        std::ofstream& writelegibly(std::ofstream&);
        friend std::ofstream& operator<<(std::ofstream& out, Personal& pr) {
            return pr.writelegibly(out);
        }
        std::ifstream& readFromConsole(std::ifstream&);
        friend std::ifstream& operator>>(std::ifstream& in, Personal& pr) {
            return pr.readFromConsole(in);
        }
};

#endif
