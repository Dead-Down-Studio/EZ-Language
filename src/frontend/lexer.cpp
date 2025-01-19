#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

enum class TokenType
{
    NUMBER,
    STRING,
    BOOLEAN,
    OPERATOR,
    KEYWORD,
    IDENTIFIER,
    END_OF_LINE,
    ERROR
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
        skipWhitespaceAndComments();

        if (position >= input.size() || input[position] == ';')
        {
            return {TokenType::END_OF_LINE, ""};
        }

        if (std::isdigit(input[position]))
        {
            return number();
        }

        if (input[position] == '"')
        {
            return string();
        }

        if (std::isalpha(input[position]) || input[position] == '_')
        {
            return identifier();
        }

        if (position + 1 < input.size())
        {
            std::string two_chars = input.substr(position, 2);
            if (multi_char_operators.find(two_chars) != multi_char_operators.end())
            {
                position += 2;
                return {TokenType::OPERATOR, two_chars};
            }
        }

        if (single_char_operators.find(input[position]) != single_char_operators.end())
        {
            return {TokenType::OPERATOR, std::string(1, input[position++])};
        }

        return errorToken();
    }

private:
    void skipWhitespaceAndComments()
    {
        while (position < input.size())
        {
            if (std::isspace(input[position]))
            {
                position++;
            }
            else if (input[position] == '/' && position + 1 < input.size())
            {
                if (input[position + 1] == '/')
                {
                    position += 2;
                    while (position < input.size() && input[position] != '\n')
                    {
                        position++;
                    }
                }
                else if (input[position + 1] == '*')
                {
                    position += 2;
                    while (position < input.size() - 1 && !(input[position] == '*' && input[position + 1] == '/'))
                    {
                        position++;
                    }
                    position += 2;
                }
            }
            else
            {
                break;
            }
        }
    }

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
        position++;
        while (position < input.size() && input[position] != '"')
        {
            value += input[position++];
        }
        if (position >= input.size() || input[position] != '"')
        {
            return {TokenType::ERROR, "Unterminated string literal"};
        }
        position++;
        return {TokenType::STRING, value};
    }

    Token identifier()
    {
        std::string value;
        while (position < input.size() && (std::isalnum(input[position]) || input[position] == '_'))
        {
            value += input[position++];
        }
        if (keywords.find(value) != keywords.end())
        {
            return {TokenType::KEYWORD, value};
        }
        if (booleans.find(value) != booleans.end())
        {
            return {TokenType::BOOLEAN, value};
        }
        return {TokenType::IDENTIFIER, value};
    }

    Token errorToken()
    {
        std::string errorChar(1, input[position]);
        position++;
        return {TokenType::ERROR, "Unexpected character: " + errorChar};
    }

    std::string input;
    size_t position;
    const std::unordered_set<std::string> multi_char_operators = {"==", "!=", "<=", ">=", "&&", "||", "<<", ">>"};
    const std::unordered_set<char> single_char_operators = {'+', '-', '*', '/', '%', '^', '&', '|', '!', '='};
    const std::unordered_set<std::string> keywords = {"if", "else", "elif", "while", "for", "return"};
    const std::unordered_set<std::string> booleans = {"true", "false"};
};

std::string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::NUMBER:
        return "NUMBER";
    case TokenType::STRING:
        return "STRING";
    case TokenType::BOOLEAN:
        return "BOOLEAN";
    case TokenType::OPERATOR:
        return "OPERATOR";
    case TokenType::KEYWORD:
        return "KEYWORD";
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
    case TokenType::END_OF_LINE:
        return "END_OF_LINE";
    case TokenType::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

int main()
{
    std::ostringstream oss;
    oss << std::cin.rdbuf();
    std::string input = oss.str();
    Lexer lexer(input);
    Token token;

    while ((token = lexer.getNextToken()).type != TokenType::END_OF_LINE)
    {
        std::cout << "Token: " << token.value << " Type: " << tokenTypeToString(token.type) << std::endl;
    }

    return 0;
}
