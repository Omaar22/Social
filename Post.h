//updated 31 DEC 2015
//Maryam El-Sokkary

#include <iostream>
#include <cstring>
#include "DateTime.h"
#include "User.h"
using namespace std;


#ifndef POST_H_
#define POST_H_

class Post {

protected:
int likeCounter;
int dislikeCounter;
int numberOfComments;
string *comments;
string *likers;
string *dislikers;
DateTime dateandtime;


public:
	Post();
	void like (string);
	void dislike (string);
	void viewComments ();
	void viewPostdetails();
	void addcomment (string);
	void deleteComment(int);
	virtual void view () = 0;
	virtual ~Post();
};

#endif /* POST_H_ */
