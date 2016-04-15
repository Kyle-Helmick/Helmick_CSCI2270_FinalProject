#ifndef TIMER_H
#define TIMER_H

using namespace std;

class Timer
{
    public:
        Timer();
        void wait(float seconds);
        virtual ~Timer();
    protected:
    private:
};

#endif // TIMER_H
