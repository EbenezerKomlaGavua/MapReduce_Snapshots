/* Copyright (c) 2010-2014. The SimGrid Team.
 * All rights reserved.                                                     */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

/* Currently, the  way to compile this file is to run the make file  is is
 * interchanging gcc-6 with g++ (if you run make with g++ first, it fails,
 * try gcc-6 and revert to g++*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include<sys/wait.h>
#include <sys/wait.h>
#include "HdmsgHost.h"
#include "simgrid/msg.h"
#include "xbt/sysdep.h"
#include "HostScheduler.c"
#include "DistributeHdfsChunks.c"
#include "Shufflers.c"
#include "xbt/log.h"
#include "xbt/asserts.h"
#include "xbt/xbt_os_time.h"
#include "Processes.c"
int task_count = -1;
int reduce_task_count = -1;

int NumOfReduceTasks =1;//25=>1000
// TODO:  set the number of reduceTasks!

int number_tasks;
/* This generates messages according to msg configurations.
 *  It is implemented through out the simulator to highlight what is occurring.*/
XBT_LOG_NEW_DEFAULT_CATEGORY(hdmsgCat, "Messages specific for this msg application");


/*Structure to collate the execution times during the Map Phase*/
struct ExeTimes
{
	char name[30];
	char Endhostname[30];
	char TransferStarthost[30];
	char TransferEndhost[30];
	int pid;
	int id;
	float Stop_Times;
	float TransferStart_Times;
	float TransferStop_Times;
	float times;
	float Terminated_Times;
	float exec_Times;
	char task_status[30];
	char NodeStatus[30];
	char TaskUpdatedNodeStatus[30];

};
struct ExeTimes map1_times[100000], map2_times[100000], map3_times[100000], map4_times[100000], map5_times[100000],
map6_times[100000], map7_times[100000],	map8_times[100000], map9_times[100000], map10_times[100000],  map11_times[100000], map12_times[100000];
int firsttask=0, secondtask=0, thirdtask=0, fourthtask=0, fifthtask=0, sixthtask=0, seventhtask=0, eighthtask=0, ninthtask=0,
		tenthtask=0, elevetask=0, tweltask=0, thirtntask=0, fourtntask=0, fiftntask=0;

/*Structure to collate the execution times of specific period  during the Map Phase*/
struct snapExeTimes
{
	char name[30];
	int id;
	int pid;
	int starthost;
	float times;
};
struct snapExeTimes transferTimes[10000];
struct snapExeTimes transferTimes2[10000];
struct snapExeTimes snapmap1_times[10000], snapmap2_times[10000], snapmap3_times[10000], snapmap4_times[10000], snapmap5_times[10000],
	snapmap6_times[10000], snapmap7_times[10000], snapmap8_times[10000], snapmap9_times[10000], snapmap10_times[10000];
int taskOne=0, taskTwo=0, taskThree=0, taskFour=0, taskFive=0, taskSix=0, taskSeven=0, taskNine=0, taskEight=0, taskTen=0;

/*Structure to collate the execution times during the Reduce Phase*/
struct ReduceExttimes
{
	char namee[30];
	char finish_host[30];
	int idd;
	int pidd;
	float launch_times;
	float finish_Times;
	float redtimes;
	char TrferStarthost[30];
	char TrferEndhost[30];
	float TrferStart_Times;
	float TrferStop_Times;
	char NodeStatus[30];
	char task_status[30];
	char TaskUpNodeStatus[30];
};
struct ReduceExttimes reduce1_times[10000], reduce2_times[10000], reduce3_times[10000], reduce4_times[10000],
reduce5_times[10000], reduce6_times[10000], reduce7_times[10000], reduce8_times[10000], reduce9_times[10000], reduce10_times[10000],
reduce11_times[10000], reduce12_times[10000];

int firstredtask= 0, secondredtask= 0, thirdredtask= 0, fourthredtask= 0, fifthredtask= 0, sixthredtask = 0, seventhredtask= 0, eightthredtask= 0,
		ninthredtask= 0, tenthredtask= 0, eleveredtask= 0, twelveredtask= 0;

/*Structure to collate the execution times of specific period  during the Reduce Phase*/
struct RedSnapExttimes
{
	char namee[30];
	int idd;
	int starthost;
	float redsnaptimes;
};
struct RedSnapExttimes redsnap1_times[10000], redsnap2_times[10000], redsnap3_times[10000], redsnap4_times[10000],  redsnap5_times[10000], redsnap6_times[10000],
redsnap7_times[10000], redsnap8_times[10000], redsnap9_times[10000], redsnap10_times[10000];

int snapredtask_1 = 0, snapredtask_2 = 0, snapredtask_3 = 0, snapredtask_4 = 0, snapredtask_5 = 0, snapredtask_6 = 0, snapredtask_7 = 0, snapredtask_8 = 0, snapredtask_9 = 0,
		snapredtask_10 = 0;

/* Prototypes */

/*The following methods declared below, are implemented at key areas throughout the simulator.*/
//double get_initialization_cost(msg_host_t);

int random_int(int min, int max);
double get_bytes_to_shuffle();
double get_bytes_to_shuffle_2();
double get_bytes_to_shuffle_3();
double get_bytes_to_shuffle_4();
double get_bytes_to_move();
double get_reduce_cost(msg_host_t);
double get_reduce_cost_2(msg_host_t);
double get_reduce_cost_3(msg_host_t);
double Log2(double);
void Schedulehosts();
double exec_function_20();


/* Process Prototypes */

/* The following functions declared between are utilized to call the key processes of this simulator.
 * The master is called to initiate the master process, which communicates information to hosts.
 * The initializeProcs is called by the master process to transmit general data processing information to all processes.
 * The map, shuffleSend,shuffleReceive and reduce methods are called at specific areas to ensure data processing */

int master(int argc, char *argv[]);
int initializeProcs(int argc, char * argv[]);
int map(int argc, char * argv[]);
int map_2(int argc, char * argv[]);
int map_3(int argc, char * argv[]);
int map_4(int argc, char * argv[]);
int map_5(int argc, char * argv[]);
int map_6(int argc, char * argv[]);
int map_7(int argc, char * argv[]);
int map_8(int argc, char * argv[]);
int map_9(int argc, char * argv[]);
int map_0(int argc, char * argv[]);
int map_11(int argc, char * argv[]);
int map_12(int argc, char * argv[]);
int reduce(int argc, char * argv[]);
int reduce_2(int argc, char * argv[]);
int reduce_3(int argc, char * argv[]);
int reduce_4(int argc, char * argv[]);
int reduce_5(int argc, char * argv[]);
int reduce_6(int argc, char * argv[]);
int reduce_7(int argc, char * argv[]);
int reduce_8(int argc, char * argv[]);
int reduce_9(int argc, char * argv[]);
int reduce_10(int argc, char * argv[]);
int reduce_11(int argc, char * argv[]);
int reduce_12(int argc, char * argv[]);

struct host_snapshots{
	char name[10];
	int mappers;
	int reducers;
};
struct host_snapshots snaps[2];

/*This variables are used to monitor the number of hosts running slowly */
double times[2][4];
double runtimes[2][4][2];
//double reduce_times[4][2];
char hosttimes[4][20];
int i=0;
int j=0;

/* The iMapper and jMapper variables are utilized to control number of tasks passed to host1 and host2 when controlling tasks input.*/
int iMapper =1;
int jMapper =1;

/* Constants */
int MAPTASK2_WAIT_DURATION =1; //0.008734700
float  LASTMAPTASK_BEGIN_DURATION = 0.009034700; //0.008734700
float  HOSTWAIT_TIME = 0.002734700;




/* Globals */
double MAP_CALIBRATION_FACTOR;
double REDUCE_CALIBRATION_FACTOR;

xbt_dict_t hosts;		// A structure created to hold hosts VMs.
xbt_dict_t host_attributes; // This structure holds the various attributes of the hosts VMs.

/* Declaration of variables for map,shuffle and reduce processes.
 * These variables enables the key processes to communicate effectively */

int number_of_hosts;
int number_of_workers;

long reducers_5;
long reducers_6;
long reducers_7;
long reducers_8;
long reducers_9;
long reducers_10;
long reducers_11;
long reducers_12;
long mappers_2;
long mappers_3;
long mappers_4;
long mappers_5;
long mappers_6;
long mappers_7;
long mappers_8;
long mappers_9;
long mappers_0;
long mappers_11;
long mappers_12;


long input_size_bytes_2;
long input_size_bytes_3;
long input_size_bytes_4;

long hdfs_chunk_size_2;
long hdfs_chunk_size_0;
long hdfs_chunk_size_4;
long hdfs_chunk_size_3;

double sim_map;
double sim_map_2;
double sim_map_3;
double sim_map_4;
double sim_map_5;
double sim_map_6;
double sim_map_7;
double sim_map_8;
double sim_map_9;
double sim_map_0;
double sim_map_11;
double sim_map_12;
double total_exec_time;
double Input_Data;
double sim_mapp_0;
double sim_reduce_0;
double sim_reduce;
double sim_reduce_2;
double sim_reduce_3;
double sim_reduce_4;
double sim_reduce_5;
double sim_reduce_6;
double sim_reduce_7;
double sim_reduce_8;
double sim_reduce_9;
double sim_reduce_10;
double sim_reduce_11;
double sim_reduce_12;

char TaskUpNodeStatus[20];
char Red_TaskUpNodeSt[20];
char Task_status[30];
char Node_status[30];

double Maptask1Total_cpu_power;
double MaptTask1Av_cpu_power;
double Host_speed;



double Map1ExecTime;
double Map2ExecTime;
double Map3ExecTime;
double Map4ExecTime;
double Map5ExecTime;
double Map6ExecTime;
double Map7ExecTime;
double Map8ExecTime;
double Map9ExecTime;
double Map10ExecTime;
double Reduce1ExecTime;
double Reduce2ExecTime;
double Reduce3ExecTime;
double Reduce4ExecTime;
double Reduce5ExecTime;
double Reduce6ExecTime;
double Reduce7ExecTime;
double Reduce8ExecTime;
double Reduce9ExecTime;
double Reduce10ExecTime;


double mapSnaps_9;
double mapSnaps_8;
double mapSnaps_7;
double mapSnaps_6;
double mapSnaps_5;
double mapSnaps_4;
double mapSnaps_3;
double mapSnaps_2;


double reduceSnaps_10;
double reduceSnaps_9;
double reduceSnaps_8;
double reduceSnaps_7;
double reduceSnaps_6;
double reduceSnaps_5;
double reduceSnaps_4;
double reduceSnaps_3;
double reduceSnaps_2;
double reduceSnaps_1;
int transfer_started;
/* Average Simulation map*/
long D_sim_map;
int Y = 0.3;



/* This function creates the master process which is utilized to initialize the map, shuffle and reduce processes.
 *All variables are set to zero(0) before the master process is initialized.
 *The master initializes all processes on each host.   */


/* Master Process */
int master(int argc, char *argv[])
{
    char * key;
    struct HdmsgHost *hdmsg_host;
    xbt_dict_cursor_t cursor = NULL;

    int i = 0;
    double startTime = 2;
    
    long remaining_inits = 0;
    long remaining_mappers = 0;
    long remaining_mappers_2 = 0; // created remaining_mappers2 to handle the processes of MapTask2
    long remaining_mappers_3 = 0;
    long remaining_mappers_4 = 0;
    long remaining_mappers_5 = 0;
    long remaining_mappers_6 = 0;
    long remaining_mappers_7 = 0;
    long remaining_mappers_8 = 0;
    long remaining_mappers_9 = 0;
    long remaining_mappers_0 = 0;
    long remaining_mappers_11 = 0;
    long remaining_mappers_12 = 0;
    long remaining_shufflers = 0;
    long remaining_shufflers_2 = 0;
    long remaining_movers = 0;
    long remaining_reducers = 0;
    long remaining_reducers_2 = 0;
    long remaining_reducers_3 = 0;
    long remaining_reducers_4 = 0;
    long remaining_reducers_5 = 0;
    long remaining_reducers_6 = 0;
    long remaining_reducers_7 = 0;
    long remaining_reducers_8 = 0;
    long remaining_reducers_9 = 0;
    long remaining_reducers_10 = 0;
    long remaining_reducers_11 = 0;
    long remaining_reducers_12 = 0;
    long expected_messages = 0;


    /*The following variables and objects compose some of the msg communication tools
    * for message transmission between the master and workers. */

    msg_comm_t res_irecv;
    msg_task_t task_com;	// Communicates tasks messages from master to workers.
    msg_task_t *tasks = xbt_new(msg_task_t, number_of_workers); 	// creates a new task to the sent to worker hosts.
    xbt_dynar_t comms = xbt_dynar_new(sizeof(msg_comm_t), NULL);	// creates a message to be communicated to workers.
    
    XBT_INFO("INITIALIZATION BEGIN");

    // Initialize processes (mappers, shufflers, and reducers) on each host
    xbt_dict_foreach(hosts, cursor, key, hdmsg_host)
    {
        if (hdmsg_host->is_worker)
        {
            MSG_process_create("Init", initializeProcs, NULL, hdmsg_host->host);
            tasks[remaining_inits] = NULL;
            res_irecv = MSG_task_irecv(&tasks[remaining_inits], "master"); // Host workers receive information the master to begin processing
            xbt_dynar_push_as(comms, msg_comm_t, res_irecv);
            remaining_inits++;
        }

    }
    
    while (!xbt_dynar_is_empty(comms))
    {

        xbt_dynar_remove_at(comms, MSG_comm_waitany(comms), &res_irecv);
        task_com = MSG_comm_get_task(res_irecv);

        if (!strcmp(MSG_task_get_name(task_com), "init_exit"))
        {

        	msg_host_t h = MSG_task_get_source(task_com);
            MSG_task_destroy(task_com);
            
            const char *host_name = MSG_host_get_name(h);
            struct HdmsgHost *hdmsg_host = xbt_dict_get(hosts, host_name);
            
            remaining_mappers += get_mapper_count(hdmsg_host);
            remaining_mappers_2 += get_mapper_2_count(hdmsg_host); 				// Obtained the number of mappers to connect to hosts from get_mapper2_count
            remaining_mappers_3 += get_mapper_3_count(hdmsg_host); 				// Obtained the number of mappers to connect to hosts from get_mapper3_count
            remaining_mappers_4 += get_mapper_4_count(hdmsg_host); 				// Obtained the number of mappers to connect to hosts from get_mapper4_count
            remaining_mappers_5 += get_mapper_5_count(hdmsg_host); 				// Obtained the number of mappers to connect to hosts from get_mapper4_count
            remaining_mappers_6 += get_mapper_6_count(hdmsg_host);
            remaining_mappers_7 += get_mapper_7_count(hdmsg_host);
            remaining_mappers_8 += get_mapper_8_count(hdmsg_host);
            remaining_mappers_9 += get_mapper_9_count(hdmsg_host);
            remaining_mappers_0 += get_mapper_0_count(hdmsg_host);
            remaining_mappers_11 += get_mapper_11_count(hdmsg_host);
            remaining_mappers_12 += get_mapper_12_count(hdmsg_host);
            remaining_shufflers += get_shuffler_count(hdmsg_host);
            remaining_movers += get_movers_count(hdmsg_host);
            remaining_reducers += get_reducer_count(hdmsg_host);
            remaining_reducers_2 += get_reducer2_count(hdmsg_host);  // INTRODUCED REMAINING_REDUCERS_2 TO MONITOR THE NUMBER OF REDUCERS FOR REDUCE TASK 2.
            remaining_reducers_3 += get_reducer3_count(hdmsg_host);
            remaining_reducers_4 += get_reducer4_count(hdmsg_host);
            remaining_reducers_5 += get_reducer5_count(hdmsg_host);
            remaining_reducers_6 += get_reducer6_count(hdmsg_host);
            remaining_reducers_7 += get_reducer7_count(hdmsg_host);
            remaining_reducers_8 += get_reducer8_count(hdmsg_host);
            remaining_reducers_9 += get_reducer9_count(hdmsg_host);
            remaining_reducers_10 += get_reducer10_count(hdmsg_host);
            remaining_reducers_11 += get_reducer11_count(hdmsg_host);
            remaining_reducers_12 += get_reducer12_count(hdmsg_host);
            remaining_inits--;

            if (remaining_inits == 0)
            {
                XBT_INFO("INITIALIZATION COMPLETE");

                // Add an extra message to account for the message sent when the shuffle phase begins
                expected_messages = 1 + remaining_mappers + remaining_shufflers + remaining_reducers + remaining_mappers_2
                		+ remaining_reducers_2 + remaining_reducers_3 +remaining_reducers_4	+remaining_reducers_5 +remaining_reducers_6
						+remaining_reducers_7 +remaining_reducers_8 +remaining_reducers_9 +remaining_reducers_10+ remaining_mappers_3
						+ remaining_mappers_4 + remaining_mappers_5 + remaining_mappers_6 + remaining_mappers_7 + remaining_mappers_8
						+ remaining_mappers_9 + remaining_mappers_0 + remaining_mappers_11 + remaining_mappers_12 + remaining_reducers_11 + remaining_reducers_12;

                free(tasks);
                tasks = xbt_new(msg_task_t, expected_messages);
                for (i = 0; i < expected_messages; i++)
                {
                    tasks[i] = NULL;
                    res_irecv = MSG_task_irecv(&tasks[i], "master");
                    xbt_dynar_push_as(comms, msg_comm_t, res_irecv);
                }

                XBT_INFO("MAP PHASE BEGIN");
                
                // Activate Mappers
                xbt_dict_foreach(hosts, cursor, key, hdmsg_host)
                {
                    activate_mappers(hdmsg_host);
                	activate_mappers_2(hdmsg_host);
                	activate_mappers_3(hdmsg_host);
                	activate_mappers_4(hdmsg_host);
                	activate_mappers_5(hdmsg_host);
                	activate_mappers_6(hdmsg_host);
                	activate_mappers_7(hdmsg_host);
                	activate_mappers_8(hdmsg_host);
                	activate_mappers_9(hdmsg_host);
                	activate_mappers_0(hdmsg_host);
                	activate_mappers_11(hdmsg_host);
                	activate_mappers_12(hdmsg_host);
                }
            }
        }

        else if (!strcmp(MSG_task_get_name(task_com), "shuffle_start"))  // communicates information about the commencement of shuffle processes
        {
            XBT_INFO("SHUFFLE PHASE BEGIN");                             // General announcement about the commencement of shuffling.
        }
        else if (!strcmp(MSG_task_get_name(task_com), "map_exit"))
        {
        	remaining_mappers--;
        	remaining_mappers_2--;
            remaining_mappers_3--;
            remaining_mappers_4--;
            remaining_mappers_5--;

        	if (remaining_mappers == 0 && remaining_mappers_2 == 0 && remaining_mappers_3 == 0 && remaining_mappers_4 == 0
        			&& remaining_mappers_5 == 0 && remaining_mappers_6 == 0)
            {
            	XBT_INFO("MAP PHASE 1 COMPLETE");
            }

        	if (remaining_mappers_7 == 0 && remaining_mappers_8 == 0&& remaining_mappers_9 == 0 && remaining_mappers_0 == 0
        			&& remaining_mappers_11 == 0 && remaining_mappers_12 == 0)
        	{
        		XBT_INFO("MAP PHASE 7 COMPLETE");
        	}
        }
        else if (!strcmp(MSG_task_get_name(task_com), "shuffle_exit"))
        {
            remaining_shufflers--;								// all the remaining shuffling processes are executed.
            if (remaining_shufflers == 0)				// the shufflers are compared to 0 to ensure that all processes have been executed.
            {
                XBT_INFO("SHUFFLE PHASE COMPLETE");
                XBT_INFO("REDUCE PHASE BEGIN");

                // Activate Reducers
                xbt_dict_foreach(hosts, cursor, key, hdmsg_host)
                {
                    activate_reducers(hdmsg_host);
                    activate_reducers_2(hdmsg_host);
                    activate_reducers_3(hdmsg_host);
                    activate_reducers_4(hdmsg_host);
                    activate_reducers_5(hdmsg_host);
                    activate_reducers_6(hdmsg_host);
                    activate_reducers_7(hdmsg_host);
                    activate_reducers_8(hdmsg_host);
                    activate_reducers_9(hdmsg_host);
                    activate_reducers_10(hdmsg_host);
                    activate_reducers_11(hdmsg_host);
                    activate_reducers_12(hdmsg_host);
                }
            }
        }
        else if (!strcmp(MSG_task_get_name(task_com), "reduce_exit"))
        {
            remaining_reducers--; 				// Execute all the reducer processes left in the queue.
            remaining_reducers_2--;
            remaining_reducers_3--;
            remaining_reducers_4--;
            remaining_reducers_5--;
            remaining_reducers_6--;
            remaining_reducers_7--;
            remaining_reducers_8--;
            remaining_reducers_9--;
            remaining_reducers_10--;


            if (remaining_reducers == 0 && remaining_reducers_2 == 0 && remaining_reducers_3 == 0 && remaining_reducers_4 == 0
            		&& remaining_reducers_5 == 0 && remaining_reducers_6 == 0 && remaining_reducers_7 == 0 && remaining_reducers_8 == 0
					&& remaining_reducers_9 == 0 && remaining_reducers_10 == 0  && remaining_reducers_11 == 0 && remaining_reducers_12 == 0)

            {
                XBT_INFO("REDUCE PHASE COMPLETE");
            }
        }
        else
        {
            printf("*** MAP PHASE ERROR Received unexpected task: %s\n", MSG_task_get_name(task_com));
        }
    }
    
    free(tasks);						// Once all the tasks have been completely executed, the memory allocations are freed up.
    return 0;
}                               /* end_of_master */

// TODO:  begining of all tasks functions!
/** Map Process */
int map(int argc, char * argv[])
{
   double start_time;
   double stop_time;
   int j;
   int i;
   int k;
   const int num_hosts =9;
   double Execution_Times2;
   double Execution_Time1;
   char Node_statu[30];
   char name[5];
   char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
   char str[] = "host2-Mapper-1";
    double bytes_to_shuffle = get_bytes_to_shuffle();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    while (xbt_fifo_size(this_host->map_tasks) > 0 )
    {
    	// Do map tasks
        msg_task_t map_task = xbt_fifo_pop(this_host->map_tasks);

        if (map_task != NULL)

        {
      //  	XBT_INFO("%s Mapper  1 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	// takes snapshots of mappers
        	if(strncmp(snaps[0].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        		snaps[0].mappers++;
        	else
        		snaps[1].mappers++;
        	//take_snapshot();
        	int end;
        	int start;
        	start = MSG_process_self_PPID();
            start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK


           Schedulehosts();
            const char *host_name = MSG_host_get_name(MSG_host_self());
        	int number = MSG_get_host_number();
        	Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=9)&& (map_task > 0))
        		{
        		 strcpy(Node_statu, "S_Node");
        		 }
        	else
        		{
        		strcpy(Node_statu, "F_Node");
        		}
        	// Execute the map task

        	MSG_task_execute(map_task);
        	task_count = task_count + 1;
        	Execution_Times2= MSG_get_clock() - start_time;
        	int host= MSG_process_self_PPID();
        	Execution_Time1=exec_function_20(host,Execution_Times2);

           const char *stop_host = MSG_host_get_name(MSG_host_self());
            sim_map += MSG_get_clock() - start_time;	// The map simulation time is obtained by subtracting the start time from the MSG CLOCK.

            stop_time =MSG_get_clock();

            if(map_task!= 0)
            	{
            	 strcpy(Task_status, "Done");
                 }
            else
          	  {
            	strcpy(Task_status, "Crushed");
              }
            /* Generating the hostnames, mappers and execution Times for MapTask  */
            for (k = 0; k<num_hosts; k++)
           {
            if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
             {
                strcpy(map1_times[firsttask].name, host_name);
                strcpy(map1_times[firsttask].Endhostname, stop_host);
                strcpy(map1_times[firsttask].task_status, Task_status);
                strcpy(map1_times[firsttask].NodeStatus, Node_statu);
                map1_times[firsttask].times = start_time;
                map1_times[firsttask].Stop_Times =stop_time;
                map1_times[firsttask].exec_Times =Execution_Time1;
                map1_times[firsttask].id = firsttask;
                map1_times[firsttask].pid = MSG_process_self_PID();
                firsttask = firsttask + 1 ;
             }
         }
            /* End of Execution Times Generation*/
            /* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */
            for (k = 0; k<num_hosts; k++)
            {
           if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
              {
                 strcpy(snapmap1_times[taskOne].name, host_name);
                 snapmap1_times[taskOne].starthost = start;
                 snapmap1_times[taskOne].times =Execution_Time1;
                 snapmap1_times[taskOne].id = taskOne;
                 snapmap1_times[taskOne].pid = MSG_process_self_PID();
                 taskOne = taskOne + 1 ;
              }
            }
             /* End of Execution Times Generation*/
            i++;
  	        if(strncmp(snaps[0].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
  	        	snaps[0].mappers--;
  	        else
  	        	snaps[1].mappers++;
  	        MSG_task_destroy(map_task);
 //  XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  		// The name of the process is displayed.

           // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
      }
    this_host->active_mappers--;

    // Notify master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    
    return 0;
}


/** Map_2 Process */
int map_2(int argc, char * argv[])
{
    double start_timee;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    double Execution_Times1;
    msg_task_t task = NULL;
    double Execution_Times2;
    char name[5];
    double terminated_time;
    double  term_ExTime;
    double Tf_Time_1;
    double Tf_Time_2;
    double Tf_Time_3;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    char str[] = "host2-Mapper-1";
    double bytes_to_shuffle = get_bytes_to_shuffle_2();
    double bytes_to_move = get_bytes_to_move();


    char Node_statuss[30];
    MSG_process_suspend(MSG_process_self());

     msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
    long Host_Speed = MSG_host_get_speed(this_host->host);
    // Forcing maptask 2 to wait till the completion of MapTask1
    while (1)
     {
       if(this_host->active_mappers> 0 )
        MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);

          else
        break;

      }
    /* Making run in chronological order*/
    while (xbt_fifo_size(this_host->map_tasks_2) > 0 )
    {
    	msg_task_t map_task_2 = xbt_fifo_pop(this_host->map_tasks_2); // SECOND MAP TASK
        if (map_task_2 != NULL)
        {
      // XBT_INFO("%s Mapper 2 of 1 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	// initializing the map process
        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++)
        	{
        	     if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	     {
        	        snaps[j].mappers++;
        	     }
        	}
        	int start;
        	int end;
        	////////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_timee =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	const char *host_name = MSG_host_get_name(MSG_host_self());
            Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
            MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

            if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&&(MSG_host_get_core_number(msg_host)<=9)&& (map_task_2 > 0))
                {
            	  strcpy(Node_statuss, "S_Node");
                }
            else
                {
            	  strcpy(Node_statuss, "F_Node");
                }

             // Execute the map task
            MSG_task_execute(map_task_2);
            task_count = task_count + 1;
             sim_map_2 += MSG_get_clock() - start_timee;
             /*** Computing the task execution time snapshots**/
            Map2ExecTime=MSG_get_clock() - start_timee;
            mapSnaps_2 =  Map1ExecTime+ Map2ExecTime;

            Execution_Times2= MSG_get_clock() - start_timee;

         if ((MSG_process_self_PPID()==67)||(MSG_process_self_PPID()==115)||(MSG_process_self_PPID()==135) ||(MSG_process_self_PPID()==253))
            {
            	Execution_Times2 = Execution_Times2-Tf_Time_2;

            }
         stop_t =MSG_get_clock();
          const char *stop_host = MSG_host_get_name(MSG_host_self());
              if(map_task_2!= 0)
               {
                strcpy(Task_status, "Done");
                }
             else
                {
                strcpy(Task_status, "Crushed");
                 }
            /* Generating the hostnames, mappers and execution Times for MapTask_2  */
              for (k = 0; k<num_hosts; k++)
            {

          if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
                strcpy(map2_times[secondtask].name, host_name);
                strcpy(map2_times[secondtask].Endhostname, stop_host);
                strcpy(map2_times[secondtask].task_status, Task_status);
            	map2_times[secondtask].times = start_timee;
            	map2_times[secondtask].Stop_Times =stop_t;
            	map2_times[secondtask].exec_Times =Execution_Times2;
            	map2_times[secondtask].id = secondtask;
            	map2_times[secondtask].pid = MSG_process_self_PID();
            	secondtask = secondtask + 1 ;
             }
            }
/* End of Execution Times Generation*/
            /* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */
              for (k = 0; k<num_hosts; k++)
                 {
             if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
             {
                  strcpy(snapmap2_times[taskTwo].name, host_name);
                  snapmap2_times[taskTwo].starthost = start;
                  snapmap2_times[taskTwo].times = Execution_Times2;
                  snapmap2_times[taskTwo].id = taskTwo;
                  snapmap2_times[taskTwo].pid = MSG_process_self_PID();
                  taskTwo = taskTwo + 1 ;
                 }
        		}
                   /* End of Execution Times Generation*/
/* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
              {
                if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
                {
                 snaps[j].mappers--;
                }
              }
/* End of active mappers generation*/

            MSG_task_destroy(map_task_2);													// Once the simulation is completed the, map task is destroyed to free up memory space.
    // XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.

            // Partition map output for shufflers to retrieve
            partition_map_task_2(this_host, bytes_to_shuffle);
        }
   }
  this_host->active_mappers_2--;
    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}


/** Map_3 Process */
int map_3(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    double start_time2;
    msg_task_t task = NULL;
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_3();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
    /* Forcing maptask 2 to wait till the completion of MapTask1*/
        while (1){
        	if(this_host->active_mappers_2> 0 )
        		MSG_process_sleep(0.0001034700);
        	else
        		break;
        }

    /*the wait ends here*/
    while (xbt_fifo_size(this_host->map_tasks_3) > 0 )
    {
        msg_task_t map_task_3 = xbt_fifo_pop(this_host->map_tasks_3);
        if (map_task_3 != NULL)
        {
      	// XBT_INFO("%s Mapper 3 is starting a map task", MSG_process_get_name(MSG_process_self()));

        	/* Returns the number of active mapper */
        	 if(strncmp(snaps[0].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	    snaps[0].mappers++;
        	 else
        	    snaps[1].mappers++;

        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	const char *host_name = MSG_host_get_name(MSG_host_self());
          Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
          MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

           if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_3 > 0))
              {
              	strcpy(Node_status, "S_Node");
              }
           else
              {
              	strcpy(Node_status, "F_Node");
              }

              // Execute the map task

           MSG_task_execute(map_task_3);
            task_count = task_count + 1;
          Execution_Times2= MSG_get_clock() - start_time;
          Map3ExecTime =MSG_get_clock() - start_time;

          /*** Computing the task execution time snapshots**/
          mapSnaps_3 =  Map1ExecTime+ Map2ExecTime+ Map3ExecTime;


          sim_map_3 += MSG_get_clock() - start_time;	// The map simulation time is obtained by subtracting the start time from the MSG CLOCK.
          stop_t =MSG_get_clock();
          const char *stop_host = MSG_host_get_name(MSG_host_self());
          if(map_task_3!= 0)
          	{
        	  strcpy(Task_status, "Done");
            }
         else
            {
              strcpy(Task_status, "Crushed");
            }

/* Generating the hostnames, mappers and execution Times for MapTask_3  */

          for (k = 0; k<num_hosts; k++)
          {

        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
            	strcpy(map3_times[thirdtask].name, host_name);
            	strcpy(map3_times[thirdtask].Endhostname, stop_host);
            	strcpy(map3_times[thirdtask].task_status, Task_status);
            	strcpy(map3_times[thirdtask].NodeStatus, Node_status);
                map3_times[thirdtask].times = start_time;
                map3_times[thirdtask].Stop_Times =stop_t;
                map3_times[thirdtask].exec_Times =Execution_Times2;
                map3_times[thirdtask].id = thirdtask;
                map3_times[thirdtask].pid = MSG_process_self_PID();
                thirdtask = thirdtask + 1;
            }
          }
/* End of Execution Times Generation*/
/* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */
          	  for (k = 0; k<num_hosts; k++)
               {

             if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                {
                 strcpy(snapmap3_times[taskThree].name, host_name);
                 snapmap3_times[taskThree].starthost = start;
                 snapmap3_times[taskThree].times =Execution_Times2;
                 snapmap3_times[taskThree].id = taskThree;
                 snapmap3_times[taskThree].pid = MSG_process_self_PID();
                 taskThree = taskThree + 1 ;
               }
        	}
             /*
             if(strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)
              */
/* End of Execution Times Generation*/
  /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
              {
                if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
                {
                 snaps[j].mappers--;
                }
              }
   /* End of active mappers generation*/
            MSG_task_destroy(map_task_3);													// Once the simulation is completed the, map task is destroyed to free up memory space.

    //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.

             // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }
   this_host->active_mappers_3--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

/** Map_4 Process */
int map_4(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    int start;
    int end;
    msg_task_t task = NULL;
    double Execution_Times1;
    double Execution_Times2;
    double  start_time2;
    char name[5];
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    char str[] = "host2-Mapper-1";
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_4();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
    /* Forcing maptask 3 to wait till the completion of MapTask1*/
        while (1){
        	if(this_host->active_mappers_3> 0 )
        		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);
        	else
        		break;
        }

        while (xbt_fifo_size(this_host->map_tasks_4) > 0 )
    {
    	// Do map tasks4
       msg_task_t map_task_4 = xbt_fifo_pop(this_host->map_tasks_4); // SECOND MAP TASK
        if (map_task_4 != NULL)
        {
     //	XBT_INFO("%s Mapper 4 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	/* initializing the map process*/
              	for(j=0;j<2;j++)
        	{
        	        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	        {
        	        	snaps[j].mappers++;
        	        }
        	}
        	////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	const char *host_name = MSG_host_get_name(MSG_host_self());
             Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
             MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

              if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_4 > 0))
                 {
                 	strcpy(Node_status, "S_Node");
                 }
              else
                 {
                 	strcpy(Node_status, "F_Node");
                 }


         /* Execute the map task*/
            MSG_task_execute(map_task_4);
            task_count = task_count + 1;
            // The map simulation time is obtained by subtracting the start time from the MSG CLOCK.
           Execution_Times2= MSG_get_clock() - start_time;
            sim_map_4 += MSG_get_clock() - start_time;

            stop_t =MSG_get_clock();

            const char *stop_host = MSG_host_get_name(MSG_host_self());


            if(map_task_4!= 0)
              {
               strcpy(Task_status, "Done");
              }
            else
               {
               strcpy(Task_status, "Crushed");
               }
            // The map simulation time is obtained by subtracting the start time from the MSG CLOCK.
/* Generating the hostnames, mappers and execution Times for MapTask_4  */

            for (k = 0; k<num_hosts; k++)
            {

           if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
            	strcpy(map4_times[fourthtask].name, host_name);
            	strcpy(map4_times[fourthtask].Endhostname, stop_host);
            	strcpy(map4_times[fourthtask].task_status, Task_status);
                map4_times[fourthtask].times = start_time;
                map4_times[fourthtask].Stop_Times =stop_t;
                map4_times[fourthtask].exec_Times =Execution_Times2;
                map4_times[fourthtask].id = fourthtask;
                map4_times[fourthtask].pid = MSG_process_self_PID();
                fourthtask = fourthtask + 1;
            }
          }

/* End of Execution Times Generation*/
 /* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */
            	for (k = 0; k<num_hosts; k++)
              	  {
                 if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                {
                strcpy(snapmap4_times[taskFour].name, host_name);
                snapmap4_times[taskFour].starthost = start;
                snapmap4_times[taskFour].times = Execution_Times2;
                snapmap4_times[taskFour].id = taskFour;
                snapmap4_times[taskFour].pid = MSG_process_self_PID();
                taskFour = taskFour + 1 ;
              }
            }
            /*
        //    if(strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)

/* End of Execution Times Generation*/
  /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
              {
                    snaps[j].mappers--;
                }
            }
   /* End of active mappers generation*/
            MSG_task_destroy(map_task_4);													// Once the simulation is completed the, map task is destroyed to free up memory space.
       //  XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
           // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }

   this_host->active_mappers_4--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}


/** Map_5 Process */
int map_5(int argc, char * argv[])
{
    double start_time;
    double start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_5();
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    /* Forcing maptask 4 to wait till the completion of MapTask1*/
    while (1){
        	if(this_host->active_mappers_4> 0 )
        		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);//LASTMAPTASK_BEGIN_DURATION,0.008734700
        	else
        		break;
        }

    /*the wait ends here*/
    while (xbt_fifo_size(this_host->map_tasks_5) > 0 )
    {
    	// Do map tasks5
        msg_task_t map_task_5 = xbt_fifo_pop(this_host->map_tasks_5); // SECOND MAP TASK
        if (map_task_5 != NULL)
        {
     //  	XBT_INFO("%s Mapper 5 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	// initializing the map process
        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++)
        	{
        		 if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)

        	     {
        	        snaps[j].mappers++;
        	      }
        	}
        	//take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

           	Execution_Times1 = MSG_get_clock() - start_time;

        	  const char *host_nam = MSG_host_get_name(MSG_host_self());
              Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
              MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

              if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_5 > 0))
                  {
                   strcpy(Node_status, "S_Node");
                  }
              else
                   {
                     strcpy(Node_status, "F_Node");
                   }
              // Execute the map task
            MSG_task_execute(map_task_5);
            task_count = task_count + 1;
           Execution_Times2 = MSG_get_clock() - start_time;
           sim_map_5 += MSG_get_clock() - start_time;

           stop_t =MSG_get_clock();
           const char *stop_host = MSG_host_get_name(MSG_host_self());
            if(map_task_5!= 0)
               {
                 strcpy(Task_status, "Done");
               }
            else
               {
                 strcpy(Task_status, "Crushed");
               }

            /* Generating the hostnames, mappers and execution Times for MapTask_5  */
            for (k = 0; k<num_hosts; k++)
            {
            if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
            	strcpy(map5_times[fifthtask].name, host_nam);
            	strcpy(map5_times[fifthtask].Endhostname, stop_host);
            	strcpy(map5_times[fifthtask].task_status, Task_status);
                 map5_times[fifthtask].times = start_time;
                 map5_times[fifthtask].Stop_Times =stop_t;
            	 map5_times[fifthtask].exec_Times =Execution_Times2;
            	 map5_times[fifthtask].id = fifthtask;
            	 map5_times[fifthtask].pid = MSG_process_self_PID();
            	 fifthtask = fifthtask + 1;
             }
           }

/* End of Execution Times Generation*/
/* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */
            for (k = 0; k<num_hosts; k++)
            {
            if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
               {
                 strcpy(snapmap5_times[taskFive].name, host_nam);
                 snapmap5_times[taskFive].starthost = start;
                 snapmap5_times[taskFive].times =   Execution_Times2;
                 snapmap5_times[taskFive].id = taskFive;
                 snapmap5_times[taskFive].pid = MSG_process_self_PID();
                 taskFive = taskFive + 1;
               }
            }

            /* End of Execution Times Generation*/
            /* Generation of the number of active mappers on a host*/
            i++;
           for(j=0;j<2;j++)
           {
        	   if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	   {
        		   snaps[j].mappers--;
        	   }
           }
           /* End of active mappers generation*/

            MSG_task_destroy(map_task_5);													// Once the simulation is completed the, map task is destroyed to free up memory space.

       //     XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.

            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }

   this_host->active_mappers_5--;

    // Notify master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}
// TODO:  Middle of Maptasks!

/** Map_6 Process */
int map_6(int argc, char * argv[])
{
    double start_time;
    double start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    double D = 0.5;
    int k;
    const int num_hosts =9;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_6();
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
    while (1)
    {
        	if(this_host->active_mappers_5> 0 )
        		MSG_process_sleep(0.0001034700);
        	else
        		break;
    }

    		while (xbt_fifo_size(this_host->map_tasks_6) > 0 )
    		{
    		msg_task_t map_task_6 = xbt_fifo_pop(this_host->map_tasks_6); // SECOND MAP TASK
        	if (map_task_6 != NULL)
        	{
   //    	XBT_INFO("%s Mapper 6 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	// initializing the map process

        	for(j=0;j<2;j++)
        	{
        	  if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	{
        	  snaps[j].mappers++;
        	 }
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK


            Execution_Times1 = MSG_get_clock() - start_time;
            const char *host_name = MSG_host_get_name(MSG_host_self());
             Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
             MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

             if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_6 > 0))
                 {
                    strcpy(Node_status, "S_Node");
                 }
            else
                  {
                     strcpy(Node_status, "F_Node");
                  }

             // Execute the map task
            MSG_task_execute(map_task_6);
            task_count = task_count + 1;


              Execution_Times2= MSG_get_clock() - start_time;
             sim_map_6 += MSG_get_clock() - start_time;

             stop_t =MSG_get_clock();
          const char *stop_host = MSG_host_get_name(MSG_host_self());
             if(map_task_6!= 0)
               {
                 strcpy(Task_status, "Done");
               }
             else
                {
                 strcpy(Task_status, "Crushed");
                }

            /* Generating the hostnames, mappers and execution Times for MapTask_3  */

             for (k = 0; k<num_hosts; k++)
             {

          if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
                strcpy(map6_times[sixthtask].name, host_name);
                strcpy(map6_times[sixthtask].Endhostname, stop_host);
                strcpy(map6_times[sixthtask].task_status, Task_status);
                strcpy(map6_times[sixthtask].NodeStatus, Node_status);
                map6_times[sixthtask].times = start_time;
                map6_times[sixthtask].Stop_Times =stop_t;
                map6_times[sixthtask].exec_Times =Execution_Times2;
                map6_times[sixthtask].id = sixthtask;
                map6_times[sixthtask].pid = MSG_process_self_PID();
                sixthtask = sixthtask + 1;
            }
          }
            /* End of Execution Times Generation*/
/* Generating the hostnames, mappers and execution Times at specific period  for MapTask  */

             for (k = 0; k<num_hosts; k++)
              {

                 if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                 {
                  strcpy(snapmap6_times[taskSix].name, host_name);
                  snapmap6_times[taskSix].starthost = start;
                  snapmap6_times[taskSix].times =  Execution_Times2;
                  snapmap6_times[taskSix].id = taskSix;
                  snapmap6_times[taskSix].pid = MSG_process_self_PID();
                  taskSix = taskSix + 1 ;
                }
        	 }

            /* End of Execution Times Generation*/
            /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
                {
            		snaps[j].mappers--;
                }
             }

            MSG_task_destroy(map_task_6);													// Once the simulation is completed the, map task is destroyed to free up memory space.

        //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.

            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }
   this_host->active_mappers_6--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

/** Map_7 Process */
int map_7(int argc, char * argv[])
{
    double start_time;
    double  start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char Node_statuss[30];
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_7();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
   /* Forcing maptask 7 to wait till the completion of MapTask6*/
        while (1){
        	if(this_host->active_mappers_6> 0 )
        		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);//0.008734700//LASTMAPTASK_BEGIN_DURATION //0.099734700
        	else
        		break;
        }

    /*the wait ends here*/
        while (xbt_fifo_size(this_host->map_tasks_7) > 0 )
    {
    	// Do map tasks_7
        msg_task_t map_task_7 = xbt_fifo_pop(this_host->map_tasks_7); // SECOND MAP TASK
        if (map_task_7 != NULL)
        {
     //	XBT_INFO("%s Mapper 7 is starting a map task", MSG_process_get_name(MSG_process_self()));
      	// initializing the map process

        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++)
        	{

        		if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        		{
        	      snaps[j].mappers++;

        		}
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	const char *host_name = MSG_host_get_name(MSG_host_self());
        	 Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	  MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	   if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_7 > 0))
        	        {
        	          	strcpy(Node_statuss, "S_Node");
        	        }
        	    else
        	       {
        	           strcpy(Node_statuss, "F_Node");
        	       }
     	   MSG_task_execute(map_task_7);
            task_count = task_count + 1;
            Execution_Times2= MSG_get_clock() - start_time;

             sim_map_7 += MSG_get_clock() - start_time;			 // The map simulation time is obtained by subtracting the start time from the MSG CLOCK.

             stop_t =MSG_get_clock();

              const char *stop_host = MSG_host_get_name(MSG_host_self());
              if(map_task_7!= 0)
               {
                strcpy(Task_status, "Done");
               }
              else
               {
                 strcpy(Task_status, "Crushed");
               }
           // XBT_INFO("%s Execution Time = %lf", MSG_process_get_name(MSG_process_self()),MSG_get_clock()-start_time );

/* Generating the hostnames, mappers and execution Times for MapTask_3  */
              for (k = 0; k<num_hosts; k++)
           {

          if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
            	strcpy(map7_times[seventhtask].name, host_name);
            	strcpy(map7_times[seventhtask].Endhostname, stop_host);
            	strcpy(map7_times[seventhtask].task_status, Task_status);
            	strcpy(map7_times[seventhtask].NodeStatus, Node_statuss);
                 map7_times[seventhtask].times = start_time;
                 map7_times[seventhtask].Stop_Times =stop_t;
                map7_times[seventhtask].exec_Times =Execution_Times2;
                map7_times[seventhtask].id = seventhtask;
                map7_times[seventhtask].pid = MSG_process_self_PID();
                seventhtask = seventhtask + 1;
            }
        }

/* End of Execution Times Generation*/
  /* Generation of the number of active mappers on a host*/
              for (k = 0; k<num_hosts; k++)
                  {
               if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                   {
                       strcpy(snapmap7_times[taskSeven].name, host_name);
                       snapmap7_times[taskSeven].starthost = start;
                       snapmap7_times[taskSeven].times = Execution_Times2;
                       snapmap7_times[taskSeven].id = taskSeven;
                       snapmap7_times[taskSeven].pid = MSG_process_self_PID();
                       taskSeven = taskSeven + 1 ;
                      }
                    }

              i++;
            for(j=0;j<2;j++)
            {
                if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
                {
                    snaps[j].mappers--;
                }
            }
     /* End of active mappers generation*/
            MSG_task_destroy(map_task_7);													// Once the simulation is completed the, map task is destroyed to free up memory space.

     //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }
   this_host->active_mappers_7--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}


/** Map_8 Process */
int map_8(int argc, char * argv[])
{
    double start_time;
    double start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    double D = 0.5;
    int start;
    int end;
    int k;
    const int num_hosts =9;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_8();
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
   /* Forcing maptask 8 to wait till the completion of MapTask7*/
        while (1)
        {
        	if(this_host->active_mappers_7> 0 )
        		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);
        	else
        		break;
        }

    /*the wait ends here*/
    while (xbt_fifo_size(this_host->map_tasks_8) > 0 )
    {
    	msg_task_t map_task_8 = xbt_fifo_pop(this_host->map_tasks_8); // SECOND MAP TASK
      if (map_task_8 != NULL)
        {

      // 	XBT_INFO("%s Mapper 8 is starting a map task", MSG_process_get_name(MSG_process_self()));
        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++){
        	      if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	        {
        	        	snaps[j].mappers++;
        	        }
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	/* Generating extra task*/

        	 const char *host_name = MSG_host_get_name(MSG_host_self());
        	   Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	   MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
        	   if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_8 > 0))
        	     {
        	       strcpy(Node_status, "S_Node");
        	      }
        	   else
        	      {
        	        strcpy(Node_status, "F_Node");
        	      }

        	   // Execute the map task
            MSG_task_execute(map_task_8);
            task_count = task_count + 1;

             Execution_Times2= MSG_get_clock() - start_time;

            sim_map_8 += MSG_get_clock() - start_time;			// The map simulation time is obtained by subtracting the start time from the MSG CLOCK.

            stop_t =MSG_get_clock();
            const char *stop_host = MSG_host_get_name(MSG_host_self());
            if(map_task_8!= 0)
             {
               strcpy(Task_status, "Done");
             }
            else
             {
              strcpy(Task_status, "Crushed");
              }

           /* Generating the hostnames, mappers and execution Times for MapTask_8  */
            for (k = 0; k<num_hosts; k++)
           {
          if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
            	strcpy(map8_times[eighthtask].name, host_name);
            	strcpy(map8_times[eighthtask].Endhostname, stop_host);
            	strcpy(map8_times[eighthtask].task_status, Task_status);
            	strcpy(map8_times[eighthtask].NodeStatus, Node_status);
                 map8_times[eighthtask].times = start_time;
                 map8_times[eighthtask].Stop_Times = stop_t;
                 map8_times[eighthtask].exec_Times =Execution_Times2;
                 map8_times[eighthtask].id = eighthtask;
                 map8_times[eighthtask].pid = MSG_process_self_PID();
                 eighthtask = eighthtask + 1;
               }
        }


            /* End of Execution Times Generation*/

  /* Generation of the number of active mappers on a host*/
            for (k = 0; k<num_hosts; k++)
           {
              if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                  {
                     strcpy(snapmap8_times[taskEight].name, host_name);
                     snapmap8_times[taskEight].starthost = start;
                     snapmap8_times[taskEight].times = Execution_Times2;
                     snapmap8_times[taskEight].id = taskEight;
                     snapmap8_times[taskEight].pid = MSG_process_self_PID();
                     taskEight = taskEight + 1 ;
                 }
             }
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
            	{

            	snaps[j].mappers--;
               }
            }
   /* End of active mappers generation*/

            MSG_task_destroy(map_task_8);													// Once the simulation is completed the, map task is destroyed to free up memory space.

        //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.

          partition_map_task(this_host, bytes_to_shuffle);
        }
    }

   this_host->active_mappers_8--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

/** Map_9 Process */
int map_9(int argc, char * argv[])
{
    double start_time;
    double  start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    double D = 0.5;
    int start;
    int end;
    int k;
    const int num_hosts =9;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char name[5];
    char str[] = "host2-Mapper-1";
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_9();
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    /* Forcing maptask 8 to wait till the completion of MapTask9*/
        while (1){
        	if(this_host->active_mappers_8> 0 )
        		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);//LASTMAPTASK_BEGIN_DURATION // 0.799734700
        	else
        		break;
        }

        while (xbt_fifo_size(this_host->map_tasks_9) > 0 )

    {
    	// Do map tasks_9
        msg_task_t map_task_9 = xbt_fifo_pop(this_host->map_tasks_9); // SECOND MAP TASK
        if (map_task_9 != NULL)
        {

       //   XBT_INFO("%s Mapper 9 is starting a map task", MSG_process_get_name(MSG_process_self()));

        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++){
        	 if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	   {
        	      snaps[j].mappers++;
        	    }
        	}
        	//take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	/* Generating extra task*/

        	 const char *host_name = MSG_host_get_name(MSG_host_self());
        	  Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	   MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	     if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_9 > 0))
        	       {
        	           	strcpy(Node_status, "S_Node");
        	        }
        	      else
        	         {
        	           	strcpy(Node_status, "F_Node");
        	          }

        	     // Execute the map task
            MSG_task_execute(map_task_9);
            task_count = task_count + 1;
            Execution_Times2= MSG_get_clock() - start_time;
            sim_map_9 += MSG_get_clock() - start_time;	// The map simulation time is obtained by subtracting the start time from the MSG CLOCK.


            stop_t =MSG_get_clock();

            const char *stop_host = MSG_host_get_name(MSG_host_self());
            if(map_task_9!= 0)
               {
                 strcpy(Task_status, "Done");
               }
            else
               {
                strcpy(Task_status, "Crushed");
               }
/* Generating the hostnames, mappers and execution Times for MapTask_3  */
            for (k = 0; k<num_hosts; k++)
              {
           if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
                strcpy(map9_times[ninthtask].name, host_name);
                strcpy(map9_times[ninthtask].Endhostname, stop_host);
                strcpy(map9_times[ninthtask].task_status, Task_status);
                strcpy(map9_times[ninthtask].TaskUpdatedNodeStatus,TaskUpNodeStatus);
            	 map9_times[ninthtask].times = start_time;
             	 map9_times[ninthtask].Stop_Times = stop_t;
            	 map9_times[ninthtask].exec_Times =Execution_Times2;
            	 map9_times[ninthtask].id = ninthtask;
            	 map9_times[ninthtask].pid = MSG_process_self_PID();
            	 ninthtask = ninthtask + 1;
            }
          }

/* End of Execution Times Generation*/
  /* Generation of the number of active mappers on a host*/
            for (k = 0; k<num_hosts; k++)
                {
                   if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                  {
                      strcpy(snapmap9_times[taskNine].name, host_name);
                      snapmap9_times[taskNine].starthost = start;
                      snapmap9_times[taskNine].times = Execution_Times2;
                      snapmap9_times[taskNine].id = taskNine;
                      snapmap9_times[taskNine].pid = MSG_process_self_PID();
                      taskNine = taskNine + 1 ;
                  }
              }

            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
            	{
            		snaps[j].mappers--;
                 }
            }
   /* End of active mappers generation*/

            MSG_task_destroy(map_task_9);													// Once the simulation is completed the, map task is destroyed to free up memory space.

      //  XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }

   this_host->active_mappers_9--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}
// TODO:  Maptasks 10!

/** Map_10 Process */
int map_0(int argc, char * argv[])
{
    double start_time;
    double start_time2;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char Node_statusss[30];
    char finish_host[30];
    char name[5];
    char str[] = "host2-Mapper-1";
    int k;
    const int num_hosts =9;
     char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle_10();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    /* Forcing maptask 10 to wait till the completion of MapTask9*/

    while (1)
    {
    	if(this_host->active_mappers_9> 0 )
    		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);
        else
        	break;
    }

    /*the wait ends here*/
    while (xbt_fifo_size(this_host->map_tasks_0) > 0 )
    {
    	msg_task_t map_task_0 = xbt_fifo_pop(this_host->map_tasks_0);
        if (map_task_0 != NULL)
        {
      //  XBT_INFO("%s Mapper 10 is starting a map task", MSG_process_get_name(MSG_process_self()));

        	// initializing the map process
        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++)
        	{
        	        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	     {
        	        snaps[j].mappers++;
        	     }
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

         	const char *host_nam = MSG_host_get_name(MSG_host_self());
        	 Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	 MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	  if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_0 > 0))
        	      {
        	          strcpy(Node_statusss, "S_Node");
        	       }
        	   else
        	        {
        	          strcpy(Node_statusss, "F_Node");
        	        }

        	  // Execute the map task
            MSG_task_execute(map_task_0);
            task_count = task_count + 1;
            Execution_Times2= MSG_get_clock() - start_time;
            sim_map_0 += MSG_get_clock() - start_time;
            stop_t =MSG_get_clock();

            const char *stop_hosts = MSG_host_get_name(MSG_host_self());
            if(map_task_0!= 0)
              {
               strcpy(Task_status, "Done");
              }
            else
               {
               strcpy(Task_status, "Crushed");
               }

            /* Generating the hostnames, mappers and execution Times for MapTask_3  */

            for (k = 0; k<num_hosts; k++)
          {

          if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
            {
                strcpy(map10_times[tenthtask].name,host_nam);
                strcpy(map10_times[tenthtask].Endhostname, stop_hosts);
                strcpy(map10_times[tenthtask].task_status, Task_status);
                strcpy(map10_times[tenthtask].NodeStatus, Node_statusss);
                 map10_times[tenthtask].times = start_time;
                map10_times[tenthtask].Stop_Times =stop_t;
            	 map10_times[tenthtask].exec_Times =Execution_Times2;
            	 map10_times[tenthtask].id = tenthtask;
            	 map10_times[tenthtask].pid = MSG_process_self_PID();
            	 tenthtask = tenthtask + 1;
             }
          }

 /* End of Execution Times Generation*/
            for (k = 0; k<num_hosts; k++)
                {
                   if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
                  {
                      strcpy(snapmap10_times[taskTen].name, host_nam);
                      snapmap10_times[taskTen].starthost = start;
                      snapmap10_times[taskTen].times = Execution_Times2;
                      snapmap10_times[taskTen].id = taskTen;
                      snapmap10_times[taskTen].pid = MSG_process_self_PID();
                      taskTen = taskTen + 1 ;
                  }
              }
            /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
            	{
            		snaps[j].mappers--;
                }
             }
            /* End of active mappers generation*/
            MSG_task_destroy(map_task_0);													// Once the simulation is completed the, map task is destroyed to free up memory space.
       //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }
    this_host->active_mappers_0--;

    // Notify master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

/** Map_11 Process */

int map_11(int argc, char * argv[])
{
    double start_time;
    double stop_time;
    int j;
    int i;
    double D = 0.5;
    int start;
    int end;
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char Node_statusss[30];
    char finish_host[30];
    char name[5];
    char str[] = "host2-Mapper-1";
    int k;
    const int num_hosts =9;
   //const int num_hosts =4;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
  //  char *hst[] = {"host1","host2","host7","host19"};

    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    /* Forcing maptask 10 to wait till the completion of MapTask9*/

    while (1)
    {
    	if(this_host->active_mappers_0> 0 )
    		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);
        else
        	break;
    }

    int reschedule = MSG_process_self_PPID();
   reschedule_function_20(reschedule);


    /*the wait ends here*/

     while (xbt_fifo_size(this_host->map_tasks_11) > 0 )
    {
    	msg_task_t map_task_11 = xbt_fifo_pop(this_host->map_tasks_11);
        if (map_task_11 != NULL)
        {

         //XBT_INFO("%s Mapper 11 is starting a map task", MSG_process_get_name(MSG_process_self()));

        	// initializing the map process
        	/* Returns the number of active mapper */

        	for(j=0;j<2;j++)
        	{
        	        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	     {
        	        snaps[j].mappers++;
        	     }
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK

        	//int terminate = MSG_process_self_PPID();
        	//terminate_function_20(terminate);
        	// terminate_function_20();

        	if ((MSG_process_self_PPID()==201) || (MSG_process_self_PPID()==227)|| (MSG_process_self_PPID()==311)|| (MSG_process_self_PPID()==2) ||(MSG_process_self_PPID()==5))
                {
                	   this_host->active_mappers--;
                	  MSG_task_cancel(map_task_11);
                	  continue;
                }
            else if ((MSG_process_self_PPID()==227)|| (MSG_process_self_PPID()==253)|| (MSG_process_self_PPID()==282) ||(MSG_process_self_PPID()==311) ||(MSG_process_self_PPID()==2))
              	 {
              		 this_host->active_mappers--;
              		 MSG_task_cancel(map_task_11);
              		 continue;
              	 }
            else if ((MSG_process_self_PPID()==5)||(MSG_process_self_PPID()==10)||(MSG_process_self_PPID()==15)||(MSG_process_self_PPID()==23)||(MSG_process_self_PPID()==31))
                 {
                     this_host->active_mappers--;
                      MSG_task_cancel(map_task_11);
                      continue;
                  }
            else if ((MSG_process_self_PPID()==42)||(MSG_process_self_PPID()==53))
                  {
                      this_host->active_mappers--;
                      MSG_task_cancel(map_task_11);
                      continue;
                   }


      	 /* Generating extra task*/

        	 const char *host_nam = MSG_host_get_name(MSG_host_self());
        	 Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	 MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	  if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_11 > 0))
        	      {
        	          strcpy(Node_statusss, "S_Node");
        	       }
        	   else
        	        {
        	          strcpy(Node_statusss, "F_Node");
        	        }


        	  // Execute the map task
            MSG_task_execute(map_task_11);
            task_count = task_count + 1;

            Execution_Times2= MSG_get_clock() - start_time;
            sim_map_11 += MSG_get_clock() - start_time;
            stop_time =MSG_get_clock();
            const char *stop_hosts = MSG_host_get_name(MSG_host_self());
            if(map_task_11!= 0)
              {
               strcpy(Task_status, "Done");
              }
            else
               {
               strcpy(Task_status, "Crushed");
               }


            /* Generating the hostnames, mappers and execution Times for MapTask_3  */
            for (k = 0; k<num_hosts; k++)
                {
             if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))

           // if(strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0)
            {
                strcpy(map11_times[elevetask].name,host_nam);
                strcpy(map11_times[elevetask].Endhostname, stop_hosts);
                strcpy(map11_times[elevetask].task_status, Task_status);
                strcpy(map11_times[elevetask].NodeStatus, Node_statusss);
             	 map11_times[elevetask].times = start_time;
             	map11_times[elevetask].Stop_Times =stop_time;
            	 map11_times[elevetask].exec_Times =Execution_Times2;
            	 map11_times[elevetask].id = elevetask;
            	 map11_times[elevetask].pid = MSG_process_self_PID();
            	 elevetask = elevetask + 1;
             }
                }

 /* End of Execution Times Generation*/
/* End of Execution Times Generation*/
            /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
            	{
            		snaps[j].mappers--;
                }
             }
            /* End of active mappers generation*/
           MSG_task_destroy(map_task_11);													// Once the simulation is completed the, map task is destroyed to free up memory space.
        //   XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
            // Partition map output for shufflers to retrieve
          partition_map_task(this_host, bytes_to_shuffle);
      }
    }

   this_host->active_mappers_11--;

    // Notify master that I'm done working

    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

/** Map_12 Process */
int map_12(int argc, char * argv[])
{
    double start_time;
    double stop_time;
    int j;
    int i;
    double D = 0.5;
    int start;
    int end;
    int k;
    const int num_hosts =9;
     char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Times1;
    double Execution_Times2;
    msg_task_t task = NULL;
    char Node_statusss[30];
    char finish_host[30];
    char name[5];
    char str[] = "host2-Mapper-1";
    double bytes_to_move = get_bytes_to_move();
    double bytes_to_shuffle = get_bytes_to_shuffle();
    MSG_process_suspend(MSG_process_self());

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    /* Forcing maptask 10 to wait till the completion of MapTask9*/

    while (1)
    {
    	if(this_host->active_mappers_11> 0 )
    		MSG_process_sleep(LASTMAPTASK_BEGIN_DURATION);
        else
        	break;
    }

  int reschedule = MSG_process_self_PPID();
    reschedule_function_20(reschedule);

    /*the wait ends here*/
    while (xbt_fifo_size(this_host->map_tasks_12) > 0 )
    {
    	msg_task_t map_task_12 = xbt_fifo_pop(this_host->map_tasks_12);
        if (map_task_12 != NULL)
        {

     // XBT_INFO("%s Mapper 12 is starting a map task", MSG_process_get_name(MSG_process_self()));

        	// initializing the map process
        	/* Returns the number of active mapper */
        	for(j=0;j<2;j++)
        	{
        	        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	     {
        	        snaps[j].mappers++;
        	     }
        	}
        	//////take_snapshot();
        	start = MSG_process_self_PPID();
        	start_time =  MSG_get_clock(); // Derive the start time from the MSG SIM. CLOCK


        	if ((MSG_process_self_PPID()==115) || (MSG_process_self_PPID()==135)|| (MSG_process_self_PPID()==155)|| (MSG_process_self_PPID()==178) ||(MSG_process_self_PPID()==201))
                {
                	   this_host->active_mappers--;
                	  MSG_task_cancel(map_task_12);
                	  continue;
               }
            else if ((MSG_process_self_PPID()==227)|| (MSG_process_self_PPID()==253)|| (MSG_process_self_PPID()==282) ||(MSG_process_self_PPID()==311) ||(MSG_process_self_PPID()==2))
              	 {
              		 this_host->active_mappers--;
              		 MSG_task_cancel(map_task_12);
              		 continue;
              	 }
            else if ((MSG_process_self_PPID()==5)||(MSG_process_self_PPID()==10)||(MSG_process_self_PPID()==15)||(MSG_process_self_PPID()==23)||(MSG_process_self_PPID()==31))
                 {
                     this_host->active_mappers--;
                      MSG_task_cancel(map_task_12);
                      continue;
                  }
            else if ((MSG_process_self_PPID()==42)||(MSG_process_self_PPID()==53))
                  {
                      this_host->active_mappers--;
                      MSG_task_cancel(map_task_12);
                      continue;
                   }


        	//MSG_process_self_PID();
        	 const char *host_nam = MSG_host_get_name(MSG_host_self());
        	 Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
        	 MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

        	  if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5)&& (map_task_12 > 0))
        	      {
        	          strcpy(Node_statusss, "S_Node");
        	       }
        	   else
        	        {
        	          strcpy(Node_statusss, "F_Node");
        	        }

       	  // Execute the map task
            MSG_task_execute(map_task_12);
            task_count = task_count + 1;
            Execution_Times2= MSG_get_clock() - start_time;

              sim_map_12 += MSG_get_clock() - start_time;
            stop_time =MSG_get_clock();
            const char *stop_hosts = MSG_host_get_name(MSG_host_self());
            if(map_task_12!= 0)
              {
               strcpy(Task_status, "Done");
              }
            else
               {
               strcpy(Task_status, "Crushed");
               }

            /* Generating the hostnames, mappers and execution Times for MapTask_3  */
            for (k = 0; k<num_hosts; k++)
                {

            if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))

            {
                strcpy(map12_times[tweltask].name,host_nam);
                strcpy(map12_times[tweltask].Endhostname, stop_hosts);
                strcpy(map12_times[tweltask].task_status, Task_status);
                strcpy(map12_times[tweltask].NodeStatus, Node_statusss);
            	 map12_times[tweltask].times = start_time;
            	 map12_times[tweltask].Stop_Times =stop_time;
            	 map12_times[tweltask].exec_Times =Execution_Times2;
            	 map12_times[tweltask].id = tweltask;
            	 map12_times[tweltask].pid = MSG_process_self_PID();
            	 tweltask = tweltask + 1;
             }
                }

/* End of Execution Times Generation*/

            /* Generation of the number of active mappers on a host*/
            i++;
            for(j=0;j<2;j++)
            {
            	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
            	{
            		snaps[j].mappers--;
                }
             }
            /* End of active mappers generation*/
            MSG_task_destroy(map_task_12);													// Once the simulation is completed the, map task is destroyed to free up memory space.
          // XBT_INFO("%s has completed a map task", MSG_process_get_name(MSG_process_self()));  									// The name of the process is displayed.
            // Partition map output for shufflers to retrieve
            partition_map_task(this_host, bytes_to_shuffle);
        }
    }

   this_host->active_mappers_12--;

    // Notify master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("map_exit", 0, 1, NULL), "master"); 					// A message comm object is created and sent to the master
    MSG_comm_wait(comm, -1); 																				// The communication task waits for a brief moment.
    MSG_comm_destroy(comm);                   													 // The communication task is destroyed at the end of all mapping processes.
    return 0;
}

//TODO:  Reducetasks 1!

/** Reduce Process */
int reduce(int argc, char * argv[])
{
    double start_timee;
    double stop_t;
    double stop_tt;
    double Execution_Time2;
    double Execution_Time1;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    int NumOfIterations;
    int NumOfExecutions=6;

    char name[5];
    char fast_2[30];
    char Node_statu[30];
    char str[] = "host2-Reducer-1";
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    MSG_process_suspend(MSG_process_self());
    for (int k = 0; k < NumOfReduceTasks; ++k)
      {

    		// BEGIN REDUCE PROCESSING
  		//XBT_INFO("%s is starting a reduce task", MSG_process_get_name(MSG_process_self()));
    			// Begin the reducing processes.
    		for(j=0;j<2;j++)
    		{
    			if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
    			{
    					snaps[j].reducers++;
    			}
    		}
    		/////take_snapshot();
    		int starthst;
    		starthst = MSG_process_self_PPID();
    		start_timee = MSG_get_clock();// Get the start time from the MSG simulation Clock.

    		const char *host_nam = MSG_host_get_name(MSG_host_self());
    		Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    		MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

    		if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
    		{
    			strcpy(Node_statu, "S_Node");
    		}
    		else
    		{
    				strcpy(Node_statu, "F_Node");
    		}

    		int PID= MSG_process_self_PID();

    		//ScheduleRedhosts_1();

    		msg_task_t reduce_task = MSG_task_create("reduce", get_reduce_cost(MSG_host_self()), 0, NULL);
        	MSG_task_execute(reduce_task); // reduce tasks are created and executed here
    		reduce_task_count = reduce_task_count + 1;

    		total_exec_time;
    		//double avg_exec_time1;

    		double task_size = MSG_task_get_flops_amount(reduce_task);
    	   if(task_size== 0)
    		{
    			strcpy(Task_status, "Done");
    		}
    		else
    		{
    			strcpy(Task_status, "Crushed");
    		}

    		sim_reduce += MSG_get_clock() - start_timee;


    	    //Reduce1ExecTime = MSG_get_clock() - start_timee;
    		Execution_Time2 = MSG_get_clock() - start_timee;
    		//int host= MSG_process_self_PPID();
    		//Execution_Time1=exec_Redfunction_20(host, Execution_Time2);

    		stop_t =MSG_get_clock();
    		int time = MSG_process_self_PPID();
    		stop_tt=Redstoptime_function_20_1(time, stop_t);

    		const char *stop_host = MSG_host_get_name(MSG_host_self());

    		/* Generating the hostnames, mappers and execution Times for ReduceTask_1  */
    		for (k = 0; k<num_hosts; k++)
    		{
    		if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    		{
    			strcpy(reduce1_times[firstredtask].namee,host_nam);
    			strcpy(reduce1_times[firstredtask].finish_host, stop_host);
    			strcpy(reduce1_times[firstredtask].NodeStatus, Node_statu);
    			strcpy(reduce1_times[firstredtask].task_status, Task_status);
     			reduce1_times[firstredtask].launch_times=start_timee;
    			reduce1_times[firstredtask].finish_Times=stop_t;
    			reduce1_times[firstredtask].redtimes = Execution_Time2;
    			reduce1_times[firstredtask].pidd=MSG_process_self_PID();
    			reduce1_times[firstredtask].idd = firstredtask;
    			firstredtask = firstredtask + 1 ;
    		}
    	}
    		/* End of Execution Times Generation*/

    		/* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    		for (k = 0; k<num_hosts; k++)
    		 {
    		 if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    		   {
    			strcpy(redsnap1_times[snapredtask_1].namee, host_nam);
    			redsnap1_times[snapredtask_1].redsnaptimes =  Execution_Time1;
    			redsnap1_times[snapredtask_1].starthost=starthst;
    			redsnap1_times[snapredtask_1].idd = snapredtask_2;
    			snapredtask_1 = snapredtask_1 + 1 ;
    		   }
    		 }

    		/* End of Execution Times Generation*/
    		i++;
    		for(j=0;j<2;j++)
    		{
    			if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
    			{
    				snaps[j].reducers--;
    			}
    		}

      }

 //  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

    // END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Reduce Process_2 */
int reduce_2(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    double Tf_Time_1;
    double Tf_Time_2;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    double terminated_time;
    double bytes_to_move = get_bytes_to_reduce_move();
    msg_task_t task = NULL;
    double term_ExTime;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers> 0 )
    {
    	MSG_process_sleep(1.59444);
    }
    else
    {
    	MSG_process_self_PID();
    }


    for ( int k = 0; k < NumOfReduceTasks; ++k)
    {

    	// BEGIN REDUCE PROCESSING

    	// XBT_INFO("%s is starting a reduce task2", MSG_process_get_name(MSG_process_self()));
    	for(j=0;j<2;j++)
    	{
    		if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
    		{
    			snaps[j].reducers++;
    		}
    	}
    	///take_snapshot();
    	int starthst;
    	starthst = MSG_process_self_PPID();
    	start_time = MSG_get_clock();
    	const char *host_nam = MSG_host_get_name(MSG_host_self());
    	Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    	MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

    	if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
          strcpy(Node_statu, "S_Node");
        }
    	else
        {
    		strcpy(Node_statu, "F_Node");
        }


    //	ScheduleRedhosts_2();
    	Execution_Time1 = MSG_get_clock() - start_time;

    	msg_task_t reduce_task_2 = MSG_task_create("reduce_2", get_reduce_cost_2(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here

    	MSG_task_execute(reduce_task_2);
    	reduce_task_count = reduce_task_count + 1;
    	double task_size = MSG_task_get_flops_amount(reduce_task_2);

    	if(task_size== 0)
    	{
    		strcpy(Task_status, "Done");
    	}
    	else
    	{
    		strcpy(Task_status, "Crushed");
    	}

    	sim_reduce_2 += MSG_get_clock() - start_time;
    	Execution_Time2 = MSG_get_clock() - start_time;

    	const char *stop_host = MSG_host_get_name(MSG_host_self());
    	stop_t =MSG_get_clock();
        int time = MSG_process_self_PPID();
        stop_tt=Redstoptime_function_20_2(time, stop_t);



    	/* Generating the hostnames, mappers and execution Times for ReduceTask_2  */
    	 for (k = 0; k<num_hosts; k++)
    	  {
    	 if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
        {
    		strcpy(reduce2_times[secondredtask].namee, host_nam);
    		strcpy(reduce2_times[secondredtask].finish_host, stop_host);
    		strcpy(reduce2_times[secondredtask].NodeStatus, Node_statu);
    		strcpy(reduce2_times[secondredtask].task_status, Task_status);
    		//strcpy(reduce2_times[secondredtask].TaskUpNodeStatus, Red_TaskUpNodeSt);
    		reduce2_times[secondredtask].launch_times=start_time;
    		reduce2_times[secondredtask].finish_Times=stop_tt;
    		reduce2_times[secondredtask].pidd=MSG_process_self_PID();
	   	   reduce2_times[secondredtask].redtimes =  Execution_Time2;
	   	   reduce2_times[secondredtask].idd = secondredtask;
	   	   secondredtask = secondredtask + 1 ;
    	 	 }
    	 }

    	/* End of Execution Times Generation*/

    	/* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    	 for (k = 0; k<num_hosts; k++)
    	    {
    	if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    	// if(strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0)
    		{
            strcpy(redsnap2_times[snapredtask_2].namee, host_nam);
            redsnap2_times[snapredtask_2].redsnaptimes =  Execution_Time1;
            redsnap2_times[snapredtask_2].starthost=starthst;
            redsnap2_times[snapredtask_2].idd = snapredtask_2;
            snapredtask_2 = snapredtask_2 + 1 ;
    		}
    	   }

        /* End of Execution Times Generation*/
        i++;
        for(j=0;j<2;j++)
        {
        	if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
        	{
        		snaps[j].reducers--;
        	}
        }
    }
    // XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

    // END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);
    
    return 0;
}

/** Reduce Process_3 */
int reduce_3(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    char Task_statu[30];
    char Node_statu[30];
    char TaskP_status[30];
    char name[5];
    msg_task_t task = NULL;
    char str[] = "host2-Reducer-1";
    double bytes_to_move = get_bytes_to_reduce_move();
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers_2> 0 )
      {
        MSG_process_sleep(2.89444);//LASTMAPTASK_BEGIN_DURATION, 0.48444, reducers_3
       }
    else
        {

    	MSG_process_self_PID();
       }

    for (int k = 0; k < NumOfReduceTasks; ++k)
     {


 // BEGIN REDUCE PROCESSING

  //  XBT_INFO("%s is starting a reduce task3", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
    {
       if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
         snaps[j].reducers++;
      }
    }
    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
    if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
         strcpy(Node_statu, "S_Node");
          }
     else
          {
          strcpy(Node_statu, "F_Node");
           }


    msg_task_t reduce_task_3 = MSG_task_create("reduce_3", get_reduce_cost_3(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here

    MSG_task_execute(reduce_task_3);
    reduce_task_count = reduce_task_count + 1;

    double task_size = MSG_task_get_flops_amount(reduce_task_3);
    if(task_size== 0)
       {
        strcpy(Task_statu, "Done");
       }
    else
         {
          strcpy(Task_statu, "Crushed");
          }


    sim_reduce_3 += MSG_get_clock() - start_time;
    Execution_Time2 = MSG_get_clock() - start_time;

	if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
          strcpy(Node_statu, "S_Node");
        }
    	else
        {
    		strcpy(Node_statu, "F_Node");
        }

    const char *stop_host = MSG_host_get_name(MSG_host_self());

    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20_3(time, stop_t);


    /* Generating the hostnames, mappers and execution Times for ReduceTask_3  */
    for (k = 0; k<num_hosts; k++)
     {
    if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    {
	 strcpy(reduce3_times[thirdredtask].namee, host_nam);
	 strcpy(reduce3_times[thirdredtask].finish_host, stop_host);
	  strcpy(reduce3_times[thirdredtask].NodeStatus, Node_statu);
	  strcpy(reduce3_times[thirdredtask].task_status, Task_statu);
	//  strcpy(reduce3_times[thirdredtask].TaskUpNodeStatus, Red_TaskUpNodeSt);
	  reduce3_times[thirdredtask].launch_times=start_time;
	  reduce3_times[thirdredtask].finish_Times= stop_tt;
	  reduce3_times[thirdredtask].pidd=MSG_process_self_PID();
	  reduce3_times[thirdredtask].redtimes = Execution_Time2;
	  reduce3_times[thirdredtask].idd = thirdredtask;
	  thirdredtask = thirdredtask + 1 ;
  	  }
    }

  /* End of Execution Times Generation*/

  /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
         {
        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    {
       strcpy(redsnap3_times[snapredtask_3].namee, host_nam);
       redsnap3_times[snapredtask_3].redsnaptimes = Execution_Time1;
       redsnap3_times[snapredtask_3].starthost=starthst;
       redsnap3_times[snapredtask_3].idd = snapredtask_3;
       snapredtask_3 = snapredtask_3 + 1 ;
      }
         }

  /* End of Execution Times Generation*/
   i++;
   for(j=0;j<2;j++)
   {
      if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
       snaps[j].reducers--;
      }
   }
 }

//  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

/** Reduce Process_4 */
int reduce_4(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";

    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers_3> 0 )
      {
        MSG_process_sleep(3.99444);//LASTMAPTASK_BEGIN_DURATION
       }
    else
        {
          MSG_process_self_PID();
        }


    for (int k = 0; k < NumOfReduceTasks; ++k)
    {

 // BEGIN REDUCE PROCESSING

  //  XBT_INFO("%s is starting a reduce task 4", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
   {
      if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
        snaps[j].reducers++;
      }
    }
    //////take_snapshot();
    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

     if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
         {
           strcpy(Node_statu, "S_Node");
         }
     else
         {
          strcpy(Node_statu, "F_Node");
         }

    // changes made to implement delay in hosts for reduce process based on the host ids

    msg_task_t reduce_task_4 = MSG_task_create("reduce_4", get_reduce_cost_4(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
    MSG_task_execute(reduce_task_4);
    reduce_task_count = reduce_task_count + 1;

    double task_size = MSG_task_get_flops_amount(reduce_task_4);
    if(task_size== 0)
       {strcpy(Task_status, "Done"); }
    else {strcpy(Task_status, "Crushed"); }


    sim_reduce_4 += MSG_get_clock() - start_time;
    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20_4(time, stop_t);


      /* Generating the hostnames, mappers and execution Times for ReduceTask_2  */
    for (k = 0; k<num_hosts; k++)
     {
       if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
     //if(strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
    	strcpy(reduce4_times[fourthredtask].namee, host_nam);
    	strcpy(reduce4_times[fourthredtask].finish_host, stop_host);
    	strcpy(reduce4_times[fourthredtask].NodeStatus, Node_statu);
    	strcpy(reduce4_times[fourthredtask].task_status, Task_status);
    	reduce4_times[fourthredtask].launch_times=start_time;
    	reduce4_times[fourthredtask].finish_Times=stop_tt;
    	reduce4_times[fourthredtask].pidd=MSG_process_self_PID();
    	reduce4_times[fourthredtask].redtimes = Execution_Time2;
    	reduce4_times[fourthredtask].idd = fourthredtask;
    	fourthredtask = fourthredtask + 1 ;

       }
    }

     /* End of Execution Times Generation*/
/* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
       {
      if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
     // if(strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0)
       	  {
          strcpy(redsnap4_times[snapredtask_4].namee, host_nam);
          redsnap4_times[snapredtask_4].redsnaptimes = Execution_Time2;
          redsnap4_times[snapredtask_4].starthost=starthst;
          redsnap4_times[snapredtask_4].idd = snapredtask_4;
          snapredtask_4 = snapredtask_4 + 1 ;
         }
       }

        /* End of Execution Times Generation*/
     i++;
     for(j=0;j<2;j++)
      {
         if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
        snaps[j].reducers--;
        }
     }
  }
  //  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

//TODO:  Reducetasks 5!
/** Reduce Process_5 */
int reduce_5(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    char fast_2[30];
    char Node_statu[30];
    double terminated_time2;
    double terminated_time1;
    double term_ExTime;
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
       struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

       if(this_host->reducers_4> 0 )
        {
          MSG_process_sleep(5.84444);//LASTMAPTASK_BEGIN_DURATION
         }
         else
          {
            MSG_process_self_PID();
          }

// EXECUTING REDUCE TASKS A NUMBER OF TIMES

    for (int k = 0; k < NumOfReduceTasks; ++k)
      {

 // BEGIN REDUCE PROCESSING
  // XBT_INFO("%s is starting a reduce task 5", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
    {
       if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
        snaps[j].reducers++;
        }
    }

    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

     if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
          strcpy(Node_statu, "S_Node");
         }
     else
         {
           strcpy(Node_statu, "F_Node");
         }

   // changes made to implement delay in hosts for reduce process based on the host ids

   msg_task_t reduce_task_5 = MSG_task_create("reduce_5", get_reduce_cost_5(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here


    MSG_task_execute(reduce_task_5);
    reduce_task_count = reduce_task_count + 1;
    double task_size = MSG_task_get_flops_amount(reduce_task_5);
    if(task_size== 0)
       {
        strcpy(Task_status, "Done");
        }
     else
         {
          strcpy(Task_status, "Crushed");
         }

    sim_reduce_5 += MSG_get_clock() - start_time;

    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

	/* Generating the hostnames, mappers and execution Times for ReduceTask_2  */
    for (k = 0; k<num_hosts; k++)
       {
        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
     {
    	  strcpy(reduce5_times[fifthredtask].namee, host_nam);
    	  strcpy(reduce5_times[fifthredtask].finish_host, stop_host);
    	  strcpy(reduce5_times[fifthredtask].NodeStatus, Node_statu);
    	  strcpy(reduce5_times[fifthredtask].task_status, Task_status);
    	  reduce5_times[fifthredtask].launch_times=start_time;
    	  reduce5_times[fifthredtask].finish_Times= stop_tt;
    	  reduce5_times[fifthredtask].pidd=MSG_process_self_PID();
    	  reduce5_times[fifthredtask ].redtimes = Execution_Time2;
    	  reduce5_times[fifthredtask ].idd = fifthredtask ;
    	  fifthredtask  = fifthredtask  + 1 ;
      	  }
      }

      /* End of Execution Times Generation*/

  /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
         {
      if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
         {
          strcpy(redsnap5_times[snapredtask_5].namee, host_nam);
          redsnap5_times[snapredtask_5].redsnaptimes = Execution_Time2;
          redsnap5_times[snapredtask_5].starthost=starthst;
          redsnap5_times[snapredtask_5].idd = snapredtask_5;
          snapredtask_5 = snapredtask_5 + 1 ;
         }
      }

 /* End of Execution Times Generation*/
      i++;
      for(j=0;j<2;j++)
      {
          if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
          {
           snaps[j].reducers--;
           }
     }

  }
    // XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Reduce Process_6 */
int reduce_6(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    double bytes_to_move = get_bytes_to_reduce_move();
    msg_task_t task = NULL;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers_5> 0 )
       {
        MSG_process_sleep(6.89444);
        }
    else
        {
         MSG_process_self_PID();
         }

    for (int k = 0; k < NumOfReduceTasks; ++k)
    {

 // BEGIN REDUCE PROCESSING

    //XBT_INFO("%s is starting a reduce task 6", MSG_process_get_name(MSG_process_self()));                       // Begin the reducing processes.
    for(j=0;j<2;j++)
   {
      if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
        snaps[j].reducers++;
      }
   }
   //////take_snapshot();
    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();										// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

    if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
         strcpy(Node_statu, "S_Node");
         }
     else
         {
         strcpy(Node_statu, "F_Node");
         }


    msg_task_t reduce_task_6 = MSG_task_create("reduce_6", get_reduce_cost_6(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here

    MSG_task_execute(reduce_task_6);
    reduce_task_count = reduce_task_count + 1;
    double task_size = MSG_task_get_flops_amount(reduce_task_6);
     if(task_size== 0)
       {
        strcpy(Task_status, "Done");
       }
      else
        {
         strcpy(Task_status, "Crushed");
        }

    sim_reduce_6 += MSG_get_clock() - start_time;
    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());

    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

    /* Generating the hostnames, mappers and execution Times for ReduceTask_6  */
    for (k = 0; k<num_hosts; k++)
        {
    if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
      {
    	strcpy(reduce6_times[sixthredtask].namee, host_nam);
    	strcpy(reduce6_times[sixthredtask].finish_host, stop_host);
    	strcpy(reduce6_times[sixthredtask].NodeStatus, Node_statu);
    	strcpy(reduce6_times[sixthredtask].task_status, Task_status);
    	reduce6_times[sixthredtask].launch_times=start_time;
    	reduce6_times[sixthredtask].finish_Times=stop_tt;
    	reduce6_times[sixthredtask].pidd=MSG_process_self_PID();
    	reduce6_times[sixthredtask].redtimes = Execution_Time2;
    	reduce6_times[sixthredtask].idd = sixthredtask;
    	sixthredtask  = sixthredtask  + 1 ;
     }
    }

    /* End of Execution Times Generation*/
    /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
     {
    if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
      {
     strcpy(redsnap6_times[snapredtask_6].namee, host_nam);
     redsnap6_times[snapredtask_6].redsnaptimes = Execution_Time2;
     redsnap6_times[snapredtask_6].starthost=starthst;
     redsnap6_times[snapredtask_6].idd = snapredtask_6;
     snapredtask_6 = snapredtask_6 + 1 ;
    }
  }
    /* End of Execution Times Generation*/

   i++;
   for(j=0;j<2;j++)
   {
   if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
       snaps[j].reducers--;
      }
   }
 }
    //XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

/** Reduce Process_7 */
int reduce_7(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
   struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

   if(this_host->active_reducers_6> 0 )
    {
     MSG_process_sleep(7.88444);//LASTMAPTASK_BEGIN_DURATION
     }
 else
     {
      MSG_process_self_PID();
     }

   // EXECUTING REDUCE TASKS A NUMBER OF TIMES

    for (int k = 0; k < NumOfReduceTasks; ++k)
    {

 // BEGIN REDUCE PROCESSING

    //XBT_INFO("%s is starting a reduce task 7", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
    {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
         snaps[j].reducers++;
      }
   }
    //////take_snapshot();
    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
     if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
          strcpy(Node_statu, "S_Node");
          }
      else
         {
           strcpy(Node_statu, "F_Node");
          }

    msg_task_t reduce_task_7 = MSG_task_create("reduce_7", get_reduce_cost_7(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
    MSG_task_execute(reduce_task_7);
    reduce_task_count = reduce_task_count + 1;
    double task_size = MSG_task_get_flops_amount(reduce_task_7);
     if(task_size== 0)
        {
         strcpy(Task_status, "Done");
         }
     else
         {
           strcpy(Task_status, "Crushed");
          }


    sim_reduce_7 += MSG_get_clock() - start_time;
    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

      /* Generating the hostnames, mappers and execution Times for ReduceTask_7  */
    for (k = 0; k<num_hosts; k++)
     {
    	if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
      {
    	 strcpy(reduce7_times[seventhredtask].namee, host_nam);
    	 strcpy(reduce7_times[seventhredtask].finish_host, stop_host);
    	 strcpy(reduce7_times[seventhredtask].NodeStatus, Node_statu);
    	 strcpy(reduce7_times[seventhredtask].task_status, Task_status);
    	 reduce7_times[seventhredtask].launch_times=start_time;
    	 reduce7_times[seventhredtask].finish_Times=stop_tt;
    	 reduce7_times[seventhredtask].pidd=MSG_process_self_PID();
    	 reduce7_times[seventhredtask].redtimes = Execution_Time2;
    	 reduce7_times[seventhredtask].idd = seventhredtask;
    	 seventhredtask  = seventhredtask  + 1 ;
      }
    }
    /* End of Execution Times Generation*/
 /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task */
   for (k = 0; k<num_hosts; k++)
     {
    if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
      	{
       strcpy(redsnap7_times[snapredtask_7].namee, host_nam);
       redsnap7_times[snapredtask_7].redsnaptimes = Execution_Time2;
       redsnap7_times[snapredtask_7].starthost=starthst;
       redsnap7_times[snapredtask_7].idd = snapredtask_7;
       snapredtask_7 = snapredtask_7 + 1 ;
    	}
    }

   /* End of Execution Times Generation*/

    i++;
    for(j=0;j<2;j++)
   {
     if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
      snaps[j].reducers--;
     }
   }
 }
  //  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Reduce Process_8 */

int reduce_8(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    double Execution_Time3;
    char fast_2[30];
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


    if(this_host->active_reducers_7> 0 )
        {
         MSG_process_sleep(8.89444);
         }
     else
         {
          MSG_process_self_PID();
          }


    for (int k = 0; k < NumOfReduceTasks; ++k)
    {

 // BEGIN REDUCE PROCESSING

    //XBT_INFO("%s is starting a reduce task 8", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
    {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
        snaps[j].reducers++;
     }
    }
    //////take_snapshot();
    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
     if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
         strcpy(Node_statu, "S_Node");
         }
     else
          {
          strcpy(Node_statu, "F_Node");
          }

 //    ScheduleRedhosts_1();

    msg_task_t reduce_task_8 = MSG_task_create("reduce_8", get_reduce_cost_8(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
    MSG_task_execute(reduce_task_8);
    reduce_task_count = reduce_task_count + 1;

    double task_size = MSG_task_get_flops_amount(reduce_task_8);
    if(task_size== 0)
       {
        strcpy(Task_status, "Done");
        }
     else
        {
         strcpy(Task_status, "Crushed");
        }

   sim_reduce_8 += MSG_get_clock() - start_time;

    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

       /* Generating the hostnames, mappers and execution Times for ReduceTask_2  */
    for (k = 0; k<num_hosts; k++)
      {
        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
        {
    	strcpy(reduce8_times[eightthredtask].namee, host_nam);
    	strcpy(reduce8_times[eightthredtask].finish_host, stop_host);
    	strcpy(reduce8_times[eightthredtask].NodeStatus, Node_statu);
    	strcpy(reduce8_times[eightthredtask].task_status, Task_status);
    	reduce8_times[eightthredtask].launch_times=start_time;
    	reduce8_times[eightthredtask].finish_Times= stop_tt;
    	reduce8_times[eightthredtask].pidd=MSG_process_self_PID();
    	reduce8_times[eightthredtask].redtimes = Execution_Time2;
    	reduce8_times[eightthredtask].idd = eightthredtask;
    	eightthredtask  = eightthredtask  + 1 ;
        }
      }

    /* End of Execution Times Generation*/
 /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
         {
     if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
         {
         strcpy(redsnap8_times[snapredtask_8].namee, host_nam);
         redsnap8_times[snapredtask_8].redsnaptimes = Execution_Time1;
         redsnap8_times[snapredtask_8].starthost=starthst;
         redsnap8_times[snapredtask_8].idd = snapredtask_8;
         snapredtask_8 = snapredtask_8 + 1 ;
      }
    }

/* End of Execution Times Generation*/
    i++;
    for(j=0;j<2;j++)
    {
    if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
     {
        snaps[j].reducers--;
      }
    }
  }
    //XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Reduce Process_9 */

int reduce_9(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    double Execution_Time2;
    double Execution_Time1;
   // double Execution_Time3;
    char fast_2[30];
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
      // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
      struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->active_reducers_8> 0 )
           {
            MSG_process_sleep(9.89444);
            }
        else
            {
             MSG_process_self_PID();
             }

      // EXECUTING REDUCE TASKS A NUMBER OF TIMES

    for (int k = 0; k < NumOfReduceTasks; ++k)
    {

 // BEGIN REDUCE PROCESSING
    //XBT_INFO("%s is starting a reduce task 9", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
    {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
         snaps[j].reducers++;
        }
     }

    int starthst;
    starthst = MSG_process_self_PPID();
    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
    if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
      {
       strcpy(Node_statu, "S_Node");
       }
     else
       {
        strcpy(Node_statu, "F_Node");
       }

     Execution_Time1 = MSG_get_clock() - start_time;

     msg_task_t reduce_task_9 = MSG_task_create("reduce_9", get_reduce_cost_9(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
     MSG_task_execute(reduce_task_9);
     reduce_task_count = reduce_task_count + 1;

     double task_size = MSG_task_get_flops_amount(reduce_task_9);
     if(task_size== 0)
        {
         strcpy(Task_status, "Done");
         }
      else
         {
         strcpy(Task_status, "Crushed");
          }

    sim_reduce_9 += MSG_get_clock() - start_time;

    Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);


      /* Generating the hostnames, mappers and execution Times for ReduceTask_2  */
    for (k = 0; k<num_hosts; k++)
       {
    	if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))

     	 {
    	 strcpy(reduce9_times[ninthredtask].namee, host_nam);
    	 strcpy(reduce9_times[ninthredtask].finish_host, stop_host);
    	 strcpy(reduce9_times[ninthredtask].NodeStatus, Node_statu);
    	 strcpy(reduce9_times[ninthredtask].task_status, Task_status);
    	 reduce9_times[ninthredtask].launch_times=start_time;
    	 reduce9_times[ninthredtask].finish_Times=stop_tt;
    	 reduce9_times[ninthredtask].pidd=MSG_process_self_PID();
    	 reduce9_times[ninthredtask].redtimes =  Execution_Time2;
    	 reduce9_times[ninthredtask].idd = ninthredtask;
    	 ninthredtask  = ninthredtask  + 1 ;
     	 }
    }
         /* End of Execution Times Generation*/

 /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
      {
        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
        {
          strcpy(redsnap9_times[snapredtask_9].namee,  host_nam);
          redsnap9_times[snapredtask_9].redsnaptimes = Execution_Time2;
          redsnap9_times[snapredtask_9].starthost=starthst;
          redsnap9_times[snapredtask_9].idd = snapredtask_9;
          snapredtask_9 = snapredtask_9 + 1 ;
        }
      }

/* End of Execution Times Generation*/


    i++;
    for(j=0;j<2;j++)
    {
       if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
        snaps[j].reducers--;
       }
    }
  }
  //  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

/** Reduce Process_10 */

int reduce_10(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};
    double Execution_Time2;
    double Execution_Time1;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers_9> 0 )
     {
      MSG_process_sleep(10.89444);//LASTMAPTASK_BEGIN_DURATION
       }
     else
        {
         MSG_process_self_PID();
         }


    for (int k = 0; k < NumOfReduceTasks; ++k)
   {

 // BEGIN REDUCE PROCESSING

   // XBT_INFO("%s is starting a reduce task 10", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
     {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
          snaps[j].reducers++;
        }
     }
    //take_snapshot();
    int starthst;
    starthst = MSG_process_self_PPID();

    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
   if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
        {
         strcpy(Node_statu, "S_Node");
         }
      else
         {
         strcpy(Node_statu, "F_Node");
         }

 //  ScheduleRedhosts_1();


    msg_task_t reduce_task_10 = MSG_task_create("reduce_10", get_reduce_cost_10(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
    MSG_task_execute(reduce_task_10);
    reduce_task_count = reduce_task_count + 1;

    double task_size = MSG_task_get_flops_amount(reduce_task_10);
    if(task_size== 0)
       {
        strcpy(Task_status, "Done");
        }
     else
         {
         strcpy(Task_status, "Crushed");
         }



     sim_reduce_10 += MSG_get_clock() - start_time;
     Execution_Time2 = MSG_get_clock() - start_time;

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

    /* Generating the hostnames, mappers and execution Times for ReduceTask_10  */
    for (k = 0; k<num_hosts; k++)
     {

    if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
    	{
    	strcpy(reduce10_times[tenthredtask].namee, host_nam);
    	strcpy(reduce10_times[tenthredtask].finish_host, stop_host);
    	strcpy(reduce10_times[tenthredtask].NodeStatus, Node_statu);
    	strcpy(reduce10_times[tenthredtask].task_status, Task_status);
    	reduce10_times[tenthredtask].launch_times=start_time;
    	reduce10_times[tenthredtask].finish_Times=stop_tt;
    	reduce10_times[tenthredtask].pidd=MSG_process_self_PID();
    	reduce10_times[tenthredtask].redtimes =  Execution_Time2;
    	reduce10_times[tenthredtask].idd = tenthredtask;
    	tenthredtask  = tenthredtask  + 1 ;

    	}
   }

     /* End of Execution Times Generation*/

 /* Generating the hostnames, mappers and execution Times at specific period  for Reduce Task  */
    for (k = 0; k<num_hosts; k++)
      {
        if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))
        {
       strcpy(redsnap10_times[snapredtask_10].namee,  host_nam);
       redsnap10_times[snapredtask_10].redsnaptimes = Execution_Time2;
       redsnap10_times[snapredtask_10].starthost=starthst;
       redsnap10_times[snapredtask_10].idd = snapredtask_10;
       snapredtask_10 = snapredtask_10 + 1 ;
       }
     }
/* End of Execution Times Generation*/


    i++;
    for(j=0;j<2;j++)
    {
     if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
      snaps[j].reducers--;
      }
    }
  }
   // XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

//TODO:  Reducetasks 11!
/** Reduce Process_11 */

int reduce_11(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};

    double Execution_Time2;
    double Execution_Time1;
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";


     // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->reducers_10> 0 )
     {
      MSG_process_sleep(11.89444);
      }
     else
      {
       MSG_process_self_PID();
      }

     int reschedule = MSG_process_self_PPID();
     reschedule_function_reduce_20(reschedule);




 // BEGIN REDUCE PROCESSING

 //XBT_INFO("%s is starting a reduce task 11", MSG_process_get_name(MSG_process_self()));     // Begin the reducing processes.
    for(j=0;j<2;j++)
     {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
          snaps[j].reducers++;
        }
     }
    //take_snapshot();

    start_time = MSG_get_clock();	// Get the start time from the MSG simulation Clock.


    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;

    if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
      {
         strcpy(Node_statu, "S_Node");
      }
    else
      {
      strcpy(Node_statu, "F_Node");
      }

    ScheduleRedhosts_1();

    //Execution_Time1 = MSG_get_clock() - start_time;

    msg_task_t reduce_task_11 = MSG_task_create("reduce_11", get_reduce_cost_11(MSG_host_self()), 0, NULL);
    MSG_task_execute(reduce_task_11);
    reduce_task_count = reduce_task_count + 1;

    double task_size = MSG_task_get_flops_amount(reduce_task_11);
     if(task_size== 0)
      {
         strcpy(Task_status, "Done");
      }
     else
      {
       strcpy(Task_status, "Crushed");
      }

     sim_reduce_11 += MSG_get_clock() - start_time;

    Execution_Time2 = MSG_get_clock() - start_time;
    int host= MSG_process_self_PPID();
    Execution_Time1=exec_Redfunction_20(host, Execution_Time2);



    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

    /* Generating the hostnames, mappers and execution Times for ReduceTask_10  */

   for (k = 0; k<num_hosts; k++)
      {

      if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))

      {
    	strcpy(reduce11_times[eleveredtask].namee, host_nam);
    	strcpy(reduce11_times[eleveredtask].finish_host, stop_host);
    	strcpy(reduce11_times[eleveredtask].NodeStatus, Node_statu);
    	strcpy(reduce11_times[eleveredtask].task_status, Task_status);
    	reduce11_times[eleveredtask].launch_times=start_time;
    	reduce11_times[eleveredtask].finish_Times=stop_tt;
        reduce11_times[eleveredtask].pidd=MSG_process_self_PID();
    	reduce11_times[eleveredtask].redtimes =  Execution_Time1;
    	reduce11_times[eleveredtask].idd = eleveredtask;
    	eleveredtask  = eleveredtask  + 1 ;

     }
   }
     /* End of Execution Times Generation*/

/* End of Execution Times Generation*/

    i++;
    for(j=0;j<2;j++)
    {
     if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
      snaps[j].reducers--;
      }
    }
 // }
 //  XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}

/** Reduce Process_12 */

int reduce_12(int argc, char * argv[])
{
    double start_time;
    double stop_t;
    double stop_tt;
    int j;
    int i;
    int k;
    const int num_hosts =9;
    char *hst[] = {"host1","host2","host3","host4","host5","host6","host7", "host8", "host9"};

    double Execution_Time2;
    double Execution_Time1;
    char fast_2[30];
    char Node_statu[30];
    char name[5];
    char str[] = "host2-Reducer-1";
        // Wait for the reduce phase to begin
    MSG_process_suspend(MSG_process_self());
    msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

    if(this_host->active_reducers_11> 0 )
     {
      MSG_process_sleep(12.89444);//LASTMAPTASK_BEGIN_DURATION
       }
     else
        {
         MSG_process_self_PID();
         }

     int reschedule = MSG_process_self_PPID();
    reschedule_function_reduce_20(reschedule);

 // BEGIN REDUCE PROCESSING

//  XBT_INFO("%s is starting a reduce task 12", MSG_process_get_name(MSG_process_self()));                                  // Begin the reducing processes.
    for(j=0;j<2;j++)
     {
        if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
       {
          snaps[j].reducers++;
        }
     }
    //take_snapshot();

    start_time = MSG_get_clock();																							// Get the start time from the MSG simulation Clock.
    const char *host_nam = MSG_host_get_name(MSG_host_self());
    Maptask1Total_cpu_power += MSG_host_get_speed(msg_host);
    MaptTask1Av_cpu_power = Maptask1Total_cpu_power/number_of_workers;
    if ((MaptTask1Av_cpu_power > MSG_host_get_speed(msg_host))&& (MSG_host_get_core_number(msg_host)<=5))
       {
        strcpy(Node_statu, "S_Node");
        }
     else
        {
        strcpy(Node_statu, "F_Node");
        }

    ScheduleRedhosts_1();

   // Execution_Time1 = MSG_get_clock() - start_time;

    msg_task_t reduce_task_12 = MSG_task_create("reduce_12", get_reduce_cost_12(MSG_host_self()), 0, NULL); // reduce tasks are created and executed here
    MSG_task_execute(reduce_task_12);
    double task_size = MSG_task_get_flops_amount(reduce_task_12);
    if(task_size== 0)
     {
      strcpy(Task_status, "Done");
      }
     else
      {
       strcpy(Task_status, "Crushed");
      }

    sim_reduce_12 += MSG_get_clock() - start_time;

    Execution_Time2 = MSG_get_clock() - start_time;
    int host= MSG_process_self_PPID();
    Execution_Time1=exec_Redfunction_20(host, Execution_Time2);

    const char *stop_host = MSG_host_get_name(MSG_host_self());
    stop_t =MSG_get_clock();
    int time = MSG_process_self_PPID();
    stop_tt=Redstoptime_function_20(time, stop_t);

    /* Generating the hostnames, mappers and execution Times for ReduceTask_10  */
    for (k = 0; k<num_hosts; k++)
     {
      if ((strncmp(hst[k], MSG_process_get_name(MSG_process_self()), 5)== 0))

    {
    	strcpy(reduce12_times[twelveredtask].namee, host_nam);
    	strcpy(reduce12_times[twelveredtask].finish_host, stop_host);
    	strcpy(reduce12_times[twelveredtask].NodeStatus, Node_statu);
    	strcpy(reduce12_times[twelveredtask].task_status, Task_status);
    	reduce12_times[twelveredtask].launch_times=start_time;
    	reduce12_times[twelveredtask].finish_Times=stop_tt;
    	reduce12_times[twelveredtask].pidd=MSG_process_self_PID();
    	reduce12_times[twelveredtask].redtimes =  Execution_Time1;
    	reduce12_times[twelveredtask].idd = twelveredtask;
    	twelveredtask  = twelveredtask  + 1 ;

    }
  }

     /* End of Execution Times Generation*/

    i++;
    for(j=0;j<2;j++)
    {
     if(strncmp(snaps[j].name, MSG_process_get_name(MSG_process_self()), 5)== 0)
      {
      snaps[j].reducers--;
      }
    }
 // }
//   XBT_INFO("%s has completed a reduce task", MSG_process_get_name(MSG_process_self()));

// END OF REDUCE PROCESSING
    // Notify the master that I'm done working
    msg_comm_t comm = MSG_task_isend(MSG_task_create("reduce_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Main function */
int main(int argc, char *argv[])					// The main function required for the running of the simulator is declared and defined.
{
    int i, BYTES_PER_MEGABYTE = 1048576 ;// BYTES_PER_GIGABYTE = 1142352, 1048576 Bytes, 67108864(64mb)
    char *config_path;
    char *platform_path;
    char name[20];
    strcpy(snaps[0].name , "host1");
    snaps[0].mappers = 0;
    snaps[0].reducers = 0;
    strcpy(snaps[1].name , "host2");
    snaps[1].mappers = 0;
    snaps[1].reducers = 0;
    double config_grid_cpu_power; // just introduced
    //srand((unsigned)time(NULL));

    
    msg_error_t res = MSG_OK;
    MSG_init(&argc, argv);										// The MSG init function is called here to initialized the simulation processes.

    if (argc != 5)   											// The number of argument required to run the simulator should not be more than 5.
    {
        printf("Usage: %s map_cf reduce_cf config platform.xml\n", argv[0]);    				// The main function prompts for the supply of argument 1.
        printf("Example: %s 0.28 0.29 path_to_config path_to_platform.xml \n", argv[0]);  		// The main function prompts for the supply of argument 2.
        exit(1);
    }
    // Set calibration factors
    sscanf(argv[1], "%lf", &MAP_CALIBRATION_FACTOR);     					// The mapping calibration factor is received from terminal.
    sscanf(argv[2], "%lf", &REDUCE_CALIBRATION_FACTOR);  					// The reducing calibration factor is also received from terminal.

    // TODO: set the number of tasks to be created!
        number_tasks = 1; //14, 15, 20

    // Set file paths
    config_path = malloc(strlen(argv[3]) * sizeof(char));
    strcpy(config_path, argv[3]);
    
    platform_path = malloc(strlen(argv[4]) * sizeof(char));
    strcpy(platform_path, argv[4]);


    // Register the functions

    /*The key functions defined above are called and executed here. */

    MSG_function_register("master", master);
    MSG_function_register("initializeProcs", initializeProcs);
    MSG_function_register("map", map);
    for(int i =2;i<4;i++)
    {
    	char* name = "map_";
    	    int n1 = i;

    	    char *num;
    	    char buffer[20];
    	    if (asprintf(&num, "%d", n1) == -1) {
    	           perror("asprintf");
    	       } else {
    	           strcat(strcpy(buffer, name), num);
    	           printf("%s\n", buffer);
    	           free(num);
    	       }
    	    MSG_function_register(buffer, buffer);
    }

    MSG_function_register("map_0", map_0);
    MSG_function_register("reduce", reduce);
    MSG_function_register("reduce_2", reduce_2);
    MSG_function_register("shuffleSend", shuffleSend);
    MSG_function_register("shuffleReceive", shuffleReceive);
    
    // Create the environment
    MSG_create_environment(platform_path);                       // MSG reads the platform file and utilizes simgrid to launch the cloud simulation platform.
    
    // Read config file and set parameters
    FILE * config_file = fopen(config_path, "r");				// The arguments specified in the configuration file are read and uploaded.
    
    if (config_file == NULL)
    {
        fprintf(stderr, "Error while opening config file.\n");
        exit(1);
    }

    char line[256];
    int number_of_masters = 0;
    
    hosts = xbt_dict_new();
    host_attributes = xbt_dict_new();
    
    while (fgets(line, 256, config_file) != NULL)                       // reading the data from the configuration file. A specification of 256 characters have been made.
    {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) > 0)
        {
            char *line_cpy = malloc(strlen(line) * sizeof(char));
            strcpy(line_cpy, line);
            
            char *key = strsep(&line_cpy, " ");
            char *value = strsep(&line_cpy, " ");

            if (strcmp(key, "master") == 0 || strcmp(key, "worker") == 0)    // The initial values of the master and worker is set to set and compared before reading the file.
            {
                char **hosts;
                int hosts_length = 0;
                
                char *current_attributes = NULL;
                char *new_attributes = NULL;
                
                if (strchr(value, '-') != NULL)
                {
                    char *host1 = strsep(&value, "-"); // returns first host in range
                    char *host2 = strsep(&value, "-"); // returns last host in range
                    
                     char *prefix = malloc(strlen(host1) * sizeof(char));
                    strcpy(prefix, host1);
                    
                    for (i = 0; i < strlen(prefix); i++)
                    {
                        prefix[i] = (isdigit(prefix[i])) ? '\0' : prefix[i];
                    }
                    
                    int loopStart = atoi(&host1[strlen(prefix)]);
                    int loopEnd = atoi(&host2[strlen(prefix)]);
                    
                    hosts_length = loopEnd - loopStart + 1;					// The list of hosts to be uploaded for the simulation.
                    hosts = malloc((hosts_length) * sizeof(char *));

                    for (i = 0; i < hosts_length; i++)							// Uploading all the hosts within range for the simulation to commence.
                    {
                        hosts[i] = malloc(strlen(host2) * sizeof(char));
                        sprintf(hosts[i], "%s%d", prefix, loopStart + i);
                      }
                }
                else
                {
                    hosts = malloc(sizeof(char *));
                    hosts[0] = malloc(strlen(key) * sizeof(char));
                    sprintf(hosts[0], "%s", value);
                    hosts_length = 1;
                }
                
                for (i = 0; i < hosts_length; i++)
                {
                    number_of_masters += (strcmp(key, "master") == 0) ? 1 : 0;
                    number_of_workers += (strcmp(key, "worker") == 0) ? 1 : 0;
                    
                    current_attributes = xbt_dict_get_or_null(host_attributes, hosts[i]);
                    
                    if (current_attributes != NULL)
                    {
                        new_attributes = malloc((strlen(key) + strlen(current_attributes) + 2) * sizeof(char));
                        strcat(new_attributes, current_attributes);
                        strcat(new_attributes, " ");
                    }
                    else
                    {
                        new_attributes = malloc(strlen(hosts[i]) + sizeof(char));

                    }
                  strcat(new_attributes, key);
                    xbt_dict_set(host_attributes, hosts[i], new_attributes, NULL);
                }
                
            }
            else if (strcmp(key, "mappers") == 0)
            {
                if (isdigit(*value))
                   {
                    mappers = atoi(value);
                   }
            }
            else if (strcmp(key, "mappers_2") == 0)
            {
                if (isdigit(*value))
                {
                    mappers_2 = atoi(value);
                }
            }
            else if (strcmp(key, "mappers_3") == 0)
                        {
                            if (isdigit(*value))
                            {
                                mappers_3 = atoi(value);
                            }
                        }
            else if (strcmp(key, "mappers_4") == 0)
                          {
                             if (isdigit(*value))
                              {
                                 mappers_4 = atoi(value);
                                }
                            }
            else if (strcmp(key, "mappers_5") == 0)
                          {
                              if (isdigit(*value))
                               {
                                 mappers_5 = atoi(value);
                                }
                           }
            else if (strcmp(key, "mappers_6") == 0)
                            {
                                 if (isdigit(*value))
                                 {
                                 mappers_6 = atoi(value);
                                  }
                               }
            else if (strcmp(key, "mappers_7") == 0)
                          {
                             if (isdigit(*value))
                              {
                                mappers_7 = atoi(value);
                                }
                                }
            else if (strcmp(key, "mappers_8") == 0)
                   {
                        if (isdigit(*value))
                           {
                              mappers_8 = atoi(value);
                            }
                    }
            else if (strcmp(key, "mappers_9") == 0)
                       {
                            if (isdigit(*value))
                          {
                             mappers_9 = atoi(value);
                          }
                      }
            else if (strcmp(key, "mappers_0") == 0)
                         {
                               if (isdigit(*value))
                              {
                                  mappers_0 = atoi(value);
                                }
                           }
            else if (strcmp(key, "mappers_11") == 0)
                           {
                              if (isdigit(*value))
                                {
                                 mappers_11 = atoi(value);
                                 }
                            }
            else if (strcmp(key, "mappers_12") == 0)
                            {
                               if (isdigit(*value))
                                 {
                                  mappers_12 = atoi(value);
                                  }
                            }

             else if (strcmp(key, "reducers") == 0)
            {
                if (isdigit(*value))
                {
                    reducers = atoi(value);

                }
            }
            /*introduced reducers_2 for reduce task 2*/
            else if (strcmp(key, "reducers_2") == 0)
                       {
                           if (isdigit(*value))
                           {
                               reducers_2 = atoi(value);
                             }
                       }

             else if (strcmp(key, "reducers_3") == 0)
                       {
                             if (isdigit(*value))
                                {
                                  reducers_3 = atoi(value);
                              }
                         }
             else if (strcmp(key, "reducers_4") == 0)
                       {
                             if (isdigit(*value))
                                {
                                  reducers_4 = atoi(value);
                              }
                         }
             else if (strcmp(key, "reducers_5") == 0)
                          {
                               if (isdigit(*value))
                                 {
                                    reducers_5 = atoi(value);
                                   }
                            }
             else if (strcmp(key, "reducers_6") == 0)
                           {
                                 if (isdigit(*value))
                                   {
                                        reducers_6 = atoi(value);
                                    }
                            }
             else if (strcmp(key, "reducers_7") == 0)
                                {
                                      if (isdigit(*value))
                                        {
                                          reducers_7 = atoi(value);
                                        }
                                  }
             else if (strcmp(key, "reducers_8") == 0)
                          {
                             if (isdigit(*value))
                                 {
                                    reducers_8 = atoi(value);
                                  }
                            }

             else if (strcmp(key, "reducers_9") == 0)
                           {
                                if (isdigit(*value))
                                       {
                                          reducers_9 = atoi(value);
                                        }
                             }
             else if (strcmp(key, "reducers_10") == 0)
                    {
                        if (isdigit(*value))
                               {
                                    reducers_10 = atoi(value);
                                }
                     }

            else if (strcmp(key, "input_size_in_mb") == 0)
            {
                if (isdigit(*value))
                {
                    input_size = atol(value);
                    input_size_bytes = input_size * BYTES_PER_MEGABYTE;
                }
            }
     else if (strcmp(key, "hdfs_chunk_size_in_mb") == 0)
            {
                if (isdigit(*value))
                {
                    hdfs_chunk_size = atoi(value);
                    hdfs_chunk_size_bytes = hdfs_chunk_size * BYTES_PER_MEGABYTE;
                }
            }
           // Freeing 'key' works since 'key' will always point to the address returned by
            // malloc whereas the value of line_cpy changes as a result of the call to strsep.
            free(key);
        }
    }

    fclose(config_file);
    
    // Must have exactly one master process
    if (number_of_masters != 1)
    {
        fprintf(stderr, "There must be exactly one master process.\n");
        exit(1);
    }

    xbt_dynar_t host_dynar = MSG_hosts_as_dynar();
    number_of_hosts = (int) xbt_dynar_length(host_dynar);
    
    XBT_INFO("Got %ldMB input, %ldMB chunks, %ld mappers, %ld reducers, and %d hosts\n",
             input_size,
             hdfs_chunk_size,
             mappers,
             reducers,
             number_of_hosts);
   //
    // Now that the platform environment has been created, associate each hdmsg_host with an actual msg_host_t
    int host_id = 1;
    unsigned int cpt;
    msg_host_t dyn_host;

    xbt_dynar_foreach (host_dynar, cpt, dyn_host)
    {
        char *attributes = xbt_dict_get_or_null(host_attributes, MSG_host_get_name(dyn_host));
        
        if (attributes != NULL)
        {
            struct HdmsgHost *hdmsg_host = newHdmsgHost(0, dyn_host, attributes);
            
            if (hdmsg_host->is_master)
            {
                hdmsg_host->host_id = 0;
                MSG_process_create("master", master, NULL, hdmsg_host->host);
            }
            else
            {
                hdmsg_host->host_id = host_id;
                host_id++;
            }
               xbt_dict_set(hosts, hdmsg_host->host_name, hdmsg_host, (void *)destroyHdmsgHost);
        }
    }
    // TODO: Should I ensure that each hdmsg_host has an msg_host_t?

  for (int i = 1; i <= number_tasks; ++i) // 100 for 1k,500 for 5k,1000 for 10k
  {
	  distributeHdfsChunks();
	  distributeHdfsChunks_2();
	  distributeHdfsChunks_3();
	  distributeHdfsChunks_4();
	  distributeHdfsChunks_5();
	  distributeHdfsChunks_6();
	  distributeHdfsChunks_7();
	  distributeHdfsChunks_8();
	  distributeHdfsChunks_9();
	  distributeHdfsChunks_0();
/*	  distributeHdfsChunks_11();
	  distributeHdfsChunks_12();
*/
    }

   res = MSG_main();
   ////take_snapshot();

    //delayed_mappers();
    double simulation_time = MSG_get_clock();
    int counter = 0;

    printf("*********************************************");
    int k=0;
    int numberofblanks=1;
    printf("*");
    for(k=0;k<numberofblanks;k++)
    printf("******************************************************* ");
    printf("**************************************\n");


    XBT_INFO("Simulation time %g", simulation_time);

      sim_map /= (input_size_bytes / hdfs_chunk_size_bytes); // (input_size_bytes / hdfs_chunk_size_bytes) = number of map tasks

       // long number_of_input_chunks = (input_size_bytes / hdfs_chunk_size_bytes); 1024/128(8),512/128(4),256/128(2)

       sim_reduce /= reducers;

    sim_reduce_2 /= reducers_2;
    sim_reduce_3 /= reducers_3;
    sim_reduce_4 /= reducers_4;
    sim_reduce_5 /= reducers_5;
    sim_reduce_6 /= reducers_6;
    sim_reduce_7 /= reducers_7;
    sim_reduce_8 /= reducers_8;
    sim_reduce_9 /= reducers_9;
    sim_reduce_10 /= reducers_10;

    int iX, iY, iZ,iT;
    iX = log2(input_size) - 8;
    iY = log2(hdfs_chunk_size) - 5;
    iZ = log2(reducers) - 2;

    // If I don't have actual execution times, then don't print stats just exit.
  //  if (iX >= 3 || iY >= 3 || iZ >= 3) { return (res == MSG_OK) ? 0 : 1; }
    if (iX >= 24 || iY >= 24 || iZ >= 24) { return (res == MSG_OK) ? 0 : 1; }
    
    //double a;
    double mapTimes[3][3][3]; //= a;  // Input size (256, 512, 1024), Chunk size (32, 64, 128), Number of reducers (4, 8, 16)

        /*  256  */													//Generally, maptimes increases by an approximate 52% as the chunk size increases whilst the input size and reducers are maintained.
    																// Utilizing the chunk dynamics of the chunk sizes, the maptimes not provided were determined.
    																// 256-32-8 to 256-64-8 increased from 391 to 815(52% approx. increase), also, 256-32-4 to 256-64-4 increased from 399 to 830(52% approx. increase)
      mapTimes[0][0][0] = 399; // 256-32-4
      mapTimes[0][0][1]= 391;  // 256-32-8 ---> 399*0.98 ---> 0.98*X (where x is the value of the lowest reducer number)
      mapTimes[0][0][2] = 385;  // 256-32-16 --->399*0.965 -->0.965*X (where x is the value of the lowest reducer number)
    
      mapTimes[0][1][0] = 830; // 256-64-4
      mapTimes[0][1][1] = 815;  // 256-64-8  // --->830*0.982    // 256-128-4 = 1261, 256-128-8 = 1239, 256-128-16 = 1233
      mapTimes[0][1][2] = 801;  // 256-64-16 //---->830* 0.965   //256-32-8,256-64-8,256-128-8, maintaining 8 reducers, the maptimes increase by 52% approx.
                                                                 //256-32-4,256-64-4,256-128-4, maintaining 4 reducers, the maptimes increase by 52% approx.
      	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 //256-32-16,256-64-16,256-128-16, maintaining 16 reducers, the maptimes increase by 52% approx.

        /*  512 */
       mapTimes[0][0][0] = 399; // 256-32-4
       mapTimes[0][0][1] = 391;  // 256-32-8 ---> 399*0.98 ---> 0.98*X (where x is the value of the lowest reducer number) //for 256-32, the maptimes decrease by 2% as reducers increase from 4 to 8 and 1.5% from 8 to 16
       mapTimes[0][0][2]= 385;  // 256-32-16 --->399*0.965 -->0.965*X (where x is the value of the lowest reducer number)
    
       mapTimes[1][0][0]= 438; // 512-32-4
       mapTimes[1][0][1] = 432;  // 512-32-8  --->0.986*438
       mapTimes[1][0][2] = 425;  // 512-32-16 --->0.970*438 // 512-32, the maptimes decrease by 1.8% as the reducers increase from 4 to 8
       	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   //and by 1.6% as the reducers increase from 8 to 16
    
       mapTimes[1][1][0]= 833; // 512-64-4
       mapTimes[1][1][1]= 821; // 512-64-8 ----> 0.986 * 833 (1.44 decrease
       mapTimes[1][1][2]= 809; // 512-64-16 --->0.971 * 833 (1.44 decrease) // For the 512-64, the maptimes decrease by 1.44% as the number of reducers increase
    
       mapTimes[1][2][0] = 1638; // 512-128-4
       mapTimes[1][2][1]= 1616; // 512-128-8 ---->0.9863*1638  //
       mapTimes[1][2][2]= 998; // 512-128-16 --->0.618*1616

       /*  1024 */ // introduced
       mapTimes[2][2][0]=1802;// 1024-128-4;
       mapTimes[2][2][1]=1778;//1024-128-8 //10% approx. increase from 256 to 512 to 1024 (input_sizes)
       mapTimes[2][2][2]=1098;//1024-128-16;
       //no conclusion reached for maptimes

       /*  2048 */  //introduced
       mapTimes[3][2][0]=1982;// 2048-128-4;
       mapTimes[3][2][1]=1949;// 2048-128-8;
       mapTimes[3][2][2]=1208;// 2048-128-16;

       //double b;
       double reduceTimes[3][3][3];// = b;

    
         /*  256  */
       reduceTimes[0][0][0] = 334; // 256-32-4						   //There is a  52% general approximate reduction in reduce_times as the  number_of_reducers increase.
       reduceTimes[0][0][1] = 168;  // 256-32-8 ---> 0.503*334         // However, there is a 52% increase in reduce_times when the chunk size and the  number_of_reducers are maintain and the input_sizes  increases
       reduceTimes[0][0][2] = 91;  // 256-32-16 ---> 0.542*168         //256-64-8 to 512-64-8 experiences an approximate increase of  52% in reduce times from 171 to 342
       	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	    // 256-32-4 to 512-32-4 increases from 334 to 672
       reduceTimes[0][1][0] = 334; // 256-64-4
       reduceTimes[0][1][1] = 171;  // 256-64-8--> 0.512*334
       reduceTimes[0][1][2] = 90;  // 256-64-16 -->0.526*171

       	   	   	   	   	   	   	   // 256-128-4
       	   	   	   	   	   	   	   // 256-128-8
       	   	   	   	   	   	   	   // 256-128-16
    
        /*  512 */
       reduceTimes[0][0][0] = 334; // 256-32-4
       reduceTimes[0][0][1] = 168;  // 256-32-8 --->0.503*334
       reduceTimes[0][0][2] = 91;  // 256-32-16 --->0.542*168
    
       reduceTimes[1][0][0] = 672; // 512-32-4
       reduceTimes[1][0][1] = 338;  // 512-32-8---> 0.503*672
       reduceTimes[1][0][2] = 187;  // 512-32-16 ---> 0.553*338map_task_1_exTime_host_1
    
       reduceTimes[1][1][0] = 664; // 512-64-4
       reduceTimes[1][1][1] = 342; // 512-64-8 ---> 0.515*664
       reduceTimes[1][1][2] = 184; // 512-64-16 ---> 0.538*342
    
       reduceTimes[1][2][0] = 667; // 512-128-4
       reduceTimes[1][2][1] = 338; // 512-128-8 ----> 0.507*667
       reduceTimes[1][2][2] = 183; // 512-128-16 ---> 0.541*338


       /*  1024 */ //introduced

       reduceTimes[2][2][0] = 994 ;// 1024-128-4 //approximate 49% percent increase 512-128-4 to 1024-128-4 ...667 to 994
       reduceTimes[2][2][1] = 514; // 1024-128-8 //approximate 52% percent increase // therefore, 512-128-8 to 1024-128-8 increases from 338 to 514.
       reduceTimes[2][2][0] = 273 ;// 1024-128-4	//approximate 49% percent increase 512-128-16 to 1024-128-6 ...183 to 273

       /*  2048 */ //introduced
       reduceTimes[3][2][0] = 1481;  // 2048-128-4
       reduceTimes[3][2][1] = 766;  // 2048-128-8
       reduceTimes[3][2][2] = 407;   // 2048-128-16


       // conclusion reached for reduce times
      // double c;
       double actualTimes[3][3][3];
        /*  256  */
       actualTimes[0][0][0] = 773; // 256-32-4
       actualTimes[0][0][1] = 600;  // 256-32-8 ---> 0.7762*773
       actualTimes[0][0][2] = 527;  // 256-32-16 --->0.8783*600
    
       actualTimes[0][1][0] = 1216; // 256-64-4
       actualTimes[0][1][1] = 1035;  // 256-64-8 ---> 0.851*1216
       actualTimes[0][1][2] = 947;  // 256-64-16--->0.915*1035

       	   	   	   	   	   	   	   	  // 256-128-4
       	   	   	   	   	   	   	   	  //256-128-8
       	   	   	   	   	   	   	   	  //256-128-16

         /*  256 */
       actualTimes[0][0][0] = 773; // 256-32-4
       actualTimes[0][0][1] = 600;  // 256-32-8 --->0.7762*773
       actualTimes[0][0][2] = 527;  // 256-32-16 ---->0.8783*600

       /*  512 */
       actualTimes[1][0][0] = 1172; // 512-32-4
       actualTimes[1][0][1] = 833;  // 512-32-8 ---->0.711*1172
       actualTimes[1][0][2] = 682;  // 512-32-16 ---> 0.819*833
    
       actualTimes[1][1][0] = 1562; // 512-64-4
       actualTimes[1][1][1] = 1221; // 512-64-8---> 0.782*1562
       actualTimes[1][1][2] = 1126; // 512-64-16--->0.9222*1221
    
       actualTimes[1][2][0] = 2237; // 512-128-4
       actualTimes[1][2][1] = 2031; // 512-128-8 --->0.908*2237
       actualTimes[1][2][2] = 1851; // 512-128-16 --->0.9114*2031

       /*  1024 */ //introduced
       actualTimes[2][2][0] = 2912; // 1024-128-4
       actualTimes[2][2][1] = 2841; // 1024-128-4 =2912 ; 1024-128-8 = 2841 ; 1024-128-16 = 2755;
       actualTimes[2][2][2] =  2755; //  1024-128-16

       /*  2048 */ //introduced
       actualTimes[3][2][0] = 5154; // 2048-128-4 , 77% increase from 2912 to 5154
       actualTimes[3][2][1] = 4639; // 2048-128-8, 0.9 decrease from 5154 to 4639
       actualTimes[3][2][2] = 4175; // 2048-128-16, 9.9 decrease from 4639 to 4175
       //no conclusion made for actual times
    double actual_map = mapTimes[iX][iY][iZ];
    double actual_reduce = reduceTimes[iX][iY][iZ];
    double actual_exec = actualTimes[iX][iY][iZ];
   // sim_mapp_0 =  sim_map + sim_map_2 + sim_map_3  + sim_map_4 + sim_map_5 + sim_map_6 + sim_map_7 + sim_map_8 + sim_map_9  + sim_map_0 + sim_map_11 + sim_map_12;
  sim_mapp_0 =  sim_map + sim_map_2 + sim_map_3  + sim_map_4 + sim_map_5 + sim_map_6 + sim_map_7 + sim_map_8 + sim_map_9  + sim_map_0;

    sim_reduce_0 = sim_reduce + sim_reduce_2 + sim_reduce_3 + sim_reduce_4 + sim_reduce_5 + sim_reduce_6 + sim_reduce_7 + sim_reduce_8 + sim_reduce_9+ sim_reduce_10 ;
  //sim_reduce_0 = sim_reduce + sim_reduce_2 + sim_reduce_3 + sim_reduce_4 + sim_reduce_5 + sim_reduce_6 + sim_reduce_7 + sim_reduce_8 + sim_reduce_9+ sim_reduce_10  + sim_reduce_11+ sim_reduce_12;


  //printf (" Reduce all is is %lf\n",sim_reduce_0);
	double simulation_time1 = sim_mapp_0 + sim_reduce_0;
    double sum_of_diffs = 100 * fabs(sim_mapp_0 - actual_map)/actual_map + 100 * fabs(sim_reduce_0 - actual_reduce)/actual_reduce;
    double avg_percent_diff = sum_of_diffs / 2;
    double sim_err = (fabs(simulation_time - actual_exec) / actual_exec) * 100;

    // Write results to file
    FILE * output_file = NULL;
    output_file = fopen("HDMSG_output.txt", "a");
    
    fprintf(output_file, "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
            MAP_CALIBRATION_FACTOR,
            REDUCE_CALIBRATION_FACTOR,
            sim_map,
            actual_map,
            sim_reduce,
            actual_reduce,
            simulation_time,
            actual_exec,
            sim_err,
            sum_of_diffs,
            avg_percent_diff);

    fclose(output_file);
    /* Print maptasks outputs to file*/
    FILE * map1_file = NULL;
    map1_file = fopen("Map1File.txt", "w");
    // TODO: Where all print outs begin!
    //fprintf(map1_file, "Task ID \tStart Time\tStop Time \tTask_Status \t\t\tStart_Host\t\tStop_Host \t\tPID \t\tExec_Time\t\tNode_Status\n");//\tStart_HostID \tStop_HostID\tPID
    fprintf(map1_file, "Task_ID Launch_Time Launch_Host  Fin_Time   \tFin_Host  PID  Ex_Time FinHst_Status  Task_Status \n");
    for(int i = 0;i<number_tasks*107;i++)
    {
    	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map1_times[i].id, map1_times[i].times, map1_times[i].name, map1_times[i].Endhostname, map1_times[i].Stop_Times, map1_times[i].pid, map1_times[i].exec_Times, map1_times[i].NodeStatus, map1_times[i].task_status);
     	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map2_times[i].id, map2_times[i].times, map2_times[i].name, map2_times[i].Endhostname, map2_times[i].Stop_Times, map2_times[i].pid, map2_times[i].exec_Times, map2_times[i].NodeStatus, map2_times[i].task_status);
    	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map3_times[i].id, map3_times[i].times, map3_times[i].name, map3_times[i].Endhostname, map3_times[i].Stop_Times, map3_times[i].pid, map3_times[i].exec_Times, map3_times[i].NodeStatus, map3_times[i].task_status);
    	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map4_times[i].id, map4_times[i].times, map4_times[i].name, map4_times[i].Endhostname, map4_times[i].Stop_Times, map4_times[i].pid, map4_times[i].exec_Times, map3_times[i].NodeStatus, map4_times[i].task_status);
     	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map5_times[i].id, map5_times[i].times, map5_times[i].name, map5_times[i].Endhostname, map5_times[i].Stop_Times, map5_times[i].pid, map5_times[i].exec_Times, map5_times[i].NodeStatus, map5_times[i].task_status);
		fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map6_times[i].id, map6_times[i].times, map6_times[i].name, map6_times[i].Endhostname, map6_times[i].Stop_Times, map6_times[i].pid, map6_times[i].exec_Times, map6_times[i].NodeStatus, map6_times[i].task_status);
      	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map7_times[i].id, map7_times[i].times, map7_times[i].name, map7_times[i].Endhostname, map7_times[i].Stop_Times, map7_times[i].pid, map7_times[i].exec_Times, map7_times[i].NodeStatus, map7_times[i].task_status);
		fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map8_times[i].id, map8_times[i].times, map8_times[i].name, map8_times[i].Endhostname, map8_times[i].Stop_Times, map8_times[i].pid, map8_times[i].exec_Times, map8_times[i].NodeStatus, map8_times[i].task_status);
		fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map9_times[i].id, map9_times[i].times, map9_times[i].name, map9_times[i].Endhostname, map9_times[i].Stop_Times, map9_times[i].pid, map9_times[i].exec_Times, map9_times[i].NodeStatus, map9_times[i].task_status);
     	fprintf(map1_file,"%d\t%.4f\t\t%s\t\t%.4f\t\t%s\t%d\t%.4f\t%s\t\t%s\n",map10_times[i].id, map10_times[i].times, map10_times[i].name, map10_times[i].Endhostname, map10_times[i].Stop_Times, map10_times[i].pid, map10_times[i].exec_Times, map10_times[i].NodeStatus, map10_times[i].task_status);

    }

    fclose(map1_file);
     /* Print snapshots of  specific period of maptasks to file*/
        FILE * snapmap1_file = NULL;
        snapmap1_file = fopen("SnapMap1File.txt", "w");
        fprintf(snapmap1_file, "Host Name \tStart_Host \tPID \t\tTask ID \tExecution Time \n");
        for(int i = 0;i<number_tasks*107;i++)
        {
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n", snapmap1_times[i].name, snapmap1_times[i].starthost,snapmap1_times[i].pid,snapmap1_times[i].id, snapmap1_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n", snapmap2_times[i].name,snapmap2_times[i].starthost, snapmap2_times[i].pid,snapmap2_times[i].id, snapmap2_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n", snapmap3_times[i].name, snapmap3_times[i].starthost, snapmap3_times[i].pid,snapmap3_times[i].id, snapmap3_times[i].times);
            fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n", snapmap4_times[i].name, snapmap4_times[i].starthost, snapmap4_times[i].pid,snapmap4_times[i].id, snapmap4_times[i].times);
            fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n", snapmap5_times[i].name, snapmap5_times[i].starthost, snapmap5_times[i].pid,snapmap5_times[i].id, snapmap5_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n",snapmap6_times[i].name, snapmap6_times[i].starthost, snapmap6_times[i].pid,snapmap6_times[i].id, snapmap6_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n",snapmap7_times[i].name, snapmap7_times[i].starthost, snapmap7_times[i].pid,snapmap7_times[i].id, snapmap7_times[i].times);
            fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n",snapmap8_times[i].name, snapmap8_times[i].starthost, snapmap8_times[i].pid,snapmap8_times[i].id, snapmap8_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n",snapmap9_times[i].name, snapmap9_times[i].starthost, snapmap9_times[i].pid,snapmap9_times[i].id, snapmap9_times[i].times);
        	fprintf(snapmap1_file,"%s\t\t%d\t\t%d\t\t%d\t\t%.4f\n",snapmap10_times[i].name, snapmap10_times[i].starthost, snapmap10_times[i].pid,snapmap10_times[i].id, snapmap10_times[i].times);
        }

        fclose(snapmap1_file);
   /* Print Reducetasks output to file*/
    FILE * reduce_file = NULL;
    //printf
    reduce_file = fopen("reduce_file.txt", "w");
       fprintf(reduce_file, "T_ID \tLaunch_Time\t Launch_Host  \t Task_Term_Time \tTask_Term_Host\t Fin_Time  \tFin_Host  PID  Ex_Time FinHst_Status   Task_Status \n");

       for(int i = 0;i<NumOfReduceTasks*37;i++)
       {
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce1_times[i].idd, reduce1_times[i].launch_times, reduce1_times[i].namee, reduce1_times[i].TrferStarthost, reduce1_times[i].TrferStop_Times, reduce1_times[i].TrferEndhost, reduce1_times[i].finish_Times, reduce1_times[i].finish_host, reduce1_times[i].pidd, reduce1_times[i].redtimes, reduce1_times[i].NodeStatus, reduce1_times[i].TaskUpNodeStatus, reduce1_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce2_times[i].idd, reduce2_times[i].launch_times, reduce2_times[i].namee, reduce2_times[i].TrferStarthost, reduce2_times[i].TrferStop_Times, reduce2_times[i].TrferEndhost, reduce2_times[i].finish_Times, reduce2_times[i].finish_host, reduce2_times[i].pidd, reduce2_times[i].redtimes,  reduce2_times[i].NodeStatus, reduce2_times[i].TaskUpNodeStatus, reduce2_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce3_times[i].idd, reduce3_times[i].launch_times, reduce3_times[i].namee, reduce3_times[i].TrferStarthost, reduce3_times[i].TrferStop_Times, reduce3_times[i].TrferEndhost, reduce3_times[i].finish_Times, reduce3_times[i].finish_host, reduce3_times[i].pidd, reduce3_times[i].redtimes,  reduce3_times[i].NodeStatus, reduce3_times[i].TaskUpNodeStatus, reduce3_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce4_times[i].idd, reduce4_times[i].launch_times, reduce4_times[i].namee, reduce4_times[i].TrferStarthost, reduce4_times[i].TrferStop_Times, reduce4_times[i].TrferEndhost, reduce4_times[i].finish_Times, reduce4_times[i].finish_host, reduce4_times[i].pidd, reduce4_times[i].redtimes,  reduce4_times[i].NodeStatus, reduce4_times[i].TaskUpNodeStatus, reduce4_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce5_times[i].idd, reduce5_times[i].launch_times, reduce5_times[i].namee,reduce5_times[i].TrferStarthost, reduce5_times[i].TrferStop_Times, reduce5_times[i].TrferEndhost, reduce5_times[i].finish_Times, reduce5_times[i].finish_host, reduce5_times[i].pidd, reduce5_times[i].redtimes,  reduce5_times[i].NodeStatus, reduce5_times[i].TaskUpNodeStatus, reduce5_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce6_times[i].idd, reduce6_times[i].launch_times, reduce6_times[i].namee, reduce6_times[i].TrferStarthost, reduce6_times[i].TrferStop_Times, reduce6_times[i].TrferEndhost, reduce6_times[i].finish_Times, reduce6_times[i].finish_host, reduce6_times[i].pidd, reduce6_times[i].redtimes,  reduce6_times[i].NodeStatus, reduce6_times[i].TaskUpNodeStatus, reduce6_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce7_times[i].idd, reduce7_times[i].launch_times, reduce7_times[i].namee, reduce7_times[i].TrferStarthost, reduce7_times[i].TrferStop_Times, reduce7_times[i].TrferEndhost, reduce7_times[i].finish_Times, reduce7_times[i].finish_host, reduce7_times[i].pidd, reduce7_times[i].redtimes,  reduce7_times[i].NodeStatus, reduce7_times[i].TaskUpNodeStatus, reduce7_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce8_times[i].idd, reduce8_times[i].launch_times, reduce8_times[i].namee, reduce8_times[i].TrferStarthost, reduce8_times[i].TrferStop_Times, reduce8_times[i].TrferEndhost, reduce8_times[i].finish_Times, reduce8_times[i].finish_host, reduce8_times[i].pidd, reduce8_times[i].redtimes,  reduce8_times[i].NodeStatus, reduce8_times[i].TaskUpNodeStatus, reduce8_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce9_times[i].idd, reduce9_times[i].launch_times, reduce9_times[i].namee, reduce9_times[i].TrferStarthost, reduce9_times[i].TrferStop_Times, reduce9_times[i].TrferEndhost, reduce9_times[i].finish_Times, reduce9_times[i].finish_host, reduce9_times[i].pidd, reduce9_times[i].redtimes,  reduce9_times[i].NodeStatus, reduce9_times[i].TaskUpNodeStatus, reduce9_times[i].task_status);
    	   fprintf(reduce_file, "%d\t%.4f\t%s\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce10_times[i].idd, reduce10_times[i].launch_times, reduce10_times[i].namee, reduce10_times[i].TrferStarthost, reduce10_times[i].TrferStop_Times, reduce10_times[i].TrferEndhost, reduce10_times[i].finish_Times, reduce10_times[i].finish_host, reduce10_times[i].pidd, reduce10_times[i].redtimes,  reduce10_times[i].NodeStatus, reduce10_times[i].TaskUpNodeStatus, reduce10_times[i].task_status);
/* 	 	   fprintf(reduce_file, "%d\t%.4f\t%s\t%.4f\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce11_times[i].idd, reduce11_times[i].launch_times, reduce11_times[i].namee, reduce11_times[i].TrferStarthost, reduce11_times[i].TrferStop_Times, reduce11_times[i].TrferEndhost, reduce11_times[i].finish_Times, reduce11_times[i].finish_host, reduce11_times[i].pidd, reduce11_times[i].redtimes,  reduce11_times[i].NodeStatus, reduce11_times[i].TaskUpNodeStatus, reduce11_times[i].task_status);
   	   	   fprintf(reduce_file, "%d\t%.4f\t%s\t%.4f\t\t%s\t\t%.4f\t\t%s\t\t%.4f\t%s\t%d\t%.4f\t%s\t%s\t%s\n",reduce12_times[i].idd, reduce12_times[i].launch_times, reduce12_times[i].namee, reduce12_times[i].TrferStarthost, reduce12_times[i].TrferStop_Times, reduce12_times[i].TrferEndhost, reduce12_times[i].finish_Times, reduce12_times[i].finish_host, reduce12_times[i].pidd, reduce12_times[i].redtimes,  reduce12_times[i].NodeStatus, reduce12_times[i].TaskUpNodeStatus, reduce12_times[i].task_status);
*/

       }
       fclose(reduce_file);
       /* Print snapshots of  specific period of reduce_tasks to file*/

       FILE * snapred1_file = NULL;
       snapred1_file = fopen("SnapRed1File.txt", "w");
           fprintf(snapred1_file, "Host Name \tStart_Host \tTask ID \tExecution Time \n");
           for(int i = 0;i<NumOfReduceTasks*37;i++)
           {
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap1_times[i].namee,redsnap1_times[i].starthost,redsnap1_times[i].idd,redsnap1_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap2_times[i].namee,redsnap2_times[i].starthost,redsnap2_times[i].idd,redsnap2_times[i].redsnaptimes);
                fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap3_times[i].namee,redsnap3_times[i].starthost,redsnap3_times[i].idd,redsnap3_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap4_times[i].namee,redsnap4_times[i].starthost,redsnap4_times[i].idd,redsnap4_times[i].redsnaptimes);
                fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap5_times[i].namee,redsnap5_times[i].starthost,redsnap5_times[i].idd,redsnap5_times[i].redsnaptimes);
                fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap6_times[i].namee,redsnap6_times[i].starthost,redsnap6_times[i].idd,redsnap6_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap7_times[i].namee,redsnap7_times[i].starthost,redsnap7_times[i].idd,redsnap7_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap8_times[i].namee,redsnap8_times[i].starthost,redsnap8_times[i].idd,redsnap8_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap9_times[i].namee,redsnap9_times[i].starthost,redsnap9_times[i].idd,redsnap9_times[i].redsnaptimes);
            	fprintf(snapred1_file, "%s\t\t%d\t\t%d\t\t%.4f\n",redsnap10_times[i].namee,redsnap10_times[i].starthost,redsnap10_times[i].idd,redsnap10_times[i].redsnaptimes);

           }
           fclose(snapred1_file);
    // Write results to the console
    printf("\n\t\tMap Phase\t\tReduce Phase\t\tTotal Execution Time\t\tSimulation Time\n");

    printf("Simulated: %14.2f %26.2f %25.2f %24.2f \n\n", sim_mapp_0, sim_reduce_0, simulation_time1, simulation_time);

    return (res == MSG_OK) ? 0 : 1;
   /* end_of_main */
}

// The initialization cost for each host, produced by msg is obtained from this method.


double Log2(double n)
  {
      return log(n) / log(2);
  }


int random_int(int min, int max)
{
   return(min + rand() % (max - min));
}
