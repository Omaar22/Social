#include "User.h"
#include "System.h"
#include "Status.h"
#include "Post.h"
#include "Poll.h"
#include "Photo.h"
#include "Message.h"

#include <bits/stdc++.h>
using namespace std;

User::User() : posts( new Post*[100] ) , friends( new User*[50] ) , numOfPosts(0) , numOfFriends(0) {}
User::~User() {}


void User::editInfo()
{
    if (system("CLS")) system("clear");
    cout << "El Social Network :\n\n\n";
    cout << "Editing information\n\n";

    char chois ; int g ;
    string s = "" ;

    cout << "1. Name\n2. Password\n3. Gender\n4. Email\n5. Date Of Birth\n6. Back\n\n";
    cout << "Enter the Number of What You Want To Edit: ";
    cin >> chois ;

    while( chois < '1' || chois > '6' )
    {
        cout << "Wrong Choice, Enter Again: " ;
        cin >> chois ;
    }

    if( chois == '1' )
    {
        while(8)
        {
            cout << "\nEnter The New Name: ";
            while( s == "") getline (cin , s) ;
            try
            {
                setName(s);
                break;
            }
            catch ( const char *c)
            {
                cout << "\n" << c ;
            }

        }
    }
    else if( chois == '2' )
    {
        while(8)
        {
            cout << "\nEnter The New Password: ";
            cin >> s ;
            try
            {
                setPassword(s);
                break;
            }
            catch ( const char *c)
            {
                cout << "\n" << c ;
            }

        }
    }
    else if( chois == '3' )
    {
        while(8)
        {
            cout << "\nEnter Gender (1 for Male , 2 for Female ): ";
            cin >> g ;
            try
            {
                setGender(g);
                break;
            }
            catch ( const char *c)
            {
                cout << "\n" << c ;
            }

        }

    }
    else if( chois == '4' )
    {
        while(8)
        {
            cout << "\nEnter The New Email: ";
            while( s == "" ) getline (cin , s) ;
            try
            {
                setEmail(s);
                break;
            }
            catch ( const char *c)
            {
                cout << "\n" << c ;
            }

        }
    }
    else if( chois == '5' )
    {
        while(8)
        {
            string date = "" , day , month , year ;
            cout << "\nEnter The New Date:\n";
            cout << "\nDay : " ;
            cin >> day ;
            cout << "\nMonth : " ;
            cin >> month ;
            cout << "\nYear : " ;
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
                cout << "\n" << c ;
            }
        }
    }
    else
    {
        return ;
    }

}
void User::viewInfo( string m )
{
    if (system("CLS")) system("clear");
    cout << "El Social Network :\n\n\n";
    cout << "About\n\n";

    DateTime dt ;
    string year  ;
    year+= birthDate[6] ;
    year+= birthDate[7] ;
    year+= birthDate[8] ;
    year+= birthDate[9] ;

    cout << "Name : " << name;
    cout << "\n\nGender : " << gender;
    cout << "\n\nEmail : " << email;
    cout << "\n\nAge : " << dt.calculateAge( year );
    cout << "\n\nDate Of Birth : " << birthDate;
    cout << "\n\nNumber Of friends: " << numOfFriends;
    cout << "\n\n";

    string chois;
    if( email == m )
    {
        cout << "Do You Want To Edit Info ? ( 1. Yes  2. Back ) : ";
        cin >> chois ;
        while(chois != "1" && chois != "2" )
        {
            cout << "Wrong Choice, Enter Again : ";
            cin >> chois ;
        }
        if( chois == "1" ) editInfo();
    }
    else
    {
        cout << "\nPress any key to go back: ";
        cin >> chois ;
    }
}
void User::viewUser( User *logged , User *caller)
{
    if (system("CLS")) system("clear");
    int choice;
    cout << endl << name << endl;
    if( logged->isFriend(caller->getEmail()) )
    {
        cout << "1. Send Massage\n2. View Information\n3. View Posts\n4. Remove From Friends\n5. Back\n\nEnter choice: " << endl;
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
            cout << "\nEnter Massage : ";
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
            viewPosts(logged);
        }
        else if( choice == 4 )
        {
            logged->removeFriend( email );
            removeFriend(logged->getEmail()) ;
        }
        else return ;

    }
    else
    {
        string Back ;
        cout << "1. Send Massage\n2. Add Friend\n3. Back\n\nEnter choice: ";
        cin >> choice;
        while( choice < 0 && choice > 3)
        {
            cout << "Wrong Choice, Enter Again: " ;
            cin >> choice ;
        }
        if( choice == 1 )
        {
            string s = "" ;
            cout << "\nEnter Massage: ";
            while(s == "")
            getline ( cin , s );

            Message msg(s , name , logged->getName() ) ;
            logged->sendMessage( msg ) ;
            receivedMessages.push_back(msg);
            cout << "\nPress any key to go Back: ";
            cin >> Back ;
        }
        else if ( choice == 2 )
        {
            friends[numOfFriends++] = logged;
            logged->addFriend(caller) ;
            cout << "\nPress any key to go Back: ";
            cin >> Back ;
        }
        else return ;

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
void User::viewFriends( User *logged )
{
    int number ;
    string chois ;
    cout << "Friends \n";
    for(int i=0 ; i<numOfFriends ; i++)
    {
        cout << i+1 << ". " << friends[i]->getName() << endl;
    }
    cout << endl;
    if( numOfFriends )
    {
        cout << "Do You Want To view Some One Profile ?\n1. Yes  2.Back\n";
        cin >> chois ;
        if( chois == "1" )
        {
            cout << "Enter Number Of Friend To View Profile : " ;
            cin >> number ;
            while( number < 0 || number > numOfFriends )
            {
                cout << "Wrong Choise, Enter Again : ";
                cin >> number ;
            }
            friends[ number-1 ]->viewUser( logged , friends[ number-1 ]) ;
        }
        else return ;
    }
    else
    {
        cout << "No friends to show\n";
    }

    cout << "Press any key to go back: ";
    string x ; cin >> x ;

}
void User::addFriend( User *U )
{
    if( numOfFriends > 50 )
    {
        cout << "You can't add more friends\n";
        return ;
    }
    friends[numOfFriends++] = U ;
    System::merge_sort( friends , numOfFriends ) ;

}
void User::removeFriend( string mail )
{
    int ch = 0 ;
    numOfFriends--;
    for(int i=0 ;i <numOfFriends ;i++)
    {
        if( friends[i]->getEmail() == mail ) ch++;
        if( ch ) friends[i] = friends[i+1];
    }
}

///////////////////

void User::addPost()
{
    if( numOfPosts > 100 )
    {
        cout << "you can't add more posts\n";
        return;
    }
    cout << "1. Status\n2. Poll\n3. Photo/Video\n" << endl;

    addAgain :
    string choice , s = "" , x , t = "";
    cout << "\nEnter choice: " ;
    cin >> choice;

    while( choice != "1" && choice != "2" && choice != "3")
    {
        cout << "Wrong Choise, Enter Again : ";
        cin >> choice ;
    }

    if( choice == "1" )
    {
        Status *st = new Status;
        cout << "\nEnter Status : ";

        while(s == "") getline( cin , s);

        cout << "Add feeling ?   ( 1. Yes  2. No ) : ";
        cin >> x ;

        if( x == "1" )
        {
            cout << "Enter what you feel: ";
            while(t == "") getline( cin , t);
            s = "Feeling " + t + "\n" + s ;
        }

        st->addStatus(s) ;
        putInPosts( st );
    }

    else if( choice == "2" )
    {
        Poll *pol = new Poll ;
        int num ;
        cout << "\nEnter Question: ";
        while(s == "") getline( cin , s ) ;

        cout << "Enter Number Of answers: ";
        cin >> num ;

        string ans;
        cout << "\nEnter The Answers\n";

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
        cout << "\nEnter Link : ";
        while( s == "") getline( cin , s ) ;

        pv->addPhoto( s ) ;
        putInPosts( pv );
    }

    cout << "\n1. Add another post\n2. Back\n";
    char r ; cin >> r;
    if( r == '1' ) goto addAgain ;

}
void User::putInPosts( Post *P )
{
    posts[numOfPosts++] = P;
}
void User::viewPosts( User *logged)
{
    char x ;
    if (numOfPosts == 0)
    {
        cout << "No posts to show!\n\nPress any key to go back: ";
        string x ; cin >> x ;

    }
    for(int i=0 ; i<numOfPosts ; i++)
    {
        cout << "\n";
        posts[i]->view() ;
        Poll *p = dynamic_cast <Poll*> (posts[i]);

        posts[i]->viewPostdetails() ;
        cout << "\n1. Like\n2. dislike\n3. comment\n4. View comments\n5. View likers and dislikers\n";
        if(p)
        {
            cout << "6. Up vote answer \n7. Down vote answer\n8. See other posts\n";
        }
        else cout << "6. See other posts\n";

        cin >> x ;
        while( ( !p && (x < '0'  || x > '6') ) || ( p && ( x < '0' || x > '8' ) ) )
        {
            cout << "Wrong Choice, Enter Again: ";
            cin >> x ;
        }
        if( x == '1' )
        {
            posts[i]->like( logged->getName() );
        }
        else if( x == '2' )
        {
            posts[i]->dislike( logged->getName() );
        }
        else if( x == '3' )
        {
            string s = "" ;
            cout << "Enter Comment: ";
            while( s == "" ) getline( cin , s );
            s = logged->getName() + ": " + s ;
            posts[i]->addcomment(s);
        }
        else if( x == '4' )
        {
            posts[i]->viewComments();
        }
        else if( x == '5' )
        {
            posts[i]->viewLikers();
        }
        else if( p && x == '6' )
        {
            int num ;
            cout << "\nEnter the number of answer: ";
            cin >> num;
            posts[i]->upVote( logged->getName() , num-1 ) ;
        }
        else if( p && x == '7' )
        {
            int num ;
            cout << "\nEnter the number of answer: ";
            cin >> num;
            posts[i]->downVote( logged->getName() , num-1 ) ;
        }

        cout << "\n************************************\n";
        if( i == numOfPosts-1 )
        {
             cout << "No more posts\n\nPress any key to go back: ";
             string x ; cin >> x ;
        }

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
        while( s == "" )
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
    bool x = System::validEmail(mail) ;
    if ( x == 2)
    {
        throw "Email already Exists";
    }
    else if (x == 0)
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

////////////////////

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
User *User::getFriends(int index) {
    return friends[index];
}
vector<Message> User::getReceivedMessages() {
    return receivedMessages;
}
vector<Message> User::getsentMessages() {
    return sentMessages;
}
int User::getNumOfPosts() {
    return numOfPosts;
}
Post *User::getPost(int index) {
    return posts[index];
}
