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
	virtual void upVote (string, int);
	virtual void downVote (string, int);
	virtual void view ();
	virtual ~Poll();
	int getNumberOfAnswers();
	string getQuestion();
	string getAnswer(int index);

};

#endif /* POLL_H_ */

