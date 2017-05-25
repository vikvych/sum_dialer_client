#ifndef SAFEUM_DIALER_CLIENT_ACTION_BILLING_H
#define SAFEUM_DIALER_CLIENT_ACTION_BILLING_H

#include "DialerClient.h"

#define VAT_FALSE "false"
#define VAT_TRUE "true"
#define VAT_NULL "null"

ListT *DialerClientGetCards(DialerClientT *Client, char *Company, char *Login);

const char *DialerClientGetVAT(double *VATRate,
                               char *VATCountry,
                               DialerClientT *Client,
                               char *Company,
                               char *Login);

double DialerClientGetBalance(DialerClientT *Client, char *Company, char *Login);
char *DialerClientGetPhoneNumber(DialerClientT *Client, char *Company, char *Login);

DWordT DialerClientActionBillingGetPaymentURL(DialerClientT *Client,
                                              char *Company,
                                              char *Login,
                                              QWordT Amount,
                                              QWordT CardId,
                                              char *VatNeeded,
                                              char *VatCountry,
                                              void *BillingCallback);

DWordT DialerClientActionBillingGetRate(DialerClientT *Client,
                                        char *Company,
                                        char *Login,
                                        char *Code,
                                        void *BillingCallback);

#endif
