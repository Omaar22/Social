<<<<<<< HEAD
#ifndef System_H
#define System_H

#include "User.h"

class System {
private:
    User **users;
    int usersCount;
    User *loggedInUser;

    void mergeSort(User **arr, int N); // sort users by email
public:
    System(); // get data from file

    int findUser(string email); // binary search return index or -1 if not found

    User *getLoggedInUser();
    User *getUser(int index);

    void signUp(User *newUser);
    bool signIn(string email, string password);
    bool isSignedIn();
    void signOut();

    int getUsersCount();

    ~System();  // call write on file function
};

#endif //System_H
=======
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
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
