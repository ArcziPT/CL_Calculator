#include <iostream>
#include <cmath>
#include "CalculatorConfig.h"
#include "TextHelper.h"
#include "FunctionFactory.h"
#include <fstream>

RPN_Converter converter;
RPN_Calculator calculator;
CalculatorConfig config;
FunctionFactory factory(&converter, &calculator);


void parse(const std::string& input){
    if (input[0] == '#') {
        auto strs = TextHelper::split(input, ' ');

        if (strs[0] == "#exit")
            exit(0);

        else if(strs[0] == "#remove"){
            config.remove_function(strs[1]).apply(converter).apply(calculator);

            std::cout<<"\""<<strs[1]<<"\" removed\n";
        }

        else if(strs[0] == "#info"){
            auto name = strs[1];

            std::cout<<"\""<<name<<"\" info:\n";
            config.print_function_data(name);
        }

        else if (strs[0] == "#define") {
            if (strs[1] == "function") {
                auto name = strs[2];
                int arg_num = stoi(strs[3]);

                auto func = factory.get_function(strs[4], arg_num);
                config.set_function(name, arg_num, *func, true, func->get_info()).apply(converter).apply(calculator);

                std::cout<<"\""<<name<<"\" defined\n";

                delete func;
            }
        }
    } else {
        auto rpn = converter.convert(input);
        std::cout << input << " = " << calculator.calculate(*rpn) << std::endl;
    }
}

int main(int argc, char** argv) {
    config.apply(calculator).apply(converter);

    if(argc < 2){
        std::string input;
        for(;;) {
            std::getline(std::cin, input);

            parse(input);
        }
    }

    else{
        auto filename = std::string(argv[1]);

        std::ifstream t(filename);

        std::string line;
        while (std::getline(t, line))
        {
            parse(line);
        }
    }

    return 0;
}