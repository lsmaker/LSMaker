/***
 *	Name: Scheduler.h
 *	Author: Albert Lloveras Carbonell (alloveras@salleurl.edu)
 *	Last Revision: 18/07/2016
 *	Description: This class implements the LSMaker scheduler that allows system
 *  and external modules to be executed concurrently with the user code even if
 *  the user is using blocking instructions such as while or for. This class
 *  also offers a public interface to allow the adding or removing LSMaker
 *  modules from the scheduler task list in runtime.
***/

#ifndef _LSMAKER_SCHEDULER_H_
#define _LSMAKER_SCHEDULER_H_

//System includes
#include <Arduino.h>
#include <avr/interrupt.h>

//Custom includes
#include "../Collections/LinkedList.h"
#include "../External/LSMakerModule.h"
#include "Task.h"

extern "C" {
    void TIMER1_OVF_vect(void) __attribute__ ((signal));
};

class Scheduler{

    private:
        static LinkedList<Task *> *tasks;

    public:
        static void init(void);
        static bool addTask(LSMakerModule *module, unsigned long period);
        static bool removeTask(LSMakerModule *module);
        friend void TIMER1_OVF_vect (void);

    private:
        static bool exists(LSMakerModule *module);
};

#endif
