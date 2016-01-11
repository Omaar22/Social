#include "Status.h"

Status::Status() {

	choice = 0;
	text = "";

}

Status::Status(string text, int choice){

	this-> text = text;
	this->choice = choice;

}

void Status::viewFeelings(){

	for (int i = 0; i < size; i++)
		cout << feelings [i] << endl;

}

void Status::addFeeling (int idx){
	feeling += "Feeling " ;
	feeling += feelings [idx];
}

void Status::addStatus(string text){
	this->text = text;
	time = dateandtime.getDate();
	time += ' ' ;
	time += dateandtime.getTime();
}

void Status::view (){
	if (text.size())
		cout << text << endl;
	if (feeling.size())
		cout << feeling << endl;
<<<<<<< HEAD
	cout << time << endl;
=======
	cout << endl <<time << endl;
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
}

Status::~Status() {
	// TODO Auto-generated destructor stub
}

<<<<<<< HEAD
=======
string Status::getText() {
	return text;
}
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
