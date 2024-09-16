#ifndef __COW_H__
#define __COW_H__

class Cow {
    char name[20];
    char * hobby;
    double weigth;
public:
    Cow();
    Cow(const char * nm, const char * bo, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

#endif   //__COW_H__