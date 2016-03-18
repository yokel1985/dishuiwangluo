//
//  lua_system.hpp
//  DISHUI
//
//  Created by apple on 16/3/16.
//
//

#ifndef lua_system_hpp
#define lua_system_hpp

#include <stdio.h>

#include "cocos2d.h"
#include <string>
#include <vector>


using namespace cocos2d;

class LuaSystem : public Ref
{
public:
    //LuaSystem();
    static LuaSystem* getInstance();
    bool	init();
    int		register_All(lua_State* L);
    int		register_third(lua_State* L);
    bool	startMainCity();
   // bool	lua_onRetMsg(MsgPack* msg);
    
    int		callLuaFunc(std::string name, int v1);
    int		callLuaFunc(std::string name, int v1, int v2);
    int		callLuaFunc(std::string name, const char* val);
    int		callLuaFunc(std::string name, cocos2d::Ref* pNode, char* uType);
    
    int		callLuaFunc(std::string name, std::string& retVal);
    int		callLuaFunc(std::string name, int v1, std::string& retVal);
    int		callLuaFunc(std::string name, int v1, int v2, std::string& retVal);
    int		callLuaFunc(std::string name, int v1, std::string v2, std::string& retVal);
    int		callLuaFunc(std::string name, int v1, int v2, int v3, std::string v4);
    
    
    void	readLuaTableItem(char* tblName, char* itemName, int& v);
    void	readLuaTableItem(char* tblName, char* itemName, float& v);
    void	readLuaTableItem(char* tblName, char* itemName, std::string& v);
    
    void	readLuaTable(char* tblName, std::vector<std::string>& vList);
    void	readLuaTable(char* tblName, std::vector<int>& vList);
    
    void	readLuaSubTable(char* tblName, char* subTblName, std::vector<int>& vList);
    
    int		callFunc(const char* funcFullName, std::string& inVal, std::string& outVal);
    int		callFunc(const char* tblName, const char* funcName, std::string& inVal, std::string& outVal);
    
protected:
    void	_test();
    
};
extern LuaSystem*	g_pLuaSystem;

#endif /* lua_system_hpp */
