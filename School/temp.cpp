#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64_decode(const std::string& input) {
    std::string clean;
    for (char c : input) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            clean += c;
        }
    }
    if (clean.empty()) return {};

    size_t len = clean.length();

    size_t pad_count = 0;
    if (len >= 2 && clean[len - 1] == '=') pad_count++;
    if (len >= 3 && clean[len - 2] == '=') pad_count++;

    std::vector<int> char_to_idx(256, -1);
    for (size_t i = 0; i < base64_chars.length(); ++i) {
        char_to_idx[static_cast<unsigned char>(base64_chars[i])] = static_cast<int>(i);
    }

    std::string decoded;
    decoded.reserve((len * 3) / 4 - pad_count); 

    for (size_t i = 0; i < len; i += 4) {
        int idx0 = char_to_idx[static_cast<unsigned char>(clean[i])];
        int idx1 = char_to_idx[static_cast<unsigned char>(clean[i + 1])];
        int idx2 = char_to_idx[static_cast<unsigned char>(clean[i + 2])];
        int idx3 = char_to_idx[static_cast<unsigned char>(clean[i + 3])];

        if (idx0 == -1 || idx1 == -1 || (i + 2 < len && idx2 == -1) || (i + 3 < len && idx3 == -1)) {
            throw std::invalid_argument("Base64 包含非法字符");
        }

        decoded += static_cast<char>((idx0 << 2) | (idx1 >> 4));
        if (i + 2 < len && clean[i + 2] != '=') {
            decoded += static_cast<char>((idx1 << 4) | (idx2 >> 2));
        }
        if (i + 3 < len && clean[i + 3] != '=') {
            decoded += static_cast<char>((idx2 << 6) | idx3);
        }
    }
    return decoded;
}

int main() {
    std::ifstream file("desc.txt");

    std::string file_content;
    std::string line;
    while (std::getline(file, line)) {
        file_content += line;
    }
    file.close(); 

    std::string str;
    for (int i = 0; i < 10000; ++i) {
        str += std::to_string(i); 
    }
    std::cout << "拼接后的字符串长度：" << str.length() << std::endl;

    try {
        std::string decoded_str = base64_decode(file_content);
        std::cout << "Base64 解码结果：\n" << decoded_str << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "解码失败：" << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "解码失败：未知异常" << std::endl;
        return 1;
    }

    // 4. 最终输出解码结果
    std::cout << "\n最终解码结果：" << std::endl;
    try {
        std::string final_decoded = base64_decode(str);
        std::cout << final_decoded << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "最终解码失败：" << e.what() << std::endl;
    }

    return 0;
}