#pragma once

#include "CommDef.h"
#include "Point2D.h"
#include <vector>
#include <map>

typedef Point2D POS_TYPE;
typedef std::vector<Point2D> POS_VEC;
#define UNINIT_POINT_POS -1
#define POINT_MIN_X	0
#define POINT_MAX_X 10 
#define POINT_MIN_Y 0
#define POINT_MAX_Y 3
#define ROUND_PREVIEW_NUM 6
#define NORMAL_ANGER -50
#define BE_HIT_ANGER -30

typedef char DISTANCE_TYPE;
typedef char MOBILITY_TYPE;

enum FIGHTER_TYPE
{
	FIGHTER_UNKNOWN = 0,
	FIGHTER_LEADER = 1,
	FIGHTER_HERO = 2,
	FIGHTER_HIRE = 3,
	FIGHTER_NPC = 4,
};

enum GAME_GROUP
{
	GG_NOGROUP = -1,	// 无阵营
	GG_ATTACK = 0,	// 进攻方
	GG_DEFENSE = 1,	// 防守方

	GG_MAX,
};

enum FIGHTER_STATUS
{
	FS_UNKNOWN = 0, //未知
	FS_SYSTEM = 1, //系统
	FS_WAIT = 2, //等待
	FS_MOVE = 3, //移动
	FS_SKILL = 4, //技能
	FS_PASSIVE = 5, //被动
	FS_AURA = 6, //光环
	FS_COMBO = 7, //连击
	FS_BEATBACK = 8, //反击
};

#define BATTLE_USER_WAIT_SEC 600
#define BATTLE_WAIT_REWARD_SEC 600

enum BATTLE_STATUS
{
	BS_UNINITIALIZED = 0,
	BS_INITIALIZED = 1,
	BS_WAITLOADOK = 2,
	BS_FINISH = 3,
	BS_RUN = 4,
	BS_SKIPBATTLE = 5,
	BS_WAITACTION = 6,
	BS_REWARD = 7,
	BS_END = 8,
	BS_ERROREND = 9,
};

//不可以斜走
#define SURROUND_SLOT_NUM 4
//可以斜走
//#define SURROUND_SLOT_NUM 8

#define U_SHIFT Point2D(0,1)
#define R_SHIFT Point2D(1,0)
#define D_SHIFT Point2D(0,-1)
#define L_SHIFT Point2D(-1,0)
#define UR_SHIFT Point2D(1,1)
#define UL_SHIFT Point2D(-1,1)
#define DR_SHIFT Point2D(1,-1)
#define DL_SHIFT Point2D(-1,-1)
#define SURROUND_SHIFT POS_VEC{U_SHIFT,R_SHIFT,D_SHIFT,L_SHIFT, UR_SHIFT, UL_SHIFT, DR_SHIFT, DL_SHIFT}

enum BATTLE_WEIGHT
{
	BASE_WEIGHT = 10,
	U_WEIGHT = BASE_WEIGHT,
	R_WEIGHT = BASE_WEIGHT,
	D_WEIGHT = BASE_WEIGHT,
	L_WEIGHT = BASE_WEIGHT,
	UR_WEIGHT = (int)(BASE_WEIGHT * 1.4),
	UL_WEIGHT = (int)(BASE_WEIGHT * 1.4),
	DR_WEIGHT = (int)(BASE_WEIGHT * 1.4),
	DL_WEIGHT = (int)(BASE_WEIGHT * 1.4),
};
#define SURROUND_WEIGHT std::vector<uint32_t>{U_WEIGHT,R_WEIGHT,D_WEIGHT,L_WEIGHT, UR_WEIGHT, UL_WEIGHT, DR_WEIGHT, DL_WEIGHT}




#define INVALID_WEIGHT std::numeric_limits<int16_t>::max()

#define LU_SHIFT Point2D(-1,1)
#define RU_SHIFT Point2D(0,1)
#define LL_SHIFT Point2D(-1,0)
#define RR_SHIFT Point2D(1,0)
#define LD_SHIFT Point2D(0,-1)
#define RD_SHIFT Point2D(1,-1) 

#define LL_WEIGHT 10
#define LU_WEIGHT 15
#define LD_WEIGHT 15
#define RR_WEIGHT 10
#define RU_WEIGHT 15
#define RD_WEIGHT 15
#define BATTLE_SLOT_MAX 27 
//#define FIGHTER_WEIGHT BATTLE_SLOT_MAX*LD_WEIGHT+1
#define FIGHTER_WEIGHT BATTLE_SLOT_MAX*LD_WEIGHT

#define OFFSET_SLOT_MAX 85

enum DIRECTION_TYPE
{
	D_UNKNOW = -1,
	D_Left = 0,
	D_Right = 1,
};

enum ATTACK_TYPE
{
	Enum_AT_PHYSICAL = 1,	//物理攻击
							//Enum_AT_MAGICAL				= 2,	//魔法攻击
							Enum_AT_HOLY = 3,	//神圣攻击
							Enum_AT_HEALTH = 4,	//治疗
							Enum_AT_ANGER = 5,	//怒气
							Enum_AT_BUFF = 6,	//buff技能
							Enum_AT_AURA = 7,	//光环技能
							Enum_AT_LOSTHPHEALTH = 8,	//血量损失回血
							Enum_AT_LOSTHPATK = 9,	//损失血量物理攻击		
													//Enum_AT_LOSTHPATKMAGIC		= 10,	//损失血量魔法攻击
													Enum_AT_REPEL = 11,	//击退
													Enum_AT_CONNECT = 12,	//检测型effect，用于转接技能
													Enum_AT_REACT = 13,	//再次行动
													Enum_AT_EXTRADAMAGE = 14,	//额外伤害
													Enum_AT_REPELSTUN = 15,	//击退，未被击退则眩晕
													Enum_AT_Dispel = 16,	//驱散

													Enum_AT_SPECIAL = 100,	//特殊
													Enum_AT_VampireLordUltra = 100,	//吸血鬼伯爵特殊攻击

													Enum_PS_ATK_PASSIVE = 200,	//攻击被动
													Enum_PS_COMBO = 200,	//连击
													Enum_PS_REPELSTUN = 201,	//击退，不成功则眩晕
													Enum_PS_SPUTTER = 202,	//溅射
													Enum_PS_TRAMPLE = 203,	//践踏
													Enum_PS_ATKATTR = 204,	//攻击方属性变化
													Enum_PS_RESTOREHP = 205,	//恢复血量
													Enum_PS_TARGETBUFF = 206,	//目标BUFF
													Enum_PS_REPELHURT = 207,	//击退，不成功伤害提升

													Enum_PS_DEF_PASSIVE = 300,	//防御被动
													Enum_PS_BEATBACK = 300,	//反击
													Enum_PS_DODGE = 301,	//闪避
													Enum_PS_DEFATTR = 302,	//防御方属性变化
};

//是友军还是敌军或者全军由effect中的字段控制
enum ATTACK_MODE
{
	AM_SHAPE = 1,//根据形状攻击，根据ai或者索敌寻找主目标
	AM_SHAPE_RANDOM = 2,//根据形状随机，根据ai或者索敌寻找主目标，然后随机对某个主目标攻击
	AM_SHAPE_ME = 3,//以自身为中心，根据形状攻击
	AM_RANDOM_NUM = 4,//范围内随机几个
	AM_ROW = 5,//目标排
	AM_ROW_PARALLEL = 6,//平行目标排
	AM_FOLLOW = 7,//跟随上一个effect目标
	AM_END = 8,//当前方向最后一个	
	AM_BEGIN = 9,//当前方向最前一个
	AM_RANDOM_ROW_END = 10,//随机几排，每排最后一个
	AM_RANDOM_ROW_BEGIN = 11,//随机几排，每排第一个
	AM_MAX_ROW = 12,//人最多的一排
	AM_SELF = 13,//自己
	AM_HP_PERCENT_MIN_NUM = 14,//目标血量百分比最少的N个
	AM_HP_PERCENT_MAX_NUM = 15,//目标血量百分比最多的N个
	AM_HP_MIN_NUM = 16,//目标血量最少的N哥
	AM_HP_MAX_NUM = 17,//目标血量最多的N哥
	AM_EXCEPT_ME = 18,//除了自己
	AM_EACH_INCR = 19,//场上每个目标对自身提升属性
	AM_ALL_CONDITION_TARGET = 20,//所有符合条件定义的目标
	AM_ALL = 21,//全场所有人
	AM_RANDOM_ROW_ALL = 22,//随机一排，每排全部
	AM_RANDOM_2_ROW_ALL = 23,//随机两排，每排全部
};

enum ENEMY_FINDER_TYPE
{
	Enum_EFT_FRIEND = 0,//友军
	Enum_EFT_ENEMY = 1,//敌军
	Enum_EFT_ALL = 2,//全军
};


enum MAIN_TARGET_TYPE
{
	MT_MYSELF = 1,//自己
	MT_ENEMY_CLOSE = 2,//最近敌人
	MT_ENEMY_FAR = 3,//最远敌人
	MT_SELF_CLOSE = 4,//最近友方
	MT_SEFL_FAR = 5,//最远友方
};

enum MOVE_TARGET_TYPE
{
	NO_MOVE = 1,//不移动
	ENEMY_CLOSE = 2,//最近的敌人
	ENEMY_FAR = 3,//最远敌人
	FRIEND_CLOSE = 4,//最近友方
	FRIEND_FAR = 5,//最远友方
};

enum Enum_AI_STRATEGY
{
	Enum_AI_NONE,
	Enum_AI_EnemyClose,
	Enum_AI_EnemyNumMax,
	Enum_AI_MoveDisMin,
	Enum_AI_EnemySurroundMax,
	Enum_AI_EnemyAttackMe,
	Enum_AI_EnemyFar,
};

enum Enum_AI_EnemyFinder
{
	Enum_AIEF_None,
	Enum_AIEF_HpMin = 1,
	Enum_AIEF_HpMax = 2,
	Enum_AIEF_DamageMax = 3,
	Enum_AIEF_AttackMe = 4,//上回合攻击自己的目标
	Enum_AIEF_MyAttack = 5,//上回合自己攻击的目标
	Enum_AIEF_Kill = 6,
};

#define HIT_VALUE 10000
#define MOVE_VALUE 1
#define DISTANCE_VALUE 100

//此枚举为和前端通信飘字使用
enum Enum_FighterBitStatus
{
	Enum_FBS_NONE = 0x00000000,
	Enum_FBS_HIT = 0x00000001,//命中
	Enum_FBS_AVOID = 0x00000002,//闪避
	Enum_FBS_CRIT = 0x00000004,//暴击
	Enum_FBS_SPUTTER = 0x00000008,//溅射
	Enum_FBS_TRAMPLE = 0x00000010,//践踏
	Enum_FBS_IGNOREDEF = 0x00000020,//穿透
	Enum_FBS_SHIDLD = 0x00000040,//盾防
	Enum_FBS_DOUBLE = 0x00000080,//倍率攻击
	Enum_FBS_DEAD = 0x80000000,//死亡
};

enum Enum_FightNotifyType
{
	Enum_FNT_SYSTEM = 0,
	Enum_FNT_EFFECT = 1,
	Enum_FNT_BUFF = 2,
	Enum_FNT_BUFFDEL = 3,
	Enum_FNT_POSCHANGE = 4,
	Enum_FNT_BUFFVALUE = 5,
	Enum_FNT_AURA = 6,
};

enum Enum_FightOperator
{
	Enum_FO_ADD = 0,
	Enum_FO_MULTIPLY = 1,
};

enum Enum_SkillTrigger
{
	Enum_ST_NONE = 0,//永远不会触发
	Enum_ST_TargetDead = 1,//攻击目标死亡 
	Enum_ST_SelfDead = 2,//自身死亡
};

typedef int BuffType;
enum Enum_BuffType
{
	Enum_BuffType_NONE = 0,
	Enum_BuffType_DOT = 1,//持续性伤血
	Enum_BuffType_HOT = 2,//持续性回血
	Enum_BuffType_ATTR = 3,//属性变换

	Enum_BuffType_SPECIAL = 1000,//特殊
	Enum_BuffType_Taunt = 1001,//嘲讽
	Enum_BuffType_Bind = 1002,//束缚
	Enum_BuffType_Stun = 1003,//眩晕
	Enum_BuffType_Seduce = 1004,//魅惑
	Enum_BuffType_Silence = 1005,//沉默
	Enum_BuffType_HpShield = 1006,//血量护盾
	Enum_BuffType_HpRespondShield = 1007,//血量反击护盾
};

typedef int BuffTrigger;
enum Enum_BuffTrigger
{
	Enum_BuffTrigger_None = 0,
	Enum_BuffTrigger_RoundStart = 1,//回合行动开始
	Enum_BuffTrigger_RoundEnd = 2,//回合行动结束
	Enum_BuffTrigger_Immediately = 3,//马上
};

enum Enum_BuffOperType
{
	Enum_BuffOperType_None = 0,//无,无视任何规则直接加入到buff列表中
	Enum_BuffOperType_Replace = 1,//直接替换
	Enum_BuffOperType_NonReplace = 2,//不能替换
	Enum_BuffOperType_ValueAdd = 3,//值叠加
	Enum_BuffOperType_RoundAdd = 4,//回合叠加
	Enum_BuffOperType_LayerAdd = 5,//层数叠加
	Enum_BuffOperType_AllAdd = 6,//值和回合都叠加
};

enum Enum_AttackType
{
	Enum_Unknow_Attack = 0,
	Enum_Melee_Attack = 1,
	Enum_Range_Attack = 2,
};

enum Enum_EffectCondition
{
	Enum_EC_Unknown = 0,
	Enum_EC_TargetFeatrue = 1,	//目标特性
	Enum_EC_Group = 2,	//阵营判断
	Enum_EC_TargetHpPercentBelow = 3,	//目标血量百分比低于
	Enum_EC_TargetHpPercentAbove = 4,	//目标血量百分比高于
	Enum_EC_BattleRound = 5,	//战斗回合数
	Enum_EC_SelfHpPercentBelow = 6,	//自身血量百分比低于
	Enum_EC_SelfHpPercentAbove = 7,	//自身血量百分比高于
	Enum_EC_TargetLevelBelow = 8,	//目标等级低于
	Enum_EC_TargetLevelAbove = 9,	//目标等级高于
	Enum_EC_SelfHpCompareTargetHp = 10,	//自身血量和目标血量比较
};

enum Enum_EffectTrigger
{
	Enum_ET_Unknown = 0,		//默认
	Enum_ET_Resident = 1,		//常驻
	Enum_ET_ActionStart = 2,	//行动开始前触发
	Enum_ET_ActionEnd = 3,		//行动结束后触发
};