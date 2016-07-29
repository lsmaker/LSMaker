#include "Scheduler.h"

LinkedList<Task *> * Scheduler::tasks = NULL;

void Scheduler::init(void){

  //Initialize tasks list
  tasks = new LinkedList<Task *>();

  //Disable Interrupts
  cli();

  TCCR1A = 0x00;
  TCCR1B = 0x01;

  //Enable Timer1 overflow interrupts
  TIMSK1 |= (1 << (TOIE1));

  //Set the Timer1 value to count 62.5uS
  TCNT1 = 64536;

  //Enable interrupts
  sei();

}

bool Scheduler::addTask(LSMakerModule *module, unsigned long period){

  bool returnValue = false;

  //Disable interrupts
  cli();

  //Check the module doesn't exist. If so, create a new Task object to wrap the
  //received object and add it to the scheduler tasks list.
  if(exists(module) == false){
    tasks->moveFirst();
    tasks->addElement(new Task(module,period));
    returnValue = true;
  }

  //Enable interrupts
  sei();

  return returnValue;

}

bool Scheduler::removeTask(LSMakerModule *module){

  bool returnValue = false;

  //Disable interrupts
  cli();

  //Check the module exists
  if(exists(module) == true){
    Task *t = tasks->getElement();
    t->destroy();
    tasks->removeElement();
    returnValue = true;
  }

  //Enable interrupts
  sei();

  return returnValue;
}

bool Scheduler::exists(LSMakerModule *module){

  //Iterate over the task list in order to find if the module received as
  //parameter has been already attatched to the system's scheduler.
  tasks->moveFirst();
  while(tasks->hasNext()){
    if(tasks->getElement()->compare(module) == true){
      return true;
    }
    tasks->moveNext();
  }

  return false;
}

void TIMER1_OVF_vect(void){

  //Iterate over scheduled tasks and execute them if needed.
  Scheduler::tasks->moveFirst();
  while(Scheduler::tasks->hasNext()){
    Scheduler::tasks->getElement()->execute();
    Scheduler::tasks->moveNext();
  }

  //Re-load the Timer1 value to force new overflow after 62.5uS
  TCNT1 = 64535;

}
