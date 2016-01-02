#ifndef USER_H
#define USER_H

#include "Post.h"
#include "Status.h"
#include "Message.h"

#include <bits/stdc++.h>

using namespace std;

class User {

private:

    string name, password, gender, email, birthDate;
    int numOfFriends;
    int numOfPosts;
    string interests[3];
    User **friends;
    Post **posts;

    vector<Message> receivedMessages;
    vector<Message> sentMessages;


public:
    void putInPosts(Post *P);

    void viewInfo(string);
    void editInfo();
    bool isFriend(string);
    void viewFriends(User *);
    void addFriend(User *);
    void removeFriend(string);

    void addPost();
    void viewPosts(User *);
    void viewUser(User *, User *);
    User searchUser(string);

    void viewReceivedMessages();
    void viewSentMessages();
    vector<Message> getReceivedMessages();
    vector<Message> getsentMessages();

    void sendMessage(Message);
    void recieveMessage(Message);
    void sendMessageFun(User *);

    void setName(string);
    string getName();
    void setPassword(string);
    string getPassword();
    void setEmail(string);
    string getEmail();
    void setGender(int);
    string getGender();
    void setBirthDate(string);
    string getBirthDate();
    int getNumOfFriends();


    User();
    ~User();

    User *getFriends(int index);
    int getNumOfPosts();
    Post *getPost(int index);
};

#endif
