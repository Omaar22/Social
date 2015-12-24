//
// Created by Omar Mohamed on 20/12/2015.
//

#include "User.h"

User::User(){}


/////////////////

void User::editInfo()
{
    int chois , string s ;
    cout << "Press the Number of What You Want To Edit ? " << endl;
    cout << " 1.Name  2.Password  3.Gender  4.Email  5.Date Of Birth  6.Interests" << endl;
    cin >> chois ;

    while( chois <= 0 || chois > 6 )
    {
        cout << "Wrong Choise, TRY AGAIN : " ;
        cin >> chois ;
    }
    if( chois == 1 )
    {
        cout << "Enter The New Name : ";
        cin >> s ;
        setName(s);
    }
    else if( chois == 2 )
    {
        cout << "Enter The New Password : ";
        cin >> s ;
        while ( !checkPass(s) )
        {
            cout << "Password is not strong enough, password size should be 8 characters" << endl;
            cout << "it must contains at least one uppercase, one lowercase, and one number" << endl;
            cout << "TRY AGAIN : ";
            cin >> s ;
        }
        setPassword(s);
    }
    else if( chois == 3 )
    {
        cout << "Enter The New Gender : " << endl << "1. Male  2. Female" << endl;
        cin >> chois ;
        while ( chois != 1 && chois != 2 )
        {
            cout << "Wrong Chois, TRY AGAIN";
            cout << "Enter The New Gender : ";
             cin >> chois ;
        }
        if( chois == 1 ) setGender( "Male" ) ;
        else setGender( "Female" ) ;

    }
    else if( chois == 4 )
    {
        cout << "Enter The New Email : ";
        cin >> s ;
        setEmail(s);
    }
    else if( chois == 5 )
    {
        DateTime newDT ;
        cout << "Enter The New Date : ";
        cin >> newDT ;
        setBirthDate( newDT );
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
    cout << "Name : " << name << endl;
    cout << "Gender : " << gender << endl;
    cout << "Email : " << email << endl;
    cout << "Date Of Birth : " << birthDate << endl;
    cout << "Interests : ";
    for(int i=0 ; i<3 ; i++) cout << interests[i] << " " ;
    cout << endl;

    if(name == loggedInUser.getName())
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

/////////////////

void User::viewFriends()
{
    int number , chois ;
    for(int i=0 ; i<numOfFriends ; i++)
    {
        cout << i+1 << ". " << friends[i].getName() << endl;
    }
    cout << "Do You Want To view Some One Profile ? " << endl << "1. Yes  2.No";
    cin >> chois ;
    if( chois == 1 )
    {
        cout << "Enter Number Of Friend To View Profile :" ;
        cin >> number ;
        while( number < 0 || number > numOfFriends )
        {
            cout << "Wrong Choise, TRY AGAIN : ";
            cin >> number ;
        }
        else
        {
            viewUser( friends[i-1] ) ;
        }
    }
}

void User::addFriend( User U )
{
    numOfFriends++;
    tmpFriends = new User[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends-1 ; i++)
    {
        tmpFriends[i] = friends[i];
    }

    delete[] friends;
    tmpFriends[ numOfFriends ] = U ;

    friends = tmpFriends ;
    U.addFriend(loggedInUser) ;
}

void User::removeFriend( User U )
{
    numOfFriends--;
    tmpFriends = new User[ numOfFriends ] ;

    for(int i=0 ; i<numOfFriends ; i++)
    {
        if( friends[i] != U )
        tmpFriends[i] = friends[i];
    }

    delete[] friends;
    friends = tmpFriends ;
}

//////////////////

User User::findUser( string mail )
{
    User U ;
    U = findFriend( mail ) ;
    if( U.getName() == "NoUser") cout << "Sorry, No Such User Exist ! ";
    else viewUser( U ) ;
}

void User::viewUser( User U)
{
    int choice;
    cout << U.getName() ;

    if( isFriend(U))
    {
        cout << "1. Send Massage  2.View Information  3. View Posts  4. Remove From Friends  5. No Thanks";
        while( choice < 0 && choice > 4)
        {
            cout << "Wrong Choice, TRY AGAIN : ";
            cin >> choice ;
        }
        if( choice == 1 )
        {
            string s ;
            cout << "Enter Massage : ";
            getline ( cin , s );
            sendMessage(s , U) ;
        }
        else if ( choice == 2 )
        {
            U.viewInfo() ;
        }
        else if( choice == 3 )
        {
           U.viewPosts();
        }
        else if( choice == 3 )
        {
           loggedInUser.RemoveFriend(U);
           U.removeFriend(loggedInUser) ;
        }

    }
    else
    {
        cout << "1. Send Massage  2.Add Friend  3. No Thanks";
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
            sendMessage(s , U) ;
        }
        else if ( choice == 2 )
        {
            addFriend(U) ;
        }

    }
}

///////////////////

void User::addPost()
{
    int choice , string s ;
    cout << "1. Status  2. Poll  3. Photo/Video" << endl;
    cout << " Enter choice : " ;
    cin >> chois;

    while( choice < 0 || choice > 3)
    {
        cout << "Wrong Choise, TRY AGAIN : ";
        cin >> choice ;
    }

    if( choice == 1 )
    {
        Status st;
        cout << "Enter Status : ";

        getline( cin , s ) ;
        st.addStatus( s ) ;

        putInPosts( &st );
    }
    else if( choice == 2)
    {
        Poll pol ;
        int num ;
        cout << "Enter Question : ";
        getline( cin , s ) ;
        cout << "Enter Number Of answers : ";
        cin >> num ;

        string ans;
        cout << "Enter The Answers : ";

        pol.addQuestion( s ) ;

        for( int i=0 ; i<num ; i++)
        {
            getline ( cin , ans ) ;
            pol.addAnswer(ans) ;
        }

        putInPosts( &pol );
    }
    else
    {
        PhotoOrVideo pv;
        cout << "Enter Link : ";
        getline( cin , s ) ;

        pv.addPhotoOrVideo( s ) ;

        putInPosts( &pv );
    }
}

void User::putInPosts( Post *P )
{
    numOfPosts++;
    Post **tmpPost = new posts*[ numOfPosts ] ;

    for(int i=0 ; i<numOfPosts-1 ; i++)
    {
        tmpPost[i] = post[i] ;
    }

    delete[] posts ;
    tmpPost[ numOfPosts ] = P ;
    
    for(int i=0 ; i<numOfPosts-1 ; i++)
    {
        posts[i] = tmpPost[i] ;
    }
    
    delete[] tmpPost ;
}

void viewPosts()
{
    for(int i=0 ; i<numOfPosts ; i++)
    {
        cout << posts[i].view() << endl;
    }
}

//////////////////////

void User::receiveMessage(Message message)
{
    receivedMessages.push_back(message);
}
void User::sendMessage(string text)
{
    
}

//////////////////////

DateTime User::getBirthDate()
{
    return birthDate;
}
void User::setBirthDate(DateTime birthDate)
{
    this->birthDate = birthDate;
}

string User::getGender()
{
    return gender;
}
void User::setGender(string gender)
{
    this->gender = gender;
}

string User::getEmail()
{
    return email;
}
void User::setEmail(string email)
{
    this->email = email;
}

string User::getPassword()
{
    return password;
}
void User::setPassword(string password)
{
    this->password = password;
}

string User::getName()
{
    return name;
}
void User::setName(string name)
{
    this->name = name;
}

///////////////////////

User::~User(){}
