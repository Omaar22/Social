#ifndef USER_H
#define USER_H
#include "Post.h"
#include "Poll.h"
#include "Photo.h"
#include "Status.h"

#include <bits/stdc++.h>
#include "Message.h"
using namespace std;

class User {

private:
    string name, password, gender, email;
    string birthDate;
    string interests[3];
    int numOfFriends;
    int numOfPosts;
    User *friends;
    Post **posts;
    vector <Message> receivedMessages;
    vector <Message> sentMessages;

    void editInfo();
    void putInPosts( Post *P ) ;

public:

    void viewInfo();

    bool isFriend( User U );
    void viewFriends();
    void mutualFriends (User);
    void addFriend( User U) ;
    void removeFriend( User U) ;
    void remove(User U) ;

    User searchUser( string mail );

    void addPost();
    void viewPosts();
    void viewUser( User *&);

    void viewReceivedMessages();
    void viewSentMessages();

    void receiveMessage(Message);
    void sendMessage();

    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setGender(int);
    string getGender();
    void setBirthDate( string birthDate);
    string getBirthDate();
    int getNumOfFriends();


    User();
    ~User();

};

#endif
