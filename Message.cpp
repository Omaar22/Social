//
// Created by Omar Mohamed on 19/12/2015.
//

#include "Message.h"

void Message::view() {
    cout << "From " << sender << "\nTo " << receiver << "\n" << text;
}

Message::Message(string text, string receiver, string sender) {
    this->text = text;
    this->receiver = receiver;
    this->sender = sender;

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
