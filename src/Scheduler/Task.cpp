#include "Task.h"

Task::Task(LSMakerModule *module, unsigned long period){
    this->period = period;
    this->lastExecution = millis();
    this->module = module;
    this->init();
}

void Task::init(void){

    //Before calling the module init() method we should check that the module
    //pointer is still valid in order to avoid segmentation fault trap to be
    //raised.
    if(this->module != NULL){
        this->module->init();
    }
}

void Task::execute(void){

    //Before calling the execute() method on module object we should be sure
    //that the pointer is still valid in order to avoid segmentation fault
    //trap to be raised.
    if(this->module != NULL){

        //If the elapsed time after last execution of the module's is bigger
        //than the user-specified period we should call again the module's
        //execute() method and update the lastExecution timestamp. Otherwise,
        //no operation should be performed.
        if((millis() - this->lastExecution) >= this->period){
            this->module->execute();
            this->lastExecution = millis();
        }

    }
}

void Task::destroy(void){

    //Check if the module instance is valid and, in consequence, the destroy
    //method can be called.
    if(this->module != NULL){
        this->module->destroy();
    }

}

bool Task::compare(LSMakerModule *module){

    //Before comparing both modules we have to check both pointers are still
    //valid. If so, we should call getModuleName() methods in each object and
    //return the comparison of returned values. Note: if any of both pointers
    //is NULL we can't assume that modules are equal and false must be returned.
    if(module != NULL && this->module != NULL){
        return this->module->getModuleName().equals(module->getModuleName());
    }
    return false;
}
