#include <stdio.h>
#include <stdlib.h>

struct node{
	char huruf;
	int frekuensi;
	node *left, *right;
};

struct minHeap {
    int size;
    int capacity;
    struct node** array;
};

struct node *createNewNode(char huruf, int frekuensi) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  newNode->left = NULL
  newNode->right = NULL;
  newNode->huruf = huruf;
  newNode->frekuensi = frekuensi;

  return newNode;
}

struct minHeap* createMinHeap(int capacity){
	struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct node**)malloc(minHeap->capacity * sizeof(struct node*));
    return minHeap;
}

void swap(struct node** a, struct node** b){
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct minHeap* minHeap, int idx){
    int terkecil = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size &&  minHeap->array[left]->frekuensi < minHeap->array[terkecil]->frekuensi){
		terkecil = left;
	}
	
    if (right < minHeap->size && minHeap->array[right]->frekuensi < minHeap->array[terkecil]->frekuensi){
    	terkecil = right;
	}
 
    if (terkecil != idx) {swap(&minHeap->array[terkecil],& minHeap->array[idx]);
        minHeapify(minHeap, terkecil);
    }
}

int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i
           && minHeapNode->freq
                  < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
 
    printf("\n");
}

int isLeaf(struct MinHeapNode* root){
 
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
 
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
 
    struct MinHeap* minHeap
        = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        top = newNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
 
void printCodes(struct MinHeapNode* root, int arr[],int top){
 
    if (root->left) {
 
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
 
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
 
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);
 
    int arr[MAX_TREE_HT], top = 0;
 
    printCodes(root, arr, top);
}
 

int main(){
 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);
 
    return 0;
}
//int main(){
//	char arr[];
//	int i=-1;
//	do{
//		i++;
//		scanf("%c", arr[i]);
//	}while(arr[i] != NULL)
//	
//	return 0;
//}
