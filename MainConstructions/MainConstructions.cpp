#include <iostream>
#include <windows.h>
#include "Array.h"
#include "Chat.h"
#include "Users.h"
#include "UsersEditor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);

	Users* users = new Users();
	Array<int> messagesToAll_UserId(100);
	Array<string> messagesToAll_Text(100);
	Array<int> messagesToSingleUser_Source(100);
	Array<int> messagesToSingleUser_Dest(100);
	Array<string> messagesToSingleUser_Text(100);

	char tip = 0;
	int o = 0;
	
	cout << "Добро пожаловать в чат!" << endl;
	cout << "Новая строка" << endl;
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
					EnterChat(users, &messagesToAll_UserId, &messagesToAll_Text, &messagesToSingleUser_Source, &messagesToSingleUser_Dest, &messagesToSingleUser_Text);
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
	return 0;
}