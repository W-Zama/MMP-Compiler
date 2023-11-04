#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <optional>
#include <map>
#include <string>

using namespace std;

// ニモニックの列挙型
typedef enum {
    GET,
    PUT,
    LOD,
    LDC,
    STR,
    ADD,
    SUB,
    MLT,
    DIV,
    EQL,
    GRT,
    LET,
    CJP,
    UJP,
} Mnemonic;

class Command {
public:
    Mnemonic mnemonic;      // ニモニック (GETなど)
    optional<int> operand;  // オペランド (ニモニックの演算対象の値)
    static map<int, string> mnemonic2string_map;    // ニモニックの列挙型と文字列の対応表

    Command(Mnemonic mnemonic, optional<int> operand);
};

#endif // _COMMAND_HPP_