/*
 *
 * 7-3_Project_Three__Christan_Harper.cpp
 *
 * Christan Harper
 * Due: 12-15-2024
 *
 * CS-210-15324
 * Prof. Faisal Shakeel
 * 7-3 Project Three: Grocery Tracker
 *
 */

#include <iostream> // for cin and cout.
#include <string> // for strings.
#include <fstream> // for file creation, reading, and writing.

using namespace std; // for std::

class GroceryTracker {
private:
    struct Node {
        string item; // stores name of grocery item.
        int frequency; // frequency of item purchased.
        Node* next; // points to next node.
    };

    Node* head; // pointer to first node.

    int findItemFrequency(const string& item) const { // searches for item in list.
        Node* current = head; // start at top of list.
        while (current != nullptr) { // go through all nodes.
            if (current->item == item) { return current->frequency; } // if item found, return frequency.
            current = current->next; // move to next node.
        }
        return 0; // item not found.
    }

    void loadData(const string& filename) { // loads items from input file for list.
        ifstream file(filename); // opens input file.
        string item; // stores each item.
        while (file >> item) { // read each item.
            Node* current = head; // begin at top of list.
            while (current != nullptr) { // check if item exists.
                if (current->item == item) {
                    current->frequency++; // increment frequency.
                    break;
                }
                current = current->next; // move to next node.
            }
            if (current == nullptr) { head = new Node{ item, 1, head }; } // if item not found, add node to top.
        }
        file.close();
    }

    void backupData(const string& filename) const { // saves data to backup file.
        ofstream file(filename); // open output file.
        Node* current = head; // start at top of list.
        while (current != nullptr) { // go through all nodes.
            file << current->item << " " << current->frequency << endl; // write item and frequency to file.
            current = current->next; // move to next node.
        }
        file.close();
    }

public:
    GroceryTracker(const string& filename) // constructor.
        : head(nullptr) { // initialize head to null.
        loadData(filename); // load data from input file
        backupData("frequency.dat"); // backup data to frequency.dat.
    }

    ~GroceryTracker() { // deconstructor.
        Node* current = head; // start at top of list.
        while (current != nullptr) { // go through all nodes.
            Node* temp = current; // store current node temp.
            current = current->next; // move to next node.
            delete temp; // delete temp node.
        }
    }

    void searchItem(const string& item) const { // searches for item and displays frequency.
        int frequency = findItemFrequency(item); // get item frequency.
        cout << item << " were purchased " << frequency << " time(s).\n";
    }

    void printFrequencies() const { // prints all items and frequencies.
        Node* current = head; // start at top of list.
        cout << "\nITEM FREQUENCIES:\n";
        while (current != nullptr) { // go through all nodes.
            cout << current->item << " " << current->frequency << endl;
            current = current->next; // move to next node.
        }
    }

    void printHistogram() const {
        Node* current = head; // start at top of list.
        cout << "\nITEM HISTOGRAM:\n";
        while (current != nullptr) { // go through all nodes.
            cout << current->item << " ";
            for (int i = 0; i < current->frequency; i++) cout << "*"; // print asterisks, frequency times.
            cout << endl;
            current = current->next; // move to next node.
        }
    }

    void displayMenu() const { // display main menu.
        for (int i = 0; i < 40; i++) { cout << '='; }
        cout << "\n       Grocery Tracker Main Menu\n";
        for (int i = 0; i < 40; i++) { cout << '='; }
        cout << "\n1. Item Search\n";
        cout << "2. Item Frequencies\n";
        cout << "3. Histogram\n";
        cout << "4. Exit\n";
        for (int i = 0; i < 40; i++) { cout << '-'; }
        cout << endl;
    }

    void runApp() {
        int choice = 0; // user input.
        while (choice != 4) { // loop until exit chosen.
            displayMenu(); // display main menu
            cout << "Make a Selection: ";
            cin >> choice; // user input.

            switch (choice) {
            case 1: { // item search.
                for (int i = 0; i < 50; i++) { cout << endl; } // clears screen.
                cout << "Enter the item to search for: ";
                string item;
                cin >> item;
                searchItem(item);
                break;
            }
            case 2: // item frequencies.
                for (int i = 0; i < 50; i++) { cout << endl; } // clears screen.
                printFrequencies();
                break;
            case 3: // histogram.
                for (int i = 0; i < 50; i++) { cout << endl; } // clears screen.
                printHistogram();
                break;
            case 4: // exit
                cout << "Exited program." << endl;
                break;
            default: // error.
                for (int i = 0; i < 50; i++) { cout << endl; } // clears screen.
                cout << "Error. Please choose an option 1-4." << endl;
            }
        }
    }
};

int main() {
    GroceryTracker gt("CS210_Project_Three_Input_File.txt"); // load data with tracker.
    gt.runApp(); // run app with tracker.
    return 0;
}