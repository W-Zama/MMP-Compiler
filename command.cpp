#include "command.hpp"

using namespace std;

Command::Command(Mnemonic mnemonic, optional<int> operand) {
    this->mnemonic = mnemonic;
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