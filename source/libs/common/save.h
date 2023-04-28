#pragma once

#include<string>
#include<vector>


class CsvSave {
public:
	/// <summary>
	/// <para>CSVファイルの読み込み</para>
	/// <para>読み込んだ値を全て文字列しに返す</para>
	/// </summary>
	/// <param name="pass	">読み込む.csvのファイルパス</param>
	/// <returns></returns>
	static std::vector<std::string> Load(std::string pass);

	/// <summary>
	/// <para>ファイルの書き出し</para>
	/// <para></para>
	/// </summary>
	/// <param name="pass	">書き出す.csvのファイルパス</param>
	/// <param name="str	">書き出す.csvのファイル名[.csvまで入れる]</param>
	/// <param name="CRLF	">改行するまでの１行の文字数</param>
	/// <returns></returns>
	static void Save(std::string pass, std::vector<std::string>str,int CRLF=10);
private:
};