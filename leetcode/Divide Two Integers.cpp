// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
int divide(int dividend, int divisor)
{

    {

        if (dividend == 0)
            return 0;

        if (divisor == INT_MIN)
        {
            if (dividend == INT_MIN)
                return 1;
            else
                return 0;
        }

        if (divisor == INT_MAX)
        {
            if (dividend == INT_MAX)
                return 1;
            else if (dividend == INT_MIN)
                return -1;
            else
                return 0;
        }
    }

    int mult = 1;
    if (dividend > 0 && divisor < 0)
        mult = -1;
    if (dividend < 0 && divisor > 0)
        mult = -1;

    int rem = dividend;

    int step_size = 1;
    int dd = divisor;

    int i = 0;

    while (i < INT_MAX)
    {

        if (rem == 0)
            break;

        if ((rem < 0 && rem > mult * divisor) || (rem > 0 && rem < mult * divisor))
        {
            break;
        }

        int temp = rem;
        rem = rem - mult * dd;

        if (temp > 0 && rem < 0 || temp < 0 && rem > 0)
        {
            rem = temp;
            dd = divisor;
            rem = rem - mult * dd;
            step_size = 1;
        }

        i += step_size;

        if (dd > 0 && dd >= INT_MAX >> 1)
        {
            step_size = divisor;
            step_size = 1;
        }
        else if (dd < 0 && dd <= INT_MIN >> 1)
        {
            dd = divisor;
            step_size = 1;
        }
        else
        {
            dd += dd;
            step_size = 2 * step_size;
        }
    }

    if (i == INT_MAX)
    {

        if (mult == -1)
        {
            if ((rem < 0 && rem > mult * divisor) || (rem > 0 && rem < mult * divisor))
            {
                return -INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
        else
            return INT_MAX;
    }

    if (mult == -1)
        return -i;

    return i;
}
};