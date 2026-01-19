#pragma once
#include "User.h"

class Users
{
public:
    Users() = default;
    ~Users();

    void addUser(string user_login, string user_password, string user_name);
    void setCurrentUserIndex(int index);

    bool login();

    int findUserById(int id);
    int findUserByLogin(string login);
    int findUserByName(string name);

    int getUserId(int index);
    string getUserLogin(int index);
    string getUserPassword(int index);
    string getUserName(int index);
    
    int getCurrentUserIndex() const;
    int getFilledUsersCount() const;
    int getEmptyUsersCount() const;

private:
    const int _maxUsersCount = 100; 
    int _currentUserIndex = -1;
    int _lastId = 1;
    int _filledUsersCount = 0;
    int _emptyUsersCount = _maxUsersCount;
    User** _users = new User *[_maxUsersCount];
};