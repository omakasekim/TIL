# Case Study: Random Access File

This case study is primarily designed to illustreate the use of generic classes and inheritance.

From the perspective of the operating systems, files are collection of bytes, regardless of their contents. From the user's perspective, files are collection of words, numbers, data sequences, records, and so on.

If the user wants to access the fifth word in a text file, a searching procedure goes sequentially through the file starting at position 0 and checks all of the bytes along the way. it counts the number of sequences of blank characters, and after it skips four such sequences (or five if a sequence of blanks begins the file), it stops because it encounters the beginning of the fifth nonblank sequence or the fifth word.

This word can begin at any position of the file. it is impossible to go to a particular position of any text file and be certain that this is a starting position of the fifth word of the file.

Ideally, we want to go directly to a certain position of the file and be sure that the fifth word begins in it. The problem is caused by the length of the preceding words and sequences of blanks. If we know that each word occupies the same amount of space, then it is possible to go directly to the fifth word by going to the position 4 * length (word).

But because words are of various lengths, this can be accomplished by assigning the same number of bytes to each word; if a word is horter, some padding characters are added to fill up the remaining space; if it is longer, then the word is trimmed, In this way, a new organisation is imposed on the file. The file is now treated not mearly as a collection of bytes, but as a collection of records; in our example, each record consists of one word.

If a request comes to access the fifth word, the word can be directly accessed without looking at the preceding words. With the new organisation, we created a random access file.

A random access file allows for direct access of each record. The record usually includes more items than one word. The preceding example suggests one way of creating a random acess file, namely, by using fixed-length words. Our task in this case study is to write a generic program that generates a random access file for any type of record.

The workings of the program are illustrated for a file containing personal records, each record consisting of five data memebers (social security number, name, city, year of birth and salary, and for a student file that stores student records. The latter records have the same data members as personal records plus information about academic major. This allows us to illustrate inheritance.

In this case study, a generic random access file program inserts a new record into a file, finds a record in the file, and modifies a record. The name of the file has to be supplied by the user, and if the file is not found, it is created; otherwise, it is open for reading and writing.

The function `find()` determines whether a record is n the file. It performs the search sequentially comparing each retrieved record `tmp` to the sought record `d` using an overloaded eqality operator`==`. The function uses to some extent the fact that the file is random by scrutinizing it record by record, not byte by byte. To be sure, the records are built out of bytes and all the bytes belonging to a particular record have to be read, but only the bytes required by the eqality operator are participating in the comparison.

The function `modify()` updates information stored in a particular record. The record is first retrived from the file, also using sequential search, and the new information is read from the user using the overloaded input operator`>>`. To store the updated record `tmp` in the file, `modify()` forces the fire pointer `database` to go back to the beginning of the record `tmp` that has just been read; otherwise, the record following `tmp` in the file would be overwritten. The starting position of `tmp` can be determined immediately because each record occupies the same number of bytes; therefore, it is enough to jump back the number of bytes occupied by one record.

This is accomplished by calling `database.seekp(-d.size(), ios::cur)`, where `size()` must be defined in the class `T`, which is the class type for object `d`. The generic `Database` class includes two more functions. Function `add()` places a record at the end of the file. Function `print()` prints the content of the file. To see the class `Database` in action, we have to define a specific class which spcifies the format of one record in a random access file. As an example, we defined the class `Personal` with five data members, `SSN`, `name`, `city`, `year`, and `salary`. The first three data members are strings, but only `SSN` is always of the same size; therefore, the size is included in its declaration, `char SSN[10]`. To have slightly more flexibility with the other two strings, two constants, `nameLen` and `citylen`, are used, whose values are in the constructors. For instance,

```C++
Personal::Personal() : nameLen(10), cityLen(10) {
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
}
```
Note that we cannot initialize constants with assignemnts, as in 

```C++
Personal::Personal () {
    nameLen = cityLen = 10;
    char name[nameLen + 1];
    char city[cityLen + 1];
}
```

But this peculiar syntax used in C++ for initialization of constants in classes can be used to initialize variables.

Storing data from one object requires particular care, which is the task of function `writeToFile()`. The SSN data member is the simplest to handle. Social security number always includes nine digits; therefore, the output operator `<<` could be used. However, the lengths of names and cities and section of a record in the data file designateed for these two data members should always have the same length. To guarantee this, the function `write()`, as in `out.write(name,nameLen)`, is used for outputting the two strings to the file because the function writes a specified number of characters from the string including the null characters `\0`. which is not output with the operator `<<`.

Another problem is posed by the numerical data members, `year` and `salary`, particularly the latter data member. If salary is written to the file with the operator `<<`, then the salary 50000 is written as a five-byte-long string \`50000\`, and the salary 100000 as a six-byte-long string \`100000\`, which violates the condition that each record in the random access file should be of the same length. To avoid the problem, the numbers are stored in binary form. For example, 50000 is represented in the data member `salary` as the string of 32 bits, 00000000000000001100001101010000 (assuming that `long` variables are stored in four bytes). We can now treat this sequence of bits as representing not a long number, but a string of four characters, 00000000, 00000000, 11000011, 01010000, that is, the characters whose ASCII codes are, in decimal, numbers 0,0,195, and 80. In this way, regardless of the value of salary, the value is always sorted in four bytes. This is accomplished with the instruction `out.write(reinterpret_cast<const char*>(&salary), sizeof(long));` which forces function `write()` to treat `salary` as a four-byte-long string by converting the address `&salary` to `const char*` and specifying the length of type `long`.

A similar approach is used to read data from a data file, which is the task of `readFromFile()`. In particular, strings that should be stored in numerical data members have to be converted from string sto numbers. For the `salary` member, this is done with the instruction

```C++
in.read(reinterpret_cast<char*>(&salary), sizeof(long));
```

which casts `&salary` to `char*` with the operator `reinterpret_cast` and specifies that four bytes `(sizeof(long))` should be read into long data member `salary`.

This method of storing records in a data file poses a readability problem, particularly in the case of numbers. For example, 50000 is stored as four bytes: two null characters, a special character and a capital P. For a human reader, it is far from obvious that these characters represent 50000. Therefore, a special routine is needed to output records in readable form. This is accomplished by overloading the operator `<<`, which uses an auxillary function `writelegibly()`. The database class also overloads the operator `<<` which uses its own auxiliary function `print()`. Function repeatedly rads records from da data file into object `tmp` with `readFromFile()` and outputs `tmp` in readable form with operator `<<`. This explains why this program uses two functions for reading and two for writing: One is for maintaining data in a random access file, and the other is for reading and writing data in readable form.

To test the flexibility of the `Database` class, another user class is defined, class `Student`. This class is also used to show one more example of inheritance.

Class `Student` uses the same data members as class `Personal` by being defined as a class derived from `Personal` plus one more member, a string member `major`. Processing input and output on objects of class type `Student` is very similar to that for class `Personal`, but the additional member has to be accounted for. This is done by redefining functions from the base class and at the same time reusing them. Consider the function `writeToFile()` for writing student records in a data file ion fixed length format:

```C++
void Student::writeToFile(std::ofstream& out) const {
    Personal::writeToFile(out);
    out.write(major,majorLen);
}
```

The function uses the base class `writeToFile()` to initialize the five data members, `SSN`, `name`, `city`, `year`, and `salary`, and initlaizes the member `major`. Note that the scope resolution operator :: must be used to inticate clearly that `writeToFile()` being defined for class `Student` calls `writeToFile()` already defined in base class `Personal`. However, class `Student` inherits without any modification function `readKey()` and the overloaded operator `==` because both in `Personal` and in `Student` objects the same key is used to uniquely identify any record, namely, `SSN`.

