//
// Created by Omar Mohamed on 20/12/2015.
//

#ifndef SOCIAL_USER_H
#define SOCIAL_USER_H

#include "Message.h"
#include "Post.h"
using namespace std;

class User {
private:
    string name, password, gender, email;
    DateTime birthDate;
    vector<string> interests;
    vector<User> friends;
    vector<Message> receivedMessages;
    vector<Message> sentMessages;
    vector<Post> posts;
public:
    void editInfo();
    void viewInfo();
    void addFriend();
    User findFriend();

    void viewPosts();
    void viewFriends();
    void viewReceivedMessages();
    void viewSentMessages();
    void receiveMessage(Message);


    void addStatus(string);
    void addLocation(string);

    void sendMessage(string text);

    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setBirthDate(DateTime birthDate);
    DateTime getBirthDate();

    void setGender(string gender);
    string getGender();



};


#endif //SOCIAL_USER_H
