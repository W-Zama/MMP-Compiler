#include "command.hpp"

using namespace std;

// コンストラクタ
Command::Command(Mnemonic mnemonic, optional<int> operand) {
    this->mnemonic = mnemonic;
    this->operand = operand;
}

// ニモニックのゲッタ
Mnemonic Command::get_mnemonic(void) {
    return mnemonic;
}

// ニモニックのセッタ
void Command::set_mnemonic(Mnemonic mnemonic) {
    this->mnemonic = mnemonic;
}

// オペランドのゲッタ
optional<int> Command::get_operand(void) {
    return operand;
}

// オペランドのセッタ
void Command::set_operand(optional<int> operand) {
    this->operand = operand;
}

// ニモニックの列挙型と文字列の対応表
map<int, string> Command::mnemonic2string_map = {
    {GET, "GET"},
    {PUT, "PUT"},
    {LOD, "LOD"},
    {LDC, "LDC"},
    {STR, "STR"},
    {ADD, "ADD"},
    {SUB, "SUB"},
    {MLT, "MLT"},
    {DIV, "DIV"},
    {EQL, "EQL"},
    {GRT, "GRT"},
    {LET, "LET"},
    {CJP, "CJP"},
    {UJP, "UJP"},
};