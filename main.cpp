#include <bits/stdc++.h>
#include "Post.h"
#include "Status.h"
#include "Poll.h";
#include "Photo.h"
#include "systems.h"
#include "User.h"

using namespace std;


int main() {



	systems sm ;
	    User U1 , U2 , U3 , U4;

	    U1.setName( "Salma" );
	    U2.setName( "Saif" );
	    U3.setName( "Maryam" );
	    U4.setName( "Omar" );


	    U1.setEmail( "salma@gmail.com" );
	    U2.setEmail( "saif@gmail.com" );
	    U3.setEmail( "maryam@gmail.com" );
	    U4.setEmail( "omar@gmail.com" );


	    U1.setPassword( "1234567Aa" );
	    U2.setPassword( "1234567Aa" );
	    U3.setPassword( "1234567Aa" );
	    U4.setPassword( "1234567Aa" );


	    U1.setGender(1);
	    U2.setGender(2);
	    U3.setGender(1);
	    U4.setGender(2);


	    U1.setBirthDate( "12/12/2009" );
	    U2.setBirthDate( "12/12/2009" );
	    U3.setBirthDate( "12/12/2009" );
	    U4.setBirthDate( "12/12/2009" );


	    U1.addFriend( U2 );
	    U1.addFriend( U3 );
	    U1.addFriend( U4 );

	    U2.addFriend( U1 );
	    U2.addFriend( U3 );
	    U2.addFriend( U4 );

	    U3.addFriend( U1 );
	    U3.addFriend( U2 );
	    U3.addFriend( U4 );

	    U4.addFriend( U1 );
	    U4.addFriend( U2 );
	    U4.addFriend( U3 );


	    sm.AddUser(U1);
	    sm.AddUser(U2);
	    sm.AddUser(U3);
	    sm.AddUser(U4);


	    cout << "\t\tSign In\n\n";
	    sm.signIn() ;
	   // cout << sm.loggedInUser.getNumOfFriends() << endl;
	 //   sm.signIn();
	   // cout << sm.loggedInUser.getNumOfFriends() << endl;
	    //sm.signIn();
	    ///cout << sm.loggedInUser.getNumOfFriends() << endl;


	    cout << "\n\t\t Welcome " << sm.loggedInUser.getName() << endl;

	    sm.loggedInUser.viewInfo();
	    sm.loggedInUser.viewFriends();

	    //cout << "Main checkpointt 9" << endl;

	    cout << endl << "Now try to add post:\n";
	    for(int i=0 ; i<3 ; i++)
	    {
	        sm.loggedInUser.addPost() ;
	    }


	    cout << "\nYour Posts: \n\n";
	    sm.loggedInUser.viewPosts();

	    cout << "\n\nYour Messages:\n";
	   // sm.loggedInUser.viewSentMessages();
	    cout << endl ;


}

/*
 * view posts endlines
 * why can't I view number of friends?
 *
 */
