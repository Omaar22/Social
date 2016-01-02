#include "Photo.h"
#include "DateTime.h"

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
	cout << endl << time << endl;
}

Photo::~Photo() {}

string Photo::getPhoto() {
	return photo;
}
