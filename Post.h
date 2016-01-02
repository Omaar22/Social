#include <bits/stdc++.h>
#include "User.h"
#include  "DateTime.h"
using namespace std;

#ifndef POST_H
#define POST_H


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

