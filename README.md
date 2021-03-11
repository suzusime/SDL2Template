SDL2Template for Visual C++
===========================

## 概要
これは、マルチメディアライブラリである[SDL2 (Simple DirectMedia Layer ver. 2)](http://www.libsdl.org/index.php)をWindowsで使うための雛型です。要するに、「面倒な環境構築を済ませておいた」ものです。

## 利用に必要なもの
- Visual Studio 2019以降

## 使い方
1. このリポジトリをzipでダウンロードするか`git clone`してください。
2. Visual StudioでSDL2Template.slnを開いてください。
3. F5キーを押すとサンプルプログラムがビルド＆実行されるはずです。

エントリポイントはSDL2Templateプロジェクトのmain.cppです。SDL2Template以外のプロジェクトはSDLのライブラリなので、通常の使用では触る必要がないはずです。

## 使用バージョン
このプロジェクトには現状、以下のバージョンのSDLが含まれています。

- SDL version 2.0.14
