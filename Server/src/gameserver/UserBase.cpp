#include "UserBase.h"

UserBase::UserBase() : UserModule(eGameUser_Base)
{
}

UserBase::~UserBase()
{
}

bool UserBase::UserAwake()
{
	return true;
}
bool UserBase::UserAfterAwake()
{
	return true;
}
bool UserBase::UserExecute()
{
	return true;
}
bool UserBase::UserBeforeShutDown()
{
	return true;
}
bool UserBase::UserShutDown()
{
	return true;
}