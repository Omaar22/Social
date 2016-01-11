#ifndef POLL_H_
#define POLL_H_
<<<<<<< HEAD

#include "Post.h"

=======
#include "Post.h"

using namespace std;

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
class Poll : public Post {
private:
	string Question;
	string time;
	string *answers;
	int *votes;
	string** voters;
	int numberOfAnswers;

public:
<<<<<<< HEAD
=======

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
	Poll();
	void addQuestion (string);
	void addAnswers (string);
	void removeAnswers (int);
<<<<<<< HEAD
	void addthisInt (int, int*&);
	void removethisInt (int, int, int*&);
	void upVote (string, int);
	void downVote (string, int);
	virtual void view ();
	//void edit ();
	virtual ~Poll();
};

#endif //POLL_H_
=======
	virtual void upVote (string, int);
	virtual void downVote (string, int);
	virtual void view ();
	virtual ~Poll();
	int getNumberOfAnswers();
	string getQuestion();
	string getAnswer(int index);

};

#endif /* POLL_H_ */

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
