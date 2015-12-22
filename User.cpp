//
// Created by Omar Mohamed on 20/12/2015.
//

#include "User.h"

void User::receiveMessage(Message message) {
    receivedMessages.push_back(message);
}

string User::getGender() {
    return gender;
}

void User::setGender(string gender) {
    this->gender = gender;
}

DateTime User::getBirthDate() {
    return birthDate;
}

void User::setBirthDate(DateTime birthDate) {
    this->birthDate = birthDate;
}

string User::getEmail() {
    return email;
}

void User::setEmail(string email) {
    this->email = email;
}

string User::getPassword() {
    return password;
}

void User::setPassword(string password) {
    this->password = password;
}

string User::getName() {
    return name;
}

void User::setName(string name) {
    this->name = name;
}

void User::sendMessage(string text) {
    cout << "Fuck";
}
