#ifndef SAFEUM_DIALER_CLIENT_ACTION_LOGIN_H
#define SAFEUM_DIALER_CLIENT_ACTION_LOGIN_H

#include "DialerClient.h"
#include "DialerPassword.h"

typedef struct {
    char *Company;
    char *Login;
    DWordT Id;
} DialerAutoLoginDataT;

ObjectT *DialerClientLoginLogin(MemoryBufferT **SessionReturning,
                                char *Company,
                                char *Login,
                                char *Password,
                                char *DeviceUID,
                                char *DeviceName,
                                char *OSVersion,
                                char *Locale,
                                char *SoftwareVersion,
                                int8_t GMT,
                                char *PushUID,
                                DWordT Id, ECCryptoModeT CryptoType,
                                MemoryBufferT *StampData);

ObjectT *DialerClientLoginAlt(char *Company,
                              char *Login,
                              char *DeviceUID,
                              DWordT Id,
                              char *SoftwareVersion,
                              char *OSVersion,
                              char *DeviceName,
                              char *Locale,
                              int8_t GMT,
                              ByteT *Session,
                              SizeT SessionLength,
                              MemoryBufferT *StampData);

DWordT DialerClientActionLoginLogin(DialerClientT *Client,
                                    char *Company,
                                    char *Login,
                                    char *Password,
                                    bool SaveSession,
                                    void *Cb);

DWordT DialerClientActionLoginAlt(DialerClientT *Client,
                                  char *Company,
                                  char *Login,
                                  void *Cb);

ListT *DialerClientActionLoginAuto(DialerClientT *DialerClient,
                                   void *LoginCallback);

DWordT DialerClientActionLoginLogout(DialerClientT *Client,
                                     char *Company,
                                     char *Login,
                                     void *Cb);

#endif
