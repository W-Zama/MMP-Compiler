#include "compiler.hpp"

using namespace std;

int main()
{
    // インスタンス生成
    Compiler compiler;

    // プログラムの文字列をセットする
    // compiler.set_program_string("A:=0.");

    // ファイル名をセットする
    string filename = "sample/sample";
    compiler.set_program_file(filename + ".pas");

    // コンパイル
    compiler.compile();

    // 結果の表示
    compiler.print_result();

    // ファイルに結果を出力
    // compiler.output_file(filename + ".obj");

    return 0;
}