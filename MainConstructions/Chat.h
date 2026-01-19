#pragma once
#include "Array.h"
#include "Users.h"

void EnterChat(Users* users, 
	Array<int>* messagesToAll_UserId, 
	Array<string>* messagesToAll_Text, 
	Array<int>* messagesToSingleUser_Source, 
	Array<int>* messagesToSingleUser_Dest, 
	Array<string>* messagesToSingleUser_Text);