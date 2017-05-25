#ifndef SAFEUM_DIALERCLIENT_T_H
#define SAFEUM_DIALERCLIENT_T_H

#include <HierarchyBase.h>
#include "./DialerNodeConnection.h"

typedef struct {
    char Host[256];
    WordT Port;
    char Path[256];
} SafeUMDialerNodeT;

typedef struct {
    char DeviceUID[1024];
    char DeviceName[1024];
    char OSVersion[32];
    char Locale[8];
    char SoftwareVersion[32];
    ByteT GMTNumber;
    char PushUID[1024];

    DWordT QueryId;

    ObjectT *MessageStack;

    BinaryTreeT *CbStack;
    BinaryTreeT *QueryStack;

    void *OpenCb;
    void *CloseCb;

    void *IncomingCallCb;

    void *EarlyMediaCallCb;
    void *AnswerCallCb;
    void *ByeCallCb;
    void *ErrorCallCb;

    HWSConnectionT *NodeConnection;
    TimerT NodeConnectionTimer;
    HWSConnectionT *BalancerConnection;

    PollingLoopSignalCb *SignalCb;

    HWSConnectionT *HWSNodeClient;
    HWSConnectionT *HWSBalancerClient;
    DialerNodeConnectionT *DialerNodeConnection;

    ObjectT *Passwords;
    ObjectT *Sessions;
    ObjectT *SessionsRAM;

    bool IsClient;

    char ConfigServersFilePath[256];
    char ConfigLastNodeFilePath[256];
    char ConfigAutologinFilePath[256];

    ListNodeT *LastBalancer;
    ObjectT *DBBase;

    LockT *Lock;
} DialerClientT;

typedef void (DialerClientOpenCb)(DialerClientT *Client);

typedef void (DialerClientCloseCb)(DialerClientT *Client,
                                   ErrnoT Error);

typedef void (DialerClientEarlyMediaCb)(DialerClientT *Client,
                                        char *Company,
                                        char *DialerLogin,
                                        char *Contact,
                                        char *CallId,
                                        char *EarlyMediaSDP,
                                        ListT *CandidateList);

typedef void (DialerClientCallAnswerCb)(DialerClientT *Client,
                                        char *Company,
                                        char *DialerLogin,
                                        char *Contact,
                                        char *CallId,
                                        char *AnswerSDP,
                                        ListT *CandidateList);

typedef void (DialerClientCallByeCb)(DialerClientT *Client,
                                     char *Company,
                                     char *DialerLogin,
                                     char *Contact,
                                     char *CallId);

typedef void (DialerClientCallErrorCb)(DialerClientT *Client,
                                       char *Company,
                                       char *DialerLogin,
                                       char *Contact,
                                       char *CallId,
                                       ErrnoT Error);

typedef void (DialerClientIncomingCallCb)(DialerClientT *Client,
                                          char *Company,
                                          char *DialerLogin,
                                          char *Contact,
                                          char *CallId,
                                          char *OfferSDP,
                                          ListT *CandidateList);

void DialerClientDestroy(DialerClientT *Client);

DialerClientT *DialerClientInit(const char *DeviceUID,
                                const char *DeviceName,
                                const char *OSVersion,
                                const char *Locale,
                                const char *SoftwareVersion,
                                int8_t GMTNumber,
                                const char *PushUID,
                                DialerClientOpenCb OpenCb,
                                DialerClientCloseCb CloseCb,
                                DialerClientIncomingCallCb IncomingCallCb,
                                DialerClientEarlyMediaCb *EarlyMediaCallCb,
                                DialerClientCallAnswerCb *AnswerCallCb,
                                DialerClientCallByeCb *ByeCallCb,
                                DialerClientCallErrorCb *ErrorCallCb,
                                const char *ConfigServersFilePath,
                                const char *ConfigLastNodeFilePath,
                                const char *AutologinConfigFilePath,
                                PollingLoopSignalCb SignalCb);

ErrnoT DialerClientStart(DialerClientT *Client);

ErrnoT DialerClientSessionStorageWrite(DialerClientT *Client);

ErrnoT DialerClientTURNPassword(char *Password,
                                DialerClientT *Client,
                                char *Company,
                                char *Login);

ArrayT *DialerClientTURNServersList(DialerClientT *Client);

#endif
