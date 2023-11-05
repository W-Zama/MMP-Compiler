#include "compiler.hpp"
#include "vm.hpp"

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

    // オブジェクトファイルを取得
    vector<Command> obj = compiler.get_obj();

    // 仮想マシンのインスタンス生成
    VM vm(compiler.get_obj());

    // オブジェクトファイルを実行
    vm.run();

    return 0;
}