#ifndef _VM_HPP_
#define _VM_HPP_

#include <vector>
#include <stack>
#include "compiler.hpp"

using namespace std;

class VM {
private:
    vector<Command> obj;    // オブジェクトファイル
    stack<int> stk;         // スタック
    int memory[26];         // メモリ

public:
    VM(vector<Command> obj);    // コンストラクタ
    void run();                 // オブジェクトファイルを実行
};
#endif // _VM_HPP_