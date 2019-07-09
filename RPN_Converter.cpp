//
// Created by ArcziPT on 09.07.2019.
//

#include "RPN_Converter.h"
#include <cctype>
#include <sstream>
#include <stack>

RPN_ptr RPN_Converter::convert(const std::string &input) {
    auto rpn = std::make_unique<RPN>();

    std::vector<Token> output_queue;
    std::stack<Token> operator_stack;

    auto tokens = get_tokens(input);
    for(auto& token : tokens){
        switch(token.type){
            case number:
                output_queue.push_back(token);
                break;

            case func:
                operator_stack.push(token);
                break;

            case op:
                if(!operator_stack.empty()){
                    while((operator_stack.top().type == Token_type::func or
                           (operator_stack.top().type == Token_type::op and has_greater_precedence(operator_stack.top().val, token.val)) or
                           (has_equal_precedence(token.val, operator_stack.top().val) and left_associativity[operator_stack.top().val])) and
                          operator_stack.top().type != Token_type::left_p)
                    {
                        output_queue.push_back(operator_stack.top());
                        operator_stack.pop();

                        if(operator_stack.empty())
                            break;
                    }
                }

                operator_stack.push(token);
                break;

            case left_p:
                operator_stack.push(token);
                break;

            case right_p:
                while(operator_stack.top().type != Token_type::left_p){
                    output_queue.push_back(operator_stack.top());
                    operator_stack.pop();
                }
                if(operator_stack.top().type == Token_type::left_p)
                    operator_stack.pop();
                break;
        }
    }

    while(!operator_stack.empty()){
        output_queue.push_back(operator_stack.top());
        operator_stack.pop();
    }

    rpn->stack = output_queue;
    return rpn;
}

std::vector<Token> RPN_Converter::get_tokens(const std::string &input) {
    std::vector<Token> tokens;

    std::stringstream num_stream;
    std::stringstream func_stream;

    //TODO: decimal point (.)
    for(auto it = input.begin(); it != input.end();){
        if(isdigit(*it)){
            while(it != input.end() and isdigit(*it)){
                num_stream << *it;
                it++;
            }

            std::string val;
            num_stream >> val;

            Token token;
            token.val = val;
            token.type = Token_type::number;

            tokens.push_back(token);
            num_stream.clear();

            if(it == input.end())
                break;
        }else if(*it != '(' and *it != ')' and precedence.count(std::string(1, *it)) == 0){
            while(it != input.end() and *it != '(' and *it != ')' and precedence.count(std::string(1, *it)) == 0){
                func_stream << *it;
                it++;
            }

            std::string val;
            func_stream >> val;

            Token token;
            token.val = val;
            token.type = Token_type::func;

            tokens.push_back(token);
            func_stream.clear();

            if(it == input.end())
                break;
        }else{
            Token token;
            token.val = std::string(1, *it);

            if(token.val == "(")
                token.type = Token_type ::left_p;
            else if(token.val == ")")
                token.type = Token_type ::right_p;
            else
                token.type = Token_type::op;

            tokens.push_back(token);
            it++;
        }
    }

    return tokens;
}

bool RPN_Converter::has_greater_precedence(const std::string &op1, const std::string &op2) {
    return precedence[op1] > precedence[op2];
}

bool RPN_Converter::has_equal_precedence(const std::string &op1, const std::string &op2) {
    return  precedence[op1] == precedence[op2];
}

void RPN_Converter::config(const std::map<std::string, int>& precedence, const std::map<std::string, bool>& left_associativity) {
    this->left_associativity = left_associativity;
    this->precedence = precedence;
}
