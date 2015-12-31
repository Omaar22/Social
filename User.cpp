#include "User.h"
#include "System.h"
#include "Status.h"
#include "Post.h"
#include "Poll.h"
#include "Photo.h"
#include "Message.h"

#include <bits/stdc++.h>
using namespace std;

User::User() : posts( new Post*[100] ) , numOfPosts(0) , numOfFriends(0) {}
User::~User() {}


void User::editInfo()
{
    int chois ;
    string s ;
    cout << "Press the Number of What You Want To Edit ? " << endl;
    cout << "1. Name\n2. Password\n3. Gender\n4. Email\n5. Date Of Birth\n6. Interests" << endl;
    cin >> chois ;

    while( chois <= 0 || chois > 6 )
    {
        cout << "Wrong Choise, TRY AGAIN : " ;
        cin >> chois ;
    }

    if( chois == 1 )
    {
        while(8)
        {
            cout << "Enter The New Name : ";
            s = "";
            while( s == "") getline (cin , s) ;
            try
            {
                setName(s);
                break;
            }
            catch ( const char *c)
            {
                cout << c ;
            }

        }
    }
    else if( chois == 2 )
    {
        while(8)
        {
            cout << "Enter The New Password : ";
            cin >> s ;
            try
            {
                setPassword(s);
                break;
            }
            catch ( const char *c)
            {
                cout << c ;
            }

        }
    }
    else if( chois == 3 )
    {
        while(8)
        {
            int g ;
            cout << "Enter Gender: ";
            cin >> g ;
            try
            {
                setGender(g);
                break;
            }
            catch ( const char *c)
            {
                cout << c ;
            }

        }

    }
    else if( chois == 4 )
    {
        while(8)
        {
            cout << "Enter The New Email : ";
            s = "";
            while( s == "") getline (cin , s) ;
            try
            {
                setEmail(s);
                break;
            }
            catch ( const char *c)
            {
                cout << c ;
            }

        }
    }
    else if( chois == 5 )
    {
        while(8)
        {
            string date = "" , day , month , year ;
            cout << "Enter The New Date : ";
            cout << "Day : " ;
            cin >> day ;
            cout << "/nMonth : " ;
            cin >> month ;
            cout << "/nDay : " ;
            cin >> year ;

            if (day.size() == 1) day = '0' + day ;
            if (month.size() == 1) month = '0' + month ;
            date += day + "/" + month + "/" + year ;

            try
            {
                setBirthDate( date );
                break ;
            }
            catch ( const char *c)
            {
                cout << c;
            }
        }
    }
    else
    {
        cout << "Enter 3 New Interests: \n";

        for(int i=0 ; i<3 ; i++)
        {
            cin >> s ;
            interests[i] = s ;
        }
    }

}
void User::viewInfo( string m )
{
    //DateTime dt ;
    cout << "Name : " << name << endl;
    cout << "Gender : " << gender << endl;
    cout << "Email : " << email << endl;
    //cout << "Age : " << dt.calculateAge( birthDate ) ;
    cout << "Date Of Birth : " << birthDate << endl;
    cout << "Number Of friends: " << numOfFriends << endl;
    cout << "Interests : ";
    for(int i=0 ; i<3 ; i++) cout << interests[i] << " " ;
    cout << endl;

    if( email == m )
    {
        cout << "Do You Want To Edit Info ? ( 1. Yes  2. No ) \n";
        int chois;
        cin >> chois ;
        while(chois != 1 && chois != 2)
        {
            cout << "Wrong Chois, TRY AGAIN : ";
            cin >> chois ;
        }
        if( chois == 1 )
        {
            editInfo();
        }
    }
}

/////////////////

bool User::isFriend( string mail )
{
    for(int i=0 ; i< numOfFriends ; i++ )
    {
        if( friends[i]->getEmail() == mail ) return 1 ;
    }
    return 0 ;
}
void User::viewFriends()
{
    int number , chois ;
    cout << endl << "Friends :" << endl;
    for(int i=0 ; i<numOfFriends ; i++)
    {
        cout << i+1 << ". " << friends[i]->getName() << endl;
    }
    cout << endl;
    cout << "Do You Want To view Some One Profile ? " << endl << "1. Yes  2.No" << endl;
    cin >> chois ;
    if( chois == 1 )
    {
        cout << "Enter Number Of Friend To View Profile : " ;
        cin >> number ;
        while( number < 0 || number > numOfFriends )
        {
            cout << "Wrong Choise, TRY AGAIN : ";
            cin >> number ;
        }
        friends[ number-1 ]->viewUser( this ) ;
    }
}
void User::addFriend( User *U )
{
    numOfFriends++;
    User **tmpFriends = new User*[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends-1 ; i++)
    {
        tmpFriends[i] = friends[i];
    }

    //delete[] friends;
    tmpFriends[ numOfFriends-1 ] = U ;
    friends = new User*[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends ; i++)
    {
        friends[i] = tmpFriends[i] ;
    }

    delete[] tmpFriends ;
//    merge_sort( friends , numOfFriends ) ;

}
void User::removeFriend( string mail )
{
    numOfFriends--;
    User **tmpFriends = new User*[ numOfFriends ] ;

    for(int i=0,j=0 ; i<=numOfFriends ; i++)
    {
        if( friends[i]->getEmail() != mail )
            tmpFriends[j++] = friends[i];
    }
    //delete[] friends;

    friends = new User*[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends ; i++)
        friends[i] = tmpFriends[i] ;

    delete[] tmpFriends ;
}


//////////////////
 void User::viewUser( User *logged )
{
    int choice;
    cout << endl << name << endl;

    if( isFriend(logged->getEmail()) )
    {
        cout << "1. Send Massage\n2. View Information\n3. View Posts\n4. Remove From Friends\n6. No Thanks" << endl;
        cin >> choice;
        while( choice < 0 && choice > 4)
        {
            cout << "Wrong Choice, Enter Again: ";
            cin >> choice ;
        }
        if( choice == 1 )
        {
            string s ;
            s = "";
            cout << "Enter Massage : ";
            while( s == "") getline ( cin , s );

            Message msg(s , name , logged->getName() ) ;
            logged->sendMessage( msg ) ;
            receivedMessages.push_back(msg);
        }
        else if ( choice == 2 )
        {
            viewInfo( logged->getEmail() ) ;
        }
        else if( choice == 3 )
        {
            viewPosts();
        }
        else if( choice == 4 )
        {
            logged->removeFriend( email );
            removeFriend(logged->getEmail()) ;
        }

    }
    else
    {
        cout << "1. Send Massage/n2.Add Friend/n3. No Thanks";
        while( choice < 0 && choice > 3)
        {
            cout << "Wrong Choice, TRY AGAIN : " ;
            cin >> choice ;
        }
        if( choice == 1 )
        {
            string s = "" ;
            cout << "Enter Massage : ";
            while(s == "")
            getline ( cin , s );

            Message msg(s , name , logged->getName() ) ;
            logged->sendMessage( msg ) ;
            receivedMessages.push_back(msg);
        }
        else if ( choice == 2 )
        {
            addFriend(logged) ;
            logged->addFriend(this) ;
        }

    }
}

///////////////////

void User::addPost()
{
    int choice ;
    string s ;
    cout << "1. Status\n2. Poll\n3. Photo/Video" << endl;
    cout << "\nEnter choice : " ;
    cin >> choice;

    while( choice < 0 || choice > 3)
    {
        cout << "Wrong Choise, TRY AGAIN : ";
        cin >> choice ;
    }

    if( choice == 1 )
    {
        Status *st = new Status;
        cout << "Enter Status : ";

        s = "";
        while(s == "") getline( cin , s);

        st->addStatus(s) ;
        putInPosts( st );
    }

    else if( choice == 2)
    {
        Poll *pol = new Poll ;
        int num ;
        cout << "Enter Question : ";
        s = "";
        while(s == "") getline( cin , s ) ;

        cout << "Enter Number Of answers : ";
        cin >> num ;

        string ans;
        cout << "Enter The Answers : ";

        pol->addQuestion( s ) ;

        for( int i=1 ; i<=num ; i++)
        {
            cout << "Answer " << i << ": ";
            ans = "";
            while( ans == "" ) getline ( cin , ans ) ;
            pol->addAnswers(ans) ;
        }

        putInPosts( pol );
    }
    else
    {
        Photo *pv = new Photo;
        cout << "Enter Link : ";
        s = "";
        while( s == "") getline( cin , s ) ;

        pv->addPhoto( s ) ;
        putInPosts( pv );
    }

}
void User::putInPosts( Post *P )
{
    posts[numOfPosts++] = P;
}
void User::viewPosts()
{
    for(int i=0 ; i<numOfPosts ; i++)
    {
        posts[i]->view();
    }
}

//////////////////////

void User::recieveMessage(Message msg)
{
    receivedMessages.push_back( msg );
}
void User::sendMessage(Message msg)
{
    sentMessages.push_back( msg );
}
void User::sendMessageFun(User *U)
{
        cout << "Enter Message Text : " ;
        string s;
        s = "";
        while( s == "" );
        getline( cin , s ) ;

        Message msg(s , U->getName() , name) ;
        sentMessages.push_back( msg ) ;
        U->recieveMessage( msg ) ;
}
void User::viewReceivedMessages()
{
    for(int i=0 ; i<receivedMessages.size() ; i++)
    {
        cout << receivedMessages[i].getMessage();
    }
}
void User::viewSentMessages()
{
    for(int i=0 ; i<sentMessages.size() ; i++)
    {
        cout << sentMessages[i].getMessage();
    }
}

//////////////////////

void User::setBirthDate( string date)
{
    if (!System::validDate(date))
    {
        throw "Invalid date";
    }
    birthDate = date ;
}

void User::setPassword( string pass)
{
    if (!System::strongPassword(pass))
    {
        throw "password size should be at least 8 characters\nit must contains at least one uppercase, one lowercase, and one number";

    }
    password = pass;
}

void User::setGender(int g)
{
    if (g != 1 && g != 2)
    {
        throw "Wrong choice";
    }
    else if (g == 1) gender = "Male";
    else gender ="Female";
}

void User::setEmail(string mail)
{
    int x = System::validEmail(mail) ;
    if ( x == 2)
    {
        throw "Email already Exists";
    }
    else if (x == 3)
    {
        throw "Invalid Email";
    }
    else email = mail;
}

void User::setName(string name)
{
    if (!System::validName(name))
    {
        throw "Invalid name";
    }
    this->name = name;
}

string User::getBirthDate()
{
    return birthDate ;
}
string User::getPassword()
{
    return password ;
}
string User::getGender()
{
    return gender ;
}
string User::getEmail()
{
    return email ;
}
string User::getName()
{
    return name ;
}
int User::getNumOfFriends()
{
    return numOfFriends ;
}
