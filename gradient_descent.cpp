/********************************************************************
    功能说明：利用梯度下降法求解函数 f = 2*x1*x1 + x2*x2的最小值
    初始条件：x = [1;1],迭代终止条件 e = 0.1
********************************************************************/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int flag = 1;
	float e = 0.1;
	float x1,x2;
	//初始化x
	float x[2] = {1,1};
	float f = 2*x1*x1 + x2*x2;
	float p[2];
	while(flag)
	{
	    //求函数f对x1和x2的偏导数
		p[0] = 4*x[0];
		p[1] = 2*x[1];
		//求偏导数的模的长度
		float p_norm = sqrt(p[0]*p[0] + p[1]*p[1]);
		//cout<<"p="<<p_norm<<endl;
		if(p_norm > e)
		{
		    // 计算迭代步长k
			float k = (4*p[0]*x[0] + 2*p[1]*x[1])/(4*p[0]*p[0] + 2*p[1]*p[1]);
			for(int i=0;i<2;i++)
			{
                // 更新x的值
				x[i] = x[i] - k*p[i];
			}
			cout<<"x[0]="<<x[0]<<"\tx[1]="<<x[1]<<endl;
		}else{
			flag = 0;
		}
	}
	return 0;
}

