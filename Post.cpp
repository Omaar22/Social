#include "Post.h"

Post::Post() {
	likeCounter = 0;
	dislikeCounter = 0;
	numberOfComments = 0;
	comments = NULL;
	likers = NULL;
	dislikers = NULL;

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

		addCell (likeCounter, *&likers);

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
		removeCell (dislikeCounter, idx,*&dislikers );
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
		addCell (dislikeCounter, *&dislikers);
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
		removeCell (likeCounter, idx, *&likers);
		--likeCounter;
	}

}

void Post::addcomment(string Comment){

	Comment += '\n';
	Comment += dateandtime.getDate();
	addCell (numberOfComments, *&comments);
	comments [numberOfComments] = Comment;
	++numberOfComments;

}
//no couts!
void Post::deleteComment (int idx){
	cout << numberOfComments << ' ' << idx <<  endl;
	removeCell (numberOfComments, idx, *&comments);
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

