#include <iostream>

struct Node_t
{
    int value;
    Node_t * left;
    Node_t * right;
};

struct Tree_t
{
    Node_t * root;
};

bool search_tree( Node_t * current_v, int last_min, int last_max )
{
    if (current_v == nullptr)
        return true;
    
    if ( !(current_v->value < last_max && current_v->value > last_min))
        return false;
        
    return search_tree(current_v->right, current_v->value, last_max) && search_tree( current_v->left, last_min, current_v->value);
    
}
int main() {
    Node_t one{1, nullptr, nullptr};
    Node_t two{2, nullptr, nullptr};
    Node_t three{3, nullptr, nullptr};
    Node_t four{4, nullptr, nullptr};
    Node_t five{5, nullptr, nullptr};
    Node_t six{6, nullptr, nullptr};
    Node_t Nums[] = {one, two, three, four, five, six};
    help_array [];
    int help_num;
    Nums[3-1].left = &Nums[2-1];//3.left = 2
    Nums[3-1].right = &Nums[5-1];
    
    Nums[2-1].left = &Nums[1-1];
    
    Nums[5-1].left = &Nums[4-1];
    Nums[5-1].right = &Nums[6-1];
    /*
    
            3
        2       5
    1         4   6
    
    */
    
    if (search_tree(&three, 0, 1024))
        std::cout << "search tree" << std::endl;
    else
        std::cout << "not search tree" << std::endl;
    
    return 0;
}
