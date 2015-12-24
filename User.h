//
// Created by Omar Mohamed on 20/12/2015.4
// Updated By Salma Samy
//

#ifndef USER_H
#define USER_H

#include "Message.h"
#include "Post.h"

using namespace std;

class User {
private:
    string name, password, gender, email;
    DateTime birthDate;
    string interests[3];
    int numOfFriends = 0 ;
    int numOfPosts = 0 ;
    User *friends;
    Post **posts;
    Message receivedMessages;
    vector<Message> sentMessages;

    void editInfo(); // Done
    void putInPosts( Post *P ) ; // Done

public:

    void viewInfo(); // Done

    void viewFriends(); // Done
    void addFriend( User U); // Done
    void removeFriend( User U); //Done

    User findUser( string mail ); //Done

    void addPost(); // Done
    void viewPosts(); // Done
    void viewUser( User U); // Done

    void viewReceivedMessages();
    void viewSentMessages();

    void receiveMessage(Message);
    void sendMessage(string text , User U);

    // Done All
    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setGender(string gender);
    string getGender();
    void setBirthDate(DateTime birthDate);
    DateTime getBirthDate();

};

