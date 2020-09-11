#include <stdio.h>
#include <stdlib.h>
typedef struct TNode
{
    int data;  //串列資料
    struct TNode *next;  //建立串列型態的指標
 } NODE;
 // ---------建立新節點---------
 NODE* createNode(void)
 {
     NODE *newNode = new NODE; // 用new建立新節點
     newNode->data = -1; // 令新節點指向的data等於-1
     newNode->next = NULL; // 令新節點的下一個指標為NULL
     return newNode;
 }
 // ---------建立新串列---------
 NODE* cresateList(void)
 {
     NODE *head, *tail; // 建立NODE型態的頭指標與尾指標
     head = createNode(); // 建立頭的新節點
     tail = createNode(); // 建立尾的新節點
     head->next=tail; // 令頭節點指向尾節點
     return head; // 回傳頭節點
 }
 //---------印出串列---------
 void printfList(NODE *List)
 {
     NODE *current = List;  // 建立當前指標，為串列的頭
     current = current->next; // 當前指標(現在是串列頭)的下個指向為自己
     int i = 0;
     while (current->data != -1) // 若當前指標的資料不是空的
     {
         printf("(%d, %d)\n",i ,current->data); // 印出序列與資料
         i++;
         current = current->next; // 將當前指標的下一個指向位址存到當前指標
         // 等於往下個串列資料移動
     }
     printf("END\n");
 }
 //---------插入資料到串列尾端---------
 NODE* InputList(int newNum, NODE *list)
 {
     NODE *newData, *current ,*List= list; // 將串列存在當前NODE類型的current
     newData = createNode(); // 建立新節點
     newData->data = newNum; // 將新節點的資料存入newNum
     newData->next = NULL; // 將新節點的指標先指向NULL
     while (List->next != NULL){
         current = List; // 令當前指標指向串列開頭
         List = List->next; // 移動到下個資料，直到最尾端
     }
     newData->next = List; //將新資料的next指向最尾端
     current->next = newData; // 將新資料加在串列後
     return List;
 }
 // 插入資料時同時排列
NODE* DataOrder(int newNum, NODE *list)
{
    NODE *newData, *current ,* List= list;
    newData = createNode();
    newData->data = newNum;
    newData->next = NULL;
    // 若新資料大於串列內的資料，移動到直到遇見更大的為止
    while ( newNum > List->data && List->next != NULL)
    {
        current = List; // 令當前指標指向現在的串列開頭
        List = List->next;   // 移動到下個串列資料
    }
    newData->next = List; // 將newData的next指向大於自身的串列
    //printf("List->data=%d\n", List->data);
    current->next = newData; // 將小於newData的前一個串列資料指標指向newData
    return List;
}
 //--------主程式----------
 int main()
 {
     int a[4]={8,6,5,9};
     NODE *ListOrder = cresateList(); // 建立空串列
     NODE *ListInput = cresateList(); // 建立空串列
     for( int i =0; i < 4; i++)
        DataOrder(a[i],ListOrder);
     printf("\n 按輸入串列時排序：\n");
     printfList(ListOrder); 
     for (int i = 0; i < 4; i++)
        InputList(a[i], ListInput);
     printf("按順序輸入串列：\n");
     printfList(ListInput);
     return 0;
 }