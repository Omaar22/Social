//
// Created by Omar Mohamed on 20/12/2015.
//

#include "System.h"

bool System::validPassword(string email, string password) {
    for (int i = 0; i < userList.size(); i++)
        if (userList[i].getEmail() == email && userList[i].getPassword() == password)
            return true;

    return false;
}

User System::search(string email) {
    for (int i = 0; i < userList.size(); i++)
        if (userList[i].getEmail() == email)
            return userList[i];

    cout << "User not found";
    return User();
}

int System::find(string email) {
    for (int i = 0; i < userList.size(); i++)
        if (userList[i].getEmail() == email)
            return i;

    cout << "User not found";
    return -1;
}

bool System::isFriend(User other) {
    for (int i = 0; i < other.friends.size(); i++) {
        if (other.friends[i] == other)
            return true;
    }

    return false;
}

void System::signUp() {
    User tmp;
    while (true) {
        if (validInfo(tmp)) {
            userList.push_back(tmp);
            break;
        }
    }
}

bool System::validInfo(User user) {
    return false;
}

void System::signIn() {

    while (true) {
        if (validPassword("", "")) {
            break;
        }
    }

}

void System::removeAccount(User user) {
    int index = find(user.getEmail());
    userList.erase(userList.begin() + index);
}

void System::viewUSer(User aUser) {


}
