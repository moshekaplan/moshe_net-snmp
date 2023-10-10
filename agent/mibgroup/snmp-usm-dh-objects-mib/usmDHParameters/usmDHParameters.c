/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.7 2003/04/08 14:57:04 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/openssl_config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/library/snmp_openssl.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "usmDHParameters.h"

#include <openssl/dh.h>

static DH *dh_params = NULL;

DH *
get_dh_params(void)
{
    return dh_params;
}

/** Initializes the usmDHParameters module */
void
init_usmDHParameters(void)
{
    BIGNUM         *p = NULL, *g = NULL;
    static oid      usmDHParameters_oid[] =
        { 1, 3, 6, 1, 3, 101, 1, 1, 1 };

    DEBUGMSGTL(("usmDHParameters", "Initializing\n"));

    netsnmp_register_scalar(netsnmp_create_handler_registration
                            ("usmDHParameters", handle_usmDHParameters,
                             usmDHParameters_oid,
                             OID_LENGTH(usmDHParameters_oid),
                             HANDLER_CAN_RWRITE));

    /* currently hard coded to the oakly group 2 set. */
    /* these values are modifiable via SNMP SETs if needed by
       management apps though */
    if (!dh_params) {
        dh_params = DH_new();
        BN_hex2bn(&g, "02");
        BN_hex2bn(&p, "ffffffffffffffffc90fdaa22168c234c4c6628b80dc1cd129024e088a67cc74020bbea63b139b22514a08798e3404ddef9519b3cd3a431b302b0a6df25f14374fe1356d6d51c245e485b576625e7ec6f44c42e9a637ed6b0bff5cb6f406b7edee386bfb5a899fa5ae9f24117c4b1fe649286651ece65381ffffffffffffffff");
        DH_set0_pqg(dh_params, p, NULL, g);
    }
}

int
handle_usmDHParameters(netsnmp_mib_handler *handler,
                       netsnmp_handler_registration *reginfo,
                       netsnmp_agent_request_info *reqinfo,
                       netsnmp_request_info *requests)
{
    /*
     * We are never called for a GETNEXT if it's registered as a
     * "instance", as it's "magically" handled for us.  
     */

    static unsigned char *cp = NULL;
    static DH *dh_tmpp = NULL;
    int cp_len;

    /*
     * a instance handler also only hands us one request at a time, so
     * we don't need to loop over a list of requests; we'll only get one. 
     */

    switch (reqinfo->mode) {

    case MODE_GET:
        if(cp) {
            free(cp);
            cp = NULL;
        }
        cp_len = i2d_DHparams(dh_params, &cp);
        if (cp_len > 0)
            snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
                                     (u_char *) cp, cp_len);
        break;

        /*
         * SET REQUEST
         *
         * multiple states in the transaction.  See:
         * http://www.net-snmp.org/tutorial-5/toolkit/mib_module/set-actions.jpg
         */
    case MODE_SET_RESERVE1:
        break;

    case MODE_SET_RESERVE2:
        cp = requests->requestvb->val.string;
        dh_tmpp = d2i_DHparams(NULL, (const unsigned char **) (void *)&cp,
                               requests->requestvb->val_len);
        if ( !dh_tmpp) {
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
        }
        if (cp - requests->requestvb->val.string !=
            requests->requestvb->val_len) {
            /* value too long; we didn't parse the whole thing */
            netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
            DH_free(dh_tmpp);
            dh_tmpp = NULL;
        }
        break;

    case MODE_SET_FREE:
    case MODE_SET_COMMIT:
        DH_free(dh_tmpp);
        dh_tmpp = NULL;
        break;

    case MODE_SET_ACTION:
    {
        DH *tmpp;
        tmpp = dh_params;
        dh_params = dh_tmpp;
        dh_tmpp = tmpp;
        break;
    }

    case MODE_SET_UNDO:
    {
        DH_free(dh_params);  /* free new value */
        dh_params = dh_tmpp; /* restore old value */
        dh_tmpp = NULL;
        break;
    }

    default:
        /*
         * we should never get here, so this is a really bad error 
         */
        return SNMP_ERR_GENERR;
    }

    return SNMP_ERR_NOERROR;
}
