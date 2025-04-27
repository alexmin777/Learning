#include <iostream>
#include <ctime>
#include <queue>

const int MIN_PER_HR = 60;

class Customer
{
private:
    long arrive_time;
    int process_time;
public:
    Customer() { arrive_time = process_time = 0; }
    void set(long when) { arrive_time = when; process_time = std::rand() % 3; }
    long when() const { return arrive_time; }
    int ptime() const { return process_time; }
};

typedef Customer Item;

bool newcustomer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    std::srand(std::time(0));

    cout << "Case Study: Bank of Herther Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customer per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    std::queue<Item> que;
    Item temp;
    int customers = 0;
    int served = 0;
    int turnaways = 0;
    int sum_line = 0;
    int line_wait = 0;
    int wait_time = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (que.size() == qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                que.push(temp);
            }
        }

        if (wait_time <= 0 && !que.empty())
        {
            wait_time = que.front().ptime();
            que.pop();
            served++;
            line_wait += wait_time;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += que.size();
    }


    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << "average wait time: " << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX) < 1;
}