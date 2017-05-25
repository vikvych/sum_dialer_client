#ifndef SAFEUM_DIALER_NODE_CONNECTION_H
#define SAFEUM_DIALER_NODE_CONNECTION_H

#include <HierarchyBase.h>
#include "DialerBalancerConnection.h"

typedef void (DialerNodeOpenCb)(char *Address);
typedef void (DialerNodeCloseCb)(char *Address);

typedef void (DialerNodeIncomingCallCb)();
typedef void (DialerNodeCallStartCb)();
typedef void (DialerNodeCallEndCb)();

typedef struct {
    DialerNodeOpenCb *OpenCb;
    DialerNodeCloseCb *CloseCb;
    void *Argument;
    //ObjectT *SIPCalls;
    //ObjectT ActiveCall;
    //DialerNodeIncomingCallCb OnIncomingCall;
    //DialerNodeCallStartCb OnCallStart;
    //DialerNodeCallEndCb OnCallEnd;
    SizeT ErrorOnCurrentNode;
    ServerInfoT CurrentNode;

    SizeT NodeIterator;

    ObjectT *TempServers;
    ArrayT *TempBalancers;
    ArrayT *TempNodes;
    ArrayT *TempTurns;

    DialerBalancerConnectionT *BalancerConnection;
    HWSConnectionT *HWSConnection;
    char ConfigLastNodeFilePath[256];
    char ConfigServersFilePath[256];

    TimerT ReconnectTimer;
    TimerT ReconnectTimerBalancer;
} DialerNodeConnectionT;

ErrnoT DialerNodeConnectionServersLoad(DialerNodeConnectionT *Node);

ErrnoT DialerNodeConnectionServersSave(DialerNodeConnectionT *Node,
                                       ObjectT *Data);

ErrnoT DialerNodeConnectionLastNodeLoad(DialerNodeConnectionT *Node);

ErrnoT DialerNodeConnectionLastNodeSave(DialerNodeConnectionT *Node);

ErrnoT DialerNodeConnectionConnect(DialerNodeConnectionT *Node);

DialerNodeConnectionT *DialerNodeConnectionInit(char *ConfigLastNodeFilePath,
                                                char *ConfigServersFilePath,
                                                DialerNodeOpenCb OpenCb,
                                                DialerNodeCloseCb CloseCb,
                                                void *Argument);

ErrnoT DialerNodeConnectionStart(DialerNodeConnectionT *Node);

#endif
