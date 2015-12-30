#include "System.h"

System::System() : numOfUsers(0), listOfUsers(NULL), loggedInUser(NULL) {

    // get data from file
}

bool System::validName(string name) {

    for (char X : name)
        if (!('a' <= X && X <= 'z' || 'A' <= X && X <= 'Z' || X == ' '))
            return 0;

    return name.size() != 0;
}

////////////////////////

bool System::strongPassword(string P) {
    int sz = (int) P.size();
    bool U = 0, L = 0, D = 0;
    for (int i = 0; i < sz; i++) {
        if (islower(P[i]))
            L = true;
        else if (isupper(P[i]))
            U = true;
        else if (isdigit(P[i]))
            D = true;
    }
    return sz >= 8 && L && U && D;
}

////////////////////////

bool System::validEmail(string P) {
    int f1 = P.rfind('@');
    int f2 = P.rfind(".com");
    int f3 = P.find(' ');
    return f1 != -1 && f2 != -1 && (f2 - f1) > 1 && f3 == -1;
}

///////////////////

void System::AddUser(User U) {
    listOfUsers[numOfUsers++] = U;
    merge_sort(listOfUsers, numOfUsers);
}

///////////////////

void System::merge_sort(User *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}

/////////////////

void System::merge(User *a, int n, int m) {
    int i = 0, j = m;
    User *b = new User[n];
    for (int k = 0; k < n; ++k) {
        if (i == m)
            b[k] = a[j++];
        else if (j == n)
            b[k] = a[i++];
        else if (a[i].getName() <= a[j].getName())
            b[k] = a[i++];
        else {
            b[k] = a[j++];
        }
    }
    for (int k = 0; k < n; ++k)
        a[k] = b[k];
    delete[] b;
}

/////////////////

int System::findUser(int lower, int upper, string email) {
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;

    if (listOfUsers[mid].getEmail() > email)
        return findUser(lower, mid - 1, email);
    if (listOfUsers[mid].getEmail() < email)
        return findUser(mid + 1, upper, email);
    return mid;
}

/////////////////////

void System::viewAllUsers() ///testing
{
    for (int i = 0; i < numOfUsers; i++)
        cout << listOfUsers[i].getName() << endl;
}

/////////////////

void System::removeAccount(User user) {
    int index = findUser(0, numOfUsers - 1, user.getEmail());

    if (index == -1)
        throw "User Not Found";

    numOfUsers--;

    for (int i = index; i < numOfUsers; i++)
        listOfUsers[i] = listOfUsers[i + 1];

}

///////////////

void System::signUp() {
    cout << "\t\t\t Welcome ..\nSign Up :\n\n";
    User newUser;
    while (1) {
        cout << "Fill these Information\n" << endl;
        try {
            string input = "";

            cout << "Name : ";
            while (input == "")
                getline(cin, input);
            if (!validName(input))
                throw "Invalid name.";
            newUser.setName(input);

            cout << "Password : ";
            cin >> input;
            if (!strongPassword(input))
                throw "Weak Password.";
            newUser.setPassword(input);

            cout << "Gender (1 for Male , 2 for Female ) : ";
            int choice;
            cin >> choice;
            if (choice != 1 && choice != 2)
                throw "Wrong Choice.";
            newUser.setGender(choice);

            cout << "Email : ";
            cin >> input;
            if (!validEmail(input))
                throw "Invalid E-mail.";
            newUser.setEmail(input);

            string month, day, year;
            cout << "Enter day month year\n";
            cin >> day >> month >> year;
            if (day.size() == 1)
                day = '0' + day;
            if (month.size() == 1)
                month = '0' + month;
            string date = day + '/' + month + '/' + year;
            if (!validDate(input))
                throw "Invalid Date.";
            newUser.setBirthDate(date);

            cout << endl;
            break;
        }
        catch (const char *error) {
            cout << error << endl;
        }
    }

    AddUser(newUser);
}

void System::signIn() {
    string email, password;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    int index = findUser(0, numOfUsers - 1, email);

    while (index == -1 || listOfUsers[index].getPassword() != password) {
        cout << "Invalid email or password .. please try again\n";
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;
        index = findUser(0, numOfUsers - 1, email);
    }

    loggedInUser = &listOfUsers[index];
}

/////////////////////


User System::searchUser(string email) {
    int index = findUser(0, numOfUsers - 1, email);
    if (index == -1)
        throw "User Not Found";
    return listOfUsers[index];
}

///////////////////////

bool System::validDate(string s) {
    if (s.size() != 10)
        return false;

    int day = (int(s[0] - '0') * 10 + int(s[1] - '0'));
    int month = (int(s[3] - '0') * 10 + int(s[4] - '0'));
    int year = (int(s[6] - '0') * 1000 + int(s[7] - '0') * 100 + int(s[8] - '0') * 10 + int(s[9] - '0'));
    return isdigit(s[0]) && isdigit(s[1]) && isdigit(s[3]) && isdigit(s[4])
           && isdigit(s[6]) && isdigit(s[7]) && isdigit(s[8]) && isdigit(s[9]) && s[2] == '/' && s[5] == '/'
           && day <= 31 && day >= 1 && month <= 12 && month >= 1 && year >= 1900 && year <= 2014;
}

///////////////

System::~System() {
    // call write on file function ..
    delete[]listOfUsers;
    delete loggedInUser;
}
