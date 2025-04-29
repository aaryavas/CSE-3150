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
using namespace std;
class ECMultiIntervalsTask : public ECSimTask
{
public:
    ECMultiIntervalsTask(const std::string &tid);
    // your code here..
    int AddInterval(int a, int b); 
    virtual bool IsReadyToRun(int tick) const override;
    virtual bool IsFinished(int tick) const override;

private:
    //composition of soft intervals
    int a;
    int b;
    vector<ECSoftIntervalTask> softTask;
};

//***********************************************************
// One-shot task: a task spans a single interval [a,b] of time; this task has hard requirement: it must start at a and end at b. If this condition is not met, it just won't run at all!

class ECHardIntervalTask : public ECSimTask
{
public:
    ECHardIntervalTask(const std::string &tid, int tmStart, int tmEnd);
    
    // your code here..   
    //behaves like soft interval but starts at time requested
    //overridden as we are handling differently
    bool IsReadyToRun(int tick) const override;  
    bool IsFinished(int tick) const override;
    // Run the task: Critical for checking the hard start condition on the first call.
    // Updates state (startedOnTime or failedToStart) based on 'tick'.
    void Run(int tick, int duration) override;

    // Wait: Critical for checking if the task missed its hard start time.
    // Updates state (failedToStart) if Wait is called at tmStart.
    void Wait(int tick, int duration) override;


private:
    int tmStart;
    int tmEnd;

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

    bool IsReadyToRun(int tick) const override;

    // Is task finished at 'tick'?
    // Finished if the interval end time is passed OR if it was interrupted.
    bool IsFinished(int tick) const override; // No longer pure virtual

    // Run the task: Sets the 'hasStarted' flag on the first call.
    void Run(int tick, int duration) override;

    // Wait: Critical for detecting interruption.
    // Sets the 'wasInterrupted' flag if called after the task has started.
    void Wait(int tick, int duration) override;
    //not sure which one to choose or to include both or not 
private:
    int tmStart;
    int tmEnd;
    //add more if needed 

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
