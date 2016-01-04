#include "System.h"

System currentSystem;
bool loggedIn;

bool signUp() {
    User *newUser = new User;

    cout << "Enter \"-1\" to exit at anytime.\n";

    string name;
    cout << "Name : ";
    while (name.size() == 0)
        getline(cin, name);
    if (name == "-1") {
        delete newUser;
        return false;
    }
    while (!System::validName(name)) {
        cout << "Invalid name.\nName: ";
        getline(cin, name);
        if (name == "-1") {
            delete newUser;
            return false;
        }
    }
    newUser->setName(name);

    cout << "Password: ";
    string password;
    cin >> password;
    if (password == "-1") {
        delete newUser;
        return false;
    }
    while (!System::strongPassword(password)) {
        cout << "Weak password.\nPassword: ";
        cin >> password;
        if (password == "-1") {
            delete newUser;
            return false;
        }
    }
    newUser->setPassword(password);

    cout << "Gender (1 for Male , 2 for Female ): ";
    int choice;

    cin >> choice;
    if (choice == -1) {
        delete newUser;
        return false;
    }
    while (choice != 1 && choice != 2) {
        cout << "Wrong Choice.\nGender (1 for Male , 2 for Female ): ";
        cin >> choice;
        if (choice == -1) {
            delete newUser;
            return false;
        }
    }
    newUser->setGender(choice);

    string email;
    cout << "Email : ";
    cin >> email;
    if (email == "-1") {
        delete newUser;
        return false;
    }
    while (!System::validEmail(email) || currentSystem.findUser(0, currentSystem.getUsersCount() - 1, email) != -1) {
        cout << "Invalid email.\nEmail: ";
        cin >> email;
        if (email == "-1") {
            delete newUser;
            return false;
        }
    }
    newUser->setEmail(email);

    cout << "Birth date in in DD/MM/YYYY format: ";
    DateTime birthDate;
    while (true) {
        string date;
        cin >> date;
        if (date == "-1") {
            delete newUser;
            return false;
        }
        try {
            birthDate.setDate(date);
            break;
        }
        catch (const char *error) {
            cout << error << endl;
        }
    }
    newUser->setBirthDate(birthDate);

    currentSystem.addUser(newUser);

    return currentSystem.logIn(email, password);
}

bool signIn() {
    string email, password;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    return currentSystem.logIn(email, password);
}

bool startPage() {
    while (!loggedIn) {
        cout << "1.Sign up\n2.Sign in\n3.Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (signUp()) {
                cout << "Welcome " << currentSystem.getLoggedInUser()->getName() << "!\n\n";
                loggedIn = true;
                return true;
            }
        }
        else if (choice == 2) {
            if (signIn()) {
                cout << "Welcome " << currentSystem.getLoggedInUser()->getName() << "!\n\n";
                loggedIn = true;
                return true;
            }
            else
                cout << "Invalid email or password.\n";
        }
        else if (choice == 3)
            return false;
        else
            cout << "Invalid choice.\n";
    }
    return true;
}

void viewYourProfile() {
    cout << currentSystem.getLoggedInUser()->getName() << endl
    << currentSystem.getLoggedInUser()->getEmail() << endl
    << currentSystem.getLoggedInUser()->getBirthDate() << endl
    << "Your friends:\n";
    for (int i = 0; i < currentSystem.getLoggedInUser()->getFriendsCount(); i++) {
        cout << currentSystem.getLoggedInUser()->getFriend(i)->getName() << endl;
    }
    cout << endl;
}

void sendMessage(User *aUser) {
    cout << "Text: ";
    string text;
    while (text.size() == 0)
        getline(cin, text);
    string sender = currentSystem.getLoggedInUser()->getName();
    string receiver = aUser->getName();
    Message newMessage(text, receiver, sender);

    currentSystem.getLoggedInUser()->sendMessage(aUser, newMessage);
}

void viewUserProfile(User *aUser) {
    bool isFriend =
            currentSystem.getLoggedInUser()->findFriend(0, currentSystem.getLoggedInUser()->getFriendsCount() - 1,
                                                        aUser->getEmail()) != -1;

    if (isFriend) {
        cout << "1.View " << aUser->getName() << "'s information\n2.Send Message\n3.Remove " << aUser->getName() <<
        " from friends\n4.back\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << aUser->getName() << endl
            << aUser->getEmail() << endl
            << aUser->getBirthDate() << endl;
        }
        else if (choice == 2) {
            sendMessage(aUser);
        }
        else if (choice == 3) {
            try {
                currentSystem.getLoggedInUser()->removeFriend(aUser->getEmail());
                cout << aUser->getName() << " removed successfully.\n";
            }
            catch (string error) {
                cout << error << endl;
                viewUserProfile(aUser);
            }
        }
        else if (choice == 4) {
            return;
        }
        else {
            cout << "Invalid choice.\n";
            viewUserProfile(aUser);
        }
    }
    else {
        cout << "1.Add " << aUser->getName() << "\n2.Send Message\n3.Back\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            try {
                currentSystem.getLoggedInUser()->addFriend(aUser);
                cout << aUser->getName() << " added successfully.\n";
            }
            catch (const char *error) {
                cout << error << endl;
                viewUserProfile(aUser);
            }
        }
        else if (choice == 2)
            sendMessage(aUser);

        else if (choice == 3)
            return;

        else {
            cout << "Invalid choice.\n";
            viewUserProfile(aUser);
        }
    }

}

void loggedInPage() {
    if (!loggedIn)
        return;

    cout << "1.View your profile\n2.Search for a user\n3.Messages\n4.Sign out\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        viewYourProfile();
    }
    else if (choice == 2) {
        cout << "Email: ";
        string email;
        cin >> email;
        int index = currentSystem.findUser(0, currentSystem.getUsersCount() - 1, email);
        if (index == -1)
            cout << "User does not exist.\n";
        else if (currentSystem.getUser(index) == currentSystem.getLoggedInUser()) {
            viewYourProfile();
        }
        else
            viewUserProfile(currentSystem.getUser(index));

    }
    else if (choice == 3) {
        cout << "1.Send message\n2.View received messages\n3.View sent messages\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Email: ";
            string email;
            cin >> email;
            int index = currentSystem.findUser(0, currentSystem.getUsersCount() - 1, email);
            if (index == -1)
                cout << "User does not exist.\n";
            else
                sendMessage(currentSystem.getUser(index));
        }
        else if (choice == 2) {
            for (int i = 0; i < currentSystem.getLoggedInUser()->getReceivedMessagesCount(); i++) {
                cout << currentSystem.getLoggedInUser()->getRecievedMessage(i) << endl;
            }
        }
        else if (choice == 3) {
            for (int i = 0; i < currentSystem.getLoggedInUser()->getSentMessagesCount(); i++) {
                cout << currentSystem.getLoggedInUser()->getSentMessage(i) << endl;
            }
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    else if (choice == 4) {
        loggedIn = false;
    }
    else {
        cout << "Invalid choice.\n";
    }
}

int main() {

    while (true) {
        if (startPage() == false)
            break;

        loggedInPage();
    }

}
