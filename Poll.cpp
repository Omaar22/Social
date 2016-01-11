#include "Poll.h"
<<<<<<< HEAD
=======
#include "Template.h"
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22

Poll::Poll() {

	answers = NULL;
	votes = NULL;
	numberOfAnswers= 0;
	voters = NULL;

}

void Poll::addQuestion(string Question){
	this->Question = Question;
	time = dateandtime.getDate();
	time += ' ';
	time += dateandtime.getTime();
}

<<<<<<< HEAD
void Poll:: addthisInt (int size, int *&p){

	int *tmp = new int [size+1];

	for (int i = 0; i < size; i++)
		tmp [i] = p[i];

	delete [] p;

	p = tmp;

}

void Poll:: removethisInt (int size, int idx, int *&p){

	int *tmp = new int [size-1];

	int j = 0;
	for (int i = 0; i < size; i++)
		if (i != idx){
			tmp [j] = p[i];
			++j;
		}


	delete [] p;

	p = tmp;


}

void Poll::addAnswers(string Answer){

	addthisString(numberOfAnswers, *&answers);
	addthisInt (numberOfAnswers, *&votes);
=======


void Poll::addAnswers(string Answer){

	add(numberOfAnswers, *&answers);
	add (numberOfAnswers, *&votes);
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
	votes[numberOfAnswers] = 0;
	answers[numberOfAnswers] = Answer;
	++numberOfAnswers;
}

void Poll::upVote(string curUser, int idx){

	++votes[idx];

}

void Poll::downVote(string curUser, int idx){

	--votes[idx];

}

void Poll::removeAnswers(int idx){
<<<<<<< HEAD
	removethisString (numberOfAnswers, idx, *&answers);

	removethisInt (numberOfAnswers, idx, *&votes);
=======
	remove (numberOfAnswers, idx, *&answers);

	remove(numberOfAnswers, idx, *&votes);
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
	--numberOfAnswers;

}

void Poll::view(){

	cout << Question << endl;

	for (int i = 0; i < numberOfAnswers; i++ )
<<<<<<< HEAD
		cout << answers[i] << ' '<< votes [i] << endl;
	cout << endl;
	cout << time;
=======
		cout << i+1 << ". " << answers[i] << ' '<< votes [i] << endl;
	cout << endl << time << endl;
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
}

Poll::~Poll() {

	delete [] answers;
	delete [] votes;
	delete [] voters;

}

/*
 * problems
 *
 * user might up vote and down vote many times
 * solution:
 * 2d dynamic array
 * each row represent answer number
 * each col represent the user who up voted
 *
 * note: user can't down vote an answer if he hasn't up voted it
 */
<<<<<<< HEAD
=======
int Poll::getNumberOfAnswers() {
	return numberOfAnswers;
}
string Poll::getQuestion() {
	return Question;
}
string Poll::getAnswer(int index) {
	return answers[index];
}
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
