#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include "json/json.h"

using namespace std;

void ParseJSON(const std::string filename, Json::Value & json_object){
    // Open
    std::ifstream file(filename);
    if (!file.is_open()){
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }

    // Parse
    Json::CharReaderBuilder builder;
    Json::Value val;
    std::string err;
    bool is_parsing = Json::parseFromStream(builder, file, &val, &err);
    file.close();

    // Error
    if (!is_parsing) {
        std::cerr << "Failed to parse JSON: " << err << std::endl;
        return;
    }

    json_object = val;
}

std::unique_ptr<std::string> CheckTarget(const Json::Value & json_object, std::string & target_key){
    if (json_object.isMember(target_key))
    {
        std::unique_ptr<std::string> vecPtr(new std::string);
        *vecPtr = json_object[target_key].asString();

        return  vecPtr;
    }
    else
        return nullptr;
}


void CompleteList(const Json::Value & json_object,  std::list<std::string> & empty_list){

    // Json::Value, keys are always stored in ascending order
    // All values of string type are inserted into the input list container in descending order of their keys.
    for (auto it = json_object.begin(); it != json_object.end(); ++it)
    {
        if (it->isString()){
            empty_list.push_front((*it).asString());
        }
    }  

    if (empty_list.empty()) {
        empty_list.push_front("NO_STRING");
    }
}

void SumTwoMembers(std::string &key1, std::string &key2, const std::string & out_filename, Json::Value & json_object){

    // Key names 1 and 2 are among the members in the input JSON file.
    if (json_object.isMember(key1) && json_object.isMember(key2)) {
        // Their values are assumed to be integer arrays.
        if (json_object[key1].isArray() && json_object[key2].isArray()) {
            // When the two integer arrays to be summed have different lengths or are both empty, the new member is not added.
            if ((json_object[key1].size() == json_object[key2].size())
            && (json_object[key1].size() > 0)
            && (json_object[key2].size() > 0))
            {
                Json::Value sum_array(Json::arrayValue);

                for (unsigned int i = 0; i < json_object[key1].size(); i++)
                {
                    sum_array.append(
                        json_object[key1][i].asInt() + json_object[key2][i].asInt()
                    );
                }

                json_object["SumOf" + key1 + "And" + key2] = sum_array;
            }
        }
    }

    std::ofstream file(out_filename);
    if (file.is_open()) {
        file << json_object;
        file.close();
    } 
    else {
        std::cerr << "Failed to open file: " << out_filename << std::endl;
    }
}