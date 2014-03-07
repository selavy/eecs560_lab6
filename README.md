eecs560_lab6
============

In terms of speed for:

insert: the array is faster because it just places the item at the end
	of the array.  Therefore, it is O(1).
	For the BST it will have to search for the correct position in
	the tree to insert, therefore it is O(lg(n))

delete: to delete an item from the array it must be searched linearly to
	find the element then swap it with the last element.  The array
	is faster that the AVL Tree for some of the elements towards the
	beginning of the list because once the item is found the delete
	operation is O(1), but because a linear search is involved it is
	O(n).  (The array can not be binary searched because it is not in
	order)

	The AVL Tree is O(lg(n)) to delete in the average and worst cases.
	Therefore, the AVL Tree is better for delete by name.  However,
	if deleting by coordinate, the entire tree must be searched, and
	the array is both faster and uses less memory because the AVL Tree
	must either use recursion of a queue to search for the element.

For the distance function, the array is better because every item must be
compared anyways.  Pointers can wreck caching algorithms because it is possible
that the memory allocated for a node would not be in a page in the cache, which
would lead to a cache miss.  Additionally, the AVL Tree requires either
recursion or a queue to iterate through all of the nodes in the tree.

Counts
---------------------------------------
Array:
	+Insert: 0
	+Delete: to remove Russellville by name and by coordinate was 25
	+Distance (on test.txt):
		  +50
		  +78
		  +100
		  +70
		  +70
		  +90
		  +74
		  +64
		  +86
		  +94
AVL:
	+Insert: from 4 - 49 inserts
	+Delete: to remove Russellville by name was 45 (though this is greater than what the array required, as the size of the array grows, the AVL tree would begin to perform better.
	                                                right now the cost of rebalancing the tree comes out to be more than the array.)
	+Distance (on test.txt):
		  +205
		  +145
		  +227
		  +196
		  +196
		  +151
		  +202
		  +160
		  +182
		  +154
		  
