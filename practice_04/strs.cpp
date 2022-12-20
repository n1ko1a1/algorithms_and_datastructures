#include <iostream>
#include <string>
#include <vector>

std::vector <char> editable_chars_list;

void prepareEditableCharsList() {
    for (int i = 65; i <= 90; ++i) {
        editable_chars_list.push_back((char) i);
    }
    for (int i = 97; i <= 122; ++i) {
        editable_chars_list.push_back((char) i);
    }
}

int getSymbolIndex (char symbol){
    for (int i = 0; i < editable_chars_list.size(); ++i) {
        if (symbol == editable_chars_list[i]) {
            return i;
        }
    }
    return -1;
}

int main()
{
    prepareEditableCharsList();

    char work_mode;
    std::string input_phrase;
    std::string output_phrase;
    int offset;

    std::cout << "Hello dear user! Caesar shipper program at your service." << std::endl
              << "Please, select work mode: " << std::endl
              << "1) Encryption (Enter a 'e' to select them)" << std::endl
              << "2) Decryption (Enter a 'd' to select them)" << std::endl
              << "Type your choice here: ";
    std::cin >> work_mode;

    switch (work_mode) {
        case 'e':
            std::cout << "Enter your text for encryption: ";
            //std::getline(std::cin, input_phrase);
            std::cin >> input_phrase;
            std::cout << "Enter your offset (integer): ";
            std::cin >> offset;

            for (char i : input_phrase) {
                if (getSymbolIndex(i) != -1) {
                    output_phrase.push_back(editable_chars_list[(getSymbolIndex(i) + offset) % editable_chars_list.size()]);
                } else {
                    output_phrase.push_back(i);
                }
            }

            std::cout <<  "Your encrypted text string: " << output_phrase;
            break;
        case 'd':
            std::cout << "Enter your text for decryption: ";
            //std::getline(std::cin, input_phrase);
            std::cin >> input_phrase;
            std::cout << "Enter your offset (integer): ";
            std::cin >> offset;

            for (char i : input_phrase) {
                if (getSymbolIndex(i) != -1) {
                    output_phrase.push_back(editable_chars_list[(getSymbolIndex(i) - offset) % editable_chars_list.size()]);
                } else {
                    output_phrase.push_back(i);
                }
            }

            std::cout <<  "Your decrypted text string: " << output_phrase;
            break;
        default:
            std::cout << "Error. You have selected a non-existent program mode.";
    }

    return 0;
}
