//
// Created by Omar Mohamed on 20/12/2015.
//

#ifndef SOCIAL_SYSTEM_H
#define SOCIAL_SYSTEM_H

#include "User.h"


class System {
private:
    vector<User> userList;

    bool validPassword(string email, string password); // to sign in
    bool validInfo(User); // to sign up
public:
    User *loggedInUser; // point to a user in userList

    User search(string); // return new user if not found
    int find(string); // return index or -1 if not found


    bool isFriend(User other); // is friend with the logged in user

    void viewUSer(User aUser); // nas2sa

    void signUp(); // na2sa
    void signIn(); // na2sa

    void removeAccount(User); // na2sa

};


#endif //SOCIAL_SYSTEM_H
