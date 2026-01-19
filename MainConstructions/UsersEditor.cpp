#include <iostream>
#include "UsersEditor.h"

void CallUsersEditor(Users* users) {
    try {

		char tip = 0;
		string user_login;
		string user_password;
		string user_name;

		int o = 0;

		while (o == 0) {
			cout << "1 - регистрация нового пользователя" << endl;
			cout << "2 - просмотр списка пользователей" << endl;
			cout << "q - возврат назад" << endl;
			cin >> tip;

			if (tip == '1' || tip == '2' || tip == 'q') {
				if (tip == 'q')	{
					o = 1;
					system("cls");
				}
				else {
					switch (tip) {
					case '1':
						if (users->getEmptyUsersCount() > 0) {
							system("cls");
							cout << "Введите имя:" << endl;
							cin >> user_name;
							if (users->findUserByName(user_name) < 0) {
								cout << "Введите логин:" << endl;
								cin >> user_login;
								if (users->findUserByLogin(user_login) < 0) {
									cout << "Введите пароль:" << endl;
									cin >> user_password;
									users->addUser(user_login, user_password, user_name);
									cout << "Пользователь добавлен в чат!" << endl;
									system("pause");
									system("cls");
								}
								else {
									cout << "Пользователь с таким логином уже есть!" << endl;
									system("pause");
									system("cls");
								}
							}
							else {
								cout << "Пользователь с таким именем уже есть!" << endl;
								system("pause");
								system("cls");
							}
						}
						else {
							cout << "Извините, добавить пользователя невозможно. Чат переполнен" << endl;
							system("pause");
							system("cls");
						}
						break;
					case '2':
						system("cls");
						cout << "Количество зарегистированных пользователей: " << users->getFilledUsersCount() << endl << endl;
						for (int i = 0; i < users->getFilledUsersCount(); i++) {
							cout << i + 1 << ". " << users->getUserName(i) << " | ID = " << users->getUserId(i) << endl;
						}
						cout << endl;
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
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}