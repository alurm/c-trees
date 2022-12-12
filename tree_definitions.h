// Tree: .value.choice: 1 for node, 0 for leaf.
typedef struct{
	my_choiced_t value;
}my_tree_t;

#define MY_TREE_NODE(LEFT, RIGHT)(\
	my_tree_node_ineo(\
		&(my_tree_t){0},\
		&(my_pair_t){0},\
		LEFT,\
		RIGHT\
	)\
)

#define MY_TREE_LEAF(DATA)(\
	my_tree_leaf_ineo(&(my_tree_t){0}, DATA)\
)
