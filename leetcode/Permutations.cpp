// https://leetcode.com/problems/permutations/
struct listnode
{
    listnode *next;
    int *permutation;
    size_t length;
    listnode() : next(NULL), permutation(NULL), length(0) {}
};



class Solution {
public:
    listnode *solve(int *arr, size_t n)
    {
        if (n == 1)
        {
            listnode *res = new listnode;
            res->permutation = new int[1];
            res->permutation[0] = arr[0];
            res->length = 1;
            return res;
        }
        listnode *res = NULL;
        for (int i = 0; i < n; i++)
        {
            int *arr_rest = new int[n - 1];
            int k = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    arr_rest[k++] = arr[j];
                }
            }

            listnode *rest = solve(arr_rest, n - 1);
            for (listnode *temp_it = rest; temp_it != NULL; temp_it = temp_it->next)
            {
                int *permutation;
                permutation = new int[n];
                permutation[0] = arr[i];
                int *rest_permutation = temp_it->permutation;
                for (int temp_ct = 1; temp_ct < n; temp_ct++)
                {
                    permutation[temp_ct] = rest_permutation[temp_ct - 1];
                }
                listnode *temp = res;
                res = new listnode;
                res->permutation = permutation;
                res->length = n;
                res->next = temp;
            }
        }
        return res;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int *arr = nums.data();
        int size = nums.size();
        listnode *res = solve(arr, size);
        vector<vector<int>> res_vec;
        for (listnode *res_it = res; res_it != NULL; res_it = res_it->next)
        {
            vector<int> temp;
            for (int i = 0; i < res_it->length; i++)
            {
                temp.push_back(res_it->permutation[i]);
            }
            res_vec.push_back(temp);
        }
        return res_vec;
    }
};