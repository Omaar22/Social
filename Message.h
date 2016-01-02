
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

};


#endif //SOCIAL_MESSAGE_H


