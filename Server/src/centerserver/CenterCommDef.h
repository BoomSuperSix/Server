#pragma once
#include "MPAutoRegister.h"
#include "CenterManagerModuleDefine.h"
#include "CenterNetProxy.h"
#include "MPDefine.pb.h"
#include "MPModuleFactory.h"

enum eCenterAutoRegisterType
{
	eCenterManagerModule = 1,
	eCenterUserModule = 2,

};

#define CENTER_MANAGER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eCenterManagerModule,INDEX,SUB)
#define CENTER_USER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eCenterUserModule,INDEX,SUB)

#define CENTER_CUR_TIME g_pCenterNetProxy->GetModule<CenterTimeManager>(eCenterMgr_Time)->CurrentTime()

#define REGISTER_GATE(CLASS,MSG,CALLBACK) g_pCenterNetProxy->AddReceiveCallBack(MP_ST_GATE,CLASS,MSG,&CALLBACK);
#define REGISTER_GAME(CLASS,MSG,CALLBACK) g_pCenterNetProxy->AddReceiveCallBack(MP_ST_GAME,CLASS,MSG,&CALLBACK);
#define REGISTER_CENTER(CLASS,MSG,CALLBACK) g_pCenterNetProxy->AddReceiveCallBack(MP_ST_CENTER,CLASS,MSG,&CALLBACK);

#define SEND2GATE(FD,MSGID,MSG) g_pCenterNetProxy->SendMsg(MP_ST_CENTER,MP_ST_GATE,FD,MSGID,MSG);
#define SEND2GAME(FD,MSGID,MSG) g_pCenterNetProxy->SendMsg(MP_ST_CENTER,MP_ST_GAME,FD,MSGID,MSG);
#define SEND2CENTER(FD,MSGID,MSG) g_pCenterNetProxy->SendMsg(MP_ST_CENTER,MP_ST_CENTER,FD,MSGID,MSG);
