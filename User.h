#ifndef USER_H
#define USER_H

#include "Poll.h"
#include "Photo.h"
#include "Status.h"
<<<<<<< HEAD
#include "Message.h"
#include "Notifications.h"

class System;

class User {
private:
    Notifications *notifications;
    string name, password, gender, email;
    DateTime birthDate;
    int friendsCount;
    User **friends;
//    int postsCount;
//    Post **posts;
    vector<Message> receivedMessages;
    vector<Message> sentMessages;

    bool strongPassword(string password);
    bool validEmail(string email);
    bool validName(string name);

//    void putInPosts(Post *P);
    void addFriend(User *aUser); // send friend request => accept => add friend
public:
    User();
    Notifications *getNotifications();

    int findFriend(string email); // return index or -1 if not found

    void sendFriendRequest(User *aUser);
    void acceptFriend(User *aUser); // accept friend request from aUser
    void removeFriend(User *aUser); // reject friend request from aUser

//    void addPost();

    void sendMessage(User *aUser, Message newMessage);

=======

#include "Message.h"

class User {

private:
    string name, password, gender, email;
    DateTime birthDate;
    string interests[3];
    int friendsCount;
    int postsCount;
    User **friends;
    Post **posts;
    vector<Message> receivedMessages;
    vector<Message> sentMessages;

    void putInPosts(Post *P);

public:
    User();

    void editInfo();

    void addFriend(User *aUser);
    void removeFriend(string email);

    void addPost();

    void sendMessage(User *aUser, Message newMessage);

    int findFriend(int lower, int upper, string email); // binary search return index or -1 if not found

>>>>>>> Project
    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
<<<<<<< HEAD
    void setEmail(string email, System &currentSystem);
=======
    void setEmail(string email);
>>>>>>> Project
    string getEmail();
    void setGender(int);
    string getGender();
    void setBirthDate(DateTime birthDate);
    DateTime getBirthDate();
    int getFriendsCount();
<<<<<<< HEAD
    User *getFriend(int index);
    int getReceivedMessagesCount();
    Message getReceivedMessage(int index);
    int getSentMessagesCount();
    Message getSentMessage(int index);

    ~User();
=======
    void setInterests(string interest[]);
    User * getFriend(int index);
    int getReceivedMessagesCount();
    Message getRecievedMessage(int index);
    int getSentMessagesCount();
    Message getSentMessage(int index);


    ~User();

>>>>>>> Project
};

#endif // USER_H
