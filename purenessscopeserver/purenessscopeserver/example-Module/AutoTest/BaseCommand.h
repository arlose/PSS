#pragma once

#include "IBuffPacket.h"
#include "ClientCommand.h"
#include "IObject.h"

#include <string>

//定义客户端信令(TCP)
#define COMMAND_AUTOTEST_HEAD         0x5000   //带头返回数据包
#define COMMAND_AUTOTEST_NOHEAD       0x5001   //不带头数据包
#define COMMAND_AUTOTEST_HEADBUFF     0x5002   //带头缓冲数据包
#define COMMAND_AUTOTEST_NOHEADBUFF   0x5003   //不带头缓冲数据包

#define COMMAND_AUTOTEST_RETUEN_HEAD         0xf000   
#define COMMAND_AUTOTEST_RETUEN_NOHEAD       0xf001
#define COMMAND_AUTOTEST_RETUEN_HEADBUFF     0xf002
#define COMMAND_AUTOTEST_RETUEN_NOHEADBUFF   0xf003

using namespace std;

class CBaseCommand : public CClientCommand
{
public:
	CBaseCommand(void);
	~CBaseCommand(void);

	int DoMessage(IMessage* pMessage, bool& bDeleteFlag);
	void SetServerObject(CServerObject* pServerObject);

private:
	bool Do_Head(IMessage* pMessage);            //返回包含头的数据包
	bool Do_NoHead(IMessage* pMessage);          //返回不包含头的数据包
	bool Do_HeadBuff(IMessage* pMessage);        //返回包含缓冲的数据包头的数据包
	bool Do_NoHeadBuff(IMessage* pMessage);      //返回不包含数据包头的数据包


private:
	CServerObject* m_pServerObject;
	int            m_nCount;
};
