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

    void merge(User *a, int n, int m) ;
    void merge_sort(User *a, int n) ;

    int findUser(string);
    void AddUser(User U) ;
    User searchUser(string);
    void removeAccount(User user) ; /// not complete

    ~System();

private:
    User *listOfUsers ;
    int numOfUsers = 0 ;
    User loggedInUser ;
    void signUp();
    void signIn() ;

};

#endif // SYSTEM_H
