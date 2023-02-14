/*
COPYRIGHT PLACEHOLDER

*/


/**********************************************************************************************
 * File         : events.h
 * Author       : Jonathan Meyer
 * Date         : 2/14/2023
 * CVS          : [Not sure what goes here]
 * Description  : Parallel Discrete Events framework
 *********************************************************************************************/

/*
  COUNT_TYPE_STAT, // stat is a simple counter  output is a number
  DIST_TYPE_STAT, // stat is the beginning of end of a distribution  output is a histogram
  PER_INST_TYPE_STAT, // stat is measured per instruction
  //   output is a ratio of count/inst_count
  PER_1000_INST_TYPE_STAT, // stat is measured per 1000 instructions
  //   output is a ratio of 1000*count/inst_count
  PER_1000_PRET_INST_TYPE_STAT, // stat is measured per 1000 pseudo-retired instructions
  //   output is a ratio of 1000*count/pret_inst_count
  PER_CYCLE_TYPE_STAT, // stat is measured per cycle
  //   output is a ratio of count/cycle_count
  RATIO_TYPE_STAT, // stat is measured per <some other stat>
  //   output is a ratio of count/other
  PERCENT_TYPE_STAT, // stat is measured per <some other stat>
  //   output is a percent of count/other
  LINE_TYPE_STAT,
*/

#include <string>

class AbstractEvent;

class AbstractEvent {
public:
    std::string str;
    long ID;
    long domain;


    AbstractEvent(const std::string& str, long ID,  long domain){
        this->str = str;
        this->ID = ID;
        this->domain = domain;
    }

    virtual ~AbstractEvent() = default;
    
};

class MemoryEvent : public AbstractEvent {

public:
    MemoryEvent(const std::string& str, long ID, long domain) : AbstractEvent(str, ID, domain) {}
    ~MemoryEvent() = default;
};

class CoreEvent : public AbstractEvent {
    public:
    CoreEvent(const std::string& str, long ID, long domain) : AbstractEvent(str, ID, domain) {}
    ~CoreEvent() = default;
};

class NOCEvent : public AbstractEvent {
    public:
    NOCEvent(const std::string& str, long ID, long domain) : AbstractEvent(str, ID, domain) {}
    ~NOCEvent() = default;
};
