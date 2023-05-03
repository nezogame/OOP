#pragma once
#include "User.h"


class Repository
{
public:
    virtual vector<User> get_older_than(int age) = 0;
    virtual User* get_by_id(int id) = 0;
    virtual void add_user(User& user) = 0;
    virtual vector<User> get_all_users() = 0;
    virtual bool id_exist(int id) = 0;
};

