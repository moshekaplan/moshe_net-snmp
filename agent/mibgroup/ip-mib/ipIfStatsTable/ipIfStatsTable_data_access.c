/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 14170 $ of $ 
 *
 * $Id:$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ipIfStatsTable.h"


#include "ipIfStatsTable_data_access.h"

static int      ipis_cache_refresh = IPIFSTATSTABLE_CACHE_TIMEOUT;

/** @ingroup interface
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipIfStatsTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * IP-MIB::ipIfStatsTable is subid 3 of ipTrafficStats.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.4.31.3, length: 9
 */

/**
 * initialization for ipIfStatsTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ipIfStatsTable_reg
 *        Pointer to ipIfStatsTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ipIfStatsTable_init_data(ipIfStatsTable_registration * ipIfStatsTable_reg)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_init_data",
                "called\n"));

    /*
     * TODO:303:o: Initialize ipIfStatsTable data.
     */
    netsnmp_access_systemstats_init();

    return MFD_SUCCESS;
}                               /* ipIfStatsTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ipIfStatsTable_container_init(netsnmp_container ** container_ptr_ptr,
                              netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_container_init",
                "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to ipIfStatsTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    /*
     * We create a custom container here so we can pre-load it, which
     * will result in all new entries with last changed values. we need
     * to clear those...  We also need to make sure ifIndexes have been
     * assigned...
     */
    *container_ptr_ptr =
        netsnmp_container_find("ipIfStatsTable:table_container");
    if (NULL != *container_ptr_ptr) {
        (*container_ptr_ptr)->container_name = strdup("ipIfStatsTable");
        ipIfStatsTable_container_load(*container_ptr_ptr);
    }
    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to ipIfStatsTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up ipIfStatsTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = IPIFSTATSTABLE_CACHE_TIMEOUT;      /* seconds */

    cache->flags |=
        (NETSNMP_CACHE_DONT_AUTO_RELEASE | NETSNMP_CACHE_DONT_FREE_EXPIRED
         | NETSNMP_CACHE_DONT_FREE_BEFORE_LOAD |
         NETSNMP_CACHE_AUTO_RELOAD);
}                               /* ipIfStatsTable_container_init */

/**
 * check entry for update
 */
static void
_check_for_updates(void *p, void *q)
{
    ipIfStatsTable_rowreq_ctx *rowreq_ctx = p;
    netsnmp_container *stats = q;
    netsnmp_systemstats_entry *ifstats_entry;

    /*
     * check for matching entry. works because indexes are the same.
     */
    ifstats_entry = (netsnmp_systemstats_entry*)CONTAINER_FIND(stats, rowreq_ctx->data);
    if (NULL == ifstats_entry) {
        DEBUGMSGTL(("ipIfStatsTable:access",
                    "updating missing entry\n"));

        /*
         * mark row as missing, so we can set discontinuity
         * when it comes back.
         *
         * what else should we do? set refresh to 0? that's not quite right...
         */
        rowreq_ctx->known_missing = 1;
    } else {
        DEBUGMSGTL(("ipIfStatsTable:access",
                    "updating existing entry\n"));

        /*
         * Check for changes & update
         */
        netsnmp_access_systemstats_entry_update(rowreq_ctx->data,
                                            ifstats_entry);

        /*
         * set discontinuity if previously missing.
         */
        if (1 == rowreq_ctx->known_missing) {
            rowreq_ctx->known_missing = 0;
            rowreq_ctx->ipIfStatsDiscontinuityTime =
                netsnmp_get_agent_uptime();
            ipIfStatsTable_lastChange_set(netsnmp_get_agent_uptime());
        }

        /*
         * remove entry from container
         */
        CONTAINER_REMOVE(stats, ifstats_entry);
        netsnmp_access_systemstats_entry_free(ifstats_entry);
    }
}

/**
 * add new entry
 */
static void
_add_new(void *p, void *q)
{
    netsnmp_systemstats_entry *ifstats_entry = p;
    netsnmp_container *container = q;
    ipIfStatsTable_rowreq_ctx *rowreq_ctx;

    DEBUGMSGTL(("ipIfStatsTable:access", "creating new entry\n"));

    netsnmp_assert(NULL != ifstats_entry);
    netsnmp_assert(NULL != container);

    /*
     * allocate an row context and set the index(es)
     */
    rowreq_ctx =
        ipIfStatsTable_allocate_rowreq_ctx(ifstats_entry, NULL);
    if ((NULL != rowreq_ctx)
        && (MFD_SUCCESS ==
            ipIfStatsTable_indexes_set(rowreq_ctx,
                                       ifstats_entry->index[0],
                                       ifstats_entry->index[1]))) {
        rowreq_ctx->ipIfStatsRefreshRate = ipis_cache_refresh * 1000;   /* milli-seconds */
        CONTAINER_INSERT(container, rowreq_ctx);
        ipIfStatsTable_lastChange_set(netsnmp_get_agent_uptime());
    } else {
        if (NULL != rowreq_ctx) {
            snmp_log(LOG_ERR, "error setting index while loading "
                     "ipIfStatsTable cache.\n");
            ipIfStatsTable_release_rowreq_ctx(rowreq_ctx);
        } else {
            snmp_log(LOG_ERR, "memory allocation failed while loading "
                     "ipIfStatsTable cache.\n");
            netsnmp_access_systemstats_entry_free(ifstats_entry);
        }
    }
}

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before ipIfStatsTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
ipIfStatsTable_container_shutdown(netsnmp_container * container_ptr)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_container_shutdown",
                "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to ipIfStatsTable_container_shutdown\n");
        return;
    }

}                               /* ipIfStatsTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement ipIfStatsTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data involves more work (e.g. parsing
 *  some other existing data, or performing calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ipIfStatsTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ipIfStatsTable_container_load(netsnmp_container * container)
{
    netsnmp_container *stats;

    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_container_load",
                "called\n"));

    netsnmp_assert(NULL != container);

    stats = netsnmp_access_systemstats_container_load(NULL, NETSNMP_ACCESS_SYSTEMSTATS_LOAD_IFTABLE);
    if (NULL == stats)
        return MFD_RESOURCE_UNAVAILABLE;        /* msg already logged */

    /*
     * TODO:351:M: |-> Load/update data in the ipIfStatsTable container.
     * loop over your ipIfStatsTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */

    /*
     * we just got a fresh copy of data. compare it to
     * what we've already got, and make any adjustements...
     */
    CONTAINER_FOR_EACH(container, _check_for_updates, stats);

    /*
     * now add any new entries
     */
    CONTAINER_FOR_EACH(stats, _add_new, container);


    /*
      * free the container. we've either claimed each ifentry, or released it,
     * so the dal function doesn't need to clear the container.
     */
    netsnmp_access_systemstats_container_free(stats,
                                          NETSNMP_ACCESS_SYSTEMSTATS_FREE_DONT_CLEAR);

    DEBUGMSGT(("verbose:ipIfStatsTable:ipIfStatsTable_container_load",
               "%lu records\n", (unsigned long)CONTAINER_SIZE(container)));

    return MFD_SUCCESS;
}                               /* ipIfStatsTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
ipIfStatsTable_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_container_free",
                "called\n"));

    /*
     * TODO:380:M: Free ipIfStatsTable container data.
     */
}                               /* ipIfStatsTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ipIfStatsTable_row_prep(ipIfStatsTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ipIfStatsTable:ipIfStatsTable_row_prep",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* ipIfStatsTable_row_prep */

/** @} */
