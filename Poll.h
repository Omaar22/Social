//updated 31 DEC 2015
//Maryam El-Sokkary

#ifndef POLL_H_
#define POLL_H_
#include "Post.h"

using namespace std;

class Poll : public Post {
private:
	string Question;
	string time;
	string *answers;
	int *votes;
	string** voters;
	int numberOfAnswers;

public:
	Poll();
	void addQuestion (string);
	void addAnswers (string);
	void removeAnswers (int);
	void upVote (string, int);
	void downVote (string, int);
	virtual void view ();
	virtual ~Poll();
};

#endif /* POLL_H_ */

