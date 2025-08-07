#pragma once
#include<memory>

class UnitBase;

class CharacterManager
{
public:
	static constexpr int CHARACTER_NUM = 4;

	CharacterManager(void);
	~CharacterManager(void);

	void Init(const int _userNum);
	void Update(void);
	void Draw(void);
	void Release(void);

private:
	std::unique_ptr<UnitBase>characteres_[CHARACTER_NUM];
};

