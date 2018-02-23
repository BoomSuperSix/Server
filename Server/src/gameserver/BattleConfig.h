#pragma once
#include <stdint.h>

struct EffectCfg
{
	uint32_t id;
	bool bConvert;
	int nShow;
	int nAtkType;
	int nAtkMode;
	int nAtkGroup;
	//int nMainTargetType;
	std::unordered_map<unsigned char, std::vector<POS_TYPE>> mShape;
	bool bMultiParam;
	std::vector<std::pair<float, float>> vValueRate;
	std::vector<std::pair<float, float>> vValueValue;
	std::vector<int> vHitAnger;
	int nTargetSize;
	float nCastRate;
	std::vector<EffectConditionCfg> vCondition;
	int nTrigger;
	std::vector<std::pair<int, char>> vExtraEffectId;
	std::vector<std::pair<const EffectCfg*, char>> vExtraEffects;
	//string expand1;
	//string expand2;

	bool CheckEffectCondition(UserFighterPtr pMe, UserFighterPtr pTarget, BattleField* pBattle = nullptr)const;
};
