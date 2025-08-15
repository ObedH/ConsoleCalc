#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

namespace StringUtils {
    inline std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t pos = 0;
        std::string token;
        std::string remainingS = s;
        while ((pos = remainingS.find(delimiter)) != std::string::npos) {
            token = remainingS.substr(0, pos);
            tokens.push_back(token);
            remainingS.erase(0, pos + delimiter.length());
        }
        tokens.push_back(remainingS);

        return tokens;
    }
    inline int toDouble(const std::string& s) {
        try {
            std::cout << "double: " + std::to_string(std::stod(s)) + "\n";
            return std::stod(s);
        }
        catch (const std::invalid_argument& e) {
            return NAN;
        }
    }
    inline std::string toString(const double& d) {
        std::cout << "sum: " << d << "\n";
        if (d == std::round(d)) {
            return std::to_string((int)std::round(d));
        }
        else {
            return std::to_string(d);
        }
    }
}