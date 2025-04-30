#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Review {
    string title;
    int rating;
    double price;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool worseprice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2);
bool betterprice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2); 
bool FillReview(shared_ptr<Review> & rr);
void ShowReview(const shared_ptr<Review> & rr);

int main()
{
    vector<shared_ptr<Review> > books;
    
    shared_ptr<Review> ptemp;
    while (FillReview(ptemp))
        books.push_back(ptemp);
    
    if (books.size() > 0)
    {
        vector<shared_ptr<Review>> some_books(books);
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tPrice\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        char ch;
        cout << "Menu:" << endl;
        cout << "o: show original books" << endl;
        cout << "a: show books by title" << endl;
        cout << "u: show books by up rating" << endl;
        cout << "d: show books by down rating" << endl;
        cout << "p: show books by up price" << endl;
        cout << "k: show books by down price" << endl;
        cout << "q: quit" << endl;
        cout << "input: ";
        while (cin >> ch, tolower(ch) != 'q')
        {
            switch (ch)
            {
                case 'o':
                {
                    cout << "Original books:\nRating\tPrice\tBook\n";
                    for_each(books.begin(), books.end(), ShowReview);
                    break;
                }
                case 'a':
                {
                    sort(some_books.begin(), some_books.end());
                    cout << "Sorted by title:\nRating\tPrice\tBook\n";
                    for_each(some_books.begin(), some_books.end(), ShowReview);
                    break;
                }
                case 'u':
                {
                    sort(some_books.begin(), some_books.end(), worseThan);
                    cout << "Sorted by up rating:\nRating\tPrice\tBook\n";
                    for_each(some_books.begin(), some_books.end(), ShowReview);
                    break;
                }
                case 'd':
                {
                    sort(some_books.begin(), some_books.end(), betterThan);
                    cout << "Sorted by down rating:\nRating\tPrice\tBook\n";
                    for_each(some_books.begin(), some_books.end(), ShowReview);
                    break;
                }
                case 'p':
                {
                    sort(some_books.begin(), some_books.end(), worseprice);
                    cout << "Sorted by up price:\nRating\tPrice\tBook\n";
                    for_each(some_books.begin(), some_books.end(), ShowReview);
                    break;
                }
                case 'k':
                {
                    sort(some_books.begin(), some_books.end(), betterprice);
                    cout << "Sorted by down price:\nRating\tPrice\tBook\n";
                    for_each(some_books.begin(), some_books.end(), ShowReview);
                    break;
                }
                default:
                {
                    cout << "Wrong input! Please enter again!" << endl;
                    break;
                }
            }
            cout << "\nMenu:" << endl;
            cout << "o: show original books" << endl;
            cout << "a: show books by title" << endl;
            cout << "u: show books by up rating" << endl;
            cout << "d: show books by down rating" << endl;
            cout << "p: show books by up price" << endl;
            cout << "k: show books by down price" << endl;
            cout << "q: quit" << endl;
            cout << "input: ";
        }
    }
    else
    {
        cout << "No entries. ";
    }
    cout << "Bye.\n";

    return 0;
}

bool FillReview(shared_ptr<Review> & rr)
{
    rr =  shared_ptr<Review>(new Review);
    cout << "Enter book title(quit to quit): ";
    getline(cin, rr->title);
    if (rr->title == "quit")
        return false;
    cout << "Enter book rating: ";
    cin >> rr->rating;
    if (!cin)
        return false;
    cout << "Enter book price: ";
    cin >> rr->price;
    if (!cin)
        return false;
    
    while (cin.get() != '\n')
        continue;
    
    return true;
}

void ShowReview(const shared_ptr<Review> &rr)
{
    cout << rr->rating << "\t" << rr->price << "\t" << rr->title << endl;
}

bool worseThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    return r1->rating < r2->rating;
}

bool betterThan(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    return worseThan(r2, r1);
}

bool worseprice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    return r1->price < r2->price;
}

bool betterprice(const shared_ptr<Review> &r1, const shared_ptr<Review> &r2)
{
    return worseprice(r2, r1);
}