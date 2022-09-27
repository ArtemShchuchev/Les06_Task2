#include "Counter.h"

    Counter::Counter()
    {
        setCount(1);
    }
    Counter::Counter(int num)
    {
        setCount(num);
    }
    void Counter::increase()
    {
        ++count;
    }
    void Counter::decrease()
    {
        --count;
    }
    void Counter::setCount(int num)
    {
        count = num;
    }
    int Counter::getCount()
    {
        return count;
    }