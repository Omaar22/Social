#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include "User.h"
using namespace std ;

class System
{
public:
    System();
    User search(string); // return new user if not found
    bool strongPassword(string P);
    bool validEmail(string P);
    bool validName(string P);
    bool validAccount() ;

    void merge(User *a, int n, int m) ;
    void merge_sort(User *a, int n) ;
    bool validInfo(User U) ;
    void  AddUser(User U) ;
    void Sort() ;
    void show();
    void signUp();
    void removeAccount(User user) ;
    int findUser(int, int, string); // binary search return index or -1 if not found
    void signIn() ;

    ~System();
protected:
private:
    User *listOfUsers ;
    int numOfUsers = 0 ;
};

#endif // SYSTEM_H
