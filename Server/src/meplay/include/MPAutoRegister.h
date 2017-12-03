#pragma once
#include <string>
#include <map>
#include <iostream>

#define DECLEAR_AUTO_REGISTER_BASE(ClassBase) \
public: \
	typedef ClassBase *(*ClassGen)(); /* ��������ָ��*/ \
protected: \
	static std::map<uint32_t, ClassGen>& ClassBaseMap() \
	{ \
		static std::map<uint32_t, ClassGen> m_mClassBaseMap; /* �洢������Ϣ */ \
		return m_mClassBaseMap; \
	} \
	static std::map<uint32_t, std::string>& ClassNameMap() \
	{ \
		static std::map<uint32_t, std::string> m_mClassNameMap; /* �洢������Ϣ */ \
		return m_mClassNameMap; \
	} \
public: \
	static ClassBase *Create(uint32_t index) \
	{ \
	auto iter = ClassBaseMap().find(index); \
	if (ClassBaseMap().end() != iter) \
		{ \
			return ((*iter).second)(); \
		} \
		return nullptr; \
	} \
protected: \
	static void Register(uint32_t index, const std::string& name,ClassGen class_gen) /* ע�ắ�� */ \
	{ \
		ClassBaseMap().insert(std::make_pair(index, class_gen)); \
		ClassNameMap().insert(std::make_pair(index, name)); \
	} 

#define H_AUTO_REGISTER_BASE(BASE) DECLEAR_AUTO_REGISTER_BASE(BASE)

// ��������
#define DECLEAR_AUTO_REGISTER_SUB(Index,BaseClass,ClassSub) \
public: \
	struct ClassSub##Register /* ��������ע��Ľṹ�� */ \
	{ \
		ClassSub##Register() /*���캯����ע������*/ \
		{ \
			static bool bRegistered = false;  \
			if(!bRegistered) \
			{ \
				meplay::MPModule::Register(Index, #ClassSub,ClassSub::Create); \
				bRegistered = true; \
			} \
		} \
	} ; \
	static MPModule* Create() \
	{ \
		return (BaseClass*)(new ClassSub()); \
	} \
	static struct ClassSub##Register m_t##ClassSub##Register;

// ʵ������
#define IMPLEMENT_AUTO_REGISTER_SUB(ClassSub) \
	static ClassSub::ClassSub##Register m_t##ClassSub##Register;

#define H_AUTO_REGISTER_SUB(INDEX,BASE,SUB) DECLEAR_AUTO_REGISTER_SUB(INDEX,BASE,SUB)
#define CPP_AUTO_REGISTER_SUB(SUB) IMPLEMENT_AUTO_REGISTER_SUB(SUB)
