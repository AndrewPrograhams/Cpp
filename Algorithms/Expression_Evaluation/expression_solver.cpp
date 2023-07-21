#include <string>
#include <iostream>


class expression_solver
{
    public:
        std::string expr;
        char symbol;
        int index = 0;
    public:
        expression_solver(std::string expr)
        {
            expression_solver::expr = expr;
            int solution = expression_solver::compute();
            std::cout << solution << std::endl;
        }
        void next_symbol();

        int process_expression();
        int process_factor();
        int process_term();
        int compute();
};

void expression_solver::next_symbol()
{
    if(index != expr.length())
    {
        symbol = expr[index];
        index++;
    }
    else
        symbol = 0;
}

int expression_solver::compute()
{
    next_symbol();
    return process_expression();
}

int expression_solver::process_expression()
{
    int term = process_term();
    if(symbol == '/' )
}

int expression_solver::process_term()
{

}

int expression_solver::process_factor()
{

}