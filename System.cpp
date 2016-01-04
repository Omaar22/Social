#include "System.h"

System::System() : usersCount(0), users(NULL), loggedInUser(NULL) {

    // get data from file
}

User *System::getLoggedInUser() {
    return loggedInUser;
}

User *System::getUser(int index) {
    if (!(0 <= index && index < usersCount))
        throw "Out of boundary.";

    return users[index];
}

bool System::validName(string name) {
    for (char X : name)
        if (!('a' <= X && X <= 'z' || 'A' <= X && X <= 'Z' || X == ' '))
            return false;

    return name.size() != 0;
}
bool System::strongPassword(string P) {
    bool U = 0, L = 0, D = 0;
    for (int i = 0; i < P.size(); i++) {
        if (islower(P[i]))
            L = true;
        else if (isupper(P[i]))
            U = true;
        else if (isdigit(P[i]))
            D = true;
    }
    return P.size() >= 8 && L && U && D;
}
bool System::validEmail(string P) {
    int f1 = P.rfind('@');
    int f2 = P.rfind(".com");
    int f3 = P.find(' ');
    return f1 != -1 && f2 != -1 && (f2 - f1) > 1 && f3 == -1;
}

void System::mergeSort(User **arr, int N) {
    if (N < 2)
        return;
    int M = N / 2;
    mergeSort(arr, M);
    mergeSort(arr + M, N - M);

    User **tmp = new User *[N];
    int i = 0, j = M;
    for (int k = 0; k < N; ++k) {
        if (i == M)
            tmp[k] = arr[j++];
        else if (j == N)
            tmp[k] = arr[i++];
        else if (arr[i]->getEmail() <= arr[j]->getEmail())
            tmp[k] = arr[i++];
        else
            tmp[k] = arr[j++];
    }

    for (int k = 0; k < N; ++k)
        arr[k] = tmp[k];
    delete[] tmp;
}

int System::findUser(int lower, int upper, string email) {
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;

    if (users[mid]->getEmail() > email)
        return findUser(lower, mid - 1, email);
    if (users[mid]->getEmail() < email)
        return findUser(mid + 1, upper, email);
    return mid;
}

void System::addUser(User *newUser) {

    User **newUsers = new User *[usersCount + 1];

    for (int i = 0; i < usersCount; i++)
        newUsers[i] = users[i];
    delete[] users;
    users = newUsers;

    users[usersCount++] = newUser;
    mergeSort(users, usersCount);
}

bool System::logIn(string email, string password) {
    int index = findUser(0, usersCount - 1, email);

    if (index == -1 || users[index]->getPassword() != password)
        return false;

    loggedInUser = users[index];
    return true;
}

int System::getUsersCount() {
    return usersCount;
}

System::~System() {
    // call write on file function ..
    for (int i = 0; i < usersCount; i++)
        delete users[i];
    delete[]users;
}