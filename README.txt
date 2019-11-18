Comand Line Calculator using Reverse Polish Notation

It can be used in interactive mode or called from commandline with one argument describing path to file, which has to be processed.

It's possible to define your own simple functions(which are converted into another RPN expression, that will be calculeted when it is called).
Example:

#define function <func_name> <args_num> <expression>
expression can consist of another functions calls, number, operators and 'xi' where i is any of(0,1,2,...,args_num-1)

#define function my_func1 2 x0*x1+x0
#define function my_func2 2 my_func(x0,x1)+my_func(x1,x0)

my_func2(10, 5) = my_func1(10,5) + my_func1(5,10) = 60 + 55 = 115