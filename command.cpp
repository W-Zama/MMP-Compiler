#include "command.hpp"

using namespace std;

Command::Command(Mnemonic mnemonic, optional<int> operand) {
    this->mnemonic = mnemonic;
    this->operand = operand;
}