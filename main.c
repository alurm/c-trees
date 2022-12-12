#include "pair.h"
#include "choiced.h"
#include "tree.h"
#include <stdio.h>

static void my_print(void*data,void*extra){
	printf("%d\n",*(int*)data);
}

static void my_double_callback(void*data_void,void*extra){
	int*data=data_void;
	*data*=2;
}

static void main2(void){
	my_tree_t*tree=MY_TREE_NODE(
		MY_TREE_LEAF(&(int){1}),
		0
	);
	*my_tree_right(tree)=tree;
	my_tree_traverse(tree,my_print);
}

int main(void){
	my_tree_t*tree=MY_TREE_NODE(
		MY_TREE_LEAF(&(int){5}),
		MY_TREE_NODE(
			MY_TREE_LEAF(&(int){10}),
			MY_TREE_LEAF(&(int){15})
		)
	);
	my_tree_traverse(tree,my_print);
	my_tree_traverse(tree,my_double_callback);
	my_tree_traverse(tree,my_double_callback);
	my_tree_traverse(tree,my_double_callback);
	my_tree_traverse(tree,my_print);
	main2();
}
