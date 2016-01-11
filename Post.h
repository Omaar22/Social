<<<<<<< HEAD
#ifndef POST_H_
#define POST_H_

#include "DateTime.h"
=======
#include <bits/stdc++.h>
#include "User.h"
#include  "DateTime.h"
using namespace std;

#ifndef POST_H
#define POST_H

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22

class Post {

protected:
<<<<<<< HEAD
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
	void addthisString (int, string*&);
	void removethisString (int,int, string*&);
	void edit (); //not sure yet!
	virtual void view () = 0;
	virtual ~Post();
};

#endif //POST_H_
=======
    int likeCounter;
    int dislikeCounter;
    int numberOfComments;
    string *comments;
    string *likers;
    string *dislikers;
    DateTime dateandtime;


public:
    Post();
    void like(string);
    void dislike(string);
    void viewComments();
    void viewPostdetails();
    void addcomment(string);
    void addcomment(string, string Date);
    void deleteComment(int);
    void viewLikers();
    virtual void upVote(string, int);
    virtual void downVote(string, int);
    virtual void view() = 0;
    virtual ~Post();

    int getLikeCounter();
    int getDislikeCounter();
    int getNumberOfComments();
    string getComment(int index);

    void setLikeCount(int likeCount);
    void setDislikeCount(int dislikeCount);
};


#endif /* POST_H_ */

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
