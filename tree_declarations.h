my_tree_t*my_tree_leaf_ineo(my_tree_t*tree,void*data);

my_tree_t*my_tree_node_ineo(
	my_tree_t*tree,
	my_pair_t*pair,
	my_tree_t*left,
	my_tree_t*right
);

void my_tree_match(
	my_tree_t*tree,
	void leaf(void*data,void*extra),
	void node(my_tree_t*tree,void*extra),
	void*extra
);

void my_tree_traverse(
	my_tree_t*tree,
	void *procedure_void
);

my_tree_t**my_tree_left(my_tree_t*tree);

my_tree_t**my_tree_right(my_tree_t*tree);

my_pair_t*my_tree_pair(my_tree_t*tree);

void**my_tree_leaf(my_tree_t*tree);
