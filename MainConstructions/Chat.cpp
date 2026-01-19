#include <iostream>
#include "Chat.h"
#include "Array.h"

void EnterChat(Users* users, 
	Array<int> *messagesToAll_UserId, 
	Array<string> *messagesToAll_Text, 
	Array<int> *messagesToSingleUser_Source, 
	Array<int> *messagesToSingleUser_Dest, 
	Array<string> *messagesToSingleUser_Text)
{
	int currentUserIndex;
	string currentUserLogin;
	string currentUserPassword;
	string currentUserName;

	cout << "Введите логин:" << endl;
	cin >> currentUserLogin;
	currentUserIndex = users->findUserByLogin(currentUserLogin);
	if (currentUserIndex < 0) {
		cout << "Пользователь с таким логином не зарегистрирован!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Введите пароль:" << endl;
		cin >> currentUserPassword;
		if (users->getUserPassword(currentUserIndex) != currentUserPassword) {
			cout << "Неверный пароль!" << endl;
			system("pause");
			system("cls");
		}
		else {
			system("cls");
			char tip = 0;
			int o = 0;

			currentUserName = users->getUserName(currentUserIndex);
			cout << currentUserName << ", добро пожаловать в чат!" << endl;

			while (o == 0) {
				cout << "1 - просмотр сообщений общего чата" << endl;
				cout << "2 - просмотр сообщений личного чата" << endl;
				cout << "3 - отправка сообщения" << endl;
				cout << "q - возврат назад" << endl;
				cin >> tip;

				if (tip == '1' || tip == '2' || tip == '3' || tip == 'q') {
					if (tip == 'q') {
						o = 1;
						system("cls");
					}
					else {
						switch (tip) {
						case '1':
							system("cls");
							if (messagesToAll_Text->getLastIndex() < 1) {
								cout << "Сообщений нет" << endl;
							}
							else {
								for (int i{ 0 }; i < messagesToAll_Text->getLastIndex(); i++) {
									cout << "[" << users->getUserName(users->findUserById(messagesToAll_UserId->getValue(i))) << "] писал <" << messagesToAll_Text->getValue(i) << ">" << endl;
								}
							}
							system("pause");
							system("cls");
							break;
						case '2':
							system("cls");
							if (messagesToSingleUser_Text->getLastIndex() < 1) {
								cout << "Сообщений нет" << endl;
							}
							else {
								for (int i{ 0 }; i < messagesToSingleUser_Text->getLastIndex(); i++) {

									int userSourceId = messagesToSingleUser_Source->getValue(i);
									int userDestId = messagesToSingleUser_Dest->getValue(i);
									if (userSourceId == users->getUserId(currentUserIndex)) {
										cout << "Вы писали [" << users->getUserName(users->findUserById(userDestId)) << "] <" << messagesToSingleUser_Text->getValue(i) << ">" << endl;
									}
									if (userDestId == users->getUserId(currentUserIndex)) {
										cout << "[" << users->getUserName(users->findUserById(userSourceId)) << "] писал Вам <" << messagesToSingleUser_Text->getValue(i) << ">" << endl;
									}
								}
							}
							system("pause");
							system("cls");
							break;
						case '3':
							system("cls");
							string message = "";
							cout << "Введите сообщение:" << endl;
							cin >> message;

							cout << "1 - отправить в общий чат" << endl;
							cout << "2 - отправить пользователю" << endl;
							cin >> tip;
							switch (tip) {
								case '1':
									messagesToAll_UserId->add(users->getUserId(currentUserIndex));
									messagesToAll_Text->add(message);
									cout << "Сообщение успешно отправлено!" << endl;
									break;
								case '2':
									string destName = "";
									cout << "Введите имя получателя" << endl;
									cin >> destName;

									int destIndex = users->findUserByName(destName);
									if (destIndex < 0) {
										cout << "Сообщение не отправлено! Имя получателя не найдено" << endl;
									}
									else {
										messagesToSingleUser_Source->add(users->getUserId(currentUserIndex));
										messagesToSingleUser_Dest->add(users->getUserId(destIndex));
										messagesToSingleUser_Text->add(message);
										cout << "Сообщение успешно отправлено!" << endl;
									}
									break;
							}
							system("pause");
							system("cls");
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
	}
}