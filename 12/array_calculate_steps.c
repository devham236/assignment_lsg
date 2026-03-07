/*
make array_calculate_steps && ./array_calculate_steps
*/
#include "base.h"

typedef enum operation_type_e
{
    OP_SET,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
} OperationType;

typedef struct operation_s
{
    double value;
    OperationType type;
} Operation;

// <Purpose statement>
double *calculate(double initial_value, Operation *operations, int operations_count)
{
    // todo: implement
    double *results = xmalloc(operations_count * sizeof(double));

    double current_value = initial_value;

    for (int i = 0; i < operations_count; i++)
    {
        switch (operations[i].type)
        {
        case OP_SET:
            current_value = operations[i].value;
            break;
        case OP_ADD:
            current_value += operations[i].value;
            break;
        case OP_SUB:
            current_value -= operations[i].value;
            break;
        case OP_MUL:
            current_value = current_value * operations[i].value;
            break;
        case OP_DIV:
            current_value = current_value / operations[i].value;
            break;

        default:
            break;
        }

        results[i] = current_value;
    }

    return results;
}

void base_test_equal_array(const char *file, int line, double *a, double *b, int length)
{
    int equal = 1;
    for (int i = 0; i < length; i++)
    {
        equal = equal && fabs(a[i] - b[i]) < 0.001;
    }
    base_test_equal_b(file, line, equal, 1);
}

#define test_equal_array(a, e, l) base_test_equal_array(__FILE__, __LINE__, a, e, l)

void test()
{
    Operation op_1[1] = {{1., OP_SET}};
    double res_1[1] = {1.};
    test_equal_array(calculate(0, op_1, 1), res_1, 1);

    Operation op_2[2] = {{1., OP_SET}, {2., OP_DIV}};
    double res_2[2] = {1., 0.5};
    test_equal_array(calculate(0, op_2, 2), res_2, 2);

    Operation op_3[5] = {{2., OP_MUL}, {2., OP_SUB}, {10., OP_ADD}, {2., OP_DIV}, {-1., OP_MUL}};
    double res_3[5] = {2., 0., 10., 5., -5.};
    test_equal_array(calculate(1, op_3, 5), res_3, 5);

    // Operation op_4[4] = {{2., OP_MUL}, {10., OP_SET}, {2., OP_DIV}, {20., OP_MUL}};
    // double res_4[4] = {0., 10., 5., 100.};
    // test_equal_array(calculate(0, op_4, 4), res_4, 4);
}

int main()
{
    test();
    return 0;
}