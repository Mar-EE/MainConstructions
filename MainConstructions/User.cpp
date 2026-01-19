#include "User.h"
using namespace std;

void User::setLogin(string value) {
    _login = value;
}

void User::setPassword(string value) {
    _password = value;
}

void User::setName(string value) {
    _name = value;
}

int User::getId() const {
    return _id;
}

string User::getLogin() const {
    return _login;
}

string User::getPassword() const {
    return _password;
}

string User::getName() const {
    return _name;
}
