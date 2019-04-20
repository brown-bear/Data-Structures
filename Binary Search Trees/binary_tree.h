// binary_tree.h

// struct declaration should be global, since member function 
//      node * btree::copy_tree()
// appears otside of class body
struct node
{
    int key_value;
    int data;
    node *left;
    node *right;
};

//---------------------------------------
class btree
{
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
    root  = NULL;
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
		cout << "(key= "<< t->key_value << ", data= " << 
			    t-> data << ")\n"; // Print the root item.

		print_tree( t->right );			// Print items in right subtree.
	}
}

node * btree::copy_tree(node * t){
	
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

void btree::get_predecessor(node * tree, int & k, int & d){
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
