Node* dfs(Node* node,  unordered_map<int, Node*>& mp) {

  // is node pe pehli baar aya hu
  Node* newNode = new Node(node->val);
  mp[node->val] = newNode; //  new address mark kro

  for (auto& curNbr : node->neighbors) { // traversing over old node nbrs
    if (mp.count(curNbr->val)) // is nbr ki new node already formed hau to bs isse mere nbrs me add kro
      newNode->neighbors.push_back(mp[curNbr->val]);

    else {
      Node* nbr = dfs(curNbr, mp); // nbr visit kro
      newNode->neighbors.push_back(nbr);
    }
  }

  return newNode;
}


//  Time: O(N) Space: O(N)  Using dfs and map
Node* cloneGraph(Node * node) {

  if (node == NULL) return NULL;
  unordered_map<int, Node*> mp; // val  pointing to new address
  return dfs(node, mp);
}

// ----------------------------------------------------------------------------------------------------

Node* bfs(Node* node,  unordered_map<int, Node*>& mp) {

  // {old node, new node}
  queue<pair<Node*, Node*>> q;

  Node* ans = new Node(node->val);
  mp[node->val] = ans;

  q.push({node, ans});

  while (!q.empty()) {

    auto cur = q.front();
    q.pop();

    Node* oldNode = cur.first;
    Node* newNode = cur.second;



    for (auto& curNbr : oldNode->neighbours) {
      if (mp.count(curNbr->val))   newNode->neighbours.push_back(curNbr); // already visited
      else {
        Node* temp = new Node(curNbr->val); // new node bnaos
        mp[curNbr->val] = temp;

        newNode->neighbours.push_back(curNbr);

        q.push({curNbr, temp});
      }
    }

  }

  return ans;
}


//  Time: O(N) Space: O(N)  Using dfs and map
Node* cloneGraph(Node * node) {

  if (node == NULL) return NULL;
  unordered_map<int, Node*> mp; // val  pointing to new address
  return bfs(node, mp);
}