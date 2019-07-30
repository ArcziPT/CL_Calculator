//
// Created by ArcziPT on 09.07.2019.
//

#include "RPN_Calculator.h"
#include <stack>
#include <functional>

double RPN_Calculator::calculate(const RPN& rpn) {
    std::stack<double> stack;

    for(auto& token : rpn.stack){
        switch(token.type){
            case number:
                stack.push(stod(token.val));
                break;

            case var:
                std::cout<<"VAR: "<<token.val<<std::endl;
                err = true;
                return 0;

            case func:
            case op:
                if(func_map.count(token.val) == 0){
                    std::cout<<"Function(operator) \""<<token.val<<"\" not defined\n";
                    err = true;
                    return 0;
                }

                auto def = func_map[token.val];

                std::vector<double> args;
                for(int i = 0; i < def.arg_num; i++){
                    args.push_back(stack.top());
                    stack.pop();
                }

                auto ret = def.func_ptr(args);
                stack.push(ret);
                break;
        }
    }

    return stack.top();
}

void RPN_Calculator::config(const std::map<std::string, func_def>& func_map, bool var_mode) {
    this->func_map = func_map;
    this->var_mode = var_mode;
}

bool RPN_Calculator::error() {
    return err;
}
