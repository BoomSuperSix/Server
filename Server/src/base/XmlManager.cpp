#include "XmlManager.h"

MP_SINGLETON_IMPLEMENT(XmlManager);

XmlManager::XmlManager()
{
	
}

XmlManager::~XmlManager()
{
}

bool XmlManager::ParseJson2Xml(const std::string& sData)
{
	return 0;
}

bool XmlManager::ParseXml2Json(const std::string& file)
{
	return true;
}

bool XmlManager::ReadNode(xml_node<>* pDataNode, std::vector<std::string>& vData, const char * pNodeName)
{
	auto pNameNode = pDataNode->first_node(pNodeName);
	if (pNameNode == nullptr)
	{
		vData.emplace_back("");
		MP_ERROR("Node %s not found!", pNodeName);
		return false;
	}
	vData.emplace_back(pNameNode->value());
	return true;
}