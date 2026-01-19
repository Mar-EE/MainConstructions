#include <iostream>
#include "Chat.h"
#include "Array.h"

void Chat::addNewMessage(Users* users) {
	system("cls");
	char tip = 0;
	string message = "";
	string destName = "";

	cout << "Введите сообщение:" << endl;
	cin >> message;

	cout << "1 - отправить в общий чат" << endl;
	cout << "2 - отправить пользователю" << endl;
	cin >> tip;
	switch (tip) {
	case '1':
		_publicMessages_UserId.add(users->getUserId(users->getCurrentUserIndex()));
		_publicMessages_Text.add(message);
		cout << "Сообщение успешно отправлено!" << endl;
		break;
	case '2':
		cout << "Введите имя получателя" << endl;
		cin >> destName;

		int destIndex = users->findUserByName(destName);
		if (destIndex < 0) {
			cout << "Сообщение не отправлено! Имя получателя не найдено" << endl;
		}
		else {
			_privateMessages_Source.add(users->getUserId(users->getCurrentUserIndex()));
			_privateMessages_Dest.add(users->getUserId(destIndex));
			_privateMessages_Text.add(message);
			cout << "Сообщение успешно отправлено!" << endl;
		}
		break;
	}
	system("pause");
	system("cls");
}

void Chat::printPublicMessages(Users* users) {
	system("cls");
	if (_publicMessages_Text.getLastIndex() < 1) {
		cout << "Сообщений нет" << endl;
	}
	else {
		for (int i{ 0 }; i < _publicMessages_Text.getLastIndex(); i++) {
			cout << "[" << users->getUserName(users->findUserById(_publicMessages_UserId[i])) << "] писал <" << _publicMessages_Text[i] << ">" << endl;
		}
	}
	system("pause");
	system("cls");
}

void Chat::printPrivateMessages(Users* users) {
	system("cls");
	if (_privateMessages_Text.getLastIndex() < 1) {
		cout << "Сообщений нет" << endl;
	}
	else {
		for (int i{ 0 }; i < _privateMessages_Text.getLastIndex(); i++) {

			if (users->getUserId(users->getCurrentUserIndex()) == _privateMessages_Source[i]) {
				cout << "Вы писали [" << users->getUserName(users->findUserById(_privateMessages_Dest[i])) << "] <" << _privateMessages_Text[i] << ">" << endl;
			}
			if (users->getUserId(users->getCurrentUserIndex()) == _privateMessages_Dest[i]) {
				cout << "[" << users->getUserName(users->findUserById(_privateMessages_Source[i])) << "] писал Вам <" << _privateMessages_Text[i] << ">" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}