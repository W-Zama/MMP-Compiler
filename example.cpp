#include "compiler.hpp"
#include "vm.hpp"

using namespace std;

int main()
{
    /* コンパイル */

    // インスタンス生成
    Compiler compiler;

    // プログラムの文字列をセットする
    // compiler.set_program_string("A:=0.");

    // ファイル名をセットする
    string filename = "sample/sample1";
    compiler.set_program_file(filename + ".pas");

    // コンパイル
    compiler.compile();

    // 結果の表示
    compiler.print_result();

    // ファイルに結果を出力
    // compiler.output_file(filename + ".obj");

    /* 仮想マシンで実行 */

    // オブジェクトファイルを取得
    vector<Command> obj = compiler.get_obj();

    // 仮想マシンのインスタンス生成
    VM vm(compiler.get_obj());

    // オブジェクトファイルを実行
    vm.run();

    return 0;
}