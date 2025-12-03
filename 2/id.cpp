#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void check_range(std::string range, std::vector<long>& invalid_ids)
{
    std::string str_first_num = range.substr(0, range.find_first_of("-"));
    std::string str_second_num = range.substr(range.find_first_of("-") + 1);

    long first_num = std::stol(str_first_num);
    long second_num = std::stol(str_second_num);

    for (long i = first_num; i <= second_num; i++)
    {
        std::string num_as_str = std::to_string(i);

        if (num_as_str.length() % 2 == 0)
        {
            std::string first_half = num_as_str.substr(0, num_as_str.length() / 2);
            std::string second_half = num_as_str.substr(num_as_str.length() / 2);

            if (first_half == second_half) invalid_ids.push_back(i);
        }
    }
}

void check_range_2(std::string range, std::vector<long>& invalid_ids)
{
    std::string str_first_num = range.substr(0, range.find_first_of("-"));
    std::string str_second_num = range.substr(range.find_first_of("-") + 1);

    long first_num = std::stol(str_first_num);
    long second_num = std::stol(str_second_num);

    for (long i = first_num; i <= second_num; i++)
    {
        std::string num_as_str = std::to_string(i);

        std::vector<int> divisors;
        for (int j = 1; j < num_as_str.length(); j++)
        {
            if (num_as_str.length() % j == 0) divisors.push_back(j);
        }
        
        for (int divisor : divisors)
        {
            int repeat_times = num_as_str.length() / divisor;

            std::string comparison;

            short already_checked = 0;

            for (int k = 0; k < repeat_times; k++)
            {
                comparison += num_as_str.substr(0, divisor);
            }

            if (comparison == num_as_str)
            {
                invalid_ids.push_back(i);
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<long> invalid_ids;

    std::ifstream ids("ids.txt");
    std::string ids_str;

    if (ids.is_open()) std::getline(ids, ids_str);

    ids.close();

    while (ids_str.find(",") != -1)
    {
        // Part 1
        // check_range(ids_str.substr(0, ids_str.find_first_of(",")), invalid_ids);

        // Part 2
        // check_range_2(ids_str.substr(0, ids_str.find_first_of(",")), invalid_ids);
        ids_str = ids_str.substr(ids_str.find_first_of(",") + 1);
    }

    if (!ids_str.empty()) check_range_2(ids_str, invalid_ids);

    long long sum = 0;

    for (long i : invalid_ids)
    {
        sum += i;
    }

    std::cout << sum << "\n";
}