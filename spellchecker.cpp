#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct word {
    std::string text;
    int line;
    int column;
};

bool read_words(
        const std::string input_file_name,
        std::vector<word>& words)
{
    std::ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    std::regex reg_exp("[a-zA-Z]+");
    std::smatch match;
    std::string text;
    int line = 0;
    int column = 0;
    while (std::getline(input_file, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

std::string Soundex(std::string palabra)
{
    if (palabra.length() == 0)
    {
        return "0000000";
    }

    std::string lowercase;
    char first_letter = tolower(palabra.front());
    std::string code;
    code += first_letter;

    for (char c : palabra)
    {
        lowercase += tolower(c);
    }

    lowercase.erase(0,1);

    for (char c : lowercase)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'h' || c == 'w' || c == 'y')
        {
            continue;
        }
        
        else if (c == 'b' || c == 'f' || c == 'p' || c == 'v')
        {
            code += '1';
        }

        else if (c == 'c' || c == 'g' || c == 'j' || c == 'k' || c == 'q' || c == 's' || c == 'x' || c == 'z')
        {
            code += '2';
        }

        else if (c == 'd'|| c == 't')
        {
            code += '3';
        }

        else if (c == 'l')
        {
            code += '4';
        }

        else if (c == 'm'|| c == 'n')
        {
            code += '5';
        }

        else if (c == 'r')
        {
            code += '6';
        }
    }

    if (code.length() < 7)
    {
        int difference = 7 - code.length();

        for (int i = 0; i < difference; i++)
        {
            code += '0';
        }
    }

    else if (code.length() > 7)
    {
        code = code.substr(0, 7);
    }

    return code;
}

bool load_dictionary(const std::string& file_name, 
                    std::unordered_set<std::string>& dictionary,  
                    std::unordered_map<std::string, std::vector<std::string>>& soundex_groups)
{
    std::ifstream input(file_name);
    if(input.fail())
    {
        return false;
    }

    std::string temp;

    while (input >> temp)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] = tolower(temp[i]);
        }
        dictionary.insert(temp);
        std::string code = Soundex(temp);
        soundex_groups[code].push_back(temp);
    }
    return true;
}

void procesar_palabras(
    const std::vector<word>& words,
    const std::unordered_set<std::string>& dictionary,
    const std::unordered_map<std::string, std::vector<std::string>>& soundex_groups)
{
    std::unordered_set<std::string> reported;

    for (const word& w : words)
    {
        std::string temp = w.text;

        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] = tolower(temp[i]);
        }

        if (dictionary.find(temp) != dictionary.end())
        {
            continue;
        }

        if (reported.find(temp) != reported.end())
        {
            continue;
        }

        reported.insert(temp);

        std::cout << "Unrecognized word: \"" << w.text << "\". First found at line " << w.line << ", column " << w.column << ".\n";
        std::string code = Soundex(temp);
        auto it = soundex_groups.find(code);
        if (it == soundex_groups.end())
        {
        std::cout << "No suggestions.\n\n";
        }
        else
        {
            auto& lista = it->second;
            if (lista.empty())
            {
                std::cout << "No suggestions.\n\n";
            }
            else
            {
                std::cout << "Suggestions: ";
                for (int i = 0; i < lista.size(); i++)
                {
                    std:: cout << lista[i];

                    if (i != lista.size() - 1)
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << "\n\n";

            }
        }
    }
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Uso correcto: " << argv[0] << " <archivo.txt>\n";
        return 1;
    }

    std::string file_name = argv[1];
    std::unordered_set<std::string> dictionary;  
    std::unordered_map<std::string, std::vector<std::string>> soundex_groups;

    if (!load_dictionary("words.txt", dictionary, soundex_groups)) {
        std::cerr << "Unable to read file: words.txt\n";
        return 1;
    }
    std::vector<word> words;

    if(read_words(file_name, words) == false) {
        std::cerr << "Unable to read file: " << file_name << "\n";
        return 1;
    }   

    procesar_palabras(words, dictionary, soundex_groups);

    return 0;
}