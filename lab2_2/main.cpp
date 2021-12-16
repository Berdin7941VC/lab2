#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string input;
    std::string str1, str2, str3;
    std::string tempString;
    int num = 1;
    bool separateFlag = false;

    std::ifstream ifstream;
    ifstream.open("input.txt", std::ifstream::in);
    if(!ifstream.is_open()){
        throw std::invalid_argument("Can't reach file \"input.txt\"");
    }

    std::getline(ifstream, input);

    for(int i=0;i<input.length();i++){
        if(i == input.length()-1){
            tempString.push_back(input[i]);
            str3 = tempString;
            break;
        }
        if(!separateFlag){
            if(input[i] == '.' || input[i] == '?' || input[i] == '!'){
                tempString.push_back(input[i]);
                separateFlag = true;
                continue;
            }
            else{
                tempString.push_back(input[i]);
                continue;
            }
        }

        if(separateFlag){
            if(input[i] == '.' || input[i] == '?' || input[i] == '!'){
                tempString.push_back(input[i]);
                continue;
            }
            else if(input[i] == ' ')
                continue;
            else{
                if(num == 1)
                    str1 = tempString;
                else if(num == 2)
                    str2 = tempString;
                tempString.clear();
                tempString.push_back(input[i]);
                separateFlag = false;
                num++;
            }
        }
    }

    std::cout << "1 sentence: " << str3 << "\n";
    std::cout << "2 sentence: " << str2 << "\n";
    std::cout << "3 sentence: " << str1 << "\n";

    return 0;
}
