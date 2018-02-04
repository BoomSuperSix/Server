#include "MPModuleFactory.h"

MPModuleFactory::MPModuleFactory()
{
}

MPModuleFactory::~MPModuleFactory()
{
}

meplay::MPModule* MPModuleFactory::Create(uint32_t nType, uint32_t nIndex)
{
	if (auto itType = m_mCreateMap.find(nType); itType != m_mCreateMap.end())
	{
		if (auto itIndex = itType->second.find(nIndex); itIndex != itType->second.end())
		{
			return itIndex->second();
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}

const std::string& MPModuleFactory::GetName(uint32_t nType, uint32_t nIndex)const
{
	if (auto itType = m_mNameMap.find(nType); itType != m_mNameMap.end())
	{
		if (auto itIndex = itType->second.find(nIndex); itIndex != itType->second.end())
		{
			return itIndex->second;
		}
		else
		{
			return m_sNullStr;
		}
	}
	else
	{
		return m_sNullStr;
	}
}