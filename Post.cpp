#include "Post.h"

Post::Post() {
	likeCounter = 0;
	dislikeCounter = 0;
	numberOfComments = 0;
	comments = NULL;
	likers = NULL;
	dislikers = NULL;

}

void Post:: addthisString (int size, string *&p){

	string *tmp = new string [size+1];

	for (int i = 0; i < size; i++)
		tmp [i] = p[i];

	delete [] p;

	p = tmp;

}

void Post:: removethisString (int size, int idx, string *&p){

	string *tmp = new string [size-1];

	int j = 0;
	for (int i = 0; i < size; i++)
		if (i != idx){
			tmp [j] = p[i];
			++j;
		}


	delete [] p;

	p = tmp;

}

void Post::like(string curUser){

	bool exist = 0;
	int idx;
	for (int i = 0; i < likeCounter; i++)
		if (likers[i] == curUser){
			exist = 1;
			break;
		}

	if (!exist){

		addthisString (likeCounter, *&likers);

		likers [likeCounter] = curUser;

		++likeCounter;

	}

	exist = 0;
	for (int i = 0; i < dislikeCounter; i++)
		if (dislikers[i] == curUser){
			idx = i;
			exist = 1;
			break;
		}

	if (exist){
		removethisString (dislikeCounter, idx,*&dislikers );
		--dislikeCounter;
	}


}

void Post::dislike(string curUser){

	bool exist = 0;
	int idx;

	for (int i = 0; i < dislikeCounter; i++)
		if (dislikers[i] == curUser){
			exist = 1;
			break;
		}

	if (!exist){
		addthisString (dislikeCounter, *&dislikers);
		dislikers[dislikeCounter] = curUser;
		++dislikeCounter;
	}

	exist = 0;

	for (int i = 0; i < likeCounter; i++)
		if (likers[i] == curUser){
			exist = 1;
			idx = i;
			break;
		}

	if (exist){
		removethisString (likeCounter, idx, *&likers);
		--likeCounter;
	}

}

void Post::addcomment(string Comment){

	Comment += '\n';
	Comment += dateandtime.getDate();
	addthisString (numberOfComments, *&comments);
	comments [numberOfComments] = Comment;
	++numberOfComments;

}

void Post::deleteComment (int idx){
	cout << numberOfComments << ' ' << idx <<  endl;
	removethisString (numberOfComments, idx, *&comments);
	--numberOfComments;

}

void Post::viewComments(){

	for (int i = 0; i < numberOfComments; i++)
		cout << comments[i] << endl;

}

void Post::viewPostdetails(){
	cout << likeCounter << " Likes "<< ' ' << dislikeCounter << " Dislikes " << ' ' << numberOfComments <<" Comments "<< endl;
}

Post::~Post() {

	delete [] comments;
	delete [] likers;
	delete [] dislikers;


}



/*
 * problems
 *
 * -view must be a pure virtual function and I can't deal with them yet using base class.
 * -remove post should be done in user I think!
 * -edit same as remove
 * -remove and edit should delete current object and add new object
 */
