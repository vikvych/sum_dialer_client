#ifndef SAFEUM_DIALER_CLIENT_ACTION_REG_H
#define SAFEUM_DIALER_CLIENT_ACTION_REG_H

#include "DialerClient.h"

DWordT DialerClientActionRegByLogin(DialerClientT *Client,
                                    char *Company,
                                    char *Login,
                                    char *Password,
                                    void *RegCallback);

#endif
