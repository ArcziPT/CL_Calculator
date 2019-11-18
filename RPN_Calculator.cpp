//
// Created by ArcziPT on 09.07.2019.
//

#include "RPN_Calculator.h"
#include <stack>
#include <functional>

double RPN_Calculator::calculate(const RPN& rpn) {
    std::stack<double> stack;

    //algorithm to calculate rpn expression
    //https://en.wikipedia.org/wiki/Reverse_Polish_notation
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
                //check if function exists
                if(func_map.count(token.val) == 0){
                    std::cout<<"Function(operator) \""<<token.val<<"\" not defined\n";
                    err = true;
                    return 0;
                }

                auto def = func_map[token.val];

                //get arguments from stack
                std::vector<double> args;
                for(int i = 0; i < def.arg_num; i++){
                    args.push_back(stack.top());
                    stack.pop();
                }

                double ret;
                //func_ptr is std::variant
                //which type will be used depends on function' dynamism
                if(def.dynamic) {
                    auto func_rpn = std::get<rpn_func_ptr>(def.func_ptr)(args);

                    //in case of dynamic one we recursively call calculate on ptr
                    ret = calculate(*func_rpn);
                }
                else
                    ret = std::get<calc_func_ptr>(def.func_ptr)(args);

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
