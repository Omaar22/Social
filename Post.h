#include <bits/stdc++.h>
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
	void edit ();
	void viewComments ();
	void viewPostdetails();
	void remove ();
	void addcomment (string);
	void deleteComment(int);
	void addthis (int, string*&);
	void removethis (int,int, string*&);
	virtual ~Post();
};

#endif /* POST_H_ */
