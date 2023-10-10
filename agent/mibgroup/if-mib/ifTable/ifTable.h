/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.48 $ of : mfd-top.m2c,v $
 *
 * $Id$
 */
#ifndef IFTABLE_H
#define IFTABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @ingroup agent
 * @defgroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>
#include <net-snmp/data_access/interface.h>

    /*
     * other required module components 
     */
    /* *INDENT-OFF*  */
config_require(if-mib/data_access/interface);
config_require(if-mib/ifTable/ifTable_interface);
config_require(if-mib/ifTable/ifTable_data_access);
/*
 * conflicts with mibII/interfaces
 */
config_exclude(mibII/interfaces);
    /* *INDENT-ON*  */

    /*
     * OID, column number and enum definions for ifTable 
     */
#include "ifTable_constants.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ifTable(void);
    void            shutdown_ifTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IF-MIB::ifTable is subid 2 of interfaces.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */
    /*
     *********************************************************************
     * When you register your mib, you get to provide a generic
     * pointer that will be passed back to you for most of the
     * functions calls.
     *
     * TODO:100:r: Review all context structures
     */
    /*
     * TODO:101:o: |-> Review ifTable registration context.
     */
    typedef netsnmp_data_list ifTable_registration;

/**********************************************************************/
    /*
     * TODO:110:r: |-> Review ifTable data context structure.
     * This structure is used to represent the data for ifTable.
     */
    /*
     * This structure contains storage for all the columns defined in the
     * ifTable.
     */
    typedef struct ifTable_data_s {

        /*
         * ifDescr(2)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/h
         */

        /*
         * ifType(3)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */

        /*
         * ifMtu(4)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */

        /*
         * ifSpeed(5)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifPhysAddress(6)/PhysAddress/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/h
         */

        /*
         * ifAdminStatus(7)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */

        /*
         * ifOperStatus(8)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */

        /*
         * ifLastChange(9)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInOctets(10)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInUcastPkts(11)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInNUcastPkts(12)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInDiscards(13)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInErrors(14)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInUnknownProtos(15)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutOctets(16)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutUcastPkts(17)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutNUcastPkts(18)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutDiscards(19)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutErrors(20)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutQLen(21)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifSpecific(22)/OBJECTID/ASN_OBJECT_ID/oid(oid)//L/A/w/e/r/d/h
         */
#ifdef IFTABLE_HAS_IFSPECIFIC
        oid             ifSpecific[128];
        size_t          ifSpecific_len; /* # of oid elements, not bytes */
#endif

#ifdef USING_IF_MIB_IFXTABLE_IFXTABLE_MODULE
        /*
         * ifXTable stuff
         */
        /*
         * ifName(1)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */

        /*
         * ifInMulticastPkts(2)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifInBroadcastPkts(3)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutMulticastPkts(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifOutBroadcastPkts(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifHCInOctets(6)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCInUcastPkts(7)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCInMulticastPkts(8)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCInBroadcastPkts(9)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCOutOctets(10)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCOutUcastPkts(11)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCOutMulticastPkts(12)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifHCOutBroadcastPkts(13)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
         */

        /*
         * ifLinkUpDownTrapEnable(14)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */
        u_long          ifLinkUpDownTrapEnable;

        /*
         * ifHighSpeed(15)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
         */

        /*
         * ifPromiscuousMode(16)/TruthValue/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */

        /*
         * ifConnectorPresent(17)/TruthValue/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */

        /*
         * ifAlias(18)/DisplayString/ASN_OCTET_STR/char(char)//L/A/W/e/R/d/H
         */
        char            ifAlias[64];
        size_t          ifAlias_len;    /* # of char elements, not bytes */

        /*
         * ifCounterDiscontinuityTime(19)/TimeStamp/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
        u_long          ifCounterDiscontinuityTime;
#endif                          /* USING_IF_MIB_IFXTABLE_IFXTABLE_MODULE */


        /*
         * some data kept externally 
         */
        netsnmp_interface_entry *ifentry;
    } ifTable_data;


    /*
     *********************************************************************
     * TODO:115:o: |-> Review ifTable undo context.
     * We're just going to use the same data structure for our
     * undo_context. If you want to do something more efficent,
     * define your typedef here.
     */
    typedef ifTable_data ifTable_undo_data;

    /*
     * TODO:120:r: |-> Review ifTable mib index.
     * This structure is used to represent the index for ifTable.
     */
    typedef struct ifTable_mib_index_s {

        /*
         * ifIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
         */
        long            ifIndex;


    } ifTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review ifTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
     */
#define MAX_ifTable_IDX_LEN     1


    /*
     *********************************************************************
     * TODO:130:o: |-> Review ifTable Row request (rowreq) context.
     * When your functions are called, you will be passed a
     * ifTable_rowreq_ctx pointer.
     */
    typedef struct ifTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
        netsnmp_index   oid_idx;
        oid             oid_tmp[MAX_ifTable_IDX_LEN];

        ifTable_mib_index tbl_idx;

        ifTable_data    data;
        ifTable_undo_data *undo;
        unsigned int    column_set_flags;       /* flags for set columns */


        /*
         * flags per row. Currently, the first (lower) 8 bits are reserved
         * for the user. See mfd.h for other flags.
         */
        u_int           rowreq_flags;

        /*
         * TODO:131:o: |   |-> Add useful data to ifTable rowreq context.
         */
        char            known_missing;
	u_char          undo_ref_count;

        /*
         * storage for future expansion
         */
        netsnmp_data_list *ifTable_data_list;

    } ifTable_rowreq_ctx;

    /*
     *********************************************************************
     * function prototypes
     */
    	
    int             _mfd_ifTable_undo_setup_allocate(ifTable_rowreq_ctx *rowreq_ctx);
    void            _mfd_ifTable_undo_setup_release(ifTable_rowreq_ctx *rowreq_ctx);
    int             ifTable_pre_request(ifTable_registration *
                                        user_context);
    int             ifTable_post_request(ifTable_registration *
                                         user_context, int rc);

    int             ifTable_check_dependencies(ifTable_rowreq_ctx *
                                               rowreq_ctx);
    int             ifTable_commit(ifTable_rowreq_ctx * rowreq_ctx);

    ifTable_rowreq_ctx *ifTable_row_find_by_mib_index(ifTable_mib_index *
                                                      mib_idx);

    extern const oid ifTable_oid[];
    extern const int ifTable_oid_size;


#include "ifTable_interface.h"
#include "ifTable_data_access.h"
    /*
     *********************************************************************
     * GET function declarations
     */

    /*
     *********************************************************************
     * GET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IF-MIB::ifTable is subid 2 of interfaces.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */
    /*
     * indexes
     */

    int             ifDescr_get(ifTable_rowreq_ctx * rowreq_ctx,
                                char **ifDescr_val_ptr_ptr,
                                size_t * ifDescr_val_ptr_len_ptr);
    int             ifType_get(ifTable_rowreq_ctx * rowreq_ctx,
                               u_long * ifType_val_ptr);
    int             ifMtu_get(ifTable_rowreq_ctx * rowreq_ctx,
                              long *ifMtu_val_ptr);
    int             ifSpeed_get(ifTable_rowreq_ctx * rowreq_ctx,
                                u_long * ifSpeed_val_ptr);
    int             ifPhysAddress_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      char **ifPhysAddress_val_ptr_ptr,
                                      size_t
                                      * ifPhysAddress_val_ptr_len_ptr);
    int             ifAdminStatus_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifAdminStatus_val_ptr);
    int             ifOperStatus_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifOperStatus_val_ptr);
    int             ifLastChange_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifLastChange_val_ptr);
    int             ifInOctets_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long * ifInOctets_val_ptr);
    int             ifInUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifInUcastPkts_val_ptr);
    int             ifInNUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long * ifInNUcastPkts_val_ptr);
    int             ifInDiscards_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifInDiscards_val_ptr);
    int             ifInErrors_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long * ifInErrors_val_ptr);
    int             ifInUnknownProtos_get(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long *
                                          ifInUnknownProtos_val_ptr);
    int             ifOutOctets_get(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long * ifOutOctets_val_ptr);
    int             ifOutUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long * ifOutUcastPkts_val_ptr);
    int             ifOutNUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long * ifOutNUcastPkts_val_ptr);
    int             ifOutDiscards_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifOutDiscards_val_ptr);
    int             ifOutErrors_get(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long * ifOutErrors_val_ptr);
    int             ifOutQLen_get(ifTable_rowreq_ctx * rowreq_ctx,
                                  u_long * ifOutQLen_val_ptr);
    int             ifSpecific_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   oid ** ifSpecific_val_ptr_ptr,
                                   size_t * ifSpecific_val_ptr_len_ptr);


    int             ifTable_indexes_set(ifTable_rowreq_ctx * rowreq_ctx,
                                        long ifIndex_val);



#ifndef NETSNMP_NO_WRITE_SUPPORT
    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IF-MIB::ifTable is subid 2 of interfaces.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */


    int             ifTable_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifTable_undo_cleanup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifTable_undo(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifTable_commit(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifTable_undo_commit(ifTable_rowreq_ctx * rowreq_ctx);


    int             ifDescr_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                        char *ifDescr_val_ptr,
                                        size_t ifDescr_val_ptr_len);
    int             ifDescr_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifDescr_set(ifTable_rowreq_ctx * rowreq_ctx,
                                char *ifDescr_val_ptr,
                                size_t ifDescr_val_ptr_len);
    int             ifDescr_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifType_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifType_val);
    int             ifType_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifType_set(ifTable_rowreq_ctx * rowreq_ctx,
                               u_long ifType_val);
    int             ifType_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifMtu_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                      long ifMtu_val);
    int             ifMtu_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifMtu_set(ifTable_rowreq_ctx * rowreq_ctx,
                              long ifMtu_val);
    int             ifMtu_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifSpeed_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long ifSpeed_val);
    int             ifSpeed_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifSpeed_set(ifTable_rowreq_ctx * rowreq_ctx,
                                u_long ifSpeed_val);
    int             ifSpeed_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifPhysAddress_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              char *ifPhysAddress_val_ptr,
                                              size_t
                                              ifPhysAddress_val_ptr_len);
    int             ifPhysAddress_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifPhysAddress_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      char *ifPhysAddress_val_ptr,
                                      size_t ifPhysAddress_val_ptr_len);
    int             ifPhysAddress_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifAdminStatus_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifAdminStatus_val);
    int             ifAdminStatus_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifAdminStatus_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifAdminStatus_val);
    int             ifAdminStatus_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOperStatus_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifOperStatus_val);
    int             ifOperStatus_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifOperStatus_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifOperStatus_val);
    int             ifOperStatus_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifLastChange_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifLastChange_val);
    int             ifLastChange_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifLastChange_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifLastChange_val);
    int             ifLastChange_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInOctets_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           u_long ifInOctets_val);
    int             ifInOctets_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifInOctets_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long ifInOctets_val);
    int             ifInOctets_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInUcastPkts_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifInUcastPkts_val);
    int             ifInUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifInUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifInUcastPkts_val);
    int             ifInUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInNUcastPkts_check_value(ifTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long ifInNUcastPkts_val);
    int             ifInNUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                              rowreq_ctx);
    int             ifInNUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifInNUcastPkts_val);
    int             ifInNUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInDiscards_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifInDiscards_val);
    int             ifInDiscards_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifInDiscards_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifInDiscards_val);
    int             ifInDiscards_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInErrors_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           u_long ifInErrors_val);
    int             ifInErrors_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifInErrors_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long ifInErrors_val);
    int             ifInErrors_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInUnknownProtos_check_value(ifTable_rowreq_ctx *
                                                  rowreq_ctx,
                                                  u_long
                                                  ifInUnknownProtos_val);
    int             ifInUnknownProtos_undo_setup(ifTable_rowreq_ctx *
                                                 rowreq_ctx);
    int             ifInUnknownProtos_set(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifInUnknownProtos_val);
    int             ifInUnknownProtos_undo(ifTable_rowreq_ctx *
                                           rowreq_ctx);

    int             ifOutOctets_check_value(ifTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long ifOutOctets_val);
    int             ifOutOctets_undo_setup(ifTable_rowreq_ctx *
                                           rowreq_ctx);
    int             ifOutOctets_set(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long ifOutOctets_val);
    int             ifOutOctets_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutUcastPkts_check_value(ifTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long ifOutUcastPkts_val);
    int             ifOutUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                              rowreq_ctx);
    int             ifOutUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifOutUcastPkts_val);
    int             ifOutUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutNUcastPkts_check_value(ifTable_rowreq_ctx *
                                                rowreq_ctx,
                                                u_long
                                                ifOutNUcastPkts_val);
    int             ifOutNUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                               rowreq_ctx);
    int             ifOutNUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long ifOutNUcastPkts_val);
    int             ifOutNUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutDiscards_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifOutDiscards_val);
    int             ifOutDiscards_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifOutDiscards_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifOutDiscards_val);
    int             ifOutDiscards_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutErrors_check_value(ifTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long ifOutErrors_val);
    int             ifOutErrors_undo_setup(ifTable_rowreq_ctx *
                                           rowreq_ctx);
    int             ifOutErrors_set(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long ifOutErrors_val);
    int             ifOutErrors_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutQLen_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifOutQLen_val);
    int             ifOutQLen_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifOutQLen_set(ifTable_rowreq_ctx * rowreq_ctx,
                                  u_long ifOutQLen_val);
    int             ifOutQLen_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifSpecific_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           oid * ifSpecific_val_ptr,
                                           size_t ifSpecific_val_ptr_len);
    int             ifSpecific_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifSpecific_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   oid * ifSpecific_val_ptr,
                                   size_t ifSpecific_val_ptr_len);
    int             ifSpecific_undo(ifTable_rowreq_ctx * rowreq_ctx);


    int             ifTable_check_dependencies(ifTable_rowreq_ctx * ctx);
#endif /* !NETSNMP_NO_WRITE_SUPPORT */

    /*
     * DUMMY markers, ignore
     *
     * TODO:099:x: *************************************************************
     * TODO:199:x: *************************************************************
     * TODO:299:x: *************************************************************
     * TODO:399:x: *************************************************************
     * TODO:499:x: *************************************************************
     */

#ifdef __cplusplus
}
#endif
#endif                          /* IFTABLE_H */
/**  @} */

