/*
 * Shufflers.c
 *
 *  Created on: Dec 19, 2021
 *      Author: Ebenezer Komla Gavua
 */
#include <stdlib.h>
#include <stdio.h>
#include "HdmsgHost.h"
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#include "xbt/log.h"
#include "xbt/asserts.h"
#include "xbt/xbt_os_time.h"
#include "xbt/sysdep.h"


/* Constants */
int SHUFFLERS_PER_REDUCER = 5;
int SHUFFLE_SLEEP_DURATION = 1;  // In seconds

int SHUFFLE_WAIT_DURATION =15;
int shuffle_started;
int shuffleSend(int argc, char * argv[]);
int shuffleReceive(int argc, char * argv[]);
double shufflefinish_Time;

/** Shuffle Send Process */
int shuffleSend(int argc, char * argv[])	/*The shuffle method declared above is define  here with all its attributes.*/
{
    msg_task_t task = NULL;	    /* The msg_task_t responsible for monitoring information transfer is set to NULL.*/


    const char * process_name = MSG_process_get_name(MSG_process_self()); // CREATING AS SHUFFLE SEND PROCESS

    msg_host_t msg_host = MSG_process_get_host(MSG_process_self()); // CONNECTING THE PROCESS TO A HOST
    struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

  /*Forcing the shuffle send process to wait until active mapper_2 are done executing*/
    while (1){
        	if(this_host->active_mappers> 0)
        		MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_2> 0  )
        		MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_3> 0  )
        	    MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_4> 0  )
        	    MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_5> 0  )
        		MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_6> 0  )
        	 MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_7> 0  )
        	   MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_8> 0  )
        	   MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_9> 0  )
        	   MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_0> 0  )
        		MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_11> 0  )
        	   MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	if(this_host->active_mappers_12> 0  )
        	   MSG_process_sleep(SHUFFLE_WAIT_DURATION);
        	  else
        		break;
        }
/* The wait ends here*/

    while (1)
    {
        task = xbt_fifo_shift(this_host->shuffle_tasks);
            if (task != NULL)
        {
            // If this is the first shuffle task, notify the master so the event is logged to the console
            if (!shuffle_started)
            {
                shuffle_started = 1;
                MSG_task_dsend(MSG_task_create("shuffle_start", 0, 1, NULL), "master", NULL);
            }

            // Create a shuffle receiver on the recipient host
            msg_host_t recipient_host = MSG_task_get_data(task);
           char * receiver_name = bprintf("%s->%s-Receiver", process_name, MSG_host_get_name(recipient_host));

          /*  begin SHUFFLESEND*/
            MSG_process_create(receiver_name, shuffleReceive, NULL, recipient_host);

            double shuffleStart_Time = MSG_get_clock();
            /* Send the task to the shuffle receiver*/
         // XBT_INFO("%s is starting a shuffle task", MSG_process_get_name(MSG_process_self()));


            MSG_task_send(task, receiver_name);
           //     XBT_INFO("%s has completed a shuffle task", MSG_process_get_name(MSG_process_self()));

            /*END SHUFFLESEND*/

            shufflefinish_Time += MSG_get_clock() -shuffleStart_Time;

        }
        else
        {
            if (this_host->active_mappers > 0)
            {
                // If there are still active mappers, sleep then check for more work
                MSG_process_sleep(SHUFFLE_SLEEP_DURATION); // While Active mappers are working, Shuffle send waits
            }
            else
            {
                // Else no mappers -> no further tasks, exit
                break;
            }
        }
    }

    // END SHUFFLESEND

    /* Notify master that I'm done working*/
    msg_comm_t comm = MSG_task_isend(MSG_task_create("shuffle_exit", 0, 1, NULL), "master");
    MSG_comm_wait(comm, -1);
    MSG_comm_destroy(comm);

    return 0;
}


/** Shuffle Receive Process */
int shuffleReceive(int argc, char * argv[])
{
    int res;
    msg_task_t task = NULL;


    /* BEGIN SHUFFLE RECEIVE*/
   res = MSG_task_receive(&(task), MSG_process_get_name(MSG_process_self())); // RECEIVING TASK FROM THE SHUFFLESEND PROCESS
      xbt_assert(res == MSG_OK, "MSG_task_get failed: Shuffle Receive");
    MSG_task_destroy(task);

	/*END SHUFFLE RECEIVE*/
    return 0;
}


/** Shuffle Receive Process */




