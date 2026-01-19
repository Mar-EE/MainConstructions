#include <iostream>
#include "Users.h"
using namespace std;

class Bad_range : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Индекс выходит за допустимые пределы!";
    }
};

Users::~Users()
{
    for (int i = 0; i < _filledUsersCount; i++) {
        delete _users[i];
    }
    delete[] _users;
}

void Users::addUser(string user_login, string user_password, string user_name) {
    _users[_filledUsersCount] = new User(_lastId, user_login, user_password, user_name);
    _lastId++;
    _filledUsersCount++;
    _emptyUsersCount--;
}

int Users::findUserById(int id) {
    for (int i = 0; i < _filledUsersCount; i++) {
        if (id == _users[i]->getId()) {
            return i;
        }
    }
    return -1;
}

int Users::findUserByLogin(string login) {
    for (int i = 0; i < _filledUsersCount; i++) {
        if (login == _users[i]->getLogin()) {
            return i;
        }
    }
    return -1;
}

int Users::findUserByName(string name) {
    for (int i = 0; i < _filledUsersCount; i++) {
        if (name == _users[i]->getName()) {
            return i;
        }
    }
    return -1;
}

int Users::getUserId(int index) {
    if (index < 0 || index >= _filledUsersCount) {
        throw Bad_range();
    }
    return _users[index]->getId();
}

string Users::getUserLogin(int index) {
    if (index < 0 || index >= _filledUsersCount) {
        throw Bad_range();
    }
    return _users[index]->getLogin();
}

string Users::getUserPassword(int index) {
    if (index < 0 || index >= _filledUsersCount) {
        throw Bad_range();
    }
    return _users[index]->getPassword();
}

string Users::getUserName(int index) {
    if (index < 0 || index >= _filledUsersCount) {
        throw Bad_range();
    }
    return _users[index]->getName();
}

int Users::getFilledUsersCount() const {
    return _filledUsersCount;
}

int Users::getEmptyUsersCount() const {
    return _emptyUsersCount;
}