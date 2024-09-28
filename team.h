#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include <iostream>

// Оголошення класу FootballPlayer
class FootballPlayer
{
    std::string name;
    int number;
    int goals;
    int yellowCards;
    double salary;

public:
    FootballPlayer(std::string n = "Unknown", int num = 0, double sal = 0.0);

    std::string getName() const;
    void increaseGoals(int g);
    void addYellowCard();
    double getSalary() const;
    void displayStats() const;

    // Перевантажені методи
    void calculateSalary(int matchesPlayed);
    void calculateSalary(int matchesPlayed, int goalsScored);

    // Методи для запису/читання з файлу
    void saveToFile(std::ostream &os) const;
    void loadFromFile(std::istream &is);
};

// Оголошення класу FootballTeam
class FootballTeam
{
    std::string teamName;
    int wins;
    int losses;
    int rating;
    std::vector<FootballPlayer> players;

public:
    FootballTeam(std::string name = "Unknown");

    std::string getTeamName() const;
    void addPlayer(const FootballPlayer &player);
    void updateResults(int w, int l);
    int getRating() const;
    void displayTeamInfo() const;
    const FootballPlayer *findPlayerByName(const std::string &playerName) const;

    // Методи для запису/читання з файлу
    void saveToFile(std::ostream &os) const;
    void loadFromFile(std::istream &is);
};

// Оголошення функції порівняння строк без урахування регістру
bool compareStringsIgnoreCase(const std::string &str1, const std::string &str2);

#endif
