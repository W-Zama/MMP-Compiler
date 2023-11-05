#include <iostream>
#include <fstream>

#include "compiler.hpp"

using namespace std;

void command_error(string message) {
    cerr << message << endl;
    cerr << "詳しくは-hまたは--helpを参照してください．" << endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        command_error("mmpc [オプション（必須）] [ファイルのパス1 ファイルのパス2, ...] の形式で実行してください．");
    }

    // 結果の出力オプションのフラグ
    bool output_to_console = false;
    bool output_to_file = false;

    for (int i = 1; i < argc; i++) {
        // i番目の引数を取得
        string filename = argv[i];

        if (i == 1) {
            if (filename == "-c") { // -cオプションの場合
                output_to_console = true;   // ターミナルに出力する
                continue;
            } else if (filename == "-f") {  // -fオプションの場合
                output_to_file = true;  // ファイルに出力する
                continue;
            } else if (filename == "-cf" || filename == "-fc") {    // -fcまたは-cfオプションの場合
                // 両方に出力する
                output_to_file = true;    // ファイルに出力する
                output_to_console = true;    // ターミナルに出力する
            } else if (filename == "-h" || filename == "--help") {  // -hまたは--helpオプションの場合
                cout << "mmpc [オプション（必須）] [ファイルのパス1 ファイルのパス2, ...] の形式で実行してください．" << endl;
                cout << endl;
                cout << "オプション一覧" << endl;
                cout << "-c: コンパイル結果をターミナルに出力する" << endl;
                cout << "-f: コンパイル結果をファイルに出力する" << endl;
                cout << "-cfまたは-fc: コンパイル結果をターミナルとファイルに出力する" << endl;
                cout << "-hまたは--help: ヘルプを表示する" << endl;
                cout << endl;
                cout << "また，ファイルのパスには拡張子を含めてください．" << endl;
                return 0;
            }
            else {
                command_error("オプションを正しく指定してください．");
            }
        }

        // 拡張子を取り除いたファイルのパスを取得
        size_t dot_index = filename.find_last_of("."); // 最後のドットの位置を取得
        string basename;
        if (dot_index != string::npos) {
            basename = filename.substr(0, dot_index); // ドットより前の部分
        } else {
            command_error("拡張子付きファイルを指定してください");
        }

        // インスタンス生成
        Compiler compiler;

        // プログラムの文字列またはファイルのセット
        compiler.set_program_file(filename);

        // コンパイル
        compiler.compile();

        // 結果の表示
        if (output_to_console) {
            cout << filename << "のコンパイル結果(" << basename << ".obj)" << endl;
            compiler.print_result();
            cout << "----------------------------------------" << endl;
        }

        // ファイルに結果を出力
        if (output_to_file) {
            compiler.output_file(basename + ".obj");
        }
    }

    return 0;
}