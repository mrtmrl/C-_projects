#include <iostream>
#include <cmath>
using namespace std;

class Exam {
protected:
    string name;
    int totalScore;
    int day, month, year;
public:
    Exam(string n, int d, int m, int y) {
        name = n;
        day = d;
        month = m;
        year = y;
    }
    virtual void calculate() = 0;
    virtual void print() = 0;
};

class TOEFL : public Exam {
private:
    int reading, listening, speaking, writing;
public:
    TOEFL(string n, int d, int m, int y, int r, int l, int s, int w) : Exam(n, d, m, y) {
        reading = r;
        listening = l;
        speaking = s;
        writing = w;
    }
    void calculate() {
        totalScore = reading + listening + speaking + writing;
    }
    void print() {
        cout << "Name: " << name << "\tExam: TOEFL\tDate of exam: " << day << "/" << month << "/" << year << endl;
        cout << "Reading: " << reading << "\tListening: " << listening << "\tSpeaking: " << speaking << "\tWriting: " << writing << endl;
        cout << "Total score: " << totalScore << endl;
    }
};

class IELTS : public Exam {
private:
    int listening, reading, writing, speaking;
    double listeningScore, readingScore, writingScore, speakingScore, averageScore;
public:
    IELTS(string n, int d, int m, int y, int l, int r, int w, int s) : Exam(n, d, m, y) {
        listening = l;
        reading = r;
        writing = w;
        speaking = s;
    }
    void calculate() {
        listeningScore = (double)listening * 9 / 40;
        readingScore = (double)reading * 9 / 40;
        writingScore = (double)writing * 9 / 40;
        speakingScore = (double)speaking * 9 / 40;
        averageScore = round((listeningScore + readingScore + writingScore + speakingScore) / 4 * 2) / 2.0;
        totalScore = averageScore;
    }
    void print() {
        cout << "Name: " << name << "\tExam: IELTS\tDate of exam: " << day << "/" << month << "/" << year << endl;
        cout << "Reading: " << readingScore << "\tListening: " << listeningScore << "\tSpeaking: " << speakingScore << "\tWriting: " << writingScore << endl;
        cout << "Total score: " << totalScore << endl;
    }
};

class Yokdil : public Exam {
private:
    int correctAnswers;
public:
    Yokdil(string n, int d, int m, int y, int c) : Exam(n, d, m, y) {
        correctAnswers = c;
    }
    void calculate() {
        totalScore = round(correctAnswers * 1.25);
    }
    void print() {
        cout << "Name: " << name << "\tExam: Yokdil\tDate of exam: " << day << "/" << month << "/" << year << endl;
        cout << "Total score: " << totalScore << endl;
    }
};

int main() {
    string name;
    int day, month, year, score, reading, listening, speaking, writing;
    char exam_type;

    // First student
    cout << "Enter name of student: ";
    getline(cin, name);
    cout << "Enter date of exam: ";
    cin >> day >> month >> year;

    cout << "Enter T for TOEFL, I for IELTS or Y for Yokdil: ";
    cin >> exam_type;

    Exam* exam = nullptr;

    if (exam_type == 'T') {
        cout << "Enter score for Reading: ";
        cin >> reading;
        cout << "Enter score for Listening: ";
        cin >> listening;
        cout << "Enter score for Speaking: ";
        cin >> speaking;
        cout << "Enter score for Writing: ";
        cin >> writing;

        exam = new TOEFL(name, day, month, year, reading, listening, speaking, writing);
    }
    else if (exam_type == 'I') {
        cout << "Enter score for Reading: ";
        cin >> reading;
        cout << "Enter score for Listening: ";
        cin >> listening;
        cout << "Enter score for Speaking: ";
        cin >> speaking;
        cout << "Enter score for Writing: ";
        cin >> writing;

        exam = new IELTS(name, day, month, year, reading, listening, speaking, writing);
    }
    else if (exam_type == 'Y') {
        cout << "Enter number of correct answers: ";
        cin >> score;

        exam = new Yokdil(name, day, month, year, score);
    }
    else {
        cout << "Invalid exam type." << endl;
        return 1;
    }

    exam->print();

    delete exam;

    // Second student
    // ...

    // Third student
    // ...

    return 0;
}
