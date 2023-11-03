#include <iostream>
#include <fstream>

#include "compiler.hpp"

using namespace std;

int main()
{
    // インスタンス生成
    Compiler compiler;

    // プログラムの文字列またはファイルのセット
    string filename = "sample";
    // compiler.set_program_string("READ(L); A:=0; K:=1; WHILE K < L+1 DO A:=A+K;K:=K+1ENDWHILE;WRITE(A).");
    compiler.set_program_file("sample/" + filename + ".pas");

    // コンパイル
    compiler.compile();

    // 結果の表示
    compiler.print_result();

    // ファイルに結果を出力
    compiler.output_file("sample/output/" + filename + ".obj");

    return 0;
}