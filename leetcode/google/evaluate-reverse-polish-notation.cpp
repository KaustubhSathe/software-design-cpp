/**
 * @file evaluate-reverse-polish-notation.cpp
 * @author Kaustubh Sathe
 * @brief https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * @version 0.1
 * @date 2022-07-24
 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        /*
            iterate in reverse order and keep pushing the items in a stack,
            if the top three items are in this order (number, number, operator) then apply the given operation
            and repeat this process until there is just one element in the stack
        */
        stack<string> heap;
        for (int i = tokens.size() - 1; i >= 0; i--)
        {
            heap.push(tokens[i]);

            while (topThreeInOrder(heap))
            {
                auto item1 = heap.top();
                heap.pop();
                auto item2 = heap.top();
                heap.pop();
                auto item3 = heap.top();
                heap.pop();

                int newValue = operate(stringToInt(item1), stringToInt(item2), item3);
                heap.push(to_string(newValue));
            }
        }
        // still some items left in the stack, process again
        if (heap.size() > 1)
        {
            while (topThreeInOrder(heap))
            {
                auto item1 = heap.top();
                heap.pop();
                auto item2 = heap.top();
                heap.pop();
                auto item3 = heap.top();
                heap.pop();

                int newValue = operate(stringToInt(item1), stringToInt(item2), item3);
                heap.push(to_string(newValue));
            }
        }

        return stringToInt(heap.top());
    }

    bool topThreeInOrder(stack<string> &heap)
    {
        if (heap.size() < 3)
        {
            return false;
        }
        auto item1 = heap.top();
        heap.pop();
        auto item2 = heap.top();
        heap.pop();
        auto item3 = heap.top();
        heap.pop();
        heap.push(item3);
        heap.push(item2);
        heap.push(item1);
        return !isOperator(item1) && !isOperator(item2) && isOperator(item3);
    }

    bool isOperator(string x)
    {
        return x == "+" || x == "-" || x == "*" || x == "/";
    }

    // Util functions
    int stringToInt(string s)
    {
        return stoi(s);
    }

    int operate(int num1, int num2, string op)
    {
        if (op == "+")
        {
            return num1 + num2;
        }
        else if (op == "-")
        {
            return num1 - num2;
        }
        else if (op == "*")
        {
            return num1 * num2;
        }
        else
        {
            return num1 / num2;
        }
    }
};
