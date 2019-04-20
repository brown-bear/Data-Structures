//-----------------------------------------
// Lucas Burke
// 27 Nov 2017
// Filename: lucas_burke_binary_tree.h
// OS: macOS High Sierra v10.13.1
//
// Homework 2: Create 3 (+2 extra credit) new functions
// to find the largest/smallest keys, data avg
// and the max/min depths of Binary Search Trees (BST)
//
//-----------------------------------------


struct node
{
    int key_value;
    int data;
    node *left;
    node *right;
};

class btree {

	node *root;
	int	 total; // total number of stored keys

	void destroy_tree(node *leaf);
	void insert(int key, node *leaf, int val);
	int  search(int key, node *leaf);
	void print_tree(node * t);
	node *copy_tree(node * t);
	void delete_(node * & tree, int item);
	void delete_node(node * & tree);
	void get_predecessor(node * tree, int & k, int & d);
    void print_vis(int depth, node * t);
    int smallest_key(node * tree);
    int largest_key(node * tree);
    double sum(node * t);  // NEW FUNCTION -- called by public average_data()
    int min_depth(node * tree); // NEW FUNCTION -- called by public min_depth()
    int max_depth(node * tree); // NEW FUNCTION -- called by public max_depth()

public:
	btree();
	btree(const btree &t);
	~btree();
	void insert(int key, int val);
	int  search(int key); // returns data associated with the key
						  // or -1 if not found
	void print();
	int  size();
	void delete_item(int item);
	void destroy_tree();
    void print_vis();
    int smallest_key();
    int largest_key();
    double average_data(); // NEW FUNCTION -- uses private sum(node * t)
    int min_depth(); // NEW FUNCTION -- uses private min_depth(node * tree)
    int max_depth(); // NEW FUNCTION -- uses private max_depth(node * tree)

};


//--------- definitions ------------
// normal constructor
btree::btree()
{
  root	= NULL;
  total = 0;
}

// copy constructor
btree::btree(const btree &t){
	root  = copy_tree(t.root);
	total = t.total;
}

// destructor
btree::~btree()
{
  destroy_tree();
}

void btree::destroy_tree()
{
	destroy_tree(root);
	root = NULL;
	total = 0;
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf, int val)

{ if(key == leaf-> key_value){
    // the key already exists
	leaf-> data = val;  // update the data
	return;
  }
  if(key < leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left, val);
    else
    {
      leaf->left=	new node;
      leaf->left->key_value	= key;
	  leaf->left->data		= val;
      leaf->left->left		= NULL; //Sets the left child of the node to null
      leaf->left->right		= NULL; //Sets the right child of the node to null
	  ++total;
    }
  }
  else if(key > leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right, val);
    else
    {
      leaf->right=	new node;
      leaf->right->key_value  = key;
	  leaf->right->data		  = val;
      leaf->right->left		  = NULL; //Sets the left child of the node to null
      leaf->right->right	  = NULL; //Sets the right child of the node to null
	  ++total;
    }
  }
}

int btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key == leaf->key_value)
      return leaf->data;
    if(key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return -1;
}

void btree::insert(int key, int val)
{
  if(root!=NULL)
    insert(key, root, val);
  else
  {
    root =	new node;
    root-> key_value	= key;
	root-> data			= val;
    root-> left			= NULL;
    root-> right		= NULL;
	++total;
  }
}

int btree::search(int key)
{
  return search(key, root);
}

void btree::print_tree(node * t)
{
	if ( t != NULL ) {  // (Otherwise, there's nothing to print.)
		print_tree(t->left);			// Print items in left subtree.
		cout << "(key= "<< t->key_value << ", data= " << t-> data << ")\n"; // Print the root item.

		print_tree( t->right );			// Print items in right subtree.
	}
}

node *btree::copy_tree(node * t){

	if(!t) return NULL;

	node * p = new node;
	p-> key_value = t-> key_value;
	p-> data	  = t-> data;
	p-> left  = copy_tree(t-> left);
	p-> right = copy_tree(t-> right);
	return p;
}

void btree::print()
{
	cout<< "tree with "<< total << " nodes:\n";
	print_tree(root);
	cout<< endl;
}

int btree::size()
{
	return total;
}

void btree::delete_item(int item){
	delete_(root, item);
}

void btree::delete_(node * & tree, int item){

	if(!tree) return;// item was not found

	if (item < tree-> key_value)
		delete_(tree->left, item);   // Look in left subtree.
	else if (item > tree-> key_value)
		delete_(tree->right, item);  // Look in right subtree.
	else
		delete_node(tree);           // node found; call delete_node()
}

void btree::delete_node(node * & tree){
	// Deletes the node pointed to by tree.
	// The user's data in the node pointed to by tree is no
	// longer in the tree.  If tree is a leaf node or has only one
	// non-NULL child pointer the node pointed to by tree is
	// deleted; otherwise, the key_value is replaced by its
	// logical predecessor and the predecessor's node is deleted.
	{
	int k, d;
	node * tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
		{
			tree = tree->right;
			delete tempPtr;
			--total;
		}
	else if (tree->right == NULL)
		{
			tree = tree->left;
			delete tempPtr;
			--total;
		}
	else // tree has two children
		{
			get_predecessor(tree->left, k, d);
			tree-> key_value = k;
			tree-> data		 = d;
			delete_(tree->left, k);  // Delete predecessor node
		}
	}
}

void btree::get_predecessor(node * tree, int & k, int & d)
{
	// Sets data to the data member of the right-most node in tree.
	while (tree->right != NULL)
		tree = tree->right;
	k = tree->key_value;
	d = tree->data;
}

void btree::print_vis(){
    print_vis(0, root);
}

void btree::print_vis(int depth, node * t)
{
    if ( t != NULL ) {  // (Otherwise, there's nothing to print.)
        for(int i=0; i<depth;i++) cout<< ' ';
        cout << t->key_value << " \n";	// Print the root item.
        print_vis(depth+2, t->left);			// Print items in left subtree.
        print_vis(depth+2, t->right );			// Print items in right subtree.
    }
    else {for(int i=0; i<depth;i++) cout<< ' ';
        cout<<"NULL\n";}
}





					//******************************************************************\\
				   //******************* !!!!!!! MY UPDATES !!!!!!!! ********************\\
				  //**********************************************************************\\


int btree::smallest_key(node * tree) {
	int k;
	if (tree == NULL){
		cout<<"Tree is empty."<<endl;  // Return comment if tree is empty.
		return 0;
	}
	else {
		while (tree->left != NULL) {tree = tree->left;}  // Else, recursively find the bottom left node.
	}
	k = tree->key_value;  // Put bottom-left (smallest key) in k and return it.
	return k;
}

int btree::smallest_key()
{
  return smallest_key(root); // public method that calls private method to prevent twiddling
}


int btree::largest_key(node * tree) {
	int k;
	if (tree == NULL){
		cout<<"Tree is empty."<<endl; // Return comment if tree is empty.
		return 0;
		}
	else {
	while (tree->right != NULL) {tree = tree->right;} // Else, recursively find the bottom right node.
	}
	k = tree->key_value; // Put bottom-right (largest key) in k and return it.
	return k;
}


int btree::largest_key()
{
  return largest_key(root);  // public method that calls private method to prevent twiddling
}


double btree::sum(node * t) {
	if (t!=NULL){
		return t->data + sum(t->left) + sum(t->right);  //  recursively adds left 'sum(t->left)' to the right 'sum(t->right)' of tree and adds it to root data (t->data)
	}
	else{
		return 0;
	}
}

double btree::average_data()
{
	double avg;

	if (sum(root) != 0) {  // Uses private sum function to add up the value of all the data
	avg = sum(root)/total;  // Calculates average and returns it using class variable 'total' -- does not modify 'total'
	return avg;
	}
	else{
		cout<<"Tree is empty, average is nothing!"<<endl; // if tree is empty, say so.
		return 0;
	}
}


int btree::min_depth(node * tree){
   if (tree==NULL){  // if tree is NULL/empty, return 0.
	   return 0;
   }
   else {
	   int left_depth = min_depth(tree->left);  // recursively find depth of left branches
	   int right_depth = min_depth(tree->right); //recursively find depth of right branches

	   if (left_depth < right_depth) {return(left_depth+1);} // if left side is smallest, return it (+1 for root)

	   else {return(right_depth+1);}  // else return right side depth
   }
}

int btree::min_depth() {
	return min_depth(root);  // Public function calling private min_depth function.
}


int btree::max_depth(node * tree) {
   if (tree==NULL){
	   return 0;
   }
   else {
	   int left_depth = max_depth(tree->left);   // This function is the exact same as min_depth, except for...
	   int right_depth = max_depth(tree->right);

	   if (left_depth > right_depth)	 {return(left_depth+1);}	// the check to see what is larger, left or right side.
	   else {return(right_depth+1);}
   }
}

int btree::max_depth() {
	return max_depth(root);  // Public function calling private max_depth function.
}
