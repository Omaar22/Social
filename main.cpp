#include "System.h"

System mySystem;

bool signUp() {
    User *newUser = new User;

    cout << "Enter \"-1\" to exit at anytime.\n";

    while (true) {
        string name;
        cout << "Name: ";

        while (name.size() == 0)
            getline(cin, name);

        if (name == "-1") {
            delete newUser;
            return false;
        }
        try {
            newUser->setName(name);
            break;
        }
        catch (char const *error) {
            cout << error << endl;
        }
    }

    while (true) {
        cout << "Password: ";
        string password;
        cin >> password;
        if (password == "-1") {
            delete newUser;
            return false;
        }
        try {
            newUser->setPassword(password);
            break;
        }
        catch (char const *error) {
            cout << error << endl;
        }
    }

    while (true) {
        string email;
        cout << "Email : ";
        cin >> email;
        if (email == "-1") {
            delete newUser;
            return false;
        }
        try {
            newUser->setEmail(email, mySystem);
            break;
        }
        catch (char const *error) {
            cout << error << endl;
        }
    }

    while (true) {
        cout << "Gender (1.Male 2.Female): ";
        int choice;

        cin >> choice;
        if (choice == -1) {
            delete newUser;
            return false;
        }
        try {
            newUser->setGender(choice);
            break;
        }
        catch (char const *error) {
            cout << error << endl;
        }
    }


    DateTime birthDate;
    while (true) {
        cout << "Birth date in in DD/MM/YYYY format: ";
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

    mySystem.signUp(newUser);

    return mySystem.signIn(newUser->getEmail(), newUser->getPassword());
}

bool signIn() {
    string email, password;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    return mySystem.signIn(email, password);
}

bool startPage() {
    while (!mySystem.isSignedIn()) {
        cout << "1.Sign up\n2.Sign in\n3.Exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            if (signUp()) {
                cout << "Welcome " << mySystem.getLoggedInUser()->getName() << "!\n\n";
                return true;
            }
            else
                cout << "\n";
        }
        else if (choice == 2) {
            if (signIn()) {
                cout << "Welcome " << mySystem.getLoggedInUser()->getName() << "!\n\n";
                return true;
            }
            else
                cout << "Invalid email or password.\n\n";
        }
        else if (choice == 3)
            return false;
        else
            cout << "Invalid choice.\n\n";
    }
    return true;
}

void sendMessage(User *aUser) {
    cout << "Text: ";
    string text;
    while (text.size() == 0)
        getline(cin, text);
    string sender = mySystem.getLoggedInUser()->getName();
    string receiver = aUser->getName();
    Message newMessage(text, receiver, sender);

    mySystem.getLoggedInUser()->sendMessage(aUser, newMessage);

    cout << "Message sent.\n\n";
}

void userProfile(User *aUser) {
    while (true) {
        bool isFriend =
                mySystem.getLoggedInUser()->findFriend(aUser->getEmail()) != -1;

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
                    mySystem.getLoggedInUser()->removeFriend(aUser);
                    aUser->removeFriend(mySystem.getLoggedInUser());
                    cout << aUser->getName() << " removed successfully.\n";
                }
                catch (string error) {
                    cout << error << endl;
                    userProfile(aUser);
                }
            }
            else if (choice == 4) {
                return;
            }
            else {
                cout << "Invalid choice.\n";
                userProfile(aUser);
            }
        }
        else {
            bool hasRequest =
                    mySystem.getLoggedInUser()->getNotifications()->findFriendRequest(aUser->getEmail()) != -1;
            bool pendingRequest =
                    aUser->getNotifications()->findFriendRequest(mySystem.getLoggedInUser()->getEmail()) != -1;

            if (hasRequest)
                cout << "1.Accept friend request from " << aUser->getName() << endl;
            else if (pendingRequest)
                cout << "1.Cancel friend request.\n";
            else
                cout << "1.Send friend request to " << aUser->getName() << endl;

            cout << "2.Send Message\n3.Back\n";
            int choice;
            cin >> choice;

            if (choice == 1 && hasRequest) {
                mySystem.getLoggedInUser()->acceptFriend(aUser);
            }
            else if (choice == 1 && pendingRequest) {
                int index = aUser->getNotifications()->findFriendRequest(mySystem.getLoggedInUser()->getEmail());
                aUser->getNotifications()->rejectFriendRequest(index);
            }
            else if (choice == 1) {
                try {
                    mySystem.getLoggedInUser()->sendFriendRequest(aUser);
                    cout << "Friend request sent.\n";
                }
                catch (const char *error) {
                    cout << error << endl;
                    userProfile(aUser);
                }
            }
            else if (choice == 2)
                sendMessage(aUser);

            else if (choice == 3)
                return;

            else {
                cout << "Invalid choice.\n";
                userProfile(aUser);
            }
        }
    }
}

void editYourProfile() {
    cout << "Enter \"-1\" to exit at anytime.\n";
    cout << "1.Name\n2.Password\n3.Email\n4.Gender\n5.Date Of Birth\n" << endl;
    int choice;
    cin >> choice;

    if (choice == -1)
        return;

    if (choice == 1) {
        while (true) {
            string name;
            cout << "Name: ";

            while (name.size() == 0)
                getline(cin, name);

            if (name == "-1") {
                return;
            }
            try {
                mySystem.getLoggedInUser()->setName(name);
                break;
            }
            catch (char const *error) {
                cout << error << endl;
            }
        }

    }
    else if (choice == 2) {

        while (true) {
            cout << "Password: ";
            string password;
            cin >> password;
            if (password == "-1") {
                return;
            }
            try {
                mySystem.getLoggedInUser()->setPassword(password);
                break;
            }
            catch (char const *error) {
                cout << error << endl;
            }
        }
    }
    else if (choice == 3) {
        while (true) {
            string email;
            cout << "Email : ";
            cin >> email;
            if (email == "-1") {
                return;
            }
            try {
                mySystem.getLoggedInUser()->setEmail(email, mySystem);
                break;
            }
            catch (char const *error) {
                cout << error << endl;
            }
        }
    }
    else if (choice == 4) {
        while (true) {
            cout << "Gender (1.Male 2.Female): ";
            int gender;
            cin >> gender;
            if (gender == -1) {
                return;
            }
            try {
                mySystem.getLoggedInUser()->setGender(gender);
                break;
            }
            catch (char const *error) {
                cout << error << endl;
            }
        }
    }
    else if (choice == 5) {

        DateTime birthDate;
        while (true) {
            cout << "Birth date in in DD/MM/YYYY format: ";
            string date;
            cin >> date;
            if (date == "-1") {
                return;
            }
            try {
                birthDate.setDate(date);
                break;
            }
            catch (const char *error) {
                cout << error << endl;
            }
        }
        mySystem.getLoggedInUser()->setBirthDate(birthDate);
    }
    else
        cout << "Invalid choice.";

}

void yourProfile() {
    cout << "Name: " << mySystem.getLoggedInUser()->getName() << endl
    << "Email: " << mySystem.getLoggedInUser()->getEmail() << endl
    << "Gender: " << mySystem.getLoggedInUser()->getGender() << endl
    << "Birth date: " << mySystem.getLoggedInUser()->getBirthDate() << " (" <<
    mySystem.getLoggedInUser()->getBirthDate().calculateAge() << " Years old)\n";

    while (true) {
        int friendRequestsCount = mySystem.getLoggedInUser()->getNotifications()->getFriendRequestsCount();
        bool hasFriendRequest = false;
        if (friendRequestsCount != 0) {
            cout << "(" << friendRequestsCount << ") friend requests.\n";
            hasFriendRequest = true;

        }

        int acceptedRequestsCount = mySystem.getLoggedInUser()->getNotifications()->getAcceptedRequestCount();
        bool hasAcceptedRequests = acceptedRequestsCount != 0;
        if (hasAcceptedRequests)
            cout << "(" << acceptedRequestsCount << ") accepted your friend request.\n";


        int indexCounter = 1;
        if (hasFriendRequest)
            cout << indexCounter++ << ".View friend requests\n";
        if (hasAcceptedRequests)
            cout << indexCounter++ << ".View accepted friends\n";
        cout << indexCounter++ << ".Edit your profile\n";
        cout << indexCounter++ << ".Your friends\n";
        cout << indexCounter++ << ".back\n";


        int choice;
        cin >> choice;

        if (choice == 1 && hasFriendRequest) { //View friend requests
            for (int i = 0; i < mySystem.getLoggedInUser()->getNotifications()->getFriendRequestsCount(); i++) {
                cout << mySystem.getLoggedInUser()->getNotifications()->getFriendRequest(i)->getName() << endl;
                bool male = mySystem.getLoggedInUser()->getNotifications()->getFriendRequest(i)->getGender() == "Male";
                if (male)
                    cout << "1.View his profile\n";
                else
                    cout << "1.View her profile\n";
                cout << "2.Accept\n3.Reject\n4.Continue\n5.Back\n";
                cin >> choice;
                if (choice == 1) {
                    userProfile(mySystem.getLoggedInUser()->getNotifications()->getFriendRequest(i));
                    break;
                }
                else if (choice == 2) {
                    try {
                        User *requestedUser = mySystem.getLoggedInUser()->getNotifications()->getFriendRequest(i);
                        mySystem.getLoggedInUser()->acceptFriend(requestedUser);
                        i--;
                    }
                    catch (char const *error) {
                        cout << error << endl;
                        break;
                    }
                }
                else if (choice == 3) {
                    mySystem.getLoggedInUser()->getNotifications()->rejectFriendRequest(i);
                    i--;
                }
                else if (choice == 4) {
                    continue;
                }
                else if (choice == 5) {
                    break;
                }
                else {
                    cout << "Invalid choice.\n";
                    i--;
                }
            }
        }
        else if (choice == 1 && hasAcceptedRequests || choice == 2 && hasAcceptedRequests) {
            for (int i = 0; i < mySystem.getLoggedInUser()->getNotifications()->getAcceptedRequestCount(); i++) {
                cout << mySystem.getLoggedInUser()->getNotifications()->getAcceptedRequest(i)->getName() << endl;
                cout << "1.View profile\n2.Continue\n3.Back\n";
                cin >> choice;
                if (choice == 1) {
                    userProfile(mySystem.getLoggedInUser()->getNotifications()->getAcceptedRequest(i));
                    mySystem.getLoggedInUser()->getNotifications()->removeAcceptedRequests(i);
                    break;
                }
                else if (choice == 2) {
                    mySystem.getLoggedInUser()->getNotifications()->removeAcceptedRequests(i);
                }
                else if (choice == 3) {
                    break;
                }
                else {
                    cout << "Invalid choice.\n";
                    i--;
                }
            }
        }
        else if (choice == indexCounter - 3) {
            editYourProfile();
        }
        else if (choice == indexCounter - 2) {
            if (mySystem.getLoggedInUser()->getFriendsCount() == 0) {
                cout << "You have no friends.\n";
                break;
            }
            cout << "Your friends:\n";
            for (int i = 0; i < mySystem.getLoggedInUser()->getFriendsCount(); i++) {
                cout << i + 1 << ". " << mySystem.getLoggedInUser()->getFriend(i)->getName() << endl;
            }
            while (true) {
                cout << "Enter index to go to profile or 0 to back.\n";
                cin >> choice;
                if (choice == 0) {
                    break;
                }
                else if (0 < choice && choice <= mySystem.getLoggedInUser()->getFriendsCount()) {
                    int index = mySystem.findUser(mySystem.getLoggedInUser()->getFriend(choice - 1)->getEmail());
                    userProfile(mySystem.getUser(index));
                    break;
                }
                else {
                    cout << "Invalid choice.\n";
                }
            }
        }
        else if (choice == indexCounter - 1) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    cout << endl;
}

void loggedInPage() {
    if (!mySystem.isSignedIn())
        return;

    cout << "1.View your profile";
    int total = mySystem.getLoggedInUser()->getNotifications()->getFriendRequestsCount() +
                mySystem.getLoggedInUser()->getNotifications()->getAcceptedRequestCount();
    if (total != 0)
        cout << "(" << total << ")";
    cout << "\n2.Search for a user\n3.Messages";

    if (mySystem.getLoggedInUser()->getNotifications()->getUnreadMessagesCount() != 0)
        cout << "(" << mySystem.getLoggedInUser()->getNotifications()->getUnreadMessagesCount() << ")";
    cout << "\n4.Sign out\n";

    int choice;
    cin >> choice;
    if (choice == 1) {
        yourProfile();
    }
    else if (choice == 2) {
        cout << "Email: ";
        string email;
        cin >> email;
        int index = mySystem.findUser(email);
        if (index == -1)
            cout << "User does not exist.\n";
        else if (mySystem.getUser(index) == mySystem.getLoggedInUser()) {
            yourProfile();
        }
        else
            userProfile(mySystem.getUser(index));

    }
    else if (choice == 3) {
        cout << "1.Send message\n2.View received messages\n3.View sent messages\n4.Back\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Email: ";
            string email;
            cin >> email;
            int index = mySystem.findUser(email);
            if (index == -1)
                cout << "User does not exist.\n\n";
            else
                sendMessage(mySystem.getUser(index));
        }
        else if (choice == 2) {
            for (int i = 0; i < mySystem.getLoggedInUser()->getReceivedMessagesCount(); i++) {
                cout << mySystem.getLoggedInUser()->getReceivedMessage(i) << endl << endl;
            }
            mySystem.getLoggedInUser()->getNotifications()->clearUnreadMessages();
        }
        else if (choice == 3) {
            for (int i = 0; i < mySystem.getLoggedInUser()->getSentMessagesCount(); i++) {
                cout << mySystem.getLoggedInUser()->getSentMessage(i) << endl << endl;
            }
        }
        else if (choice == 4) {
            return;
        }
        else {
            cout << "Invalid choice.\n\n";
        }
    }
    else if (choice == 4) {
        cout << "Goodbye " << mySystem.getLoggedInUser()->getName() << endl << endl;
        mySystem.signOut();

    }
    else {
        cout << "Invalid choice.\n\n";
    }
}

int main() {

    while (true) {
        if (startPage() == false)
            break;

        loggedInPage();
    }

}
