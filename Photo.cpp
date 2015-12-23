//Maryam El-Sokkary
//12:54 am 25.DEC.2015
#include "Photo.h"

Photo::Photo() {
	photo = "";
	time = "";
}

void Photo:: addPhoto (string photo){
	this->photo = photo;
	time = dateandtime.getDate() + ' ' + dateandtime.getTime();
}

void Photo::view(){
	cout << photo << endl;
	cout << time << endl;
}

Photo::~Photo() {
	// TODO Auto-generated destructor stub
}

