#ifndef SAFEUM_DIALER_CLIENT_ACTION_CALL_H
#define SAFEUM_DIALER_CLIENT_ACTION_CALL_H

#include "DialerClient.h"
#include <HierarchyExt.h>

typedef enum {
    CALL_MESSAGE_TYPE_OFFER = 0,
    CALL_MESSAGE_TYPE_ANSWER = 1,
    CALL_MESSAGE_TYPE_BYE = 2,
    CALL_MESSAGE_TYPE_EARLY_MEDIA = 3,
    CALL_MESSAGE_TYPE_ERROR = 4
} CallMessageTypeT;


//Delete function from header after tests
char *DialerSIPSDPCreate(char *OfferAnswer,
                         ListT *CandidateList,
                         bool IsOffer);

SDPSessionT *SDPRemoteToLocal(SDPSessionT *Session, char *IP, WordT Port);

SDPSessionT *SDPRemoteToLocal2(SDPSessionT *Session, DWordT IP, WordT Port);

char *DialerClientGenerateCallId();


DWordT DialerClientActionCallStart(DialerClientT *Client,
                                   char *Company,
                                   char *Login,
                                   char *Contact,
                                   char *Offer,
                                   ListT *CandidateList,
                                   void *Cb,
                                   char **CallId);

DWordT DialerClientActionCallBye(DialerClientT *Client,
                                 char *Company,
                                 char *Login,
                                 char *Contact,
                                 void *Cb,
                                 char *CallId);

DWordT DialerClientActionCallAnswer(DialerClientT *Client,
                                    char *Company,
                                    char *Login,
                                    char *Contact,
                                    char *Answer,
                                    ListT *CandidateList,
                                    void *Cb,
                                    char *CallId);

ErrnoT DialerWebRTCSDPFromSIPCreate(char **WEBRTCSDP,
                                    ListT **WEBRTCCandidateList,
                                    char *SIPSDP,
                                    CallMessageTypeT Type);


#endif
