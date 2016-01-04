#ifndef PHOTO_H
#define PHOTO_H

#include "Post.h"

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

#endif //PHOTO_H
