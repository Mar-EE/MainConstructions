#pragma once
#include "User.h"

class Users
{
public:
    Users() = default;
    ~Users();

    void addUser(string user_login, string user_password, string user_name);

    int findUserById(int id);
    int findUserByLogin(string login);
    int findUserByName(string name);
    int getUserId(int index);
    string getUserLogin(int index);
    string getUserPassword(int index);
    string getUserName(int index);
    int getFilledUsersCount() const;
    int getEmptyUsersCount() const;

private:
    int _maxUsersCount = 100; 
    int _lastId = 1;
    int _filledUsersCount = 0;
    int _emptyUsersCount = _maxUsersCount;
    User** _users = new User *[_maxUsersCount];
};