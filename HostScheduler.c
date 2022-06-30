/*
 * HostScheduler.c
 *
 *  Created on: Feb 7, 2022
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

 double Execution_Times2;
 double H_1Exec_Times;


//TODO:  Schedule 20 nodes, 8 cores for map tasks !

void Schedulehosts()

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
		{
			MSG_process_sleep(0.01);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(0.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(8.35);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(8.5);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(8.65);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(8.75);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(8.9);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(9.0);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(9.15);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(9.3);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(9.4);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(9.5);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(9.7);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(18.0);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(18.1);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(18.2);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(18.3);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(18.4);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(27.5);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}


void Schedulehosts_10()// Both 10 secs and 20 seconds use this scheduler!

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
		{
			MSG_process_sleep(0.01);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(3);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(6);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(9);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(12);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(15);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(18);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(21);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(24);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(27);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(30);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(33);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(36);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(39);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(42);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(45);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(48);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(51);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(54);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(57);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}





//TODO:  Schedule 20 nodes, 16 cores for map tasks !

void Schedulehosts_20_16()

{


	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
		{
			MSG_process_sleep(0.01);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(0.3);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(8.45);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(8.6);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(8.75);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(8.95);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(9.1);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(9.3);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(9.45);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(9.6);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(9.7);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(9.9);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(10.2);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(18.4);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(18.6);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(18.9);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(19.1);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(19.2);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(29.3);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}




//TODO:  Schedule 25 nodes, 16 cores for map tasks !

void Schedulehosts_25_16()
{


	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
		struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


   if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))//H25
	{
		MSG_process_sleep(0.01);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))//H23
	{
		MSG_process_sleep(0.4);
	}
	else if((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))//H22
	{
		MSG_process_sleep(8.6);
	}
	else if((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))//H21
	{
		MSG_process_sleep(8.8);
	}

	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
	{
		MSG_process_sleep(9.0);
	 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(9.2);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(9.3);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(16.65);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(16.8);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(16.9);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(17.1);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(17.3);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(17.5);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(17.7);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(18.0);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(18.2);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(18.4);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(18.5);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(26.8);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(27.0);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(27.3);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(27.5);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(27.6);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(37.7);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}



//TODO:  Schedule 40 nodes, 8 cores for map tasks !

void Schedulehosts_40()

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
		struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


   if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))//H25
	{
		MSG_process_sleep(0.01);
	}
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.2);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.3);
	}
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.5);
	}
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(6.7);
	}
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(6.9);
	}
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(7.1);
	}
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(7.3);
	}
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(7.5);
	}
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(7.9);
	}
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(8.1);
	}
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(8.2);
	}
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(8.5);
	}
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(8.7);
	}
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(8.9);
	}
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(9.1);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(9.3);
	}
	else if((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))//H23
	{
		MSG_process_sleep(9.5);
	}
	else if((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))//H22
	{
		MSG_process_sleep(17.7);
	}
	else if((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))//H21
	{
		MSG_process_sleep(17.9);
	}

	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
	{
		MSG_process_sleep(18.1);
	 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(18.3);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(18.5);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(27.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(28.9);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(29.1);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(29.3);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(29.5);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(29.7);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(29.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(30.1);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(30.3);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(30.5);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(30.7);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(39.2);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(39.4);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(39.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(39.8);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(41.0);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(50.9);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}

// TODO Reschedules tasks from one host to another for the 40_8 setup map phase!

void reschedule_function_Map_40(int reschedule)
{

	reschedule = MSG_process_self_PPID();

	 switch (reschedule)
	 {
	     case 81:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host19"));
	    	break;
	     case 178:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host24"));
	     	  break;
	     case 785:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host4"));
	     	  break;
	     case 1103:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host8"));
	     	  break;
	     case 835:
	     	  MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host3"));
	     	  break;
	     case 647:
	     	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host39"));
	     	 break;


	 }
	 return;
}

// TODO Reschedules tasks from one host to another for the 20_8 setup reduce phase!
void reschedule_function_reduce_20(int reschedule)
{

	reschedule = MSG_process_self_PPID();

	 switch (reschedule)
	 {
	     case 42:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host17"));
	    	break;
	     case 115:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host4"));
	     	  break;
	     case 135:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host7"));
	     	  break;
	     case 155:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host8"));
	     	  break;
	 }
	 return;
}







//TODO:  Schedule 50 nodes, 8 cores for map tasks !

void Schedulehosts_50()

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
		struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


   if ((strncmp("host50", MSG_process_get_name(MSG_process_self()), 6)== 0))//H25
	{
		MSG_process_sleep(0.01);
	}
   else if ((strncmp("host49", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(0.2);
   	 }
   else if ((strncmp("host48", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(0.4);
   	 }
   else if ((strncmp("host47", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(0.6);
   	 }
   else if ((strncmp("host46", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(0.8);
   	 }
   else if ((strncmp("host45", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(1.0);
   	 }
   else if ((strncmp("host44", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(1.2);
   	 }
   else if ((strncmp("host43", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(1.4);
   	 }
   else if ((strncmp("host42", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(1.6);
   	 }
   else if ((strncmp("host41", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
   	{
   		MSG_process_sleep(1.8);
   	 }
   else if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24 check here
   	{
   		MSG_process_sleep(19.0);
   	 }
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.2);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.4);
	}
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.6);
	}
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(27.7);
	}
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(27.9);
	}
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(28.1);
	}
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(28.3);
	}
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(28.5);
	}
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(28.9);
	}
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(29.1);
	}
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(29.2);
	}
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(29.5);
	}
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(29.7);
	}
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(29.9);
	}
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(30.1);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(30.3);
	}
	else if((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))//H23
	{
		MSG_process_sleep(30.5);
	}
	else if((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))//H22
	{
		MSG_process_sleep(38.7);
	}
	else if((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))//H21
	{
		MSG_process_sleep(38.9);
	}

	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
	{
		MSG_process_sleep(39.1);
	 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(39.3);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(39.5);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(47.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(47.9);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(48.1);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(48.3);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(48.5);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(48.7);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(48.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(49.1);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(49.3);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(49.5);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(49.7);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(57.2);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(57.4);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(57.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(57.8);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(58.0);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(66.9);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}




//TODO:  Schedule 100 nodes, 8 cores for map tasks !
void Schedulehosts_100()

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
		struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


   if ((strncmp("host100", MSG_process_get_name(MSG_process_self()), 7)== 0))//H25
	{
		MSG_process_sleep(0.01);
	}
	else if ((strncmp("host99", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.2);
	 }
	else if ((strncmp("host98", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.4);
	 }
	else if ((strncmp("host97", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.6);
	 }
	else if ((strncmp("host96", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(0.8);
	 }
	else if ((strncmp("host95", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(1.0);
	 }
	else if ((strncmp("host94", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(1.2);
	 }
	else if ((strncmp("host93", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(1.4);
	 }
	else if ((strncmp("host92", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(1.6);
	 }
	else if ((strncmp("host91", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(1.8);
	 }
	else if ((strncmp("host90", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(2.0);
	 }
	else if ((strncmp("host89", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(2.2);
	 }
	else if ((strncmp("host88", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(2.4);
	 }
	else if ((strncmp("host87", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(2.6);
	 }
	else if ((strncmp("host86", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(2.8);
	 }
	else if ((strncmp("host85", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(3.0);
	 }
	else if ((strncmp("host84", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(3.2);
	 }
	else if ((strncmp("host83", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(3.4);
	 }
	else if ((strncmp("host82", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(3.6);
	 }
	else if ((strncmp("host81", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(3.8);
	 }
	else if ((strncmp("host80", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(4.0);
	 }
	else if ((strncmp("host79", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(4.2);
	 }
	else if ((strncmp("host78", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(4.4);
	 }
	else if ((strncmp("host77", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(4.6);
	 }
	else if ((strncmp("host76", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(12.8);
	 }
	else if ((strncmp("host75", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(13.0);
	 }
	else if ((strncmp("host74", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(13.2);
	 }
	else if ((strncmp("host73", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(13.4);
	 }
	else if ((strncmp("host72", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(13.6);
	 }
	else if ((strncmp("host71", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(13.8);
	 }
	else if ((strncmp("host70", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(14.0);
	 }
	else if ((strncmp("host69", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(14.2);
	 }
	else if ((strncmp("host68", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(14.4);
	 }
	else if ((strncmp("host67", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(14.6);
	 }
	else if ((strncmp("host66", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(14.8);
	 }
	else if ((strncmp("host65", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(15.0);
	 }
	else if ((strncmp("host64", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(15.2);
	 }
	else if ((strncmp("host63", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(15.4);
	 }
	else if ((strncmp("host62", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(15.6);
	 }
	else if ((strncmp("host61", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(15.8);
	 }
	else if ((strncmp("host60", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(16.0);
	 }
	else if ((strncmp("host59", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(16.2);
	 }
	else if ((strncmp("host58", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(16.4);
	 }
	else if ((strncmp("host57", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(16.6);
	 }
	else if ((strncmp("host56", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(16.8);
	 }
	else if ((strncmp("host55", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(17.0);
	 }
	else if ((strncmp("host54", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(17.2);
	 }
	else if ((strncmp("host53", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(17.4);
	 }
	else if ((strncmp("host52", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(17.6);
	 }
	else if ((strncmp("host51", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(17.8);
	 }
  	else if ((strncmp("host50", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(18.0);
	 }
	else if ((strncmp("host49", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(18.2);
	 }
	else if ((strncmp("host48", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(18.4);
	 }
	else if ((strncmp("host47", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(18.6);
	 }
	else if ((strncmp("host46", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(18.8);
	 }
	else if ((strncmp("host45", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.0);
	 }
	else if ((strncmp("host44", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.2);
	 }
	else if ((strncmp("host43", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.3);
	 }
	else if ((strncmp("host42", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.5);
	 }
	else if ((strncmp("host41", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(19.7);
	 }
	else if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(32.9);
	 }
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(33.1);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(34.3);
	}
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(35.5);
	}
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(43.7);
	}
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(43.9);
	}
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(44.1);
	}
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(44.3);
	}
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(44.5);
	}
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(44.7);
	}
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(44.9);
	}
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(45.1);
	}
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(45.3);
	}
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(45.5);
	}
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(45.7);
	}
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(45.9);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))//H24
	{
		MSG_process_sleep(46.1);
	}
	else if((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))//H23
	{
		MSG_process_sleep(46.3);
	}
	else if((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))//H22
	{
		MSG_process_sleep(55.5);
	}
	else if((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))//H21
	{
		MSG_process_sleep(55.7);
	}
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//H20
	{
		MSG_process_sleep(55.9);
	 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//H19
	{
		MSG_process_sleep(56.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//H18
	{
		MSG_process_sleep(56.3);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//H17
	{
		MSG_process_sleep(65.5);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//H16
	{
		MSG_process_sleep(65.7);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//H15
	{
		MSG_process_sleep(65.9);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//H14
	{
		MSG_process_sleep(66.1);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//H13
	{
		MSG_process_sleep(66.3);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//H12
	{
		MSG_process_sleep(66.5);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//H11
	{
		MSG_process_sleep(66.7);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//H10
	{
		MSG_process_sleep(66.9);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//H9
	{
		MSG_process_sleep(67.1);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//H8
	{
		MSG_process_sleep(67.3);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//H7
	{
		MSG_process_sleep(67.5);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H6
	{
		MSG_process_sleep(76.7);//9.8
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H5
	{
		MSG_process_sleep(76.9);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//H4
	{
		MSG_process_sleep(77.1);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//H3
	{
		MSG_process_sleep(77.3);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//H2
	{
		MSG_process_sleep(77.5);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0)) //H1
	{
		MSG_process_sleep(86.9);//4.9 //  2 seconds, increase by 3 (4.9); 5 seconds increase by 6(6.9)
	}
}


//TODO:  Schedule 20 nodes, 8 cores for reduce tasks !

void ScheduleRedhosts_1()
{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
		{
			MSG_process_sleep(0.019);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.1);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.2);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.3);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.4);
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.5);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.7);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.8);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.9);
	}
}

//TODO:  Schedule 20 nodes, 8 cores for reduce tasks !
void ScheduleRedhosts_2()
{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
		{
			MSG_process_sleep(0.03);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.5);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.6);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.7);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.8);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.0);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.1);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.2);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.3);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.4);
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.5);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.7);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.8);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(5.9);
	}


}

void ScheduleRedhosts20_5()
{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
		{
			MSG_process_sleep(0.0);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.1);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.2);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.3);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.4);
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.5);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.7);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.8);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.9);
	}
}

// TODO
void ScheduleRedhosts20_6()
{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
		{
			MSG_process_sleep(0.0);
		 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
	 }
	else if((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	}
	else if((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	}
	else if((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
	}
	else if((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
	}
	else if((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	}
	else if((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
	}
	else if((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	}
	else if((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.1);
	}
	else if((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.2);
	 }
	else if((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.3);
	}
	else if((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.4);
	}
	else if((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.5);
	}
	else if((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.6);
	 }
	else if((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.7);
	}
	else if((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.8);
	}
	else if((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(1.9);
	}
}


//TODO:  Schedule 40 nodes, 8 cores for reduce tasks !
void ScheduleRedhosts_40()
{
	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.05);
	}
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
    }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }

	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	 }
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
    }
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
	 }
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
    }
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	 }
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
	 }
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	 }
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))
	 {
		MSG_process_sleep(1.1);
	 }
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.2);
	}
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.3);
	}
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.4);
	}
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.5);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.6);
	}
	else if ((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.7);
	}
	else if ((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.8);
	}
	else if ((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.9);
	}
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.0);
	}
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.1);
	}
	else if ((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
			MSG_process_sleep(2.2);
	}
	else if ((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.3);
	}
	else if ((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.4);
	}
	else if ((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.5);
	}
	else if ((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.6);
	}
	else if ((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.7);
	}
	else if ((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.8);
	}
	else if ((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.9);
	}
	else if ((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.0);
	}
	else if ((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.1);
	}
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.2);
	}
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.3);
	}
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.4);
	}
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.5);
	}
	else if ((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.6);
	}
	else if ((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.7);
	}
	else if ((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.8);
	}
	else if ((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.9);
	}

}

//TODO:  Schedule 40 nodes, 8 cores for reduce tasks !
void ScheduleRedhosts_40_2()
{
	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.05);
	}
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
    }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }

	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
	 }
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
    }
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
	 }
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
    }
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	 }
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
	 }
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	 }
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))
	 {
		MSG_process_sleep(1.1);
	 }
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.2);
	}
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.3);
	}
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.4);
	}
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.5);
	}
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.6);
	}
	else if ((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.7);
	}
	else if ((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.8);
	}
	else if ((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.9);
	}
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.0);
	}
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.1);
	}
	else if ((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
			MSG_process_sleep(2.2);
	}
	else if ((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.3);
	}
	else if ((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.4);
	}
	else if ((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.5);
	}
	else if ((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.6);
	}
	else if ((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.7);
	}
	else if ((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.8);
	}
	else if ((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.9);
	}
	else if ((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.0);
	}
	else if ((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.1);
	}
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.2);
	}
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(3.3);
	}
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.4);
	}
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.5);
	}
	else if ((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.6);
	}
	else if ((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.7);
	}
	else if ((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.8);
	}
	else if ((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(8.9);
	}

}



//TODO
void ScheduleRedhosts_100()
{
	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	if ((strncmp("host100", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(0.01);
	}
	else if ((strncmp("host99", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
    }
	else if ((strncmp("host98", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if ((strncmp("host97", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
    }
	else if ((strncmp("host96", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	 }
	else if ((strncmp("host95", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
    }
	else if ((strncmp("host94", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if ((strncmp("host93", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
    }
	else if ((strncmp("host92", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	 }
	else if ((strncmp("host91", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
    }
	else if ((strncmp("host90", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.0);
	 }
	else if ((strncmp("host89", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.1);
    }
	else if ((strncmp("host88", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.2);
	 }
	else if ((strncmp("host87", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.3);
	 }
	else if ((strncmp("host86", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.4);
    }
	else if ((strncmp("host85", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.5);
	 }
	else if ((strncmp("host84", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.6);
    }
	else if ((strncmp("host83", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.7);
	 }
	else if ((strncmp("host82", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.8);
    }
	else if ((strncmp("host81", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.9);
	 }
	else if ((strncmp("host80", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.0);
    }
	else if ((strncmp("host79", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.1);
	 }
	else if ((strncmp("host78", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.2);
	 }
	else if ((strncmp("host77", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.3);
    }
	else if ((strncmp("host76", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.4);
	 }
	else if ((strncmp("host75", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.5);
	 }
	else if ((strncmp("host74", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.6);
    }
	else if ((strncmp("host73", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.7);
	 }
	else if ((strncmp("host72", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.8);
    }
	else if ((strncmp("host71", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.9);
	 }
	else if ((strncmp("host70", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.0);
    }
	else if ((strncmp("host69", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.1);
	 }
	else if ((strncmp("host68", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.2);
    }
	else if ((strncmp("host67", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.3);
	 }
	else if ((strncmp("host66", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.4);
	 }
	else if ((strncmp("host65", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.5);
    }
	else if ((strncmp("host64", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.6);
	 }
	else if ((strncmp("host63", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.7);
	 }
	else if ((strncmp("host62", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.8);
    }
	else if ((strncmp("host61", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.9);
	 }
	else if ((strncmp("host60", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.0);
    }
	else if ((strncmp("host59", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.1);
	 }
	else if ((strncmp("host58", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.2);
    }
	else if ((strncmp("host57", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.3);
	 }
	else if ((strncmp("host56", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.4);
    }
	else if ((strncmp("host55", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.5);
	 }
	else if ((strncmp("host54", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.6);
	 }
	else if ((strncmp("host53", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.7);
    }
	else if ((strncmp("host52", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.8);
	 }
	else if ((strncmp("host51", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.9);
	 }
	else if ((strncmp("host50", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.0);
    }
	else if ((strncmp("host49", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.1);
	 }
	else if ((strncmp("host48", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.2);
    }
	else if ((strncmp("host47", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.3);
	 }
	else if ((strncmp("host46", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.4);
    }
	else if ((strncmp("host45", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.5);
	 }
	else if ((strncmp("host44", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.6);
    }
	else if ((strncmp("host43", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.7);
	 }
	else if ((strncmp("host42", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.8);
    }
	else if ((strncmp("host41", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.9);
	 }
	else if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.0);
    }
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.1);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.2);
    }
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.3);
	 }
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.4);
	 }
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.5);
    }
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.6);
	 }
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.7);
	 }
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.8);
    }
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.9);
	 }
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.0);
    }
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.1);
	 }
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.2);
    }
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.3);
	 }
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.4);
    }
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.5);
	 }
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.6);
    }
	else if ((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.7);
	 }
	else if ((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.8);
    }
	else if ((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.9);
	 }
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.0);
    }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.1);
	 }
	else if ((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.2);
    }
	else if ((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.3);
	 }
	else if ((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.4);
    }
	else if ((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.5);
	 }
	else if ((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.6);
    }
	else if ((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.7);
	 }
	else if ((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.8);
    }
	else if ((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.9);
	 }
	else if ((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(9.0);
	 }
	else if ((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.1);
    }
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.2);
	 }
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.3);
	 }
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.4);
    }
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.5);
	 }
	else if ((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.6);
    }
	else if ((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.7);
	 }
	else if ((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.8);
	 }
	else if ((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.9);
}
}


void ScheduleMaphosts_200()
{
	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));

	 if ((strncmp("host200", MSG_process_get_name(MSG_process_self()), 7)== 0)) //0.1
		{
				MSG_process_sleep(0.01);
		}
	 else if ((strncmp("host199", MSG_process_get_name(MSG_process_self()), 7)== 0)) //0.1
	{
			MSG_process_sleep(0.1);
	}
	else if ((strncmp("host198", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.2
	{
			MSG_process_sleep(0.2);
	 }
	else if ((strncmp("host197", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.3
	{
			MSG_process_sleep(0.3);
	}
	else if ((strncmp("host196", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.4
	{
			MSG_process_sleep(0.4);
	}
	else if ((strncmp("host195", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.5
	{
			MSG_process_sleep(0.5);
	}
	else if ((strncmp("host194", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.6
	{
			MSG_process_sleep(0.6);
	}
	else if ((strncmp("host193", MSG_process_get_name(MSG_process_self()), 7)== 0))//0.7
	{
			MSG_process_sleep(0.7);
	}
	else if ((strncmp("host192", MSG_process_get_name(MSG_process_self()), 7)== 0))////0.8
	{
			MSG_process_sleep(0.8);
	}
	else if ((strncmp("host191", MSG_process_get_name(MSG_process_self()), 7)== 0)) //0.9
	{
			MSG_process_sleep(0.9);
	}
	else if ((strncmp("host190", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.0
	{
			MSG_process_sleep(1.0);
	}
	else if ((strncmp("host189", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.1
	{
			MSG_process_sleep(1.1);
	}
	else if ((strncmp("host188", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.2
	{
			MSG_process_sleep(1.2);
	}
	else if ((strncmp("host187", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.3
	{
			MSG_process_sleep(1.3);
	 }
	else if ((strncmp("host186", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.4
	{
			MSG_process_sleep(1.4);
	}
	else if ((strncmp("host185", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.5
	{
			MSG_process_sleep(1.5);
	}
	else if ((strncmp("host184", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.6
	{
			MSG_process_sleep(1.6);
	}
	else if ((strncmp("host183", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.7
	{
			MSG_process_sleep(1.7);
	}
	else if ((strncmp("host182", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.8
	{
			MSG_process_sleep(1.8);
	}
	else if ((strncmp("host181", MSG_process_get_name(MSG_process_self()), 7)== 0))//1.9
	{
			MSG_process_sleep(1.9);
	}
	else if ((strncmp("host180", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.0
	{
			MSG_process_sleep(2.0);
	}
	else if ((strncmp("host179", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.1
	{
			MSG_process_sleep(2.1);
	}
	else if ((strncmp("host178", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.2
	{
			MSG_process_sleep(2.2);
	}
	else if ((strncmp("host177", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.3
	{
			MSG_process_sleep(2.3);
	}
	else if ((strncmp("host176", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.4
	{
			MSG_process_sleep(2.4);
	}
	else if ((strncmp("host175", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.5
	{
			MSG_process_sleep(2.5);
	}
	else if ((strncmp("host174", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.6
	{
			MSG_process_sleep(2.6);
	}
	else if ((strncmp("host173", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.7
	{
			MSG_process_sleep(2.7);
	}
	else if ((strncmp("host172", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.8
	{
			MSG_process_sleep(2.8);
	}
	else if ((strncmp("host171", MSG_process_get_name(MSG_process_self()), 7)== 0))//2.9
	{
			MSG_process_sleep(2.9);
	 }
	else if ((strncmp("host170", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.0
	{
			MSG_process_sleep(3.0);
	}
	else if ((strncmp("host169", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.1
	{
			MSG_process_sleep(3.1);
	 }
	else if ((strncmp("host168", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.2
	{
			MSG_process_sleep(3.2);
	}
	else if ((strncmp("host167", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.3
	{
			MSG_process_sleep(3.3);
	}
	else if ((strncmp("host166", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.4
	{
			MSG_process_sleep(3.4);
	}
	else if ((strncmp("host165", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.5
	{
			MSG_process_sleep(3.5);
	}
	else if ((strncmp("host164", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.6
	{
			MSG_process_sleep(3.6);
	}
	else if ((strncmp("host163", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.7
	{
			MSG_process_sleep(3.7);
	 }
	else if ((strncmp("host162", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.8
	{
			MSG_process_sleep(3.8);
	}
	else if ((strncmp("host161", MSG_process_get_name(MSG_process_self()), 7)== 0))//3.9
	{
			MSG_process_sleep(3.9);
	 }
	else if ((strncmp("host160", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.0
	{
			MSG_process_sleep(4.0);
	}
	else if ((strncmp("host159", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.1
	{
			MSG_process_sleep(4.1);
	 }
	else if ((strncmp("host158", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.2
	{
			MSG_process_sleep(4.2);
	}
	else if ((strncmp("host157", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.3
	{
			MSG_process_sleep(4.3);
	 }
	else if ((strncmp("host156", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.4
	{
			MSG_process_sleep(4.4);
	}
	else if ((strncmp("host155", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.5
	{
			MSG_process_sleep(4.5);
	 }
	else if ((strncmp("host154", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.6
	{
			MSG_process_sleep(4.6);
	}
	else if ((strncmp("host153", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.7
	{
			MSG_process_sleep(4.7);
	}
	else if ((strncmp("host152", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.8
	{
			MSG_process_sleep(4.8);
	}
	else if ((strncmp("host151", MSG_process_get_name(MSG_process_self()), 7)== 0))//4.9
	{
			MSG_process_sleep(4.9);
	}
	else if ((strncmp("host150", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.0
	{
			MSG_process_sleep(5.0);
	}
	else if ((strncmp("host149", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.1
	{
			MSG_process_sleep(5.1);
	 }
	else if ((strncmp("host148", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.2
	{
			MSG_process_sleep(5.2);
	}
	else if ((strncmp("host147", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.3
	{
			MSG_process_sleep(5.3);
	 }
	else if ((strncmp("host146", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.4
	{
			MSG_process_sleep(5.4);
	}
	else if ((strncmp("host145", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.5
	{
			MSG_process_sleep(5.5);
	 }
	else if ((strncmp("host144", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.6
	{
			MSG_process_sleep(5.6);
	}
	else if ((strncmp("host143", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.7
	{
			MSG_process_sleep(5.7);
	 }
	else if ((strncmp("host142", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.8
	{
		  MSG_process_sleep(5.8);
	}
	else if ((strncmp("host141", MSG_process_get_name(MSG_process_self()), 7)== 0))//5.9
	{
		   MSG_process_sleep(5.9);
	 }
	else if ((strncmp("host140", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.0
	{
			MSG_process_sleep(6.0);
	}
	else if ((strncmp("host139", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.1
	{
			MSG_process_sleep(6.1);
	}
	else if ((strncmp("host138", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.2
	{
			MSG_process_sleep(6.2);
	}
	else if ((strncmp("host137", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.3
	{
			MSG_process_sleep(6.3);
	}
	else if ((strncmp("host136", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.4
	{
			MSG_process_sleep(6.4);
	 }
	else if ((strncmp("host135", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.5
	{
			MSG_process_sleep(6.5);
	 }
	else if ((strncmp("host134", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.6
	{
			MSG_process_sleep(6.6);
	}
	else if ((strncmp("host133", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.7
	{
			MSG_process_sleep(6.7);
	 }
	else if ((strncmp("host132", MSG_process_get_name(MSG_process_self()),7)== 0))//6.8
	{
			MSG_process_sleep(6.8);
	}
	else if ((strncmp("host131", MSG_process_get_name(MSG_process_self()), 7)== 0))//6.9
	{
			MSG_process_sleep(6.9);
	 }
	else if ((strncmp("host130", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.0
	{
			MSG_process_sleep(7.0);
	}
	else if ((strncmp("host129", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.1
	{
			MSG_process_sleep(7.1);
	 }
	else if ((strncmp("host128", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.2
	{
			MSG_process_sleep(7.2);
	}
	else if ((strncmp("host127", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.3
	{
			MSG_process_sleep(7.3);
	 }
	else if ((strncmp("host126", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.4
	{
			MSG_process_sleep(7.4);
	}
	else if ((strncmp("host125", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.5
	{
			MSG_process_sleep(7.5);
	 }
	else if ((strncmp("host124", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.6
	{
			 MSG_process_sleep(7.6);
	}
	else if ((strncmp("host123", MSG_process_get_name(MSG_process_self()),7)== 0))//7.7
	{
		     MSG_process_sleep(7.7);
	 }
	else if ((strncmp("host122", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.8
	{
			MSG_process_sleep(7.8);
	 }
	else if ((strncmp("host121", MSG_process_get_name(MSG_process_self()), 7)== 0))//7.9
	{
			MSG_process_sleep(7.9);
	 }
	else if ((strncmp("host120", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.0
	{
			MSG_process_sleep(8.0);
	}
	else if ((strncmp("host119", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.1
	{
			MSG_process_sleep(8.1);
	 }
	else if ((strncmp("host118", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.2
	{
			MSG_process_sleep(8.2);
	}
	else if ((strncmp("host117", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.4
	{
			MSG_process_sleep(8.4);
	 }
	else if ((strncmp("host116", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.5
	{
			MSG_process_sleep(8.5);
	}
	else if ((strncmp("host115", MSG_process_get_name(MSG_process_self()),7)== 0))//8.6
	{
			MSG_process_sleep(8.6);
	 }
	else if ((strncmp("host114", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.7
	{
			MSG_process_sleep(8.7);
	}
	else if ((strncmp("host113", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.8
	{
			MSG_process_sleep(8.8);
	 }
	else if ((strncmp("host112", MSG_process_get_name(MSG_process_self()), 7)== 0))//8.9
	{
			MSG_process_sleep(8.9);
	}
	else if ((strncmp("host111", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.0
	{
			MSG_process_sleep(9.0);
	}
	else if ((strncmp("host110", MSG_process_get_name(MSG_process_self()),7)== 0))//9.1
	{
			MSG_process_sleep(9.1);
	}
	else if ((strncmp("host109", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.2
	{
			MSG_process_sleep(9.2);
	}
	else if ((strncmp("host108", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.3
	{
			MSG_process_sleep(9.3);
	}
	else if ((strncmp("host107", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.4
	{
			MSG_process_sleep(9.4);
	 }
	else if ((strncmp("host106", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.5
	{
			MSG_process_sleep(9.5);
	}
	else if ((strncmp("host105", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.6
	{
			MSG_process_sleep(9.6);
	 }
	else if ((strncmp("host104", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.7
	{
			MSG_process_sleep(9.7);
	}
	else if ((strncmp("host103", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.8
	{
		  MSG_process_sleep(9.8);
	 }
	else if ((strncmp("host102", MSG_process_get_name(MSG_process_self()), 7)== 0))//9.9
	{
			MSG_process_sleep(9.9);
	 }
	else if ((strncmp("host101", MSG_process_get_name(MSG_process_self()), 7)== 0))//10.0
	{
		MSG_process_sleep(10.0);
	}
	else if ((strncmp("host100", MSG_process_get_name(MSG_process_self()), 7)== 0))//10.1
	{
			MSG_process_sleep(10.1);
	}
	else if ((strncmp("host99", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.2
	{
			MSG_process_sleep(10.2);
	}
	else if ((strncmp("host98", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.3
	{
		MSG_process_sleep(10.3);
	}
	else if ((strncmp("host97", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.4
	{
		MSG_process_sleep(10.4);
    }
	else if ((strncmp("host96", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.5
	{
		MSG_process_sleep(10.5);
	 }
	else if ((strncmp("host95", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.6
	{
		MSG_process_sleep(10.6);
    }
	else if ((strncmp("host94", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.7
	{
		MSG_process_sleep(10.7);
	 }
	else if ((strncmp("host93", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.8
	{
		MSG_process_sleep(10.8);
    }
	else if ((strncmp("host92", MSG_process_get_name(MSG_process_self()), 6)== 0))//10.9
	{
		MSG_process_sleep(10.9);
	 }
	else if ((strncmp("host91", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.0
	{
		MSG_process_sleep(11.0);
    }
	else if ((strncmp("host90", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.1
	{
		MSG_process_sleep(11.1);
	 }
	else if ((strncmp("host89", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.2
	{
		MSG_process_sleep(11.2);
    }
	else if ((strncmp("host88", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.3
	{
		MSG_process_sleep(11.3);
	 }
	else if ((strncmp("host87", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.4
	{
		MSG_process_sleep(11.4);
    }
	else if ((strncmp("host86", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.5
	{
		MSG_process_sleep(11.5);
	 }
	else if ((strncmp("host85", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.6
	{
		MSG_process_sleep(11.6);
	 }
	else if ((strncmp("host84", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.7
	{
		MSG_process_sleep(11.7);
    }
	else if ((strncmp("host83", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.8
	{
		MSG_process_sleep(11.8);
	 }
	else if ((strncmp("host82", MSG_process_get_name(MSG_process_self()), 6)== 0))//11.9
	{
		MSG_process_sleep(11.9);
    }
	else if ((strncmp("host81", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.0
	{
		MSG_process_sleep(12.0);
	 }
	else if ((strncmp("host80", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.1
	{
		MSG_process_sleep(12.1);
    }
	else if ((strncmp("host79", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.2
	{
		MSG_process_sleep(12.2);
	 }
	else if ((strncmp("host78", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.3
	{
		MSG_process_sleep(12.3);
    }
	else if ((strncmp("host77", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.4
	{
		MSG_process_sleep(12.4);
	 }
	else if ((strncmp("host76", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.5
	{
		MSG_process_sleep(12.5);
	 }
	else if ((strncmp("host75", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.6
	{
		MSG_process_sleep(12.6);
    }
	else if ((strncmp("host74", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.7
	{
		MSG_process_sleep(12.7);
	 }
	else if ((strncmp("host73", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.8
	{
		MSG_process_sleep(12.8);
	 }
	else if ((strncmp("host72", MSG_process_get_name(MSG_process_self()), 6)== 0))//12.9
	{
		MSG_process_sleep(12.9);
    }
	else if ((strncmp("host71", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.0
	{
		MSG_process_sleep(13.0);
	 }
	else if ((strncmp("host70", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.1
	{
		MSG_process_sleep(13.1);
    }
	else if ((strncmp("host69", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.2
	{
		MSG_process_sleep(13.2);
	 }
	else if ((strncmp("host68", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.3
	{
		MSG_process_sleep(13.3);
    }
	else if ((strncmp("host67", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.4
	{
		MSG_process_sleep(13.4);
	 }
	else if ((strncmp("host66", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.5
	{
		MSG_process_sleep(13.5);
    }
	else if ((strncmp("host65", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.6
	{
		MSG_process_sleep(13.6);
	 }
	else if ((strncmp("host64", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.7
	{
		MSG_process_sleep(13.7);
	 }
	else if ((strncmp("host63", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.8
	{
		MSG_process_sleep(13.8);
    }
	else if ((strncmp("host62", MSG_process_get_name(MSG_process_self()), 6)== 0))//13.9
	{
		MSG_process_sleep(13.9);
	 }
	else if ((strncmp("host61", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.0
	{
		MSG_process_sleep(14.0);
	 }
	else if ((strncmp("host60", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.1
	{
		MSG_process_sleep(14.1);
    }
	else if ((strncmp("host59", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.2
	{
		MSG_process_sleep(14.2);
	 }
	else if ((strncmp("host58", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.3
	{
		MSG_process_sleep(14.3);
    }
	else if ((strncmp("host57", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.4
	{
		MSG_process_sleep(14.4);
	 }
	else if ((strncmp("host56", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.5
	{
		MSG_process_sleep(14.5);
    }
	else if ((strncmp("host55", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.6
	{
		MSG_process_sleep(14.6);
	 }
	else if ((strncmp("host54", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.7
	{
		MSG_process_sleep(14.7);
    }
	else if ((strncmp("host53", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.8
	{
		MSG_process_sleep(14.8);
	 }
	else if ((strncmp("host52", MSG_process_get_name(MSG_process_self()), 6)== 0))//14.9
	{
		MSG_process_sleep(14.9);
	 }
	else if ((strncmp("host51", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.0
	{
		MSG_process_sleep(15.0);
    }
	else if ((strncmp("host50", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.1
	{
		MSG_process_sleep(15.1);
	 }
	else if ((strncmp("host49", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.2
	{
		MSG_process_sleep(15.2);
	 }
	else if ((strncmp("host48", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.3
	{
		MSG_process_sleep(15.3);
    }
	else if ((strncmp("host47", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.4
	{
		MSG_process_sleep(15.4);
	 }
	else if ((strncmp("host46", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.5
	{
		MSG_process_sleep(15.5);
    }
	else if ((strncmp("host45", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.6
	{
		MSG_process_sleep(15.6);
	 }
	else if ((strncmp("host44", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.7
	{
		MSG_process_sleep(15.7);
    }
	else if ((strncmp("host43", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.8
	{
		MSG_process_sleep(15.8);
	 }
	else if ((strncmp("host42", MSG_process_get_name(MSG_process_self()), 6)== 0))//15.9
	{
		MSG_process_sleep(15.9);
    }
	else if ((strncmp("host41", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.0
	{
		MSG_process_sleep(16.0);
	 }
	else if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.1
	{
		MSG_process_sleep(16.1);
    }
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.2
	{
		MSG_process_sleep(16.2);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.3
	{
		MSG_process_sleep(16.3);
    }
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.4
	{
		MSG_process_sleep(16.4);
	 }
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.5
	{
		MSG_process_sleep(16.5);
    }
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.6
	{
		MSG_process_sleep(16.6);
	 }
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.7
	{
		MSG_process_sleep(16.7);
	 }
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.8
	{
		MSG_process_sleep(16.8);
    }
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))//16.9
	{
		MSG_process_sleep(16.9);
	 }
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.0
	{
		MSG_process_sleep(17.0);
	 }
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.1
	{
		MSG_process_sleep(17.1);
    }
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.2
	{
		MSG_process_sleep(17.2);
	 }
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.3
	{
		MSG_process_sleep(17.3);
    }
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.4
	{
		MSG_process_sleep(17.4);
	 }
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.5
	{
		MSG_process_sleep(17.5);
    }
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.6
	{
		MSG_process_sleep(17.6);
	 }
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.7
	{
		MSG_process_sleep(17.7);
    }
	else if ((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.8
		{
			MSG_process_sleep(17.8);
		 }
	else if ((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.8
	{
		MSG_process_sleep(17.9);
	 }
	else if ((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))//17.9
	{
		MSG_process_sleep(18.0);
    }
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.0
	{
		MSG_process_sleep(18.1);
	 }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.1
	{
		MSG_process_sleep(18.2);
    }
	else if ((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.2
	{
		MSG_process_sleep(18.3);
	 }
	else if ((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.3
	{
		MSG_process_sleep(18.4);
    }
	else if ((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.4
	{
		MSG_process_sleep(18.5);
	 }
	else if ((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.5
	{
		MSG_process_sleep(18.6);
    }
	else if ((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.6
	{
		MSG_process_sleep(18.7);
	 }
	else if ((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.7
	{
		MSG_process_sleep(18.8);
    }
	else if ((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.8
	{
		MSG_process_sleep(18.9);
	 }
	else if ((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))//18.9
	{
		MSG_process_sleep(19.0);
    }
	else if ((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))//19.0
	{
		MSG_process_sleep(19.1);
	 }
	else if ((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.1
	{
		MSG_process_sleep(19.2);
    }
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.2
	{
		MSG_process_sleep(19.3);
	 }
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.3
	{
		MSG_process_sleep(19.4);
	 }
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.4
	{
		MSG_process_sleep(19.5);
    }
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.5
	{
		MSG_process_sleep(19.6);
	 }
	else if ((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.6
	{
		MSG_process_sleep(19.7);
	 }
	else if ((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.7
	{
		MSG_process_sleep(19.8);
    }
	else if ((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.8
	{
		MSG_process_sleep(19.9);
	 }
	else if ((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))//19.9
	{
		MSG_process_sleep(20.0);
    }

}



void ScheduleRedhosts_200()
{
	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));


	if ((strncmp("host200", MSG_process_get_name(MSG_process_self()), 7)== 0))
		{
			MSG_process_sleep(0.01);
		}
	else if ((strncmp("host199", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.2);
	}
	else if ((strncmp("host198", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.3);
	 }
	else if ((strncmp("host197", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.4);
	}
	else if ((strncmp("host196", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.5);
	}
	else if ((strncmp("host195", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.6);
	}
	else if ((strncmp("host194", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.7);
	}
	else if ((strncmp("host193", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.8);
	}
	else if ((strncmp("host192", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(0.9);
	}
	else if ((strncmp("host191", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
			MSG_process_sleep(0.10);
	}
	else if ((strncmp("host190", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.1);
	}
	else if ((strncmp("host189", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.2);
	}
	else if ((strncmp("host188", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.3);
	}
	else if ((strncmp("host187", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.4);
	 }
	else if ((strncmp("host186", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.5);
	}
	else if ((strncmp("host185", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.6);
	}
	else if ((strncmp("host184", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.7);
	}
	else if ((strncmp("host183", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.8);
	}
	else if ((strncmp("host182", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(1.9);
	}
	else if ((strncmp("host181", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.0);
	}
	else if ((strncmp("host180", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.1);
	}
	else if ((strncmp("host179", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.2);
	}
	else if ((strncmp("host178", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.3);
	}
	else if ((strncmp("host177", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.4);
	}
	else if ((strncmp("host176", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.5);
	}
	else if ((strncmp("host175", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.6);
	}
	else if ((strncmp("host174", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.7);
	}
	else if ((strncmp("host173", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.8);
	}
	else if ((strncmp("host172", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(2.9);
	}
	else if ((strncmp("host171", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.0);
	 }
	else if ((strncmp("host170", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.1);
	}
	else if ((strncmp("host169", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.2);
	 }
	else if ((strncmp("host168", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.3);
	}
	else if ((strncmp("host167", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.4);
	}
	else if ((strncmp("host166", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.5);
	}
	else if ((strncmp("host165", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.6);
	}
	else if ((strncmp("host164", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.7);
	}
	else if ((strncmp("host163", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.8);
	 }
	else if ((strncmp("host162", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(3.9);
	}
	else if ((strncmp("host161", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.0);
	 }
	else if ((strncmp("host160", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.1);
	}
	else if ((strncmp("host159", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.2);
	 }
	else if ((strncmp("host158", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.3);
	}
	else if ((strncmp("host157", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.4);
	 }
	else if ((strncmp("host156", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.5);
	}
	else if ((strncmp("host155", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.6);
	 }
	else if ((strncmp("host154", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.7);
	}
	else if ((strncmp("host153", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.8);
	}
	else if ((strncmp("host51", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(4.9);
	}
	else if ((strncmp("host152", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.0);
	}
	else if ((strncmp("host151", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.1);
	}
	else if ((strncmp("host150", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.2);
	 }
	else if ((strncmp("host149", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.3);
	}
	else if ((strncmp("host148", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.4);
	 }
	else if ((strncmp("host147", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.5);
	}
	else if ((strncmp("host146", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.6);
	 }
	else if ((strncmp("host145", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.7);
	}
	else if ((strncmp("host144", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(5.8);
	 }
	else if ((strncmp("host143", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(5.9);
	}
	else if ((strncmp("host142", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(6.0);
	 }
	else if ((strncmp("host141", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.1);
	}
	else if ((strncmp("host140", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.2);
	}
	else if ((strncmp("host139", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.3);
	}
	else if ((strncmp("host138", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.4);
	}
	else if ((strncmp("host137", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.5);
	 }
	else if ((strncmp("host136", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.6);
	 }
	else if ((strncmp("host135", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.7);
	}
	else if ((strncmp("host134", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.8);
	 }
	else if ((strncmp("host133", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(6.9);
	}
	else if ((strncmp("host132", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.0);
	 }
	else if ((strncmp("host131", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.1);
	}
	else if ((strncmp("host130", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.2);
	 }
	else if ((strncmp("host129", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.3);
	}
	else if ((strncmp("host128", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.4);
	 }
	else if ((strncmp("host127", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.5);
	}
	else if ((strncmp("host126", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.6);
	 }
	else if ((strncmp("host125", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.7);
	}
	else if ((strncmp("host124", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(7.8);
	 }
	else if ((strncmp("host123", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(7.9);
	 }
	else if ((strncmp("host122", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.0);
	 }
	else if ((strncmp("host121", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.1);
	}
	else if ((strncmp("host120", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.2);
	 }
	else if ((strncmp("host118", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.3);
	}
	else if ((strncmp("host119", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.4);
	 }
	else if ((strncmp("host118", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.5);
	}
	else if ((strncmp("host117", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.6);
	 }
	else if ((strncmp("host116", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.7);
	}
	else if ((strncmp("host115", MSG_process_get_name(MSG_process_self()),7)== 0))
	{
			MSG_process_sleep(8.8);
	 }
	else if ((strncmp("host114", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(8.9);
	}
	else if ((strncmp("host113", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.0);
	}
	else if ((strncmp("host112", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.1);
	}
	else if ((strncmp("host111", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.2);
	}
	else if ((strncmp("host110", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.3);
	}
	else if ((strncmp("host109", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.4);
	 }
	else if ((strncmp("host108", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.5);
	}
	else if ((strncmp("host107", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.6);
	 }
	else if ((strncmp("host106", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.7);
	}
	else if ((strncmp("host105", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(9.8);
	 }
	else if ((strncmp("host104", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(9.9);
	 }
	else if ((strncmp("host103", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(10.1);
	}
	else if ((strncmp("host102", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(10.2);
	}
	else if ((strncmp("host101", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
			MSG_process_sleep(10.3);
	}

	else if ((strncmp("host100", MSG_process_get_name(MSG_process_self()), 7)== 0))
	{
		MSG_process_sleep(0.01);
	}
	else if ((strncmp("host99", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.1);
    }
	else if ((strncmp("host98", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.2);
	 }
	else if ((strncmp("host97", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.3);
    }
	else if ((strncmp("host96", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.4);
	 }
	else if ((strncmp("host95", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.5);
    }
	else if ((strncmp("host94", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.6);
	 }
	else if ((strncmp("host93", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.7);
    }
	else if ((strncmp("host92", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.8);
	 }
	else if ((strncmp("host91", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.9);
    }
	else if ((strncmp("host90", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(0.10);
	 }
	else if ((strncmp("host89", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.1);
    }
	else if ((strncmp("host88", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.2);
	 }
	else if ((strncmp("host87", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.3);
	 }
	else if ((strncmp("host86", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.4);
    }
	else if ((strncmp("host85", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.5);
	 }
	else if ((strncmp("host84", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.6);
    }
	else if ((strncmp("host83", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.7);
	 }
	else if ((strncmp("host82", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.8);
    }
	else if ((strncmp("host81", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(1.9);
	 }
	else if ((strncmp("host80", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.0);
    }
	else if ((strncmp("host79", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.1);
	 }
	else if ((strncmp("host78", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.2);
	 }
	else if ((strncmp("host77", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.3);
    }
	else if ((strncmp("host76", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.4);
	 }
	else if ((strncmp("host75", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.5);
	 }
	else if ((strncmp("host74", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.6);
    }
	else if ((strncmp("host73", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.7);
	 }
	else if ((strncmp("host72", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.8);
    }
	else if ((strncmp("host71", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(2.9);
	 }
	else if ((strncmp("host70", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.0);
    }
	else if ((strncmp("host69", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.1);
	 }
	else if ((strncmp("host68", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.2);
    }
	else if ((strncmp("host67", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.3);
	 }
	else if ((strncmp("host66", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.4);
	 }
	else if ((strncmp("host65", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.5);
    }
	else if ((strncmp("host64", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.6);
	 }
	else if ((strncmp("host63", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.7);
	 }
	else if ((strncmp("host62", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.8);
    }
	else if ((strncmp("host61", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(3.9);
	 }
	else if ((strncmp("host60", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.0);
    }
	else if ((strncmp("host59", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.1);
	 }
	else if ((strncmp("host58", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.2);
    }
	else if ((strncmp("host57", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.3);
	 }
	else if ((strncmp("host56", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.4);
    }
	else if ((strncmp("host55", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.5);
	 }
	else if ((strncmp("host54", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.6);
	 }
	else if ((strncmp("host53", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.7);
    }
	else if ((strncmp("host52", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.8);
	 }
	else if ((strncmp("host51", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(4.9);
	 }
	else if ((strncmp("host50", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.0);
    }
	else if ((strncmp("host49", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.1);
	 }
	else if ((strncmp("host48", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.2);
    }
	else if ((strncmp("host47", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.3);
	 }
	else if ((strncmp("host46", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.4);
    }
	else if ((strncmp("host45", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.5);
	 }
	else if ((strncmp("host44", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.6);
    }
	else if ((strncmp("host43", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.7);
	 }
	else if ((strncmp("host42", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.8);
    }
	else if ((strncmp("host41", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(5.9);
	 }
	else if ((strncmp("host40", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.0);
    }
	else if ((strncmp("host39", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.1);
	 }
	else if ((strncmp("host38", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.2);
    }
	else if ((strncmp("host37", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.3);
	 }
	else if ((strncmp("host36", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.4);
	 }
	else if ((strncmp("host35", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.5);
    }
	else if ((strncmp("host34", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.6);
	 }
	else if ((strncmp("host33", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.7);
	 }
	else if ((strncmp("host32", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.8);
    }
	else if ((strncmp("host31", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(6.9);
	 }
	else if ((strncmp("host30", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.0);
    }
	else if ((strncmp("host29", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.1);
	 }
	else if ((strncmp("host28", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.2);
    }
	else if ((strncmp("host27", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.3);
	 }
	else if ((strncmp("host26", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.4);
    }
	else if ((strncmp("host25", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.5);
	 }
	else if ((strncmp("host24", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.6);
    }
	else if ((strncmp("host23", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.7);
	 }
	else if ((strncmp("host22", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.8);
    }
	else if ((strncmp("host21", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(7.9);
	 }
	else if ((strncmp("host20", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.0);
    }
	else if ((strncmp("host19", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.1);
	 }
	else if ((strncmp("host18", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.2);
    }
	else if ((strncmp("host17", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.3);
	 }
	else if ((strncmp("host16", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.4);
    }
	else if ((strncmp("host15", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.5);
	 }
	else if ((strncmp("host14", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.6);
    }
	else if ((strncmp("host13", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.7);
	 }
	else if ((strncmp("host12", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.8);
    }
	else if ((strncmp("host11", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(8.9);
	 }
	else if ((strncmp("host10", MSG_process_get_name(MSG_process_self()), 6)== 0))
	{
		MSG_process_sleep(9.0);
	 }
	else if ((strncmp("host9", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.1);
    }
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.2);
	 }
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.3);
	 }
	else if ((strncmp("host8", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.4);
    }
	else if ((strncmp("host7", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.5);
	 }
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.6);
    }
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.7);
	 }
	else if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.8);
    }
	else if ((strncmp("host4", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(9.9);
	 }
	else if ((strncmp("host3", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(10.1);
    }
	else if ((strncmp("host2", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(10.2);
	 }
	else if ((strncmp("host1", MSG_process_get_name(MSG_process_self()), 5)== 0))
	{
		MSG_process_sleep(10.3);
	 }

}
 // TODO Returns the execution time for maptasks 1!
double Map_exec_function(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	     case 2:
	    	 Execution_Time1=Execution_Time2-0.0;
	    	break;
	    case 738:
	    	 Execution_Time1=Execution_Time2-0.2;
	    	 break;
	    case 691:
	    	 Execution_Time1=Execution_Time2-0.3;
	    	 break;
	    case 647:
	    	 Execution_Time1=Execution_Time2-0.5;
	    	 break;
	    case 603:
	    	 Execution_Time1=Execution_Time2-6.7;
	    	 break;
	    case 562:
	    	 Execution_Time1=Execution_Time2-6.9;
	    	 break;
	    case 521:
	   	     Execution_Time1=Execution_Time2-7.1;
	   	     break;
	    case 483:
	   	     Execution_Time1=Execution_Time2-7.3;
	   	     break;
	    case 445:
	   	     Execution_Time1=Execution_Time2-7.5;
	   	     break;
	    case 410:
	   	     Execution_Time1=Execution_Time2-7.9;
	   	     break;
	    case 375:
	   	     Execution_Time1=Execution_Time2-8.1;
	   	     break;
	    case 343:
	   	     Execution_Time1=Execution_Time2-8.2;
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-8.5;
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-8.7;
	   	     break;
	    case 253:
		   	 Execution_Time1=Execution_Time2-8.9;
		   	 break;
	    case 227:
		   	 Execution_Time1=Execution_Time2-9.1;
		   	 break;
	    case 201:
	 		 Execution_Time1=Execution_Time2-9.3;
	 		 break;
	    case 178:
	 		 Execution_Time1=Execution_Time2-9.5;
	 		 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-17.7;
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-17.9;
	 		 break;
	    case 115:
	 		 Execution_Time1=Execution_Time2-18.1;
	 		 break;
	    case 98:
	 		 Execution_Time1=Execution_Time2-18.3;
	 		 break;
	    case 81:
	 		 Execution_Time1=Execution_Time2-18.5;
	 		 break;
	    case 67:
	 		 Execution_Time1=Execution_Time2-27.3;
	 		 break;
	    case 53:
	 		 Execution_Time1=Execution_Time2-28.9;
	 		 break;
	    case 42:
	 		 Execution_Time1=Execution_Time2-29.1;
	 		 break;
	    case 31:
	 		 Execution_Time1=Execution_Time2-29.3;
	 		 break;
	    case 23:
	    	  Execution_Time1=Execution_Time2-29.5;
	    	  break;
	    case 15:
	    	  Execution_Time1=Execution_Time2-29.7;
	    	  break;
	    case 10:
	    	 Execution_Time1=Execution_Time2-29.9;
	    	 break;
	    case 5:
	    	 Execution_Time1=Execution_Time2-30.1;
	    	 break;
	    case 1221:
	    	 Execution_Time1=Execution_Time2-30.3;
	    	 break;
	    case 1162:
	    	 Execution_Time1=Execution_Time2-30.5;
	    	 break;
	    case 1103:
	    	 Execution_Time1=Execution_Time2-30.7;
	    	 break;
	    case 1047:
	    	 Execution_Time1=Execution_Time2-39.2;
	    	 break;
	    case 991:
	    	 Execution_Time1=Execution_Time2-39.4;
	    	 break;
	    case 938:
	    	 Execution_Time1=Execution_Time2-39.6;
	    	  break;
	    case 885:
	    	 Execution_Time1=Execution_Time2-39.8;
	    	 break;
	    case 835:
	    	 Execution_Time1=Execution_Time2-41.0;
	    	 break;
	    case 785:
	    	 Execution_Time1=Execution_Time2-50.9;
	    	break;
	   default:
	    	 Execution_Time1=Execution_Times2;
	    	break;
	  }

	return Execution_Time1;
}


double exec_function_20(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.0001;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-0.1;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-0.2;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-8.35;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-8.5;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-8.65;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-8.75;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-8.9;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-9.0;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-9.15;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-9.3;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-9.4;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-9.5;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-9.7;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-18.0;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-18.1;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-18.2;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-18.3;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-18.4; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-27.5; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}


double exec_Redfunction_20(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.019;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-0.1;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-0.2;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-0.3;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-0.4;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-0.5;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-0.6;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-0.7;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-0.8;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-0.9;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-1.0;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-1.1;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-1.2;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-1.3;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-1.4;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-1.5;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-1.6;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-1.7;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-1.8; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-1.9; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}


double exec_Redfunction_20_2(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.03;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-0.1;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-0.2;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-0.3;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-0.4;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-4.5;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-4.6;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-4.7;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-4.8;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-4.9;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-5.0;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-5.1;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-5.2;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-5.3;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-5.4;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-5.5;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-5.6;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-5.7;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-5.8; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-5.9; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}

// TODO Return the execution times for both 10 and 20 seconds maptasks running times!
double exec_function_20_10_sec(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.0001;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-3;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-6;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-9;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-12;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-15;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-18;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-21;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-24;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-27;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-30;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-33;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-36;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-39;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-42;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-45;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-48;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-51;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-54; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-57; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}

// TODO Return the execution times for 30 seconds maptasks running times!
double exec_function_20_30_sec(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.0001;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-4;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-8;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-12;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-16;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-20;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-24;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-28;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-32;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-36;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-40;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-44;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-48;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-52;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-56;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-60;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-64;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-68;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-72; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-76; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}

double exec_function_20_40_sec(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	    case 98:
	    	 Execution_Time1=Execution_Time2-0.0001;//H19
	    	break;
	    case 81:
	    	 Execution_Time1=Execution_Time2-5;//H19
	    	break;
	    case 67:
	    	 Execution_Time1=Execution_Time2-10;//H18
	    	 break;
	    case 53:
	    	 Execution_Time1=Execution_Time2-15;//H17
	    	 break;
	    case 42:
	    	 Execution_Time1=Execution_Time2-20;//H16
	    	 break;
	    case 31:
	    	 Execution_Time1=Execution_Time2-25;//H15
	    	 break;
	    case 23:
	    	 Execution_Time1=Execution_Time2-30;//H14
	    	 break;
	    case 15:
	   	     Execution_Time1=Execution_Time2-35;//H13
	   	     break;
	    case 10:
	   	     Execution_Time1=Execution_Time2-40;//H12
	   	     break;
	    case 5:
	   	     Execution_Time1=Execution_Time2-45;//H11
	   	     break;
	    case 2:
	   	     Execution_Time1=Execution_Time2-50;//H10
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-55;//H9
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-60;//H8
	   	     break;
	    case 253:
	   	     Execution_Time1=Execution_Time2-65;//H7
	   	     break;
	    case 227:
	   	     Execution_Time1=Execution_Time2-70;//H6
	   	     break;
	    case 201:
		   	 Execution_Time1=Execution_Time2-75;//H5
		   	 break;
	    case 178:
		   	 Execution_Time1=Execution_Time2-80;//H4
		   	 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-85;//H3
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-90; //H2
	 		 break;
	    case 115:
	   	 	 Execution_Time1=Execution_Time2-95; //H1
	   	 	 break;
	   }

	return Execution_Time1;
}


void reschedule_function_20(int reschedule)
{

	reschedule = MSG_process_self_PPID();

	 switch (reschedule)
	 {
	     case 67:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host19"));
	    	break;
	     case 115:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host4"));
	     	  break;
	     case 135:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host3"));
	     	  break;
	     case 253:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host8"));
	     	  break;

	 }
	 return;
}



void terminate_function_20()

{

	msg_host_t msg_host = MSG_process_get_host(MSG_process_self());
	struct HdmsgHost * this_host = xbt_dict_get(hosts, MSG_host_get_name(msg_host));
	while (1)
	    {

	if ((strncmp("host5", MSG_process_get_name(MSG_process_self()), 5)== 0))//H20
		{
			continue;
		 }
	else if ((strncmp("host6", MSG_process_get_name(MSG_process_self()), 5)== 0))//H19
		{
		continue;
		}
	else
	  break;
	    }
}




//TODO:  create reduce execution times functions !

double exec_function(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	     case 2:
	    	 Execution_Time1=Execution_Time2-0.01;
	    	break;
	    case 738:
	    	 Execution_Time1=Execution_Time2-0.1;
	    	 break;
	    case 691:
	    	 Execution_Time1=Execution_Time2-0.2;
	    	 break;
	    case 647:
	    	 Execution_Time1=Execution_Time2-0.3;
	    	 break;
	    case 603:
	    	 Execution_Time1=Execution_Time2-0.4;
	    	 break;
	    case 562:
	    	 Execution_Time1=Execution_Time2-0.5;
	    	 break;
	    case 521:
	   	     Execution_Time1=Execution_Time2-0.6;
	   	     break;
	    case 483:
	   	     Execution_Time1=Execution_Time2-0.7;
	   	     break;
	    case 445:
	   	     Execution_Time1=Execution_Time2-0.8;
	   	     break;
	    case 410:
	   	     Execution_Time1=Execution_Time2-0.9;
	   	     break;
	    case 375:
	   	     Execution_Time1=Execution_Time2-1.0;
	   	     break;
	    case 343:
	   	     Execution_Time1=Execution_Time2-1.1;
	   	     break;
	    case 311:
	   	     Execution_Time1=Execution_Time2-1.2;
	   	     break;
	    case 282:
	   	     Execution_Time1=Execution_Time2-1.3;
	   	     break;
	    case 253:
		   	 Execution_Time1=Execution_Time2-1.4;
		   	 break;
	    case 227:
		   	 Execution_Time1=Execution_Time2-1.5;
		   	 break;
	    case 201:
	 		 Execution_Time1=Execution_Time2-1.6;
	 		 break;
	    case 178:
	 		 Execution_Time1=Execution_Time2-1.7;
	 		 break;
	    case 155:
	 		 Execution_Time1=Execution_Time2-1.8;
	 		 break;
	    case 135:
	 		 Execution_Time1=Execution_Time2-1.9;
	 		 break;
	    case 115:
	 		 Execution_Time1=Execution_Time2-2.0;
	 		 break;
	    case 98:
	 		 Execution_Time1=Execution_Time2-2.1;
	 		 break;
	    case 81:
	 		 Execution_Time1=Execution_Time2-2.2;
	 		 break;
	    case 67:
	 		 Execution_Time1=Execution_Time2-2.3;
	 		 break;
	    case 53:
	 		 Execution_Time1=Execution_Time2-2.4;
	 		 break;
	    case 42:
	 		 Execution_Time1=Execution_Time2-2.5;
	 		 break;
	    case 31:
	 		 Execution_Time1=Execution_Time2-2.6;
	 		 break;
	    case 23:
	    	  Execution_Time1=Execution_Time2-2.7;
	    	  break;
	    case 15:
	    	  Execution_Time1=Execution_Time2-2.8;
	    	  break;
	    case 10:
	    	 Execution_Time1=Execution_Time2-2.9;
	    	 break;
	    case 5:
	    	 Execution_Time1=Execution_Time2-3.0;
	    	 break;
	    case 1221:
	    	 Execution_Time1=Execution_Time2-3.1;
	    	 break;
	    case 1162:
	    	 Execution_Time1=Execution_Time2-3.2;
	    	 break;
	    case 1103:
	    	 Execution_Time1=Execution_Time2-3.3;
	    	 break;
	    case 1047:
	    	 Execution_Time1=Execution_Time2-3.4;
	    	 break;
	    case 991:
	    	 Execution_Time1=Execution_Time2-3.5;
	    	 break;
	    case 938:
	    	 Execution_Time1=Execution_Time2-3.6;
	    	  break;
	    case 885:
	    	 Execution_Time1=Execution_Time2-3.7;
	    	 break;
	    case 835:
	    	 Execution_Time1=Execution_Time2-3.8;
	    	 break;
	    case 785:
	    	 Execution_Time1=Execution_Time2-3.9;
	    	break;
	   default:
	    	 Execution_Time1=Execution_Times2;
	    	break;
	  }

	return Execution_Time1;
}



//TODO:  create reduce execution times functions !

double MAPexec_function_20_1(int host, double Execution_Time2)
{
	double Execution_Time1=0;

	 host = MSG_process_self_PPID();

	 switch (host)
	 {
	     case 2:
	    	 Execution_Time1=Execution_Time2-0.01;
	    	break;
	    case 738:
	    	 Execution_Time1=Execution_Time2-0.1;
	    	 break;
	    case 691:
	    	 Execution_Time1=Execution_Time2-0.2;
	    	 break;
	    case 647:
	    	 Execution_Time1=Execution_Time2-0.3;
	    	 break;
	    case 603:
	    	 Execution_Time1=Execution_Time2-0.4;
	    	 break;
	    case 562:
	    	 Execution_Time1=Execution_Time2-0.5;
	    	 break;

	   default:
	    	 Execution_Time1=Execution_Times2;
	    	break;
	  }

	return Execution_Time1;
}



double Redstoptime_function_20(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	     case 115:
	    	 stop_tt=stop_t-1.0;
	    	break;
	     case 135:
	    	 stop_tt=stop_t-1.0;
	     	  break;
	     case 178:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 155:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 201:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 227:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 253:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 282:
	     	 stop_tt=stop_t-1.0;
	     	 break;
	     case 311:
	     	   stop_tt=stop_t-1.0;
	     	   break;
	     case 2:
	     	   stop_tt=stop_t-1.0;
	     	   break;
	     default:
	    	 stop_tt=stop_t;
	     	  break;
	    }
	 return stop_tt;
}



double Redstoptime_function_20_4(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	     case 115:
	    	 stop_tt=stop_t-1.0;
	    	break;
	     case 135:
	    	 stop_tt=stop_t-1.0;
	     	  break;
	     case 178:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 155:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 201:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 227:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 253:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 282:
	     	 stop_tt=stop_t-1.0;
	     	 break;
	     case 311:
	     	   stop_tt=stop_t-1.0;
	     	   break;
	     case 2:
	     	   stop_tt=stop_t-1.0;
	     	   break;
	     case 98:
	    	   stop_tt=stop_t+1.0;
	    	    break;
	     case 81:
	    	   stop_tt=stop_t+1.0;
	    	   break;
	     case 67:
	    	   stop_tt=stop_t+1.0;
	    	    break;
	     case 53:
	    	    stop_tt=stop_t+1.0;
	    	    break;
	     case 42:
	    	   stop_tt=stop_t+1.0;
	    	    break;
	     case 31:
	    	    stop_tt=stop_t+1.0;
	    	    break;
	     default:
	    	 stop_tt=stop_t;
	     	  break;
	    }
	 return stop_tt;
}


double Mapstoptime_function_20_2(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	     case 115:
	    	 stop_tt=stop_t+3.3134;
	    	break;
	     case 135:
	    	 stop_tt=stop_t+3.2989;
	     	  break;
	     case 253:
	     	  stop_tt=stop_t+3.3134;
	     	  break;
	     case 67:
	     	 stop_tt=stop_t+3.2989;
	     	 break;
	  	 default:
	    	 stop_tt=stop_t;
	     	  break;
	    }
	 return stop_tt;
}



double Mapstarttime_function_20_3(int time_2, double start_time)
{
	double start_time2=0;

	 time_2 = MSG_process_self_PPID();

	 switch (time_2)
	 {
	     case 115:
	    	 start_time2=start_time +3.3134;
	    	break;
	     case 135:
	    	 start_time2=start_time +3.2989;
	     	  break;
	     case 253:
	    	 start_time2=start_time +3.3134;
	     	  break;
	     case 67:
	    	 start_time2=start_time +3.2989;
	     	 break;
	  	 default:
	  		start_time2=start_time;
	     	  break;
	    }
	 return start_time2;
}


double Redstoptime_function_20_3(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	     case 115:
	    	 stop_tt=stop_t-1.0;
	    	break;
	     case 135:
	    	 stop_tt=stop_t-1.0;
	     	  break;
	     case 178:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 155:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 201:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 227:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 253:
	     	  stop_tt=stop_t-1.0;
	     	  break;
	     case 282:
	     	 stop_tt=stop_t-1.0;
	     	 break;
	  	 default:
	    	 stop_tt=stop_t;
	     	  break;
	    }
	 return stop_tt;
}


double Redstoptime_function_20_2(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	 	 	 case 115:
	 	    	 stop_tt=stop_t-3.91;
	 	    	break;
	 	     case 135:
	 	    	 stop_tt=stop_t-3.91;
	 	     	  break;
	 	     case 178:
	 	     	  stop_tt=stop_t-4.91;
	 	     	  break;
	 	     case 155:
	 	     	  stop_tt=stop_t-3.91;
	 	     	  break;
	 	     case 201:
	 	     	  stop_tt=stop_t-4.91;
	 	     	  break;
	 	     case 227:
	 	     	  stop_tt=stop_t-4.91;
	 	     	  break;
	 	     case 253:
	 	     	  stop_tt=stop_t-4.21;
	 	     	  break;
	 	     case 282:
	 	     	 stop_tt=stop_t-4.21;
	 	     	 break;
	 	     case 311:
	 	     	   stop_tt=stop_t-3.91;
	 	     	   break;
	 	     case 2:
	 	     	   stop_tt=stop_t-4.21;
	 	     	   break;
	 	     case 5:
	 	    	   stop_tt=stop_t-4.21;
	 	    	    break;
	 	     case 23:
	 	    	   stop_tt=stop_t-3.91;
	 	    	   break;
	 	     case 15:
	 	    	    stop_tt=stop_t-3.91;
	 	    	    break;
	 	     case 10:
	 	    	   stop_tt=stop_t-3.91;
	 	    	    break;
	 	     case 31:
	 	    	    stop_tt=stop_t-3.91;
	 	    	    break;
	 	     default:
	 	    	 stop_tt=stop_t;
	 	     	  break;
	    }
	 return stop_tt;
}


double Redstoptime_function_20_1(int time, double stop_t)
{
	double stop_tt=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	 	 	 case 115:
	 	    	 stop_tt=stop_t-1.9;
	 	    	break;
	 	     case 135:
	 	    	 stop_tt=stop_t-1.9;
	 	     	  break;
	 	     case 155:
	 	     	  stop_tt=stop_t-1.9;
	 	     	  break;
	 	     default:
	 	    	 stop_tt=stop_t;
	 	     	  break;
	    }
	 return stop_tt;
}



//TODO:  create execution times functions! Returns the Stop time for reduce task 1 for the 40_8 setup!

double stoptime_function_40_1(int time, double stop_t)
{
	double stop_tt_40_1=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	     case 2:
	    	 stop_tt_40_1=stop_t+0.1;
	    	break;
	     case 201:
	    	 stop_tt_40_1=stop_t-0.6;
	     	  break;
	     case 178:
	     	  stop_tt_40_1=stop_t-1.0;
	     	  break;
	     case 155:
	     	  stop_tt_40_1=stop_t-1.0;
	     	  break;
	     case 135:
	     	   stop_tt_40_1=stop_t-1.0;
	     	   break;
	     case 115:
	     	   stop_tt_40_1=stop_t-1.0;
	     	   break;
	     case 98:
	    	  stop_tt_40_1=stop_t-1.5;
	    	  break;
	     case 81:
	     	  stop_tt_40_1=stop_t-1.7;
	     	  break;
	     case 67:
	     	  stop_tt_40_1=stop_t-1.8;
	     	  break;
	     case 53:
	     	  stop_tt_40_1=stop_t-1.9;
	     	  break;
	     case 42:
	     	 stop_tt_40_1=stop_t-2.0;
	     	 break;
	     case 31:
	     	   stop_tt_40_1=stop_t-2.1;
	     	   break;
	     case 23:
	     	   stop_tt_40_1=stop_t-2.2;
	     	   break;
	     case 15:
	     	  stop_tt_40_1=stop_t-2.3;
	     	  break;
	     case 10:
	     	   stop_tt_40_1=stop_t-2.4;
	     	    break;
	     case 5:
	     	    stop_tt_40_1=stop_t-2.5;
	     	    break;
	     case 1221:
	     	    stop_tt_40_1=stop_t-2.6;
	     	    break;
	     case 1162:
	     	    stop_tt_40_1=stop_t-2.7;
	     	    break;
	     case 1103:
	     	     stop_tt_40_1=stop_t-2.8;
	     	     break;
	     case 1047:
	     	     stop_tt_40_1=stop_t-2.9;
	     	     break;
	     case 991:
	     	     stop_tt_40_1=stop_t-3.0;
	     	     break;
	     case 938:
	     	     stop_tt_40_1=stop_t-3.1;
	     	     break;
	     case 885:
	     	     stop_tt_40_1=stop_t-2.9;
	     	     break;
	     case 835:
	     	     stop_tt_40_1=stop_t-3.0;
	     	     break;
	     case 785:
	     	     stop_tt_40_1=stop_t-3.1;
	     	     break;
	     default:
	    	stop_tt_40_1=stop_t;
	    	 break;
	 }
	 return stop_tt_40_1;
}
// TODO Returns the Stop time for reduce tasks 2 for the 40_8 setup !
double stoptime_function_40_2(int time, double stop_t)
{
	double stop_tt_40_2=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {

	     case 282:
	    	 stop_tt_40_2=stop_t-1.3;
	     	  break;
	     case 253:
	    	 stop_tt_40_2=stop_t-1.4;
	     	  break;
	     case 227:
	    	 stop_tt_40_2=stop_t-1.5;
	     	  break;
	     case 201:
	    	 stop_tt_40_2=stop_t-1.6;
	     	 break;
	     case 178:
	     	  stop_tt_40_2=stop_t-1.7;
	     	   break;
	     case 155:
	     	  stop_tt_40_2=stop_t-1.8;
	     	  break;
	     case 135:
	     	  stop_tt_40_2=stop_t-1.9;
	     	  break;
	     case 115:
	   	     stop_tt_40_2=stop_t-2.0;
	   	     break;
	     case 98:
	     	   stop_tt_40_2=stop_t-2.1;
	     	   break;
	     case 81:
	     	  stop_tt_40_2=stop_t-2.2;
	     	   break;
	     case 67:
	     	  stop_tt_40_2=stop_t-2.3;
	     	  break;
	     case 53:
	     	  stop_tt_40_2=stop_t-2.4;
	     	  break;
	     case 42:
	     	 stop_tt_40_2=stop_t-2.0;
	     	 break;
	     case 31:
	     	  stop_tt_40_2=stop_t-2.1;
	     	  break;
	     case 23:
	     	  stop_tt_40_2=stop_t-2.2;
	     	   break;
	     case 15:
	     	  stop_tt_40_2=stop_t-2.3;
	     	  break;
	     case 10:
	     	  stop_tt_40_2=stop_t-2.4;
	     	  break;
	     case 5:
	     	   stop_tt_40_2=stop_t-2.5;
	     	   break;
	     case 1221:
	     	   stop_tt_40_2=stop_t-2.6;
	     	   break;
	     case 1162:
	     	   stop_tt_40_2=stop_t-2.7;
	     	   break;
	     case 1103:
	     	    stop_tt_40_2=stop_t-2.8;
	     	     break;
	     case 1047:
	     	    stop_tt_40_2=stop_t-7.9; // add noise of 5
	     	    break;
	     case 991:
	     	     stop_tt_40_2=stop_t-8.0;
	     	     break;
	     case 938:
	     	     stop_tt_40_2=stop_t-8.1;
	     	     break;
	     case 885:
	     	    stop_tt_40_2=stop_t-3.2;
	     	    break;
	     case 835:
	     	     stop_tt_40_2=stop_t-3.3;
	     	     break;
	     case 785:
	     	     stop_tt_40_2=stop_t-3.4;
	     	     break;
   		default:
	    	 stop_tt_40_2=stop_t;
	    	 break;
	 }
	 return stop_tt_40_2;
}

// TODO Returns the Stop time for reduce tasks 3 for the 40_8 setup !
double stoptime_function_40_3(int time, double stop_t)
{
	double stop_tt_40_3=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {

	 	 case 343:
		    stop_tt_40_3=stop_t-1.1;
		     break;
	     case 282:
	    	 stop_tt_40_3=stop_t-1.3;
	     	  break;
	     case 253:
	    	 stop_tt_40_3=stop_t-1.4;
	     	  break;
	     case 227:
	    	 stop_tt_40_3=stop_t-1.5;
	     	  break;
	     case 201:
	    	 stop_tt_40_3=stop_t-1.6;
	     	 break;
	     case 178:
	     	  stop_tt_40_3=stop_t-1.7;
	     	  break;
	     case 155:
	     	  stop_tt_40_3=stop_t-1.8;
	     	  break;
	     case 135:
	     	   stop_tt_40_3=stop_t-1.9;
	     	   break;
	     case 115:
	     	   stop_tt_40_3=stop_t-2.0;
	     	   break;
	     case 98:
	     	  stop_tt_40_3=stop_t-2.1;
	     	  break;
	     case 81:
	     	  stop_tt_40_3=stop_t-2.2;
	     	  break;
	     case 67:
	     	  stop_tt_40_3=stop_t-2.3;
	     	   break;
	     case 53:
	     	  stop_tt_40_3=stop_t-2.4;
	     	  break;
	     case 42:
	     	  stop_tt_40_3=stop_t-2.0;
	     	  break;
	     case 31:
	     	  stop_tt_40_3=stop_t-2.1;
	     	  break;
	     case 23:
	     	   stop_tt_40_3=stop_t-2.2;
	     	   break;
	     case 15:
	     	   stop_tt_40_3=stop_t-2.3;
	     	   break;
	     case 10:
	     	   stop_tt_40_3=stop_t-2.4;
	     	   break;
	     case 5:
	     	    stop_tt_40_3=stop_t-2.5;
	     	   break;
	     case 1221:
	     	  stop_tt_40_3=stop_t-2.6;
	     	  break;
	     case 1162:
	     	   stop_tt_40_3=stop_t-2.7;
	     	   break;
	     case 1103:
	     	     stop_tt_40_3=stop_t-2.8;
	     	     break;
	     case 1047:
	    	     stop_tt_40_3=stop_t-2.9;
	    	     break;
	     case 991:
	     	     stop_tt_40_3=stop_t-3.0;
	     	     break;
	     case 938:
	     	     stop_tt_40_3=stop_t-3.1;
	     	     break;
	     case 885:
	    	     stop_tt_40_3=stop_t-3.2;
	    	     break;
	     case 835:
	     	     stop_tt_40_3=stop_t-3.3;
	     	     break;
	     case 785:
	     	     stop_tt_40_3=stop_t-3.4;
	     	     break;

		 default:
	    	stop_tt_40_3=stop_t;
	    	 break;
	 }
	 return stop_tt_40_3;
}

// TODO Returns the Stop time for reduce tasks 4 for the 40_8 setup !
double stoptime_function_40_4(int time, double stop_t)
{
	double stop_tt_40_4=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {

	 	 case 410:
	 		 stop_tt_40_4=stop_t-0.05;
	     	 break;
 	 	 case 375:
 	 		 stop_tt_40_4=stop_t-0.15;
	    	break;
	 	 case 343:
		    stop_tt_40_4=stop_t-1.1;
		     break;
	     case 282:
	    	 stop_tt_40_4=stop_t-1.3;
	     	  break;
	     case 253:
	    	 stop_tt_40_4=stop_t-1.4;
	     	  break;
	     case 227:
	    	 stop_tt_40_4=stop_t-1.5;
	     	  break;
	     case 201:
	    	 stop_tt_40_4=stop_t-1.6;
	     	 break;
	     case 178:
	     	   stop_tt_40_4=stop_t-1.7;
	     	   break;
	     case 155:
	     	  stop_tt_40_4=stop_t-1.8;
	     	  break;
	     case 135:
	     	  stop_tt_40_4=stop_t-1.9;
	     	  break;
	     case 115:
	     	  stop_tt_40_4=stop_t-2.0;
	     	  break;
	     case 98:
	     	  stop_tt_40_4=stop_t-2.1;
	     	  break;
	     case 81:
	     	  stop_tt_40_4=stop_t-2.2;
	     	  break;
	     case 67:
	     	  stop_tt_40_4=stop_t-2.3;
	     	  break;
	     case 53:
	     	  stop_tt_40_4=stop_t-2.4;
	     	  break;
	     case 42:
	     	   stop_tt_40_4=stop_t-2.0;
	     	   break;
	     case 31:
	     	   stop_tt_40_4=stop_t-2.1;
	     	   break;
	     case 23:
	     	    stop_tt_40_4=stop_t-2.2;
	     	    break;
	     case 15:
	     	    stop_tt_40_4=stop_t-2.3;
	     	    break;
	     case 10:
	     	    stop_tt_40_4=stop_t-2.4;
	     	    break;
	     case 5:
	     	    stop_tt_40_4=stop_t-2.5;
	     	    break;
	     case 1221:
	     	    stop_tt_40_4=stop_t-2.6;
	     	    break;
	     case 1162:
	     	     stop_tt_40_4=stop_t-2.7;
	     	    break;
	     case 1103:
	     	     stop_tt_40_4=stop_t-2.8;
	     	     break;
	     case 1047:
	     	     stop_tt_40_4=stop_t-2.9;
	     	     break;
	     case 991:
	     	     stop_tt_40_4=stop_t-3.0;
	     	     break;
	     case 938:
	     	     stop_tt_40_4=stop_t-3.1;
	     	     break;
	     case 885:
	    	     stop_tt_40_4=stop_t-3.2;
	    	     break;
	     case 835:
	    	     stop_tt_40_4=stop_t-3.3;
	    	     break;
	    case 785:
	    	     stop_tt_40_4=stop_t-3.4;
	    	     break;
		 default:
			 stop_tt_40_4=stop_t;
	    	 break;
	 }
	 return stop_tt_40_4;
}

// TODO Returns the Stop time for reduce tasks 5 for the 40_8 setup !
double stoptime_function_40_5(int time, double stop_t)
{
	double stop_tt_40_5=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
	 	 case 375:
 	 		 stop_tt_40_5=stop_t-0.15;
	    	break;
	 	 case 343:
		    stop_tt_40_5=stop_t-1.1;
		     break;
	 	case 311:
	 		stop_tt_40_5=stop_t-1.2;
	 		 break;
	     case 282:
	    	 stop_tt_40_5=stop_t-1.3;
	     	  break;
	     case 253:
	    	 stop_tt_40_5=stop_t-1.4;
	     	  break;
	     case 227:
	    	 stop_tt_40_5=stop_t-1.5;
	     	  break;
	     case 201:
	    	 stop_tt_40_5=stop_t-1.6;
	     	 break;
	     case 178:
	     	   stop_tt_40_5=stop_t-1.7;
	     	   break;
	     case 155:
	     	  stop_tt_40_5=stop_t-1.8;
	     	  break;
	     case 135:
	     	  stop_tt_40_5=stop_t-1.9;
	     	  break;
	     case 115:
	     	  stop_tt_40_5=stop_t-2.0;
	     	  break;
	     case 98:
	     	  stop_tt_40_5=stop_t-2.1;
	     	  break;
	     case 81:
	     	  stop_tt_40_5=stop_t-2.2;
	     	  break;
	     case 67:
	     	  stop_tt_40_5=stop_t-2.3;
	     	   break;
	     case 53:
	     	  stop_tt_40_5=stop_t-2.4;
	     	  break;
	     case 42:
	     	  stop_tt_40_5=stop_t-2.0;
	     	  break;
	     case 31:
	     	   stop_tt_40_5=stop_t-2.1;
	     	   break;
	     case 23:
	     	   stop_tt_40_5=stop_t-2.2;
	     	   break;
	     case 15:
	     	    stop_tt_40_5=stop_t-2.3;
	     	    break;
	     case 10:
	     	   stop_tt_40_5=stop_t-2.4;
	     	    break;
	     case 5:
	     	    stop_tt_40_5=stop_t-2.5;
	     	    break;
	     case 1221:
	     	     stop_tt_40_5=stop_t-2.6;
	     	     break;
	     case 1162:
	     	     stop_tt_40_5=stop_t-2.7;
	     	     break;
	     case 1103:
	     	     stop_tt_40_5=stop_t-2.8;
	     	     break;
	     case 1047:
	     	     stop_tt_40_5=stop_t-2.9;
	     	     break;
	     case 991:
	     	     stop_tt_40_5=stop_t-3.0;
	     	      break;
	     case 938:
	     	     stop_tt_40_5=stop_t-3.1;
	     	     break;
	     case 885:
	     	     stop_tt_40_5=stop_t-3.2;
	     	     break;
	     case 835:
	     	     stop_tt_40_5=stop_t-3.3;
	     	      break;
	     case 785:
	     	     stop_tt_40_5=stop_t-3.4;
	     	     break;


	     default:
	    	stop_tt_40_5=stop_t;
	    	 break;
	 }
	 return stop_tt_40_5;
}

// TODO Returns the Stop time for reduce tasks 9 for the 40_8 setup !
double stoptime_function_40_9(int time, double stop_t)
{
	double stop_tt_40_9=0;

	 time = MSG_process_self_PPID();

	 switch (time)
	 {
 	 	 case 375:
 	 		 stop_tt_40_9=stop_t-0.15;
	    	break;
	 	case 311:
	 		stop_tt_40_9=stop_t-1.2;
	 		 break;
	     case 282:
	    	 stop_tt_40_9=stop_t-1.3;
	     	  break;
	     case 253:
	    	 stop_tt_40_9=stop_t-1.4;
	     	  break;
	     case 227:
	    	 stop_tt_40_9=stop_t-1.5;
	     	  break;
	     case 201:
	    	 stop_tt_40_9=stop_t-1.6;
	     	 break;
	     case 178:
	     	  stop_tt_40_9=stop_t-1.7;
	     	  break;
	     case 155:
	     	  stop_tt_40_9=stop_t-1.8;
	     	  break;
	     case 135:
	     	  stop_tt_40_9=stop_t-1.9;
	     	  break;
	     case 115:
	     	  stop_tt_40_9=stop_t-2.0;
	     	  break;
	     case 98:
	     	 stop_tt_40_9=stop_t-2.1;
	     	  break;
	     case 81:
	   	     stop_tt_40_9=stop_t-2.2;
	   	     break;
	     case 67:
	     	  stop_tt_40_9=stop_t-2.3;
	     	  break;
	     case 53:
	     	  stop_tt_40_9=stop_t-2.4;
	     	  break;
	     case 42:
	     	  stop_tt_40_9=stop_t-2.0;
	     	   break;
	     case 31:
	     	  stop_tt_40_9=stop_t-2.1;
	     	  break;
	     case 23:
	     	    stop_tt_40_9=stop_t-2.2;
	     	    break;
	     case 15:
	     	    stop_tt_40_9=stop_t-2.3;
	     	    break;
	     case 10:
	     	   stop_tt_40_9=stop_t-2.4;
	     	   break;
	     case 5:
	     	   stop_tt_40_9=stop_t-2.5;
	     	   break;
	     case 1221:
	     	    stop_tt_40_9=stop_t-2.6;
	     	    break;
	     case 1162:
	     	    stop_tt_40_9=stop_t-2.7;
	     	    break;
	     case 1103:
	     	     stop_tt_40_9=stop_t-2.8;
	     	     break;
	     case 1047:
	     	     stop_tt_40_9=stop_t-2.9;
	     	     break;
	     case 991:
	     	      stop_tt_40_9=stop_t-3.0;
	     	     break;
	     case 938:
	     	     stop_tt_40_9=stop_t-3.1;
	     	     break;

	     case 885:
	     	     stop_tt_40_9=stop_t-3.2;
	     	     break;
	     case 835:
	     	     stop_tt_40_9=stop_t-3.3;
	     	     break;
	     case 785:
	     	     stop_tt_40_9=stop_t-3.4;
	     	     break;

		 default:
	    	stop_tt_40_9=stop_t;
	    	 break;
	 }
	 return stop_tt_40_9;
}


// TODO Reschedules tasks from one host to another for the 40_8 setup!

void reschedule_function_40(int reschedule)
{

	reschedule = MSG_process_self_PPID();

	 switch (reschedule)
	 {
	     case 1103:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host8"));
	    	break;
	     case 785:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host4"));
	     	  break;
	     case 885:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host9"));
	     	  break;
	     case 835:
	    	 MSG_process_migrate(MSG_process_self(), MSG_get_host_by_name("host11"));
	     	  break;

	 }
	 return;
}
