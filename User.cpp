#include "User.h"
#include "System.h"
#include "Status.h"
#include "Post.h"
#include "Poll.h"
#include "Photo.h"
#include "Message.h"

#include <bits/stdc++.h>
using namespace std;

User::User() {
	posts = new Post* [100];
	friends = NULL;
	numOfFriends = 0;
	numOfPosts = 0;
}
User::~User(){}

systems sm;

void User::editInfo()
{
    int chois ;
    string s ;
    cout << "Press the Number of What You Want To Edit ? " << endl;
    cout << " 1.Name\n2.Password\n3.Gender\n4.Email\n5.Date Of Birth\n6.Interests" << endl;
    cin >> chois ;

    while( chois <= 0 || chois > 6 )
    {
        cout << "Wrong Choise, TRY AGAIN : " ;
        cin >> chois ;
    }
    if( chois == 1 )
    {
        cout << "Enter The New Name : ";
        getline (cin , s) ;
        while( !sm.validName( s ) )
        {
            cout << "Name must not have numbers , TRY AGAIN : ";
            getline (cin , s) ;
        }
        setName(s);
    }
    else if( chois == 2 )
    {
        cout << "Enter The New Password : ";
        cin >> s ;
        while ( !sm.strongPassword(s) )
        {
            cout << "Password is not strong enough, password size should be at least 8 characters" << endl;
            cout << "it must contains at least one uppercase, one lowercase, and one number" << endl;
            cout << "TRY AGAIN : ";
            cin >> s ;
        }
        setPassword(s);
    }
    else if( chois == 3 )
    {
        cout << "Enter Gender (1 for male , 2 for female) : " << endl;
        cin >> chois ;
        while ( chois != 1 && chois != 2 )
        {
            cout << "Wrong Chois, TRY AGAIN : ";
            cin >> chois ;
        }
        setGender(chois) ;

    }
    else if( chois == 4 )
    {
        cout << "Enter The New Email : ";
        getline (cin , s) ;

        while ( !sm.validEmail(s) )
        {
            cout << "Not Valid, TRY AGAIN : ";
            getline (cin , s) ;
        }
        setEmail(s);
    }
    else if( chois == 5 )
    {
        string date = "" , day , month , year ;
        cout << "Enter The New Date : ";
        cout << "Day : " ; cin >> day ;
        cout << "/nMonth : " ; cin >> month ;
        cout << "/nDay : " ; cin >> year ;
        date += day + "/" + month + "/" + year ;
        setBirthDate( date );
    }
    else
    {
        cout << "Enter 3 New Interests : ";

        for(int i=0 ; i<3 ; i++)
        {
            cin >> s ;
            interests[i] = s ;
        }
    }

}

void User::viewInfo()
{
    cout << "\n" << this->getName() << " Information --->\n";
    //DateTime dt ;
    cout << "Name : " << name << endl;
    cout << "Gender : " << gender << endl;
    cout << "Email : " << email << endl;
    //cout << "Age : " << dt.calculateAge( birthDate ) ;
    cout << "Date Of Birth : " << birthDate << endl;
    cout << "Interests : ";
    for(int i=0 ; i<3 ; i++) cout << interests[i] << " " ;
    cout << endl;

    if(name == sm.loggedInUser.getName())
    {
        cout << "Do You Want To Edit Info ?" << endl << "1. Yes  2. No";
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


void User::mutualFriends(User myfriend){ //could be better!

	int numOfMutualFriends = 0;
	vector <string> myfriends;

	cout << myfriend.getNumOfFriends() << endl;



}
bool User::isFriend( User U )
{
    for(int i=0 ; i< numOfFriends ; i++ )
    {
        if( friends[i].getEmail() == U.getEmail() ) return 1 ;
    }
    return 0 ;
}

void User::viewFriends()
{
    int number , chois ;
    cout << endl << "Friend :" << endl;
    for(int i=0 ; i<numOfFriends ; i++)
    {
        cout << i+1 << ". " << friends[i].getName() << endl;
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
        User *U = &friends[ number-1 ];


        viewUser(U) ;
    }
}

void User::addFriend( User U )
{
    numOfFriends++;
    User *tmpFriends = new User[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends-1 ; i++)
    {
        tmpFriends[i] = friends[i];
    }

    //delete[] friends;
    tmpFriends[ numOfFriends-1 ] = U ;
    friends = new User[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends ; i++)
    {
        friends[i] = tmpFriends[i] ;
    }

    delete[] tmpFriends ;
    sm.merge_sort(friends , numOfFriends ) ;
}

void User::removeFriend( User U )
{
    numOfFriends--;
    User *tmpFriends = new User[ numOfFriends ] ;

    for(int i=0,j=0 ; i<=numOfFriends ; i++)
    {
        if( friends[i].getEmail() != U.getEmail() )
        tmpFriends[j++] = friends[i];
    }
    delete[] friends;

    friends = new User[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends ; i++)
    friends[i] = tmpFriends[i] ;

    delete[] tmpFriends ;
}



User User::searchUser( string mail )
{
    User *U ;
    *U = sm.searchUser( mail ) ;
    if( U->getName() == "NoUser" ) cout << "Sorry, No Such User Exist ! ";
    else viewUser( U ) ;
}
void User::viewUser( User *&U)
{
    int choice;
    cout << endl << U->getName() << endl;

    cout << U << endl;

    cout << U->getNumOfFriends() << endl;

    if( isFriend(*U) )
    {

        cout << "1. Send Massage\n2. View Information\n3. View Posts\n4. Remove From Friends\n6. No Thanks" << endl;
        cin >> choice;
        while( choice < 0 && choice > 4)
        {
            cout << "Wrong Choice, TRY AGAIN : ";
            cin >> choice ;
        }
        if( choice == 1 )
        {
            string s ;
            s = "";
            cout << "Enter Massage : ";
            while( s == "")
            getline ( cin , s );

            Message msg(s , U->getName() , name) ;
            sentMessages.push_back( msg ) ;
            U->receiveMessage( msg ) ;
        }
        else if ( choice == 2 )
        {
            U->viewInfo() ;
        }
        else if( choice == 3 )
        {
           U->viewPosts();
        }
        else if( choice == 4 )
        {
           removeFriend(*U);
           //U.removeFriend(loggedInUser) ;
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
            string s ;
            cout << "Enter Massage : ";
            getline ( cin , s );

            Message msg (s , U->getName() , name) ;
            sentMessages.push_back( msg ) ;
            U->receiveMessage( msg ) ;
        }
        else if ( choice == 2 )
        {
            addFriend(*U) ;
            //U.addFriend(loggedInUser) ;
        }

    }
}



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
        while(s == "")
        getline( cin , s);

        st->addStatus(s) ;
        putInPosts( st );
    }
    else if( choice == 2)
    {
        Poll *pol = new Poll ;
        int num ;
        cout << "Enter Question : ";
        s = "";
        while(s == "")
        getline( cin , s ) ;

        cout << "Enter Number Of answers : ";
        cin >> num ;

        string ans;
        cout << "Enter The Answers : ";

        pol->addQuestion( s ) ;

        for( int i=0 ; i<num ; i++)
        {
            ans = "";
            while( ans == "")
            getline ( cin , ans ) ;
            pol->addAnswers(ans) ;
        }

        putInPosts( pol );
    }
    else
    {
        Photo *pv = new Photo;
        cout << "Enter Link : ";
        s = "";
        while( s == "")
        getline( cin , s ) ;
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
        cout << endl;
    }
}



void User::receiveMessage(Message message)
{
    receivedMessages.push_back(message);
}
void User::sendMessage()
{
    string mail ;
    cout << "Email :";
    cin >> mail ;

    User U ;
    U = sm.searchUser( mail ) ;
    if( U.getName() == "NoUser" ) cout << "Sorry, No Such User Exist ! ";
    else
    {
        cout << "Enter Message Text : " ;
        string s;
        s = "";
        while( s == "" );
        getline( cin , s ) ;

        Message msg(s , U.getName() , name) ;
        sentMessages.push_back( msg ) ;
        U.receiveMessage( msg ) ;
    }
}
void User::viewReceivedMessages()
{
    for(int i=0 ; i<receivedMessages.size() ; i++)
    {
        cout << sentMessages[i].getMessage();
    }
}
void User::viewSentMessages()
{
    for(int i=0 ; i<sentMessages.size() ; i++)
    {
        cout << sentMessages[i].getMessage();
    }
}


void User::setBirthDate( string date )
{
    if (!sm.validDate(date))
    {
        throw "Invalid date";
    }
    birthDate = date ;
}
void User::setPassword(string password )
{
    if (!sm.strongPassword(password))
    {
        throw "Password is too weak";
    }
    this->password = password;
}
void User::setGender(int g )
{
    if (g != 1 && g != 2)
    {
        throw "Wrong choice";
    }
    else if (g == 1)
        gender = "Male";
    else
        gender ="Female";
}
void User::setEmail(string e )
{
    int x = sm.validEmail(e) ;
    if ( x == 2)
        throw "Email already Exists";
    else if (x == 3)
        throw "Invalid Email";
    email = e;
}
void User::setName(string n )
{
    if (!sm.validName(n))
    {
        throw "Invalid name";
    }
    name = n;
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
