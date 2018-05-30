#include <iostream>
#include <sstream>

using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Welcome to Amogh's policy debate citation creator v1 -- please select an option from the list below: ";
  cout << endl;
  cout 
    << "1. New Citation" << endl
    << "2. Quit" << endl;
    
  cin >> choice;
  
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
  
}

void printCitation(string firstName, string lastName, string month, string day, string year, 
string authorInfo, string sourceLink, string userName, string journalInfo, string articleTitle, string fullDate){

    if (lastName != ""){
        cout << lastName << " '";
    }
    
    else if (lastName == ""){
        cout << "No Author" << " '";
    }
    
    if (year != ""){
        cout << year.at(2) << year.at(3);
    }

    else if (year == ""){
        cout << "No Date";
    }

    
    if (authorInfo != ""){
        cout << " – " << authorInfo;
    }
    
    cout << " (";
    
    if (firstName != ""){
        cout << firstName << ", ";
    }
    
    if (journalInfo != ""){
        articleTitle = articleTitle + ",";
        cout <<  "\"" << articleTitle << "\" ";
        cout << journalInfo << ", ";

    }
    
    else if (journalInfo == ""){
        cout <<  "\"" << articleTitle << "\"";
    }
    
    if (fullDate != "No Date"){
        cout << ", " << month << " " << day << ", " << year;
    }
    
    if (sourceLink != ""){
        cout << ", Accessed From: " << sourceLink;
    }
    
    cout << ")";
    
    if (userName != ""){
        cout << "//" << userName;
    }
    
    return;
}

int main() {

  int choice = menu();
  
  string authorFullName;
  string firstName;
  string lastName;
  
  string fullDate;
  string month;
  string day;
  string year;
  
  string articleTitle;
  string journalInfo;
  string authorInfo;
  string sourceLink;
  string userName;

  while (choice != 2) {
      
    if (choice == 1) {
    
        cout << "Enter the first and last name of the author. If the author is unknown, type none." << endl;
        getline(cin, authorFullName);
        
        if (authorFullName == "none" || authorFullName == "NONE"){
            authorFullName = "No Author";
        }
        
        else {
            istringstream nameParser(authorFullName);
            nameParser >> firstName;
            nameParser >> lastName;        
        }
        
        cout << endl;
        
        cout << "Enter author credentials/information. If information is unknown, type none." << endl;
        getline(cin, authorInfo);
        
        if (authorInfo == "none" || authorInfo == "NONE"){
            authorInfo = "";
        }
        
        cout << endl;
        
        cout << "Enter the date of publication in the format MONTH [space] DAY [space] YEAR. If the date is unknown, type none." << endl;
        getline(cin, fullDate);
        
        if (fullDate == "none" || fullDate == "NONE"){
            fullDate = "No Date";
        }
        
        else {
            istringstream dateParser(fullDate);
            dateParser >> month;
            dateParser >> day; 
            dateParser >> year;
        }
        
        cout << endl;
        
        
        cout << "Enter title of article/book." << endl;
        getline(cin, articleTitle);
        
        cout << endl;
        
        cout << "Enter information about the journal/publication. If not available, type none." << endl;
        getline(cin, journalInfo);
        
        if (journalInfo == "none" || journalInfo == "NONE"){
            journalInfo = "";
        }  
        
        
        cout << endl;
        
        cout << "Paste the link for the source. If source is not online, type none." << endl;
        getline(cin, sourceLink);
        
        if (sourceLink == "none" || sourceLink == "NONE"){
            sourceLink = "";
        }  
        
        
        cout << endl;
        
        string include;
        cout << "Would you like to include credits (initials/name) for cutting the card? Enter Y or N." << endl;
        getline(cin, include);
        
        if (include == "Yes" || include == "Y" || include == "yes"){
            cout << "Enter the name/initials that you would like included in the citation." << endl;
            getline(cin, userName);
        }
        
        else {
            userName = "";
        }
      
        cout << endl;
        cout << "Citation generated: " << endl;
        cout << endl;
  
        printCitation(firstName, lastName, month, day, year, authorInfo, sourceLink, userName, journalInfo, articleTitle, fullDate);
        cout << endl;
        cout << endl;
    } 

    choice = menu();
    
  }
  
  
  return 0;
}