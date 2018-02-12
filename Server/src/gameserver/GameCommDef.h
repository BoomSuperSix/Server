#pragma once
#include "MPAutoRegister.h"
#include "GameManagerModuleDefine.h"
#include "GameNetProxy.h"
#include "UserErrCode.pb.h"
#include "MPModuleFactory.h"

enum eGameAutoRegisterType
{
	eGameManagerModule	= 1,
	eGameUserModule		= 2,

};

#define GAME_MANAGER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eGameManagerModule,INDEX,SUB)
#define GAME_USER_MODULE_REG(INDEX,SUB) AUTO_REGISTER(eGameUserModule,INDEX,SUB)

#define REGISTER_GATE(CLASS,MSG,CALLBACK) g_pGameNetProxy->AddReceiveCallBack(MP_ST_GATE,CLASS,MSG,&CALLBACK);
#define REGISTER_SUPER(CLASS,MSG,CALLBACK) g_pGameNetProxy->AddReceiveCallBack(MP_ST_SUPER,CLASS,MSG,&CALLBACK);

#define SEND_USER_MSG(FD,MSGID,MSG) g_pGameNetProxy->SendMsg(MP_ST_GAME,MP_ST_GATE,FD,MSGID,MSG);
#define SEND2SUPER(FD,MSGID,MSG) g_pGameNetProxy->SendMsg(MP_ST_GAME,MP_ST_SUPER,FD,MSGID,MSG);
#define SEND2GATE(FD,MSGID,MSG) g_pGameNetProxy->SendMsg(MP_ST_GAME,MP_ST_GATE,FD,MSGID,MSG);

#define SEND_TRANS_MSG(MSGID,MSG);

#define MAKE_INT_32(a,b) ((a&0xFFFF) << 16) | (b&0xFFFF)
#define SPLIT_INT_32(a,b,x) a = x >> 16; b = x&0xFFFF;

#define MAKE_INT_64(a,b) ((((int64_t)a)&0xFFFFFFFF) << 32) | (((int64_t)b)&0xFFFFFFFF)
#define SPLIT_INT_64(a,b,x) a = x >> 32; b = x&0xFFFFFFFF;

#define GET_XML_DATA(FILE,...) g_pXmlMgr->ReadTableT_IMPL("../xml/"+std::string(FILE)+".xml", std::make_tuple(##__VA_ARGS__));