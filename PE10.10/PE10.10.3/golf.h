#ifndef __GOLF_H__
#define __GOLF_H__

class Golf
{
    private:
        enum {Len = 40};
        char fullname[Len] {};
        int handicap {};
    public:
        Golf();
        Golf(const char *, int);
        void showGolf();
};

#endif