#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int sum_matrix(const std::vector<std::vector<int>> &col_matrix)
{
    int sum;
    for (int i{}; const auto &col_element : col_matrix)
    {
        for (int j{}; const auto &row_element : col_element)
        {
            if (i % 2 != 0 || j % 2 == 0)
            {
                sum += row_element;
            }

            j++;
        }
        i++;
    }
    return sum;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    std::vector<int> matrix_rows{};
    std::vector<std::vector<int>> matrix_cols{};
    int row, col, sum;

    std::cout << "Pick number of rows and cols: ";
    std::cin >> row >> col;

    for (int j{}; j < col; ++j)
    {
        for (int i{}; i < row; ++i)
        {
            matrix_rows.push_back(rand() % 10);
        }
        matrix_cols.push_back(matrix_rows);
        matrix_rows.clear();
    }

    for (int i{}; const auto &col_element : matrix_cols)
    {
        for (int j{}; const auto &row_element : col_element)
        {
            std::cout << row_element << " ";
            j++;
        }
        std::cout << std::endl;
        i++;
    }
    sum=sum_matrix(matrix_cols);
    std::cout << sum << std::endl;

    return 0;
}