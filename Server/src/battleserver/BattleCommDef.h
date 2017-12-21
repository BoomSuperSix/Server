#pragma once
#include "MPAutoRegister.h"
#include "BattleManagerModuleDefine.h"
#include "BattleNetProxy.h"
#include "MPDefine.pb.h"
#include "MPModuleFactory.h"

enum eBattleAutoRegisterType
{
	eBattleManagerModule = 1,
	eBattleUserModule = 2,

};

#define BATTLE_MANAGER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eBattleManagerModule,INDEX,SUB)
#define BATTLE_USER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eBattleUserModule,INDEX,SUB)

#define BATTLE_CUR_TIME g_pBattleNetProxy->GetModule<BattleTimeManager>(eBattleMgr_Time)->CurrentTime()

#define REGISTER_GATE(CLASS,MSG,CALLBACK) g_pBattleNetProxy->AddReceiveCallBack(MP_ST_GATE,CLASS,MSG,&CALLBACK);
#define REGISTER_GAME(CLASS,MSG,CALLBACK) g_pBattleNetProxy->AddReceiveCallBack(MP_ST_GAME,CLASS,MSG,&CALLBACK);
#define REGISTER_CENTER(CLASS,MSG,CALLBACK) g_pBattleNetProxy->AddReceiveCallBack(MP_ST_CENTER,CLASS,MSG,&CALLBACK);

#define SEND2GATE(FD,MSGID,MSG) g_pBattleNetProxy->SendMsg(MP_ST_BATTLE,MP_ST_GATE,FD,MSGID,MSG);
#define SEND2GAME(FD,MSGID,MSG) g_pBattleNetProxy->SendMsg(MP_ST_BATTLE,MP_ST_GAME,FD,MSGID,MSG);
#define SEND2CENTER(FD,MSGID,MSG) g_pBattleNetProxy->SendMsg(MP_ST_BATTLE,MP_ST_CENTER,FD,MSGID,MSG);
