#include <iostream>
#include <windows.h>
#include "Chat.h"
#include "ChatEditor.h"
#include "Users.h"
#include "UsersEditor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	Chat* chat = new Chat();
	Users* users = new Users();
	
	char tip = 0;
	int o = 0;
	
	cout << "Добро пожаловать в чат!" << endl;
	cout << "Выберите один из вариантов:" << endl;

	while (o == 0)
	{
		cout << "1 - регистрация пользователей" << endl;
		cout << "2 - вход в чат" << endl;
		cout << "q - закрыть программу" << endl;
		cin >> tip;

		if (tip == '1' || tip == '2' || tip == 'q')
		{
			if (tip == 'q')
			{
				o = 1;
			}
			else
			{
				switch (tip)
				{
				case '1':
					system("cls");
					CallUsersEditor(users);
					break;
				case '2':
					system("cls");
					if (users->login()) {
						CallChatEditor(users, chat);
					}
					break;
				}
			}
		}
		else
		{
			system("cls");
			cout << "Введите один из предложенных вариантов" << endl;
		}
	}

	delete users;
	delete chat;

	return 0;
}