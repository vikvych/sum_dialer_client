#ifndef SAFEUM_DIALER_CLIENT_CB_STACK_H
#define SAFEUM_DIALER_CLIENT_CB_STACK_H

#include <HierarchyBase.h>

typedef void (DialerClientStackDataCb)(void *Client,
                                       char *Company,
                                       char *Login,
                                       bool Success,
                                       char *Comment,
                                       DWordT Id,
                                       ObjectT *ProgressData);

typedef struct {
    DialerClientStackDataCb *DataCb;
    void *Argument;
} DialerClientStackCb;

ErrnoT DialerClientCbStackInsert(BinaryTreeT *Tree,
                                 char *Action,
                                 char *Subaction,
                                 DWordT Id,
                                 DialerClientStackDataCb *Callback, void *Argument);

DialerClientStackDataCb *DialerClientCbStackGet(void **Argument,
                                                BinaryTreeT *Tree,
                                                char *Action,
                                                char *Subaction,
                                                DWordT Id);

void DialerClientCbStackRemove(BinaryTreeT *Tree,
                               char *Action,
                               char *Subaction,
                               DWordT Id);

#endif
