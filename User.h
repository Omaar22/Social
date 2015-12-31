#ifndef USER_H
#define USER_H
#include "Post.h"
#include "Status.h"
#include "Message.h"

#include <bits/stdc++.h>
using namespace std;

class User
{

    private:

        string name, password, gender, email, birthDate ;
        int numOfFriends ;
        int numOfPosts ;
        string interests[3] ;
        User **friends;
        Post **posts;

        vector <Message> receivedMessages;
        vector <Message> sentMessages;

        void putInPosts( Post *P ) ;

    public:

        void viewInfo(string);
        void editInfo();
        bool isFriend( string );
        void viewFriends();
        void addFriend( User* ) ;
        void removeFriend( string ) ;
        User getFriends();

        User searchUser( string );

        void addPost();
        void viewPosts();
        void viewUser( User* );

        void viewReceivedMessages();
        void viewSentMessages();

        void sendMessage(Message);
        void recieveMessage(Message);
        void sendMessageFun(User*);

        void setName( string );
        string getName();
        void setPassword( string );
        string getPassword();
        void setEmail( string );
        string getEmail();
        void setGender( int );
        string getGender();
        void setBirthDate( string );
        string getBirthDate();
        int getNumOfFriends();



        User();
        ~User();

};

#endif
