#include <iostream >
using namespace std;
int main() {
double num1 , num2;
int choice;
char confirm;
do {

cout << "Enter first number: ";
cin >> num1;
cout << "Enter second number: ";
cin >> num2;
cout << "\nSelect an operation:" << endl;
cout << "1. Addition (+)" << endl;
cout << "2. Subtraction (-)" << endl;
cout << "3. Multiplication (*)" << endl;
cout << "4. Division (/)" << endl;
cout << "Choice: ";
cin >> choice;
if (choice == 1)
cout << "Result: " << num1 + num2 << endl;
else if (choice == 2)
cout << "Result: " << num1 - num2 << endl;
else if (choice == 3)
cout << "Result: " << num1 * num2 << endl;
else if (choice == 4) {
if (num2 != 0)
cout << "Result: " << num1 / num2 << endl;
else
cout << "Error: Division by zero!" << endl;
}
else
cout << "Invalid selection!" << endl;
cout << "\nDo you want to perform another calculation? (y/n): ";
cin >> confirm;
} while (confirm == 'y' || confirm == 'Y');
cout << "Thank you for using the calculator. Goodbye!" << endl;
return 0;
}
