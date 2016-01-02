#include "Poll.h"
#include "Template.h"

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



void Poll::addAnswers(string Answer){

	add(numberOfAnswers, *&answers);
	add (numberOfAnswers, *&votes);
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
	remove (numberOfAnswers, idx, *&answers);

	remove(numberOfAnswers, idx, *&votes);
	--numberOfAnswers;

}

void Poll::view(){

	cout << Question << endl;

	for (int i = 0; i < numberOfAnswers; i++ )
		cout << i+1 << ". " << answers[i] << ' '<< votes [i] << endl;
	cout << endl << time << endl;
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
int Poll::getNumberOfAnswers() {
	return numberOfAnswers;
}
string Poll::getQuestion() {
	return Question;
}
string Poll::getAnswer(int index) {
	return answers[index];
}
