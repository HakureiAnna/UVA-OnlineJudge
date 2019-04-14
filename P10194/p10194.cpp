#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

struct Team {
  string name;
  int wins;
  int ties;
  int losses;
  int goalsScored;
  int goalsAgainst;
};

bool compare(Team a, Team b);
void processGame(vector<Team> *teams, string game);
void printTeams(vector<Team> *teams);
void parseGame(string line, string *teamA, string *teamB, int *pointA, int *pointB);
void processTeam(vector<Team>::iterator team, int point, int pointAgainst);

int main() {
  string tournament;
  vector<Team> teams;
  int n;
  int numTeams;
  int numGames;
  Team team;
  string line;

  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; ++i) {
    teams.clear();

    getline(cin, tournament);
    cin >> numTeams;
    cin.ignore();
    for (int j = 0; j < numTeams; ++j) {
      getline(cin, line);
      team.name = line;
      team.wins = 0;
      team.ties = 0;
      team.losses = 0;
      team.goalsScored = 0;
      team.goalsAgainst = 0;
      teams.push_back(team);
    }

    cin >> numGames;
    cin.ignore();
    for (int j = 0; j < numGames; ++j) {
      getline(cin, line);
      processGame(&teams, line);
    }

    sort(teams.begin(), teams.end(), compare);

    cout << tournament << endl;
    printTeams(&teams);
    if (i < n-1)
      cout << endl;
  }
  return 0;
}

bool compare(Team a, Team b) {
  int pointsA = a.wins * 3 + a.ties;
  int pointsB = b.wins * 3 + b.ties;
  if (pointsA != pointsB)
    return pointsA > pointsB;
  if (a.wins != b.wins)
    return a.wins > b.wins;

  int goalDiffA = a.goalsScored - a.goalsAgainst;
  int goalDiffB = b.goalsScored - b.goalsAgainst;
  if (goalDiffA != goalDiffB)
    return goalDiffA > goalDiffB;
  if (a.goalsScored != b.goalsScored)
    return a.goalsScored > b.goalsScored;

  int gamesA = a.wins + a.ties + a.losses;
  int gamesB = b.wins + b.ties + b.losses;
  if (gamesA != gamesB)
    return gamesA < gamesB;

  char buffer[32];
  string nameA, nameB;
  int sLen, i;
  sLen = a.name.length();
  for (i = 0; i < sLen; ++i)
    buffer[i] = tolower(a.name[i]);
  buffer[i] = '\0';
  nameA = string(buffer);

  sLen = b.name.length();
  for (i = 0; i < sLen; ++i)
    buffer[i] = tolower(b.name[i]);
  buffer[i] = '\0';
  nameB = string(buffer);
  return nameA < nameB;
}

void processGame(vector<Team> *teams, string game) {
  string teamA, teamB;
  int pointA, pointB;
  bool foundA = false, foundB = false;

  parseGame(game, &teamA, &teamB, &pointA, &pointB);
  //cout << teamA << endl;
  //cout << teamB << endl;

  for (vector<Team>::iterator itor = teams->begin(); itor != teams->end(); ++itor) {
    if (!itor->name.compare(teamA)) {
      //cout << itor->name << "==" << teamA << endl;
      processTeam(itor, pointA, pointB);
      foundA = true;
    } else if (!itor->name.compare(teamB)) {
      //cout << itor->name << "==" << teamB << endl;
      processTeam(itor, pointB, pointA);
      foundB = true;
    }

    if (foundA && foundB) {
      //cout << "processed" << endl;
      break;
    }
  }
}

void printTeams(vector<Team> *teams) {
  int i = 1;

  for (vector<Team>::iterator itor = teams->begin(); itor != teams->end(); ++itor) {
    cout << i++ << ") " << itor->name << " "
      << itor->wins*3 + itor->ties << "p, "
      << itor->wins + itor->ties + itor->losses << "g ("
      << itor->wins << "-" << itor->ties << "-" << itor->losses << "), "
      << itor->goalsScored - itor->goalsAgainst << "gd ("
      << itor->goalsScored << "-" << itor->goalsAgainst << ")\n";
  }
}

void parseGame(string line, string *teamA, string *teamB, int *pointA, int *pointB) {
  char str[256];
  int val = 0;
  int sLen = line.length();
  int j = 0;
  int state = 0;
  for (int i = 0; i < sLen; ++i) {
    switch (state) {
      case 0:
        if (line[i] != '#')
          str[j++] = line[i];
        else {
          str[j] = '\0';
          *teamA = string(str);
          j = 0;
          state = 1;
        }
        break;
      case 1:
        if (line[i] != '@') {
          val *= 10;
          val += line[i] - '0';
        } else {
          *pointA = val;
          state = 2;
          val = 0;
        }
        break;
      case 2:
        if (line[i] != '#') {
          val *= 10;
          val += line[i] - '0';
        } else {
          *pointB = val;
          state = 3;
          val = 0;
        }
       break;
      case 3:
        str[j++] = line[i];
       break;
    }
  }
  str[j] = '\0';
  *teamB = string(str);
}

void processTeam(vector<Team>::iterator team, int point, int pointAgainst) {
  team->goalsScored += point;
  team->goalsAgainst += pointAgainst;
  if (point > pointAgainst)
    team->wins++;
  else if (point < pointAgainst)
    team->losses++;
  else
    team->ties++;
}
