#pragma once

#include <unordered_map>
#include <functional>
#include <tuple>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidjson/rapidjson.h"
#include "MPSingleton.h"
#include "MPLogger.h"

using namespace rapidxml;

typedef std::function<bool()> XML_FUNC_TYPE;

typedef std::vector<std::vector<std::string>> XML_DATA_TYPE;

class XmlManager
{
public:
	MP_SINGLETON_DECLARE(XmlManager);
public:
	bool ReadNode(xml_node<>* pDataNode, std::vector<std::string>& vData, const char * pNodeName);

	template<typename Tuple, std::size_t... Index>
	decltype(auto) ReadDataT_IMPL(xml_node<>* pTableNode, XML_DATA_TYPE& vData, Tuple&& tp, std::index_sequence<Index...>)
	{
		auto pDataNode = pTableNode->first_node("DATA");
		for (; pDataNode != nullptr; pDataNode = pDataNode->next_sibling())
		{
			std::vector<std::string> vSingleData;
			(ReadNode(pDataNode, vSingleData, (std::get<Index>(tp))), ...);
			vData.emplace_back(vSingleData);
		}
	}

	template<typename Tuple>
	decltype(auto) ReadTableT_IMPL(std::string& sFileName, Tuple&& tNames)
	{
		MP_INFO("Start read table %s.", sFileName.c_str());
		XML_DATA_TYPE vDatas;
		file<> fdoc(sFileName.c_str());
		xml_document<> doc;
		doc.parse<0>(fdoc.data());
		auto pTableNode = doc.first_node("TABLE");
		for (; pTableNode != nullptr; pTableNode = pTableNode->next_sibling())
		{
			constexpr auto size = std::tuple_size<typename std::decay_t<Tuple>>::value;
			ReadDataT_IMPL(pTableNode, vDatas, std::forward<Tuple>(tNames), std::make_index_sequence<size>{});
		}

		MP_INFO("Finish read table %s.", sFileName.c_str());
		return vDatas;
	}


	/*bool ReadXml(
		const std::string& sFile,
		std::vector<std::string>& vInfo,
		std::tuple<*/
public:
	static bool ParseJson2Xml(const std::string& sData);
	static bool ParseXml2Json(const std::string& file);
private:
};
#define g_pXmlMgr XmlManager::GetInstance()