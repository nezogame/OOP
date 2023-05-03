#include "UserRepository.h"

json UserRepository::get_users_data() {
    return users_data_;
}

UserRepository::UserRepository(const std::string& filename) {
    filename_ = filename;
    file = new FileWriter(filename);
    ifstream input_file(filename_) ;
    if (input_file.is_open()) {
        if (input_file.peek() != std::ifstream::traits_type::eof()) {
            input_file >> users_data_;
        }
    }

}

User* UserRepository::UserRepository::get_by_id(int id) {
    for (auto& user_data : users_data_) {
        if (user_data["id"] == id) {
            string name = user_data["name"];
            string last_name = user_data["last_name"];
            int age = user_data["age"];
            User* user = new User(id,name, last_name, age);
            return user;
        }
    }
    return nullptr;
}

vector<User> UserRepository::get_older_than(int age) {
    std::vector<User> older_users;
    for (const auto& user_data : users_data_) {
        if (user_data["age"] > age) {
            int id = user_data["id"];
            string name = user_data["name"];
            string last_name = user_data["last_name"];
            int age = user_data["age"];
            older_users.push_back(User(id, name, last_name, age));
        }
    }
    return older_users;
}

void UserRepository::add_user( User& user)  {
    if (id_exist(user.get_id())) {
        cout << "User with id " << user.get_id()<<" alredy exis!\n";
        return;
    }
    json user_data = {
        user.to_json()
    };
    users_data_.push_back(user_data);
    file->write(users_data_);
}

bool UserRepository::id_exist(int id) {
    for (const auto& user_data : users_data_) {
        if (user_data["id"] == id) {
            return true;
        }
    }
    return false;
}
vector<User> UserRepository::get_all_users() {
    std::vector<User> users;
    for (const auto& user_data : users_data_) {
        User user(
            user_data["id"],
            user_data["name"],
            user_data["last_name"],
            user_data["age"]
        );
        users.push_back(user);
    }
    return users;
}