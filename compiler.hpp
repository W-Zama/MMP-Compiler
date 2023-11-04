#ifndef _COMPILER_HPP_
#define _COMPILER_HPP_

#include <string>
#include <vector>

#include "Command.hpp"

using namespace std;

class Compiler {
private:
    string str;
    char* cursor;
    vector<Command> obj;

    void program(void);
    void statement(void);
    bool parse_read(void);
    bool parse_write(void);
    bool parse_assignment(void);
    bool parse_while_do(void);
    void relational_expression(void);
    void simple_expression(void);
    void term(void);
    void factor(void);
    void unsigned_constant(void);
    void skip(void);
    void syntax_error(string message);

public:
    Compiler(void);
    void set_program_string(string str);
    void set_program_file(string filename);
    void compile(void);
    void print_result(void);
    void output_file(string filename);

};

#endif // _COMPILER_HPP_