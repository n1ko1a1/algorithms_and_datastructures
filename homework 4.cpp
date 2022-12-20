#include<iostream>

using namespace std;

int main()
{
	char message[100], ch;
	int i, key;
	cout << "Enter a message to encrypt: ";
	cin.getline(message, 100);
	cout << "Enter the offset step: ";
	cin >> key;
	for (i = 0; message[i] != '\0'; ++i) {
		ch = message[i];
		if (ch >= 'r' && ch <= 'm') {
			ch = ch + key;
			if (ch > 'm') {
				ch = ch - 'm' + 'r' - 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'R' && ch <= 'M') {
			ch = ch + key;
			if (ch > 'M') {
				ch = ch - 'Z' + 'M' - 1;
			}
			message[i] = ch;
		}
	}
	cout << "Received message: " << message;
	return 0;
}