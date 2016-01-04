#include "User.h"
#include "System.h" // included in .cpp to avoid recursion

User::User() {
    posts = NULL;
    friends = NULL;
    friendsCount = 0;
    postsCount = 0;
}

void User::editInfo() {
    cout << " 1.Name\n2.Password\n3.Gender\n4.Email\n5.Date Of Birth\n6.Interests" << endl;
    int choice;
    cin >> choice;

    string input;
    if (choice == 1) {
        cout << "Enter The New Name : ";
        cin.ignore();
        getline(cin, input);
        while (System::validName(input)) {
            cout << "Invalid name, TRY AGAIN : ";
            getline(cin, input);
        }
        setName(input);
    }
    else if (choice == 2) {
        cout << "Enter The New Password : ";
        cin >> input;
        while (System::strongPassword(input)) {
            cout << "Password is not strong enough, password size should be at least 8 characters" << endl;
            cout << "it must contains at least one uppercase, one lowercase, and one number" << endl;
            cout << "TRY AGAIN : ";
            cin >> input;
        }
        setPassword(input);
    }
    else if (choice == 3) {
        cout << "Enter Gender (1 for male , 2 for female) : " << endl;
        cin >> choice;
        while (choice != 1 && choice != 2) {
            cout << "Wrong choice, TRY AGAIN : ";
            cin >> choice;
        }
        setGender(choice);
    }
    else if (choice == 4) {
        cout << "Enter The New Email : ";
        cin.ignore();
        getline(cin, input);

        while (System::validEmail(input)) {
            cout << "Invalid, TRY AGAIN : ";
            getline(cin, input);
        }
        setEmail(input);
    }
    else if (choice == 5) {
        string date = "", day, month, year;
        cout << "Enter The New Date : ";
        cout << "Day : ";
        cin >> day;
        cout << "Month : ";
        cin >> month;
        cout << "Year : ";
        cin >> year;

        DateTime tmpDate;
        tmpDate.setDate(day, month, year);

        setBirthDate(tmpDate);
    }
    else if (choice == 6) {
        cout << "Enter 3 new interests : ";

        string interest[3];
        for (int i = 0; i < 3; i++)
            cin >> interest[i];

        setInterests(interest);

    }
    else
        cout << "Invalid choice.";

}

int User::findFriend(int lower, int upper, string email) {
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;

    if (friends[mid]->getEmail() > email)
        return findFriend(lower, mid - 1, email);
    if (friends[mid]->getEmail() < email)
        return findFriend(mid + 1, upper, email);
    return mid;
}

void User::addFriend(User *aUser) {
    if (findFriend(0, friendsCount - 1, aUser->getEmail()) != -1)
        throw "User is already a friend.";
    if (aUser->getEmail() == email)
        throw "You can't add yourself.";

    User **tmpFriends = new User *[friendsCount + 1];

    bool added = false;
    for (int i = 0; i <= friendsCount; i++) {
        if (!added && (i == friendsCount || friends[i]->getEmail() > aUser->getEmail())) {
            tmpFriends[i] = aUser;
            added = true;
        }
        if (!added)
            tmpFriends[i] = friends[i];
        else if (i != friendsCount)
            tmpFriends[i + 1] = friends[i];
    }

    delete[] friends;
    friends = tmpFriends;

    friendsCount++;
}

void User::removeFriend(string email) {

    int index = findFriend(0, friendsCount - 1, email);

    if (index == -1)
        throw "Friend not found.";

    User **tmpFriends = new User *[friendsCount - 1];

    for (int i = 0; i < friendsCount; i++) {
        if (i == index)
            continue;
        if (i > index)
            tmpFriends[i - 1] = friends[i];
        else
            tmpFriends[i] = friends[i];

    }
    delete[] friends;
    friends = tmpFriends;
    friendsCount--;
}

void User::addPost() {
    int choice;
    string s;
    cout << "1. Status\n2. Poll\n3. Photo/Video" << endl;
    cout << "\nEnter choice : ";
    cin >> choice;

    while (choice < 0 || choice > 3) {
        cout << "Wrong Choise, TRY AGAIN : ";
        cin >> choice;
    }

    if (choice == 1) {
        Status *st = new Status;
        cout << "Enter Status : ";

        s = "";
        while (s == "")
            getline(cin, s);

        st->addStatus(s);
        putInPosts(st);
    }
    else if (choice == 2) {
        Poll *pol = new Poll;
        int num;
        cout << "Enter Question : ";
        s = "";
        while (s == "")
            getline(cin, s);

        cout << "Enter Number Of answers : ";
        cin >> num;

        string ans;
        cout << "Enter The Answers : ";

        pol->addQuestion(s);

        for (int i = 0; i < num; i++) {
            ans = "";
            while (ans == "")
                getline(cin, ans);
            pol->addAnswers(ans);
        }

        putInPosts(pol);
    }
    else {
        Photo *pv = new Photo;
        cout << "Enter Link : ";
        s = "";
        while (s == "")
            getline(cin, s);
        pv->addPhoto(s);

        putInPosts(pv);
    }
}

void User::putInPosts(Post *P) {
    posts[postsCount++] = P;

}

void User::sendMessage(User *aUser, Message newMessage) {
    sentMessages.push_back(newMessage);
    aUser->receivedMessages.push_back(newMessage);
}

void User::setBirthDate(DateTime date) {
    birthDate = date;
}
void User::setPassword(string password) {
    if (!System::strongPassword(password)) {
        throw "Password is too weak";
    }
    this->password = password;
}
void User::setGender(int g) {
    if (g != 1 && g != 2) {
        throw "Wrong choice";
    }
    else if (g == 1)
        gender = "Male";
    else
        gender = "Female";
}
void User::setEmail(string e) {
    int x = System::validEmail(e);
    if (x == 2)
        throw "Email already Exists";
    else if (x == 3)
        throw "Invalid Email";
    email = e;
}
void User::setName(string n) {
    if (!System::validName(n)) {
        throw "Invalid name";
    }
    name = n;
}
DateTime User::getBirthDate() {
    return birthDate;
}
string User::getPassword() {
    return password;
}
string User::getGender() {
    return gender;
}
string User::getEmail() {
    return email;
}
string User::getName() {
    return name;
}
int User::getFriendsCount() {
    return friendsCount;
}
void User::setInterests(string *interest) {
    for (int i = 0; i < 3; i++)
        interests[i] = interest[i];

}
User *User::getFriend(int index) {
    return friends[index];
}

User::~User() {
    for (int i = 0; i < friendsCount; i++)
        friends[i]->removeFriend(email);
    delete[]friends;

    for (int i = 0; i < postsCount; i++)
        delete posts[i];
    delete[]posts;
}

int User::getReceivedMessagesCount() {
    return receivedMessages.size();
}
Message User::getRecievedMessage(int index) {
    if (!(0 <= index and index < receivedMessages.size()))
        throw "index out of boundary";

    return receivedMessages[index];
}

int User::getSentMessagesCount() {
    return sentMessages.size();
}
Message User::getSentMessage(int index) {
    if (!(0 <= index and index < sentMessages.size()))
        throw "index out of boundary";

    return sentMessages[index];
}
