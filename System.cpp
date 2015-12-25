#include "System.h"

void System::sortUsers() {
    mergeSort(userList, 0, userListSize - 1);
}

void System::merge(User *arr, int L, int R) {
    int M = (L + R) / 2;
    int N1 = M - L + 1;
    int N2 = R - M;
    User *left = new User[N1];
    User *right = new User[N2];
    for (int i = 0; i < N1; ++i)
        left[i] = arr[L + i];
    for (int i = 0; i < N2; ++i)
        right[i] = arr[M + 1 + i];

    int i = 0, j = 0, k = L;

    while (i < N1 && j < N2) {
        if (left[i].getEmail() <= right[j].getEmail()) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < N1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < N2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void System::mergeSort(User *arr, int L, int R) {
    if (L >= R)
        return;
    int M = (L + R) / 2;
    mergeSort(arr, L, M);
    mergeSort(arr, M + 1, R);
    merge(arr, L, R);
}

int System::find(int lower, int upper, string email) {
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;
    if (userList[mid].getEmail() > email)
        return find(lower, mid - 1, email);
    else if (userList[mid].getEmail() < email)
        return find(mid + 1, upper, email);
    else return mid;
}


bool System::validPassword(string email, string password) {
    int index = find(0, userListSize - 1, email);

    return index != -1 && userList[index].getPassword() == password;
}

User System::search(string email) {
    int index = find(0, userListSize - 1, email);

    if (index != -1)
        return userList[index];

    cout << "User not found";
    return User();
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
    cout << "Enter Name, Email ";
    string name, mail;
    cin >> name >> mail;
    tmp.setEmail(mail);
    tmp.setName(name);
    while (true) {
        if (validInfo(tmp)) {

            if (userListSize == userListTotalSize) {
                userListTotalSize *= 2;
                User *newArr = new User[userListTotalSize];
                for (int i = 0; i < userListSize; i++)
                    newArr[i] = userList[i];

                delete[]userList;
                userList = newArr;
            }

            userList[userListSize++] = tmp;

            break;
        }
    }
}

bool System::validInfo(User user) {
    return true;
}

void System::signIn(string email, string password) {

    while (true) {
        if (validPassword(email, password)) {
//            loggedInUser = &userList[find(email)];
            break;
        }
    }

}

void System::removeAccount(User user) {
    int index = find(0, userListSize - 1, user.getEmail());
    
    userListSize--;

    for (int i = index; i < userListSize; i++)
        userList[i] = userList[i + 1];
}

void System::viewUSer(User aUser) {


}

System::System() {
    userListTotalSize = 10;
    userList = new User[userListTotalSize];
    userListSize = 0;
}
