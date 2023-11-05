#include <iostream>

#include "vm.hpp"

using namespace std;

VM::VM(vector<Command> obj) {
    this->obj = obj;
}

void VM::run(void) {
    for (auto it = obj.begin(); it < obj.end();) {
    // itのインクリメントはCJP，UDPの時にエスケープするために，for文の最後に行う

        // ニモニックに応じた処理
        Mnemonic mnemonic = it->get_mnemonic();
        if (mnemonic == GET) {
            string input_string;
            int input_num;
            cin >> input_string;
            try {
                input_num = stoi(input_string);
            } catch (const invalid_argument& e) {
                cerr << "正常な数値を入力してください．" << endl;
                exit(1);
            } catch (const out_of_range& e) {
                cerr << "入力された数値が大きすぎます．" << endl;
                exit(1);
            }
            if (input_num < 0) {
                cerr << "非負の整数を入力してください．";
                exit(1);
            }
            // stoi()は入力が小数の場合でも例外を投げないので，小数点があるかどうかを確認する
            if (input_string.find('.') != string::npos) {
                cerr << "整数を入力してください．" << endl;
                exit(1);
            }
            memory[it->get_operand().value()] = input_num;
        } else if (mnemonic == PUT) {
            cout << memory[it->get_operand().value()] << endl;
        } else if (mnemonic == LOD) {
            stk.push(memory[it->get_operand().value()]);
        } else if (mnemonic == LDC) {
            stk.push(it->get_operand().value());
        } else if (mnemonic == STR) {
            int value = stk.top();
            stk.pop();
            memory[it->get_operand().value()] = value;
        } else if (mnemonic == ADD) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 + value1);
        } else if (mnemonic == SUB) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 - value1);
        } else if (mnemonic == MLT) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 * value1);
        } else if (mnemonic == DIV) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 / value1);
        } else if (mnemonic == EQL) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 == value1);
        } else if (mnemonic == GRT) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(value2 > value1);
        } else if (mnemonic == LET) {
            int value1 = stk.top();
            stk.pop();
            int value2 = stk.top();
            stk.pop();
            stk.push(int(value2 < value1));
        } else if (mnemonic == CJP) {
            int value = stk.top();
            stk.pop();
            if (value == 0) {
                it = obj.begin() + it->get_operand().value();
                continue;   // インクリメントをエスケープ
            }
        } else if (mnemonic == UJP) {
            it = obj.begin() + it->get_operand().value();
            continue;   // インクリメントをエスケープ
        }

        ++it;
    }
}