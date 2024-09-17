#ifndef __CLASSIC_H__
#define __CLASSIC_H__

class Cd {
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd() {}
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd {
private:
    char keyword[50];
public:
    Classic(const char * key, const char * s1, const char * s2, int n, double x);
    Classic(const Cd & d, const char * key);
    Classic(const Classic & c);
    Classic();
    ~Classic() {}
    virtual void Report() const;
    Classic & operator=(const Classic & d);
};

#endif