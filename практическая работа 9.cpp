#include <iostream>
#include <fstream>
#include <unordered_set>
#include <cctype>

int main() {
    std::unordered_set<char> forbidden = {'u','s','e','r','a','g','m','n','t'};
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    char c;
    while (in.get(c)) {
        if (forbidden.find(std::tolower(static_cast<unsigned char>(c))) == forbidden.end()) {
            out.put(c);
        }
    }
    in.close();
    out.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() {
    const std::string forbidden = "useragreement";
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    char c;
    while (in.get(c)) {
        char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (forbidden.find(lower) == std::string::npos) {
            out.put(c);
        }
    }
    in.close();
    out.close();
    return 0;
}



#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in1("input1.txt");
    std::ifstream in2("input2.txt");
    std::string X, Y;
    in1 >> X;
    in2 >> Y;
    in1.close();
    in2.close();

    if (X.find(Y) != std::string::npos) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}




#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string s;
    std::getline(in, s);
    in.close();

    long long num = 0;
    bool hasNum = false;

    for (char c : s) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            num = num * 10 + (c - '0');
            hasNum = true;
        } else {
            if (hasNum) {
                std::string bin;
                if (num == 0) bin = "0";
                else {
                    while (num > 0) {
                        bin.push_back('0' + (num % 2));
                        num /= 2;
                    }
                    std::reverse(bin.begin(), bin.end());
                }
                out << bin;
                hasNum = false;
                num = 0;
            }
            out.put(c);
        }
    }
    if (hasNum) {
        std::string bin;
        if (num == 0) bin = "0";
        else {
            while (num > 0) {
                bin.push_back('0' + (num % 2));
                num /= 2;
            }
            std::reverse(bin.begin(), bin.end());
        }
        out << bin;
    }
    out.close();
    return 0;
}
