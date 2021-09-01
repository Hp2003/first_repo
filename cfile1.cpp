#include <iostream>
#include<vector>
#include <cmath>
using namespace std;

void high_real_f(vector<int>& gg , int size){
    for (int i = 0; i < size - 1; i++)
    {
        gg[i] = gg[i] - gg[i + 1];
    }
}

void less_real_f(vector<int>& gg , int size){
   for (int i = 0; i < size - 1 ; i++)
   {
       gg[i] = gg[i + 1] - gg[i];
   }
}

void checkF(vector <int>& f , int size){
    int count = 1, count1 = size  , temp = 0;
    for (int i = 0; i < size -1; i++)
    {
        if (f[i] > f[i +1])
        {
            count++;
        }
        if (f[i] < f[i+1])
        {
            count1--;
        }   
    }

    if (count == size)
    {
        high_real_f(f , size);
        for (int i = 0; i < size; i++)
        {
            cout<<f[i]<<endl;
        }
        
    }    
     else if(count1 == 0){
       less_real_f( f , size); 
    }      
}
/***************************************************************************************************/
float mean(int arr[], int size)
{
    static float a;
    for (int i = 0; i < size; i++)
    {
        a = a + arr[i];
    }
    return a / size;
}
/*********************************************************************************************/
float a_mean(int arr[], int size, int f[])
{
    // checkF(f , size);
    float fx = 1;
    float sum = 0;
    float Fsum = 0;
    for (int i = 0; i < size; i++)
    {
        fx = arr[i] * f[i];
        sum = sum + fx;
        Fsum = Fsum + f[i];
    }
    return sum / Fsum;
}
/***********************************************************************************************************/
float ranged_mean(int a[], int size, int f[])
{
    float fx = 0;
    float sum = 0;
    float Fsum = 0;
    float x[size];
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        x[i] = (a[i] + a[i + 1]) / 2; // finding x
        if (i % 2 == 0)               // finding fx / sum of fx
        {
            fx += x[i] * f[temp];
            temp++;
        }
        sum = sum + f[i];
    }
    return fx / sum;
}
/****************************************************************************************************/
float assumed_mean(int a[], int size, int f[])
{
    // For find A
    int A = (0 + size) / 2;
    float fd = 0;
    int n = 0;
    static float d;
    for (int i = 0; i < size; i++)
    {
        d = a[i] - a[A];
        fd += (f[i] * d);
        n = n + f[i];
    }
    return a[A] + (fd / n);
}
/**********************************************************************************************************/
float Assumed_mean_with_range(int a[], int size, int f[])
{
    vector <int> f1(f , f + size/2);
    checkF(f1 , size/2);
    static int tem, d ;
    static float sf , comD , fd , final_ans;
    int t1 = size / 2 , h = a[1] - a[0] , check;
    vector <int> X;
    int A = t1 / 2 ;
    int z;
    for (int i = 0; i < size; i++)
    {   
        if (i%2 == 0)
        {
            X.push_back((a[i] + a[i + 1]) / 2);
        }
    }
            A = X.at(A);
    for (int i = 0; i < size/2; i++)
    {
            d = X.at(i) - A;
            sf = sf + f1[i];
            comD = d/10;
            fd += f1[i]*comD;
    }
    final_ans = A + fd/sf*h;
    return final_ans;
}
/*****************************************************************************************************************/
float weighted_mean(int a[] , int size , float f[]){
    float ans , tem = 0 , W = 0; 
    for (int i = 0; i < size; i++)
    {
        tem += a[i] * f[i];
        W = W+f[i];
    }
    return tem/W;
}
/*************************************************************************************************************************/
float harmonic_mean_without_F(int a[] , int size){
    float sum = 0 , v[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = a[i];
           sum += (1/v[i]); 
        }
    return size/sum;
}
/********************************************************************************************************************/
float harmonic_mean(float a[] , int size , int f[]){
    float sum = 0 , fsum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += f[i]/a[i];
        fsum = fsum + f[i];
    }
    return fsum/sum;
}
int main()
{
    // int a[4] = { 1 , 2 , 3 , 4 };
    // int f[4] = {8 , 12 , 21 , 10 };
    // cout<<mean(a , 10);
    // cout<<a_mean(a , 4 , f);
    // int a[10] = {4 , 6 , 6, 8 , 8 , 10 ,10 , 12 , 12 , 14 };
    // int f[10] = {6 , 12 ,17 , 10 ,5};
    // cout<<ranged_mean(a , 10 , f);
    // int a[7] = {15 , 16 , 17 , 18 , 19 , 20 , 21 };
    // int f[7] = {3 , 10 ,15 , 10 , 8 , 3 , 1};
    // cout<<assumed_mean(a , 7 , f);
    // int a[14] = {0, 10, 10, 20, 20, 30, 30, 40, 40, 50, 50, 60, 60, 70};
    // int f[7] = {6, 5, 8, 15, 7, 6, 3};
    // int a[10] = {0 , 10 , 10 , 20 , 20 , 30 , 30 , 40 , 40 , 50};
    // int f[5] = {20 , 24 , 40 , 36 , 20};
    // int a[10] = {20 , 29 , 30 , 39 , 40 , 49 , 50 , 59 , 60 , 69};
    // int f [5] = {10 , 8 , 6 , 4 ,2};
    // sd_with_range(a, 10, f);
    // int s[3] = {70 , 65 , 60};
    // float weight[3] = {0.5 , 0.2 , 0.3};
    // cout<<weighted_mean(s , 3 , weight);
    // int a[5] = {3 , 6 , 24 , 48 , 69};
    // cout<<harmonic_mean_without_F(a , 5);
    // float a[4] = {46.1 , 121 , 127 , 202};
    // int f[4] = {8 , 5  , 7 , 3};
    //float a[4] = {350 , 60 , 25 , 25};
    //int f[4] = {400 , 900 , 3000 , 15};
    //cout<<harmonic_mean(a , 4 , f);
    /******************************************************/
    // int a[5] = { 8 , 11 , -6 , 22 , -3};
    // cout<<mean(a , 5);
    /*****************************************************/
    // int a[4] = {1 , 2 , 3 , 4};
    // int f[4] = {3 , 5 , 8 , 4};
    // cout<<a_mean(a , 4 , f);
    /********************************************************************/
    // int a[10] = {4 , 6 , 6 , 8 , 8 , 10 , 10 , 12 , 12 , 14};
    // int f[5] = {6 , 12 , 17 , 10 , 5};
    // cout<<assumed_mean(a , 10 , f);
    /********************************************************************************************/
    // int a [10] = {0, 10 , 10 , 20 , 20 , 30 ,30 , 40 , 40 , 50 };
    // int f[5] = {20 , 24 , 40 , 36 , 20};
    // cout<<sd_with_range(a , 10 , f);
    /**************************************************************************************************/
    // int a[10] = {0 , 10 , 10 , 20 , 20 , 30 , 30 , 40 ,40 , 50};
    // int f[5] = {5 , 17 , 31 , 41 , 49};
    // cout<<assumed_mean(a , 10 , f);
    int a[10] = { 10 , 20 , 20 , 30 , 30 , 40 , 40 , 50 , 50 ,60   };
    int f[5] = {30 , 28 , 24 , 18 ,10 };
    cout<<Assumed_mean_with_range(a ,10 , f );
    

    return 0;
}