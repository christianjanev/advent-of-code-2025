#include <iostream>
#include <fstream>
#include <string>

void rotate_dial(short& dial, std::string amount_s)
{
    int amount = std::stoi(amount_s.substr(1));
    int l_zeros = 0;

    if (amount_s.substr(0, 1) == "L") amount *= -1;
    
    dial = ((dial + amount) % 100 + 100) % 100;
}

void rotate_dial_2(short& dial, int& zeros, std::string amount_s)
{
    int amount = std::stoi(amount_s.substr(1));
    int l_zeros = 0;

    if (amount_s.substr(0, 1) == "L") amount *= -1;
    
    if (amount > 0) {
        int first_zero = (100 - dial) % 100;
        if (first_zero == 0) first_zero = 100;
        
        if (amount >= first_zero) {
            l_zeros = 1 + (amount - first_zero) / 100;
        }
    }
    else if (amount < 0) {
        int abs_amount = -amount;
        int first_zero = dial == 0 ? 100 : dial;
        
        if (abs_amount >= first_zero) {
            l_zeros = 1 + (abs_amount - first_zero) / 100;
        }
    }
    
    dial = ((dial + amount) % 100 + 100) % 100;
    
    zeros += l_zeros;
}

int main(int argc, char** argv)
{
    short dial = 50;
    int zeros = 0;

    std::string turn;
    std::ifstream file("turns.txt");
    if (file.is_open())
    {
        while (std::getline(file, turn))
        {
            /* Part 1
                rotate_dial(dial, turn);
                if (dial == 0) zeros++;
            */

            /* Part 2
                rotate_dial_2(dial, zeros, turn);
            */
            std::cout << "Dial: " << dial << ". Zeros: " << zeros << "\n";
        }
    }
}