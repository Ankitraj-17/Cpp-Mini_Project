#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Book {
  int id;
  string title;
  string author;
  bool isIssued;
};

vector<Book> library;

// Helper function to print a decorative line
void printLine(char ch = '=', int length = 60) {
  cout << string(length, ch) << endl;
}

// Display the header banner
void displayHeader() {
  cout << "\n";
  printLine('-');
  cout << "-" << setw(40) << "LIBRARY MANAGEMENT SYSTEM" << setw(19) << "-"
       << endl;
  printLine('-');
}

// Display the menu
void displayMenu() {
  cout << "\n";
  printLine('-');
  cout << "  [1] Add New Book\n";
  cout << "  [2] Issue Book\n";
  cout << "  [3] Return Book\n";
  cout << "  [4] Display All Books\n";
  cout << "  [5] Search Book\n";
  cout << "  [6] Delete Book\n";
  cout << "  [7] Exit\n";
  printLine('-');
  cout << "  Enter your choice: ";
}

// Check if a book ID already exists
bool bookExists(int id) {
  for (const auto &book : library) {
    if (book.id == id)
      return true;
  }
  return false;
}

// Find book index by ID, returns -1 if not found
int findBookIndex(int id) {
  for (int i = 0; i < library.size(); i++) {
    if (library[i].id == id)
      return i;
  }
  return -1;
}

void addBook() {
  Book newBook;
  cout << "\n--- Add New Book ---\n";

  cout << "Enter Book ID: ";
  cin >> newBook.id;

  // Check for duplicate ID
  if (bookExists(newBook.id)) {
    cout << "Error: A book with ID " << newBook.id << " already exists!\n";
    return;
  }

  cin.ignore(); // Clear newline from buffer
  cout << "Enter Book Title: ";
  getline(cin, newBook.title);
  cout << "Enter Book Author: ";
  getline(cin, newBook.author);
  newBook.isIssued = false;
  library.push_back(newBook);

  cout << "\n>> Book '" << newBook.title << "' added successfully!\n";
}

void issueBook() {
  if (library.empty()) {
    cout << "\nNo books in the library to issue.\n";
    return;
  }

  int id;
  cout << "\n--- Issue Book ---\n";
  cout << "Enter Book ID to issue: ";
  cin >> id;

  int index = findBookIndex(id);
  if (index != -1) {
    if (library[index].isIssued) {
      cout << "\nError: Book '" << library[index].title
           << "' is already issued.\n";
    } else {
      library[index].isIssued = true;
      cout << "\n>> Book '" << library[index].title
           << "' issued successfully!\n";
    }
  } else {
    cout << "\nError: Book with ID " << id << " not found.\n";
  }
}

void returnBook() {
  if (library.empty()) {
    cout << "\nNo books in the library.\n";
    return;
  }

  int id;
  cout << "\n--- Return Book ---\n";
  cout << "Enter Book ID to return: ";
  cin >> id;

  int index = findBookIndex(id);
  if (index != -1) {
    if (!library[index].isIssued) {
      cout << "\nError: Book '" << library[index].title
           << "' was not issued.\n";
    } else {
      library[index].isIssued = false;
      cout << "\n>> Book '" << library[index].title
           << "' returned successfully!\n";
    }
  } else {
    cout << "\nError: Book with ID " << id << " not found.\n";
  }
}

void searchBook() {
  if (library.empty()) {
    cout << "\nNo books in the library to search.\n";
    return;
  }

  string keyword;
  cout << "\n--- Search Book ---\n";
  cin.ignore();
  cout << "Enter title or author to search: ";
  getline(cin, keyword);

  // Convert keyword to lowercase for case-insensitive search
  string lowerKeyword = keyword;
  for (char &c : lowerKeyword)
    c = tolower(c);

  vector<Book> results;
  for (const auto &book : library) {
    string lowerTitle = book.title;
    string lowerAuthor = book.author;
    for (char &c : lowerTitle)
      c = tolower(c);
    for (char &c : lowerAuthor)
      c = tolower(c);

    if (lowerTitle.find(lowerKeyword) != string::npos ||
        lowerAuthor.find(lowerKeyword) != string::npos) {
      results.push_back(book);
    }
  }

  if (results.empty()) {
    cout << "\nNo books found matching '" << keyword << "'.\n";
  } else {
    cout << "\n>> Found " << results.size() << " book(s):\n\n";
    cout << left << setw(8) << "ID" << setw(25) << "Title" << setw(20)
         << "Author" << setw(12) << "Status" << endl;
    printLine('-');
    for (const auto &book : results) {
      cout << left << setw(8) << book.id << setw(25) << book.title << setw(20)
           << book.author << setw(12)
           << (book.isIssued ? "Issued" : "Available") << endl;
    }
  }
}

void deleteBook() {
  if (library.empty()) {
    cout << "\nNo books in the library to delete.\n";
    return;
  }

  int id;
  cout << "\n--- Delete Book ---\n";
  cout << "Enter Book ID to delete: ";
  cin >> id;

  int index = findBookIndex(id);
  if (index != -1) {
    string deletedTitle = library[index].title;
    library.erase(library.begin() + index);
    cout << "\n>> Book '" << deletedTitle << "' deleted successfully!\n";
  } else {
    cout << "\nError: Book with ID " << id << " not found.\n";
  }
}

void displayBooks() {
  if (library.empty()) {
    cout << "\nNo books in the library.\n";
    return;
  }

  // Count available and issued books
  int available = 0, issued = 0;
  for (const auto &book : library) {
    if (book.isIssued)
      issued++;
    else
      available++;
  }

  cout << "\n";
  printLine('=');
  cout << "                    LIBRARY INVENTORY\n";
  cout << "       Total: " << library.size() << " | Available: " << available
       << " | Issued: " << issued << endl;
  printLine('=');

  cout << left << setw(8) << "ID" << setw(25) << "Title" << setw(20) << "Author"
       << setw(12) << "Status" << endl;
  printLine('-');

  for (const auto &book : library) {
    cout << left << setw(8) << book.id << setw(25) << book.title << setw(20)
         << book.author << setw(12) << (book.isIssued ? "Issued" : "Available")
         << endl;
  }
  printLine('=');
}

int main() {
  int choice;

  displayHeader();

  do {
    displayMenu();
    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\n>> Invalid input! Please enter a number (1-7).\n";
      continue;
    }

    switch (choice) {
    case 1:
      addBook();
      break;
    case 2:
      issueBook();
      break;
    case 3:
      returnBook();
      break;
    case 4:
      displayBooks();
      break;
    case 5:
      searchBook();
      break;
    case 6:
      deleteBook();
      break;
    case 7:
      cout << "\n";
      printLine('-');
      cout << "    Thank you for using Library Management System!\n";
      cout << "                    Goodbye!\n";
      printLine('-');
      break;
    default:
      cout << "\n>> Invalid choice! Please enter 1-7.\n";
    }
  } while (choice != 7);

  return 0;
}
