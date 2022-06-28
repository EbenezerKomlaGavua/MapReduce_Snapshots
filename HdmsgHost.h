//
//  HdmsgHost.h
//  HDMSG
//
//  Created by ics699 on 9/21/16.
//  Copyright © 2016 ics699. All rights reserved.
//

#ifndef HDMSGHOST_H
#define HDMSGHOST_H

//Introduce a mailbox to enable transfer of tasks
#define MAILBOX_ALIAS_SIZE 256

#include <stdio.h>
#include "simgrid/msg.h"

//////////////////////
// Constants
//////////////////////
/*These constants are distributed amongst the hosts(master and worker vms) to
 * to enable the map and reduce processes can be achieved.
  */

extern int SHUFFLERS_PER_REDUCER;
extern int mappers_per_worker;
extern int movers_per_worker;
extern int mappers_snapshots_per_worker;
extern int reducers_per_worker;
extern int number_of_workers;
extern xbt_dict_t hosts;

//////////////////////
// Types
//////////////////////

/* The HdmsgHost structure is required for the creation of the various VMs (master and workers)
 * It declares the various attributes and variables that the VMs can take on. */

struct HdmsgHost
{
    int host_id;
    int is_master;
    int is_worker;
    int active_mappers;
    int active_mappers_2;
    int active_mappers_3;
    int active_mappers_4;
    int active_mappers_5;
    int active_mappers_6;
    int active_mappers_7;
    int active_mappers_8;
    int active_mappers_9;
    int active_mappers_0;
    int active_mappers_31;
    int active_mappers_32;
    int active_mappers_33;
    int active_mappers_11;
    int active_mappers_12;
    int active_mappers_13;
    int active_mappers_14;
    int active_mappers_15;
    int active_mappers_16;
    int active_mappers_17;
    int active_mappers_18;
    int active_mappers_19;
    int active_mappers_20;
    int active_mappers_00;


    //int active_mappers_snapshots;
    int map_tasks_id; //

    int active_reducers;
    int active_reducers_2;
    int active_reducers_3;
    int active_reducers_4;
    int active_reducers_5;
    int active_reducers_6;
    int active_reducers_7;
    int active_reducers_8;
    int active_reducers_9;
    int active_reducers_10;
    int active_reducers_11;
    int active_reducers_12;
    int active_reducers_13;
    int active_reducers_14;
    int active_reducers_15;
    int active_reducers_16;
    int active_reducers_17;
    int active_reducers_18;
    int active_reducers_19;
    int active_reducers_20;


    xbt_fifo_t map_tasks;
    xbt_fifo_t map_tasks_2;
    xbt_fifo_t map_tasks_3;
    xbt_fifo_t map_tasks_4;
    xbt_fifo_t map_tasks_5;
    xbt_fifo_t map_tasks_6;
    xbt_fifo_t map_tasks_7;
    xbt_fifo_t map_tasks_8;
    xbt_fifo_t map_tasks_9;
    xbt_fifo_t map_tasks_0;
    xbt_fifo_t map_tasks_31;
    xbt_fifo_t map_tasks_32;
    xbt_fifo_t map_tasks_33;
    xbt_fifo_t map_tasks_11;
    xbt_fifo_t map_tasks_12;
    xbt_fifo_t map_tasks_13;
    xbt_fifo_t map_tasks_14;
    xbt_fifo_t map_tasks_15;
    xbt_fifo_t map_tasks_16;
    xbt_fifo_t map_tasks_17;
    xbt_fifo_t map_tasks_18;
    xbt_fifo_t map_tasks_19;
    xbt_fifo_t map_tasks_20;
    xbt_fifo_t map_tasks_00;


    xbt_fifo_t reduce_tasks_2;
    xbt_fifo_t reduce_tasks_3;
    xbt_fifo_t reduce_tasks_4;
    xbt_fifo_t reduce_tasks_5;
    xbt_fifo_t reduce_tasks_6;
    xbt_fifo_t reduce_tasks_7;
    xbt_fifo_t reduce_tasks_8;
    xbt_fifo_t reduce_tasks_9;
    xbt_fifo_t reduce_tasks_10;
    xbt_fifo_t reduce_tasks_11;
    xbt_fifo_t reduce_tasks_12;
    xbt_fifo_t reduce_tasks_13;
    xbt_fifo_t reduce_tasks_14;
    xbt_fifo_t reduce_tasks_15;
    xbt_fifo_t reduce_tasks_16;
    xbt_fifo_t reduce_tasks_17;
    xbt_fifo_t reduce_tasks_18;
    xbt_fifo_t reduce_tasks_19;
    xbt_fifo_t reduce_tasks_20;
    xbt_fifo_t shuffle_tasks;
    xbt_fifo_t move_tasks;
    xbt_fifo_t tasks;
    xbt_fifo_t move_reduce_tasks;
    xbt_fifo_t shuffle_tasks_2;
    xbt_fifo_t map_tasks_snapshots;

    const char *host_name;
    
    msg_host_t host;
    
     xbt_fifo_t mappers;     // = mappers_per_worker
    xbt_fifo_t reducers;    // = reducers_per_worker

    xbt_fifo_t mappers_2;
    xbt_fifo_t mappers_3;
    xbt_fifo_t mappers_4;
    xbt_fifo_t mappers_5;
    xbt_fifo_t mappers_6;
    xbt_fifo_t mappers_7;
    xbt_fifo_t mappers_8;
    xbt_fifo_t mappers_9;
    xbt_fifo_t mappers_0;
    xbt_fifo_t mappers_31;
    xbt_fifo_t mappers_32;
    xbt_fifo_t mappers_33;
    xbt_fifo_t mappers_11;
    xbt_fifo_t mappers_12;
    xbt_fifo_t mappers_13;
    xbt_fifo_t mappers_14;
    xbt_fifo_t mappers_15;
    xbt_fifo_t mappers_16;
    xbt_fifo_t mappers_17;
    xbt_fifo_t mappers_18;
    xbt_fifo_t mappers_19;
    xbt_fifo_t mappers_20;
    xbt_fifo_t mappers_00;

    xbt_fifo_t reducers_2;
    xbt_fifo_t reducers_3;
    xbt_fifo_t reducers_4;
    xbt_fifo_t reducers_5;
    xbt_fifo_t reducers_6;
    xbt_fifo_t reducers_7;
    xbt_fifo_t reducers_8;
    xbt_fifo_t reducers_9;
    xbt_fifo_t reducers_10;
    xbt_fifo_t reducers_11;
    xbt_fifo_t reducers_12;
    xbt_fifo_t reducers_13;
    xbt_fifo_t reducers_14;
    xbt_fifo_t reducers_15;
    xbt_fifo_t reducers_16;
    xbt_fifo_t reducers_17;
    xbt_fifo_t reducers_18;
    xbt_fifo_t reducers_19;
    xbt_fifo_t reducers_20;
    xbt_fifo_t shuffle_senders;
    xbt_fifo_t movers;
    xbt_fifo_t shuffle_senders_2;
    xbt_fifo_t mappers_snapshots; //newly introduced mappers_snapshots per worker.


};


//////////////////////
// Prototypes
//////////////////////

/*After the creation of the HdmsgHost structure,
 * the structure is implemented as pointer to create new host processes with their attributes. */

struct HdmsgHost *newHdmsgHost(int, msg_host_t, char *);

/* These prototypes enable the number of 'mappers, shufflers
 * and reducers on newly created worker hosts to be enumerated */

int get_mapper_count(struct HdmsgHost *);
int get_mapper_count_3(struct HdmsgHost *);
int get_mapper_count_4(struct HdmsgHost *);
int get_mapper_count_5(struct HdmsgHost *);
int get_mapper_count_6(struct HdmsgHost *);
int get_mapper_count_7(struct HdmsgHost *);
int get_mapper_count_8(struct HdmsgHost *);
int get_mapper_count_9(struct HdmsgHost *);
int get_mapper_count_0(struct HdmsgHost *);
int get_mapper_count_11(struct HdmsgHost *);
int get_mapper_count_12(struct HdmsgHost *);

int get_shuffler_count(struct HdmsgHost *);
int get_movers_count(struct HdmsgHost *);
int get_shuffler_count_2(struct HdmsgHost *);
int get_reducer_count(struct HdmsgHost *);
int get_reducer2_count(struct HdmsgHost *);
int get_reducer3_count(struct HdmsgHost *);
int get_reducer4_count(struct HdmsgHost *);
int get_reducer5_count(struct HdmsgHost *);
int get_reducer6_count(struct HdmsgHost *);
int get_reducer7_count(struct HdmsgHost *);
int get_reducer8_count(struct HdmsgHost *);
int get_reducer9_count(struct HdmsgHost *);
int get_reducer10_count(struct HdmsgHost *);
int get_reducer11_count(struct HdmsgHost *);
int get_reducer12_count(struct HdmsgHost *);
/*These functions enable implementable methods of HdmsgHost structure to be declared here
 * and defined in the HdmsgHost.c file. */

void add_map_task(struct HdmsgHost *, double);
void add_map_task_2(struct HdmsgHost *, double);
void add_map_task_3(struct HdmsgHost *, double);
void add_map_task_4(struct HdmsgHost *, double);
void add_map_task_5(struct HdmsgHost *, double);
void add_map_task_6(struct HdmsgHost *, double);
void add_map_task_7(struct HdmsgHost *, double);
void add_map_task_8(struct HdmsgHost *, double);
void add_map_task_9(struct HdmsgHost *, double);
void add_map_task_0(struct HdmsgHost *, double);
void add_map_task_11(struct HdmsgHost *, double);
void add_map_task_12(struct HdmsgHost *, double);
void partition_map_task(struct HdmsgHost *, double);
void partition_map_task_2(struct HdmsgHost *, double);
void move_map_task(struct HdmsgHost *, double);

void activate_mappers(struct HdmsgHost*);
void activate_mappers_2(struct HdmsgHost*);
void activate_mappers_3(struct HdmsgHost*);
void activate_mappers_4(struct HdmsgHost*);
void activate_mappers_5(struct HdmsgHost*);
void activate_mappers_6(struct HdmsgHost*);
void activate_mappers_7(struct HdmsgHost*);
void activate_mappers_8(struct HdmsgHost*);
void activate_mappers_9(struct HdmsgHost*);
void activate_mappers_0(struct HdmsgHost*);
void activate_mappers_11(struct HdmsgHost*);
void activate_mappers_12(struct HdmsgHost*);
void activate_reducers(struct HdmsgHost *);
void activate_reducers_2(struct HdmsgHost *);
void activate_reducers_3(struct HdmsgHost *);
void activate_reducers_4(struct HdmsgHost *);
void activate_reducers_5(struct HdmsgHost *);
void activate_reducers_6(struct HdmsgHost *);
void activate_reducers_7(struct HdmsgHost *);
void activate_reducers_8(struct HdmsgHost *);
void activate_reducers_9(struct HdmsgHost *);
void activate_reducers_10(struct HdmsgHost *);
void activate_reducers_11(struct HdmsgHost *);
void activate_reducers_12(struct HdmsgHost *);



/* This fuction is implemented to free up memory spaces when host complete
 *  the map, shuffle and reduce processes.
 *  It is declare here and defined in the HdmsgHost.c file. */

void destroyHdmsgHost(struct HdmsgHost *);

struct task_info_s
   {
	 size_t   id;
   };

typedef struct task_info_s* task_info_t;



#endif /* HdmsgHost_h */
