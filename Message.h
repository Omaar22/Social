//
// Created by Omar Mohamed on 19/12/2015.
//

#ifndef SOCIAL_MESSAGE_H
#define SOCIAL_MESSAGE_H

#include <string>
#include <iostream>

using namespace std;



class Message {
private:
    string text, receiver, sender;
    // DateTime
public:
    void view();

    Message(string text, string receiver, string sender);

    string getSender();

    string getReceiver();

    string getText();

};


#endif //SOCIAL_MESSAGE_H


