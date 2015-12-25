#ifndef SOCIAL_SYSTEM_H
#define SOCIAL_SYSTEM_H

#include "User.h"

class System {
private:
    User *userList;
    int userListSize;
    int userListTotalSize;

    bool validPassword(string email, string password); // to sign in
    bool validInfo(User); // to sign up

    void merge(User arr[], int L, int R);
    void mergeSort(User arr[], int L, int R);

    int find(int, int, string); // binary search return index or -1 if not found

public:
    System();
    User *loggedInUser; // point to a user in userList
    void sortUsers(); // merge sort

    User search(string); // return new user if not found


    bool isFriend(User other); // is friend with the logged in user // shoud be in user?

    void viewUSer(User aUser); // nas2sa

    void signUp(); // na2sa

    void signIn(string email, string password);


    void removeAccount(User);

    void readFromFile();
    void writeOnFile();

};


#endif //SOCIAL_SYSTEM_H
