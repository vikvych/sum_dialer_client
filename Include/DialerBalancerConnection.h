#ifndef SAFEUM_DIALER_BALANCER_CONNECTION_H
#define SAFEUM_DIALER_BALANCER_CONNECTION_H

#include <HierarchyBase.h>
#include "Config.h"

typedef void (ClientBalancerGetAllDataCb)(void *Node, ObjectT *Servers);

typedef struct {
    bool DataWasGot;
    SizeT BalancerIterator;
    ArrayT *BalancerList;
    HWSConnectionT *HWSConnection;
    ClientBalancerGetAllDataCb *CallbackData;
    void *NodeConnection;
    TimerT ReconnectTimer;
} DialerBalancerConnectionT;

typedef struct {
    char Domain[256];
    char IP[64];
    WordT Port;
} ServerInfoT;

ErrnoT SafeUMDialerClientBalancerStart(DialerBalancerConnectionT *Balancer);
ErrnoT SafeUMDialerClientBalancerStart2(DialerBalancerConnectionT *Balancer);

DialerBalancerConnectionT *SafeUMDialerClientBalancerInit(void *Node,
                                                          ClientBalancerGetAllDataCb DialerBalancerOnGetAll);

#endif
