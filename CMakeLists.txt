cmake_minimum_required(VERSION 3.14)
project(ccalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(ccalculator main.cpp RPN_Converter.cpp RPN_Converter.h RPN_Calculator.cpp RPN_Calculator.h default_functions.cpp default_functions.h CalculatorConfig.cpp CalculatorConfig.h TextHelper.cpp TextHelper.h FunctionFactory.cpp FunctionFactory.h CalcFunction.cpp CalcFunction.h)