#include "System.h"
<<<<<<< HEAD

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

int System::findUser(string email) {
    int lower = 0, upper = usersCount - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;

        if (users[mid]->getEmail() > email)
            upper = mid - 1;
        else if (users[mid]->getEmail() < email)
            lower = mid + 1;
        else
            return mid;
    }
    return -1;
}

int System::getUsersCount() {
    return usersCount;
}

void System::signUp(User *newUser) {

    User **newUsers = new User *[usersCount + 1];

    for (int i = 0; i < usersCount; i++)
        newUsers[i] = users[i];
    delete[] users;
    users = newUsers;

    users[usersCount++] = newUser;
    mergeSort(users, usersCount);
}
bool System::signIn(string email, string password) {
    int index = findUser(email);

    if (index == -1 || users[index]->getPassword() != password)
        return false;

    loggedInUser = users[index];
    return true;
}
bool System::isSignedIn() {
    return loggedInUser != NULL;
}
void System::signOut() {
    loggedInUser = NULL;
}

System::~System() {
    // call write on file function ..
    for (int i = 0; i < usersCount; i++)
        delete users[i];
    delete[]users;
=======
#include "User.h"
#include "Poll.h"
#include "Photo.h"

System::System() : numOfUsers(0), listOfUsers(new User *[100]) {

    try {
        readFromFile();
    }
    catch (const char *error) {
        cout << error << endl;
    }

}

System::~System() {

    try {
        writeToFile();
    }
    catch (const char *error) {
        cout << error << endl;
    }

    for (int i = 0; i < numOfUsers; i++)
        delete listOfUsers[i];
    delete[] listOfUsers;


}
void System::writeToFile() {
    ofstream data("C:\\Users\\Omar Mohamed\\Desktop\\Data.txt");
    if (data.fail()) {
        throw "Write File opening failed.";
    }

    data << numOfUsers << endl;
    for (int i = 0; i < numOfUsers; i++) {
        data << listOfUsers[i]->getName() << endl;
        data << listOfUsers[i]->getPassword() << endl;
        data << listOfUsers[i]->getEmail() << endl;

        vector<Message> receivedMessages = listOfUsers[i]->getReceivedMessages();
        data << receivedMessages.size() << endl;
        for (int j = 0; j < receivedMessages.size(); j++) {
            data << receivedMessages[j].getSender() << endl;
            data << receivedMessages[j].getReceiver() << endl;
            data << receivedMessages[j].getText() << endl;
        }

        vector<Message> sentMessages = listOfUsers[i]->getsentMessages();
        data << sentMessages.size() << endl;
        for (int j = 0; j < sentMessages.size(); j++) {
            data << sentMessages[j].getSender() << endl;
            data << sentMessages[j].getReceiver() << endl;
            data << sentMessages[j].getText() << endl;
        }

        data << listOfUsers[i]->getNumOfPosts() << endl;
        for (int j = 0; j < listOfUsers[i]->getNumOfPosts(); j++) {

            if (Status *tmp = dynamic_cast<Status *>(listOfUsers[i]->getPost(j))) {
                data << 1 << endl;
                string text = tmp->getText();
                data << text << endl;

            }
            if (Poll *tmp = dynamic_cast<Poll *>(listOfUsers[i]->getPost(j))) {
                data << 2 << endl;
                string question = tmp->getQuestion();
                data << question << endl;
                int answersCount = tmp->getNumberOfAnswers();
                data << answersCount << endl;
                for (int k = 0; k < answersCount; k++) {
                    string answer = tmp->getAnswer(k);
                    data << answer << endl;
                }
            }
            if (Photo *tmp = dynamic_cast<Photo *>(listOfUsers[i]->getPost(j))) {
                data << 3 << endl;
                string photo = tmp->getPhoto();
                data << photo << endl;
            }
            data << listOfUsers[i]->getPost(j)->getLikeCounter() << endl;
            data << listOfUsers[i]->getPost(j)->getDislikeCounter() << endl;
            data << listOfUsers[i]->getPost(j)->getNumberOfComments() << endl;
            for (int k = 0; k < listOfUsers[i]->getPost(j)->getNumberOfComments(); k++) {
                data << listOfUsers[i]->getPost(j)->getComment(k) << endl;
            }

        }
    }
    for (int i = 0; i < numOfUsers; i++) {
        data << listOfUsers[i]->getNumOfFriends() << endl;
        for (int j = 0; j < listOfUsers[i]->getNumOfFriends(); j++) {
            data << listOfUsers[i]->getFriends(j)->getEmail() << endl;
        }
    }
    data.close();
}
void System::readFromFile() {
    ifstream data("C:\\Users\\Omar Mohamed\\Desktop\\Data.txt");
    if (data.fail()) {
        throw "Read File opening failed.";
    }


    string userCount;
    getline(data, userCount);
    numOfUsers = stoi(userCount);

    for (int i = 0; i < numOfUsers; i++) {
        listOfUsers[i] = new User;
        string name;
        getline(data, name);
        listOfUsers[i]->setName(name);
        string password;
        getline(data, password);
        listOfUsers[i]->setPassword(password);
        string email;
        getline(data, email);
        listOfUsers[i]->setEmail(email);

        string receivedCount;
        getline(data, receivedCount);
        int receivedMessagesCount = stoi(receivedCount);

        for (int j = 0; j < receivedMessagesCount; j++) {
            string sender;
            getline(data, sender);

            string receiver;
            getline(data, receiver);

            string text;
            getline(data, text);

            Message X(text, receiver, sender);
            listOfUsers[i]->recieveMessage(X);
        }


        string sentCount;
        getline(data, sentCount);

        int sentMessagesCount = stoi(sentCount);

        for (int j = 0; j < sentMessagesCount; j++) {
            string sender;
            getline(data, sender);

            string receiver;
            getline(data, receiver);

            string text;
            getline(data, text);

            Message X(text, receiver, sender);
            listOfUsers[i]->sendMessage(X);
        }

        string postCounter;
        getline(data, postCounter);
        int postsCount = stoi(postCounter);
        for (int j = 0; j < postsCount; j++) {
            string type; //////////
            getline(data, type);

            if (type == "1") {
                string text;
                getline(data, text);

                string input;
                getline(data, input);

                int likesCount;
                if (input.size() > 3) {
                    text += "\n" + input;
                    Status *tmp = new Status(text, 0);
                    listOfUsers[i]->putInPosts(tmp);

                    string number;
                    getline(data, number);
                    likesCount = stoi(number);
                }
                else {
                    Status *tmp = new Status(text, 0);
                    listOfUsers[i]->putInPosts(tmp);

                    likesCount = stoi(input);
                }


                listOfUsers[i]->getPost(j)->setLikeCount(likesCount);

                string dislikesCounter;
                getline(data, dislikesCounter);
                int dislikesCount = stoi(dislikesCounter);
                listOfUsers[i]->getPost(j)->setDislikeCount(dislikesCount);

                string commentsCounter;
                getline(data, commentsCounter);
                int commentsCount = stoi(commentsCounter);


                for (int k = 0; k < commentsCount; k++) {
                    string comment;
                    getline(data, comment);
                    string date;
                    getline(data, date);
                    listOfUsers[i]->getPost(j)->addcomment(comment, date);
                }
            }
            else if (type == "2") {
                Poll *tmp = new Poll;
                string question;
                getline(data, question);
                tmp->addQuestion(question);
                string answersCounter;
                getline(data, answersCounter);
                int answersCount = stoi(answersCounter);
                for (int k = 0; k < answersCount; k++) {
                    string answer;
                    getline(data, answer);
                    tmp->addAnswers(answer);
                }
                listOfUsers[i]->putInPosts(tmp);

                string inputNumber;
                getline(data, inputNumber);
                int likesCount = stoi(inputNumber);
                listOfUsers[i]->getPost(j)->setLikeCount(likesCount);

                getline(data, inputNumber);
                int dislikesCount = stoi(inputNumber);
                listOfUsers[i]->getPost(j)->setDislikeCount(dislikesCount);

                string commentCounter;
                getline(data, commentCounter);
                int commentsCount = stoi(commentCounter);
                for (int k = 0; k < commentsCount; k++) {
                    string comment;
                    getline(data, comment);
                    string date;
                    getline(data, date);
                    listOfUsers[i]->getPost(j)->addcomment(comment, date);
                }
            }
            else if (type == "3") {
                Photo *tmp = new Photo;
                string photo;
                getline(data, photo);
                tmp->addPhoto(photo);
                listOfUsers[i]->putInPosts(tmp);

                string inputNumber;
                getline(data, inputNumber);
                int likesCount = stoi(inputNumber);
                listOfUsers[i]->getPost(j)->setLikeCount(likesCount);

                getline(data, inputNumber);
                int dislikesCount = stoi(inputNumber);
                listOfUsers[i]->getPost(j)->setDislikeCount(dislikesCount);

                getline(data, inputNumber);
                int commentsCount = stoi(inputNumber);
                for (int k = 0; k < commentsCount; k++) {
                    string comment;
                    getline(data, comment);
                    string date;
                    getline(data, date);
                    listOfUsers[i]->getPost(j)->addcomment(comment, date);
                }
            }
            else
                throw "Error reading Data.";

        }
    }

    for (int i = 0; i < numOfUsers; i++) {
        string friendCounter;
        getline(data, friendCounter);
        int friendsCount = stoi(friendCounter);
        for (int j = 0; j < friendsCount; j++) {
            string email;
            getline(data, email);

            listOfUsers[i]->addFriend(searchUser(email));
        }
    }
    data.close();

}

void System::signIn() {
    string e, p;

    cout << "\t\t Sign In:\n\nEmail: ";
    cin >> e;
    int idx = findUser(e);
    while (idx == -1) {
        cout << "Email does not exist please Enter it again :\nEmail: ";
        cin >> e;
        idx = findUser(e);
    }
    cout << "\nPassword :";
    cin >> p;
    while (listOfUsers[idx]->getPassword() != p) {
        cout << "Invalid password .. please Enter again: ";
        cin >> p;
    }
    loggedInUser = listOfUsers[idx];
}
void System::signUp() {

    if (!validAccount()) {
        cout << "Sorry ,You cannot sign up\n";
        return;
    }

    cout << "\t\t\t Welcome ..\nSign Up :\n\n";
    User *u = new User;

    string s;
    while (8) {
        cout << "Fill these Information\n" << endl;
        try {

            int choice;
            cout << "\nName : ";

            s = "";
            while (s == "")
                getline(cin, s);
            u->setName(s);

            cout << "\nEmail : ";
            cin >> s;
            u->setEmail(s);

            cout << "\nPassword : ";
            cin >> s;
            u->setPassword(s);

            cout << "\nGender (1 for Male , 2 for Female ) : ";
            cin >> choice;
            u->setGender(choice);
            cout << "\nEnter your date of birth: " << endl;

            string month, day, year;
            cout << "\nDay: ";
            cin >> day;
            cout << "Month: ";
            cin >> month;
            cout << "Year: ";
            cin >> year;

            if (day.size() == 1) day = '0' + day;
            if (month.size() == 1) month = '0' + month;
            string s = day + '/' + month + '/' + year;
            u->setBirthDate(s);

            cout << endl;
            break;

        }
        catch (const char *c) {
            cout << c << endl;
            continue;
        }
    }

    AddUser(u);
    loggedInUser = u;
    //merge_sort(listOfUsers , numOfUsers) ;

}
void System::startMinue() {
    here:
    if (system("CLS")) system("clear");
    cout << "\t\t\t\t\t\t WELCOME ... \n";
    cout << "\t\t\t\t\t\t\t El Social Network\n\n";
    cout << "\n\n\t\t1. Sign Up\n\t\t2. Sign In\n\t\t3. Exit\n\n";
    string x;
    cout << "Your choice: ";
    cin >> x;

    while (x != "1" && x != "2" && x != "3") {
        cout << "Wrong choice , Enter Again :";
        cin >> x;
    }

    if (system("CLS")) system("clear");
    if (x == "1") signUp();
    if (x == "2") signIn();
    else if (x == "3") return;

    while (8) {
        profile :
        if (system("CLS")) system("clear");
        int choice;
        string s, Back;
        cout << "El Social Network :\n";
        cout <<
        "\n\n\n1. View Profile\n2. Search Friend\n3. Add Post\n4. View Posts\n5. View Friends\n6. Message\n7. Sign Out\n";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        while (choice < 1 && choice > 5) {
            cout << "Wrong choice, Enter Again: ";
            cin >> choice;
        }
        if (choice == 1) {
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n";
            cout << "\t\t Welcome, " << loggedInUser->getName() << "\n\n";
            loggedInUser->viewInfo(loggedInUser->getEmail());
            merge_sort(listOfUsers, numOfUsers);
        }
        else if (choice == 2) {
            again :
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n\n";
            cout << "Searching for friend\n\n";
            cout << "Enter Email: ";
            cin >> s;
            User *u;
            u = searchUser(s);
            if (u->getName() == "NoUser") {
                cout << "No such user exist!\n";
            }
            else if (u->getEmail() == loggedInUser->getEmail()) {
                goto profile;
            }
            else
                u->viewUser(loggedInUser, u);
            cout << "\n1. Search again\n2. Back\n\nEnter choice: ";
            cin >> Back;
            if (Back == "1") goto again;

        }
        else if (choice == 3) {
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n\n";
            cout << "Adding post\n\n";
            loggedInUser->addPost();
        }
        else if (choice == 4) {
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n\n";
            cout << "Posts \n\n";
            loggedInUser->viewPosts(loggedInUser);
        }
        else if (choice == 5) {
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n\n";
            loggedInUser->viewFriends(loggedInUser);
        }
        else if (choice == 6) {
            msg :
            if (system("CLS")) system("clear");
            cout << "El Social Network :\n\n\n";
            cout << "Message\n\n";
            int x;
            cout << "1. Send Message\n2. View Sent Messages\n3. View Received Messages\n4. Back\n";
            cin >> x;
            cout << "\n";

            while (x < 0 || x > 4) {
                cout << "Wrong Choice, Enter Again: ";
                cin >> x;
            }
            if (x == 1) {
                msgg :
                string mail;
                cout << "\n\nEmail :";
                cin >> mail;

                User *U;
                U = searchUser(mail);
                if (U->getName() == "NoUser") {
                    cout << "No Such User Exist! ";
                    cout << "\n1. Try again\n2. Back\n\nEnter choice: ";
                    cin >> Back;
                    if (Back == "1") goto msgg;
                }
                else loggedInUser->sendMessageFun(U);

                goto msg;
            }
            else if (x == 2) {
                cout << "\n\nSent Messages: \n\n";
                loggedInUser->viewSentMessages();
                cout << "\n\nPress any key to go back\n";
                cin >> Back;
                goto msg;
            }
            else if (x == 3) {
                cout << "\n\nReceived Messages: \n\n";
                loggedInUser->viewReceivedMessages();
                cout << "\n\nPress any key to go back\n";
                cin >> Back;
                goto msg;
            }
            else goto profile;

        }
        else if (choice == 7) {
            goto here;
        }
    }
}

//////////////////

bool System::validName(string s) {
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == ' ')
            continue;
        else
            return 0;
    }
    return s.size();
}
bool System::validEmail(string P) {
    int f1 = P.rfind('@');
    int f2 = P.rfind(".com");
    int f3 = P.find(' ');
    return f1 != -1 && f2 != -1 && (f2 - f1) > 1 && f3 == -1;
//    int idx = findUser(P);
//    if (idx == -1 && b)
//    return 1;
//    else if (idx != -1)
//        return 2 ;
//    return 3;

}
bool System::validAccount() {
    return numOfUsers < 100;
}
bool System::strongPassword(string P) {
    int sz = int(P.size());
    bool U, L, D;
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
bool System::validDate(string s) {
    int sz = s.size();
    int day = (int(s[0] - '0') * 10 + int(s[1] - '0'));
    int month = (int(s[3] - '0') * 10 + int(s[4] - '0'));
    int year = (int(s[6] - '0') * 1000 + int(s[7] - '0') * 100 + int(s[8] - '0') * 10 + int(s[9] - '0'));
    return isdigit(s[0]) && isdigit(s[1]) && isdigit(s[3]) && isdigit(s[4])
           && isdigit(s[6]) && isdigit(s[7]) && isdigit(s[8]) && isdigit(s[9]) && s[2] == '/' && s[5] == '/'
           && day <= 31 && day >= 1 && month <= 12 && month >= 1 && year >= 1900 && year <= 2014;
}

///////////////////////

void System::AddUser(User *U) {
    listOfUsers[numOfUsers++] = U;
}
int System::findUser(string email) {
    for (int i = 0; i < numOfUsers; i++) {
        if (listOfUsers[i]->getEmail() == email)
            return i;
    }
    return -1;
}
User *System::searchUser(string e) {
    for (int i = 0; i < numOfUsers; i++) {
        if (listOfUsers[i]->getEmail() == e)
            return listOfUsers[i];
    }
    User *U = new User;
    U->setName("NoUser");
    return U;
}

///////////////////

void System::merge_sort(User **a, int n) {
    if (n < 2) return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
void System::merge(User **a, int n, int m) {
    int i = 0, j = m;
    User **b = new User *[n];

    for (int k = 0; k < n; ++k) {
        if (i == m) b[k] = a[j++];
        else if (j == n) b[k] = a[i++];
        else if (a[i]->getName() <= a[j]->getName()) b[k] = a[i++];
        else {
            b[k] = a[j++];
        }
    }
    for (int k = 0; k < n; ++k)
        a[k] = b[k];

    delete[] b;
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
}
