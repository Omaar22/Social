//Maryam El-Sokkary
//12:56 am 24.DEC.2015

#ifndef PHOTO_H_
#define PHOTO_H_

#include "Post.h";

class Photo : public Post {
private:
	string photo;
	string time;
public:
	Photo();
	void addPhoto (string);
	virtual void view ();
	virtual ~Photo();
};

#endif /* PHOTO_H_ */
