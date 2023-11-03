# Mini-Mini-Pascal Compiler
作成者： **Wataru Zama**

## 実行方法
### インスタンス生成
`Compiler`クラスのインスタンスを生成する．
```cpp
// インスタンス生成
Compiler compiler;
```
### コンパイル対象のプログラムをセットする．
文字列を直接セットする場合は`Compiler::set_program_string`関数を使用する．

```cpp
// プログラムの文字列をセットする
compiler.set_program_string("A:=0.");
```
コンパイルするファイル名を指定する場合は`Compiler::set_program_file`関数を使用する．
```cpp
// ファイル名をセットする
compiler.set_program_file("sample.pas");
```
### コンパイルの実行
Compiler::compile関数を使ってコンパイルする．
```cpp
// コンパイル
compiler.compile();
```

### 結果の表示
結果をコンソールに表示する．
```cpp
// 結果の表示
compiler.print_result();
```
指定したファイルに結果を出力する．
```cpp
// ファイルに結果を出力
compiler.output_file("sample.obj");
```

## ディレクトリ構成
- **command.cpp**: `Commandクラス`のソースファイル
- **command.hpp**: `Commandクラス`のヘッダファイル
- **compiler.cpp**: `Compilerクラス`のソースファイル
- **compiler.hpp**: `Compilerクラス`のヘッダファイル
- **main.cpp**: main関数のソースファイル
- **sample/**: サンプルプログラムのディレクトリ
    - **output/**: サンプルプログラムの出力ディレクトリ
        - **sample1.obj**: サンプルプログラム1の出力オブジェクトファイル
        - **sample2.obj**: サンプルプログラム2の出力オブジェクトファイル
        - **︙**
    - **sample1.pas**: サンプルプログラム1
    - **sample2.pas**: サンプルプログラム2
    - **︙**

## 誤り処理一覧
| 誤り内容 | メッセージ |
|:----:|:----------:|
| 文（statement）の末尾が`;`または`.`でない． | `文の末尾が正しく認識されません．` |
| 文（statement）がREAD文，WRITE文，代入文，`;`または`.`のみの文 | `文が正しく認識されません．` |
| `READ`の左括弧がない | `READ文の左括弧が認識されません．` |
| `READ`の変数が存在しないか，A-Zでない | `READ文の引数が正しくありません．` |
| `READ`の右括弧がない | `READ文の右括弧が認識されません．` |
| `WRITE`の左括弧がない | `WRITE文の左括弧が認識されません．` |
| `WRITE`の変数が存在しないか，A-Zでない | `WRITE文の引数が正しくありません．` |
| `WRITE`の右括弧がない | `WRITE文の右括弧が認識されません．` |
| `WHILE`の後に空白がない | `WHILE文の後に空白がありません．` |
| `WHILE`の後に`DO`がない | `WHILE文のDOが認識されません．` |
| `DO`の後に空白または改行がない | `WHILE文のDOの後に空白または改行がありません．` |
| `ENDWHILE`がない | `WHILE文の終わり(ENDWHILE)が認識されません．` |
| 関係式がの演算子が`=`か`>`か`<`の何でもない | `関係式が正しくありません．` |
| 符号なし定数が0から始まっている | `定数が0から始まっています．` |

<!-- ## 誤り表示 -->