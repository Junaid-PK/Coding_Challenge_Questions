#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct StringMeeting {
  string start;
  string end;
};

int stringToMinutes(string time) {
    // time is in 9:00 format
    // split by:
    int hours = stoi(time.substr(0, time.find(":")));
    int minutes = stoi(time.substr(time.find(":") + 1));
    return hours * 60 + minutes;

}

string minutesToString(int timeInMinutes) {
    int hours = timeInMinutes / 60;
    int minutes = timeInMinutes % 60;
    string hoursString = to_string(hours);
    string minutesString = to_string(minutes);
    if (minutes < 10) {
        minutesString = "0" + minutesString;
    }
    return hoursString + ":" + minutesString;
}

vector<StringMeeting> updateCalendar(vector<StringMeeting> calendar, StringMeeting dailyBounds) {
    // update the calendar to include the daily bounds
    vector<StringMeeting> updatedCalendar = calendar;
    updatedCalendar.insert(updatedCalendar.begin(), StringMeeting{"00:00", dailyBounds.start});
    updatedCalendar.push_back(StringMeeting{dailyBounds.end, "23:59"});
    return updatedCalendar;
}

vector<StringMeeting> mergeCalendars(vector<StringMeeting> calendar1, vector<StringMeeting> calendar2) {
    // merge the calendars together
    vector<StringMeeting> mergedCalendar;
    int i = 0, j = 0;
    while (i < calendar1.size() && j < calendar2.size()) {
        StringMeeting meeting1 = calendar1[i];
        StringMeeting meeting2 = calendar2[j];
        if (stringToMinutes(meeting1.start) < stringToMinutes(meeting2.start)) {
            mergedCalendar.push_back(meeting1);
            i++;
        } else {
            mergedCalendar.push_back(meeting2);
            j++;
        }
    }
    while (i < calendar1.size()) {
        mergedCalendar.push_back(calendar1[i]);
        i++;
    }
    while (j < calendar2.size()) {
        mergedCalendar.push_back(calendar2[j]);
        j++;
    }
    return mergedCalendar;
}


vector<StringMeeting> getMatchingAvailabilities(vector<StringMeeting> flattenedCalendar, int meetingDuration) {
    // find the available meeting times by comparing the merged calendar to the meeting duration
    vector<StringMeeting> matchingAvailabilities;
    for (int i = 1; i < flattenedCalendar.size(); i++) {
        int start = stringToMinutes(flattenedCalendar[i - 1].end);
        int end = stringToMinutes(flattenedCalendar[i].start);
        int availabilityDuration = end - start;
        if (availabilityDuration >= meetingDuration) {
            matchingAvailabilities.push_back(StringMeeting{minutesToString(start), minutesToString(end)});
        }
    }
    return matchingAvailabilities;
}
vector<StringMeeting> flattenCalendar(vector<StringMeeting> mergedCalendar) {
    // Flatten the calendar by removing nested meetings
    vector<StringMeeting> flattenedCalendar = {mergedCalendar[0]};
    for (int i = 1; i < mergedCalendar.size(); i++) {
        StringMeeting currentMeeting = mergedCalendar[i];
        StringMeeting previousMeeting = flattenedCalendar[flattenedCalendar.size() - 1];
        StringMeeting newPreviousMeeting = {"", ""};
        if (stringToMinutes(currentMeeting.start) <= stringToMinutes(previousMeeting.end)) {
            newPreviousMeeting.start = previousMeeting.start;
            newPreviousMeeting.end = max(previousMeeting.end, currentMeeting.end);
            flattenedCalendar[flattenedCalendar.size() - 1] = newPreviousMeeting;
        } else {
            flattenedCalendar.push_back(currentMeeting);
        }
    }
    return flattenedCalendar;
}



vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration) {
    // update the calendar to include the daily bounds
    vector<StringMeeting> updatedCalendar1 = updateCalendar(calendar1, dailyBounds1);
    vector<StringMeeting> updatedCalendar2 = updateCalendar(calendar2, dailyBounds2);

    // merge the calendars together
    vector<StringMeeting> mergedCalendar = mergeCalendars(updatedCalendar1, updatedCalendar2);

    // Flatten the calendar by removing nested meetings
    vector<StringMeeting> flattenedCalendar = flattenCalendar(mergedCalendar);

    // find the available meeting times by comparing the merged calendar to the meeting duration
    vector<StringMeeting> matchingAvailabilities = getMatchingAvailabilities(flattenedCalendar, meetingDuration);

    return matchingAvailabilities;

}
int main() {
    vector<StringMeeting> calendar1 = {{"9:00", "10:30"}, {"12:00", "13:00"}, {"16:00", "18:00"}};
    StringMeeting dailyBounds1 = {"9:00", "20:00"};
    vector<StringMeeting> calendar2 = {{"10:00", "11:30"}, {"12:30", "14:30"}, {"14:30", "15:00"}, {"16:00", "17:00"}};
    StringMeeting dailyBounds2 = {"10:00", "18:30"};
    int meetingDuration = 30;
    vector<StringMeeting> expected = {{"11:30", "12:00"}, {"15:00", "16:00"}, {"18:00", "18:30"}};
    vector<StringMeeting> actual = calendarMatching(calendar1, dailyBounds1, calendar2, dailyBounds2, meetingDuration);
    for (int i = 0; i < actual.size(); i++) {
        cout << actual[i].start << " " << actual[i].end << endl;
    }
    return 0;
}
