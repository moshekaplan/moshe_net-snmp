/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.iterate_access.conf,v 1.4 2003/07/01 00:15:11 hardaker Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-features.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "netSnmpHostsTable.h"
#include "netSnmpHostsTable_checkfns.h"
#include "netSnmpHostsTable_access.h"

netsnmp_feature_require(oid_stash);
netsnmp_feature_require(oid_stash_get_data);
netsnmp_feature_require(oid_stash_add_data);

static netsnmp_oid_stash_node *undoStorage = NULL;
static netsnmp_oid_stash_node *commitStorage = NULL;

struct undoInfo {
    void           *ptr;
    size_t          len;
};

struct commitInfo {
    void           *data_context;
    int             have_committed;
    int             new_row;
};

void
netSnmpHostsTable_free_undoInfo(void *vptr)
{
    struct undoInfo *ui = vptr;
    if (!ui)
        return;
    SNMP_FREE(ui->ptr);
    SNMP_FREE(ui);
}

/** Initialize the netSnmpHostsTable table by defining its contents and how it's structured */
void
initialize_table_netSnmpHostsTable(void)
{
    static oid      netSnmpHostsTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 2, 2 };
    netsnmp_table_registration_info *table_info;
    netsnmp_handler_registration *my_handler;
    netsnmp_iterator_info *iinfo;

    /** create the table registration information structures */
    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);

    /** if your table is read only, it's easiest to change the
        HANDLER_CAN_RWRITE definition below to HANDLER_CAN_RONLY */
    my_handler = netsnmp_create_handler_registration("netSnmpHostsTable",
                                                     netSnmpHostsTable_handler,
                                                     netSnmpHostsTable_oid,
                                                     OID_LENGTH
                                                     (netSnmpHostsTable_oid),
                                                     HANDLER_CAN_RWRITE);

    if (!my_handler || !table_info || !iinfo) {
        snmp_log(LOG_ERR,
                 "malloc failed in initialize_table_netSnmpHostsTable");
        free(my_handler);
        free(table_info);
        free(iinfo);
        return; /** Serious error. */
    }

    /***************************************************
     * Setting up the table's definition
     */
    netsnmp_table_helper_add_indexes(table_info, ASN_OCTET_STR,
                                                 /** index: netSnmpHostName */
                                     0);

    /** Define the minimum and maximum accessible columns.  This
        optimizes retrieval. */
    table_info->min_column = 2;
    table_info->max_column = 5;

    /** iterator access routines */
    iinfo->get_first_data_point = netSnmpHostsTable_get_first_data_point;
    iinfo->get_next_data_point = netSnmpHostsTable_get_next_data_point;

    /** you may wish to set these as well */
    iinfo->make_data_context = netSnmpHostsTable_context_convert_function;
    iinfo->free_data_context = netSnmpHostsTable_data_free;
    iinfo->free_loop_context_at_end = netSnmpHostsTable_loop_free;

    /** tie the two structures together */
    iinfo->table_reginfo = table_info;

    /***************************************************
     * registering the table with the master agent
     */
    DEBUGMSGTL(("initialize_table_netSnmpHostsTable",
                "Registering table netSnmpHostsTable as a table iterator\n"));
    netsnmp_register_table_iterator2(my_handler, iinfo);
}

/** Initializes the netSnmpHostsTable module */
void
init_netSnmpHostsTable(void)
{

  /** here we initialize all the tables we're planning on supporting */
    initialize_table_netSnmpHostsTable();
}

/** handles requests for the netSnmpHostsTable table, if anything else needs to be done */
int
netSnmpHostsTable_handler(netsnmp_mib_handler *handler,
                          netsnmp_handler_registration *reginfo,
                          netsnmp_agent_request_info *reqinfo,
                          netsnmp_request_info *requests)
{

    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct commitInfo *ci = NULL;

    void           *data_context = NULL;

    for (request = requests; request; request = request->next) {
        /* column and row index encoded portion */
        netsnmp_variable_list *var = request->requestvb;
        const oid * const suffix = var->name + reginfo->rootoid_len + 1;
        const size_t suffix_len = var->name_length - (reginfo->rootoid_len + 1);

        if (request->processed != 0)
            continue;

        switch (reqinfo->mode) {
        case MODE_GET:
        case MODE_SET_RESERVE1:
            data_context = netsnmp_extract_iterator_context(request);
            if (data_context == NULL) {
                if (reqinfo->mode == MODE_GET) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
            }
            break;

        default:               /* == the other SET modes */
            ci = netsnmp_oid_stash_get_data(commitStorage,
                                            suffix + 1, suffix_len - 1);
            break;

        }

        /** extracts the information about the table from the request */
        table_info = netsnmp_extract_table_info(request);
        /** table_info->colnum contains the column number requested */
        /** table_info->indexes contains a linked list of snmp variable
           bindings for the indexes of the table.  Values in the list
           have been set corresponding to the indexes of the
           request */
        if (table_info == NULL) {
            continue;
        }

        switch (reqinfo->mode) {
        case MODE_GET:
            switch (table_info->colnum) {
            case COLUMN_NETSNMPHOSTADDRESSTYPE:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    retval =
                        get_netSnmpHostAddressType(data_context,
                                                   &retval_len);
                    snmp_set_var_typed_value(var, ASN_INTEGER,
                                             (const u_char *) retval,
                                             retval_len);
                }
                break;

            case COLUMN_NETSNMPHOSTADDRESS:
                {
                    char           *retval;
                    size_t          retval_len = 0;
                    retval =
                        get_netSnmpHostAddress(data_context, &retval_len);
                    snmp_set_var_typed_value(var, ASN_OCTET_STR,
                                             (const u_char *) retval,
                                             retval_len);
                }
                break;

            case COLUMN_NETSNMPHOSTSTORAGE:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    retval =
                        get_netSnmpHostStorage(data_context, &retval_len);
                    snmp_set_var_typed_value(var, ASN_INTEGER,
                                             (const u_char *) retval,
                                             retval_len);
                }
                break;

            case COLUMN_NETSNMPHOSTROWSTATUS:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    retval =
                        get_netSnmpHostRowStatus(data_context,
                                                 &retval_len);
                    snmp_set_var_typed_value(var, ASN_INTEGER,
                                             (const u_char *) retval,
                                             retval_len);
                }
                break;

            default:
                /** We shouldn't get here */
                snmp_log(LOG_ERR,
                         "problem encountered in netSnmpHostsTable_handler: unknown column\n");
            }
            break;

        case MODE_SET_RESERVE1:
            ci = netsnmp_oid_stash_get_data(commitStorage,
                                            suffix + 1, suffix_len - 1);

            if (!ci) {
                    /** create the commit storage info */
                ci = SNMP_MALLOC_STRUCT(commitInfo);
                if (!data_context) {
                    ci->data_context =
                        netSnmpHostsTable_create_data_context(table_info->
                                                              indexes);
                    ci->new_row = 1;
                } else {
                    ci->data_context = data_context;
                }
                netsnmp_oid_stash_add_data(&commitStorage,
                                           suffix + 1, suffix_len - 1, ci);
            }
            break;

        case MODE_SET_RESERVE2:
            switch (table_info->colnum) {
            case COLUMN_NETSNMPHOSTADDRESSTYPE:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    struct undoInfo *ui = NULL;
                    int             ret;

                    /** first, get the old value */
                    retval =
                        get_netSnmpHostAddressType(ci->data_context,
                                                   &retval_len);
                    if (retval) {
                        ui = SNMP_MALLOC_STRUCT(undoInfo);
                        ui->len = retval_len;
                        ui->ptr = netsnmp_memdup(retval, ui->len);
                    }

                    /** check the new value, possibly against the
                        older value for a valid state transition */
                    ret =
                        check_netSnmpHostAddressType(request->requestvb->
                                                     type,
                                                     (long *) request->
                                                     requestvb->val.string,
                                                     request->requestvb->
                                                     val_len, retval,
                                                     retval_len);
                    if (ret != 0) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                        netSnmpHostsTable_free_undoInfo(ui);
                    } else if (ui) {
                        /** remember information for undo purposes later */
                        netsnmp_oid_stash_add_data(&undoStorage,
                                                   suffix, suffix_len, ui);
                    }

                }
                break;
            case COLUMN_NETSNMPHOSTADDRESS:
                {
                    char           *retval;
                    size_t          retval_len = 0;
                    struct undoInfo *ui = NULL;
                    int             ret;

                    /** first, get the old value */
                    retval =
                        get_netSnmpHostAddress(ci->data_context,
                                               &retval_len);
                    if (retval) {
                        ui = SNMP_MALLOC_STRUCT(undoInfo);
                        ui->len = retval_len;
                        ui->ptr = netsnmp_memdup(retval, ui->len);
                    }

                    /** check the new value, possibly against the
                        older value for a valid state transition */
                    ret =
                        check_netSnmpHostAddress(request->requestvb->type,
                                                 (char *) request->
                                                 requestvb->val.string,
                                                 request->requestvb->
                                                 val_len, retval,
                                                 retval_len);
                    if (ret != 0) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                        netSnmpHostsTable_free_undoInfo(ui);
                    } else if (ui) {
                        /** remember information for undo purposes later */
                        netsnmp_oid_stash_add_data(&undoStorage,
                                                   suffix, suffix_len, ui);
                    }

                }
                break;
            case COLUMN_NETSNMPHOSTSTORAGE:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    struct undoInfo *ui = NULL;
                    int             ret;

                    /** first, get the old value */
                    retval =
                        get_netSnmpHostStorage(ci->data_context,
                                               &retval_len);
                    if (retval) {
                        ui = SNMP_MALLOC_STRUCT(undoInfo);
                        ui->len = retval_len;
                        ui->ptr = netsnmp_memdup(retval, ui->len);
                    }

                    /** check the new value, possibly against the
                        older value for a valid state transition */
                    ret =
                        check_netSnmpHostStorage(request->requestvb->type,
                                                 (long *) request->
                                                 requestvb->val.string,
                                                 request->requestvb->
                                                 val_len, retval,
                                                 retval_len);
                    if (ret != 0) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                        netSnmpHostsTable_free_undoInfo(ui);
                    } else if (ui) {
                        /** remember information for undo purposes later */
                        netsnmp_oid_stash_add_data(&undoStorage,
                                                   suffix, suffix_len, ui);
                    }

                }
                break;
            case COLUMN_NETSNMPHOSTROWSTATUS:
                {
                    long           *retval;
                    size_t          retval_len = 0;
                    struct undoInfo *ui = NULL;
                    int             ret;

                    /** first, get the old value */
                    retval =
                        get_netSnmpHostRowStatus(ci->data_context,
                                                 &retval_len);
                    if (retval) {
                        ui = SNMP_MALLOC_STRUCT(undoInfo);
                        ui->len = retval_len;
                        ui->ptr = netsnmp_memdup(retval, ui->len);
                    }

                    /** check the new value, possibly against the
                        older value for a valid state transition */
                    ret =
                        check_netSnmpHostRowStatus(request->requestvb->
                                                   type,
                                                   (long *) request->
                                                   requestvb->val.string,
                                                   request->requestvb->
                                                   val_len, retval,
                                                   retval_len);
                    if (ret != 0) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                        netSnmpHostsTable_free_undoInfo(ui);
                    } else if (ui) {
                        /** remember information for undo purposes later */
                        netsnmp_oid_stash_add_data(&undoStorage,
                                                   suffix, suffix_len, ui);
                    }

                }
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_ERR_NOTWRITABLE);
                break;
            }
            break;

        case MODE_SET_ACTION:
            /** save a variable copy */
            switch (table_info->colnum) {
            case COLUMN_NETSNMPHOSTADDRESSTYPE:
                {
                    int             ret;
                    ret = set_netSnmpHostAddressType(ci->data_context,
                                                     (long *) request->
                                                     requestvb->val.string,
                                                     request->requestvb->
                                                     val_len);
                    if (ret) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTADDRESS:
                {
                    int             ret;
                    ret = set_netSnmpHostAddress(ci->data_context,
                                                 (char *) request->
                                                 requestvb->val.string,
                                                 request->requestvb->
                                                 val_len);
                    if (ret) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTSTORAGE:
                {
                    int             ret;
                    ret = set_netSnmpHostStorage(ci->data_context,
                                                 (long *) request->
                                                 requestvb->val.string,
                                                 request->requestvb->
                                                 val_len);
                    if (ret) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTROWSTATUS:
                {
                    int             ret;
                    ret = set_netSnmpHostRowStatus(ci->data_context,
                                                   (long *) request->
                                                   requestvb->val.string,
                                                   request->requestvb->
                                                   val_len);
                    if (ret) {
                        netsnmp_set_request_error(reqinfo, request, ret);
                    }
                    if (*request->requestvb->val.integer == RS_DESTROY) {
                        ci->new_row = -1;
                    }
                }
                break;
            }
            break;

        case MODE_SET_COMMIT:
            if (!ci->have_committed) {
                    /** do this once per row only */
                netSnmpHostsTable_commit_row(&ci->data_context,
                                             ci->new_row);
                ci->have_committed = 1;
            }
            break;

        case MODE_SET_UNDO:
             /** save a variable copy */
            switch (table_info->colnum) {
            case COLUMN_NETSNMPHOSTADDRESSTYPE:
                {
                    int             retval;
                    struct undoInfo *ui;
                    ui = netsnmp_oid_stash_get_data(undoStorage,
                                                    suffix, suffix_len);
                    retval =
                        set_netSnmpHostAddressType(ci->data_context,
                                                   ui->ptr, ui->len);
                    if (retval) {
                        netsnmp_set_request_error(reqinfo, request,
                                                  SNMP_ERR_UNDOFAILED);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTADDRESS:
                {
                    int             retval;
                    struct undoInfo *ui;
                    ui = netsnmp_oid_stash_get_data(undoStorage,
                                                    suffix, suffix_len);
                    retval =
                        set_netSnmpHostAddress(ci->data_context, ui->ptr,
                                               ui->len);
                    if (retval) {
                        netsnmp_set_request_error(reqinfo, request,
                                                  SNMP_ERR_UNDOFAILED);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTSTORAGE:
                {
                    int             retval;
                    struct undoInfo *ui;
                    ui = netsnmp_oid_stash_get_data(undoStorage,
                                                    suffix, suffix_len);
                    retval =
                        set_netSnmpHostStorage(ci->data_context, ui->ptr,
                                               ui->len);
                    if (retval) {
                        netsnmp_set_request_error(reqinfo, request,
                                                  SNMP_ERR_UNDOFAILED);
                    }
                }
                break;
            case COLUMN_NETSNMPHOSTROWSTATUS:
                {
                    int             retval;
                    struct undoInfo *ui;
                    ui = netsnmp_oid_stash_get_data(undoStorage,
                                                    suffix, suffix_len);
                    retval =
                        set_netSnmpHostRowStatus(ci->data_context, ui->ptr,
                                                 ui->len);
                    if (retval) {
                        netsnmp_set_request_error(reqinfo, request,
                                                  SNMP_ERR_UNDOFAILED);
                    }
                }
                break;
            }
            break;

        case MODE_SET_FREE:
            break;

        default:
            snmp_log(LOG_ERR,
                     "problem encountered in netSnmpHostsTable_handler: unsupported mode\n");
        }
    }

    /** clean up after all requset processing has ended */
    switch (reqinfo->mode) {
    case MODE_SET_UNDO:
    case MODE_SET_FREE:
    case MODE_SET_COMMIT:
        /** clear out the undo cache */
        netsnmp_oid_stash_free(&undoStorage,
                               netSnmpHostsTable_free_undoInfo);
        netsnmp_oid_stash_free(&commitStorage, netsnmp_oid_stash_no_free);
    }


    return SNMP_ERR_NOERROR;
}
