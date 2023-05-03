#pragma once
#include <nlohmann/json.hpp>
#include <string>


using namespace std;
using json = nlohmann::json;


class User
{
private:
	int id_;
	string name_;
	string last_name_;
	int age_;
public:
	User(int, string, string, int );
	int get_id();
	string get_name();
	string get_last_name();
	int get_age();
	void set_id(int);
	void set_name(string);
	void set_last_name(string);
	void set_age(int);
	json to_json() const;
};

