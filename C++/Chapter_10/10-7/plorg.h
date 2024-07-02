#ifndef __PLORG_H_
#define __PLORG_H_

class Plorg
{
private:
    static const int MAX = 19;
    char p_name[MAX];
    int ci;
public:
    Plorg(char * name = "Plorga", int value = 50);
    void set_ci(int value);
    void show_plorg(void) const;
};

#endif // __PLORG_H_