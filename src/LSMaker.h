/***
 *	Name: LSMaker.h
 *	Author: Albert Lloveras Carbonell (alloveras@salleurl.edu)
 *	Last Revision: 18/07/2016
 *	Description: This class implements the core library for the LSMaker Arduino
 *  project. It exports a global initialization method and two more methods that
 *  act as public interface for users to subscribe or unsubscribe modules to the
 *  LSMaker scheduler.
***/

#ifndef _LSM_LSMAKER_H_
#define _LSM_LSMAKER_H_

//Arduino Library include
#include <Arduino.h>

//Additional includes
#include "External/LSMakerModule.h"
#include "Collections/LinkedList.h"

namespace LSM{
    
    class LSMaker{

        public:
            static void init(void);

        public:
            static bool addModule(LSMakerModule *module, unsigned long period = 0);
            static bool removeModule(LSMakerModule *module);
    };

}

#endif
