#pragma once
#include "MPAutoRegister.h"
#include "MatchManagerModuleDefine.h"
#include "MatchNetProxy.h"
#include "MPDefine.pb.h"
#include "MPModuleFactory.h"

enum eMatchAutoRegisterType
{
	eMatchManagerModule = 1,

};

#define MATCH_MANAGER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eMatchManagerModule,INDEX,SUB)
#define MATCH_USER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eMatchUserModule,INDEX,SUB)

#define MATCH_CUR_TIME g_pMatchNetProxy->GetModule<MatchTimeManager>(eMatchMgr_Time)->CurrentTime()

#define REGISTER_SUPER(CLASS,MSG,CALLBACK) g_pMatchNetProxy->AddReceiveCallBack(MP_ST_SUPER,CLASS,MSG,&CALLBACK);
#define REGISTER_CENTER(CLASS,MSG,CALLBACK) g_pMatchNetProxy->AddReceiveCallBack(MP_ST_CENTER,CLASS,MSG,&CALLBACK);

#define SEND2SUPER(FD,MSGID,MSG) g_pMatchNetProxy->SendMsg(MP_ST_MATCH,MP_ST_SUPER,FD,MSGID,MSG);
#define SEND2CENTER(FD,MSGID,MSG) g_pMatchNetProxy->SendMsg(MP_ST_MATCH,MP_ST_CENTER,FD,MSGID,MSG);
