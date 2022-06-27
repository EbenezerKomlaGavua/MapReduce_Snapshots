/*
 * Process.c
 *
 *  Created on: Dec 19, 2021
 *      Author: Ebenezer Komla Gavua
 */
/* Process Prototypes */
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
double get_initialization_cost(msg_host_t);

long reducers_5;
long reducers_6;
long reducers_7;
long reducers_8;
long reducers_9;
long reducers_10;

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


double timeout =1;


//The initialization cost for each host, produced by msg is obtained from this method.
double get_initialization_cost(msg_host_t h)
{
  // double INIT_CALIBRATION_FACTOR = 35;
	double INIT_CALIBRATION_FACTOR =1;
    return INIT_CALIBRATION_FACTOR * MSG_host_get_speed(h);
}


/** Initialize Processes */
int initializeProcs(int argc, char * argv[])
{
    // Get the current host
    const char * host_name = MSG_host_get_name(MSG_process_get_host(NULL));
    struct HdmsgHost * this_host = xbt_dict_get(hosts, host_name);

    int i;
    long mappers_to_launch = MSG_host_get_core_number(this_host->host);

    long reducers_to_launch = reducers/ number_of_workers; 																// Number of reducers to launch. Meaning if 8 reducers are configured, 4 will be launched. 16 reducers, 8 will be launched.



    // If the number of reducers is not divisible by the number of workers,
    // allocate the remaining reducers
    if (reducers % number_of_workers != 0)
    {
        if (this_host->host_id <= (reducers % number_of_workers))
        {
            reducers_to_launch++;
        }
    }

    // Create mappers

//TODO
     mappers += mappers_to_launch;
      for (i = 0; i < mappers_to_launch; i++)
       {
         char * mapper_name = bprintf("%s-Mapper(M1T1_1/10)-%d", host_name, i);  		// Generates the host_name linked to the mapper and the counter.eg: host1-Mapper-1.
         msg_process_t mapper = MSG_process_create(mapper_name, map, NULL, this_host->host); // creates a map task
          xbt_fifo_push(this_host->mappers, mapper);
          this_host->active_mappers++;

     	}

     mappers_2 += mappers_to_launch;
       for (i = 0; i < mappers_to_launch; i++)
           {
             char * mapper_name = bprintf("%s-Mapper(M1T1_2/10)-%d", host_name, i);
             msg_process_t mapper_2 = MSG_process_create(mapper_name, map_2, NULL, this_host->host);
             xbt_fifo_push(this_host->mappers_2, mapper_2);
             this_host->active_mappers_2++;
         	}

    mappers_3 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
         char * mapper_name = bprintf("%s-Mapper(M1T1_3/10)-%d", host_name, i);
         msg_process_t mapper_3 = MSG_process_create(mapper_name, map_3, NULL, this_host->host);
         xbt_fifo_push(this_host->mappers_3, mapper_3);
         this_host->active_mappers_3++;
    	}

   mappers_4 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
    	char * mapper_name = bprintf("%s-Mapper(M1T1_4/10)-%d", host_name, i);
        msg_process_t mapper_4 = MSG_process_create(mapper_name, map_4, NULL, this_host->host);
        xbt_fifo_push(this_host->mappers_4, mapper_4);
        this_host->active_mappers_4++;
    	}

    mappers_5 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
    	char * mapper_name = bprintf("%s-Mapper(M1T1_5/10)-%d", host_name, i);
    	msg_process_t mapper_5 = MSG_process_create(mapper_name, map_5, NULL, this_host->host);
        xbt_fifo_push(this_host->mappers_5, mapper_5);
        this_host->active_mappers_5++;
    	}

    mappers_6 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
    	char * mapper_name = bprintf("%s-Mapper_(M1T1_6/10)-%d", host_name, i);
    	msg_process_t mapper_6 = MSG_process_create(mapper_name, map_6, NULL, this_host->host);
        xbt_fifo_push(this_host->mappers_6, mapper_6);
        this_host->active_mappers_6++;
    	}

    mappers_7 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
       char * mapper_name = bprintf("%s-Mapper(M1T1_7/10)-%d", host_name, i);
       msg_process_t mapper_7 = MSG_process_create(mapper_name, map_7, NULL, this_host->host);
       xbt_fifo_push(this_host->mappers_7, mapper_7);
       this_host->active_mappers_7++;
    	}

    mappers_8 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
    	char * mapper_name = bprintf("%s-Mapper(M1T1_8/10)-%d", host_name, i);
    	msg_process_t mapper_8 = MSG_process_create(mapper_name, map_8, NULL, this_host->host);
    	xbt_fifo_push(this_host->mappers_8, mapper_8);
    	this_host->active_mappers_8++;
    	}

    mappers_9 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
         char * mapper_name = bprintf("%s-Mapper(M1T1_9/10)-%d", host_name, i);
         msg_process_t mapper_9 = MSG_process_create(mapper_name, map_9, NULL, this_host->host);
         xbt_fifo_push(this_host->mappers_9, mapper_9);
         this_host->active_mappers_9++;
    	}


    mappers_0 += mappers_to_launch;
    for (i = 0; i < mappers_to_launch; i++)
    	{
            char * mapper_name = bprintf("%s-Mapper(M1T1_10/10)-%d", host_name, i);
            msg_process_t mapper_0 = MSG_process_create(mapper_name, map_0, NULL, this_host->host);
            xbt_fifo_push(this_host->mappers_0, mapper_0);
            this_host->active_mappers_0++;
    	}

   mappers_11 += mappers_to_launch;
       for (i = 0; i < mappers_to_launch; i++)
       {
            char * mapper_name = bprintf("%s-Mapper(M1T1_11/10)-%d", host_name, i);
            msg_process_t mapper_11 = MSG_process_create(mapper_name, map_11, NULL, this_host->host);
            xbt_fifo_push(this_host->mappers_11, mapper_11);
            this_host->active_mappers_11++;
         }

   mappers_12 += mappers_to_launch;
       for (i = 0; i < mappers_to_launch; i++)
          {
             char * mapper_name = bprintf("%s-Mapper(M1T1_12/10)-%d", host_name, i);
             msg_process_t mapper_12 = MSG_process_create(mapper_name, map_12, NULL, this_host->host);
             xbt_fifo_push(this_host->mappers_12, mapper_12);
             this_host->active_mappers_12++;
           }

//TODO
    // Create shufflers
    long number_of_shufflers = SHUFFLERS_PER_REDUCER * reducers_to_launch;
    for (i = 0; i < number_of_shufflers; i++)
    {
        char * sender_name = bprintf("%s-Sender-%d", host_name, i);
        msg_process_t sender = MSG_process_create(sender_name, shuffleSend, NULL, this_host->host);
        xbt_fifo_push(this_host->shuffle_senders, sender);
    }


    // CREATE REDUCE PROCESSES

    for (i = 0; i < reducers_to_launch; i++)
    {
        char * reducer_name = bprintf("%s-Reducer1/10", host_name);
        msg_process_t reducer = MSG_process_create(reducer_name, reduce, NULL, this_host->host);
        xbt_fifo_push(this_host->reducers, reducer);
        this_host->active_reducers++;
     }

     for (i = 0; i < reducers_to_launch; i++)
     {
            char * reducer_name_2 = bprintf("%s-Reducer2/10", host_name);
            msg_process_t reducer_2 = MSG_process_create(reducer_name_2, reduce_2, NULL, this_host->host);
            xbt_fifo_push(this_host->reducers_2, reducer_2);
            this_host->active_reducers_2++;
     }

     for (i = 0; i < reducers_to_launch; i++)
     {
             char * reducer_name_3 = bprintf("%s-Reducer3/10", host_name);
             msg_process_t reducer_3 = MSG_process_create(reducer_name_3, reduce_3, NULL, this_host->host);
             xbt_fifo_push(this_host->reducers_3, reducer_3);
             this_host->active_reducers_3++;
     }

     for (i = 0; i < reducers_to_launch; i++)
     {
              char * reducer_name_4 = bprintf("%s-Reducer4/10", host_name);
              msg_process_t reducer_4 = MSG_process_create(reducer_name_4, reduce_4, NULL, this_host->host);
              xbt_fifo_push(this_host->reducers_4, reducer_4);
              this_host->active_reducers_4++;
     }

     for (i = 0; i < reducers_to_launch; i++)
            {
               char * reducer_name_5 = bprintf("%s-Reducer5/10", host_name);
               msg_process_t reducer_5 = MSG_process_create(reducer_name_5, reduce_5, NULL, this_host->host);
               xbt_fifo_push(this_host->reducers_5, reducer_5);
               this_host->active_reducers_5++;
            }

     for (i = 0; i < reducers_to_launch; i++)
           {
               char * reducer_name_6 = bprintf("%s-Reducer6/10", host_name);
               msg_process_t reducer_6 = MSG_process_create(reducer_name_6, reduce_6, NULL, this_host->host);
               xbt_fifo_push(this_host->reducers_6, reducer_6);
               this_host->active_reducers_6++;
           }

     for (i = 0; i < reducers_to_launch; i++)
             {
                 char * reducer_name_7 = bprintf("%s-Reducer7/10", host_name);
                 msg_process_t reducer_7 = MSG_process_create(reducer_name_7, reduce_7, NULL, this_host->host);
                 xbt_fifo_push(this_host->reducers_7, reducer_7);
                 this_host->active_reducers_7++;
              }

     for (i = 0; i < reducers_to_launch; i++)
         {
              char * reducer_name_8 = bprintf("%s-Reducer8/10", host_name);
                 msg_process_t reducer_8 = MSG_process_create(reducer_name_8, reduce_8, NULL, this_host->host);
                 xbt_fifo_push(this_host->reducers_8, reducer_8);
                 this_host->active_reducers_8++;
          }

     for (i = 0; i < reducers_to_launch; i++)
            {
                 char * reducer_name_9 = bprintf("%s-Reducer9/10", host_name);
                  msg_process_t reducer_9 = MSG_process_create(reducer_name_9, reduce_9, NULL, this_host->host);
                  xbt_fifo_push(this_host->reducers_9, reducer_9);
                  this_host->active_reducers_9++;
            }

      for (i = 0; i < reducers_to_launch; i++)
           {
                char * reducer_name_10 = bprintf("%s-Reducer10/10", host_name);
                msg_process_t reducer_10 = MSG_process_create(reducer_name_10, reduce_10, NULL, this_host->host);
                xbt_fifo_push(this_host->reducers_10, reducer_10);
                this_host->active_reducers_10++;
           }

      for (i = 0; i < reducers_to_launch; i++)
           {
               char * reducer_name_11 = bprintf("%s-Reducer11/10", host_name);
               msg_process_t reducer_11 = MSG_process_create(reducer_name_11, reduce_11, NULL, this_host->host);
               xbt_fifo_push(this_host->reducers_11, reducer_11);
               this_host->active_reducers_11++;

           }
      for (i = 0; i < reducers_to_launch; i++)
              {
                char * reducer_name_12 = bprintf("%s-Reducer12/10", host_name);
                msg_process_t reducer_12 = MSG_process_create(reducer_name_12, reduce_12, NULL, this_host->host);
                xbt_fifo_push(this_host->reducers_12, reducer_12);
                this_host->active_reducers_12++;
              }

    // The cost of this task should be equal to the overhead of starting these processes
    MSG_task_execute(MSG_task_create("initialization", get_initialization_cost(this_host->host), 0, NULL)); // GENERAL INITIALIZATION OF PROCESSES

    // Notify master that initialization on this host is complete
    MSG_task_send(MSG_task_create("init_exit", 0, 1, NULL), "master"); // NOTIFICATION OF TASKS CREATION

    return 0;
}



