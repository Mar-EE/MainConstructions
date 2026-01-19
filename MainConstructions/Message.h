#pragma once
#include <iostream>
#include <string>

using namespace std;

class Message
{
public:
    Message(string source, string dest, string text) : _source(source), _dest(dest), _text(text) {}

    string getSource() const;
    string getDest() const;
    string getText() const;

private:
    string _source = "";
    string _dest = "";
    string _text = "";
};
