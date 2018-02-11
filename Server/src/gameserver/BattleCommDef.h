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
	GG_NOGROUP = -1,	// ����Ӫ
	GG_ATTACK = 0,	// ������
	GG_DEFENSE = 1,	// ���ط�

	GG_MAX,
};

enum FIGHTER_STATUS
{
	FS_UNKNOWN = 0, //δ֪
	FS_SYSTEM = 1, //ϵͳ
	FS_WAIT = 2, //�ȴ�
	FS_MOVE = 3, //�ƶ�
	FS_SKILL = 4, //����
	FS_PASSIVE = 5, //����
	FS_AURA = 6, //�⻷
	FS_COMBO = 7, //����
	FS_BEATBACK = 8, //����
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

//������б��
#define SURROUND_SLOT_NUM 4
//����б��
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
	Enum_AT_PHYSICAL = 1,	//������
							//Enum_AT_MAGICAL				= 2,	//ħ������
							Enum_AT_HOLY = 3,	//��ʥ����
							Enum_AT_HEALTH = 4,	//����
							Enum_AT_ANGER = 5,	//ŭ��
							Enum_AT_BUFF = 6,	//buff����
							Enum_AT_AURA = 7,	//�⻷����
							Enum_AT_LOSTHPHEALTH = 8,	//Ѫ����ʧ��Ѫ
							Enum_AT_LOSTHPATK = 9,	//��ʧѪ��������		
													//Enum_AT_LOSTHPATKMAGIC		= 10,	//��ʧѪ��ħ������
													Enum_AT_REPEL = 11,	//����
													Enum_AT_CONNECT = 12,	//�����effect������ת�Ӽ���
													Enum_AT_REACT = 13,	//�ٴ��ж�
													Enum_AT_EXTRADAMAGE = 14,	//�����˺�
													Enum_AT_REPELSTUN = 15,	//���ˣ�δ��������ѣ��
													Enum_AT_Dispel = 16,	//��ɢ

													Enum_AT_SPECIAL = 100,	//����
													Enum_AT_VampireLordUltra = 100,	//��Ѫ�������⹥��

													Enum_PS_ATK_PASSIVE = 200,	//��������
													Enum_PS_COMBO = 200,	//����
													Enum_PS_REPELSTUN = 201,	//���ˣ����ɹ���ѣ��
													Enum_PS_SPUTTER = 202,	//����
													Enum_PS_TRAMPLE = 203,	//��̤
													Enum_PS_ATKATTR = 204,	//���������Ա仯
													Enum_PS_RESTOREHP = 205,	//�ָ�Ѫ��
													Enum_PS_TARGETBUFF = 206,	//Ŀ��BUFF
													Enum_PS_REPELHURT = 207,	//���ˣ����ɹ��˺�����

													Enum_PS_DEF_PASSIVE = 300,	//��������
													Enum_PS_BEATBACK = 300,	//����
													Enum_PS_DODGE = 301,	//����
													Enum_PS_DEFATTR = 302,	//���������Ա仯
};

//���Ѿ����ǵо�����ȫ����effect�е��ֶο���
enum ATTACK_MODE
{
	AM_SHAPE = 1,//������״����������ai��������Ѱ����Ŀ��
	AM_SHAPE_RANDOM = 2,//������״���������ai��������Ѱ����Ŀ�꣬Ȼ�������ĳ����Ŀ�깥��
	AM_SHAPE_ME = 3,//������Ϊ���ģ�������״����
	AM_RANDOM_NUM = 4,//��Χ���������
	AM_ROW = 5,//Ŀ����
	AM_ROW_PARALLEL = 6,//ƽ��Ŀ����
	AM_FOLLOW = 7,//������һ��effectĿ��
	AM_END = 8,//��ǰ�������һ��	
	AM_BEGIN = 9,//��ǰ������ǰһ��
	AM_RANDOM_ROW_END = 10,//������ţ�ÿ�����һ��
	AM_RANDOM_ROW_BEGIN = 11,//������ţ�ÿ�ŵ�һ��
	AM_MAX_ROW = 12,//������һ��
	AM_SELF = 13,//�Լ�
	AM_HP_PERCENT_MIN_NUM = 14,//Ŀ��Ѫ���ٷֱ����ٵ�N��
	AM_HP_PERCENT_MAX_NUM = 15,//Ŀ��Ѫ���ٷֱ�����N��
	AM_HP_MIN_NUM = 16,//Ŀ��Ѫ�����ٵ�N��
	AM_HP_MAX_NUM = 17,//Ŀ��Ѫ������N��
	AM_EXCEPT_ME = 18,//�����Լ�
	AM_EACH_INCR = 19,//����ÿ��Ŀ���������������
	AM_ALL_CONDITION_TARGET = 20,//���з������������Ŀ��
	AM_ALL = 21,//ȫ��������
	AM_RANDOM_ROW_ALL = 22,//���һ�ţ�ÿ��ȫ��
	AM_RANDOM_2_ROW_ALL = 23,//������ţ�ÿ��ȫ��
};

enum ENEMY_FINDER_TYPE
{
	Enum_EFT_FRIEND = 0,//�Ѿ�
	Enum_EFT_ENEMY = 1,//�о�
	Enum_EFT_ALL = 2,//ȫ��
};


enum MAIN_TARGET_TYPE
{
	MT_MYSELF = 1,//�Լ�
	MT_ENEMY_CLOSE = 2,//�������
	MT_ENEMY_FAR = 3,//��Զ����
	MT_SELF_CLOSE = 4,//����ѷ�
	MT_SEFL_FAR = 5,//��Զ�ѷ�
};

enum MOVE_TARGET_TYPE
{
	NO_MOVE = 1,//���ƶ�
	ENEMY_CLOSE = 2,//����ĵ���
	ENEMY_FAR = 3,//��Զ����
	FRIEND_CLOSE = 4,//����ѷ�
	FRIEND_FAR = 5,//��Զ�ѷ�
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
	Enum_AIEF_AttackMe = 4,//�ϻغϹ����Լ���Ŀ��
	Enum_AIEF_MyAttack = 5,//�ϻغ��Լ�������Ŀ��
	Enum_AIEF_Kill = 6,
};

#define HIT_VALUE 10000
#define MOVE_VALUE 1
#define DISTANCE_VALUE 100

//��ö��Ϊ��ǰ��ͨ��Ʈ��ʹ��
enum Enum_FighterBitStatus
{
	Enum_FBS_NONE = 0x00000000,
	Enum_FBS_HIT = 0x00000001,//����
	Enum_FBS_AVOID = 0x00000002,//����
	Enum_FBS_CRIT = 0x00000004,//����
	Enum_FBS_SPUTTER = 0x00000008,//����
	Enum_FBS_TRAMPLE = 0x00000010,//��̤
	Enum_FBS_IGNOREDEF = 0x00000020,//��͸
	Enum_FBS_SHIDLD = 0x00000040,//�ܷ�
	Enum_FBS_DOUBLE = 0x00000080,//���ʹ���
	Enum_FBS_DEAD = 0x80000000,//����
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
	Enum_ST_NONE = 0,//��Զ���ᴥ��
	Enum_ST_TargetDead = 1,//����Ŀ������ 
	Enum_ST_SelfDead = 2,//��������
};

typedef int BuffType;
enum Enum_BuffType
{
	Enum_BuffType_NONE = 0,
	Enum_BuffType_DOT = 1,//��������Ѫ
	Enum_BuffType_HOT = 2,//�����Ի�Ѫ
	Enum_BuffType_ATTR = 3,//���Ա任

	Enum_BuffType_SPECIAL = 1000,//����
	Enum_BuffType_Taunt = 1001,//����
	Enum_BuffType_Bind = 1002,//����
	Enum_BuffType_Stun = 1003,//ѣ��
	Enum_BuffType_Seduce = 1004,//�Ȼ�
	Enum_BuffType_Silence = 1005,//��Ĭ
	Enum_BuffType_HpShield = 1006,//Ѫ������
	Enum_BuffType_HpRespondShield = 1007,//Ѫ����������
};

typedef int BuffTrigger;
enum Enum_BuffTrigger
{
	Enum_BuffTrigger_None = 0,
	Enum_BuffTrigger_RoundStart = 1,//�غ��ж���ʼ
	Enum_BuffTrigger_RoundEnd = 2,//�غ��ж�����
	Enum_BuffTrigger_Immediately = 3,//����
};

enum Enum_BuffOperType
{
	Enum_BuffOperType_None = 0,//��,�����κι���ֱ�Ӽ��뵽buff�б���
	Enum_BuffOperType_Replace = 1,//ֱ���滻
	Enum_BuffOperType_NonReplace = 2,//�����滻
	Enum_BuffOperType_ValueAdd = 3,//ֵ����
	Enum_BuffOperType_RoundAdd = 4,//�غϵ���
	Enum_BuffOperType_LayerAdd = 5,//��������
	Enum_BuffOperType_AllAdd = 6,//ֵ�ͻغ϶�����
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
	Enum_EC_TargetFeatrue = 1,	//Ŀ������
	Enum_EC_Group = 2,	//��Ӫ�ж�
	Enum_EC_TargetHpPercentBelow = 3,	//Ŀ��Ѫ���ٷֱȵ���
	Enum_EC_TargetHpPercentAbove = 4,	//Ŀ��Ѫ���ٷֱȸ���
	Enum_EC_BattleRound = 5,	//ս���غ���
	Enum_EC_SelfHpPercentBelow = 6,	//����Ѫ���ٷֱȵ���
	Enum_EC_SelfHpPercentAbove = 7,	//����Ѫ���ٷֱȸ���
	Enum_EC_TargetLevelBelow = 8,	//Ŀ��ȼ�����
	Enum_EC_TargetLevelAbove = 9,	//Ŀ��ȼ�����
	Enum_EC_SelfHpCompareTargetHp = 10,	//����Ѫ����Ŀ��Ѫ���Ƚ�
};

enum Enum_EffectTrigger
{
	Enum_ET_Unknown = 0,		//Ĭ��
	Enum_ET_Resident = 1,		//��פ
	Enum_ET_ActionStart = 2,	//�ж���ʼǰ����
	Enum_ET_ActionEnd = 3,		//�ж������󴥷�
};