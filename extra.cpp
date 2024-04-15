#include <bits/stdc++.h>
using namespace std;
#define ll long long int;

void solve(){
    
}

int main(){
    solve();
    return 0;
}

/* Link list Node/
// C++ program to subtract smaller valued list from
// larger valued list and return result as a list.
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
struct Node {
	int data;
	struct Node* next;
};

// A utility which creates Node.
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

//A utility function to get length of linked list 
int getLength(Node* Node)
{
	int size = 0;
	while (Node != NULL) {
		Node = Node->next;
		size++;
	}
	return size;
}

//A Utility that padds zeros in front of the Node, with the given diff 
Node* paddZeros(Node* sNode, int diff)
{
	if (sNode == NULL)
		return NULL;

	Node* zHead = newNode(0);
	diff--;
	Node* temp = zHead;
	while (diff--) {
		temp->next = newNode(0);
		temp = temp->next;
	}
	temp->next = sNode;
	return zHead;
}

//Subtract LinkedList Helper is a recursive function,move till the last Node, and subtract the digits and
//create the Node and return the Node. If d1 < d2, we borrow the number from previous digit. 
Node* subtractLinkedListHelper(Node* l1, Node* l2,bool& borrow)
{
	if (l1 == NULL && l2 == NULL && borrow == 0)
		return NULL;

	Node* previous = subtractLinkedListHelper(
		l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);

	int d1 = l1->data;
	int d2 = l2->data;
	int sub = 0;

	// if you have given the value to next digit then reduce the d1 by 1 
	if (borrow) {
		d1--;
		borrow = false;
	}

	//If d1 < d2, then borrow the number from previous digit. Add 10 to d1 and set borrow = true; 
	if (d1 < d2) {
		borrow = true;
		d1 = d1 + 10;
	}
	sub = d1 - d2;
	Node* current = newNode(sub);

	// Set the Next pointer as Previous 
	current->next = previous;
	return current;
}

// This API subtracts two linked lists and returns the linked list which shall have the subtracted result. 
Node* subtractLinkedList(Node* l1, Node* l2)
{
	// Base Case.
	if (l1 == NULL && l2 == NULL)
		return NULL;

	// In either of the case, get the lengths of both
	// Linked list.
	int len1 = getLength(l1);
	int len2 = getLength(l2);

	Node *lNode = NULL, *sNode = NULL;

	Node* temp1 = l1;
	Node* temp2 = l2;

	// If lengths differ, calculate the smaller Node
	// and padd zeros for smaller Node and ensure both
	// larger Node and smaller Node has equal length.
	if (len1 != len2) {
		lNode = len1 > len2 ? l1 : l2;
		sNode = len1 > len2 ? l2 : l1;
		sNode = paddZeros(sNode, abs(len1 - len2));
	}

	else {
		// If both list lengths are equal, then calculate
		// the larger and smaller list. If 5-6-7 & 5-6-8
		// are linked list, then walk through linked list
		// at last Node as 7 < 8, larger Node is 5-6-8
		// and smaller Node is 5-6-7.
		while (l1 && l2) {
			if (l1->data != l2->data) {
				lNode = l1->data > l2->data ? temp1 : temp2;
				sNode = l1->data > l2->data ? temp2 : temp1;
				break;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	// If both lNode and sNode still have NULL value,
	// then this means that the value of both of the given
	// linked lists is the same and hence we can directly
	// return a node with value 0.
	if (lNode == NULL && sNode == NULL) {
		return newNode(0);
	}
	// After calculating larger and smaller Node, call
	// subtractLinkedListHelper which returns the subtracted
	// linked list.
	bool borrow = false;
	return subtractLinkedListHelper(lNode, sNode, borrow);
}

void printList(struct Node* Node)
{
	while (Node != NULL) {
		printf("%d ", Node->data);
		Node = Node->next;
	}
	printf("\n");
}

// Driver program to test above functions
int main()
{
	Node* head1 = newNode(1);
	head1->next = newNode(0);
	head1->next->next = newNode(0);

	Node* head2 = newNode(1);

	Node* result = subtractLinkedList(head1, head2);

	printList(result);

	return 0;
}
*/

//TrieNode
/*

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
void insert(struct TrieNode *root, string key)

        {

            // code here

            for (int i=0;i<key.size();i++)

            {

                if (root->children[key[i]-'a']==NULL)

                    {root->children[key[i]-'a']=new TrieNode();}

                root=root->children[key[i]-'a'];

            }

            root->isLeaf=true;

        }

        

        //Function to use TRIE data structure and search the given string.

        bool search(struct TrieNode *root, string key) 

        {

            // code here

            for (int i=0;i<key.size();i++)

            {

                if (root->children[key[i]-'a']==NULL) return false;

                root=root->children[key[i]-'a'];

            }

            if (root->isLeaf==true) return true;

            return false;

        }
*/

//stinghash
/*
class StringHash {
public:
    vector<long long>ps1,ps2;
    long long Q1 = 271, Q2 = 277, M1 = 1000000007, M2 = 998244353;
    StringHash(string s) {
        ps1 = vector<long long>(s.size()+1); ps2 = vector<long long>(s.size()+1);
        for (int i = 1; i <= s.size(); i++) {
            long long c = s[i-1] + 1;
            ps1[i] = ((Q1 * ps1[i-1]) + c)%M1;
            ps2[i] = ((Q2 * ps2[i-1]) + c)%M2;
        }
    }
    long long int powxy(long long int x, long long int y, long long M) {
        if (y == 0) return 1;
        if (y%2 == 1) return (x*powxy(x, y-1, M))%M;
        long long int t = powxy(x, y/2, M);
        return (t*t)%M;
    }
    long long substrHash1(int firstIndex, int lastIndex) {
        long long rem = (powxy(Q1,lastIndex-firstIndex+1,M1) * ps1[firstIndex])%M1;
        return (ps1[lastIndex+1] - rem + M1)%M1;
    }
    long long substrHash2(int firstIndex, int lastIndex) {
        long long rem = (powxy(Q2,lastIndex-firstIndex+1,M2) * ps2[firstIndex])%M2;
        return (ps2[lastIndex+1] - rem + M2)%M2;
    }
    pair<long long, long long> substrHash(int firstIndex, int lastIndex) {
        return {substrHash1(firstIndex, lastIndex), substrHash2(firstIndex, lastIndex)};
    }
};
*/

//z-algorithm
/*
class ZAlgorithm {

    public int[] calculateZ(char input[]) {
        int Z[] = new int[input.length];
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.length; k++) {
            if(k > right) {
                left = right = k;
                while(right < input.length && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                //we are operating inside box
                int k1 = k - left;
                //if value does not stretches till right bound then just copy it.
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { //otherwise try to see if there are more matches.
                    left = k;
                    while(right < input.length && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    */

//distance between nodes and findLCA(lowest common ancestor if unique) 
/*
 int dist(Node* root, int a, int d){
        if(root==NULL){
            return -1;
        }
        if(root->data==a){
            return d;
        }
        
        int left=dist(root->left, a, d+1);
        int right= dist(root->right, a, d+1);
        
        if(left!=-1) return left;
        if(right!=-1) return right;
        
        return -1;
    }
    
    Node* findLCA(Node*root, int a, int b){
        if(root==NULL) return NULL;
        if(root->data==a || root->data==b) return root;
        
        Node* left= findLCA(root->left, a, b);
        Node* right= findLCA(root->right, a, b);
        
        if(left==NULL) return right;
        if(right==NULL) return left;
        
        return root;    
    }
*/

//map sorting based on values
/*
bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    return a.second < b.second; 
} 

sort(v.begin(), v.end(), [](auto &left, auto &right) {
    return left.second < right.second;
});
 
// Function to sort the map according 
// to value in a (key-value) pairs 
void sort(map<string, int>& M) 
{ 
 
    // Declare vector of pairs 
    vector<pair<string, int> > A; 
 
    // Copy key-value pair from Map 
    // to vector of pairs 
    for (auto& it : M) { 
        A.push_back(it); 
    } 
 
    // Sort using comparator function 
    sort(A.begin(), A.end(), cmp); 
 
    // Print the sorted value 
    for (auto& it : A) { 
 
        cout << it.first << ' '
            << it.second << endl; 
    } 
}

            or

sort(v.begin(),v.end(),greater<int,char>>()); // use vector<pair<int,char>>v;
*/

//use #include<algorithm> for next_permutation(s.begin(),s.end());

//KMPString Search
/*
void computeLPSArray(vector<int>& pattern, vector<int>& lps) {
    int patternLen = pattern.size();
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform pattern searching using the KMP algorithm
int KMPSearch(vector<int>& text, vector<int>& pattern) {
    int textLen = text.size();
    int patternLen = pattern.size();
    // Create lps array to store the longest prefix suffix values
    vector<int> lps(patternLen, 0);
    // Preprocess the pattern to build the lps array
    computeLPSArray(pattern, lps);
    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]
    int cnt = 0;
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == patternLen) {
            cnt++;
            j = lps[j - 1];
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return cnt;
}
// prefix == sufix for a string longest length
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
*/

//Floyd Algorithm
/*
bool hasCycle(ListNode *head) {
        if (!head||!head->next || !head->next->next) 
            return 0;
        ListNode *fast=head, *slow=head;
        //int i=0;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        //    cout<<++i<<",";
            if (fast==slow) return 1;
        }
        return 0;
    }
    */

#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
#define int long long
typedef pair<LL, LL> pll;
 
const int MOD =  998244353;
const pll BASE = {1e9 + 7, 1e9 + 9};
 
pll operator+(const pll &a, const pll &b)
{
    return {(a.first + b.first) % MOD, (a.second + b.second) % MOD};
}
 
pll operator+(const pll &a, const LL &b)
{
    return {(a.first + b) % MOD, (a.second + b) % MOD};
}
 
pll operator-(const pll &a, const pll &b)
{
    return {(MOD + a.first - b.first) % MOD, (MOD + a.second - b.second) % MOD};
}
 
pll operator*(const pll &a, const pll &b)
{
    return {(a.first * b.first) % MOD, (a.second * b.second) % MOD};
}
 
pll operator*(const pll &a, const LL &b)
{
    return {(a.first * b) % MOD, (a.second * b) % MOD};
}
 
inline LL modpow(LL x, int p)
{
    if (!p)
        return 1;
    return (modpow(x * x % MOD, p >> 1) * (p % 2 ? x : 1)) % MOD;
}
 
inline LL modinv(LL x)
{
    return modpow(x, MOD - 2);
}
 
struct hsh_bit
{
    int N;
    string S;
    vector<pll> fen, pp, ipp;
 
    hsh_bit(string S_)
    {
        S = S_;
        N = S.size();
        fen.resize(N + 1);
        pp.resize(N);
        ipp.resize(N);
        pp[0] = ipp[0] = {1, 1};
        const pll ibase = {modinv(BASE.first), modinv(BASE.second)};
        for (int i = 1; i < N; i++)
        {
            pp[i] = pp[i - 1] * BASE;
            ipp[i] = ipp[i - 1] * ibase;
        }
        for (int i = 0; i < N; i++)
        {
            upd(i, S[i]);
        }
    }
 
    void upd(int i, int x)
    {
        pll p = pp[i] * x;
        for (++i; i <= N; i += i & -i)
        {
            fen[i] = fen[i] + p;
        }
    }
 
    pll qry(int i)
    {
        pll ret = {0, 0};
        for (; i; i -= i & -i)
        {
            ret = ret + fen[i];
        }
        return ret;
    }
 
    void set(int i, char c)
    {
        int d = (MOD + c - S[i]) % MOD;
        S[i] = c;
        upd(i, d);
    }
 
    pll get(int s, int e)
    {
        return (qry(e) - qry(s)) * ipp[s];
    }
};
 
signed main()
{

     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;

    while(tt--) {
    
        int n, q; cin >> n >> q;
        string s; cin >> s;

        vector<int>preSum(n + 1);

        for(int i = 2; i <= n; i += 2) preSum[i] = i;
        partial_sum(preSum.begin(), preSum.end(), preSum.begin());
    
        hsh_bit left(s);
        reverse(s.begin(), s.end());
        hsh_bit right(s);
    
        for(int i = 0; i < q; i++)
        {
            int l, r; cin >> l >> r;


            if(l == r) {
                cout << 0 << "\n";
                continue;
            }

            vector<int>okay(4);

            for(int i = 0; i < 4; i++) {
                if(l + i > r) break;
                okay[i] = ( left.get((l + i) - 1, r - 1) == right.get(n - 1 - (r - 1), n - 1 - ((l + i) - 1)) &&
                            left.get(l - 1, (r - i) - 1) == right.get(n - 1 - ((r - i) - 1), n - 1 - (l - 1)));
            }

                int answer = (r - l + 1) * (r - l + 2) / 2 - 1;
                if(okay[0]) answer -= (r - l + 1);

                if(okay[0] && okay[1]) answer = 0;
                else if(okay[0] && okay[2]) answer = preSum[r - l + 1];
                else if(okay[1] && okay[3]) answer = preSum[r - l + 1];

                cout << answer << "\n";
        }
    }
}

