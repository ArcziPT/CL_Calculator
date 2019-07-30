//
// Created by ArcziPT on 09.07.2019.
//

#ifndef CL_CALCULATOR_RPN_CONVERTER_H
#define CL_CALCULATOR_RPN_CONVERTER_H

#include <vector>
#include <cstring>
#include <iostream>
#include <memory>
#include <map>

//Token
enum Token_type{
    number,
    func,
    left_p,
    right_p,
    op,
    var
};

struct Token{
    std::string val;
    Token_type type;
};

//RPN
struct RPN{
    std::vector<Token> stack;
};

using RPN_ptr = std::unique_ptr<RPN>;

//RPN converter
class RPN_Converter {
public:
    RPN_ptr convert(const std::string& input);
    void config(const std::map<std::string, int>& precedence, const std::map<std::string, bool>& left_associativity, bool var_mode);

private:
    std::map<std::string, int> precedence;
    std::map<std::string, bool> left_associativity;
    bool var_mode = false;

    std::vector<Token> get_tokens(const std::string& input);
    bool has_greater_precedence(const std::string& op1, const std::string& op2);  //does op1 has greater precedence?
    bool has_equal_precedence(const std::string& op1, const std::string& op2);
};


#endif //CL_CALCULATOR_RPN_CONVERTER_H
