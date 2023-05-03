// 5Lab4SemC++(OOP)(SecondPart).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileWriter.h"
#include "UserRepository.h"
#include "User.h"
#include "User.h"

bool interface(UserRepository* repo) {
    int action, id, age;
    string name, last_name;
    cout << "Chose action:\n";
    cout << "1) Add user\n";
    cout << "2) Find user by id\n";
    cout << "3) Users older then\n";
    cout << "4) Print all users\n";
    cout << "0) Exit out\n";
    cin >> action;
    if (action == 1) {
        cout << "\nEnter id: ";
        cin>> id;
        cout << "\nEnter name: ";
        cin >> name;
        cout << "\nEnter last name: ";
        cin >> last_name;
        cout << "\nEnter age: "; 
        cin >> age;
        User user = User(id, name, last_name, age);
        repo->add_user(user);
    }
    else if (action == 2) {
        cout << "\nEnter id: ";
        cin >> id;
        User* user = repo->get_by_id(id);
        if (user != nullptr) {
            cout << "User with ID " << id<<": "<< user->get_name() << " " << user->get_last_name() << " " << user->get_age() << endl;
        }
        else {
            cout << "No user with ID "<<id<<"is exist\n";
        }
    }
    else if (action == 3) {
        cout << "\nEnter age: ";
        cin >> age;
        vector<User> older_users = repo->get_older_than(age);
        if (older_users.empty()) {
            cout<<"No user older than " << age << " is exist\n";
        }
        else {
            cout << "Users older than " << age << ": \n";
            for (auto& user : older_users) {
                cout <<"id: " << user.get_id() << " name: " << user.get_name() 
                    << " last_name: "<< user.get_last_name() << " age: " << user.get_age() << endl;
            }
        }
    }
    else if (action == 4) {
        vector<User> all_users = repo->get_all_users();

        for (auto& user : all_users) {
            cout << "id: " << user.get_id() << " name: " << user.get_name()
                << " last_name: " << user.get_last_name() << " age: " << user.get_age() << endl;
        }
    }
    else if (action == 0) {
        return false;
    }
    else {
        cout << "Wrong action!\n";
    }
    return true;
}

int main()
{
    UserRepository* repo = new UserRepository("Users.json");
    bool res = true;
    while (res) {
        res = interface(repo);
    }
}

