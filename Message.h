<<<<<<< HEAD
=======

>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
#ifndef SOCIAL_MESSAGE_H
#define SOCIAL_MESSAGE_H

#include "DateTime.h"

class Message {
private:
    string text, receiver, sender;
    DateTime dateTime;
    string message;
public:

    Message(string text, string receiver, string sender);

    void view();

    string getMessage();

    string getSender();

    string getReceiver();

    string getText();

<<<<<<< HEAD
    friend ostream &operator<<(ostream &out, const Message &M);

=======
>>>>>>> a90df24badc5dd5e29dc22fc4fa894f659bceb22
};


#endif //SOCIAL_MESSAGE_H


