#ifndef SAFEUM_DIALER_CLIENT_ACTION_SYNC_H
#define SAFEUM_DIALER_CLIENT_ACTION_SYNC_H

#include "DialerClient.h"

ObjectT *DBBaseStamps(DialerClientT *Client, char *Company, char *Login);
ErrnoT DBBaseSync(DialerClientT *Client, char *Company, char *Login, ObjectT *DiffObject);

DWordT DialerClientActionSyncBase(DialerClientT *Client,
                                  char *Company,
                                  char *Login,
                                  void *SyncCallback,
                                  DWordT Id);

#endif

