#include "User.h"

User::User(int id, string name, string last_name, int age) {
	id_ = id;
	name_ = name;
	last_name_ = last_name;
	age_ = age;
}

int User::get_id() {
	return id_;
}

string User::get_name() {
	return name_;
}

string User::get_last_name() {
	return last_name_;
}

int User::get_age() {
	return age_;
}

void User::set_id(int id) {
	id_ = id;
}

void User::set_name(string name) {
	name_ = name;
}

void User::set_last_name(string last_name) {
	last_name_ = last_name;
}

void User::set_age(int age) {
	age_ = age;
}

json User::to_json() const {
	/*json j = {
		{"id", id_},
		{"name",name_},
		{"last_name", last_name_},
		{"age", age_}
	};*/
	json j;
	j["id"] = id_;
	j["name"] = name_;
	j["last_name"] = last_name_;
	j["age"] = age_;
	return j;
}