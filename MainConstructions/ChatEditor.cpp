#include <iostream>
#include "ChatEditor.h"

void CallChatEditor(Users* users, Chat* chat) {
	try {

		char tip = 0;
		int o = 0;

		while (o == 0) {
			cout << "1 - просмотр сообщений общего чата" << endl;
			cout << "2 - просмотр сообщений личного чата" << endl;
			cout << "3 - отправка сообщения" << endl;
			cout << "q - выйти из чата" << endl;
			cin >> tip;

			if (tip == '1' || tip == '2' || tip == '3' || tip == 'q') {
				if (tip == 'q') {
					o = 1;
					users->setCurrentUserIndex(-1);
					system("cls");
				}
				else {
					switch (tip) {
					case '1':
						chat->printPublicMessages(users);
						break;
					case '2':
						chat->printPrivateMessages(users);
						break;
					case '3':
						chat->addNewMessage(users);
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
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}