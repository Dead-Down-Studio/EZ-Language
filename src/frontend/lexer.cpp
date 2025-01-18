/*
    THIS IS AN EXAMPLE OF A LEXER IMPLEMENTATION IN C++.
    THIS WILL NOT BE USED IN THE FINAL PROJECT.
    THIS IS JUST FOR LEARNING PURPOSES.
    THIS IS A SIMPLE LEXER THAT CAN PARSE NUMBERS AND STRINGS.
*/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>

enum class TokenType
{
    NUMBER,
    STRING,
    END_OF_FILE,
    UNKNOWN
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
public:
    Lexer(const std::string &input) : input(input), position(0) {}

    Token getNextToken()
    {
        while (position < input.size() && std::isspace(input[position]))
        {
            ++position;
        }

        if (position >= input.size())
        {
            return {TokenType::END_OF_FILE, ""};
        }

        if (std::isdigit(input[position]))
        {
            return number();
        }

        if (input[position] == '"')
        {
            return string();
        }

        return {TokenType::UNKNOWN, std::string(1, input[position++])};
    }

private:
    Token number()
    {
        std::string value;
        while (position < input.size() && std::isdigit(input[position]))
        {
            value += input[position++];
        }
        return {TokenType::NUMBER, value};
    }

    Token string()
    {
        std::string value;
        ++position; // Skip the opening quote
        while (position < input.size() && input[position] != '"')
        {
            value += input[position++];
        }
        ++position; // Skip the closing quote
        return {TokenType::STRING, value};
    }

    std::string input;
    size_t position;
};

int main()
{
    std::string input = "123 \"hello world\" 456  \"C\"";
    Lexer lexer(input);
    Token token;

    while ((token = lexer.getNextToken()).type != TokenType::END_OF_FILE)
    {
        std::cout << "Token: " << token.value << " Type: " << static_cast<int>(token.type) << std::endl;
    }

    return 0;
}