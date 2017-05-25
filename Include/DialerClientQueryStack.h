#ifndef SAFEUM_DIALER_CLIENT_QUERY_STACK_H
#define SAFEUM_DIALER_CLIENT_QUERY_STACK_H

#include <HierarchyBase.h>

typedef struct {
    ObjectT *Query;
} DialerClientStackQueryT;

ErrnoT DialerClientQueryStackInsert(BinaryTreeT *Tree,
                                    char *Action,
                                    char *Subaction,
                                    DWordT Id,
                                    ObjectT *Query);

ObjectT *DialerClientQueryStackGet(BinaryTreeT *Tree,
                                   char *Action,
                                   char *Subaction,
                                   DWordT Id);

void DialerClientQueryStackRemove(BinaryTreeT *Tree,
                                  char *Action,
                                  char *Subaction,
                                  DWordT Id);

#endif
