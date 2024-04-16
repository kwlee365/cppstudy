#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

#include "functions.hpp"

using namespace std;

void ParseCSV(const std::string & filename, std::map<int, std::string> & header_cols, map<std::string, vector<std::string>> & data_map){

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    std::string line;
    bool is_first_line = true;
    while (std::getline(file, line)){   

        std::stringstream parser;
        std::string token;
        std::vector<std::string> csv_data;

        parser.str(line);
        
        char exception = '\"';

        while(getline(parser, token, ','))
        {
            // If any element of the data row is empty, ignore the row.
            if(token.front() != exception)
            {
                if(!token.empty() && token.back() != exception)
                {
                    csv_data.push_back(token);
                }
            }
            else
            {
                // If an element is enclosed by double quotes (") in the CSV file,
                // any commas inside the double quotes are not considered as delimiters.
                // When an element is enclosed by double quotes ("), the double quotes should also be kept in data_map.
                std::string token_temp;
                std::string line_temp = line;
                size_t pos = line_temp.find(exception);
                if(pos != std::string::npos)    
                {
                    line_temp.replace(0, pos + 1, "");
                    
                    size_t pos = line_temp.find(exception);
                    if(pos != std::string::npos)    
                    {
                        line_temp.replace(pos, line_temp.size(), "");
                    }

                    token_temp.append("\"");
                    token_temp.append(line_temp);
                    token_temp.append("\"");
                    csv_data.push_back(token_temp);
                }
            }
        }

        if (is_first_line == true)
        {
            int iter = 0;
            for (auto val : csv_data)
            {
                header_cols.insert({iter, val});

                iter++;
            }

            is_first_line = false;
        }
        else
        {
            // If the data row has a different number of elements than the header, ignore the row.
            if(csv_data.size() == header_cols.size())
            {
                int iter = 0;
                for (auto val : csv_data)
                {
                    data_map[header_cols[iter]].push_back(val);
                    iter++;
                }
            }
        }
    }

    // // Check header_cols //
    // std::cout << "header_cols" << std::endl;
    // for (auto it = header_cols.begin(); it != header_cols.end(); ++it)    
    //     std::cout << "keys : " << it->first << ", values: " << it->second << std::endl;
    // std::cout << std::endl;

    // // Check data_map //
    // std::cout << "data_map" << std::endl;
    // for (auto it = data_map.begin(); it != data_map.end(); ++it)    
    // {
    //     std::cout << "keys : " << it->first <<  " , values: ";
    //     for (auto val : it->second)
    //        std::cout << val << " ";
    //     std::cout << std::endl;
    // }

    file.close();   // Close the file
}

// Sum all elements in the column  
int SumColumn(const std::string &column_name, map<std::string, vector<std::string>> &data_map){

    int col_sum = 0;
    std::vector<std::string> target_col;

    if (data_map.find(column_name) != data_map.end())
        target_col = data_map[column_name];

    for (auto it = target_col.begin(); it != target_col.end(); ++it){
        col_sum += std::stoi(*it);
    }    

    return col_sum;
}

double FilterMostFrequentAvg(const std::string &key_col, std::string &value_col, map<std::string, vector<std::string>> &data_map){

    int col_avg = 0;
    int col_sum = 0;
    map<std::string, int> cnt_map;

    // Count the number of key elements
    for (const auto &key : data_map[key_col])
        cnt_map[key]++;

    // Find the key
    std::string max_frequent_key; 
    int max_frequency = 0; 
    for (auto it = cnt_map.begin(); it != cnt_map.end(); ++it)
    {
        if(it->second >= max_frequency)
        {
            max_frequent_key = it->first;
            max_frequency = it->second;
        }
    }

    if (max_frequency == 0)
    {
        return 0;
    }

    // Sum
    int iter = 0;
    for (auto key : data_map[key_col])
    {
        if (key == max_frequent_key)
        {
            col_sum += std::stoi(data_map[value_col].at(iter));
        }
        iter++;
    }

    // Average
    col_avg = col_sum / max_frequency;

    return static_cast<double>(col_avg);
}

void SumTwoColumns(std::string &value_col1, std::string &value_col2, const std::string & out_filename, std::map<int, std::string> & header_cols, map<std::string, vector<std::string>> & data_map){

    std::vector<std::string> col1;
    std::vector<std::string> col2;
    std::vector<double> col_sum;

    // Map search (value_col1)
    if (data_map.find(value_col1) != data_map.end())
        col1 = data_map[value_col1];

    // Map search (value_col2)
    if (data_map.find(value_col2) != data_map.end())
        col2 = data_map[value_col2];

    // Sum
    for (int i = 0; i < col1.size(); i++){
        col_sum.push_back(
            std::stoi(col1.at(i)) + 
            std::stoi(col2.at(i)));
    }

    // Output
    std::ofstream file(out_filename);

    // Header
    for (auto it = header_cols.begin(); it != header_cols.end(); ++it)    
        file << it->second << ",";
    file << "SumOf" << value_col1 << "And" << value_col2 << "\n";

    for (int i = 0; i < col1.size(); i++)
    {
        for (auto it = header_cols.begin(); it != header_cols.end(); ++it)
        {
            file << data_map[it->second].at(i) << ",";
        }   
        file << col_sum.at(i) << "\n";
    }

    file.close();
}