//
// Created by Omar Mohamed on 19/12/2015.
//

#include "Message.h"

void Message::view() {
    cout << message;
}

Message::Message(string text, string receiver, string sender) {
    this->text = text;
    this->receiver = receiver;
    this->sender = sender;

    message = text + "\nFrom " + sender + "\nTo " + receiver + "\nAt " + dateTime.getDate() + " " + dateTime.getTime();
}


string Message::getSender() {
    return sender;
}

string Message::getReceiver() {
    return receiver;
}

string Message::getText() {
    return text;
}

string Message::getMessage() {
    return message;
}
