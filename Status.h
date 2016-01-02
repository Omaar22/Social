#ifndef STATUS_H_
#define STATUS_H_
#include <bits/stdc++.h>
#include "Post.h"
#include "DateTime.h"

using namespace std;

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
	virtual void view ();
	virtual ~Status();
	string getText();
};

#endif /* STATUS_H_ */
