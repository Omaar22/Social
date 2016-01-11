#ifndef STATUS_H_
#define STATUS_H_
<<<<<<< HEAD

#include "Post.h"
=======
#include <bits/stdc++.h>
#include "Post.h"
#include "DateTime.h"

using namespace std;
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22

class Status :public Post {
private:
	string feelings [10] = {"sad", "mad", "happy", "determined"};
	int size = 4;
	int choice;
	string text;
	string feeling;
	string time;

public:
	Status();
	Status (string, int);
	void viewFeelings ();
	void addFeeling (int);
	void addStatus (string);
<<<<<<< HEAD
	//void edit ();
	virtual void view ();
	virtual ~Status();
};

#endif //STATUS_H_
=======
	virtual void view ();
	virtual ~Status();
	string getText();
};

#endif /* STATUS_H_ */
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
