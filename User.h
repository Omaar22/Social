#ifndef USER_H
#define USER_H

#include "Poll.h"
#include "Photo.h"
#include "Status.h"

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

    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setGender(int);
    string getGender();
    void setBirthDate(DateTime birthDate);
    DateTime getBirthDate();
    int getFriendsCount();
    void setInterests(string interest[]);
    User * getFriend(int index);
    int getReceivedMessagesCount();
    Message getRecievedMessage(int index);
    int getSentMessagesCount();
    Message getSentMessage(int index);


    ~User();

};

#endif // USER_H
