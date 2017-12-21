#pragma once
#include <stdint.h>

enum MP_SERVER_TYPES : int8_t
{
	MP_ST_NONE		= -1,    // NONE
	MP_ST_CENTER	= 1,
	MP_ST_SUPER		= 2,    //
	MP_ST_GATE		= 3,    //
	MP_ST_GAME		= 4,
	MP_ST_BATTLE	= 5,
	MP_ST_MATCH		= 6,
	MP_ST_MAX,

	MP_TCP_CLIENT		= 100,
	MP_RUDP_CLIENT		= 101,

};

#define SERVER_TYPE2NAME(TYPE,NAME) case TYPE: return NAME;

static const char * GetServerTypeNames(int8_t nType)
{
	switch(nType)
	{
		SERVER_TYPE2NAME(MP_ST_CENTER, "CenterServer");
		SERVER_TYPE2NAME(MP_ST_SUPER, "SuperServer");
		SERVER_TYPE2NAME(MP_ST_GATE, "GatewayServer");
		SERVER_TYPE2NAME(MP_ST_GAME, "GameServer");
		SERVER_TYPE2NAME(MP_ST_BATTLE, "BattleServer");
		SERVER_TYPE2NAME(MP_TCP_CLIENT, "TCP_Client");
		SERVER_TYPE2NAME(MP_RUDP_CLIENT, "RUDP_Client");
	default:
		return "Unknown ServerType";
	}
};

#define U32_MASK 0xFFFFFFFF
#define MAKE_U64(a, b) static_cast<uint64_t>((((static_cast<uint64_t>(a))&U32_MASK)<<32) | static_cast<uint64_t>(b&U32_MASK))
#define SPLIT_U64(a,b,x) a = x >> 32; b = x & U32_MASK;

#define U16_MASK 0xFFFF
#define MAKE_U32(a, b) static_cast<uint32_t>((((static_cast<uint32_t>(a))&U16_MASK)<<16) | static_cast<uint32_t>(b&U16_MASK))
#define SPLIT_U32(a,b,x) a = x >> 32; b = x & U16_MASK;