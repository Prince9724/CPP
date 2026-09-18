#include <iostream>
#include <iomanip>
using namespace std;

class TimeConverter
{
public:

    // Convert seconds to HH:MM:SS
    void secondsToTime(int totalSeconds)
    {
        int hours = totalSeconds / 3600;
        int remainingSeconds = totalSeconds % 3600;

        int minutes = remainingSeconds / 60;
        int seconds = remainingSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }
 
    int timeToSeconds(int hours, int minutes, int seconds)
    {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

        return totalSeconds;
    }
};

int main()
{
    TimeConverter converter;
    int choice;

    cout << "===== TIME CONVERTER =====" << endl;
    cout << "1. Seconds to HH:MM:SS" << endl;
    cout << "2. HH:MM:SS to Seconds" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int totalSeconds;

        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        if (totalSeconds < 0)
        {
            cout << "Please enter a valid positive value." << endl;
        }
        else
        {
            converter.secondsToTime(totalSeconds);
        }
    }
    else if (choice == 2)
    {
        int hours, minutes, seconds;

        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        if (hours < 0 || minutes < 0 || seconds < 0 ||
            minutes >= 60 || seconds >= 60)
        {
            cout << "Invalid time format!" << endl;
        }
        else
        {
            int totalSeconds =
                converter.timeToSeconds(hours, minutes, seconds);

            cout << "Total seconds: " << totalSeconds << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}