/***
 *	Name: Task.h
 *	Author: Albert Lloveras Carbonell (alloveras@salleurl.edu)
 *	Last Revision: 18/07/2016
 *	Description: This class is a wrapper that acts as a container for all those
 *  LSMaker modules that are attached to the Scheduler. This class was added
 *  to provide a higher layer of abstraction to the module developer. It allows
 *  the LSMakerModule class to be logic-less because all the logic
 *  implementations needed by the scheduler is implemented by this private class
 *  wrapper.
***/

#ifndef _LSM_LSMAKER_SCHEDULER_TASK_H_
#define _LSM_LSMAKER_SCHEDULER_TASK_H_

#include <Arduino.h>
#include "../External/LSMakerModule.h"

namespace LSM{

    class Task{

        private:
            unsigned long period = 0;
            unsigned long lastExecution = 0;
            LSMakerModule *module = NULL;

        private:
            void init(void);

        public:
            Task(LSMakerModule *module, unsigned long period = 0);
            void execute(void);
            void destroy(void);
            bool compare(LSMakerModule *module);
    };

}

#endif
