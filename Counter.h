#pragma once

class Counter
{
private:
    int count;

public:
    Counter();
    Counter(int);
    void increase();
    void decrease();
    void setCount(int);
    int getCount();
};