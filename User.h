#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

class User {
private:
    string name, password, gender, email;
    string birthDate;
    string interests[3];
    int numOfFriends = 0 ;
    int numOfPosts = 0 ;

    User *friends;
    //Post **posts;
    //vector <Message> receivedMessages;
    //vector <Message> sentMessages;

    void editInfo();
    //void putInPosts( Post *P ) ;

public:
    void remove(User U) ;

    void viewInfo();

    bool isFriend( User U );
    void viewFriends();
    void addFriend( User U);
    void removeFriend( User U);

    User searchUser( string mail );

    void addPost();
    void viewPosts();
    void viewUser( User U);

    void viewReceivedMessages();
    void viewSentMessages();

    //void receiveMessage(Message);
    void sendMessage();

    int getNumOfFriends();
    void setName(string name);
    string getName();
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setGender(string gender);
    string getGender();
    void setBirthDate( string birthDate);
    string getBirthDate();


    User();
    ~User();

};

#endif
