#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    User(int id, string login, string password, string name) : _id(id), _login(login), _password(password), _name(name) {}

    void setLogin(string value);
    void setPassword(string value); 
    void setName(string value);
    int getId() const;
    string getLogin() const;
    string getPassword() const; 
    string getName() const;

private:
    int _id = 1;
    string _login = "";
    string _password = "";
    string _name = "";
};