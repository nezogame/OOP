#pragma once
#include "User.h"
#include "Repository.h"
#include "FileWriter.h"
#include <fstream>

using namespace std;

class UserRepository : public Repository
{
private:
	std::string filename_;
	json users_data_;
	FileWriter* file;
public:
	UserRepository(const string& );
	void add_user( User& user) override;
	User* get_by_id(int id) override;
	vector<User> get_older_than(int age) override;
	bool id_exist(int id) override;
	vector<User> get_all_users() override;
	json get_users_data();
};

