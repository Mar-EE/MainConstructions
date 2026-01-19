#include "Message.h"

using namespace std;

string Message::getSource() const {
    return _source;
}

string Message::getDest() const {
    return _dest;
}

string Message::getText() const {
    return _text;
}
