// var 10
#include <stdio.h>
typedef struct node {
	char data[100];
	struct node* left;
	struct node* right;
} Node;
void AddNode(Node **node, char data[100]) {
	if (*node == NULL) {
		*node = (Node*)malloc(sizeof(Node));
		strcpy((*node)->data,data);
		(*node)->left = (*node)->right = NULL;

	}
	else {
		if (strcmp(data, (*node)->data) < 0) {
			AddNode(&((*node)->left), data);
		}
		else if (strcmp(data, (*node)->data) > 0) {
			AddNode(&((*node)->right), data);
		}
		else {
			printf("This word is alrady present in the tree\n");
		}
	}
	
}
void findPalindrome(char data[100]) {
	int wordLen = strlen(data);
	for (int i = 0; i < wordLen / 2; i++) {
		if (data[i] != data[wordLen - i  - 1]) {
			return;
		}
	}
	printf("%s\n", data);
}
void LeftOrder(Node* node)
{
	
	if (node->left) {
		LeftOrder(node->left);
	}
	if (node->right) {
		LeftOrder(node->right);
	}
	findPalindrome(node->data);
	//printf("%s\n", node->data);

}
int main() {
	Node* root = NULL;
	char word[100];
	printf("Word: ");
	gets(word);
	if (!(strcmp(word, "end"))) {
		return;
	}
	while (strcmp(word, "end")){

		AddNode(&root, word);
		printf("Word: ");
		gets(word);
	}
	LeftOrder(root);
	return -1;
}
