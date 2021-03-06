/*
Lab5 source file
Largely adapted from program 2 robomall.c as written by Professor Robert Kinicki, with the inclusion
of a space for queue implementation. Changes made by Alexi Kessler.

*/
#ifndef LAB5_CPP
#define LAB5_CPP
#include <iostream>
#include "globals.h"
#include "tile.h"
#include "destination.h"
#include <cstdlib>

using namespace std;

Dest Dests[20];
Tile Mall[MAX+1][MAX+1][2];
int simTime = 0;

void readData(int stores);
int init_mall ();
void printloc (int []);
bool IsEqual (int [], int []);
void d1(int [], int); 
void d2(int [], int[], int);
void d3(int [], int[], int);  
void next(int [], int [], int);
void twoway(int [], int [], int);
void elevator(int [], int[], int);

// move function controls robot's steps  
void move (int cur[], int des[], int size) //Adapted
{

/* Choices {Invalid, One, Two, Three, Next, 
   TwoWay, Elevator,Store}              

   The main idea is to categorize the type of
   choice the robot has and use switch to process
   that choice.  type array keeps choice type for
   all mall locations.

*/
  switch ((Mall[cur[ROW]][cur[COL]][cur[FLOOR]]).getType())
  
  {
    case Store:    
    case One:      d1(cur, SIZE);
                   break;
    case Two:      d2(cur,des,SIZE);
                   break;
    case Three:    d3(cur,des,SIZE);
                   break;
    case Next:     next(cur,des,SIZE);
                   break;
    case TwoWay:   twoway(cur,des,SIZE);
                   break;
    case Elevator: elevator(cur,des,SIZE);
                   break;
    case INVALID:
    default:
                   printf("M: Lost in Mall at ");
                   printloc(cur);
		   printf("Type = %d\n",
                    Mall[cur[ROW]][cur[COL]][cur[FLOOR]].getType());
                   exit(EXIT_FAILURE);
  } //end switch

  // Simulation simTime incremented here after one step!
  simTime++;
  /*  This is a debug print in case you want to see individual
      robot steps.  

    printf("Time: %d Robot at ", simTime);
    printloc(cur);                        
  */
  return;
}

/* travel function takes robot  from 'from' location to 'to' location */
void travel (int from[], int to[], int size) //Adapted
{
  int cntr = 0;        // cntr used to check for infinite loop
   printf("Time: %d Robot leaves ", simTime);
   printloc(from);

   // Loop until robot arrives at store or A1
   while(!IsEqual(from,to) &&
         (cntr < MAX_PATH))
   {
     // move controls robot's steps
     move(from,to, SIZE);
     cntr++;
   }
   if (cntr == MAX_PATH) 
   {
     printf ("\n Infinite Loop"); 
     exit(EXIT_FAILURE);
   }
   return;
 }

 //Print's robot start and finish simTime
void printtravel(int tsimTime [2]) //Adapted
{
	printf ("Start Time   Finish Time\n");
	printf ("%11d  %12d\n", tsimTime[STIME], tsimTime[ETIME]);
	return;
}

int main (int argc, char*argv[]) //Author: Alexi Kessler
{
	int storeCnt, slice;
	char *storeCntString;
	char *sliceString;
	
	if (argc!=3){
		printf("Proper usage is ./lab5 stores simTime_slice\n");
	} else {
		storeCntString = argv[1];
		sliceString = argv[2];
		storeCnt = atoi(storeCntString);
		slice = atoi(sliceString);
		int i,j;
		int travelsimTime[2];
		
		*queue storeQueue = new queue();
		
		// R array holds robot location
		// S array holds next store location
		int robots, stores[MAX_STORES], R[3], S[3];

		// init_mall initializes type and step arrays
		init_mall();
		//Reads in the list of stores that the robot will visit and the time to be spent at each store
		readData(storeCnt);
		//Robot starts at A1 
		R[FLOOR] = First;
		R[ROW] = MID;
		R[COL] = MAX;
		//record robot's arrival simTime
		travelsimTime [STIME] = simTime;
		printf("Time: %d Robot enters Mall\n",
	    simTime);
		
		/* Implement movement and queue logic here
		//go through loop once for each store                 
		for (j = 0; j < storeCnt; j++)
		{
			//These variables, dr, dc, and df, are for a more elegant later implementation where stores are stored
			//as a Dest object and only their locations are passed
			int dr, dc, df;
			dr = (Dests[j]).getRow();
			dc = (Dests[j]).getCol();
			df = 2;
			S[ROW]=dr;
			S[COL]=dc;
			S[FLOOR]=df;
			printf("Next store is at %d %d %d\n", S[ROW], S[COL], S[FLOOR]);

			//robot travels from current location to next store
			travel(R, S, SIZE);
			printf("Time: %d Robot arrived at %d %d %d \n",
			   simTime, S[ROW], S[COL], S[FLOOR]);

		// bump up simTime to account for delay in store
		
		// Room for store queue implementation 
		
		simTime = simTime + 1 + S[FLOOR];
		}

		//robot has visited all its stores. Set store location
		// to A1 and then robot travels to exit mall         

		// use S to send robot to A1 exit from RoboMall
		S[ROW] = MID;
		S[COL] = MAX;
		S[FLOOR] = First;
		travel(R, S, SIZE);

		// record robot departure simTime from RoboMall
		travelsimTime[ETIME] = simTime;
		printf("Time: %d Robot leaves the mall!\n",
		simTime); 
		simTime++;  //bump up clock by one for next robots entry
	  
		
		
		//End of Simulation
		printf("Time: %d Simulation Ends\n", simTime);
		//Print out the start and end time
		printtravel(travelsimTime); */
	}
}

void readData(int stores) //Author: Alexi Kessler
{
	int counter = 0;
	for (counter = 0; counter<stores; counter++)
	{
		int c, r, s;
		cin>>c; //read in as x
		cin>>r; //read in as y
		cin>>s;
		Dests[counter].setCol(c); 
		Dests[counter].setRow(r);
		Dests[counter].setServ(s);
		if (DEBUGREAD==1)
		{
			cout<<"Dest["<<counter<<"]'s Row = "<<Dests[counter].getRow()<<endl;
			cout<<"Dest["<<counter<<"]'s Col = "<<Dests[counter].getCol()<<endl;
			cout<<"Dest["<<counter<<"]'s ServTime = "<<Dests[counter].getServ()<<endl;
		}
	}
}

#endif

