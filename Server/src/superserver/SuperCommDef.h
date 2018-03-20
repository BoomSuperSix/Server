#pragma once
#include "MPAutoRegister.h"
#include "SuperManagerModuleDefine.h"
#include "SuperNetProxy.h"
#include "MPDefine.pb.h"
#include "MPModuleFactory.h"

enum eSuperAutoRegisterType
{
	eSuperManagerModule = 1,
	eSuperUserModule = 2,

};

#define SUPER_MANAGER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eSuperManagerModule,INDEX,SUB)
#define SUPER_USER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eSuperUserModule,INDEX,SUB)

#define SUPER_CUR_TIME g_pSuperNetProxy->GetModule<SuperTimeManager>(eSuperMgr_Time)->CurrentTime()

#define REGISTER_GATE(CLASS,MSG,CALLBACK) g_pSuperNetProxy->AddReceiveCallBack(MP_ST_GATE,CLASS,MSG,&CALLBACK);
#define REGISTER_GAME(CLASS,MSG,CALLBACK) g_pSuperNetProxy->AddReceiveCallBack(MP_ST_GAME,CLASS,MSG,&CALLBACK);
#define REGISTER_CENTER(CLASS,MSG,CALLBACK) g_pSuperNetProxy->AddReceiveCallBack(MP_ST_CENTER,CLASS,MSG,&CALLBACK);

#define REGISTER_HTTP(PATH,CLASS,CALLBACK) g_pSuperNetProxy->AddHttpCallBack(MP_ST_GAME,CLASS,PATH,&CALLBACK);

#define SEND2GATE(FD,MSGID,MSG) g_pSuperNetProxy->SendMsg(MP_ST_SUPER,MP_ST_GATE,FD,MSGID,MSG);
#define SEND2GAME(FD,MSGID,MSG) g_pSuperNetProxy->SendMsg(MP_ST_SUPER,MP_ST_GAME,FD,MSGID,MSG);
#define SEND2CENTER(FD,MSGID,MSG) g_pSuperNetProxy->SendMsg(MP_ST_SUPER,MP_ST_CENTER,FD,MSGID,MSG);
