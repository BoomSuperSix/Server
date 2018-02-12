#pragma once
#include "ManagerModule.h"

class ItemManager : public ManagerModule
{
public:
	ItemManager();
	~ItemManager();
public:
	virtual bool Awake()override;
	virtual bool AfterAwake()override;
	virtual bool Execute()override;
	virtual bool BeforeShutDown()override;
	virtual bool ShutDown()override;
};