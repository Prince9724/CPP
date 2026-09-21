#include <iostream>
using namespace std;
class Train
{
    int no;
    string name, source, destination, time;

public:
    static int trainCount;
    Train()
    {
        this->name = "";
        this->source = "";
        this->destination = "";
        this->time = "";
        this->no = 0;
    }

    void setTrain()
    {
        cout << "Enter train number :";
        cin >> this->no;
        cout << "Enter train name :";
        cin >> this->name;
        cout << "Enter train source :";
        cin >> this->source;
        cout << "Enter train destination :";
        cin >> this->destination;
        cout << "Enter train time :";
        cin >> this->time;
        cout << endl;
    }

    void getTrain()
    {
        cout << endl
             << "Train-No : " << this->no << endl;
        cout << "Train-Name : " << this->name << endl;
        cout << "Train-Source : " << this->source << endl;
        cout << "Train-Destination : " << this->destination << endl;
        cout << "Train-Time : " << this->time << endl
             << endl;
    }

    int getTrainNo()
    {
        return this->no;
    }
};

int Train::trainCount = 0;

int main()
{
    Train train[100];
    bool isRunning = true;

    while (isRunning)
    {
        int input;
        cout << endl
             << "------Welcome to train booking system--------" << endl;
        cout << "Enter 1 To Add New Train " << endl;
        cout << "Enter 2 To See All Train " << endl;
        cout << "Enter 3 To Search Train By Name " << endl;
        cout << "Enter 4 To Exit" << endl
             << endl;
        cout << "Enter your input :";
        cin >> input;
        cout << endl;

        switch (input)
        {
        case 1:
            train[Train::trainCount].setTrain();
            Train::trainCount++;
            break;
        case 2:
            for (int i = 0; i < Train::trainCount; i++)
            {
                train[i].getTrain();
            }
            break;
        case 3:
        {
            int searchNo;
            bool found = false;

            cout << "Enter train number to search : ";
            cin >> searchNo;

            for (int i = 0; i < Train::trainCount; i++)
            {
                if (train[i].getTrainNo() == searchNo)
                {
                    train[i].getTrain();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Train not found!" << endl;
            }

            break;
        }
        case 4:
            isRunning = false;
            cout << "Thank You For Visiting ";
        }
    }
    return 0;
}