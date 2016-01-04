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

    int findUser(int lower, int upper, string email); // binary search return index or -1 if not found

    User *getLoggedInUser();
    User *getUser(int index);

    void addUser(User *newUser);
    bool logIn(string email, string password);

    bool static strongPassword(string P);
    bool static validEmail(string P);
    bool static validName(string P);

    int getUsersCount();
    ~System();  // call write on file function
};

#endif //System_H
