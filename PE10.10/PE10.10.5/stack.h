#ifndef STACK_H__
#define STACK_H__

static const int NameSize = 35;

struct customer
{
    char fullname[NameSize];
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum {Max = 10};
    Item items[Max] {};
    int top {};
    double total_payment {};
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &);
    bool pop(Item &);
    void show(void) const;
};

#endif