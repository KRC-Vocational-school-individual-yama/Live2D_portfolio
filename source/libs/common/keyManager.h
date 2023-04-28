#pragma once
#include<unordered_map>
#include<vector>
class KeyBoard;

class KeyManager {
public:
	KeyManager();
	~KeyManager();
	
	bool Down(int keyNumber);
	bool DownKeep(int keyNumber);
	bool Up(int keyNumber);

	void SetKey(std::vector<int>keyList);
private:
	 std::unordered_map<int, KeyBoard*>keys;

	void SetKey(int keyNumber);
};
