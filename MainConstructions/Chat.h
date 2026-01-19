#pragma once
#include "Array.h"
#include "Users.h"

class Chat
{
public:
	Chat() = default;

	void addNewMessage(Users* users);
	void printPublicMessages(Users* users);
	void printPrivateMessages(Users* users);

private:
	int _maxMessagesCount = 100;
	Array<int> _publicMessages_UserId{ _maxMessagesCount };
	Array<string> _publicMessages_Text{ _maxMessagesCount };
	Array<int> _privateMessages_Source{ _maxMessagesCount };
	Array<int> _privateMessages_Dest{ _maxMessagesCount };
	Array<string> _privateMessages_Text{ _maxMessagesCount };
};