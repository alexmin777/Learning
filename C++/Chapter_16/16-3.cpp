#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cctype>

void file_words(std::vector<std::string> &);

int main()
{
    using namespace std;

    char play;
    vector<string> wordlist;
    
    srand(time(0));
    file_words(wordlist);

    cout << "Will you play a word game? <y/n>";
    cin >> play;
    play = tolower(play);
    while ('y' == play)
    {
        string target = wordlist[rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << "letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }
            else
            {
                cout << "Good guess!\n";
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";
        cout << "Will you play another? <y/n>";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye!\n";

    return 0;
}

void file_words(std::vector<std::string> & wordlist)
{
    using namespace std;

    ifstream file;
    string temp;

    file.open("wordlist");
    if (!file.is_open())
    {
        cout << "Can't open file wordlist" << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        while (file >> temp)
            wordlist.push_back(temp);
    }

    if (wordlist.empty())
    {
        cout << "No word in wordlist!" << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
}