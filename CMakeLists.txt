cmake_minimum_required(VERSION 3.14)
project(cl_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(cl_calculator main.cpp RPN_Converter.cpp RPN_Converter.h RPN_Calculator.cpp RPN_Calculator.h default_functions.cpp default_functions.h CalculatorConfig.cpp CalculatorConfig.h TextHelper.cpp TextHelper.h FunctionFactory.cpp FunctionFactory.h CalcFunction.cpp CalcFunction.h)