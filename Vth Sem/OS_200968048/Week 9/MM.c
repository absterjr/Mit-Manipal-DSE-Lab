#include<stdio.h>

void firstfit() {
int n_blocks, n_required, block_size[10], required_size[10], available_space[10];
int i,j;
printf("Memory Blocks: ");
scanf("%d", &n_blocks);
printf("Required Blocks: ");
scanf("%d", &n_required);
printf("Memory Block Sizes: ");
for(i = 0; i < n_blocks; i++)
scanf("%d", &block_size[i]);
printf("Required Block Sizes: ");
for(i = 0; i < n_required; i++)
scanf("%d", &required_size[i]);
for(i = 0; i < n_blocks; i++)
available_space[i] = block_size[i];
for(i = 0; i < n_required; i++) {
int allocated = 0;
for(j = 0; j < n_blocks; j++) {
if(required_size[i] <= available_space[j]) {
printf("%d Size Memory Block -> %d Size Process\n", block_size[j], required_size[i]);
available_space[j] -= required_size[i];
allocated = 1;
break;
}
}
if(!allocated)
printf("%d Size Process Not Allocated\n", required_size[i]);
}
}
void bestfit() {
int n_blocks, n_required, block_size[10], required_size[10], available_space[10];
int i,j;
printf("Memory Blocks: ");
scanf("%d", &n_blocks);
printf("Required Blocks: ");
scanf("%d", &n_required);
printf("Memory Block Sizes: ");
for(i = 0; i < n_blocks; i++)
scanf("%d", &block_size[i]);
printf("Required Block Sizes: ");
for( i = 0; i < n_required; i++)
scanf("%d", &required_size[i]);
for(i = 0; i < n_blocks; i++)
available_space[i] = block_size[i];
for(i = 0; i < n_required; i++) {
int best_index = -1;
for( j = 0; j < n_blocks; j++) {
if(required_size[i] <= available_space[j]) {
if(best_index == -1)
best_index = j;
else if(available_space[j] < available_space[best_index])
best_index = j;
}
}
if(best_index == -1)
printf("%d Size Process Not Allocated\n", required_size[i]);
else {
printf("%d Size Memory Block -> %d Size Process\n", block_size[best_index], required_size[i]);
available_space[best_index] -= required_size[i];
}
}
}
void worstfit() {
int n_blocks, n_required, block_size[10], required_size[10], available_space[10];
int i,j;
printf("Memory Blocks: ");
scanf("%d", &n_blocks);
printf("Required Blocks: ");
scanf("%d", &n_required);
printf("Memory Block Sizes: ");
for( i = 0; i < n_blocks; i++)
scanf("%d", &block_size[i]);
printf("Required Block Sizes: ");
for( i = 0; i < n_required; i++)
scanf("%d", &required_size[i]);
for( i = 0; i < n_blocks; i++)
available_space[i] = block_size[i];
for( i = 0; i < n_required; i++) {
int best_index = -1;
for( j = 0; j < n_blocks; j++) {
if(required_size[i] <= available_space[j]) {
if(best_index == -1)
best_index = j;
else if(available_space[j] > available_space[best_index])
best_index = j;
}
}
if(best_index == -1)
printf("%d Size Process Not Allocated\n", required_size[i]);
else {
printf("%d Size Memory Block -> %d Size Process\n", block_size[best_index], required_size[i]);
available_space[best_index] -= required_size[i];
}
}
}
int main(){
	printf("1.First Fit\n2.Best Fit\n3.Worst Fit\nEnter Choice: ");
	int a;
	scanf("%d", &a);
	switch(a) {
  case 1:
    firstfit();
    break;
  case 2:
    bestfit();
    break;
    case 3:
    	worstfit();
    	break;
  default:
    printf("Invalid Code!!");
}
	
}
