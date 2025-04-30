//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"

#include <string>
#include <vector>
//ECMultiIntervalsTask
//taks consists of multiple intervals
//AddInterval(int a, int b) that add an interval a,b to it 
//otherwise behaves same as single soft interval
ECMultiIntervalsTask::ECMultiIntervalsTask(const std::string &tid) 
    : ECSimTask(tid), a(0), b(0)
{
}

void ECMultiIntervalsTask::AddInterval(int a, int b){
    //adds an interval to the vector
    softTask.push_back(pair<int, int>(a,b));
}

bool ECMultiIntervalsTask::IsReadyToRun(int tick) const{
    //similar approach to SoftIntervalTask except we need to iterate through
    for(auto i: softTask){
        return tick >= i.first && tick <= i.second;
    }
    
}

bool ECMultiIntervalsTask::IsFinished(int tick) const{

}




//ECHardIntervalTask
//different from ECSoftIntervalTask
//it must start at the time it requested
//otherwise it behaves the same as soft interval
using namespace std;
ECHardIntervalTask::ECHardIntervalTask(const string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn)
{
}

bool ECHardIntervalTask::IsReadyToRun(int tick) const{

}

bool ECHardIntervalTask::IsFinished(int tick) const{
}

void ECHardIntervalTask::Run(int tick, int duration){
}

void ECHardIntervalTask::Wait(int tick, int duration){
}

//ECConsecutiveTask
//Must run in a sonsecutive interbal
//once interupted it will finish
using namespace std;
ECConsecutiveIntervalTask::ECConsecutiveIntervalTask(const string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn)
{
}

bool ECConsecutiveIntervalTask::IsReadyToRun(int tick) const{
}

bool ECConsecutiveIntervalTask::IsFinished(int tick) const{
}

void ECConsecutiveIntervalTask::Run(int tick, int duration){
}

void ECConsecutiveIntervalTask::Wait(int tick, int duration){
}




//ECPerodicTask
//Recurring Task 
//Requests to run periodically of fixed length
//then idle for a fixed time
using namespace std;
ECPeriodicTask::ECPeriodicTask(const string &tid, int tmStart, int runLen, int sleepLen) : ECSimTask(tid), tmStart(tmStart), runLen(runLen), sleepLen(sleepLen)
{
}


bool ECPeriodicTask::IsReadyToRun(int tick) const{
}

bool ECPeriodicTask::IsFinished(int tick) const{
}

void ECPeriodicTask::Run(int tick, int duration){
}

void ECPeriodicTask::Wait(int tick, int duration){
}



