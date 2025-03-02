#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln, const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    
};

#endif  /* EMP_H_ */