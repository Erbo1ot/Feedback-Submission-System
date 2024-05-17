#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

struct Feedback {
    string app;
    string person;
    string text;
    string date;
    int rating;
};

Feedback collectFeedback() {
    Feedback feedback;
    cout << "Enter app name: ";
    getline(cin, feedback.app);
    cout << "Enter your name: ";
    getline(cin, feedback.person);
    cout << "Enter feedback text: ";
    getline(cin, feedback.text);
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, feedback.date);
    cout << "Enter rating (1-5): ";
    cin >> feedback.rating;
    cin.ignore();
    return feedback;
}

void displayFeedback(const vector<Feedback>& feedbacks) {
    if (feedbacks.empty()) {
        cout << "No feedback submitted yet." << endl;
        return;
    }

    cout << "\n--- All Feedback Entries ---" << endl;
    for (const auto& feedback : feedbacks) {
        cout << "App: " << feedback.app << endl;
        cout << "Name: " << feedback.person << endl;
        cout << "Date: " << feedback.date << endl;
        cout << "Rating: " << feedback.rating << endl;
        cout << "Feedback: " << feedback.text << endl;
        cout << "---------------------------" << endl;
    }
}

void displayReport(const vector<Feedback>& feedbacks) {
    if (feedbacks.empty()) {
        cout << "No feedback submitted yet." << endl;
        return;
    }

    map<string, pair<int, int>> appRatings;
    for (const auto& feedback : feedbacks) {
        appRatings[feedback.app].first += feedback.rating;
        appRatings[feedback.app].second++;
    }

    cout << "\n--- Summary Report ---" << endl;
    for (const auto& app : appRatings) {
        double averageRating = static_cast<double>(app.second.first) / app.second.second;
        cout << app.first << ": " << fixed << setprecision(1) << averageRating << endl;
    }

    cout << "\nTotal feedback: " << feedbacks.size() << " people" << endl;
    cout << "Total apps: " << appRatings.size() << " app(s)" << endl;
}

int main() {
    vector<Feedback> feedbacks;
    char choice;

    do {
        cout << "\nFeedback Submission System\n";
        cout << "1. Submit Feedback\n";
        cout << "2. Display All Feedback\n";
        cout << "3. Display Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                Feedback feedback = collectFeedback();
                feedbacks.push_back(feedback);
                cout << "Feedback submitted successfully.\n";
                break;
            }
            case '2':
                displayFeedback(feedbacks);
                break;
            case '3':
                displayReport(feedbacks);
                break;
            case '4':
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != '4');

    return 0;
}
