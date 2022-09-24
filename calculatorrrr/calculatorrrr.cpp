// calculatorrrr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool notOperator(char& a)
{
    return (a != '+' && a != '/' && a != '*' && a != '-');
}

int main()
{
    int result = 0;
    std::vector<int> termResults;
    std::vector<int> numbers;
    std::string operators;
    std::string bOperators;
    std::vector<char> aOperators;
    std::string operation;
    std::cout << "Input your operation: ";
    std::cin >> operation;
    

    for (int i = 0; i < operation.length(); i++)
    {
        std::string numberString;
        int numberParsed;
        do
        {
            if (notOperator(operation[i]))
            {
                numberString += operation[i];
            }

            if (operation[i+1] != '\0' && notOperator(operation[i+1]) && notOperator(operation[i]))
            {
                i++;
            }
            else
            {
                break;
            }
            
        }
        while (notOperator(operation[i]));

        if (numberString.length() >= 1)
        {
            numberParsed = std::stoi(numberString);
            numbers.push_back(numberParsed);
        }

        if (operation[i] == '/' || operation[i] == '*')
        {
            operators.push_back(operation[i]);
            aOperators.push_back(operation[i]);
        }
        else if(operation[i] == '+' || operation[i] == '-')
        {
            operators.push_back(operation[i]);
            bOperators.push_back(operation[i]);
        }
    }

    for (int i = 0; i < operators.size(); i++)
    {
        int termResultStore = 0;
        do
        {
            if (operators[i] == '*')
            {
                termResultStore = numbers[i] * numbers[i + 1];
                numbers[i + 1] = termResultStore;
                i++;
            }
            else if (operators[i] == '/')
            {
                termResultStore = numbers[i] / numbers[i + 1];
                numbers[i + 1] = termResultStore;
                i++;
            }
            else
            {
                termResultStore = numbers[i];
            }
        } while (operators[i] != '+' && operators[i] != '-' && operators[i] != '\0');

        termResults.push_back(termResultStore);
    }

    if (bOperators.length() == termResults.size())
    {
        termResults.push_back(numbers.back());
    }

    for (int& a : termResults)
    {
        std::cout << a << '\n';
    }

    for (int i = 0; i < bOperators.length(); i++)
    {
        int tempResult = 0;
        if (bOperators[i] == '+')
        {
            tempResult = termResults[i] + termResults[i + 1];
            termResults[i + 1] = tempResult;
        }
        else if(bOperators[i] == '-')
        {
            tempResult = termResults[i] - termResults[i + 1];
            termResults[i + 1] = tempResult;
        }
    }
    result = termResults.back();

    std::cout << result << '\n';
}

