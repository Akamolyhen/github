//_HuffmanTree_H
#ifndef _HuffmanTree_H
#define _HuffmanTree_H
 
typedef struct
 {
   unsigned int weight;
   char ch;
   unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree; 
 typedef char **HuffmanCode; 
 
//这三个是哈夫曼树的生成
int min1(HuffmanTree t,int i);     //选出权值数组中最小的一个 ，，
 
void select(HuffmanTree t,int i,int *s1,int *s2);   //权值数组中最小的两个，，，并把临时数组对应位置改为1防止重复选择
 
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);  //根据权值数组W，和元素个数N开辟空间，HC存放编码
 
void getWeightInfile(int *w);// 从MyTxt.TXT里读入字母，以字母个数为权值，生成数组并返回
 
void bianMaInFile(HuffmanTree *p,HuffmanCode cd);    //根据编码.txt里面字母，找到对应的下标，在hc里面匹配编码
 
void yimaInFile(HuffmanTree *p);   //分析出  数的根结点下标应该为2n-1。。。所以只需根据编码 0 1确定向左还是向右 最终直到=遇到有意义的字母停止
 
 
 
#endif  //