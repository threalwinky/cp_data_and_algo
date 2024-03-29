#include<iostream>
using namespace std;
class trie{
	private:
		static const int INSZ = 32;
	public:
		struct trie_node{
			trie_node *child_node[2];
			int isEnd;
			int value;
		};
		trie_node *new_node(){
			trie_node *pnode = new trie_node;
			pnode -> value = 0;
			pnode -> isEnd = 0;
			pnode -> child_node[0] = pnode -> child_node[1] = NULL;
		}
		trie_node *root = new_node();
		void insert(int key){
			trie_node *crawl_node = root;
			for (int i = INSZ - 1; i>=0 ;i--){
				bool bit = (key & (1 << i));
				if (!crawl_node -> child_node[bit])
					crawl_node -> child_node[bit] = new_node();
				crawl_node -> isEnd++;
				crawl_node = crawl_node -> child_node[bit];
			}
			crawl_node -> value = key;
		}
		void remove(int key){
			trie_node *crawl_node = root;
			for (int i = INSZ - 1; i>=0; i--){
				bool bit = (key & (1 << i));
				if (!crawl_node -> child_node[bit])
					return;
				if (crawl_node -> isEnd == 1){
					crawl_node -> child_node[bit] = nullptr;
					
					return;
				}
				
				crawl_node = crawl_node -> child_node[bit];
			}
		}
		bool search(int key){
			trie_node *crawl_node = root;
			for (int i = INSZ - 1; i>=0; i--){
				bool bit = (key&(1<<i));
				if (!crawl_node -> child_node[bit]) return 0;
				crawl_node = crawl_node -> child_node[bit];
			}
			return 1;
		}
		int min_xor(int key){
			trie_node* crawl_node = root;
			for (int i = INSZ - 1; i >= 0; i--) {
				bool bit = (key & (1 << i));
				if (crawl_node->child_node[bit] != NULL)
					crawl_node = crawl_node->child_node[bit];
				else if (crawl_node->child_node[1 - bit] != NULL)
					crawl_node = crawl_node->child_node[1 - bit];
			}
			return key ^ crawl_node->value;
		}
};
int main(){
	
}