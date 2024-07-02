#ifndef __GOLF_H_
#define __GOLF_H_

class Golf {
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;

public:
    Golf(const char * name, int hc = 0);
    Golf();
    void set_handicap(int hc);
    void showgolf(void) const;
};

#endif // __GOLF_H_