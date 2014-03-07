#include "AVLTree.hpp"
#include <queue>

AVLTree::AVLTree() : root(NULL) {
}

AVLTree::~AVLTree() {
  destruct_helper( root );
}

void AVLTree::insert(const City& city) {
  insert_helper(city, root);
}

void AVLTree::remove(const std::string& name) {
  remove_helper(root, name);
}

void AVLTree::remove_helper(Node * & t, const std::string& name) {
  if( t == NULL ) return; // wasn't able to find the node
  else if(name < t->city.name) {
    remove_helper( t->left, name );
  }
  else if(name > t->city.name) {
    remove_helper( t->right, name );
  }
  else { // else found the node
    // found the node to delete
    
    // Case 1: node has no children
    if((!t->left) && (!t->right)) {
      delete t;
      t = NULL;
    }
    // Case 2a: node has 1 child on left
    else if(!t->right) {
      Node * save_left = t->left;
      delete t;
      t = save_left;
    }

    //Case 2b: node has 1 child on right
    else if(!t->left) {
      Node * save_right = t->right;
      delete t;
      t = save_right;
    }

    // Case 3: node has 2 children
    else {
      // find the inorder successor, left most child of right subtree
      Node * succ = t->right;
      
      // case 1: succ has no left child
      if(!succ->left) {
	delete t;
	t = succ;
      }
      // case 2: succ does have left child
      else {
	while(succ->left) succ = succ->left;
	Node * save_right = succ->right;
	t->city = succ->city;
	delete succ;
	succ = save_right;
      }
    }
  }

  if(!t) return;

  t->height = MAX( height(t->left), height(t->right) ) + 1;
  const int balance = getBalance( t );
  const int balance_left = getBalance( t->left );
  const int balance_right = getBalance( t->right );
  
  // Case 1: Left Left Case
  if((balance > 1) && (balance_left >= 0)) {
    rotateWithLeftChild(t);
  }
  // Case 2: Left Right Case
  else if((balance > 1) && (balance_left < 0)) {
    rotateWithRightChild(t->left);
    rotateWithLeftChild(t);
  }
  // Case 3: Right Right
  else if((balance < -1) && (balance_right <= 0)) {
    rotateWithRightChild(t);
  }
  // Case 4: Right Left
  else if((balance < -1) && (balance_right > 0)) {
    rotateWithLeftChild(t->right);
    rotateWithRightChild(t);
  }
  
}

int AVLTree::getBalance( Node * t ) const {
  if(t == NULL) return 0;
  return height( t->left ) - height( t->right );
}

void AVLTree::remove(int x, int y) {
}

void AVLTree::print() const {
  std::queue<Node*> q;
  //int limit = 1;
  q.push(root);
  
  while(!q.empty()) {
    //for(int i = 0; (i < limit) && (!q.empty()); ++i)
    {
      Node * curr = q.front();
      q.pop();
      if(curr==NULL) {
	std::cout << "NULL ";
	continue;
      }
      q.push( curr->left );
      q.push( curr->right );
      std::cout << curr->city.name << " ";
    }
    //limit *= 2;
    //std::cout << std::endl;
  }
}

void AVLTree::printinorder() const {
  printinorder_helper(root);
}

void AVLTree::printinorder_helper(Node * t) const {
  if(t == NULL) return;
  printinorder_helper(t->left);
  std::cout << t->city.name << ": (" << t->city.x << "," << t->city.y << ") ";
  printinorder_helper(t->right);
}

void AVLTree::insert_helper(const City& city, Node * & t) {
  if( t == NULL ) {
    t = new Node( city, NULL, NULL, 0 );
  } else if( city < t->city ) {
    insert_helper( city, t->left );
    if( height( t->left ) - height( t->right ) == 2 ) {
      if( city < t->left->city ) {
	rotateWithLeftChild( t );
      } else {
	doubleWithLeftChild( t );
      }
    }
  } else if( t->city < city ) {
    insert_helper( city, t->right );
    if( height( t->right ) - height( t->left ) == 2 ) {
      if( t->right->city < city ) {
	rotateWithRightChild( t );
      } else {
	doubleWithRightChild( t );
      }
    }
  }
  else {
    // duplicate item so do nothing
  }

  t->height = MAX( height(t->left), height(t->right) ) + 1;
}

void AVLTree::rotateWithLeftChild(Node * & k2) {
  Node * k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = MAX( height(k2->left), height(k2->right) ) + 1;
  k1->height = MAX( height(k1->left), k2->height ) + 1;
  k2 = k1;
}

void AVLTree::rotateWithRightChild(Node * & k1) {
  Node * k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = MAX( height( k1->left ), height( k1->right ) ) + 1;
  k2->height = MAX( k1->height, height( k2->right ) ) + 1;
  k1 = k2;
}

void AVLTree::doubleWithLeftChild(Node * & t) {
  rotateWithRightChild( t->left );
  rotateWithLeftChild( t );
}

void AVLTree::doubleWithRightChild(Node * & t) {
  rotateWithLeftChild( t->right );
  rotateWithRightChild( t );
}

void AVLTree::destruct_helper(Node * & t) {
  if(t == NULL) return;
  destruct_helper(t->left);
  destruct_helper(t->right);
  delete t;
}

int AVLTree::height( Node * t ) const {
  return (t == NULL) ? -1 : t->height;
}
