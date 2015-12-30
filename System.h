#ifndef System_H
#define System_H

#include "User.h"

class System {
private:
    User *listOfUsers;
    int numOfUsers = 0;

    int findUser(int lower, int upper, string email); // binary search return index or -1 if not found

    bool strongPassword(string P);
    bool validEmail(string P);
    bool validName(string P);
    bool validDate(string s);
    void AddUser(User U);

    void merge(User *a, int n, int m);
    void merge_sort(User *a, int n);
public:
    User *loggedInUser;

    System(); // get data from file

    void signUp();
    void signIn();
    User searchUser(string); // throw an exception if not found
    void removeAccount(User user); // na2sa
    void viewAllUsers(); // print names only

    ~System();  // call write on file function
};

#endif // System_H
