#include "LSMaker.h"

//Internal classes includes
#include "Scheduler/Scheduler.h"

void LSMaker::init(void){
  Scheduler::init();
}

bool LSMaker::addModule(LSMakerModule *module, unsigned long period){
  return Scheduler::addTask(module,period);
}

bool LSMaker::removeModule(LSMakerModule *module){
  return Scheduler::removeTask(module);
}
