#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include "User.h"
using namespace std ;

class System
{
public:
    System();

    void startMinue();

    static bool strongPassword(string P);
    static bool validEmail(string P);
    static bool validName(string P);
    static bool validDate(string );
    bool validAccount();

    static void merge(User **a, int n, int m) ;
    static void merge_sort(User **a, int n) ;

    int findUser(string);
    void AddUser(User *U) ;
    User* searchUser(string);

    ~System();

private:
    User **listOfUsers ;
    int numOfUsers ;
    User *loggedInUser ;
    void signUp();
    void signIn() ;
    void readFromFile();
    void writeToFile();
};

#endif // SYSTEM_H
