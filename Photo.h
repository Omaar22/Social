
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
	string getPhoto();
};

#endif /* PHOTO_H_ */
