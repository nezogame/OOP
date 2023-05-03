#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class FileWriter
{
private:
	string filename_;
public:
    FileWriter(std::string filename); 

    void write(const json& j) {
        std::ofstream file(filename_);
        if (file.is_open()) {
            file << j.dump(4) << std::endl;
            file.close();
        }
        else {
            std::cerr << "Failed to open file " << filename_ << std::endl;
        }
    }
};

