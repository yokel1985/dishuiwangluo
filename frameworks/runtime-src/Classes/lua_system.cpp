//
//  lua_system.cpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#include "lua_system.h"


#include "CCLuaEngine.h"
#include <string>
#include <vector>
#include  "util.h"
//#include "CCScriptSupport.h"
#include "GameManger.h"
#include"tinyxml2/tinyxml2.h"
#include "xml.h"

using namespace cocos2d;
using namespace std;
using namespace tinyxml2;

LuaSystem* g_pLuaSystem = 0;


#define LogLuaStackNum(L)  CCLOG("lua stack num: %d.", lua_gettop(L));

LuaSystem* LuaSystem::getInstance()
{
    static LuaSystem _LuaSystem;
    return &_LuaSystem;
}
bool LuaSystem::init()
{
    LuaEngine* engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    
    register_All(engine->getLuaStack()->getLuaState());
    return true;
}

int LuaSystem::callLuaFunc(std::string name, int v1)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    int iRet = lua_pcall(L, 1, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    int ret = lua_tointeger(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return ret;
}
int LuaSystem::callLuaFunc(std::string name, int v1, int v2)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    lua_pushinteger(L, v2);
    int iRet = lua_pcall(L, 2, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    int ret = lua_tointeger(L, -1);
    
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return ret;
}
int LuaSystem::callLuaFunc(std::string name, const char* val)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushstring(L, val);
    int iRet = lua_pcall(L, 1, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    int ret = lua_tointeger(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return ret;
}
int	LuaSystem::callLuaFunc(std::string name, std::string& retVal)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    int iRet = lua_pcall(L, 0, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    retVal = lua_tostring(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return iRet;
}
int	LuaSystem::callLuaFunc(std::string name, int v1, std::string& retVal)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    int iRet = lua_pcall(L, 1, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    retVal = lua_tostring(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return iRet;
}
int	LuaSystem::callLuaFunc(std::string name, int v1, int v2, std::string& retVal)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    lua_pushinteger(L, v2);
    int iRet = lua_pcall(L, 2, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    retVal = lua_tostring(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return iRet;
}
int	LuaSystem::callLuaFunc(std::string name, int v1, std::string v2, std::string& retVal)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    lua_pushstring(L, v2.c_str());
    int iRet = lua_pcall(L, 2, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    retVal = lua_tostring(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return iRet;
}
int	LuaSystem::callLuaFunc(std::string name, int v1, int v2, int v3, std::string v4)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    lua_pushinteger(L, v1);
    lua_pushinteger(L, v2);
    lua_pushinteger(L, v3);
    lua_pushstring(L, v4.c_str());
    int iRet = lua_pcall(L, 4, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    int ret = lua_tointeger(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return ret;
}

/*int	LuaSystem::callLuaFunc(std::string name, int v1, int v2, std::string v3, std::string& retVal )
 {
	lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	lua_getglobal(L, name.c_str());
	lua_pushinteger(L, v1);
	lua_pushinteger(L, v2);
	lua_pushstring(L, v3.c_str());
	int iRet = lua_pcall(L, 3, 1, 0);
	if (0 != iRet)
	{
 CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
 return 0;
	}
 
	retVal = lua_tostring(L, -1);
	lua_pop(L, 1);
	LogLuaStackNum(L);
	return iRet;
 }*/

int	LuaSystem::callLuaFunc(std::string name, cocos2d::Ref* pNode, char* uType)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, name.c_str());
    tolua_pushusertype(L, pNode, uType);
    int iRet = lua_pcall(L, 1, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    iRet = lua_tointeger(L, -1);
    lua_pop(L, 1);
    LogLuaStackNum(L);
    return iRet;
}
void LuaSystem::readLuaTableItem(char* tblName, char* itemName, int& v)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, tblName);
    lua_pushstring(L, itemName);
    lua_gettable(L, -2);
    v = lua_tointeger(L, -1);
    lua_pop(L, 2);
    LogLuaStackNum(L);
}
void LuaSystem::readLuaTableItem(char* tblName, char* itemName, float& v)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, tblName);
    lua_pushstring(L, itemName);
    lua_gettable(L, -2);
    v = (float)lua_tonumber(L, -1);
    lua_pop(L, 2);
    LogLuaStackNum(L);
}
void LuaSystem::readLuaTableItem(char* tblName, char* itemName, std::string& v)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, tblName);
    lua_pushstring(L, itemName);
    lua_gettable(L, -2);
    v = lua_tostring(L, -1);
    lua_pop(L, 2);
    LogLuaStackNum(L);
}
void LuaSystem::readLuaTable(char* tblName, std::vector<std::string>& vList)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    vList.clear();
    lua_getglobal(L, tblName);
    int it = lua_gettop(L);
    lua_pushnil(L);
    //printf("Enum %s:", tblName);
    while(lua_next(L, it))
    {
        //printf("  %d", (int)lua_tonumber(L, -1));
        std::string str = lua_tostring(L, -1);
        vList.push_back(str);
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    LogLuaStackNum(L);
}
void LuaSystem::readLuaTable(char* tblName, std::vector<int>& vList)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    vList.clear();
    lua_getglobal(L, tblName);
    int it = lua_gettop(L);
    lua_pushnil(L);
    while(lua_next(L, it))
    {
        vList.push_back(lua_tointeger(L, -1));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    LogLuaStackNum(L);
}
void LuaSystem::readLuaSubTable(char* tblName, char* subTblName, std::vector<int>& vList)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    vList.clear();
    lua_getglobal(L, tblName);
    lua_pushstring(L, subTblName);
    lua_gettable(L, -2);
    
    int it = lua_gettop(L);
    lua_pushnil(L);
    while(lua_next(L, it))
    {
        vList.push_back(lua_tointeger(L, -1));
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    LogLuaStackNum(L);
}
int	LuaSystem::callFunc(const char* funcFullName, std::string& inVal, std::string& outVal)
{
    std::string strFull = funcFullName;
    std::vector<std::string> strs;
    split(strFull, '.', strs);
    if (strs.size() > 1)
        return callFunc(strs[0].c_str(), strs[1].c_str(), inVal, outVal);
    return callFunc(0, strs[0].c_str(), inVal, outVal);
}
int	LuaSystem::callFunc(const char* tblName,const char* funcName, std::string& inVal, std::string& outVal)
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    if (tblName) {
        lua_getglobal(L, tblName);
        lua_getfield(L, -1, funcName);
    } else {
        lua_getglobal(L, funcName);
    }
    lua_pushstring(L, inVal.c_str());
    
    int iRet = lua_pcall(L, 1, 1, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed:%s\n", lua_tostring(L, -1));
        return 0;
    }
    
    const char* oStr = lua_tostring(L, -1);
    if (oStr) outVal = oStr;
    
    if (tblName) {
        lua_pop(L, 2);
    } else {
        lua_pop(L, 1);
    }
    LogLuaStackNum(L);
    return 0;
}
///////////////////////////////////////////////////////////////////
//
static int cpp_Add(lua_State* L)
{
    //int nArg = lua_gettop(L);
    //int a = lua_tointeger(L, -1);
    //int b = lua_tointeger(L, -2);
    //int ret = a + b;
    //lua_pushinteger(L, ret);
    //return 1;
    //TTFConfig cfg("fonts/msyh.ttf", 24);
    //FontAtlas* f = cocos2d::FontAtlasCache::getFontAtlasTTF(cfg);
    /*auto ss = f->getTextures();
     for (auto i:ss)
     {
     
     i.second->initWithData();
     Texture2D* pTet;
     Image* img = new Image;
     img->initWithRawData(pTet->
     img->saveToFile("1.png");
     
     auto rtt = RenderTexture::create(1136,640, Texture2D::PixelFormat::RGBA8888);
     rtt->begin();
     rtt->visit();
     rtt->end();
     }*/
    //f->getLetterDefinitionForChar()
    return 0;
}

// export lua
static int cpp_getDeviceSN(lua_State* L)
{
    return 1;
}
static int cpp_startBattleScene(lua_State* L)
{
    return 0;
}
static int cpp_BackSpace(lua_State* L)
{
    IMEDispatcher::sharedDispatcher()->dispatchDeleteBackward();
    return 0;
}
static int cpp_endBattle(lua_State* L)
{
    return 0;
}
static int cpp_playEffect(lua_State* L)
{
    return 0;
}
static int cpp_addEnergy(lua_State* L)
{
    return 0;
}
static int cpp_showEnergy(lua_State* L)
{
    return 0;
}
static int cpp_addHp(lua_State* L)
{
    return 0;
}
static int cpp_addStep(lua_State* L)
{
    return 0;
}

static int cpp_addArmy(lua_State* L)
{
    return 0;
}
static int cpp_addArmyList(lua_State* L)
{
    return 0;
}
static int cpp_state(lua_State* L)
{
    return 0;
}
static int cpp_pauseBattle(lua_State* L)
{
    return 0;
}
static int cpp_continueBattle(lua_State* L)
{
    return 0;
}
static int cpp_log(lua_State* L)
{
    return 0;
}
static int cpp_getSystemInfo(lua_State* L)
{
    return 1;
}
static int cpp_unloadTextures(lua_State* L)
{
    int nArg = lua_gettop(L);
    if (nArg == 1)
    {
        cocos2d::Node* pNode = (cocos2d::Node*)tolua_tousertype(L, -1, 0);
        //if (pNode)
        //XImageLoading::getInstance()->unloadTextures(pNode);
    }
    return 0;
}
static int cpp_reloadTextures(lua_State* L)
{
    //XImageLoading::getInstance()->reloadTextures(0);
    return 0;
}
static int cpp_AI(lua_State* L)
{
    return 0;
}
static int cpp_umlog(lua_State* L)
{
    return 0;
};
static int cpp_battleResume(lua_State* L)
{
    return 0;
};
static int cpp_battlePause(lua_State* L)
{
    return 0;
};
static int cpp_battleEndGuider(lua_State* L)
{
    return 0;
};
int cpp_battleTouchFunc(lua_State* L)
{
    return 0;
};
int cpp_battleDelete(lua_State* L)
{
    return 0;
};
int cpp_battleSelSpec(lua_State* L)
{
    return 0;
};
int cpp_battleShowGrid(lua_State* L)
{
    return 0;
}
int cpp_btShowArmys(lua_State* L)
{
    return 0;
}
int cpp_btDoSpell(lua_State* L)
{
    return 1;
}
int cpp_efftest(lua_State* L)
{
    return 0;
}
// lua net system

// class TiXmlDocument
int cpp_TiXmlDocument_new(lua_State* L)
{
    tinyxml2::XMLDocument * pDoc = new tinyxml2::XMLDocument();
    tolua_pushusertype(L, pDoc, "TiXmlDocument");
    return 1;
}
int cpp_TiXmlDocument_delete(lua_State* L)
{
    tinyxml2::XMLDocument* pObj = (tinyxml2::XMLDocument*)tolua_tousertype(L, 1, 0);
    if (pObj)
        delete pObj;
    return 0;
}
int cpp_TiXml_NullDestroy(lua_State* L)
{
    return 0;
}
int cpp_TiXmlDocument_Parse(lua_State* L)
{
    tinyxml2::XMLDocument* pObj = (tinyxml2::XMLDocument*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        bool ret = CocosLoadXMLDoc(str, *pObj);
        lua_pushboolean(L, ret);
        return 1;
    }
    return 0;
}
int cpp_TiXmlDocument_FirstChildElement(lua_State* L)
{
    tinyxml2::XMLDocument* pObj = (tinyxml2::XMLDocument*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==0)
    {
        tinyxml2::XMLElement* pAtt = pObj->FirstChildElement();
        tolua_pushusertype(L, pAtt, "TiXmlElement");
        return 1;
    }
    else if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        tinyxml2::XMLElement* pAtt = pObj->FirstChildElement(str.c_str());
        tolua_pushusertype(L, pAtt, "TiXmlElement");
        return 1;
    }
    return 0;
}
// class TiXmlElement
int cpp_TiXmlElement_FirstChildElement(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==0)
    {
        tinyxml2::XMLElement* pEle = pObj->FirstChildElement();
        tolua_pushusertype(L, pEle, "TiXmlElement");
        return 1;
    }
    else if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        tinyxml2::XMLElement* pEle = pObj->FirstChildElement(str.c_str());
        tolua_pushusertype(L, pEle, "TiXmlElement");
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_NextSiblingElement(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==0)
    {
        tinyxml2::XMLElement* pEle = pObj->NextSiblingElement();
        tolua_pushusertype(L, pEle, "TiXmlElement");
        return 1;
    }
    else if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        tinyxml2::XMLElement* pNext = pObj->NextSiblingElement(str.c_str());
        tolua_pushusertype(L, pNext, "TiXmlElement");
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_FirstAttribute(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    if (pObj)
    {
        const tinyxml2::XMLAttribute* pAtt = pObj->FirstAttribute();
        tolua_pushusertype(L, (void*)pAtt, "TiXmlAttribute");
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_Attribute(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        std::string val = pObj->Attribute(str.c_str());
        lua_pushstring(L, val.c_str());
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_Attribute_Int(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        int val = atoi( pObj->Attribute(str.c_str()) );
        lua_pushinteger(L, val);
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_Attribute_Float(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==1)
    {
        std::string str = lua_tostring(L, 2);
        lua_Number val = atof( pObj->Attribute(str.c_str()) );
        lua_pushnumber(L, val);
        return 1;
    }
    return 0;
}
int cpp_TiXmlElement_FindChild(lua_State* L)
{
    tinyxml2::XMLElement* pObj = (tinyxml2::XMLElement*)tolua_tousertype(L, 1, 0);
    int argc = lua_gettop(L) - 1;
    if (pObj && argc==2)
    {
        std::string key = lua_tostring(L, 2);
        //int id = lua_tointeger(L, 3);
        int id = lua_tonumber(L, 3);
        tinyxml2::XMLElement* pEle = pObj->FirstChildElement();
        while (pEle)
        {
            const char* sPro = pEle->Attribute(key.c_str());
            if (sPro)
            {
                int val = atoi(sPro);
                if (val == id)
                    break;
            }
            pEle = pEle->NextSiblingElement();
        }
        tolua_pushusertype(L, pEle, "TiXmlElement");
        return 1;
    }
    return 0;
}
// class TiXmlAttribute
int cpp_TiXmlAttribute_Name(lua_State* L)
{
    tinyxml2::XMLAttribute* pObj = (tinyxml2::XMLAttribute*)tolua_tousertype(L, 1, 0);
    if (pObj)
    {
        std::string str = pObj->Name();
        lua_pushstring(L, str.c_str());
        return 1;
    }
    return 0;
}
int cpp_TiXmlAttribute_Value(lua_State* L)
{
    tinyxml2::XMLAttribute* pObj = (tinyxml2::XMLAttribute*)tolua_tousertype(L, 1, 0);
    if (pObj)
    {
        std::string str = pObj->Value();
        lua_pushstring(L, str.c_str());
        return 1;
    }
    return 0;
}
int cpp_TiXmlAttribute_Next(lua_State* L)
{
    tinyxml2::XMLAttribute* pObj = (tinyxml2::XMLAttribute*)tolua_tousertype(L, 1, 0);
    if (pObj)
    {
        const tinyxml2::XMLAttribute* pAtt = pObj->Next();
        tolua_pushusertype(L, (void*)pAtt, "TiXmlAttribute");
        return 1;
    }
    return 0;
}
// class Effect
int cpp_Effect_create(lua_State* L)
{
    return 0;
}
int cpp_Effect_play(lua_State* L)
{
    return 0;
}
int cpp_Effect_preLoadRes(lua_State* L)
{
    return 0;
}
// class SoundManager
int cpp_SoundManager_getInstance(lua_State* L)
{
    return 1;
}
int cpp_SoundManager_playMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_stopMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_pauseMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_continueMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_playEffect(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_stopEffect(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_enableMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_isEnableMusic(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_enableEffect(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_isEnableEffect(lua_State* L)
{
    return 0;
}
int cpp_SoundManager_isPlayingMusic(lua_State* L)
{
    return 0;
}


//class MissionTriggerManager
int cpp_MissionTriggerManager_getInstance(lua_State* L)
{
    return 1;
}

int cpp_MissionTriggerManager_init(lua_State* L)
{
    return 0;
}

////////////////////////////////////////////////////////////////////////////
static int lua_cocos2dx_createDir(lua_State* L)
{
    return 0;
}

static int lua_cocos2dx_createDownloadDir(lua_State* L)
{
    return 0;
}

static int lua_cocos2dx_deleteDownloadDir(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    if (1 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isstring(L, 1, 0, &tolua_err)) goto tolua_lerror;
#endif
        std::string pathToSave = tolua_tostring(L, 1, "");
        
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        std::string command = "rm -rf ";
        // Path may include space.
        command += "\"" + pathToSave + "\"";
        system(command.c_str());
#else
        std::string command = "rd /s /q ";
        // Path may include space.
        command += "\"" + pathToSave + "\"";
        system(command.c_str());
#endif
        return 0;
    }
    
    CCLOG("'resetDownloadDir' function wrong number of arguments: %d, was expecting %d\n", argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'resetDownloadDir'.",&tolua_err);
    return 0;
#endif
}

static int lua_cocos2dx_addSearchPath(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
    if (2 == argc)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_isstring(L, 1, 0, &tolua_err) ||
            !tolua_isboolean(L, 2, 0, &tolua_err))
            goto tolua_lerror;
#endif
        std::string pathToSave = tolua_tostring(L, 1, "");
        bool before           = tolua_toboolean(L, 2, 0);
        std::vector<std::string> searchPaths = FileUtils::getInstance()->getSearchPaths();
        if (before)
        {
            searchPaths.insert(searchPaths.begin(), pathToSave);
        }
        else
        {
            searchPaths.push_back(pathToSave);
        }
        
        FileUtils::getInstance()->setSearchPaths(searchPaths);
        
        return 0;
    }
    CCLOG("'addSearchPath' function wrong number of arguments: %d, was expecting %d\n", argc, 2);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(L,"#ferror in function 'addSearchPath'.",&tolua_err);
    return 0;
#endif
}
static int cpp_deleteFile(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    if (1 == argc)
    {
        std::string fileDel = tolua_tostring(L, 1, "");
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
        std::string command = "rm -rf ";
        // Path may include space.
        command += "\"" + fileDel + "\"";
        system(command.c_str());
#else
        std::string command = "rd /s /q ";
        // Path may include space.
        command += "\"" + fileDel + "\"";
        if (0 != system(command.c_str())) {
            remove(fileDel.c_str());//a file
        }
#endif
        return 0;
    }
    
    return 0;
}
static int cpp_unzipFile(lua_State* L)
{
    int argc = lua_gettop(L);
    if (argc == 3)
    {
        std::string s1 = lua_tostring(L, 1);
        std::string s2 = lua_tostring(L, 2);
        std::string s3 = lua_tostring(L, 3);
        ssize_t len;
        unsigned char* buff = FileUtils::getInstance()->getFileDataFromZip(s1.c_str(), s2.c_str(), &len);
        FILE *out = fopen(s3.c_str(), "wb");
        fwrite(buff, 1, len, out);
        fclose(out);
    }
    return 0;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
int cpp_ios_pay(lua_State* L)
{
    return 0;
}

int cpp_ios_CanPay(lua_State* L)
{
    if (nullptr == L)
        return 0;
    int argc = lua_gettop(L);
    if (argc == 1)
    {
        std::string str = lua_tostring(L, 1);
        //void _ios_pay(char* buyType, int num);
        //_ios_pay((char*)str.c_str(), 1);
    }
    return 0;
}

#endif

static int cpp_setGText(lua_State* L)
{
    return 0;
}
int cpp_tobattleScene(lua_State* L)
{
    CCLOG("TO CPP BATTLESCENE ");
    
    GameManager::getInstance()->initBattleScene();
    
    return 0;
}
int cpp_getXMLData(lua_State* L)
{
    //xml::getInstance()->init(fileName);
    CCLOG("open xml data");
    int n = lua_gettop(L);
    //lua_tolstring(L, 6, sizeof("tr  "));
    cout<<"参数的值"<<endl;
    cout<<lua_tonumber(L,1)<<endl;
    for (int i =1; i !=n; ++i) {
        cout<<lua_tonumber(L, i)<<endl;

    }
    CCLOG("参数的个数：%d",n);
//    lua_State *LL = luaL_newstate();
//    lua_getglobal(LL,"Loading.tbl");
//    lua_getfield(LL,-1,"name");
    string str = lua_tostring(L,-1);
    cout<<"tbl:name = "<<str.c_str()<<endl;
    
    
    lua_pushnumber(L,123456789);
    lua_pushfstring(L, "cpp to lua ++++++++");
    return 2;
}
// regist Class to Lua
int lua_regist_MyClass(lua_State* tolua_S)
{
    lua_State* L = tolua_S;
    tolua_module(L, 0, 0);
    tolua_beginmodule(L, 0);
    
    tolua_usertype(L, "TiXmlDocument");
    tolua_cclass(L, "TiXmlDocument", "TiXmlDocument", "", cpp_TiXml_NullDestroy);
    tolua_beginmodule(L, "TiXmlDocument");
    tolua_function(L, "new", cpp_TiXmlDocument_new);
    tolua_function(L, "delete", cpp_TiXmlDocument_delete);
    tolua_function(L, "Parse", cpp_TiXmlDocument_Parse);
    tolua_function(L, "FirstChildElement", cpp_TiXmlDocument_FirstChildElement);
    tolua_endmodule(L);
    
    tolua_usertype(L, "TiXmlElement");
    tolua_cclass(L, "TiXmlElement", "TiXmlElement", "", cpp_TiXml_NullDestroy);
    tolua_beginmodule(L, "TiXmlElement");
    tolua_function(L, "FirstChildElement", cpp_TiXmlElement_FirstChildElement);
    tolua_function(L, "NextSiblingElement", cpp_TiXmlElement_NextSiblingElement);
    tolua_function(L, "FirstAttribute", cpp_TiXmlElement_FirstAttribute);
    tolua_function(L, "Attribute", cpp_TiXmlElement_Attribute);
    tolua_function(L, "Get", cpp_TiXmlElement_Attribute);// rename
    tolua_function(L, "GetString", cpp_TiXmlElement_Attribute);// rename
    tolua_function(L, "GetInt", cpp_TiXmlElement_Attribute_Int);// rename
    tolua_function(L, "GetFloat", cpp_TiXmlElement_Attribute_Float);// rename
    tolua_function(L, "FindChild", cpp_TiXmlElement_FindChild);//to do ...(map)
    tolua_endmodule(L);
    
    tolua_usertype(L, "TiXmlAttribute");
    tolua_cclass(L, "TiXmlAttribute", "TiXmlAttribute", "", cpp_TiXml_NullDestroy);
    tolua_beginmodule(L, "TiXmlAttribute");
    tolua_function(L, "Name", cpp_TiXmlAttribute_Name);
    tolua_function(L, "Value", cpp_TiXmlAttribute_Value);
    tolua_function(L, "Next", cpp_TiXmlAttribute_Next);
    tolua_endmodule(L);
    
    tolua_usertype(L, "Effect");
    tolua_cclass(L, "Effect", "Effect", "cc.Node", nullptr);
    tolua_beginmodule(L, "Effect");
    tolua_function(L, "create", cpp_Effect_create);
    tolua_function(L, "play", cpp_Effect_play);
    tolua_function(L, "preLoadRes", cpp_Effect_preLoadRes);
    tolua_endmodule(L);
    
    tolua_usertype(L, "SoundManager");
    tolua_cclass(L, "SoundManager", "SoundManager", "", nullptr);
    tolua_beginmodule(L, "SoundManager");
    tolua_function(L, "getInstance", cpp_SoundManager_getInstance);
    tolua_function(L, "playMusic", cpp_SoundManager_playMusic);
    tolua_function(L, "stopMusic", cpp_SoundManager_stopMusic);
    tolua_function(L, "pauseMusic", cpp_SoundManager_pauseMusic);
    tolua_function(L, "continueMusic", cpp_SoundManager_continueMusic);
    tolua_function(L, "playEffect", cpp_SoundManager_playEffect);
    tolua_function(L, "stopEffect", cpp_SoundManager_stopEffect);
    tolua_function(L, "enableMusic", cpp_SoundManager_enableMusic);
    tolua_function(L, "isEnableMusic", cpp_SoundManager_isEnableMusic);
    tolua_function(L, "enableEffect", cpp_SoundManager_enableEffect);
    tolua_function(L, "isEnableEffect", cpp_SoundManager_isEnableEffect);
    tolua_function(L, "isPlayingMusic", cpp_SoundManager_isPlayingMusic);
    tolua_endmodule(L);
    
    tolua_usertype(L,"MissionTriggerManager");
    tolua_cclass(L, "MissionTriggerManager", "MissionTriggerManager", "", nullptr);
    tolua_beginmodule(L, "MissionTriggerManager");
    tolua_function(L, "getInstance", cpp_MissionTriggerManager_getInstance);
    tolua_function(L, "init", cpp_MissionTriggerManager_init);
    tolua_endmodule(L);
    
    
    //tolua_endmodule(L);
    
    return 1;
}
//////////////////////////////////////////////////////////////////////////
//
int LuaSystem::register_All(lua_State* L)
{
    lua_register(L, "cpp_Add", cpp_Add);
    lua_register(L, "cpp_getDeviceSN", cpp_getDeviceSN);
    lua_register(L, "cpp_startBattleScene", cpp_startBattleScene);
    lua_register(L, "cpp_BackSpace", cpp_BackSpace);
    lua_register(L, "cpp_endBattle", cpp_endBattle);
    lua_register(L, "cpp_playEffect", cpp_playEffect);
    lua_register(L, "cpp_addEnergy", cpp_addEnergy);
    lua_register(L, "cpp_showEnergy", cpp_showEnergy);
    lua_register(L, "cpp_addHp", cpp_addHp);
    lua_register(L, "cpp_addStep", cpp_addStep);
    lua_register(L, "cpp_addArmy", cpp_addArmy);
    lua_register(L, "cpp_addArmyList", cpp_addArmyList);
    lua_register(L, "cpp_state", cpp_state);
    lua_register(L, "cpp_pauseBattle", cpp_pauseBattle);
    lua_register(L, "cpp_continueBattle", cpp_continueBattle);
    lua_register(L, "cpp_log", cpp_log);
    lua_register(L, "cpp_getSystemInfo", cpp_getSystemInfo);
    lua_register(L, "cpp_unloadTextures", cpp_unloadTextures);
    lua_register(L, "cpp_reloadTextures", cpp_reloadTextures);
    lua_register(L, "cpp_AI", cpp_AI);
    lua_register(L, "cpp_umlog", cpp_umlog);
    lua_register(L, "cpp_battleResume", cpp_battleResume);
    lua_register(L, "cpp_battlePause", cpp_battlePause);
    lua_register(L, "cpp_battleEndGuider", cpp_battleEndGuider);
    lua_register(L, "cpp_battleTouchFunc", cpp_battleTouchFunc);
    lua_register(L, "cpp_battleDelete", cpp_battleDelete);
    lua_register(L, "cpp_battleSelSpec", cpp_battleSelSpec);
    lua_register(L, "cpp_battleShowGrid", cpp_battleShowGrid);
    lua_register(L, "cpp_btShowArmys", cpp_btShowArmys);
    lua_register(L, "cpp_btDoSpell", cpp_btDoSpell);
    lua_register(L, "cpp_efftest", cpp_efftest);
    
    lua_register(L, "cpp_createDir", lua_cocos2dx_createDir);
    lua_register(L, "cpp_createDownloadDir", lua_cocos2dx_createDownloadDir);
    lua_register(L, "cpp_deleteDownloadDir", lua_cocos2dx_deleteDownloadDir);
    lua_register(L, "cpp_addSearchPath", lua_cocos2dx_addSearchPath);
    lua_register(L, "cpp_deleteFile", cpp_deleteFile);
    lua_register(L, "cpp_unzipFile", cpp_unzipFile);
    lua_register(L, "cpp_setGText", cpp_setGText);
    lua_register(L, "cpp_tobattleScene", cpp_tobattleScene);
    lua_register(L,"cpp_getXMLData",cpp_getXMLData);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //g_pLuaSystem->register_third(L);
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    lua_register(L, "cpp_ios_pay", cpp_ios_pay);
#endif
    
    lua_regist_MyClass(L);
    
    return 0;
}

bool LuaSystem::startMainCity()
{
    lua_State* L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
    lua_getglobal(L, "uimain_start");
    int iRet = lua_pcall(L, 0, 0, 0);
    if (0 != iRet)
    {
        CCLOG("lua_pcall failed\n");
        return false;
    }
    return true;
}



