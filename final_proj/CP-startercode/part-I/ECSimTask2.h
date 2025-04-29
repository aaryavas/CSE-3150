//
//  ECSimTask2.h
//  
//
//  Simulation task: different types
//

#ifndef ECSimTask2_h
#define ECSimTask2_h

#include <string>
#include <vector>
#include "ECSimTask.h"

// Now your need to define the following different kinds of classes...

//***********************************************************
// Multiple intervasl task: a task spans multiple intervals of time; otherwise it behaves just like single (soft) interval

class ECMultiIntervalsTask : public ECSimTask
{
public:
    ECMultiIntervalsTask(const std::string &tid);
    // your code here..
    //AdddInterval Method - come back might be wrong
    int AddInterval(int a, int b); 
    //outside of this behaves the same as soft interval
    //use composition to fetch softinterval functionality

private:
    //values added only needed within the function
    ECSoftIntervalTask* soft; //composition of soft intervals
    int a;
    int b;

};

//***********************************************************
// One-shot task: a task spans a single interval [a,b] of time; this task has hard requirement: it must start at a and end at b. If this condition is not met, it just won't run at all!

class ECHardIntervalTask : public ECSimTask
{
public:
    ECHardIntervalTask(const std::string &tid, int tmStart, int tmEnd);
    
    // your code here..   
    //behaves like soft interval but starts at time requested
    
    //overridden as we are handling start differently
    bool IsReadyToRun(int tick) const override;  


private:
    ECSoftIntervalTask* soft;
};

//***********************************************************
// Consecutive interval task: a task spans a single interval [a,b] of time; this task, once start (can be anytime after time a, must run consecutively; if interrupted, it can no longer run

class ECConsecutiveIntervalTask : public ECSimTask
{
public:
    ECConsecutiveIntervalTask(const std::string &tid, int tmStart, int tmEnd);
    
    // your code here..

    //is handled differently for stopping
    //will stop when interrupted
    //maybe IsFinished but I think it will use Run

    virtual void Run(int tick, int duration) {tmTotRun += duration;}
        
    virtual bool IsFinished(int tick) const = 0;

    //not sure which one to choose or to include both or not 
private:
    int tmTotRun;
};

//***********************************************************
// Periodic task: a recurrent task that runs periodically of certain length

class ECPeriodicTask : public ECSimTask
{
public:
    // tickStart: when to start this periodic task; runLen: how long to run this task each time; sleepLen: after it finishes one run, hong long it will sleep
    ECPeriodicTask(const std::string &tid, int tmStart, int runLen, int sleepLen);
    
    // your code here..
    
    //occurs periodically for a fixed length
    bool IsReadyToRun(int tick) const override; 
    bool IsFinished(int tick) const override;

private:
    ECSoftIntervalTask* soft; 

};

#endif /* ECSimTask2_h */
