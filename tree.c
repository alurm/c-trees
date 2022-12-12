#include "pair.h"
#include "choiced.h"
#include "tree_definitions.h"

my_pair_t*my_tree_pair(my_tree_t*tree){
	return tree->value.data;
}

my_tree_t**my_tree_left(my_tree_t*tree){
	return (my_tree_t**)&my_tree_pair(tree)->left;
}

my_tree_t*my_tree_leaf_ineo(my_tree_t*tree,void*data){
	tree->value.choice=0;
	tree->value.data=data;
	return tree;
}

my_tree_t*my_tree_node_ineo(
	my_tree_t*tree,
	my_pair_t*pair,
	my_tree_t*left,
	my_tree_t*right
){
	pair->left=left;
	pair->right=right;
	tree->value.choice=1;
	tree->value.data=pair;
	return tree;
}

my_tree_t**my_tree_right(my_tree_t*tree){
	return (my_tree_t**)&my_tree_pair(tree)->right;
}

void**my_tree_leaf(my_tree_t*tree){
	return &tree->value.data;
}

_Bool my_tree_is_node(my_tree_t*tree){
	return tree->value.choice;
}

void my_tree_match(
	my_tree_t*tree,
	void leaf(void*data,void*extra),
	void node(my_tree_t*tree,void*extra),
	void*extra
){
	if(my_tree_is_node(tree)){
		node(*my_tree_left(tree),extra);
		node(*my_tree_right(tree),extra);
	}else{
		leaf(*my_tree_leaf(tree),extra);
	}
}

void my_tree_traverse(
	my_tree_t*tree,
	void *procedure_void
){
	void(*procedure)(void*data,void*extra)=procedure_void;
	my_tree_match(
		tree,
		procedure,
		my_tree_traverse,
		procedure
	);
}

#include "tree_declarations.h"
