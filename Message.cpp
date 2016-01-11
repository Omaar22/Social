#include "Message.h"

void Message::view() {
    cout << message;
}

Message::Message(string text, string receiver, string sender) {
    this->text = text;
    this->receiver = receiver;
    this->sender = sender;

<<<<<<< HEAD
    message = "\nFrom " + sender + "\n" + text + "\n" + dateTime.getDate() + " " + dateTime.getTime();
=======
    message = text + "\nFrom " + sender + "\nTo " + receiver + "\nAt " + dateTime.getDate() + " " + dateTime.getTime();
>>>>>>> Project
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

ostream &operator<<(ostream &out, const Message &M) {
    out << M.message;
    return out;
}
