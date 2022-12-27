#include <iostream>

struct Node_t {
	Node_t* left;
	Node_t* right;
	int data;
};

struct Tree_t {
	Node_t* root;
};

bool is_search_tree( Node_t* current, int last_min, int last_max ) {
	if (current == nullptr)
		return true;
	if (!(current->data < last_max && current->data > last_min))
		return false;
	return is_search_tree(current->left, last_min, current->data) &&
		is_search_tree(current->right, current->data, last_max);
}

void print_tree( Node_t* root, int level ) {
	if (root) {
		print_tree(root->right, level + 1);
		for (int i = 0; i < level; i++)
		{
			std::cout << "      ";
		}
		std::cout << root->data << std::endl;
		print_tree(root->left, level + 1);
	}
}

int main()
{
	Node_t root_of_correct_tree{ nullptr, nullptr, 7 };
	Node_t three{ nullptr, nullptr, 3 };
	Node_t ten{ nullptr, nullptr, 10 };
	Node_t one{ nullptr, nullptr, 1};
	Node_t nine{ nullptr, nullptr, 9};
	Node_t twelve{ nullptr, nullptr, 12};
	Node_t two{ nullptr, nullptr, 2};
	Node_t eight{ nullptr, nullptr, 8};
	Node_t eleven{ nullptr, nullptr, 11};
	Node_t thirteen{ nullptr, nullptr, 13};
	root_of_correct_tree.left = &three;
	root_of_correct_tree.right = &ten;
	three.left = &one;
	one.right = &two;
	ten.left = &nine;
	ten.right = &twelve;
	nine.left = &eight;
	twelve.left = &eleven;
	twelve.right = &thirteen;

	Node_t root_of_incorrect_tree{ nullptr, nullptr, 6 };
	Node_t five{ nullptr, nullptr, 5 };
	Node_t fiveteen{ nullptr, nullptr, 15 };
	Node_t sixteen{ nullptr, nullptr, 16 };
	Node_t fourteen{ nullptr, nullptr, 14 };
	root_of_incorrect_tree.left = &five;
	root_of_incorrect_tree.right = &fiveteen;
	five.right = &sixteen;
	fiveteen.left = &fourteen;

	print_tree(&root_of_correct_tree, 0);
	std::cout << "The binary tree is right? - " << std::boolalpha 
		<< is_search_tree(&root_of_correct_tree, 0, 100) << '\n' << std::endl;
	print_tree(&root_of_incorrect_tree, 0);
	std::cout << "The binary tree is right? - " << std::boolalpha 
		<< is_search_tree(&root_of_incorrect_tree, 0, 100) << '\n' << std::endl;

	return 0;
}
